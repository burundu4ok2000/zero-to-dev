---
title: "SQLite 3 vs Other SQL Databases — What’s the difference?"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 04
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "00:40:15"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 16.01.06.png]]

## Summary
**SQLite 3** is an **embedded** SQL database: no server, just a single file on disk that your program reads/writes. You still use **SQL**, but the engine is built into your app. Other systems like **PostgreSQL** or **MySQL** are **client–server** databases: you run a database **server** and connect to it over a network.

## Very simple
> Think of data like books.
- **SQLite**: a personal notebook in your backpack — super handy for one person or a small group.  
- **PostgreSQL/MySQL/etc.**: a full library with a librarian — great for many people at once, with strict rules.

## Quick comparison

| Engine         | Kind                 | Where data lives         | Concurrency                            | Features vibe                                                                   | Typical uses                                           |
| -------------- | -------------------- | ------------------------ | -------------------------------------- | ------------------------------------------------------------------------------- | ------------------------------------------------------ |
| **SQLite 3**   | Embedded, file-based | Single **.db** file      | Good for few writers, many readers     | Small, zero‑config, **ACID**, transactions, indices                             | Mobile/desktop apps, prototypes, CLIs, teaching (CS50) |
| **PostgreSQL** | Client–server        | Separate DB server       | Strong **MVCC**, many concurrent users | Rich SQL, **JSONB**, window funcs, CTEs, **extensions** (PostGIS), strict types | Web backends, analytics, GIS, serious prod systems     |
| **MySQL**      | Client–server        | Separate DB server       | Solid concurrency                      | Fast, popular in web, broad tooling; some SQL quirks                            | LAMP stacks, web apps                                  |
| **MariaDB**    | Client–server        | Separate DB server       | Solid concurrency                      | Community fork of MySQL; extra engines/features                                 | Drop‑in alt for MySQL                                  |
| **SQL Server** | Client–server        | Separate DB server       | Enterprise‑grade                       | T‑SQL, strong MS ecosystem, BI tooling                                          | Windows/.NET shops                                     |
| **Oracle DB**  | Client–server        | Separate DB server       | Enterprise‑grade                       | Advanced features, partitioning, RAC, pricey                                    | Large enterprises                                      |
| **DuckDB**     | Embedded, columnar   | Single file or in‑memory | Single‑process                         | Analytics‑oriented, fast local queries                                          | Data science, notebooks                                |

**Embedded** = engine inside your app; zero admin. **Client–server** = dedicated DB process; connects many apps/users at once.

## How they differ (short list)
- **Deployment**: SQLite ships as a library and writes to one file; others run a **server** and store many databases.  
- **Scaling**: SQLite shines on one machine; client–server DBs scale to many users and machines.  
- **Concurrency**: SQLite uses file‑level/row‑level mechanisms tuned for light writes; Postgres/MySQL use **MVCC** and sophisticated schedulers for heavy concurrent writes.  
- **Features**: Postgres leads on advanced SQL (window functions, CTEs), types, and **extensions**; MySQL/MariaDB have wide ecosystem support; SQLite focuses on being small and reliable.  
- **Admin & Ops**: SQLite = no admin. Others need backups, users/roles, replication, monitoring.  
- **Use‑cases**: Local apps, tests, and teaching → **SQLite**. Multi‑user production backends → **PostgreSQL/MySQL/etc.**

## CS50 angle — working with sqlite3
```bash
sqlite3 students.db           # open/create file DB
.schema                       # see tables
.mode csv                     # read CSV mode
.import students.csv students # CSV -> table
SELECT name FROM students ORDER BY name LIMIT 5;
.quit
```
You use the **sqlite3** shell’s dot‑commands (**.mode**, **.import**, **.schema**) to load data (e.g., from **CSV**) and then write standard **SQL** queries.

## When to choose which
- Pick **SQLite** when your app is local, you want **zero config**, or you’re prototyping.  
- Pick **PostgreSQL** (or **MySQL/MariaDB**) when you need **many concurrent users**, **access control**, **replication**, or advanced SQL.  
- Pick **DuckDB** when you’re doing **analytics** on a single machine with Parquet/CSV and want SQL speed without a server.

## Related Concepts
- [[CSV — Comma-Separated Values]] – quick import into SQLite with `.mode csv` and `.import`.
- [[Flat-file Database]] – how SQLite improves on simple files.
- [[SQL — SELECT WHERE ORDER BY]] – core querying across engines.
- [[SQL Joins — INNER vs LEFT]] – same SQL idea across databases.
- [[Indexes — B-trees & Performance]] – how ORDER BY/filters get fast.
- [[Normalization — 1NF 2NF 3NF]] – stays the same across engines.
- [[SQLite Shell — Dot Commands]] – `.schema`, `.mode`, `.import`.
- [[Database vs Application Logic]] – what to do in SQL vs Python.

## See also
- SQLite docs: https://sqlite.org/docs.html  
- PostgreSQL docs: https://www.postgresql.org/docs/  
- MySQL docs: https://dev.mysql.com/doc/

## Terms
[[SQLite]], [[embedded database]], [[client-server database]], [[ACID]], [[MVCC]], [[index]], [[extension]], [[JSON]], [[.schema]], [[.mode csv]], [[.import]], [[PostgreSQL]], [[MySQL]], [[MariaDB]], [[SQL Server]], [[Oracle Database]], [[DuckDB]]
