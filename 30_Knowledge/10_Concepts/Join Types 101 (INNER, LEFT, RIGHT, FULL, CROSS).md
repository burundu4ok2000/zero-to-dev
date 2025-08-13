---
title: "Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 03
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS).png]]

## **One-liner**
Understand **join types** and **join conditions** to combine tables correctly without duplicates or data loss.

## The Big Idea
- Choose a **join type** based on whether unmatched rows should remain in the result.
- Put **filters on the right table** inside the **ON** clause for **LEFT JOIN** to avoid accidentally converting it to **INNER JOIN**.
- Always join on keys with matching **types** and **cardinality**; pre-aggregate to avoid many-to-many explosions.

## Join Types
- **INNER JOIN** — keep only matching rows from both sides.  
- **LEFT JOIN** — keep all rows from the left; right side may be **NULL**.  
- **RIGHT JOIN** — symmetric to left (often avoided in favor of rewriting as **LEFT**).  
- **FULL OUTER JOIN** — keep non-matching rows from both sides.  
- **CROSS JOIN** — Cartesian product (no join condition); use sparingly.

## Examples
```sql
-- 1) LEFT join with filter on right table: put predicate in ON
select o.order_id, o.customer_id, r.reason
from orders o
left join refunds r
  on r.order_id = o.order_id
 and r.status = 'approved';      -- stays a LEFT join

-- 2) Anti-join (orders without refunds)
select o.*
from orders o
left join refunds r on r.order_id = o.order_id
where r.order_id is null;        -- or: where not exists (select 1 ...)

-- 3) FULL OUTER join for reconciliation
select coalesce(a.id, b.id) as id, a.val as a_val, b.val as b_val
from a
full join b on a.id = b.id;

-- 4) CROSS join to generate a small calendar/product matrix
select d.day, p.category
from dim_date d
cross join dim_category p
where d.day between date '2025-08-01' and date '2025-08-07';
```

## Gotchas
- Filtering columns from the right table in **WHERE** after a **LEFT JOIN** turns it into **INNER JOIN**.  
- Many-to-many joins duplicate rows; **dedupe** or **aggregate** first, or use window-based selection.  
- Implicit type casts on join keys (e.g., `TEXT` ↔ `INT`) cause slow scans; align types beforehand.  
- Joining on non-unique keys unintentionally — verify **cardinality** and add constraints/tests.

## Interview Checks (self-test)
- Explain when to place predicates in **ON** vs **WHERE** for **LEFT JOIN**.  
- Write an **anti-join** two ways: `LEFT JOIN ... IS NULL` and `NOT EXISTS`.  
- Reconcile two tables with a **FULL OUTER JOIN** and `COALESCE` to produce a combined key.

## Related Concepts
- [[SQL NULL & Three-Valued Logic]] – how **NULL**s appear on the right side of **LEFT JOIN**.  
- [[Subqueries & EXISTS Basics]] – **EXISTS/NOT EXISTS** as semi/anti-joins.  
- [[Aggregations & GROUP BY and HAVING]] – pre-aggregate to control join **grain**.  
- [[SQL Data Types & Casting Essentials]] – align key **types** to avoid implicit casting.  
- [[SQL Patterns & Window Functions for Data Engineers]] – window-based dedup before joins.

## See Also
- PostgreSQL: JOINs — https://www.postgresql.org/docs/current/queries-table-expressions.html#QUERIES-FROM  
- Snowflake: JOIN syntax — https://docs.snowflake.com/en/sql-reference/constructs/join

## Terms
[[join]], [[join type]], [[inner join]], [[left join]], [[right join]], [[full outer join]], [[cross join]], [[join condition]], [[anti join]], [[semi join]], [[coalesce]], [[cardinality]], [[many-to-many join]], [[implicit cast]]
