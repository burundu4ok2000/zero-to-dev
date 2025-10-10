---
title: "Aliases, Self‑Joins, and the Cartesian Product Model of JOIN"  
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 24
status: "in-progress"
difficulty: "easy"
date: "2025-10-05"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
---

## Summary
**Aliases** help you nickname tables in a query (especially when the **same table appears twice**). A **self‑join** is a regular **JOIN** where a table is joined **to itself** using different aliases. Logically, a **JOIN** starts as a **Cartesian product** (all row pairs) and then the **ON** condition **filters** that grid down to matching pairs. Understanding this model makes multi‑join queries predictable and bug‑resistant.

## Very simple
“Give me Kevin (p1) → find his movie rows (s1) → find other people in those same movies (s2) → print their names (p2).” Each arrow is a **JOIN**, and each alias is just a short name.

## Example — “Kevin Bacon (1958) co‑stars”
```sql
SELECT DISTINCT p2.name
FROM people p1
JOIN stars  s1 ON p1.id = s1.person_id          -- Kevin → his movie rows
JOIN stars  s2 ON s1.movie_id = s2.movie_id     -- same movies → other rows
JOIN people p2 ON s2.person_id = p2.id          -- those people → names
WHERE p1.name = 'Kevin Bacon' 
	AND p1.birth = 1958
	AND p2.name != 'Kevin Bacon';
```
**Why DISTINCT?** The same co‑star can appear with Kevin in multiple movies.

## What SQL “does” (the mental model)
1) **FROM / first JOIN** builds the **Cartesian product** of left and right tables (all combinations).  
2) **ON** keeps only combinations where the condition is true.  
3) Repeat for every next **JOIN**.  
4) **WHERE** then filters the already‑joined rows; **SELECT/ORDER/LIMIT** come later.

> Think “all pairs → filter by ON”. Databases don’t materialize that grid; they use indexes to reach the same result *as if* they did.

## Why aliases matter (scope/order)
Aliases exist **after** the table appears in `FROM`/`JOIN`. You can only reference an alias **introduced earlier**:
```sql
FROM people p1
JOIN stars s1 ON p1.id = s1.person_id      -- OK: p1 exists
JOIN stars s2 ON s1.movie_id = s2.movie_id -- OK: s1 exists now
JOIN people p2 ON s2.person_id = p2.id     -- OK: s2 exists now
```
Trying to use `s2` before it’s declared raises an error.

## Self‑join patterns you’ll reuse
### Same table, different roles
```sql
-- Employees who share the same manager
SELECT e.name, c.name AS colleague
FROM employees e
JOIN employees c ON e.manager_id = c.manager_id
WHERE e.id <> c.id;
```

### Graph‑like hops
```sql
-- People who follow the same user
SELECT a.follower_id, b.follower_id
FROM follows a
JOIN follows b ON a.followee_id = b.followee_id
WHERE a.follower_id <> b.follower_id;
```

## Cartesian product and CROSS JOIN
```sql
-- Explicit cross product (rare in practice)
SELECT * FROM A CROSS JOIN B;  -- every row of A paired with every row of B
```
Any **INNER/LEFT JOIN** without a valid `ON` condition **degenerates** into a cross product (usually a bug).

## Pitfalls
- **Missing ON** or wrong join key → explosion of rows (cartesian blow‑up).  
- Using an alias before it exists.  
- Confusing **WHERE** vs **ON** with **LEFT JOIN**: put row‑matching logic in **ON** or you may turn a **LEFT JOIN** into an **INNER JOIN** accidentally.  
- Forgetting **DISTINCT** when deduping co‑stars.  
- Comparing names instead of **ids** (use ids for stable joins; names can collide).

## Performance nudges
- Index the columns used in **JOIN**s and **WHERE** (`people.id`, `stars.person_id`, `stars.movie_id`).  
- Prefer equality **equijoins** (allow B‑tree indexes).  
- For case‑insensitive matches, standardize with **UPPER()** and consider an **expression index**.  
- Start from the most selective table (planner often figures this out, but good schema/indexes help).

## Cheat shapes
```sql
-- Canonical inner join with aliases
SELECT t1.a, t2.b
FROM T t1
JOIN U t2 ON t2.u_id = t1.u_id;

-- Self‑join
SELECT p1.name, p2.name
FROM people p1
JOIN people p2 ON p1.best_friend_id = p2.id;

-- Anti‑join (find people with no stars rows)
SELECT p.name
FROM people p
LEFT JOIN stars s ON s.person_id = p.id
WHERE s.person_id IS NULL;
```

## Related Concepts
- [[SQL Clause Order — Syntax vs Execution + Common Mistakes]]
- [[SQL Basics — SELECT, WHERE, ORDER BY, LIMIT (tiny patterns)]]
- [[SQL CRUD Basics — SELECT, INSERT, UPDATE, DELETE]]
- [[SQL Joins — INNER vs LEFT]]
- [[Indexes — B-trees & Performance]]
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]]
- [[Speeding up a search: JOIN → subqueries → indexes (3 steps)]]

## See also
- SQLite query language — JOIN: https://sqlite.org/lang_select.html#joinop  
- PostgreSQL: Joins explained: https://www.postgresql.org/docs/current/queries-table-expressions.html#QUERIES-FROM  
- “A Visual Explanation of SQL Joins”: https://blog.codinghorror.com/a-visual-explanation-of-sql-joins/

## Terms
[[alias]], [[self-join]], [[JOIN]], [[INNER JOIN]], [[LEFT JOIN]], [[ON]], [[WHERE]], [[Cartesian product]], [[CROSS JOIN]], [[equijoin]], [[anti-join]], [[scope]], [[DISTINCT]]
