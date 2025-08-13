---
title: "Set Operations & DISTINCT"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 04
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[Set Operations & DISTINCT.png]]

## **One-liner**
Use **set operations** (**UNION**, **UNION ALL**, **INTERSECT**, **EXCEPT/MINUS**) and **DISTINCT** deliberately to combine results and control **duplicates** without masking modeling issues.

## The Big Idea
- **UNION** removes duplicates; **UNION ALL** keeps everything. Removing dups costs CPU/memory and may sort/hash the whole result.
- Set ops compare rows **positionally**. Columns must have the same **count** and compatible **types**; engines may do **implicit casts**.
- **DISTINCT** applies to the whole **SELECT-list** row. Prefer targeted **dedup** (e.g., **ROW_NUMBER()** + filter) when you need the “latest” per key.

## Core Concepts
- **UNION** — concatenates and deduplicates rows across inputs.  
- **UNION ALL** — concatenates without dedup (faster).  
- **INTERSECT** — rows common to both inputs.  
- **EXCEPT** (aka **MINUS**) — rows in left not in right.  
- **DISTINCT** — removes duplicate rows after projection.  
- **Set semantics & NULL** — for set ops and DISTINCT, equality is based on “**IS NOT DISTINCT FROM**” semantics; two **NULL**s are treated as equal for dedup.

## Examples
```sql
-- 1) Union traffic from two sources (fast path first)
select user_id, event_day from web_events
union all
select user_id, event_day from app_events;

-- 2) Dedup explicitly (keep one row per (user_id, event_day))
select user_id, event_day
from (
  select user_id, event_day,
         row_number() over (partition by user_id, event_day order by 1) as rn
  from (
    select user_id, event_day from web_events
    union all
    select user_id, event_day from app_events
  ) u
) t
where rn = 1;

-- 3) INTERSECT: users who appear in both systems
select user_id from web_users
intersect
select user_id from app_users;

-- 4) EXCEPT/MINUS: orders missing payments
select order_id from orders
except
select order_id from payments;

-- 5) DISTINCT pitfalls: whole-row dedup
-- This dedupes on (user_id, country) together
select distinct user_id, country from users;

-- 6) Postgres-only helper: DISTINCT ON (first by sort)
-- Keep the latest order per customer (Postgres)
select distinct on (customer_id) customer_id, order_id, order_ts
from orders
order by customer_id, order_ts desc;
```

## Gotchas
- Blindly using **UNION** where **UNION ALL** is correct → unnecessary dedup and cost.  
- Relying on **DISTINCT** to paper over many-to-many **JOIN**s — fix the join or pre-aggregate.  
- Column order/type mismatch across operands → implicit **coercion** or errors; cast explicitly.  
- Assuming sort order after set ops — order is **undefined** without **ORDER BY**.  
- `COUNT(DISTINCT ...)` on massive tables is expensive; consider **approximate** distinct where available.

## Practical Patterns
- Prefer **UNION ALL** + targeted dedup with **window functions** when you need per-key rules (e.g., latest record).  
- For audit/reconciliation, **EXCEPT** and **FULL JOIN** are complementary: EXCEPT finds **missing** rows; FULL JOIN shows differences side by side.  
- Use **QUALIFY** (if available) to filter window results post-SELECT instead of wrapping subqueries.

## Interview Checks (self-test)
- Explain when to use **UNION** vs **UNION ALL**.  
- Show why **DISTINCT** dedupes by the entire row and how to dedupe per key with **ROW_NUMBER()**.  
- Find rows present in A but not B using **EXCEPT** and using **LEFT JOIN … IS NULL**.

## Related Concepts
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]]  
- [[SQL NULL & Three-Valued Logic]]  
- [[Aggregations & GROUP BY and HAVING]]  
- [[SQL Patterns & Window Functions for Data Engineers]]  
- [[Subqueries & EXISTS Basics]]  
- [[Query Optimization Basics & EXPLAIN Lite]]

## See Also
- PostgreSQL: Set operations — https://www.postgresql.org/docs/current/queries-union.html  
- BigQuery: Set operators — https://cloud.google.com/bigquery/docs/reference/standard-sql/query-syntax#set-operators

## Terms
[[set operation]], [[union]], [[union all]], [[intersect]], [[except]], [[minus]], [[distinct]], [[duplicate]], [[deduplication]], [[window function]], [[row_number]], [[qualify]], [[implicit cast]], [[type coercion]]
