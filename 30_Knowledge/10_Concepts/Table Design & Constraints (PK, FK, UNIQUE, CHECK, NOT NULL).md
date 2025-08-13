---
title: "Table Design & Constraints (PK, FK, UNIQUE, CHECK, NOT NULL)"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 09
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[Table Design & Constraints (PK, FK, UNIQUE, CHECK, NOT NULL).png]]

## **One-liner**
Use **constraints** (**PK**, **FK**, **UNIQUE**, **CHECK**, **NOT NULL**) to encode business rules and keep tables consistent, deduped, and queryable.

## The Big Idea
- Constraints are **guardrails**: they prevent bad writes and document assumptions. Even if your warehouse ignores some constraint types at runtime, you should design with them and enforce via **tests** (dbt/GE) or upstream services.
- A good table has a clear **grain** and a stable **key** (prefer a **surrogate key** when the natural one is messy). Foreign keys express **relationships** and enable safe **UPSERT/MERGE** logic.

## Core Concepts
- **PRIMARY KEY (PK)** — uniquely identifies each row; implies **UNIQUE** + **NOT NULL**.  
- **FOREIGN KEY (FK)** — references a parent table to enforce **referential integrity**; may define actions (**ON DELETE/UPDATE**).  
- **UNIQUE** — no duplicate values across specified columns (can be **composite**).  
- **CHECK** — boolean rule per row (e.g., `amount >= 0`).  
- **NOT NULL** — column must have a value; pairs with **DEFAULT** when appropriate.  
- **Surrogate vs Natural key** — generated key (e.g., `identity`) vs business key (e.g., `email`).  
- **Deferrable** (RDBMS) — allow constraint checks at **transaction** end for complex loads.

## Examples (PostgreSQL-flavored DDL)
```sql
-- Dimension table
create table dim_customer (
  customer_id bigserial primary key,               -- surrogate PK
  external_id text unique,                         -- optional natural key
  email text unique,
  country text not null,
  created_at timestamp not null default now(),
  constraint email_has_at check (position('@' in email) > 1)
);

-- Fact table with FK
create table fct_order (
  order_id bigserial primary key,
  customer_id bigint not null references dim_customer(customer_id) on delete restrict,
  order_ts timestamp not null,
  amount numeric(12,2) not null check (amount >= 0)
);

-- Composite uniqueness at the business grain
create unique index uq_order_customer_ts on fct_order (customer_id, order_ts);
```

## Warehouses (Snowflake/BigQuery/Redshift) Notes
- Some engines **don’t enforce** FKs/CHECKs at write time; still define them in **design docs/dbt tests** to protect models.  
- Use **cluster/partition** keys for performance; constraints are for **correctness**.  
- Enforce **uniqueness**/**not null** with dbt tests or **MERGE** patterns during ELT.

## Practical Patterns
- Choose a **stable key** for UPSERTs (e.g., `business_id` + `op_ts`), then add a **surrogate PK** for joins/performance.  
- Validate upstream with **CHECK** constraints or application logic (e.g., `status in (...)`).  
- Add **created_at / updated_at** timestamps and document **SLA** fields (freshness).  
- Prefer **idempotent** loads: stage data, run **MERGE** into target keyed by business key, keep constraints green.  
- For slowly changing dims: SCD Type 2 needs `(business_key, valid_from)` **composite PK** or a unique constraint.

## Gotchas
- Missing **PK** leads to duplicates, broken **joins**, and painful dedupe.  
- Overly strict **CHECK**s block legitimate data; dry-run loads before enabling.  
- Using **RIGHT** keys but wrong **grain** — e.g., unique constraint on `(email)` when same email can exist per tenant. Include **tenant_id**.  
- FK cascade deletes in analytics can remove history; often prefer `restrict` and handle deletes via **soft delete** flags or CDC.  
- Mismatched data types between FK and referenced PK break joins and can force casts.

## Interview Checks (self-test)
- Design `dim_product` and `fct_sales` with proper **PK/FK**, one **CHECK**, and a **UNIQUE** business rule.  
- Explain when to use a **surrogate key** vs a **natural key**.  
- Show how you’d enforce **uniqueness** in a warehouse that doesn’t check constraints at write time.  
- Describe a safe **MERGE** into a constrained table and what happens on violations.

## Related Concepts
- [[SQL Data Types & Casting Essentials]]  
- [[Aggregations & GROUP BY and HAVING]]  
- [[Join Types 101 (INNER, LEFT, RIGHT, FULL, CROSS)]]  
- [[DML Basics (INSERT, UPDATE, DELETE, UPSERT)]]  
- [[SQL NULL & Three-Valued Logic]]  
- [[Dimensional Modeling (Kimball)]]  
- [[Data Warehouse]]  
- [[dbt Core Concepts]]  
- [[Data Quality & Testing (Great Expectations)]]

## See Also
- PostgreSQL: Constraints — https://www.postgresql.org/docs/current/ddl-constraints.html  
- Snowflake: Constraints & properties — https://docs.snowflake.com/en/sql-reference/constraints-overview  
- BigQuery: Constraints — https://cloud.google.com/bigquery/docs/information-schema-tables#constraints_view

## Terms
[[primary key]], [[foreign key]], [[unique constraint]], [[check constraint]], [[not null]], [[referential integrity]], [[on delete cascade]], [[on delete restrict]], [[on update]], [[deferrable]], [[surrogate key]], [[natural key]], [[composite key]], [[business key]], [[constraint validation]], [[index]], [[sequence]], [[identity]], [[generated identity]], [[default]], [[soft delete]]
