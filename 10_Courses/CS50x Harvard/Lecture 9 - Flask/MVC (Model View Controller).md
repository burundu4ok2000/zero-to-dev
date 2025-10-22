---
title: "MVC (Model View Controller)"
lang_tags: "#lang/architecture"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 07
status: "done"
difficulty: "easy"
date: "2025-10-22"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-21 at 17.09.04.png]]

## Summary
**MVC** splits a web app into three parts: **Model** (data), **View** (what user sees), **Controller** (glue that handles requests and returns responses). In Flask: database/data code = Model, templates = View, routes/functions = Controller.

## Very simple
> User talks to the **controller** (a Flask **route**). The controller asks the **model** (data) and then gives the answer to a **view** (template) that renders HTML back to the user.

## Key Points
- **Model** — your data layer: SQL tables, queries, or an **ORM**. Validates and stores information.
- **View** — the UI layer: **Jinja** templates and static files (HTML/CSS/JS).
- **Controller** — the logic layer: Flask **routes**, read **request**, call model, return **response** via **render_template**.
- **Separation of concerns** → easier testing, reuse, and maintenance.
- You can keep files separate: `models.py`, `templates/`, `app.py` (controllers).

## Request → Response flow
1. Browser sends a request to `GET /players`.
2. **Controller** (Flask function) runs.
3. It queries the **Model** (DB) for players.
4. It passes results to the **View** (`render_template("players.html", players=rows)`).
5. The **View** renders HTML and Flask returns it as a response.

## Mini example
```python
# app.py  (Controller)
from flask import Flask, render_template, request
from cs50 import SQL

app = Flask(__name__)
db = SQL("sqlite:///app.db")  # Model

@app.route("/players")
def players():
    rows = db.execute("SELECT name, team FROM players ORDER BY name")
    return render_template("players.html", players=rows)  # View
```

```html
<!-- templates/players.html (View) -->
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Players</title>
  </head>
  <body>
    <ul>
      {% for p in players %}
        <li>{{ p.name }} — {{ p.team }}</li>
      {% endfor %}
    </ul>
  </body>
</html>
```

## **Why It Matters**
Using **MVC** makes small apps clean and big apps survivable. You change data logic in the **model** without touching templates, and redesign the **view** without rewriting routes.

## Questions
- ❓Where should I put **validation**: in controller, model, or both?
- ❓When is it time to split code into `blueprints`/packages in Flask?
- ❓How to test each layer separately?

## Related Concepts
- [[render_template() in Flask]] – controller → view handoff.
- [[Insert into database (parameterized)]] – model best practice.
- [[Jinja templates documentation]] – view syntax.
- [[Jinja loop for select options]] – dynamic options in views.
- [[POST form data and DevTools payload]] – how requests reach controllers.
- [[HTTP GET vs POST]] – common controller methods.
- [[Routing in Flask]] – mapping URLs to controller functions.
- [[CS50 — Week 9 Flask Hub]] – overview hub.

## See also
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)

## Terms
[[MVC]], [[Model]], [[View]], [[Controller]], [[Route]], [[Template]], [[ORM]], [[Request]], [[Response]]
