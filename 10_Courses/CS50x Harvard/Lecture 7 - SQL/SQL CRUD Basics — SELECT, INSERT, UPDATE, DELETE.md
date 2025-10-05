---
title: "SQL CRUD Basics — SELECT, INSERT, UPDATE, DELETE"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 22
status: "in-progress"
difficulty: "easy"
date: "2025-10-05"
timecode: "CS50 Shorts (basics)"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-04 at 17.40.54.png]]

## Summary
These are the **CRUD** operations in SQL: **CREATE** (via **INSERT**), **READ** (**SELECT**), **UPDATE**, and **DELETE**. Mastering this tiny set gets you 80% of day‑to‑day database work. Examples below use the CS50 TV schema (**people**, **shows**, **stars**, **ratings**).

## Very simple
- **SELECT** — read rows.  
- **INSERT** — add a row.  
- **UPDATE** — change columns in matching rows.  
- **DELETE** — remove matching rows.  
Use **WHERE** to target rows; add **ORDER BY** and **LIMIT** to control output.

---

## SELECT — read data
```sql
SELECT <columns>
FROM   <table>
WHERE  <predicate>
ORDER BY <column> [ASC|DESC]
LIMIT <n>;
```
**Examples**
```sql
-- Titles with "Office", alphabetically
SELECT id, title FROM shows WHERE title LIKE '%Office%' ORDER BY title;

-- Highly rated popular shows (top 5)
SELECT s.title, r.rating, r.votes
FROM shows s JOIN ratings r ON r.show_id = s.id
WHERE r.votes >= 50000 AND r.rating >= 8.5
ORDER BY r.rating DESC, r.votes DESC
LIMIT 5;
```
Tips: prefer explicit column lists over `*`; remember `IS NULL` (not `= NULL`).

---

![[Screenshot 2025-10-05 at 08.38.35.png]]

## INSERT — add rows
```sql
INSERT INTO <table> (<columns>) VALUES (<values>);
```
**Examples**
```sql
-- Add a new person
INSERT INTO people (name, birth) VALUES ('New Star', 1990);

-- Insert and read back the new id (SQLite)
INSERT INTO shows (title, year) VALUES ('Brand New Show', 2025);
SELECT last_insert_rowid();
```
Safety: validate inputs; in app code always bind parameters (never string‑concat).

---

![[Screenshot 2025-10-05 at 08.34.39.png]]

## UPDATE — modify rows
```sql
UPDATE <table>
SET    <column> = <value>, ...
WHERE  <predicate>;
```
**Examples**
```sql
-- Fix a typo safely
UPDATE people SET name = 'Steve Carell' WHERE name = 'Steve Carelll';

-- Increment a counter
UPDATE ratings SET votes = votes + 1 WHERE show_id = 123;
```
Safety: **always** add a **WHERE**; test as a `SELECT` first. Consider a transaction if touching many rows.

---

![[Screenshot 2025-10-05 at 08.34.56.png]]

## DELETE — remove rows
```sql
DELETE FROM <table>
WHERE <predicate>;
```
**Examples**
```sql
-- Remove a test row
DELETE FROM people WHERE name = 'Temp User';

-- Clear orphaned stars (no matching person)
DELETE FROM stars
WHERE person_id NOT IN (SELECT id FROM people);
```
Safety: keep the **WHERE** tight; wrap destructive work in a transaction so you can **ROLLBACK** if needed.

---

## Mini cheats
- **Aliases**: `SELECT s.title FROM shows AS s` (shorter joins).  
- **DISTINCT** returns unique rows: `SELECT DISTINCT year FROM shows;`  
- **LIMIT/OFFSET** for paging: `LIMIT 20 OFFSET 40` (page 3 of 20‑per‑page).  
- **RETURNING** (Postgres) / `last_insert_rowid()` (SQLite) to fetch generated ids.

## Good habits
- Use **prepared statements** with parameters (`?` in SQLite).  
- Keep **constraints** in your schema (**PRIMARY KEY**, **UNIQUE**, **CHECK**, **FOREIGN KEY**).  
- Add **indexes** on frequent **WHERE/JOIN** columns for speed.  
- Practice on CSV → SQLite imports, then query with SQL.

## Related Concepts
- [[SQL Basics — SELECT, WHERE, ORDER BY, LIMIT (tiny patterns)]]
- [[SQL DELETE — Safe Usage, WHERE, and Rollback Habits]]
- [[SQL Clause Order — Syntax vs Execution + Common Mistakes]]
- [[Indexes — speed up WHERE/JOIN/ORDER BY]]
- [[sqlite3 shell — Import CSV into SQLite (dot-commands)]]
- [[SQL Injection — attacks and defenses (CS50 Week 7)]]
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]]
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]]

## See also
- SQLite SELECT/INSERT/UPDATE/DELETE: https://sqlite.org/lang.html  
- CS50 Week 7 page: https://cs50.harvard.edu/x/2025/weeks/7/  
- SQL style guide: https://www.sqlstyle.guide/

## Terms
[[SELECT]], [[INSERT]], [[UPDATE]], [[DELETE]], [[WHERE]], [[ORDER BY]], [[LIMIT]], [[OFFSET]], [[VALUES]], [[SET]], [[PRIMARY KEY]], [[UNIQUE]], [[CHECK]], [[FOREIGN KEY]], [[index]], [[prepared statement]]
