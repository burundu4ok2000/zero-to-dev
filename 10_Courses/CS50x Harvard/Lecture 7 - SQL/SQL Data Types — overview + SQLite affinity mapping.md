---
title: "SQL Data Types — overview + SQLite affinity mapping"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 20
status: "in-progress"
difficulty: "easy"
date: "2025-10-04"
timecode: "00:04:58 (CS50 Shorts — Data Types)"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-04 at 17.14.21.png]]

## Summary
Columns in an **SQL** table store values of a **data type**. Engines like **PostgreSQL** and **MySQL** enforce types strongly (e.g., **INT**, **VARCHAR**, **DATE**). **SQLite** is looser: it uses **type affinity** (five families: **INTEGER**, **REAL**, **TEXT**, **BLOB**, **NUMERIC**) and *coerces* your declared type name to one of those families. Knowing both models helps you write portable schemas and avoid nasty surprises.

## Very simple
Think of each column as a **labeled box**: some boxes are for numbers, some for text, some for dates. In SQLite, the labels are more flexible stickers; in Postgres/MySQL, they’re rigid labels.

## Common SQL types (strict engines like Postgres/MySQL)
- **INT**, **SMALLINT**, **TINYINT**, **MEDIUMINT**, **BIGINT** — integer sizes (range increases with size).  
- **DECIMAL/NUMERIC(p, s)** — exact fixed‑point numbers (money).  
- **FLOAT/DOUBLE** — approximate real numbers.  
- **BIT** — bit fields/flags.  
- **CHAR(n)** — fixed‑length string; **VARCHAR(n)** — variable‑length string (max n).  
- **TEXT** — long text.  
- **BINARY/VARBINARY** and **BLOB** — raw bytes.  
- **DATE**, **TIME**, **TIMESTAMP**, **DATETIME** — temporal values.  
- **ENUM** — string chosen from a fixed set (engine‑specific; MySQL).  
- **GEOMETRY/LINESTRING** — spatial types (extensions).

## SQLite’s type affinity (how it maps names)
SQLite looks at the **type name** and picks an affinity:
- contains `"INT"` → **INTEGER**  
- contains `"CHAR"`, `"CLOB"`, or `"TEXT"` → **TEXT**  
- contains `"BLOB"` or no type given → **BLOB**  
- contains `"REAL"`, `"FLOA"`, or `"DOUB"` → **REAL**  
- otherwise → **NUMERIC**

**Effect:** `VARCHAR(255)` behaves as **TEXT**; `DECIMAL(10,2)` becomes **NUMERIC**; `BIGINT` becomes **INTEGER**. SQLite stores almost any value in any column, but compares/sorts according to the column’s **affinity**.

## Quick examples

### Postgres/MySQL‑style DDL
```sql
CREATE TABLE orders (
  id        BIGINT PRIMARY KEY,
  total     DECIMAL(12, 2) NOT NULL,
  status    VARCHAR(16)    NOT NULL,
  created_at TIMESTAMP     NOT NULL
);
```

### SQLite equivalent (with constraints to keep it sane)
```sql
CREATE TABLE orders (
  id         INTEGER PRIMARY KEY,                     -- rowid-backed
  total      NUMERIC NOT NULL CHECK(total >= 0),
  status     TEXT    NOT NULL CHECK(status IN ('new','paid','shipped','canceled')),
  created_at TEXT    NOT NULL                        -- store ISO8601 string 'YYYY-MM-DDTHH:MM:SSZ'
);
```

### Dates/times tip
In SQLite, store **ISO 8601** strings or Unix seconds in **INTEGER**. Use built-ins like `date('now')`, `datetime('now')`, or `strftime(...)` for queries.

## Portability gotchas
- **VARCHAR(n)** limits are enforced in MySQL/Postgres; **ignored** by SQLite (it treats as **TEXT**). Use **CHECK** to enforce length if needed.  
- **ENUM** doesn’t exist in SQLite or Postgres (Postgres has its own `ENUM` type, different semantics). Prefer separate lookup tables + **FOREIGN KEY** or **CHECK**.  
- **Money/precision**: prefer **DECIMAL/NUMERIC** (exact) over **FLOAT/DOUBLE** (approximate) for currency. In SQLite, use **NUMERIC** plus a **CHECK**, or store **cents as INTEGER**.  
- **Binary** data: in SQLite use **BLOB**; in Postgres/MySQL you can use **BYTEA/VARBINARY/BLOB**.  
- **Spatial** types require extensions (PostGIS, MySQL spatial).

## Choosing types (rules of thumb)
- Use the **smallest exact type** that fits your range.  
- Use **INTEGER** surrogate keys; add **FOREIGN KEY**s for relationships.  
- Use **TEXT** for human strings; pick a **collation** if case/locale matters.  
- Use **DECIMAL/NUMERIC** for money; **REAL/DOUBLE** only for scientific/approx values.  
- For SQLite, *declare like strict SQL*, then **enforce with CHECK/UNIQUE** and app validation.

## Related Concepts
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]]  
- [[CREATE TABLE + FOREIGN KEY (shows/ratings) — what it does]]  
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]]  
- [[SQL Clause Order — Syntax vs Execution + Common Mistakes]]  
- [[Indexes — speed up WHERE/JOIN/ORDER BY]]  
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]]  
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]]  
- [[CSV — Comma-Separated Values]]

## See also
- SQLite Type Affinity: https://sqlite.org/datatype3.html  
- PostgreSQL Data Types: https://www.postgresql.org/docs/current/datatype.html  
- MySQL Data Types: https://dev.mysql.com/doc/refman/8.0/en/data-types.html

## Terms
[[INT]], [[SMALLINT]], [[TINYINT]], [[MEDIUMINT]], [[BIGINT]], [[DECIMAL]], [[NUMERIC]], [[FLOAT]], [[DOUBLE]], [[BIT]], [[CHAR]], [[VARCHAR]], [[TEXT]], [[BLOB]], [[BINARY]], [[VARBINARY]], [[DATE]], [[TIME]], [[TIMESTAMP]], [[DATETIME]], [[ENUM]], [[GEOMETRY]], [[LINESTRING]], [[INTEGER]], [[REAL]], [[NUMERIC affinity]], [[TEXT affinity]], [[BLOB affinity]], [[type affinity]]
