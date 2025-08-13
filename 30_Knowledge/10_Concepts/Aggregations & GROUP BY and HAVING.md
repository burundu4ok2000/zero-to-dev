---
title: "Aggregations & GROUP BY and HAVING"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 05
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[Aggregations & GROUP BY and HAVING.png]]

## **One-liner**
Aggregate safely with **GROUP BY** and **HAVING** by choosing the right **grain**, understanding how **NULL**s behave, and avoiding double counting.

## The Big Idea
- **GROUP BY** defines the **grain** (level of detail) of your result. Every non-aggregated column must be in the **GROUP BY**.
- Use **WHERE** to filter rows **before** grouping and **HAVING** to filter **after** aggregates are computed.
- **COUNT(col)** ignores **NULL**; **COUNT(*)** counts rows. **COUNT(DISTINCT col)** is expensive on huge tables—prefer **approximate** functions if available.

## Core Concepts
- **Aggregate functions**: **SUM**, **AVG**, **MIN**, **MAX**, **COUNT**, **COUNT DISTINCT**.  
- **Grain**: the unique key of the result (e.g., `(day, country)` for daily country metrics).  
- **Pre-aggregation**: reduce rows before joins to avoid many-to-many explosions.  
- **Window functions vs aggregates**: windows return row-level results; aggregates collapse rows.  
- **NULL semantics**: **AVG/SUM** ignore NULL values; `SUM(NULL)` → NULL only if all values are NULL.

## Examples
```sql
-- 1) Daily revenue (set result grain explicitly)
select
  date(order_ts) as day,
  sum(amount)    as revenue
from orders
where status = 'paid'
group by day;

-- 2) Filter by aggregate: only days with revenue > 0
select date(order_ts) as day, sum(amount) as revenue
from orders
group by day
having sum(amount) > 0;

-- 3) Unique active users per day (COUNT DISTINCT is costly at scale)
select day, count(distinct user_id) as dau
from events
group by day;

-- 4) Pre-aggregate then join (avoid double counting)
with payments_by_order as (
  select order_id, sum(amount) as paid
  from payments
  group by order_id
)
select o.customer_id, sum(p.paid) as total_paid
from orders o
join payments_by_order p on p.order_id = o.order_id
group by o.customer_id;

-- 5) Approximate distinct (dialect-specific; example: BigQuery)
-- select day, approx_count_distinct(user_id) as dau
-- from events group by day;
```

## Gotchas
- Mixing columns of different **grain** in one SELECT (e.g., `country` with `customer_id`) without grouping correctly.  
- Counting after a many-to-many **JOIN** → duplicates. Pre-aggregate on each side before the join.  
- Relying on **DISTINCT** to fix modeling mistakes; define clear keys/grain instead.  
- `COUNT(DISTINCT ...)` on very wide/high-cardinality data is slow; consider **approximate** functions or sketch tables.  
- Grouping by **computed expressions** can block partition pruning; compute early in a **CTE** if needed.

## Practical Patterns
- Define the grain first—write it as a comment or CTE output keys.  
- Use half-open ranges for time filters to avoid boundary bugs (`>= start AND < next_start`).  
- For “top-k per group,” prefer **window functions** (`ROW_NUMBER()`) over nested **GROUP BY** + **JOIN**.  
- Keep **types** aligned (e.g., cast `order_ts` to **DATE** once) to avoid implicit casts in GROUP BY.

## Interview Checks (self-test)
- Write revenue per `(day, country)` and explain why both columns must be in the **GROUP BY**.  
- Show the difference between `COUNT(*)` and `COUNT(col)` on a table with **NULL**s.  
- Aggregate payments safely across `orders` and `payments` without double counting.  
- Rewrite a slow `COUNT(DISTINCT user_id)` into an approximate version (if the engine supports it).

## Related Concepts
- [[SQL NULL & Three-Valued Logic]]  
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]]  
- [[Set Operations & DISTINCT]]  
- [[SQL Patterns & Window Functions for Data Engineers]]  
- [[Query Optimization Basics & EXPLAIN Lite]]  
- [[Data Warehouse]]

## See Also
- Snowflake: Aggregate functions — https://docs.snowflake.com/en/sql-reference/functions-aggregate  
- BigQuery: GROUP BY — https://cloud.google.com/bigquery/docs/reference/standard-sql/group-by  
- PostgreSQL: GROUP BY / HAVING — https://www.postgresql.org/docs/current/queries-table-expressions.html#QUERIES-GROUP

## Terms
[[aggregate]], [[GROUP BY]], [[HAVING]], [[grain]], [[SUM]], [[AVG]], [[MIN]], [[MAX]], [[COUNT]], [[COUNT DISTINCT]], [[approximate distinct]], [[pre-aggregation]], [[double counting]], [[CTE]], [[window function]]
