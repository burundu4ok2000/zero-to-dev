---
title: "ETL"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/orchestration/airflow"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

---

![[ETL.png]]

---
## **One-liner**
**ETL** (**Extract → Transform → Load**) cleans, standardizes, and reshapes data **before** loading it into the **data warehouse** so only curated, governance-compliant datasets land inside.

## The Big Idea
- Transforms happen on **external compute** (Python/**Spark**, Beam, SQL-on-files, vendor tools) and produce **curated outputs** that the warehouse simply ingests.
- Fits teams with strong **data engineering** chops and strict **compliance** (e.g., **PII** needs masking/tokenization **pre-load**).
- Reduces warehouse churn and storage of sensitive **raw** data; trades that for more moving parts and infra to operate.
- Often coexists with **ELT**. Use ETL for privacy-critical or non-SQL-heavy logic; use ELT for mainstream analytics models.

## Core Workflow
1) **Extract** — pull from DBs (**CDC**/**binlog**), SaaS APIs, files, or streams into a **staging** area.  
2) **Transform** — run cleansing, type-casting, joins, aggregations, and **SCD** handling on external engines; write outputs as **partitioned**/versioned files (Parquet) or temp tables.  
3) **Load** — **idempotent** insert/merge into final warehouse tables (facts/dimensions or wide curated tables).

```
sources  -> staging -> external compute (Spark/Python) -> curated artifacts -> warehouse load
```

## Reliability & Governance
- **Idempotency**: stable keys + **UPSERT/MERGE**; retries with **exponential backoff**.  
- **Schema management**: contracts, evolution rules, validation; **DLQ** for bad records.  
- **Security**: **PII** masking/tokenization/redaction **before** the warehouse; secrets in a vault; **TLS** everywhere.  
- **Observability**: pipeline **metrics/logs/traces**, row counts, freshness **SLA/SLO**.

## Performance Notes
- **Parallel extraction** (by key ranges or time windows), **chunking**, and **backpressure**.  
- Write **columnar** (Parquet/ORC), **partition** by date/entity, and compact small files.  
- Push heavy joins/aggregations to **Spark**/**Beam**; keep loads **append-only** then merge in the warehouse during a short maintenance window.

## Example: Airflow DAG for ETL (conceptual)
```python
from airflow import DAG
from airflow.operators.empty import EmptyOperator
from airflow.operators.bash import BashOperator
from datetime import datetime

with DAG("etl_orders", start_date=datetime(2025, 1, 1), schedule="@hourly", catchup=False) as dag:
    start = EmptyOperator(task_id="start")

    extract = BashOperator(
        task_id="extract_orders",
        bash_command="python etl/extract_orders.py --since { ds } --out s3://raw/orders/{ ds }"
    )

    transform = BashOperator(
        task_id="transform_orders",
        bash_command="spark-submit etl/transform_orders.py s3://raw/orders/{ ds } s3://curated/orders/{ ds }"
    )

    load = BashOperator(
        task_id="load_to_warehouse",
        bash_command="python etl/load_orders.py --src s3://curated/orders/{ ds } --table analytics.orders"
    )

    start >> extract >> transform >> load
```

## Example: Spark transform step (conceptual)
```python
from pyspark.sql import SparkSession, functions as F

spark = SparkSession.builder.getOrCreate()
df = spark.read.parquet("s3://raw/orders/2025-08-12")

clean = (df
    .withColumn("order_ts", F.to_timestamp("order_ts"))
    .withColumn("email", F.lower(F.col("email")))
    .filter(F.col("status").isin("paid","shipped"))
)

# partitioned, compressed Parquet
(clean
 .repartition(8, "order_date")
 .write.mode("overwrite")
 .partitionBy("order_date")
 .parquet("s3://curated/orders/2025-08-12"))
```

## Common Gotchas
- Skipping a clear **grain** in facts leads to duplicates and broken sums.  
- Forgetting **late-arriving** data and **SCD Type 2** rules rewrites history silently.  
- Writing tons of tiny files kills downstream performance—**compact** aggressively.  
- No **data contract** → schema drift breaks loads without alerts.

## Related Concepts
- [[ELT vs ETL]] – decision trade-offs and when to prefer each.  
- [[ELT]] – load raw then transform inside the warehouse.  
- [[Data Ingestion]] – connectors and landing patterns feeding ETL.  
- [[Data Warehouse]] – curated home for analytics-ready tables.  
- [[Data Lake]] – object storage layer for raw/staged/curated files.  
- [[Orchestration]] – scheduling dependencies and retries (Airflow, Dagster).  
- [[Dimensional Modeling]] – facts/dimensions and SCD handling.

## See Also
- [Apache Airflow: Concepts](https://airflow.apache.org/docs/apache-airflow/stable/concepts/index.html)
- [Databricks: ETL Best Practices](https://docs.databricks.com/en/delta/best-practices/etl.html)
- [AWS Glue: What is ETL?](https://docs.aws.amazon.com/glue/latest/dg/what-is-glue.html)

## Terms
[[extract]], [[transform]], [[load]], [[staging area]], [[CDC]], [[binlog]], [[SCD Type 2]], [[UPSERT]], [[MERGE]], [[idempotency]], [[deduplication]], [[partitioning]], [[Parquet]], [[object storage]], [[DLQ]], [[tokenization]], [[masking]], [[vault]], [[exponential backoff]], [[backpressure]], [[freshness]], [[SLA]], [[observability]]
