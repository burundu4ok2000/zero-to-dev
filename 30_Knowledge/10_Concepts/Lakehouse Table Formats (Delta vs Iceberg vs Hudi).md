---
title: "Lakehouse Table Formats (Delta vs Iceberg vs Hudi)"
lang_tags: "#lang/sql #lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/lakehouse"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Lakehouse Table Formats (Delta vs Iceberg vs Hudi).png]]


## **One-liner**
Delta Lake, Apache Iceberg, and Apache Hudi bring **ACID tables** to object storage, enabling **MERGE/UPSERT**, **time travel**, and safe concurrent reads/writes so you can run warehouse-grade **ELT** directly on the lake.

## The Big Idea
- A **table format** defines how files + metadata create a **transactional table** over S3/GCS/ADLS. It tracks snapshots, schema, partitions, and compaction so engines (Spark/Trino/BigQuery/Flake adapters) can read/write safely.
- All three provide **ACID**, **schema evolution**, and **snapshots**; they differ in metadata design and strengths:
  - **Delta Lake** — append-only **transaction log** (`_delta_log` JSON/Parquet), simple mental model, strong Spark & Databricks tooling, **OPTIMIZE**/**Z-ORDER**, **VACUUM**.
  - **Iceberg** — layered **manifests** + snapshot metadata, powerful **partition evolution** and **hidden partitioning**, multi-engine first-class (Spark, Flink, Trino, Presto, Hive). Supports **branching**/**tagging**.
  - **Hudi** — built around **upserts** and **incremental pull**; storage types **Copy-on-Write (COW)** and **Merge-on-Read (MOR)** with background **compaction**; great for CDC-heavy pipelines.

## Capabilities (quick compare)
| Feature | Delta Lake | Iceberg | Hudi |
|---|---|---|---|
| ACID transactions | ✓ | ✓ | ✓ |
| Time travel / snapshots | ✓ | ✓ | ✓ |
| MERGE/UPSERT | ✓ | ✓ | ✓ (via upsert APIs) |
| Schema evolution | ✓ | ✓ (robust) | ✓ |
| Partition evolution | Limited | ✓ | Partial |
| Hidden partitioning | – | ✓ | – |
| Streaming reads/writes | ✓ | ✓ | ✓ (strong for upserts) |
| Compaction/Optimize | OPTIMIZE, VACUUM | Rewrite data/manifests | Compaction for MOR |
| Clustering/Z-order | Z-ORDER (vendor) | Sort/cluster (engine-dependent) | Clustering (Hudi index) |
| Branch/Tag | – | ✓ | – |
| Engine support | Spark, Trino, Flink, many | Spark, Flink, Trino, Presto, Hive | Spark, Flink, Trino |

## Choosing Guide
- Pick **Delta** when you live in the Databricks/Spark ecosystem and want straightforward ops, **OPTIMIZE**/**VACUUM**, and Z-ordering for query pruning.
- Pick **Iceberg** for **multi-engine** stacks, evolving partitions over time, and governance via modern catalogs (Nessie/Glue/Hive/Polaris-like).
- Pick **Hudi** for **CDC-heavy** workloads needing **near-real-time upserts**, **incremental queries**, and **MOR** for low-latency reads while compaction runs.

## Common Patterns
- **Bronze → Silver**: land raw files/events, then **MERGE** CDC into Silver with stable keys (business PK, op_ts).  
- **Materialize Gold**: build star schemas as **tables** (or maintained views) and schedule compaction/OPTIMIZE jobs.  
- **Streaming**: Kafka → Spark/Flink write to table format with **checkpointing**; downstream readers do near-real-time analytics.  
- **Compaction & Cleanup**: periodic compaction, **VACUUM**/retention to drop old snapshots and orphan files.

## Example Snippets

### Delta Lake — MERGE into Silver
```sql
MERGE INTO silver.orders AS t
USING staging.orders_cdc AS s
ON t.order_id = s.order_id
WHEN MATCHED AND s.op = 'D' THEN DELETE
WHEN MATCHED AND s.op IN ('U','R') AND s.op_ts > t.op_ts THEN UPDATE SET *
WHEN NOT MATCHED AND s.op IN ('C','R') THEN INSERT *;
-- OPTIMIZE silver.orders ZORDER BY (order_ts);
-- VACUUM silver.orders RETAIN 168 HOURS;
```

### Iceberg — snapshot & partition evolution (conceptual SQL)
```sql
ALTER TABLE silver.orders ADD PARTITION FIELD bucket(order_id, 16);
-- later change partition spec without rewriting all history
ALTER TABLE silver.orders REPLACE PARTITION FIELD days(order_ts);
-- time travel
SELECT * FROM silver.orders /* AT SNAPSHOT <snapshot_id> */;
```

### Hudi — Upsert with Spark (PySpark)
```python
(hudi_df.write
  .format("hudi")
  .option("hoodie.table.name", "silver_orders")
  .option("hoodie.datasource.write.recordkey.field", "order_id")
  .option("hoodie.datasource.write.precombine.field", "op_ts")
  .option("hoodie.datasource.write.operation", "upsert")
  .mode("append")
  .save("s3://lake/silver/orders/"))
# MOR tables will compact in background; readers see near-real-time views.
```

## Maintenance & Tuning
- Set **file sizes** and **row groups/stripes** for scan efficiency; schedule **compaction**.  
- Manage **snapshot retention**: keep recent snapshots for **time travel**, clean older with retention policies.  
- Use **clustered sorting**/Z-order (where available) for multi-column pruning.  
- Track table **metadata size**; optimize manifest lists (Iceberg) or compact logs (Delta/Hudi).  
- Validate data with **data contracts** and **quality checks** before merges.

## Catalogs & Governance
- Register tables in a **catalog** (Hive Metastore, AWS Glue, Nessie, Polaris/Unity-like) for discovery, permissions, and **lineage**.  
- Apply **RBAC**, **masking**, and row/object policies at the engine/platform layer.  
- Expose **docs** (dbt, catalog UIs) with owners, SLAs, and downstream **exposures**.

## Related Concepts
- [[Data Lake vs Lakehouse]]
- [[Medallion Architecture (Bronze/Silver/Gold)]]
- [[ELT]]
- [[Data Warehouse]]
- [[Spark Basics for Data Engineering]]
- [[Change Data Capture (CDC)]]
- [[Data Contracts & Schema Management (Avro/Protobuf/JSON Schema)]]
- [[Data Formats & Compression for Analytics (CSV/JSON/Parquet/ORC)]]
- [[Data Quality & Testing (Great Expectations)]]
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]

## See Also
- Delta Lake: https://delta.io/
- Apache Iceberg: https://iceberg.apache.org/
- Apache Hudi: https://hudi.apache.org/

## Terms
[[table format]], [[ACID]], [[transaction log]], [[manifest]], [[snapshot]], [[time travel]], [[partition evolution]], [[hidden partitioning]], [[MERGE]], [[UPSERT]], [[Copy-on-Write]], [[Merge-on-Read]], [[compaction]], [[optimize]], [[vacuum]], [[schema evolution]], [[optimistic concurrency control]], [[catalog]], [[Hive Metastore]], [[AWS Glue]], [[Nessie]], [[branch]], [[tag]], [[checkpoint]], [[incremental pull]], [[Z-order]], [[clustered sort]]
