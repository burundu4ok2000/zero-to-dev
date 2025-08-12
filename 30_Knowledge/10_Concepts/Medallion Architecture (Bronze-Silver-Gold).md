---
title: "Medallion Architecture (Bronze/Silver/Gold)"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/dbt"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Medallion Architecture (Bronze-Silver-Gold).png]]

## **One-liner**
Layered **ELT** layout that lands **raw** in **Bronze**, cleans and **deduplicates** into **Silver**, and publishes **modeled** analytics (**facts/dimensions**) in **Gold**—optimizing for **reliability**, **governance**, and **speed**.

## The Big Idea
- Separate concerns by **layer** so changes upstream don’t break **downstream** models instantly.
- Keep **Bronze** as an immutable, replayable **system of record** (append-only, versioned files, **time travel**).
- Build **Silver** as the cleaned, **schema-on-write** truth with **upserts/merges**, **SCD** rules, and stable keys.
- Serve **Gold** as business-ready **star schemas**, **materialized views**, or **data marts** for BI.
- Works best with **cloud lakehouse** storage and table formats that support **ACID** and **schema evolution** (e.g., **Delta Lake**, **Apache Iceberg**, **Apache Hudi**).

## Layers (what goes where)
- **Bronze (raw/landing)** — source snapshots, CDC change logs, API dumps, files as-is. Write **append-only**, preserve **lineage**, include minimal metadata (source, load_ts, checksum).
- **Silver (clean/curated)** — normalized types, **deduplication**, **late-arriving** handling, **surrogate keys**, **UPSERT/MERGE**. Data is trustworthy and joins cleanly.
- **Gold (serving/BI)** — **fact tables** at a clear **grain**, **dimension tables** (often **SCD Type 2**), aggregated marts, **materializations** for dashboards.

## Read/Write Rules
- **Bronze**: immutable files/tables; allow **reprocess** via versioning; avoid schema coercion (**schema-on-read**).
- **Silver**: **idempotent** transforms; manage **watermarks**/**cursor** fields; enforce constraints (**NOT NULL**, **unique**, **FK** where possible).
- **Gold**: keep interface **stable**; expose **semantic** names; document **additivity**; protect with **RBAC** and masking policies.

## Implementation Patterns
- Storage: object store (S3/GCS/ADLS) + table format (**Delta/Iceberg/Hudi**).
- Ingestion: **Airbyte/Fivetran/Debezium** to **Bronze** (batch or **streaming**/**CDC**).
- Transform: **dbt SQL** models or Spark jobs from **Bronze → Silver → Gold**.
- Orchestrate: **Airflow/Dagster** with retries, **SLA/SLO**, and **observability** hooks.
- Catalog & Quality: **data catalog**, **lineage**, **Great Expectations**/**dbt tests**; DLQ/quarantine for bad records.

## Example Layout
```
/lake/
  bronze/               # raw landings (append-only)
    orders/ingest_date=2025-08-12/part-000.parquet
    customers/ingest_date=2025-08-12/...
  silver/               # cleaned & deduped
    orders/
    customers/
  gold/                 # modeled for BI
    fct_orders/
    dim_customer/
```

## Example: Silver & Gold (conceptual SQL)
```sql
-- silver.orders: dedupe + type fixes
create or replace table silver.orders as
select *
from (
  select
    cast(order_id as bigint) as order_id,
    customer_id,
    order_ts::timestamp as order_ts,
    status,
    row_number() over (partition by order_id order by _ingest_ts desc) as rn
  from bronze.orders
)
where rn = 1;

-- gold.fct_orders: daily rollup
create or replace table gold.fct_orders as
select
  date_trunc('day', order_ts) as order_day,
  count(*) as orders
from silver.orders
group by 1;
```

## Governance & Ops
- Enforce **RBAC**, **row/object** policies, and **PII** masking at **Silver/Gold**.
- Track **freshness** and **SLA** per dataset; alert on drift and volume anomalies.
- Keep **backfills** safe with versioned **Bronze** and idempotent **Silver** builds.
- Document contracts: inputs, expected schema, nullability, **SLAs**, owners.

## Related Concepts
- [[ELT]] – transformations inside the warehouse/lakehouse.
- [[ETL vs ETL]]  <!-- will be corrected by the user if needed -->
- [[Data Lake vs Lakehouse]]
- [[Data Warehouse]]
- [[Data Ingestion]]
- [[Dimensional Modeling (Kimball)]]
- [[dbt Core Concepts]]
- [[Change Data Capture (CDC)]]
- [[Data Quality & Testing (Great Expectations)]]

## See Also
- [Databricks: Medallion Architecture](https://www.databricks.com/glossary/medallion-architecture)
- [Microsoft Fabric: Medallion architecture](https://learn.microsoft.com/fabric/data-engineering/lakehouse-medallion-layers)
- [Delta Lake: Table formats & ACID](https://delta.io/)

## Terms
[[bronze layer]], [[silver layer]], [[gold layer]], [[ELT]], [[data lake]], [[lakehouse]], [[Delta Lake]], [[Apache Iceberg]], [[Apache Hudi]], [[schema-on-read]], [[schema-on-write]], [[deduplication]], [[upsert]], [[merge]], [[watermark]], [[cursor field]], [[SCD Type 2]], [[data contract]], [[RBAC]], [[masking]], [[lineage]], [[partitioning]], [[compaction]], [[time travel]], [[observability]], [[SLA]]
