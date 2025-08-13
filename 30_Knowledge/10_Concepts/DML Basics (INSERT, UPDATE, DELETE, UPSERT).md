---
title: "DML Basics (INSERT, UPDATE, DELETE, UPSERT)"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 10
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[DML Basics (INSERT, UPDATE, DELETE, UPSERT).png]]

## **One-liner**
Change data safely with **INSERT**, **UPDATE**, **DELETE**, and **UPSERT** patterns (including **MERGE**) while keeping operations **idempotent**, predictable, and tied to stable **business keys**.

## The Big Idea
- DML (Data Manipulation Language) mutates rows. Production-safe DML is **transactional**, **idempotent**, and keyed by a **unique**/**primary key** you can trust.
- Prefer **UPSERT/MERGE** for incremental loads and late-arriving data; avoid duplicate inserts and non-deterministic updates.
- Stage → validate → **MERGE** into target is the bread-and-butter ELT workflow.

## Core Statements
- **INSERT** — add rows to a table; optionally with a column list and `DEFAULT` values.  
- **UPDATE** — modify existing rows matched by a selective `WHERE`.  
- **DELETE** — remove rows matched by a selective `WHERE`; sometimes use **soft deletes** (a flag).  
- **UPSERT** — insert or update depending on key existence: `INSERT ... ON CONFLICT` (Postgres) or ANSI **MERGE** in warehouses.  
- **TRANSACTION** — bundle steps atomically (`BEGIN/COMMIT/ROLLBACK`).

## Examples

### INSERT (with explicit columns)
```sql
insert into dim_product (product_id, name, price)
values (101, 'Widget', 12.30);
```

### UPDATE (safe pattern via CTE)
```sql
-- Update only intended rows; CTE helps preview the set
with to_fix as (
  select product_id from dim_product where price < 0
)
update dim_product p
set price = 0
from to_fix t
where p.product_id = t.product_id;
```

### DELETE (targeted)
```sql
delete from sessions
where last_seen < timestamp '2024-01-01 00:00:00';
```

### UPSERT (PostgreSQL: ON CONFLICT)
```sql
insert into dim_customer (customer_id, email, country)
values (1001, 'a@ex.com', 'NL')
on conflict (customer_id) do update
set email = excluded.email,
    country = excluded.country;
```

### MERGE (ANSI / Warehouses)
```sql
merge into silver.orders as t
using staging.orders_delta as s
on t.order_id = s.order_id
when matched and s.op = 'D' then delete
when matched and s.op in ('U','R') and s.op_ts > t.op_ts then
  update set amount = s.amount, status = s.status, op_ts = s.op_ts
when not matched and s.op in ('C','R') then
  insert (order_id, customer_id, amount, status, op_ts)
  values (s.order_id, s.customer_id, s.amount, s.status, s.op_ts);
```

### Transactions & Idempotency
```sql
begin;
  -- 1) stage incoming batch
  create temporary table _stage as
  select * from external_feed where batch_id = 20250813;

  -- 2) validate (row counts, keys unique)
  -- 3) merge into target (idempotent by unique key)
  merge into silver.users t
  using _stage s
    on t.user_id = s.user_id
  when matched then update set name = s.name, updated_at = s.updated_at
  when not matched then insert (user_id, name, updated_at) values (s.user_id, s.name, s.updated_at);
commit;
```

## Practical Patterns
- **Idempotent ELT**: key writes by a **stable business key** (and optionally a **version/op_ts**); running the same batch twice yields the same result.  
- **Soft delete**: keep history with a `is_deleted` flag and `deleted_at`; or apply CDC ops in **MERGE**.  
- **Selective updates**: include a **staleness check** (`s.op_ts > t.op_ts`) to avoid out-of-order overwrites.  
- **Audit columns**: `created_at`, `updated_at`, `source_batch_id`, `inserted_by`, `updated_by`.  
- **Staging first**: load to a **staging** table, validate uniqueness and types, then **MERGE** into the target.  
- **Retry-safe** loads: wrap in a **transaction** or use **merge-once** semantics (unique key + deterministic set).

## Gotchas
- Missing **WHERE** in `UPDATE/DELETE` — catastrophic changes. Always preview with a `SELECT` first.  
- UPSERT without a **unique**/**primary key** → duplicates or row churn. Define constraints/tests.  
- Non-deterministic updates (no `op_ts` or version check) — older data can overwrite newer.  
- Casting columns in predicates breaks **sargability** and can make updates scan the entire table.  
- In some warehouses, **constraints** aren’t enforced; simulate with **dbt tests** and **MERGE** logic.

## Interview Checks (self-test)
- Write an **UPSERT** in Postgres for `dim_customer` keyed by `customer_id`.  
- Implement a **MERGE** that handles CDC ops (C/U/D) with an `op_ts` freshness check.  
- Show how to make an incremental load **idempotent** (stable key + merge).  
- Explain how you’d safely rollback a bad batch (transaction or snapshot/time-travel if table format supports it).

## Related Concepts
- [[Table Design & Constraints (PK, FK, UNIQUE, CHECK, NOT NULL)]]  
- [[SQL Data Types & Casting Essentials]]  
- [[SQL NULL & Three-Valued Logic]]  
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]]  
- [[Query Optimization Basics & EXPLAIN Lite]]  
- [[ELT]]  
- [[Data Warehouse]]

## See Also
- PostgreSQL: INSERT/UPDATE/DELETE — https://www.postgresql.org/docs/current/dml.html  
- PostgreSQL: ON CONFLICT (UPSERT) — https://www.postgresql.org/docs/current/sql-insert.html#SQL-ON-CONFLICT  
- Snowflake: MERGE — https://docs.snowflake.com/en/sql-reference/sql/merge  
- BigQuery: MERGE — https://cloud.google.com/bigquery/docs/reference/standard-sql/dml-syntax#merge_statement

## Terms
[[DML]], [[insert]], [[update]], [[delete]], [[upsert]], [[merge]], [[on conflict]], [[business key]], [[primary key]], [[idempotency]], [[transaction]], [[commit]], [[rollback]], [[staging table]], [[soft delete]], [[cdc]], [[op_ts]], [[sargable predicate]]
