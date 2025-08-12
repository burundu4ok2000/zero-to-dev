---
title: "SQL Patterns & Window Functions for Data Engineers"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[SQL Patterns & Window Functions for Data Engineers.png]]


## **One-liner**
Battle‑tested **SQL** idioms for analytics: **JOIN** patterns (including **semi/anti**), **CTE** pipelines, and **window functions** (**ROW_NUMBER**, **RANK**, **LAG/LEAD**, frames) to solve top‑N, dedup, running totals, and “gaps & islands”.

## The Big Idea
- Most data‑engineering interviews probe your ability to model a problem as **set operations** and **window analytics**, not just basic `GROUP BY`.
- Windows separate **grouping** from **ordering**: you can aggregate over a logical partition while still returning row‑level detail.
- Performance comes from filtering early, correct **JOIN** choice, sensible **frames**, and avoiding unnecessary re‑scans with **CTE** staging.

## Execution Order (mental model)
`FROM` → `WHERE` → `GROUP BY` → `HAVING` → `SELECT` → `ORDER BY` → `LIMIT`  
This explains why window functions (computed in `SELECT`) can’t be used in `WHERE`, but can in `QUALIFY` (where supported) or wrapped.

## Core JOIN Patterns
- **Inner join**: keep matching rows.  
- **Left join**: keep all left rows; right may be NULL.  
- **Semi join** (exists): filter left rows that **have** a match.  
- **Anti join** (not exists): filter left rows that **don’t have** a match.  

```sql
-- semi join
select o.*
from orders o
where exists (select 1 from refunds r where r.order_id = o.order_id);

-- anti join
select o.*
from orders o
where not exists (select 1 from fraud f where f.order_id = o.order_id);
```

## Top‑N per Group (with ties or without)
```sql
-- Without ties: one row per group
select *
from (
  select c.*, row_number() over (partition by country order by revenue desc) as rn
  from customers c
) t
where rn = 1;

-- With ties (all equal top rows)
select *
from (
  select c.*, rank() over (partition by country order by revenue desc) as rk
  from customers c
) t
where rk = 1;
```

## Deduping Rows
```sql
-- Keep latest by business key using ROW_NUMBER
with ranked as (
  select *, row_number() over (partition by order_id order by updated_at desc) as rn
  from bronze_orders
)
select *
from ranked
where rn = 1;
```

## Running Totals & Moving Averages
```sql
-- Running total by customer
select
  customer_id,
  order_ts,
  amount,
  sum(amount) over (partition by customer_id order by order_ts
                    rows between unbounded preceding and current row) as running_amount
from orders;

-- 7‑day moving avg (fixed frame)
select
  day,
  avg(revenue) over (order by day rows between 6 preceding and current row) as ma7
from daily_revenue;
```

## Gaps & Islands (contiguous sequences)
```sql
-- Example: consecutive days of activity per user
with x as (
  select user_id, day,
         row_number() over (partition by user_id order by day) as rn
  from activity
),
g as (
  select user_id, day, (date_part('epoch', day)::int - rn) as grp
  from x
)
select user_id, min(day) as start_day, max(day) as end_day, count(*) as length
from g
group by user_id, grp;
```

## Frame Semantics
- Default is often `RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW` on ordered numeric/date; prefer explicit **ROWS** frames for deterministic results.
- `ROWS` counts physical rows; `RANGE` groups peer rows with same sort value (ties).

## NULL Semantics & Safety
- `NULL` ≠ anything; use `coalesce(col, 0)` in aggregates and `is distinct from` (where supported) to compare safely.  
- Be careful with `count(col)` (ignores NULLs) vs `count(*)` (counts rows).  
- Control sort with `nulls first/last` if supported.

## Performance Hints
- Filter early; **project** only needed columns.  
- Pick the right join direction; ensure join keys are of same **type** / **collation**.  
- Prefer **partitioned**/clustered tables; prune with partitions and clustered keys.  
- Avoid huge unbounded windows; use **frames** or pre‑aggregate in a **CTE**.  
- In warehouses: leverage **QUALIFY** to filter by window results post‑select (BigQuery/Snowflake).

## Related Concepts
- [[Data Warehouse]]
- [[Dimensional Modeling (Kimball)]]
- [[dbt Core Concepts]]
- [[Data Quality & Testing (Great Expectations)]]
- [[ELT vs ETL]]
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]

## See Also
- [PostgreSQL: Window Functions](https://www.postgresql.org/docs/current/tutorial-window.html)
- [Snowflake: Window Functions & QUALIFY](https://docs.snowflake.com/en/sql-reference/functions-analytic)
- [Mode: SQL Window Functions Tutorial](https://mode.com/sql-tutorial/sql-window-functions/)

## Terms
[[INNER JOIN]], [[LEFT JOIN]], [[SEMI JOIN]], [[ANTI JOIN]], [[EXISTS]], [[NOT EXISTS]], [[GROUP BY]], [[HAVING]], [[CTE]], [[window function]], [[OVER clause]], [[PARTITION BY]], [[ORDER BY]], [[frame clause]], [[ROWS BETWEEN]], [[RANGE BETWEEN]], [[ROW_NUMBER]], [[RANK]], [[DENSE_RANK]], [[LAG]], [[LEAD]], [[FIRST_VALUE]], [[LAST_VALUE]], [[running total]], [[moving average]], [[percentile]], [[QUALIFY]], [[NULL semantics]], [[COALESCE]], [[IS DISTINCT FROM]], [[execution order]], [[predicate pushdown]], [[cardinality]], [[skew]], [[deduplication]], [[top-N per group]], [[gaps and islands]]
