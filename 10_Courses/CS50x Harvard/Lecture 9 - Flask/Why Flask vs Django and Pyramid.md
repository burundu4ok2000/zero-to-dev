---
title: Why Flask vs Django and Pyramid
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 11
status: done
difficulty: easy
date: 2025-10-23
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/9/
review_next: 2025-11-22
---

## Summary
Quick map of popular languages and Python web frameworks. Then: why **Flask** is the framework used in CS50x Week 9 instead of **Django** or **Pyramid**.

## Popular languages — quick observation
- **JavaScript**, **Python**, and **SQL** show up at the top of many surveys. That’s why web stacks often look like **Python (server)** + **JavaScript (client)**.

## Python web frameworks at a glance
- **Flask** — **microframework**. Minimal core (routing, request/response, **Jinja2** templates). Easy to start, add only what you need with **extensions**.
- **Django** — **batteries‑included** full‑stack framework. Built‑in **ORM**, **Admin**, **Auth**, migrations, forms, etc.
- **Pyramid** — flexible, lightweight framework that can start small and scale up. You pick pieces (templating, DB, auth) as needed.

## Why CS50x uses Flask (not Django/Pyramid)
- **Teaches fundamentals clearly.** With Flask you see raw **routes**, **requests/responses**, **templates**, **sessions** without lots of auto‑magic. Great for learning **HTTP** and server basics.
- **Tiny setup, fast iteration.** One file + a `templates/` folder is enough. Perfect for short labs and problem sets.
- **Composable.** Need DB? Add an extension (e.g., **SQLite** via CS50’s `SQL` helper). Need sessions? Add **Flask‑Session**. You learn to wire pieces yourself.
- **Stepping stone to bigger frameworks.** After grasping Flask, you can appreciate what Django adds (ORM, admin, auth) and adopt it later if your project needs it.
- **Community/docs.** Rich docs and examples, widely used in education and quick prototypes.

## Tiny examples
**Flask hello:**
```python
from flask import Flask
app = Flask(__name__)

@app.route("/")
def index():
    return "hello, world"
```
**Django hello (conceptually):**
- Create project and app, configure URLs, view, template. More files, more power.

**Pyramid hello (conceptually):**
```python
from wsgiref.simple_server import make_server
from pyramid.config import Configurator
from pyramid.response import Response

def hello(request):
    return Response("hello, world")

with Configurator() as config:
    config.add_route("home", "/")
    config.add_view(hello, route_name="home")
    app = config.make_wsgi_app()

make_server("0.0.0.0", 8000, app).serve_forever()
```

## See also (docs)
- [Flask docs — welcome page](https://flask.palletsprojects.com/)
- [Django docs — “batteries included”](https://docs.djangoproject.com/en/5.2/)
- [Pyramid docs — intro & philosophy](https://trypyramid.com/)
- [CS50x Week 9 — Flask](https://cs50.harvard.edu/x/2025/weeks/9/)

## **Why It Matters**
Choosing a framework is about **fit**. For teaching, **Flask** spotlights the core web ideas with less noise. For production, you can scale Flask with extensions or pick **Django** for built‑ins, or **Pyramid** for maximal flexibility.

## Related Concepts
- [[render_template() in Flask]]
- [[Session (cookies) setup]]
- [[AJAX search (shows)]]
- [[JSON API responses]]
- [[MVC (Model View Controller)]]
- [[Jinja templates documentation]]
- [[Insert into database (parameterized)]]
- [[HTTP GET vs POST]]

## Terms
[[Flask]], [[Django]], [[Pyramid]], [[Microframework]], [[WSGI]], [[Jinja2]], [[ORM]], [[Batteries included]]
