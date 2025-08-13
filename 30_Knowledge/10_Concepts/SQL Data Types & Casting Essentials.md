---
title: "SQL Data Types & Casting Essentials"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 02
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[SQL Data Types & Casting Essentials.png]]

## **One-liner**
Choose correct **data types** and explicit **casts** to avoid truncation, precision loss, and **timezone** bugs. Types are contracts; don’t let the engine **coerce** behind your back.

## The Big Idea
- Right types make queries **faster** and **safer**. Use **DECIMAL/NUMERIC** for money; keep timestamps as **UTC**; avoid storing numbers in **TEXT**.
- **Implicit casts** during **JOIN**s and **WHERE** can force table scans and break **partition pruning**. Prefer **explicit** casts on **literals/params**, not on columns.
- Document **nullability** and default values—types + **constraints** express business rules.

## Core Types (pragmatic guide)
- **INTEGER/BIGINT** — identifiers, counters.  
- **DECIMAL/NUMERIC(p,s)** — currency, precise sums (no floating error).  
- **FLOAT/DOUBLE** — scientific/approximate math; not for money.  
- **VARCHAR/TEXT** — strings; validate formats with **CHECK** or at ingest.  
- **BOOLEAN** — flags; beware `'0'/'1'` strings.  
- **DATE/TIME/TIMESTAMP** — store event time as **TIMESTAMP (UTC)**; convert on presentation.  
- **ARRAY/STRUCT/JSON** (dialect-dependent) — semi-structured data; normalize in **ELT** when possible.

## Casting & Conversions
```sql
-- Literals: cast on the literal, not on the column
select *
from orders
where order_ts >= timestamp '2025-01-01 00:00:00+00';

-- Safe numeric parsing (dialect may vary)
select try_cast(price_txt as numeric(12,2)) as price from raw_prices;

-- Normalizing ids before joins
select *
from a
join b on a.user_id = cast(b.user_id as bigint);  -- better: store as the same type

-- Money example
select cast('12.30' as numeric(10,2)) as price;
```

## Practical Patterns
- **Text-to-type** at the edge: cast/validate on **ingest** (Bronze→Silver) so downstream stays clean.  
- Avoid **timezone** footguns: store UTC; keep fields as **TIMESTAMP WITHOUT TIME ZONE** (engine-specific) and convert at query edges.  
- Use **generated columns** or **materialized views** to precompute searchable keys (e.g., `lower(email)`), not functions in hot predicates.  
- For enums, prefer validated **VARCHAR** with a check or a small **dimension** table; true enum types are dialect-specific.

## Gotchas
- Joining `TEXT` to `INT` → implicit cast, no pruning, slow plan. Align types first.  
- Using **FLOAT** for money → rounding errors; use **DECIMAL**.  
- Comparing timestamps with `BETWEEN` (end inclusive) → off-by-one; use half-open ranges.  
- Casting columns in **WHERE** (e.g., `cast(order_ts as date) = ...`) → non-**sargable**.  
- Locale-dependent parsing (`','` vs `'.'`) — parse at ingest and standardize.

## Interview Checks (self-test)
- Explain why `count(col)` differs from `count(*)` with **NULL**s (ties to type/nullable).  
- Show how to safely parse strings to **NUMERIC** and handle bad rows.  
- Describe storing datetimes across timezones and how you’d query “day” robustly.

## Related Concepts
- [[SQL NULL & Three-Valued Logic]]  
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]]  
- [[Aggregations & GROUP BY and HAVING]]  
- [[Filtering & Predicates (WHERE, IN, BETWEEN, LIKE)]]  
- [[Data Warehouse]]  
- [[ELT]]  

## See Also
- PostgreSQL: Data types — https://www.postgresql.org/docs/current/datatype.html  
- BigQuery: Data types — https://cloud.google.com/bigquery/docs/reference/standard-sql/data-types  
- Snowflake: Data types — https://docs.snowflake.com/en/sql-reference/intro-summary-data-types

## Terms
[[data type]], [[cast]], [[try_cast]], [[numeric]], [[decimal]], [[float]], [[double precision]], [[varchar]], [[text]], [[boolean]], [[timestamp]], [[utc]], [[timezone]], [[coercion]], [[implicit cast]], [[sargable predicate]], [[partition pruning]], [[nullability]], [[constraint]]
