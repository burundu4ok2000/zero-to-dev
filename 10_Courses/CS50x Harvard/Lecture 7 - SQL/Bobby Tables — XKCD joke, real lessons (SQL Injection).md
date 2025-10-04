---
title: "Bobby Tables — XKCD joke, real lessons (SQL Injection)"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 19
status: "in-progress"
difficulty: "easy"
date: "2025-10-04"
timecode: "02:36:54"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-04 at 16.26.37.png]]

## Summary
**Bobby Tables** (XKCD #327 “Exploits of a Mom”) is the classic **SQL injection** joke: a child’s name contains SQL so a sloppy school database executes it. The comic is funny; the takeaway is serious—never concatenate untrusted input into **SQL**. Use **parameterized queries** and **least privilege** so even if injections slip in, they can’t wreck the DB.

## Very simple
If you glue user text into SQL, users can glue **SQL** right back into your text. Bind values with parameters instead.

## What the comic teaches (practical rules)
- Treat any external string (form field, URL, OCR text) as **untrusted input**.  
- The fix is **prepared statements** (aka **parameterized queries**) → the query text and the values travel separately.  
- Layer defenses: **allowlists** for expected formats, **constraints** (UNIQUE/CHECK/FKs), and **least privilege** (no `DROP` rights for app users).

## Vulnerable vs safe (SQLite + Python)
```python
# ❌ vulnerable
name = request.args.get("name")
db.execute(f"SELECT id FROM students WHERE name = '{name}';")
```

```python
# ✅ safe: parameters
name = request.args.get("name")
db.execute("SELECT id FROM students WHERE name = ?", (name,))
```

```python
# ✅ safer search with LIKE: escape wildcards
term = request.args.get("q")
db.execute("SELECT name FROM students WHERE name LIKE ? ESCAPE '\\'",
           (term.replace('%','\\%').replace('_','\\_'),))
```

## Checklist (pin to your brain)
- Is every variable in SQL bound via **?** placeholders (SQLite) or **%s** (Postgres/MySQL)?  
- Are we validating fields with **allowlists** (e.g., plate `^[A-Z0-9-]+$`)?  
- Do tables have **constraints** to keep data sane if something slips through?  
- Does the app account have **read/write only**, no DDL?  
- Are logs alerting on common payloads (`';--`, `UNION`, `OR 1=1`)?

## Related Concepts
- [[SQL Injection — attacks and defenses (CS50 Week 7)]]  
- [[SQL Clause Order — Syntax vs Execution + Common Mistakes]]  
- [[SQL DELETE — Safe Usage, WHERE, and Rollback Habits]]  
- [[Race Conditions — what they are and how to avoid them]]  
- [[Indexes — speed up WHERE/JOIN/ORDER BY]]  
- [[IMDb — Big Real-World Database (CS50 usage)]]  
- [[CREATE TABLE + FOREIGN KEY (shows/ratings) — what it does]]  
- [[Speeding up a search: JOIN → subqueries → indexes (3 steps)]]

## See also
- XKCD #327 “Exploits of a Mom”: https://xkcd.com/327/  
- OWASP SQL Injection Prevention Cheat Sheet: https://cheatsheetseries.owasp.org/cheatsheets/SQL_Injection_Prevention_Cheat_Sheet.html  
- Python sqlite3 parameter binding: https://docs.python.org/3/library/sqlite3.html#using-placeholders

## Terms
[[SQL injection]], [[prepared statement]], [[parameterized query]], [[input validation]], [[allowlist]], [[least privilege]], [[constraint]], [[CHECK constraint]], [[FOREIGN KEY]], [[UNIQUE]], [[LIKE ESCAPE]]
