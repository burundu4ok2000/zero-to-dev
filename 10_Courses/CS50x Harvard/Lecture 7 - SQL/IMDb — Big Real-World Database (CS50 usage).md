---
title: "IMDb — Big Real-World Database (CS50 usage)"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 10
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "01:18:00"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 18.55.53.png]]

## Summary
**IMDb** (Internet Movie Database) is a **huge relational database** of movies, people, and ratings. In CS50, we use a trimmed **SQLite** version (often `movies.db`) that mirrors the real dataset’s structure so we can practice **JOINs**, **aggregates**, and reasoning about **many‑to‑many** relationships.

## Very simple
> Imagine many linked spreadsheets:
- one for **movies**, one for **people**, one for **who acted in what**, and one for **ratings** — then connect them with IDs. That’s IMDb.

## Tables you’ll see in CS50’s movies.db (typical)
```text
movies(id, title, year)
people(id, name, birth)
ratings(movie_id, rating, votes)
stars(movie_id, person_id)          -- actors/actresses in a movie
directors(movie_id, person_id)      -- directors of a movie
```
- **id** columns are **primary keys**.  
- Link tables (**stars**, **directors**) model **many‑to‑many** relationships via **foreign keys** to `movies.id` and `people.id`.

## What you’ll query (examples)
```sql
-- Top 10 highest‑rated movies with at least 100,000 votes
SELECT m.title, r.rating, r.votes
FROM movies m
JOIN ratings r ON r.movie_id = m.id
WHERE r.votes >= 100000
ORDER BY r.rating DESC, r.votes DESC
LIMIT 10;

-- All movies starring 'Tom Hanks' (case-insensitive)
SELECT m.title, m.year
FROM people p
JOIN stars  s ON s.person_id = p.id
JOIN movies m ON m.id = s.movie_id
WHERE UPPER(p.name) = 'TOM HANKS'
ORDER BY m.year;

-- Co‑stars who appeared with 'Emma Watson' at least 3 times
SELECT p2.name, COUNT(*) AS together
FROM people p1
JOIN stars s1 ON s1.person_id = p1.id
JOIN stars s2 ON s2.movie_id  = s1.movie_id
JOIN people p2 ON p2.id       = s2.person_id
WHERE p1.name = 'Emma Watson' AND p2.id != p1.id
GROUP BY p2.id
HAVING together >= 3
ORDER BY together DESC, p2.name;
```

## Why IMDb is a great teaching example
- Shows **normalized** design: separate tables, no duplicated names, everything linked by IDs.  
- Forces real **JOIN** thinking (actors ↔ movies ↔ ratings).  
- Great for **performance** lessons (create **indexes** on join/filter keys like `movies.id`, `stars.movie_id`, `people.name`).  
- Lets you practice careful **filtering** (`WHERE` vs **HAVING**), **sorting**, and **LIMIT** for top‑N lists.

## Quick CS50 workflow
1. Open the DB: `sqlite3 movies.db`  
2. Explore structure: `.schema` (or `.tables`)  
3. Iterate queries from the shell; save good ones to a `.sql` file for reuse.

## Related Concepts
- [[SQL Joins — INNER vs LEFT]] – IMDb queries are mostly joins across 2–4 tables.  
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]] – aggregates for ratings and counts.  
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]] – the daily toolkit on this dataset.  
- [[Indexes — B-trees & Performance]] – speed up joins and filters on foreign keys.  
- [[Normalization — 1NF 2NF 3NF]] – why we split people/movies/stars.  
- [[Keys — Primary & Foreign]] – identify rows and link tables.  
- [[sqlite3 shell — Import CSV into SQLite (dot-commands)]] – not for IMDb itself, but same shell skills.  
- [[Database vs Application Logic]] – push work into SQL before Python.

## See also
- IMDb Datasets (official export): https://www.imdb.com/interfaces/  
- CS50 Week 7 page: https://cs50.harvard.edu/x/2025/weeks/7/  
- SQLite Query Language (SELECT): https://sqlite.org/lang_select.html

## Terms
[[IMDb]], [[movies.db]], [[movies table]], [[people table]], [[ratings table]], [[stars table]], [[directors table]], [[many-to-many]], [[JOIN]], [[PRIMARY KEY]], [[FOREIGN KEY]]
