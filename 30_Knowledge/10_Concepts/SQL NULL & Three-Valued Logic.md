---
title: "SQL NULL & Three-Valued Logic"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 01
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[SQL NULL & Three-Valued Logic.png]]

## **One-liner**
Learn how **NULL** and SQL’s **three-valued logic** work so your filters, **JOIN**s, and **aggregates** don’t lie to you.

## The Big Idea
- SQL doesn’t know only TRUE/FALSE; it also has **UNKNOWN**. Any comparison with **NULL** produces **UNKNOWN**.
- The **WHERE** clause keeps only rows where the predicate is **TRUE**. **UNKNOWN** is dropped, which silently filters rows.
- Aggregates mostly ignore **NULL** (except `COUNT(*)`). Use **COALESCE**/**NULLIF** and safe comparisons to control behavior.

## Core Concepts
- **NULL ≠ ''**: empty string is a value; **NULL** means “unknown/absent”.
- **IS NULL / IS NOT NULL**: never use `= NULL` or `<> NULL`.
- **COUNT(col)** skips **NULL**s; **COUNT(*)** counts rows.
- **COALESCE(expr, fallback)** replaces **NULL** with a fallback value.
- **NULLIF(a, b)** returns **NULL** if `a = b` (avoid divide-by-zero, etc.).
- **IS DISTINCT FROM** (where supported) compares safely even with **NULL**s.

## Practical Patterns
```sql
-- 1) Safe anti join (find orders without approved refunds)
select o.*
from orders o
left join refunds r
  on r.order_id = o.order_id and r.status = 'approved'
where r.order_id is null;  -- NOT EXISTS equivalent

-- 2) Count behavior
select
  count(*)            as rows,
  count(email)        as non_null_emails
from users;

-- 3) Avoid non-sargable date filters
-- bad: where date(order_ts) = date '2025-01-01'
-- good:
where order_ts >= timestamp '2025-01-01 00:00:00'
  and order_ts <  timestamp '2025-01-02 00:00:00';

-- 4) Safe division
select
  sum(amount) / nullif(sum(qty), 0) as avg_price  -- avoids division by zero
from line_items;
```

## Gotchas
- Filtering the right table of a **LEFT JOIN** in the **WHERE** clause turns it into **INNER JOIN**.
- Using `IN (subquery)` when the subquery might yield **NULL** can behave unexpectedly; prefer **EXISTS**.
- Wrapping columns with functions in predicates can defeat indexes/partition pruning (non-**sargable**).
- Relying on default **RANGE** frames in window functions causes surprises with ties; prefer explicit **ROWS** frames.

## Interview Checks (self-test)
- Explain why `WHERE col = NULL` returns zero rows and fix it.
- Show the difference between `COUNT(col)` and `COUNT(*)` on a table with **NULL**s.
- Write an **anti join** two ways: `LEFT JOIN ... WHERE right.id IS NULL` and `WHERE NOT EXISTS (...)`.

## Related Concepts
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]] – how **LEFT JOIN** interacts with **NULL**s.
- [[Set Operations & DISTINCT]] – deduping without ломать семантику **NULL**.
- [[Aggregations & GROUP BY and HAVING]] – grain and **COUNT DISTINCT** with **NULL**s.
- [[SQL Patterns & Window Functions for Data Engineers]] – windows and **frame** semantics.
- [[Data Warehouse]] – why **NULL** handling matters for BI correctness.

## See Also
- PostgreSQL: Functions & NULL handling — https://www.postgresql.org/docs/current/functions-conditional.html
- Snowflake: NULL handling — https://docs.snowflake.com/en/user-guide/null-handling
- SQLite: NULL and three-valued logic — https://www.sqlite.org/nulls.html

## Terms
[[NULL]], [[three-valued logic]], [[UNKNOWN]], [[COALESCE]], [[NULLIF]], [[IS DISTINCT FROM]], [[anti join]], [[semi join]], [[COUNT vs COUNT(*)]], [[sargable predicate]], [[frame clause]]
