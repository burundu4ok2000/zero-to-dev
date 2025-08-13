---
title: "Filtering & Predicates (WHERE, IN, BETWEEN, LIKE)"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 07
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[Filtering & Predicates (WHERE, IN, BETWEEN, LIKE).png]]

## **One-liner**
Write selective **predicates** that let the engine prune data: sargable **WHERE** clauses, careful **IN**/**BETWEEN**, and safe **LIKE** patterns.

## The Big Idea
- Good filters are **sargable** (Search ARGument ABLE): no functions wrapping the column side, types match, ranges are **half-open** for timestamps.
- Use **IN** for small literal lists; prefer **EXISTS** for large, dynamic membership checks.
- **LIKE** is handy but dangerous for performance; leading wildcards (`'%foo'`) block indexes/partition pruning.

## Core Concepts
- **WHERE** filters rows **before** grouping; use **HAVING** for post-aggregation filters.
- **IN / NOT IN**: list membership; beware `NOT IN (subquery)` with **NULL**s → prefer **NOT EXISTS**.
- **BETWEEN** is **inclusive** on both ends; use half-open ranges for time.
- **LIKE / ILIKE** (case-insensitive, dialect-specific); escape `%` and `_` with `ESCAPE` when needed.
- **Sargability**: keep columns bare on the left side of comparisons; cast **literals/params**, not columns.

## Examples
```sql
-- 1) Sargable time range (half-open)
where event_ts >= timestamp '2025-01-01 00:00:00+00'
  and event_ts <  timestamp '2025-02-01 00:00:00+00';

-- 2) Non-sargable vs sargable
-- bad: date(event_ts) = date '2025-01-01'
-- good:
where event_ts >= timestamp '2025-01-01 00:00:00'
  and event_ts <  timestamp '2025-01-02 00:00:00';

-- 3) IN for small sets; EXISTS for large
-- small list
where status in ('paid','shipped','refunded');

-- large/dynamic set (use EXISTS)
where exists (
  select 1 from vip_users v where v.user_id = o.user_id
);

-- 4) LIKE patterns
where email like '%@example.com'        -- suffix: likely non-sargable
-- Better: store/compute domain column
where email_domain = 'example.com';

-- 5) Case-insensitive search (dialect-specific)
where name ilike 'alex%';               -- Postgres
-- or normalized search key
where name_lc like 'alex%';             -- with generated lower(name)

-- 6) Escaping wildcards
where path like 'C:\\%\_temp' escape '\\';  -- treat % and _ literally
```

## Gotchas
- Wrapping columns with functions (`lower(col)`, `date(col)`) in hot predicates → no pruning. Use stored **generated columns** or normalized fields.
- `BETWEEN` on timestamps includes the end value; use half-open ranges to avoid missed/duplicated rows.
- `NOT IN (subquery)` with **NULL** inside the subquery → returns zero rows. Use **NOT EXISTS**.
- Mismatched **types** (TEXT vs INT) in predicates → implicit casts and table scans.
- Relying on implicit order after filtering; add **ORDER BY** for deterministic results.

## Practical Patterns
- Precompute searchable keys (e.g., `email_domain`, `name_lc`) via **ELT** or **generated columns**/**materialized views**.
- Filter on **partition**/**cluster** keys first to leverage pruning in warehouses.
- Combine selective predicates early; select only needed columns to reduce I/O.
- For text search beyond simple LIKE, use proper **full-text search** extensions or search engines.

## Interview Checks (self-test)
- Rewrite a non-sargable date filter into a half-open range.
- Show two ways to find users in a large VIP set (**EXISTS** vs **JOIN**).
- Explain why `name like '%foo'` is slow and propose a schema fix.

## Related Concepts
- [[SQL NULL & Three-Valued Logic]]
- [[SQL Data Types & Casting Essentials]]
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]]
- [[Subqueries & EXISTS Basics]]
- [[Aggregations & GROUP BY and HAVING]]
- [[Query Optimization Basics & EXPLAIN Lite]]
- [[Dates, Times & Time Zones in SQL]]

## See Also
- BigQuery: Filtering best practices — https://cloud.google.com/bigquery/docs/best-practices-performance-compute#filters  
- PostgreSQL: Pattern Matching `LIKE` — https://www.postgresql.org/docs/current/functions-matching.html  
- Snowflake: Search optimization and pruning — https://docs.snowflake.com/en/user-guide/tables-clustering-overview

## Terms
[[predicate]], [[WHERE]], [[IN]], [[NOT IN]], [[EXISTS]], [[BETWEEN]], [[LIKE]], [[ILIKE]], [[ESCAPE clause]], [[sargable predicate]], [[partition pruning]], [[cluster key]], [[half-open interval]], [[generated column]], [[materialized view]], [[full-text search]]
