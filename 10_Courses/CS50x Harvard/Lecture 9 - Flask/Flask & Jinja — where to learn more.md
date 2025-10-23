---
title: "Flask & Jinja — where to learn more"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 16
status: "done"
difficulty: "easy"
date: "2025-10-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-23 at 15.15.18.png]]

## Summary
Two core docs to keep handy:

- **Flask Quickstart:** <https://flask.palletsprojects.com/en/latest/quickstart/>
- **Jinja Template Docs:** <https://jinja.palletsprojects.com/en/latest/templates/>

They go deeper than CS50’s intro and show patterns you’ll meet in real projects.

## Small extras not covered in CS50 (quick bites)

### 1) **Blueprints** — split routes into modules
```python
# users/routes.py
from flask import Blueprint
bp = Blueprint("users", __name__, url_prefix="/users")

@bp.route("/<int:id>")
def profile(id): ...
```
```python
# app.py
from users.routes import bp as users_bp
app.register_blueprint(users_bp)
```

### 2) **Custom error pages**
```python
@app.errorhandler(404)
def not_found(e):
    return render_template("404.html"), 404
```

### 3) **Static files** via `url_for`
```html
<link rel="stylesheet" href="{{ url_for('static', filename='site.css') }}">
```

### 4) **Jinja macros** (reusable snippets)
```html
{%- macro button(text, kind='primary') -%}
  <button class="btn {{ kind }}">{{ text }}</button>
{%- endmacro -%}

{{ button('Save') }}
```

### 5) **Custom filters** in Jinja
```python
@app.template_filter("money")
def money_filter(v):
    return f"${v:,.2f}"
```
```html
Total: {{ cart_total|money }}
```

### 6) **Context processors** — values for all templates
```python
@app.context_processor
def inject_year():
    from datetime import date
    return {"year": date.today().year}
```
```html
<footer>© {{ year }}</footer>
```

## Related Concepts
- [[render_template() in Flask]] – base function for serving HTML.
- [[Jinja templates documentation]] – full syntax reference.
- [[AJAX search (shows)]] – client-side updates with fetch.
- [[JSON API responses]] – return data instead of HTML.
- [[GET vs POST route methods]] – enable form submissions.
- [[Session (cookies) setup]] – remember user state.
- [[MVC (Model View Controller)]] – how routes and views fit.
- [[Jinja loop for select options]] – loops in templates.

## See also
- [Flask Quickstart](https://flask.palletsprojects.com/en/latest/quickstart/)
- [Jinja: Template Designer Documentation](https://jinja.palletsprojects.com/en/latest/templates/)
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)
