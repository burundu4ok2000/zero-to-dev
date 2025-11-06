---
title: "Parameterized queries prevent SQL injection"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/sqlite, #tool/python, #tool/flask"
atom_idx: 21
status: "done"
difficulty: "easy"
date: "2025-11-06"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-12-06"
---

## Summary
**SQL injection** happens when untrusted input is concatenated into an **SQL** string and the database interprets it as **code**. The fix is simple: use **parameterized queries** (also called **prepared statements**) with **placeholders** like `?`. In **CS50’s** Python library (and **sqlite3**), `db.execute("... ? ...", value)` binds the value **separately** from the SQL text, so the DB treats it as **data**, not code.

## Vulnerable vs safe
Bad (string formatting / f-string):
```python
username = request.form.get("username")
rows = db.execute(f"SELECT * FROM users WHERE username = '{username}'")
# If username = "stan' OR '1'='1", this can match everyone.
```

Good (parameter binding with `?`):
```python
username = request.form.get("username")
rows = db.execute("SELECT * FROM users WHERE username = ?", username)
# The value is bound as data; the DB won’t execute injected SQL.
```

## Why `?` works
- In **SQLite/DB-API**, `?` is the **qmark** placeholder. Values are passed as a **separate parameter list/tuple**, so the driver escapes and binds them safely.
- SQLite also supports `?NNN`, `:name`, `@name`, `$name` styles; CS50’s **SQL** wrapper supports `?` and named placeholders.
- Prefer binding over manual escaping. Binding avoids most injection bugs by design.

## Patterns you’ll use
**Single value**
```python
rows = db.execute("SELECT * FROM users WHERE id = ?", user_id)
```
**Multiple values**
```python
rows = db.execute("SELECT * FROM items WHERE a = ? AND b = ?", a, b)
```
**IN (…) dynamic count**
```python
placeholders = ", ".join("?" for _ in ids)
rows = db.execute(f"SELECT * FROM items WHERE id IN ({placeholders})", *ids)
```
**Named style (alternative)**
```python
rows = db.execute("SELECT * FROM users WHERE username = :u", u=username)
```

## Do & Don’t
**Do**
- Bind **every** user-supplied value via placeholders.
- Keep SQL text static; vary only the **parameters**.
- Validate/normalize inputs (types, ranges) even when binding safely.

**Don’t**
- Don’t build SQL by `+`, `format()`, or f-strings from user input.
- Don’t try to “escape” manually — it’s brittle.

## Related Concepts
- [[Flask: request.form and methods]] – form input ends up in your SQL; always **bind**.
- [[Returning JSON from Flask]] – safe queries backing your **API** endpoints.
- [[AJAX — Asynchronous JavaScript and XML]] – front‑end calls hitting DB‑backed routes.
- [[Routing and URL params in Flask]] – path params are input too; validate + bind.
- [[Sessions and cookies in Flask]] – never trust client data; treat as untrusted input.
- [[ORM vs raw SQL]] – how ORMs (e.g., SQLAlchemy) parameterize under the hood.
- [[CS50 Finance database model]] – places where binding is required.
- [[Error handling and apology()]] – handle DB errors without leaking details.

## See also
- [OWASP: SQL Injection — overview & prevention](https://owasp.org/www-community/attacks/SQL_Injection)
- [Python docs: sqlite3 — placeholders and binding values](https://docs.python.org/3/library/sqlite3.html)
- [CS50 Python SQL library — placeholders](https://cs50.readthedocs.io/libraries/cs50/python/?highlight=SQL)

## Terms
[[SQL injection]], [[Parameterized query]], [[Placeholder ? (SQLite)]], [[Prepared statement]], [[DB-API execute]], [[Named placeholder :name]], [[Input validation]], [[Escaping vs binding]]
