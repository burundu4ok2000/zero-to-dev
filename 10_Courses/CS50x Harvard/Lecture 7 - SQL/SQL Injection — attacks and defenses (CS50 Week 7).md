---
title: "SQL Injection — attacks and defenses (CS50 Week 7)"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 17
status: "in-progress"
difficulty: "easy"
date: "2025-10-04"
timecode: "02:26:00"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-04 at 16.15.01.png]]

## Summary
**SQL injection** is when untrusted input becomes part of an **SQL** command’s **syntax** and changes what the query does. A classic example is adding `' OR 1=1 --` to a login form so the **WHERE** clause turns into a **tautology**. The gold‑standard defense is **parameterized queries** (aka **prepared statements**) — not string building.

## Very simple
Treat user input like glitter: once it’s in your query string, it sticks everywhere. Keep it in **parameters**, not in the query text.

## What goes wrong (vulnerable code)
```python
# ❌ vulnerable: user can break out of the quotes
name = request.args.get("name")    # e.g., "Steve' OR 1=1 --"
rows = db.execute(f"SELECT title FROM shows WHERE name = '{name}';")
```

## Fix it (SQLite + Python DB-API)
```python
# ✅ safe: query text is fixed; values are bound separately
name = request.args.get("name")
rows = db.execute("SELECT title FROM shows WHERE name = ?", (name,))
```

### Pattern notes
- In **SQLite**, use `?` placeholders; pass a **tuple** of values.  
- Never build SQL with f‑strings, `+`, or `%`.  
- For multiple criteria: `"WHERE name = ? AND year >= ?"`, `(..., (name, year))`.

## Common attack flavors
- **Tautology**: `' OR 1=1 --` turns filters into “match everything.”  
- **UNION injection**: attacker appends `UNION SELECT ...` to dump other tables.  
- **Stacked queries**: some engines let attackers send multiple statements; SQLite’s Python DB‑API typically rejects this.  
- **Blind injection**: no error messages; attacker infers data via yes/no responses or timing.

## Defense in layers
- **Parameterized queries / prepared statements** — mandatory.  
- **Least privilege** — app user should not be able to `DROP TABLE`.  
- **Constraints** (e.g., **CHECK**, **FOREIGN KEY**, **UNIQUE**) — keep data valid even if something slips through.  
- **Escape LIKE wildcards** when using user input with `LIKE`:
  ```sql
  -- search literal %/_ characters
  WHERE name LIKE ? ESCAPE '\'
  -- and pass value with % and _ escaped in code
  ```
- **Input validation / allowlists** — for things like sort fields or fixed choices.  
- **Logging and alerts** — detect repeated injection strings.  
- **ORMs** help but aren’t magic; still parameterize raw queries.

## Tiny Bobby Tables reminder
> “Drop Tables” jokes are funny once. Production isn’t. Use parameters, not prayers.

## Examples on the TV schema

```python
# Find all shows for a person (safe)
person = request.args.get("person")
sql = """
SELECT s.title
FROM people p
JOIN stars st ON st.person_id = p.id
JOIN shows s ON s.id = st.show_id
WHERE p.name = ?
ORDER BY s.title;
"""
rows = db.execute(sql, (person,))
```

```python
# Case-insensitive search (safe with expression index if you create one)
term = request.args.get("q")
rows = db.execute("SELECT name FROM people WHERE UPPER(name) = UPPER(?)", (term,))
```

## Related Concepts
- [[Indexes — speed up WHERE/JOIN/ORDER BY]] – performance; doesn’t replace safety.  
- [[SQL Clause Order — Syntax vs Execution + Common Mistakes]] – injection often abuses WHERE logic.  
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]] – clauses targeted by attackers.  
- [[CREATE TABLE + FOREIGN KEY (shows/ratings) — what it does]] – constraints as a backstop.  
- [[SQL DELETE — Safe Usage, WHERE, and Rollback Habits]] – mitigate damage with transactions.  
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]] – join points often targeted.  
- [[When to use Python instead of SQL (Sorting)]] – push only safe work to code.  
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]] – stacked queries & parameter markers differ.

## See also
- OWASP: SQL Injection Prevention Cheat Sheet — https://cheatsheetseries.owasp.org/cheatsheets/SQL_Injection_Prevention_Cheat_Sheet.html  
- SQLite Parameters & Python DB‑API (`?` placeholders) — https://docs.python.org/3/library/sqlite3.html#using-placeholders  
- CS50 Week 7 page — https://cs50.harvard.edu/x/2025/weeks/7/

## Terms
[[SQL injection]], [[prepared statement]], [[parameterized query]], [[tautology]], [[UNION]], [[stacked query]], [[blind injection]], [[least privilege]], [[constraint]], [[CHECK constraint]], [[FOREIGN KEY]], [[UNIQUE]], [[LIKE ESCAPE]]
