---
title: "SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 07
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "00:51:55"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 17.15.37.png]]

## Summary
Core **SQL clauses** you’ll use constantly in Week 7. Use **WHERE** to filter rows, **LIKE** for simple pattern matches, **GROUP BY** to aggregate, **ORDER BY** to sort, and **LIMIT** to cap the result size. Clause order matters.

## Very simple
> Recipe order matters:
1. **WHERE** = choose ingredients.  
2. **GROUP BY** = put like items in bowls.  
3. **ORDER BY** = line the bowls up by size.  
4. **LIMIT** = take only the first few bowls.  
5. **LIKE** = fuzzy picking (names that start with “The ”).

## Clause order (cheat)
```sql
SELECT ... 
FROM table
WHERE ...                  -- filter rows first
GROUP BY ...               -- make groups
HAVING ...                 -- filter groups (after grouping)
ORDER BY ...               -- sort rows or groups
LIMIT n [OFFSET m];        -- take top n (skip m)
```

## Quick uses on the `favorites` table

### WHERE — filter rows
```sql
SELECT name, title
FROM favorites
WHERE title = 'The Office';
```

### LIKE — simple patterns
```sql
-- % = any length; _ = single character
SELECT name, title 
FROM favorites
WHERE title LIKE 'The %';       -- begins with "The "
```
SQLite’s **LIKE** is case‑insensitive for ASCII by default. For case‑sensitive matching use **GLOB** or adjust collation/PRAGMA.

### GROUP BY — aggregate
```sql
SELECT title, COUNT(*) AS n
FROM favorites
GROUP BY title;
```

### ORDER BY — sort results
```sql
SELECT title, COUNT(*) AS n
FROM favorites
GROUP BY title
ORDER BY n DESC, title ASC;   -- sort by count then alphabetically
```

### LIMIT — cap the output
```sql
SELECT title, COUNT(*) AS n
FROM favorites
GROUP BY title
ORDER BY n DESC
LIMIT 10;
```

### WHERE vs HAVING
```sql
-- Keep only rows with non-empty titles, then group
SELECT title, COUNT(*) AS n
FROM favorites
WHERE title <> ''
GROUP BY title
HAVING n >= 5                 -- filter groups with at least 5 votes
ORDER BY n DESC;
```

## Details & tips
- **WHERE** runs **before** grouping; **HAVING** runs **after**.  
- Use **indexes** on columns in WHERE/ORDER BY/GROUP BY (e.g., `CREATE INDEX IF NOT EXISTS idx_favorites_title ON favorites(title)`), especially when data grows.  
- **ORDER BY** accepts multiple keys and directions (ASC/DESC).  
- **LIMIT** often pairs with **ORDER BY** to make “Top‑N” queries deterministic.  
- Watch collations: sorting strings depends on the database’s collation rules.

## Related Concepts
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]] – pair these with GROUP BY.  
- [[sqlite3 shell — Import CSV into SQLite (dot-commands)]] – how the `favorites` table got here.  
- [[CSV — Comma-Separated Values]] – source file for import.  
- [[When to use Python instead of SQL (Sorting)]] – decide where to sort.  
- [[Indexes — B-trees & Performance]] – make WHERE/ORDER BY fast.  
- [[SQL Joins — INNER vs LEFT]] – combine tables before grouping.  
- [[Normalization — 1NF 2NF 3NF]] – better grouping keys.  
- [[Database vs Application Logic]] – what belongs in SQL vs Python.

## See also
- SQLite SELECT syntax (WHERE/GROUP BY/HAVING/ORDER BY/LIMIT): https://sqlite.org/lang_select.html  
- CS50 Week 7 page: https://cs50.harvard.edu/x/2025/weeks/7/

## Terms
[[WHERE]], [[LIKE]], [[GROUP BY]], [[HAVING]], [[ORDER BY]], [[LIMIT]], [[OFFSET]], [[wildcard]], [[collation]], [[index]]
