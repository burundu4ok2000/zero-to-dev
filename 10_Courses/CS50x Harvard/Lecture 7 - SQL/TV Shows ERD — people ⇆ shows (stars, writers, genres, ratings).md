---
title: "TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 11
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "01:19:00"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 19.03.33.png]]

## Summary
This ER diagram is the **CS50 TV shows** schema. It models people, shows, and their relationships with **bridge tables**. You’ll practice **JOINs**, **grouping**, and **filtering** on a realistic, normalized design.

## Very simple
- **people**: who (actors, writers).  
- **shows**: what (title, year, episodes).  
- **stars**/**writers**: “who worked on what” (bridge tables).  
- **genres**: a show can have many genres.  
- **ratings**: per‑show rating and vote count.

## Tables (typical columns)
```
people(id, name, birth)
shows(id, title, year, episodes)
stars(show_id, person_id)        -- many-to-many (people ↔ shows)
writers(show_id, person_id)      -- many-to-many (people ↔ shows)
genres(show_id, genre)           -- one show → many genres
ratings(show_id, rating, votes)  -- one-to-one or one-to-few per show
```
- **id** in `people` and `shows` is a **primary key**.  
- `stars`, `writers`, `genres`, `ratings` store **foreign keys** to `shows.id` (and to `people.id` where relevant).  
- `stars` and `writers` are **junction tables** implementing **many-to-many** relationships.

## Key Points
- This is **normalized**: names and titles live once; links are via integer IDs → fewer duplicates and cleaner updates.  
- **JOINs** stitch data back together when you query (e.g., show titles with star names).  
- Add **indexes** on join/filter keys (`people.id`, `shows.id`, `stars.person_id`, `stars.show_id`, etc.) to keep queries fast.  
- **Cardinality**:  
  - shows ↔ stars (many-to-many), shows ↔ writers (many-to-many)  
  - shows → genres (one-to-many), shows → ratings (one-to-one/few)

## Example queries

### All stars for a given show (case-insensitive title)
```sql
SELECT p.name
FROM shows s
JOIN stars st ON st.show_id = s.id
JOIN people p ON p.id = st.person_id
WHERE UPPER(s.title) = 'BREAKING BAD'
ORDER BY p.name;
```

### Top 10 shows by rating with at least 50k votes
```sql
SELECT s.title, r.rating, r.votes
FROM shows s
JOIN ratings r ON r.show_id = s.id
WHERE r.votes >= 50000
ORDER BY r.rating DESC, r.votes DESC
LIMIT 10;
```

### Writers who also starred in the same show
```sql
SELECT DISTINCT p.name
FROM people p
JOIN writers w ON w.person_id = p.id
JOIN stars   st ON st.person_id = p.id AND st.show_id = w.show_id
ORDER BY p.name;
```

### Count shows per genre (top 5)
```sql
SELECT g.genre, COUNT(*) AS n
FROM genres g
GROUP BY g.genre
ORDER BY n DESC
LIMIT 5;
```

## Index hints (SQLite)
```sql
CREATE INDEX IF NOT EXISTS idx_stars_show   ON stars(show_id);
CREATE INDEX IF NOT EXISTS idx_stars_person ON stars(person_id);
CREATE INDEX IF NOT EXISTS idx_writers_show ON writers(show_id);
CREATE INDEX IF NOT EXISTS idx_people_name  ON people(name);
```
These speed up common JOINs and lookups.

## Related Concepts
- [[IMDb — Big Real-World Database (CS50 usage)]] – similar structure, bigger dataset.
- [[SQL Joins — INNER vs LEFT]] – how we connect people ↔ shows.
- [[Indexes — B-trees & Performance]] – make JOINs and WHERE fast.
- [[Keys — Primary & Foreign]] – identity and relationships.
- [[Normalization — 1NF 2NF 3NF]] – why bridge tables exist.
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]] – daily toolkit.
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]] – aggregates for ratings/genres.
- [[sqlite3 shell — Import CSV into SQLite (dot-commands)]] – shell skills you’ll reuse.

## See also
- SQLite Foreign Keys: https://sqlite.org/foreignkeys.html  
- Entity–relationship model (overview): https://en.wikipedia.org/wiki/Entity%E2%80%93relationship_model  
- SQLite Query Planner overview: https://sqlite.org/optoverview.html

## Terms
[[ER diagram]], [[schema]], [[primary key]], [[foreign key]], [[many-to-many]], [[junction table]], [[cardinality]], [[JOIN]], [[index]], [[normalization]]
