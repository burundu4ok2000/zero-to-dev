---
title: "Speeding up a search: JOIN → subqueries → indexes (3 steps)"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 15
status: "in-progress"
difficulty: "easy"
date: "2025-10-04"
timecode: "02:12:25–02:13:30"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-04 at 15.13.01.png]]

## Summary
Same question, three increasingly faster queries on the **TV shows** schema: find all show **titles** that star **Steve Carell**. We go from a naïve **JOIN** that scans a lot of rows → to **subqueries** that shrink the data earlier → to adding **indexes** so the planner can jump directly to matching rows.

## Step 1 — naïve multi‑table JOIN (slowest)
```sql
SELECT title
FROM shows, stars, people
WHERE shows.id = stars.show_id
  AND people.id = stars.person_id
  AND name = 'Steve Carell';
```
- Implicit join across three tables; without helpful indexes the engine does large scans and row multiplications.  
- In the demo run time was ≈ **3.48 s** (your machine will differ).

![[Screenshot 2025-10-04 at 15.13.10.png]]

## Step 2 — filter early with subqueries (faster)
```sql
SELECT title
FROM shows
WHERE id IN (
  SELECT show_id
  FROM stars
  WHERE person_id = (
    SELECT id FROM people WHERE name = 'Steve Carell'
  )
);
```
- This structure lets SQLite focus on **IDs** first, then fetch matching shows.  
- Demo run time dropped to ≈ **0.215 s**.

![[Screenshot 2025-10-04 at 15.13.21.png]]
![[Screenshot 2025-10-04 at 15.13.23.png]]

## Step 3 — add indexes on lookup keys (fastest)
```sql
CREATE INDEX IF NOT EXISTS name_index   ON people(name);
CREATE INDEX IF NOT EXISTS person_index ON stars(person_id);
-- (shows.id is already the PRIMARY KEY → implicitly indexed)
```
Rerun Step‑2 query and the planner can use **B‑tree indexes** to resolve the subqueries with **log‑time** seeks.  
- Demo run time fell to ≈ **0.001 s**.

![[Screenshot 2025-10-04 at 15.16.32.png]]
![[Screenshot 2025-10-04 at 15.17.03.png]]

## Why this works
- **Subqueries vs JOINs**: logically equivalent here, but the subquery form encourages the planner to reduce to **small ID sets** early. Some engines will optimize both forms the same; the real win is the **indexes**.  
- **Indexes** turn `WHERE name = 'Steve Carell'` and `WHERE person_id = ?` into quick lookups instead of full scans.  
- **Primary keys** (like `shows.id`) are already indexed, so you typically index the **foreign‑key side** (`stars.person_id`) and the **search column** (`people.name`).

## Tips
- Verify plans: `EXPLAIN QUERY PLAN <your query>;`  
- Prefer **explicit JOIN** syntax for readability (same performance as comma joins when equivalent).  
- For case‑insensitive searches, either store normalized names (e.g., **UPPER**) with an **expression index**, or compare with the same function on both sides.

## Related Concepts
- [[Indexes — speed up WHERE/JOIN/ORDER BY]]  
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]]  
- [[SQL Joins — INNER vs LEFT]]  
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]]  
- [[IMDb — Big Real-World Database (CS50 usage)]]  
- [[CREATE TABLE + FOREIGN KEY (shows/ratings) — what it does]]  
- [[SQL Clause Order — Syntax vs Execution + Common Mistakes]]  
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]]

## See also
- SQLite indexes: https://sqlite.org/lang_createindex.html  
- EXPLAIN QUERY PLAN: https://sqlite.org/eqp.html  
- Query planner overview: https://sqlite.org/optoverview.html

## Terms
[[JOIN]], [[subquery]], [[IN]], [[index]], [[B-tree]], [[PRIMARY KEY]], [[FOREIGN KEY]], [[query planner]], [[EXPLAIN QUERY PLAN]], [[expression index]]
