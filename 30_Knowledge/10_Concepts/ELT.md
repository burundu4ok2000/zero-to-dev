---
title: "ELT"
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

---

![[ELT.png]]

---
## **One-liner**
Load raw data first then transform inside the warehouse with scalable **SQL** and **compute pushdown**.

## The Big Idea
- **ELT** flips the classic **ETL** order. Move data quickly into a **warehouse** or **lakehouse** then build models with SQL and tools like **dbt**.
- Cloud platforms made this viable by separating **storage and compute**, providing elastic **scaling**, and strong **optimizers**.
- Keeping **raw** enables backfills, reproducibility, better **lineage**, and **time travel**. It also shifts teams toward **analytics engineering**.
- ELT coexists with selective **ETL** for privacy critical or non SQL heavy transforms.

## Core Workflow
1. **Extract** from sources to a durable **staging** or raw layer.
2. **Load** into raw tables with metadata and stable **identifiers** for **idempotency**.
3. **Transform** into **silver** and **gold** models via SQL views or materializations, orchestrated on a schedule.

```
raw  ->  silver  ->  gold
(land)   (clean)    (modeled for BI)
```

## Common Patterns
- **Incremental models** with **watermarks** or **change data capture** (**CDC**).
- **Surrogate keys** and **upserts/merges** for deduplication and late arriving data.
- **Materialized views** or table materializations for latency sensitive dashboards.
- **Medallion** layering in lakehouses bronze → silver → gold.
- **Data contracts** on inputs and outputs to control schema changes.

## Governance and Quality
- Enforce **RBAC**, **masking**, and **row/object policies** in warehouse.
- Add **tests** on models and freshness checks in **dbt**.
- Monitor **SLA/SLO** using query logs, model run times, and data **observability** signals.

## Example: Minimal dbt ELT (conceptual)
```sql
-- models/stg_customers.sql
select
  cast(id as bigint) as customer_id,
  lower(email) as email,
  coalesce(country, 'unknown') as country,
  created_at::timestamp as created_at
from { source('raw', 'customers') }

-- models/dim_customer.sql  (gold)  materialized as table
select
  customer_id,
  email,
  country,
  date_trunc('day', created_at) as signup_day
from { ref('stg_customers') }
```

## Related Concepts
- [[ELT vs ETL]] – comparison and decision factors.
- [[ETL]] – transform outside then load curated data.
- [[Data Warehouse]] – the compute engine for ELT.
- [[Data Lake]] – low cost raw landing zone.
- [[Medallion Architecture]] – bronze silver gold layering.
- [[Data Ingestion]] – connectors and pipelines feeding ELT.
- [[Dimensional Modeling]] – shaping gold tables.
- [[Orchestration]] – scheduling and dependencies for runs.

## See Also
- [dbt: What is ELT](https://docs.getdbt.com/docs/introduction)
- [Snowflake: ELT overview](https://docs.snowflake.com/en/guides-overview-elt)
- [BigQuery: Transform data using SQL](https://cloud.google.com/bigquery/docs/reference-standard-sql)

## Terms
[[extract]], [[load]], [[transform]], [[raw data]], [[staging area]], [[compute pushdown]], [[optimizer]], [[dbt]], [[materialization]], [[incremental model]], [[watermark]], [[CDC]], [[surrogate key]], [[upsert]], [[merge]], [[time travel]], [[lineage]], [[data contract]], [[observability]], [[SLA]]
