---
title: "Spark Basics for Data Engineering"
lang_tags: "#lang/python #lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/spark"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Spark Basics for Data Engineering.png]]


## **One-liner**
**Apache Spark** is a distributed **DataFrame** engine with **lazy evaluation**, a cost-based **Catalyst optimizer**, and **Tungsten** execution—good for **batch** and **structured streaming** workloads in data platforms.

## The Big Idea
- You write high-level **transformations** on **DataFrames**; Spark builds a logical plan, optimizes it (predicate pushdown, projection pruning, join reordering), and executes as a distributed **DAG** of **stages**/**tasks**.
- Scale comes from **partitions** across **executors**. Some ops are **narrow** (map/filter) and avoid shuffle; others are **wide** (join/groupBy) and trigger **shuffle**.
- Performance is mostly about **I/O formats** (prefer **Parquet/ORC**), **partitioning**, limiting **shuffle**, and using built-in expressions instead of **UDFs**.
- For real-time, **Structured Streaming** treats streams as unbounded tables with **event-time**, **watermarks**, and **stateful** windows/joins.

## Architecture (mental model)
- **Driver** — coordinates the job, holds the session, creates the DAG.  
- **Executors** — processes that run tasks and hold **caches**.  
- **Cluster manager** — Standalone/YARN/Kubernetes allocates resources.  
- **Catalyst & Tungsten** — query optimizer + efficient memory/codegen backend.  

## Core Concepts
- **Transformations** (lazy): `select`, `where`, `withColumn`, `groupBy`, `join`, `window`.  
- **Actions** (eager): `count`, `collect`, `write`, `foreach`.  
- **Partitions**: control parallelism; `repartition` (increase/shuffle), `coalesce` (decrease/avoid shuffle).  
- **Shuffle**: data exchange across executors for wide ops; tune via `spark.sql.shuffle.partitions`.  
- **Caching**: `cache`/`persist` when reused; unpersist to free memory.  
- **Broadcast join**: ship small dim table to all executors to avoid shuffle.  
- **Skew**: one key dominates; mitigate with **salting**, **skew hints**, or pre-aggregation.  
- **AQE**: **Adaptive Query Execution** can coalesce shuffle partitions, handle skew, and pick join strategies at runtime.  

## File & Table Formats
- Prefer **columnar** (**Parquet**, **ORC**) with compression; enable **predicate pushdown** and **partition pruning**.  
- For lakehouse tables use **Delta Lake**/**Apache Iceberg**/**Hudi** for **ACID**, **MERGE**, and **time travel**.  
- Avoid tiny files; aim for 128–1024 MB per file; compact after heavy incremental writes.

## PySpark Examples

### Read → Transform → Write (batch)
```python
from pyspark.sql import SparkSession, functions as F

spark = (SparkSession.builder
         .appName("etl")
         .config("spark.sql.adaptive.enabled", "true")
         .config("spark.sql.shuffle.partitions", "200")
         .getOrCreate())

df = (spark.read.parquet("s3://lake/bronze/orders/")
      .select("order_id", "customer_id", "order_ts", "status", "amount")
      .withColumn("order_ts", F.to_timestamp("order_ts"))
      .filter(F.col("status").isin("paid","shipped")))

# Broadcast small dimension to avoid shuffle
dim = spark.read.parquet("s3://lake/silver/dim_customer/")
joined = df.join(F.broadcast(dim), "customer_id", "left")

agg = (joined
       .groupBy(F.window("order_ts", "1 day").alias("w"))
       .agg(F.sum("amount").alias("revenue"))
       .select(F.col("w.start").alias("day"), "revenue"))

(agg.coalesce(32)  # fewer, bigger files
    .write.mode("overwrite")
    .partitionBy("day")
    .parquet("s3://lake/gold/fct_daily_revenue/"))
```

### Structured Streaming (Kafka → silver)
```python
from pyspark.sql import functions as F

events = (spark.readStream
  .format("kafka")
  .option("kafka.bootstrap.servers", "kafka:9092")
  .option("subscribe", "orders")
  .option("startingOffsets", "earliest")
  .load())

json = F.from_json(F.col("value").cast("string"), schema)  # define a StructType schema
orders = (events.select(json.alias("j"))
  .select("j.order_id","j.customer_id","j.order_ts","j.status","j.amount")
  .withColumn("order_ts", F.to_timestamp("order_ts"))
  .withWatermark("order_ts", "30 minutes"))

windowed = (orders
  .groupBy(F.window("order_ts", "10 minutes"))
  .agg(F.count("*").alias("orders")))

query = (windowed.writeStream
  .outputMode("update")
  .option("checkpointLocation", "s3://lake/_chk/orders_10m/")
  .format("parquet")
  .option("path", "s3://lake/silver/orders_10m/")
  .trigger(processingTime="1 minute")
  .start())
```

## Performance Checklist
- Read only needed **columns**; push **filters** early.  
- Tune `spark.sql.shuffle.partitions` to match cluster size; let **AQE** coalesce.  
- Prefer built-in SQL functions; **UDFs** disable some optimizations. Use **Pandas UDFs** only when necessary.  
- **Broadcast** small dims; otherwise **bucket**/**partition** large joins.  
- Control **skew**: salting, `skewJoin` hints, pre-aggregation.  
- Avoid `collect()` and massive driver-side operations.  
- Manage file sizes: `repartition`/`coalesce` before writes; schedule **compaction** jobs.  
- For streaming: set **checkpointing**, **watermarks**, and idempotent sinks; monitor **state store** size.

## Common Gotchas
- Millions of tiny files from over-parallelized writes → slow reads.  
- Leaving default `spark.sql.shuffle.partitions=200` on huge clusters → under/over-parallelism.  
- Heavy **UDF** usage when a built-in exists.  
- Joining two huge tables without partitioning/broadcast → explosive shuffle.  
- No **watermark** → unbounded state growth and late data leaks.  
- Writing to the same path from multiple jobs without ACID table format → corruption.

## Related Concepts
- [[Data Lake vs Lakehouse]]  
- [[ELT]]  
- [[Data Warehouse]]  
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]  
- [[Stream Processing & Kafka Fundamentals]]  
- [[Change Data Capture (CDC)]]  
- [[Medallion Architecture (Bronze/Silver/Gold)]]  
- [[Docker for Data Engineering]]  

## See Also
- [Spark SQL, DataFrames and Datasets Guide](https://spark.apache.org/docs/latest/sql-programming-guide.html)
- [Structured Streaming Programming Guide](https://spark.apache.org/docs/latest/structured-streaming-programming-guide.html)
- [Monitoring and Tuning Guide](https://spark.apache.org/docs/latest/tuning.html)

## Terms
[[driver]], [[executor]], [[cluster manager]], [[DataFrame]], [[Dataset]], [[RDD]], [[Catalyst optimizer]], [[Tungsten]], [[lazy evaluation]], [[logical plan]], [[physical plan]], [[stage]], [[task]], [[partition]], [[shuffle]], [[narrow transformation]], [[wide transformation]], [[action]], [[broadcast join]], [[predicate pushdown]], [[partition pruning]], [[repartition]], [[coalesce]], [[cache]], [[persist]], [[skew]], [[salting]], [[AQE]], [[Parquet]], [[ORC]], [[Delta Lake]], [[Apache Iceberg]], [[Hudi]], [[window function]], [[watermark]], [[stateful aggregation]], [[checkpoint]], [[trigger]], [[micro-batch]], [[exactly-once semantics]]
