---
title: "dbt Core Concepts"
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

![[dbt Core Concepts.png]]


## **One-liner**
**dbt** turns **SQL** + a bit of **Jinja** into a tested, versioned, dependency-aware **ELT** workflow that compiles to your warehouse and documents itself.

## The Big Idea
- Treat transformations as **code**: modular **models**, declarative **dependencies**, **tests**, and **docs** all in Git.
- dbt **compiles** templated SQL (Jinja) into plain SQL and runs it on your **data warehouse** (Snowflake, BigQuery, Postgres, etc.).
- Your project DAG is built from `ref()`/**sources**; materializations control **tables/views/incremental** behavior.

## Core Pieces
- **Model** — a `.sql` file that becomes a view/table. Use `ref('other_model')` to declare deps (builds the DAG).
- **Materialization** — how a model is persisted: **view**, **table**, **incremental**, **ephemeral**, **materialized view** (adapter-specific).
- **Source** — declares external/raw tables, enabling freshness checks and lineage to upstream systems.
- **Seed** — CSV files versioned in repo → loaded as small lookup tables.
- **Snapshot** — tracks history of a mutable source table (like SCD Type 2) with `check` or `timestamp` strategy.
- **Tests** — assertions like `not_null`, `unique`, `accepted_values`, plus custom tests; fail the build on violations.
- **Docs** — combine model descriptions, columns, tests into auto-generated site with lineage graph.
- **Packages** — reusable macros/models (dbt-utils, dbt-expectations) managed via `packages.yml`.
- **Macros** — Jinja functions to DRY up SQL; leverage **adapter** macros for cross-database compatibility.
- **Exposures** — document downstream use (dashboards, ML jobs) to close the lineage loop.
- **Artifacts** — `manifest.json` and `run_results.json` for CI, lineage, and observability tooling.

## Typical Folder Layout
```
dbt_project.yml
models/
  staging/
  marts/
    core/
    finance/
seeds/
macros/
snapshots/
tests/
packages.yml
```

## Materializations in Practice
- **view** — cheap to build, compute on read; good for **staging**/**silver**.
- **table** — persisted snapshot; good for **gold** marts and BI.
- **incremental** — process only new/changed rows using a **watermark**/**unique key**; optionally **merge** late data.
- **ephemeral** — inlined as CTEs at compile time; reduces temp tables but watch query length.

## Example Models
```sql
-- models/stg_orders.sql
with src as (
  select * from {{ source('raw', 'orders') }}
)
select
  cast(id as bigint) as order_id,
  customer_id,
  {{ dbt_utils.safe_cast("order_ts", api.Column.translate_type("timestamp")) }} as order_ts,
  lower(status) as status
from src
```

```sql
-- models/fct_orders.sql  (materialized as table)
{{ config(materialized='table') }}
select
  date_trunc('day', order_ts) as order_day,
  count(*) as orders
from {{ ref('stg_orders') }}
group by 1
```

## Testing & Docs (YAML)
```yaml
version: 2
models:
  - name: stg_orders
    description: "Cleaned orders staging layer"
    columns:
      - name: order_id
        tests: [not_null, unique]
      - name: status
        tests:
          - accepted_values:
              values: ['paid','shipped','refunded']
  - name: fct_orders
    description: "Daily orders fact"
sources:
  - name: raw
    tables:
      - name: orders
        freshness:
          warn_after: {count: 2, period: hour}
          error_after: {count: 6, period: hour}
```

## Incremental Pattern (conceptual)
```sql
{{ config(materialized='incremental', unique_key='order_id') }}
select *
from {{ ref('stg_orders') }}
{% if is_incremental() %}
where order_ts > (select coalesce(max(order_ts), '1900-01-01') from {{ this }})
{% endif %}
```

## CI & Environments
- Run `dbt build` in **CI** on PRs; require green **tests** and **freshness**.
- Use profiles or env-vars for **dev/staging/prod**; isolate **schemas** per developer to allow parallel work.
- Track artifacts (`manifest.json`) to power docs and **lineage** in catalogs.

## Common Gotchas
- Missing `ref()`/`source()` → broken lineage and non-deterministic build order.
- Overusing **table** materializations → storage bloat and slow rebuilds; prefer **view**/**ephemeral** for staging.
- Weak **unique keys** on incrementals → duplicates; define a stable **business key** and **merge** logic.
- Not documenting **grain** and **SLA** → confusing downstream usage.

## Related Concepts
- [[ELT]]  
- [[Data Warehouse]]  
- [[Dimensional Modeling (Kimball)]]  
- [[Medallion Architecture (Bronze/Silver/Gold)]]  
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]  
- [[Data Quality & Testing (Great Expectations)]]  
- [[Change Data Capture (CDC)]]

## See Also
- [dbt Documentation](https://docs.getdbt.com/docs/introduction)
- [dbt Best Practices](https://docs.getdbt.com/best-practices/overview)
- [dbt Hub (packages)](https://hub.getdbt.com/)
- [dbt-utils package](https://hub.getdbt.com/dbt-labs/dbt_utils/latest/)

## Terms
[[model]], [[materialization]], [[view]], [[table]], [[incremental model]], [[ephemeral model]], [[ref]], [[source]], [[seed]], [[snapshot]], [[test]], [[accepted_values]], [[unique key]], [[watermark]], [[merge]], [[macro]], [[package]], [[adapter]], [[manifest.json]], [[run_results.json]], [[DAG]], [[lineage]], [[environment]], [[profile]], [[schema]], [[docs]], [[exposure]]
