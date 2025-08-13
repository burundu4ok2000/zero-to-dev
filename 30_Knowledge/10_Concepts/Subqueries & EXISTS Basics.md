---
title: "Subqueries & EXISTS Basics"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 06
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[Subqueries & EXISTS Basics.png]]

## **One-liner**
Use **subqueries** and **EXISTS** to express **semi**/**anti joins** cleanly and efficiently, avoid surprises with **NULL**, and keep predicates **sargable**.

## The Big Idea
- A subquery can return a **scalar**, a **set** (for `IN`), or a **rowset** used by **EXISTS**.  
- **EXISTS** checks whether the subquery yields **any row** and stops early; it ignores the subquery’s **SELECT list** and is robust to **NULL**s.  
- Prefer **EXISTS/NOT EXISTS** for membership checks on large or **NULL**-containing sets; use `IN` for small, literal lists.

## Core Concepts
- **Scalar subquery** — returns one value (per outer row).  
- **Correlated subquery** — references columns from the outer query.  
- **EXISTS**/**NOT EXISTS** — semi/anti join semantics.  
- **IN**/**NOT IN** — membership by equality; be careful with **NULL** in subquery results.  
- **Sargable predicate** — avoids wrapping columns with functions so engines can prune partitions or use indexes.

## Examples
```sql
-- 1) Scalar subquery: per-user average purchase
select u.user_id,
       (select avg(amount) from orders o where o.user_id = u.user_id) as avg_amount
from users u;

-- 2) EXISTS vs IN (membership check)
-- Prefer EXISTS on large sets or when NULLs may appear
select o.*
from orders o
where exists (select 1 from vip_users v where v.user_id = o.user_id);

-- 3) Anti join with NOT EXISTS (orders without payments)
select o.*
from orders o
where not exists (select 1 from payments p where p.order_id = o.order_id);

-- 4) Rewrite a correlated subquery as a join + aggregate (often faster)
-- latest order per customer
with last_order as (
  select customer_id,
         max(order_ts) as last_ts
  from orders
  group by customer_id
)
select c.customer_id, o.order_id, o.order_ts
from customers c
join last_order lo on lo.customer_id = c.customer_id
join orders o
  on o.customer_id = lo.customer_id and o.order_ts = lo.last_ts;

-- 5) NOT IN gotcha with NULLs (can return 0 rows)
-- If payments.order_id contains NULL, NOT IN behaves unexpectedly
-- Use NOT EXISTS instead:
select o.*
from orders o
where not exists (select 1 from payments p where p.order_id = o.order_id);
```

## Gotchas
- `NOT IN (subquery)` returns no rows if the subquery can produce **NULL**; use **NOT EXISTS**.  
- Correlated subqueries can be slow if executed row-by-row; rewrite as **JOIN** + **GROUP BY** when possible.  
- Wrapping join/filter columns with functions in subqueries breaks **sargability** and partition pruning.  
- Scalar subqueries that return multiple rows cause errors; enforce uniqueness or aggregate.

## Practical Patterns
- Put filters for the right table **inside ON** for **LEFT JOIN**; or express as **EXISTS** for clarity.  
- For “top-1 per group,” prefer **window functions** (`ROW_NUMBER()`) over deeply nested subqueries.  
- Use **QUALIFY** (if supported) to filter by window results without an extra subquery.  
- In warehouses, verify plans with **EXPLAIN** to ensure the engine de-correlates subqueries.

## Interview Checks (self-test)
- Write users who have at least one order using **EXISTS**; then rewrite with **INNER JOIN**.  
- Show an **anti join** both as `LEFT JOIN ... IS NULL` and as `NOT EXISTS`.  
- Explain the **NOT IN + NULL** trap and fix it.  
- Convert a correlated subquery into a **JOIN** + **GROUP BY** and explain why it’s faster.

## Related Concepts
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]]  
- [[SQL NULL & Three-Valued Logic]]  
- [[Filtering & Predicates (WHERE, IN, BETWEEN, LIKE)]]  
- [[SQL Patterns & Window Functions for Data Engineers]]  
- [[Query Optimization Basics & EXPLAIN Lite]]

## See Also
- PostgreSQL: Subqueries — https://www.postgresql.org/docs/current/queries-subqueries.html  
- BigQuery: Subqueries — https://cloud.google.com/bigquery/docs/reference/standard-sql/subqueries

## Terms
[[subquery]], [[scalar subquery]], [[correlated subquery]], [[exists]], [[not exists]], [[in]], [[not in]], [[semi join]], [[anti join]], [[sargable]], [[qualify]]
