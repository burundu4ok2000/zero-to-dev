---
title: "CREATE TABLE + FOREIGN KEY (shows/ratings) — what it does"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 13
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "01:36:43"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 19.55.10.png]]

## Summary
This snippet defines two tables in **SQLite** — `shows` and `ratings` — and links them with a **FOREIGN KEY** so every `ratings.show_id` must point to an existing `shows.id`. The `.schema` command in the shell prints these **DDL** statements (data‑definition language).

## Code (from the shell)
```sql
CREATE TABLE shows (
  id INTEGER,
  title TEXT NOT NULL,
  year NUMERIC,
  episodes INTEGER,
  PRIMARY KEY(id)
);

CREATE TABLE ratings (
  show_id INTEGER NOT NULL,
  rating REAL NOT NULL,
  votes INTEGER NOT NULL,
  FOREIGN KEY(show_id) REFERENCES shows(id)
);
```

## Line‑by‑line
- `CREATE TABLE shows (...)` — defines the **schema** for TV shows.  
  - `id INTEGER` + `PRIMARY KEY(id)` — unique identifier for each show (in SQLite, an `INTEGER PRIMARY KEY` column is the rowid).  
  - `title TEXT NOT NULL` — show must have a title.  
  - `year NUMERIC` — year stored with a **NUMERIC** affinity (SQLite is flexible about types).  
  - `episodes INTEGER` — number of episodes (optional).  
- `CREATE TABLE ratings (...)` — per‑show rating and vote count.  
  - `show_id INTEGER NOT NULL` — references the parent show.  
  - `rating REAL NOT NULL` — floating‑point rating.  
  - `votes INTEGER NOT NULL` — how many people voted.  
  - `FOREIGN KEY(show_id) REFERENCES shows(id)` — **referential integrity**: `show_id` must match an existing `shows.id`.

> Important: In SQLite you must enable FK enforcement when using the shell or scripts:  
`PRAGMA foreign_keys = ON;`

## Why this design
- **One‑to‑one (or one‑to‑few)** between `shows` and `ratings` — each show has at most one ratings row (in this simplified schema).  
- Separating `ratings` keeps the `shows` row lean and lets you add rating‑specific constraints later (e.g., valid range).

## Safer / stronger version
```sql
PRAGMA foreign_keys = ON;

CREATE TABLE IF NOT EXISTS shows (
  id        INTEGER PRIMARY KEY,
  title     TEXT    NOT NULL,
  year      INTEGER CHECK(year BETWEEN 1900 AND 2100),
  episodes  INTEGER CHECK(episodes >= 0)
);

CREATE TABLE IF NOT EXISTS ratings (
  show_id INTEGER PRIMARY KEY,                -- 1:1 with shows
  rating  REAL    NOT NULL CHECK(rating BETWEEN 0 AND 10),
  votes   INTEGER NOT NULL CHECK(votes >= 0),
  FOREIGN KEY (show_id) REFERENCES shows(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_ratings_votes ON ratings(votes);
```
- `PRIMARY KEY` on `ratings.show_id` enforces **one row per show**.  
- `CHECK` constraints validate ranges.  
- `ON DELETE CASCADE` removes ratings automatically if a show is deleted.  
- Index on `votes` speeds up top‑N queries by votes.

## Query examples
```sql
-- join ratings with show titles
SELECT s.title, r.rating, r.votes
FROM ratings r
JOIN shows s ON s.id = r.show_id
ORDER BY r.rating DESC, r.votes DESC
LIMIT 10;

-- find shows without ratings (LEFT JOIN)
SELECT s.title
FROM shows s
LEFT JOIN ratings r ON r.show_id = s.id
WHERE r.show_id IS NULL;
```

## Gotchas
- Forgetting `PRAGMA foreign_keys = ON;` means the **FOREIGN KEY** won’t be enforced in SQLite shells.  
- Using `NUMERIC` for year allows strings like `'2024'`; convert/validate with **CHECK** or in code.  
- `INTEGER PRIMARY KEY` is special in SQLite; if you need a separate surrogate key plus a unique natural key, add an explicit **UNIQUE** constraint.  

## Related Concepts
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]] – where these tables fit.  
- [[One-to-One Relationship — schema & SQL patterns]] – enforcing 1↔1 with shared keys.  
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]] – query toolbox.  
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]] – aggregating ratings.  
- [[Indexes — B-trees & Performance]] – why the index on `votes` matters.  
- [[Keys — Primary & Foreign]] – constraints behind IDs.  
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]] – portability notes.  
- [[sqlite3 shell — Import CSV into SQLite (dot-commands)]] – shell commands used nearby.

## See also
- SQLite CREATE TABLE: https://sqlite.org/lang_createtable.html  
- Foreign keys in SQLite: https://sqlite.org/foreignkeys.html  
- SELECT and JOINs: https://sqlite.org/lang_select.html

## Terms
[[CREATE TABLE]], [[PRIMARY KEY]], [[FOREIGN KEY]], [[REFERENCES]], [[CHECK constraint]], [[ON DELETE CASCADE]], [[schema]], [[affinity]], [[rowid]], [[PRAGMA foreign_keys]]
