---
title: "SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 06
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "00:48:40"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 16.55.50.png]]

## Summary
These are built‑in **SQL functions** used in CS50’s Week 7 with **SQLite 3**. Some are **aggregate functions** (walk over many rows and return one value per group), others are **scalar functions** (transform a single value per row).

- **AVG(expr)** — average of numeric values (ignores NULLs).  
- **COUNT(\*) / COUNT(expr)** — row count; with an expression counts non‑NULL values.  
- **DISTINCT** (modifier) — remove duplicates before the function or SELECT.  
- **MAX(expr) / MIN(expr)** — largest/smallest value.  
- **LOWER(text) / UPPER(text)** — change case of strings (scalar).

## Very simple
> Imagine a big list of scores and names:
- **AVG** tells the classroom’s average score.  
- **COUNT** tells how many papers you have.  
- **DISTINCT** removes duplicates before counting.  
- **MAX/MIN** tell the highest/lowest score.  
- **LOWER/UPPER** make names the same case so you can compare fairly.

## Key Points
- **Aggregates**: **AVG**, **COUNT**, **MAX**, **MIN** work with **GROUP BY** to collapse many rows into one per group.  
- **DISTINCT** applies before the aggregate (e.g., `COUNT(DISTINCT title)`).  
- **Scalar** case functions ( **LOWER/UPPER** ) help with **case‑insensitive** comparisons and grouping.  
- **NULLs** are skipped by AVG, MAX, MIN, and by `COUNT(expr)`, but `COUNT(*)` counts every row.  
- #### Use **HAVING** to filter groups after aggregation; use **WHERE** to filter rows before aggregation.  

## Examples (favorites table)
```sql
-- count all rows
SELECT COUNT(*) AS total_number_of_rows FROM favorites;

-- unique titles (distinct values)
SELECT COUNT(DISTINCT title) AS unique_titles FROM favorites;

-- top titles by frequency
SELECT title, COUNT(*) AS n
FROM favorites
GROUP BY title
ORDER BY n DESC
LIMIT 10;

-- average title length
SELECT AVG(LENGTH(title)) AS avg_len FROM favorites;

-- case-insensitive grouping
SELECT UPPER(title) AS t, COUNT(*) AS n
FROM favorites
GROUP BY t
ORDER BY n DESC;

-- smallest and largest title alphabetically
SELECT MIN(title) AS first_title, MAX(title) AS last_title FROM favorites;

-- keep only groups with at least 5 votes
SELECT title, COUNT(*) AS n
FROM favorites
GROUP BY title
HAVING n >= 5
ORDER BY n DESC;
```

## Details
- **LOWER/UPPER** are **scalar** so they run for each row; combine with **GROUP BY** to normalize text.  
- **COUNT(DISTINCT col)** is common for cardinality questions. In SQLite it accepts one expression; for multi‑column distinct counts, use a concatenation or subquery.  
- Aggregates ignore **NULL** values; be explicit with `COALESCE(expr, 0)` when you need zeros.  
- For speed on big data, create an **index** on the grouping/sorting columns (e.g., `CREATE INDEX ... ON favorites(title)`), then the engine may avoid a full scan.  

## Related Concepts
- [[sqlite3 shell — Import CSV into SQLite (dot-commands)]] – how the `favorites` table got into SQLite.
- [[CSV — Comma-Separated Values]] – source file we imported.
- [[SQL — SELECT WHERE ORDER BY]] – foundation for queries here.
- [[When to use Python instead of SQL (Sorting)]] – where to perform the sort.
- [[Indexes — B-trees & Performance]] – why GROUP BY/ORDER BY get faster.
- [[Normalization — 1NF 2NF 3NF]] – cleaner grouping keys.
- [[SQL Joins — INNER vs LEFT]] – aggregate across related tables.
- [[Database vs Application Logic]] – decide SQL vs Python transforms.

## See also
- SQLite core functions: https://sqlite.org/lang_corefunc.html  
- SQLite aggregate queries (GROUP BY/HAVING): https://sqlite.org/lang_aggfunc.html  
- CS50 Week 7 page: https://cs50.harvard.edu/x/2025/weeks/7/

## Terms
[[aggregate function]], [[scalar function]], [[GROUP BY]], [[HAVING]], [[COUNT]], [[DISTINCT]], [[AVG]], [[MAX]], [[MIN]], [[LOWER]], [[UPPER]], [[NULL]], [[index]]
