---
title: "SQL Clause Order — Syntax vs Execution + Common Mistakes"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 08
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

## Summary
The **order of SQL clauses matters**. There are two useful views:
1) **Syntax order** — the order you *write* clauses.  
2) **Logical execution order** — the order the database *processes* them.

Understanding both prevents classic bugs like using **WHERE** for aggregates or sorting before you group.

## Very simple
> Think of making lemonade:
- **FROM** = get lemons.  
- **WHERE** = toss rotten lemons.  
- **GROUP BY** = box lemons by size.  
- **HAVING** = keep only boxes with enough lemons.  
- **SELECT** = decide what to show on the label.  
- **ORDER BY** = line boxes from biggest to smallest.  
- **LIMIT** = take only the first few boxes.

## 1) Syntax order (how you write a query)
```sql
SELECT ... 
FROM ...
[WHERE ...]
[GROUP BY ...]
[HAVING ...]
[ORDER BY ...]
[LIMIT n [OFFSET m]];
```

## 2) Logical execution order (how it’s evaluated)
```text
FROM (+ JOIN)   -> build the row set
WHERE           -> filter rows
GROUP BY        -> form groups
HAVING          -> filter groups
SELECT          -> compute output columns (and DISTINCT)
ORDER BY        -> sort the result
LIMIT/OFFSET    -> take a slice
```
This explains **why** some things work and others don’t (e.g., you can’t use a **SELECT** alias inside **WHERE**, because **WHERE** runs first).

## Common mistakes (and fixes)

- **Using WHERE with aggregates**
  - ❌ `WHERE COUNT(*) > 5`
  - ✅ Use **HAVING** after grouping:
    ```sql
    SELECT title, COUNT(*) AS n
    FROM favorites
    GROUP BY title
    HAVING n > 5;
    ```

- **Relying on ORDER BY before GROUP BY**
  - ❌ Sorting rows you will immediately group is wasted work.  
  - ✅ Group first, then **ORDER BY** the grouped result.

- **Forgetting ORDER BY with LIMIT**
  - ❌ `SELECT * FROM favorites LIMIT 10;` (order is arbitrary)  
  - ✅ Add a deterministic sort key:
    ```sql
    SELECT title, COUNT(*) AS n
    FROM favorites
    GROUP BY title
    ORDER BY n DESC, title ASC
    LIMIT 10;
    ```

- **Using SELECT aliases in WHERE**
  - ❌ `SELECT UPPER(title) AS t FROM favorites WHERE t = 'THE OFFICE';`  
  - ✅ Repeat the expression or wrap in a subquery/CTE:
    ```sql
    SELECT t FROM (
      SELECT UPPER(title) AS t FROM favorites
    ) WHERE t = 'THE OFFICE';
    ```
  - Tip: aliases are safe in **ORDER BY** (most dialects, including SQLite).

- **Filtering after grouping with WHERE**
  - ❌ `... GROUP BY title WHERE n >= 5`  
  - ✅ Use **HAVING** for post‑group filters (as above).

- **Case‑sensitive LIKE surprises**
  - In SQLite, **LIKE** is case‑insensitive for ASCII by default; if you need strict matching use **GLOB** or apply **UPPER/LOWER** consistently.

## Tiny checklist before you run
- Do I filter rows in **WHERE**, and filter groups in **HAVING**?  
- Is my **LIMIT** paired with **ORDER BY** so results are stable?  
- Am I accidentally using a **SELECT** alias in **WHERE**?  
- Do I need an **index** on columns used in **WHERE/ORDER BY/GROUP BY**?

## Examples (favorites table)
```sql
-- Top 5 favorite titles (stable and correct)
SELECT title, COUNT(*) AS n
FROM favorites
WHERE title <> ''
GROUP BY title
HAVING n >= 2
ORDER BY n DESC, title ASC
LIMIT 5;
```

```sql
-- Case-insensitive grouping by title
SELECT UPPER(title) AS t, COUNT(*) AS n
FROM favorites
WHERE title NOT NULL
GROUP BY t
ORDER BY n DESC;
```

## Related Concepts
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]]  
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]]  
- [[sqlite3 shell — Import CSV into SQLite (dot-commands)]]  
- [[CSV — Comma-Separated Values]]  
- [[Flat-file Database]]  
- [[When to use Python instead of SQL (Sorting)]]  
- [[Indexes — B-trees & Performance]]  
- [[Database vs Application Logic]]

## See also
- SQLite SELECT syntax & order: https://sqlite.org/lang_select.html  
- CS50 Week 7 page: https://cs50.harvard.edu/x/2025/weeks/7/

## Terms
[[SELECT]], [[FROM]], [[WHERE]], [[GROUP BY]], [[HAVING]], [[ORDER BY]], [[LIMIT]], [[OFFSET]], [[alias]], [[subquery]], [[CTE]]
