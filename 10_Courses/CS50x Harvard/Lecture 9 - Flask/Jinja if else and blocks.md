---
title: Jinja if else and blocks
lang_tags: "#lang/html"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 8
status: done
difficulty: easy
date: 2025-10-22
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/9/
review_next: 2025-11-22
---

![[Screenshot 2025-10-21 at 22.14.24.png]]

## Summary
**Jinja** lets templates make simple decisions. `{% if %}…{% else %}…{% endif %}` chooses what HTML to show. **Blocks** let child templates fill parts of a **base layout**.

## Very simple
> If we have a `name`, show “You are logged in as …”. Otherwise say “You are not logged in.” The decision happens on the **server** when Flask calls **render_template()**.

## The snippet
```html
{% extends "layout.html" %}

{% block body %}
  {% if name %}
    You are logged in as {{ name }}.
  {% else %}
    You are not logged in.
  {% endif %}
{% endblock %}
```
- `{% extends "layout.html" %}` — reuse a **base template**.
- `{% block body %}…{% endblock %}` — area you can replace from the child page.
- `{% if name %}` — if `name` is **truthy** (not empty/None).
- `{{ name }}` — print the variable (**auto‑escaped**).
- The browser receives **final HTML**; it does not see the Jinja markers.

## Key Points
- Pass `name` from Python: `render_template("index.html", name=user_name)`.
- Jinja tests truthiness like Python: empty string → **false**.
- Keep logic **simple** in templates; heavy logic stays in Python.
- Combine with **blocks/extends** to keep one clean layout for the whole site.
- For multiple sections, create more blocks: `title`, `head_extra`, `content`, etc.

## Examples

### Route that sets `name`
```python
# app.py
from flask import Flask, render_template, session
app = Flask(__name__)
app.secret_key = "dev"  # needed if you later store name in session

@app.route("/")
def index():
    user_name = session.get("name")  # or fetch from DB/auth
    return render_template("index.html", name=user_name)
```

### Base and child
```html
<!-- templates/layout.html -->
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>{% block title %}Site{% endblock %}</title>
  </head>
  <body>
    <main>
      {% block body %}{% endblock %}
    </main>
  </body>
</html>
```

```html
<!-- templates/index.html -->
{% extends "layout.html" %}
{% block title %}Home{% endblock %}
{% block body %}
  {% if name %}
    You are logged in as {{ name }}.
  {% else %}
    You are not logged in.
  {% endif %}
{% endblock %}
```

## **Why It Matters**
Jinja **if/else** and **blocks** are the core of dynamic, reusable pages: one layout, many pages, and small decisions per user state (logged in vs guest).

## Questions
- ❓What counts as “truthy/falsey” in Jinja?
- ❓When should I move logic from template into Python?
- ❓How to internationalize the messages shown in templates?

## Related Concepts
- [[render_template() in Flask]] – sends data into templates.
- [[Jinja templates documentation]] – the full template syntax.
- [[Jinja loop for select options]] – dynamic lists in HTML.
- [[POST form data and DevTools payload]] – where `name` can come from.
- [[MVC (Model View Controller)]] – how views fit the bigger picture.
- [[Base layout template (layout.html)]] – pattern for reusable pages.
- [[CS50 — Week 9 Flask Hub]] – overview of week 9 atoms.

## See also
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)

## Terms
[[Jinja2]], [[if statement]], [[else]], [[block]], [[extends]], [[Template variable]], [[Autoescape]], [[Layout template]]
