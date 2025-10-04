---
title: "Indexes — speed up WHERE/JOIN/ORDER BY"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 14
status: "in-progress"
difficulty: "easy"
date: "2025-10-04"
timecode: "02:07:57"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-04 at 13.49.58.png]]

## Summary
An **index** is a tiny, sorted data structure (in SQLite, usually a **B‑tree**) that lets the database find rows without scanning the whole table. You pay extra **disk space** and **slower writes** to get **much faster reads** for **WHERE**, **JOIN**, and **ORDER BY**.

## Very simple
Think of an index like the **glossary** at the back of a book. Without it you’d leaf through every page; with it you jump straight to the right spot.

## When to add an index
- Columns used often in **WHERE** filters.  
- Columns used to **JOIN** tables (foreign keys, ids).  
- Common **ORDER BY** or **GROUP BY** keys.  
- Columns that must be **UNIQUE** (use a **UNIQUE INDEX**).

Small tables (hundreds of rows) often don’t need indexes; full scans are already fast.

## Core commands (SQLite)
```sql
-- create
CREATE INDEX IF NOT EXISTS idx_favorites_title ON favorites(title);

-- composite index (order matters: leftmost prefix rule)
CREATE INDEX IF NOT EXISTS idx_ratings_votes_rating ON ratings(votes, rating);

-- unique index (also enforces data integrity)
CREATE UNIQUE INDEX IF NOT EXISTS idx_people_name_birth ON people(name, birth);

-- drop/rebuild
DROP INDEX IF EXISTS idx_favorites_title;
REINDEX;  -- rebuild indexes in the DB
```

## How the planner uses them
- If your filter matches the **leading column(s)** of a composite index, SQLite can seek directly.  
- When the index alone has all the columns a query needs, it becomes a **covering index** (reads only the index pages).  
- The planner **won’t** use an index if you wrap the column in a function or start a pattern with a wildcard (`LIKE '%office'`), or if the type/collation doesn’t match.

Use `EXPLAIN QUERY PLAN` to see choices:
```sql
EXPLAIN QUERY PLAN
SELECT title, COUNT(*) 
FROM favorites 
WHERE title >= 'M' AND title < 'N'
GROUP BY title
ORDER BY COUNT(*) DESC;
```

## Examples
### Speed up a JOIN (TV shows schema)
```sql
CREATE INDEX IF NOT EXISTS idx_stars_show   ON stars(show_id);
CREATE INDEX IF NOT EXISTS idx_stars_person ON stars(person_id);

SELECT p.name, s.title
FROM stars st
JOIN people p ON p.id = st.person_id
JOIN shows  s ON s.id = st.show_id
WHERE s.year >= 2010;
```

### Top‑N queries
```sql
CREATE INDEX IF NOT EXISTS idx_ratings_votes ON ratings(votes);
SELECT s.title, r.rating, r.votes
FROM ratings r JOIN shows s ON s.id = r.show_id
WHERE r.votes >= 50000
ORDER BY r.rating DESC, r.votes DESC
LIMIT 10;
```

### Partial index (only where useful)
```sql
-- SQLite can index a subset of rows
CREATE INDEX IF NOT EXISTS idx_ratings_popular
ON ratings(rating)
WHERE votes >= 50000;
```

## Costs & gotchas
- **Writes slow down**: every **INSERT/UPDATE/DELETE** must update the index.  
- **Space**: each index stores keys (and row pointers).  
- **Too many indexes** confuse the planner and your future self. Start with the critical ones; measure.  
- **Functions/expressions** on columns break index use: `WHERE UPPER(name) = ...` can’t use `INDEX(name)` (unless you create an **expression index** in SQLite).  
- **Leading wildcard** with **LIKE** (`'%text'`) can’t use a normal index.

## Checklist before adding
- Does this query run often and read a lot of rows?  
- Can I match the **leftmost prefix** of a composite index?  
- Do I also need a **UNIQUE** guarantee? Kill two birds with a unique index.  
- Did I verify with **EXPLAIN QUERY PLAN**?

## Related Concepts
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]] – clauses that benefit from indexing.  
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]] – combine with GROUP BY on indexed keys.  
- [[CREATE TABLE + FOREIGN KEY (shows/ratings) — what it does]] – index foreign keys for faster joins.  
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]] – where join indexes live.  
- [[IMDb — Big Real-World Database (CS50 usage)]] – ideal playground to test indexes.  
- [[SQL Clause Order — Syntax vs Execution + Common Mistakes]] – why ORDER BY + LIMIT needs the right key.  
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]] – index features vary across engines.  
- [[sqlite3 shell — Import CSV into SQLite (dot-commands)]] – load data, then add indexes.

## See also
- SQLite indexes: https://sqlite.org/lang_createindex.html  
- Query planner overview: https://sqlite.org/optoverview.html  
- EXPLAIN QUERY PLAN: https://sqlite.org/eqp.html  
- CS50 Week 7 page: https://cs50.harvard.edu/x/2025/weeks/7/

## Terms
[[index]], [[B-tree]], [[query planner]], [[covering index]], [[composite index]], [[partial index]], [[UNIQUE index]], [[EXPLAIN QUERY PLAN]], [[leftmost prefix]], [[collation]]
