---
title: "ELT vs ETL"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/warehouse/snowflake"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

---

![[ELT vs ETL.png]]

---
## **One-liner**
**ETL** transforms data **before** loading into the warehouse; **ELT** loads **raw** first and transforms **in-warehouse** using scalable SQL and **compute pushdown**.

## The Big Idea
- **ETL (Extract → Transform → Load)** pre-shapes data on external compute (Spark, Python, ETL tools) and loads curated outputs into the warehouse.
- **ELT (Extract → Load → Transform)** lands **raw** data quickly in a lake/warehouse, then runs SQL/dbt to build **silver/gold** models inside the platform.
- Cloud warehouses made **ELT** attractive by offering cheap storage, elastic **compute**, and strong **SQL** engines.
- Choice depends on **data gravity**, **compliance**, **latency**, **cost**, and your team’s **operational** muscle.

## When ETL shines
- Strict **compliance** requires pre-load **PII** masking, tokenization, or aggregation outside the warehouse.
- Complex **multistep** transforms that are easier in a general-purpose runtime (Python/Scala) or require **custom libraries**.
- Legacy warehouses with limited **compute** or poor **pushdown**.
- Tight **SLAs** where loading only curated outputs reduces storage churn and downstream noise.

## When ELT shines
- Need to ingest fast and **iterate**: load raw, then model with **dbt** or SQL views/materializations.
- Heavy transforms benefit from **warehouse optimizers**, **columnar** storage, and **automatic scaling**.
- Desire for full **lineage** and **time travel** on raw data for reproducibility and reprocessing.
- Teams comfortable with **analytics engineering** and SQL-first workflows.

## Architecture at a Glance
```
            +------------------+
Extract --> | Landing / Raw    |  (object storage or raw tables)
            +------------------+
                  |                               ETL path           \  ELT path
        +-------------------+       \ 
        | External Compute  |        \-> Load raw → Transform in-warehouse
        | (Spark, Airflow)  |       
        +-------------------+
                  |
                  v
            +------------------+
            | Curated Tables   |  (warehouse / marts)
            +------------------+
```

## Trade-offs
| Aspect | ETL | ELT |
|---|---|---|
| **Latency to raw** | Slower (transform first) | Faster (load first) |
| **Storage cost** | Lower raw retention | Higher (keep raw + curated) |
| **Compute location** | External engines | Warehouse pushdown |
| **Operational complexity** | More moving parts | Fewer tools, more SQL |
| **Reprocessing** | Harder (need raw backups) | Easier (raw retained) |
| **Governance** | Pre-load controls | In-warehouse policies/masking |
| **Skill profile** | Data engineering heavy (Python/Scala) | Analytics engineering heavy (SQL/dbt) |

## Practical Guidance
- Prefer **ELT** in cloud **lakehouse**/**warehouse** setups (Snowflake, BigQuery, Databricks SQL) where **compute** is elastic and cheap relative to ops effort.
- Prefer **ETL** when regulation forbids landing sensitive **raw** data unmasked, or when transforms require **non-SQL** logic at scale.
- Hybrid is normal: **ETL** for privacy-critical or ML feature generation, **ELT** for mainstream BI models.
- Keep **idempotent** loads, explicit **data contracts**, and versioned **staging**. Test models with **dbt tests** and track **freshness**/**SLA**.

## Example: Minimal ELT with dbt (conceptual)
```sql
-- models/stg_orders.sql  (silver)
select
  cast(order_id as bigint) as order_id,
  customer_id,
  order_ts::timestamp as order_ts,
  status
from { source('raw', 'orders') }

-- models/fct_orders.sql  (gold)
select
  date_trunc('day', order_ts) as order_day,
  count(*) as orders
from { ref('stg_orders') }
group by 1
```

## Related Concepts
- [[Data Warehouse]] – the execution engine and home for curated models.
- [[Data Lake]] – low-cost storage for raw and staged data.
- [[Medallion Architecture]] – bronze/silver/gold flow that fits ELT naturally.
- [[Data Ingestion]] – gets data to raw so ELT can start.
- [[Dimensional Modeling]] – shapes gold tables for BI.
- [[Orchestration]] – scheduling/running pipelines (Airflow, Dagster).

## See Also
- [Snowflake: ETL vs ELT](https://www.snowflake.com/guides/etl-vs-elt/)
- [Fivetran: What is ELT?](https://www.fivetran.com/learn/what-is-elt)
- [Databricks: ETL vs ELT in the Lakehouse](https://www.databricks.com/discover/data-engineering/etl-vs-elt)

## Terms
[[extract]], [[load]], [[transform]], [[raw data]], [[staging area]], [[silver table]], [[gold table]], [[compute pushdown]], [[optimizer]], [[dbt]], [[materialization]], [[lineage]], [[time travel]], [[data contract]], [[idempotency]], [[SLA]], [[governance]], [[tokenization]], [[masking]]
