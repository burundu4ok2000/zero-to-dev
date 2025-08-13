---
title: "Ordering & Pagination (ORDER BY, LIMIT/OFFSET, Keyset)"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 08
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[Ordering & Pagination (ORDER BY, LIMIT/OFFSET, Keyset).png]]

## **One-liner**
Sort **deterministically** with **ORDER BY**, and paginate efficiently using **keyset (seek) pagination** instead of heavy **LIMIT/OFFSET** on big tables.

## The Big Idea
- SQL result sets are **unordered** unless you specify **ORDER BY**. Always include explicit sort keys and deterministic **tie-breakers**.
- **OFFSET** works but slows down linearly as N grows (the engine still scans/skips N rows). **Keyset** pagination uses a stable **cursor** (e.g., `(event_ts, id)`) and a `WHERE` clause to fetch the **next page** efficiently.
- Sorting interacts with **NULLS FIRST/LAST**, collations, and stable ordering; be explicit to avoid surprises.

## Core Concepts
- **ORDER BY** — defines output order; applied after `SELECT` (and window calculations).  
- **Deterministic order** — include a stable tie-breaker (e.g., `id`) to avoid random reshuffles between runs.  
- **LIMIT / FETCH** — cap the number of rows returned.  
- **OFFSET** — skip N rows; avoid for deep pages.  
- **Keyset (seek) pagination** — use last seen sort key in a `WHERE` predicate to get the next page.  
- **NULLS FIRST/LAST** — control placement of NULLs (dialect-specific defaults vary).  
- **Composite ordering** — sort by multiple columns to stabilize order and pagination.

## Examples
```sql
-- 1) Deterministic sorting (tie-breaker)
select order_id, customer_id, order_ts
from orders
order by order_ts desc, order_id desc;

-- 2) Basic pagination (LIMIT/OFFSET) -- simple but slows with deep offsets
select order_id, order_ts
from orders
order by order_ts desc, order_id desc
limit 50 offset 1000;  -- engine still scans/skips first 1000

-- 3) Keyset pagination (seek method) -- efficient
-- Page 1
select order_id, order_ts
from orders
order by order_ts desc, order_id desc
limit 50;

-- Suppose last row on page 1 is (order_ts='2025-08-01 12:00:00', order_id=12345).
-- Page 2: fetch rows "after" that composite key
select order_id, order_ts
from orders
where (order_ts, order_id) < (timestamp '2025-08-01 12:00:00', 12345)
order by order_ts desc, order_id desc
limit 50;

-- 4) Handling NULLs explicitly
select * from users
order by last_login nulls last, user_id;

-- 5) Standard FETCH syntax (ANSI)
select * from events
order by event_ts
fetch first 100 rows only;
```

## Gotchas
- Relying on implicit order (no **ORDER BY**) — not portable or reliable.  
- Sorting by an expression on large tables without clustering/indexing — expensive; consider precomputed columns.  
- Using **OFFSET** for deep pages — leads to slow scans and unstable UX as data changes.  
- Missing tie-breaker → duplicate/missing rows across pages as new records arrive.  
- Sorting on non-deterministic functions (`random()`) for production paging — avoid.  
- Different default **NULLS FIRST/LAST** per engine — always specify if it matters.

## Practical Patterns
- Define a **composite sort key** that is unique and monotonic enough, e.g., `(event_ts, id)` or `(created_at, id)`.  
- Return a **cursor token** (the last key values) to the client; avoid exposing raw **OFFSET**.  
- For date-based browsing, partition/prune by day, then sort within the day for smaller working sets.  
- When mixing **filters** and pagination, keep predicates **sargable** so engines can prune data before sorting.  
- For stable “latest first” feeds, consider **keyset** + **window** flag to mark the last row `is_last_in_page` on the server side.

## Interview Checks (self-test)
- Show why **OFFSET** degrades for deep pages and rewrite with **keyset**.  
- Add a correct **tie-breaker** to fix non-deterministic sorting.  
- Handle **NULL** ordering explicitly and explain engine defaults.  
- Implement pagination when users can apply dynamic filters by date/status without breaking sargability.

## Related Concepts
- [[Filtering & Predicates (WHERE, IN, BETWEEN, LIKE)]]
- [[SQL Patterns & Window Functions for Data Engineers]]
- [[Query Optimization Basics & EXPLAIN Lite]]
- [[Dates, Times & Time Zones in SQL]]
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]]

## See Also
- PostgreSQL: ORDER BY — https://www.postgresql.org/docs/current/queries-order.html  
- SQL standard FETCH — https://jakewheat.github.io/sql-overview/part2.html#fetch-first  
- Use the Index, Luke!: Pagination — https://use-the-index-luke.com/no-offset

## Terms
[[order by]], [[limit]], [[offset]], [[fetch first]], [[keyset pagination]], [[seek method]], [[cursor]], [[composite key]], [[tie-breaker]], [[nulls first]], [[nulls last]], [[deterministic order]], [[stable sort]]
