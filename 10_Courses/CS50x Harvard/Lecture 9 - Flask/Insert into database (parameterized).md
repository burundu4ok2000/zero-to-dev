---
title: "Insert into database (parameterized)"
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 06
status: "done"
difficulty: "easy"
date: "2025-10-22"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-21 at 15.06.30.png]]

## Summary
This route **validates form inputs** (`name`, `sport`) and saves them into a SQL table using a **parameterized INSERT**:
```python
db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)
```
The `?` placeholders prevent **SQL injection** and handle escaping for you.

## The snippet (what each part means)
- `request.form.get("sport")` — read value from the submitted form (POST body).
- `if not sport:` / `if sport not in SPORTS:` — server-side **validation**.
- `db.execute("INSERT ... VALUES(?, ?)", name, sport)` — run SQL with **bound parameters**.
- `return render_template("success.html")` — respond with a success page.
- `@app.route("/registrants")` — another view to **list** rows in a page.

## Key Points
- Use **placeholders** (`?`) instead of string formatting in SQL. This is the DB-API’s **qmark** style (common with **SQLite**).
- **Why**: protects against **SQL injection**, handles quoting/escaping, and lets the driver reuse query plans.
- Always **validate** inputs before inserting (required fields, allowed values).
- Prefer **Post/Redirect/Get** after insert to avoid duplicate submissions on refresh.
- To display data, query the table and pass rows to your template.

## Example — full mini flow
```python
# app.py
from flask import Flask, render_template, request, redirect, url_for
from cs50 import SQL  # or use sqlite3; API is similar

app = Flask(__name__)
db = SQL("sqlite:///froshims.db")
SPORTS = ["Soccer", "Basketball", "Tennis"]

@app.route("/", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        name = request.form.get("name", "").strip()
        sport = request.form.get("sport")

        if not name:
            return render_template("error.html", message="Missing name")
        if not sport:
            return render_template("error.html", message="Missing sport")
        if sport not in SPORTS:
            return render_template("error.html", message="Invalid sport")

        db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)
        return redirect(url_for("registrants"))  # PRG pattern

    return render_template("index.html", sports=SPORTS)

@app.route("/registrants")
def registrants():
    rows = db.execute("SELECT name, sport FROM registrants ORDER BY rowid DESC")
    return render_template("registrants.html", registrants=rows)
```

```sql
-- schema.sql
CREATE TABLE IF NOT EXISTS registrants (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  name TEXT NOT NULL,
  sport TEXT NOT NULL
);
```

```html
<!-- templates/registrants.html -->
<table>
  <thead><tr><th>Name</th><th>Sport</th></tr></thead>
  <tbody>
    {% for r in registrants %}
      <tr><td>{{ r.name }}</td><td>{{ r.sport }}</td></tr>
    {% endfor %}
  </tbody>
</table>
```

## **Why It Matters**
**Parameterized queries** are the default-safe way to write to a database from web apps. They reduce security risks, avoid quoting bugs, and keep your code clean and maintainable.

## Questions
- ❓How would you **update** or **delete** rows safely (placeholders again)?
- ❓When should you enforce allowed values at the **DB level** (CHECK/FOREIGN KEY)?
- ❓How to handle duplicate registrations (unique index or server-side check)?

## Related Concepts
- [[POST form data and DevTools payload]] – how the values reach the server.
- [[HTTP GET vs POST]] – POST for state change, GET for reading.
- [[Form validation (server-side)]] – validating inputs before DB writes.
- [[Jinja loop for select options]] – populating the sports `<select>`.
- [[SQL Injection]] – what parameterization protects against.
- [[render_template() in Flask]] – rendering success/error pages.
- [[CS50 — Week 9 Flask Hub]] – overview of week 9 atoms.

## See also
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)
- [Python sqlite3 — parameter substitution](https://docs.python.org/3/library/sqlite3.html#execute)
- [OWASP: SQL Injection Prevention Cheat Sheet](https://owasp.org/www-community/attacks/SQL_Injection)

## Terms
[[Parameterized query]], [[Placeholder ?]], [[SQL injection]], [[request.form]], [[DB-API]], [[INSERT]], [[PRG pattern]], [[SELECT]]
