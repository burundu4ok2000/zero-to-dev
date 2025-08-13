---
title: "Query Optimization Basics & EXPLAIN Lite"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 12
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[Query Optimization Basics & EXPLAIN Lite.png]]

## **One-liner**
Speed up queries by writing **sargable** predicates, pruning **partitions**, minimizing **I/O/shuffle**, and reading **EXPLAIN** to spot bad joins and full scans.

## The Big Idea
- The fastest query reads **less data** and does **less work**. Select only needed columns, filter early, and let the engine skip files/partitions via **predicate pushdown** and **partition pruning**.
- Match **types** on join keys, pre-aggregate to control **grain**, and avoid row-multiplying **many-to-many** joins.
- Use built-in SQL functions instead of heavy UDFs; prefer **approximate** aggregations for huge **COUNT DISTINCT**s.
- Learn to read **EXPLAIN**/**query profile**: scan type, join method/order, estimated vs. actual rows, and shuffle/bytes scanned (warehouses).

## Core Signals to Watch
- **Scan**: sequential/full scan vs. partition/index/cluster pruning.  
- **Join method**: **hash join**, **merge join**, **nested loop**; look for big build/probe sides.  
- **Join order**: small → large often helps; broadcast tiny dims when possible.  
- **Cardinality/estimates**: bad estimates → wrong plans; keep **statistics** fresh.  
- **Shuffle/Exchange** (distributed engines): number of partitions, skew, bytes shuffled.  
- **Projection**: are we selecting `*` or only required columns?

## Quick Wins (Checklist)
- Filter early with **sargable** predicates; cast **literals/params**, not columns.  
- Use **half-open** time ranges; hit **partition**/**cluster** keys.  
- Align join key **types** (no implicit casts).  
- Pre-aggregate on each side before big joins; materialize temp results if needed.  
- Replace `COUNT(DISTINCT ...)` with **approximate** where acceptable.  
- Avoid unnecessary **ORDER BY/DISTINCT**; they sort/hash huge sets.  
- For lakes/warehouses: prefer **Parquet/ORC**, avoid tiny files, and combine outputs.

## Examples

### 1) Read EXPLAIN (PostgreSQL-ish)
```sql
explain
select o.customer_id, sum(o.amount) as revenue
from orders o
join customers c on c.customer_id = o.customer_id
where o.order_ts >= date '2025-01-01'
group by o.customer_id;
-- Look for: sequential scan on orders? partition pruning? join method? estimated rows?
```

### 2) Rewrite non-sargable filter (date cast → range)
```sql
-- bad
where date(order_ts) = date '2025-08-13'
-- good
where order_ts >= timestamp '2025-08-13 00:00:00'
  and order_ts <  timestamp '2025-08-14 00:00:00';
```

### 3) Pre-aggregate before join (avoid m2m blow-up)
```sql
with payments_by_order as (
  select order_id, sum(amount) as paid
  from payments
  group by order_id
)
select o.customer_id, sum(p.paid) as total_paid
from orders o
join payments_by_order p using (order_id)
group by o.customer_id;
```

### 4) Use approximate distinct (dialect-specific)
```sql
-- BigQuery: approx
-- select approx_count_distinct(user_id) from events;
```

### 5) Broadcast the small table (hint/style varies)
```sql
-- Spark SQL / some warehouses support hints
select /*+ BROADCAST(dim) */ *
from fact f
join dim on dim.key = f.key;
```

## Gotchas
- `SELECT *` on wide tables causes massive I/O and disables column pruning.  
- **CTE** materialization (engine-dependent) can block optimization; in some engines CTEs inline, in others they may materialize.  
- Accidental **cross joins** from missing join conditions explode rows.  
- Functions on columns in **WHERE/JOIN** prevent pruning and indexes.  
- Mismatched **collations/types** on join keys lead to slow implicit casts.  
- Over-partitioned lakes produce millions of tiny files; compact before heavy reads.  
- Unbounded window frames and `ORDER BY` on huge sets = expensive sorts.

## Practical Patterns
- Start with a **covering query** (only needed columns) and add pieces gradually while watching **EXPLAIN**.  
- Keep table **statistics** fresh (`ANALYZE` or warehouse auto-stats).  
- Use **staging**/**temp** tables to break complex queries into validated steps.  
- In warehouses, inspect the **query profile** UI: bytes scanned, slots used, shuffle stages; fix the biggest cost first.  
- For skewed joins, pre-salt keys or aggregate first; consider engine-specific **AQE**/**join hints** where safe.

## Interview Checks (self-test)
- Given an `EXPLAIN` showing a full table scan, propose two rewrites that enable pruning.  
- Diagnose a slow join due to implicit casts and fix the schema/query.  
- Reduce a heavy `COUNT(DISTINCT user_id)` while keeping acceptable accuracy.  
- Explain when a **hash join** vs **merge join** is preferable.

## Related Concepts
- [[Filtering & Predicates (WHERE, IN, BETWEEN, LIKE)]]  
- [[SQL Data Types & Casting Essentials]]  
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]]  
- [[Aggregations & GROUP BY and HAVING]]  
- [[Set Operations & DISTINCT]]  
- [[SQL Patterns & Window Functions for Data Engineers]]  
- [[Dates, Times & Time Zones in SQL]]  
- [[Data Formats & Compression for Analytics (CSV-JSON-Parquet-ORC)]]  
- [[Data Warehouse]]

## See Also
- PostgreSQL: EXPLAIN — https://www.postgresql.org/docs/current/sql-explain.html  
- BigQuery: Query explain & statistics — https://cloud.google.com/bigquery/docs/explain  
- Snowflake: Query Profile — https://docs.snowflake.com/en/user-guide/ui-query-profile

## Terms
[[EXPLAIN]], [[query profile]], [[cost]], [[row estimate]], [[cardinality]], [[sequential scan]], [[index scan]], [[partition pruning]], [[predicate pushdown]], [[projection]], [[join order]], [[hash join]], [[merge join]], [[nested loop]], [[broadcast join]], [[shuffle]], [[skew]], [[statistics]], [[ANALYZE]], [[CTE]], [[materialization]], [[sargable predicate]], [[approximate distinct]]
