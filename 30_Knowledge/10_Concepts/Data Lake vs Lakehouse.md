---
title: "Data Lake vs Lakehouse"
lang_tags: "#lang/sql"
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

![[Data Lake vs Lakehouse.png]]

## **One-liner**
A **data lake** is low-cost **object storage** with **schema-on-read**; a **lakehouse** adds **ACID tables**, **transactions**, and **governance** so you can run warehouse-grade analytics directly on the lake.

## The Big Idea
- **Data Lake**: stores raw/staged files (CSV/JSON/**Parquet**). Cheap, flexible, but weak on **transactions**, **concurrency**, and **governed** updates. You add engines (Spark/Trino/Athena) on top and manage consistency yourself.
- **Lakehouse**: same object store, but with a **table format** that brings **ACID**, **schema evolution**, **time travel**, and **concurrent** reads/writes. Lets you do **ELT**, **BI**, and **ML** on one foundation without copying data into a separate warehouse.
- Modern platforms often combine **lakehouse** + **warehouse** patterns (e.g., external tables, unified catalogs) depending on latency, cost, and tooling.

## Quick Compare
| Aspect | Data Lake | Lakehouse |
|---|---|---|
| **Storage** | Object store (S3/GCS/ADLS) with files | Same, but organized as **ACID tables** |
| **Schema** | **Schema-on-read** | **Schema-on-write** (enforced) + evolution |
| **Transactions** | None (eventual consistency) | **ACID** with **transaction log** / manifests |
| **Updates/Merge** | Hard (rewrite files) | **UPSERT/MERGE**, **DELETE**, **UPDATE** |
| **Concurrency** | Best-effort | Serializable/optimistic locking (format-dependent) |
| **Time travel** | Manual versioning | Built-in versions/snapshots |
| **Governance** | Ad-hoc (paths, IAM) | Central **catalog**, **RBAC**, masking, lineage |
| **Performance** | Good scans, fragile maintenance | **Compaction**, **clustering**, metadata pruning |

## Architecture Patterns
- **Data Lake**: `/raw`, `/staged` zones of **Parquet** files; query via Spark/Trino/Athena. Reliability relies on folder discipline, partitioning, and job design.
- **Lakehouse**: the same, but files are managed by a **table format** (e.g., Delta Lake, Apache Iceberg, Apache Hudi) that tracks versions and enforces constraints. A **catalog** (Glue, Hive Metastore, Unity/Polaris, Nessie) provides discovery, permissions, and lineage.
- **Lakehouse + Warehouse**: keep curated **gold** models both as lakehouse tables and as **warehouse** tables/views where required for tooling or SLAs.

## Typical Workflow (Medallion)
- **Bronze**: raw landings (append-only) in the lake.
- **Silver**: cleaned, **deduplicated** tables with stable keys (**UPSERT/MERGE**).
- **Gold**: **star schemas** for BI; expose them as **materialized** lakehouse tables or external views in the warehouse.

## When to Choose What
- Choose **Data Lake** when you need cheapest storage for diverse raw data, exploratory **ML**, or long-term archives—accepting more ops work.
- Choose **Lakehouse** when teams want **warehouse-like guarantees** (ACID, governance) without duplicating datasets, and plan to run **ELT** and **BI** directly on the lake.
- Hybrid is normal: lakehouse for curated layers, plus **warehouse** for specific workloads or vendor ecosystems.

## Example: Conceptual DDL (Iceberg/Delta-like)
```sql
-- Create a managed lakehouse table
CREATE TABLE silver.orders (
  order_id BIGINT,
  customer_id BIGINT,
  order_ts TIMESTAMP,
  status STRING
)
PARTITION BY (date_trunc('day', order_ts));

-- Idempotent merge for late-arriving data
MERGE INTO silver.orders t
USING staging.orders s
ON t.order_id = s.order_id
WHEN MATCHED THEN UPDATE SET *
WHEN NOT MATCHED THEN INSERT *;
```

## Common Gotchas
- Treating a lake like a warehouse without **ACID** → duplicates, lost updates, and broken analytics.
- Skipping **compaction**/**vacuum** → too many small files, slow scans.
- Over-partitioning (one folder per user/day/hour) → metadata blow-up; prefer balanced partitioning and **clustering/z-order** if supported.
- Lack of a **catalog** and **data contracts** → schema drift goes unnoticed.

## Related Concepts
- [[Medallion Architecture (Bronze/Silver/Gold)]]
- [[Data Warehouse]]
- [[ELT]]
- [[ELT vs ETL]]
- [[Data Ingestion]]
- [[Dimensional Modeling (Kimball)]]
- [[Change Data Capture (CDC)]]
- [[dbt Core Concepts]]
- [[Delta Lake]]
- [[Apache Iceberg]]
- [[Apache Hudi]]

## See Also
- [Databricks: What is a Lakehouse?](https://www.databricks.com/discover/data-lakehouse/what-is-a-data-lakehouse)
- [Apache Iceberg: Introduction](https://iceberg.apache.org/docs/latest/)
- [Delta Lake: Overview](https://delta.io/)
- [AWS Lake Formation: Data lakes on AWS](https://aws.amazon.com/lake-formation/)

## Terms
[[object storage]], [[schema-on-read]], [[schema-on-write]], [[Parquet]], [[table format]], [[transaction log]], [[ACID]], [[time travel]], [[upsert]], [[merge]], [[delete]], [[catalog]], [[RBAC]], [[lineage]], [[partitioning]], [[clustering]], [[compaction]], [[vacuum]], [[manifest]], [[query engine]], [[Spark]], [[Trino]], [[Athena]], [[materialization]]
