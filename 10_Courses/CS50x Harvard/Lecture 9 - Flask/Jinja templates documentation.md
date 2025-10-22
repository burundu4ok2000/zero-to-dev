---
title: "Jinja templates documentation"
lang_tags: "#lang/html"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 04
status: "done"
difficulty: "easy"
date: "2025-10-22"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-21 at 12.34.33.png]]

## Summary
Official **Jinja** templates docs — the reference for the syntax Flask uses to render HTML: **variables**, **filters**, **control flow**, **blocks**, **extends**, **includes**, **macros**, and **autoescaping**.

## Very simple
> Jinja is like a smart **HTML generator**. You write a page with holes, and Jinja fills those holes with your data, loops, and ifs.

## Key Points
- Jinja is the **template engine** used by Flask’s `render_template()`.
- Core syntax:
  - Variables: `{{ user }}` (auto-escaped by default).
  - Control flow: `{% if %}…{% endif %}`, `{% for item in items %}…{% endfor %}`.
  - **Blocks** / **extends** for layouts: child pages reuse a base file.
  - **Includes** to reuse partials (headers, forms).
  - **Filters**: `{{ name|title }}`, `{{ price|round(2) }}`.
  - **Macros**: reusable mini-functions in templates.
- **Autoescape** protects from simple XSS; use `|safe` only for trusted HTML.
- Use `url_for()` in templates for links and static files.
- The full reference lives at jinja.palletsprojects.com/templates/ (bookmark it).

## Details
- Templates are just **text files** (usually HTML) in your `templates/` folder.
- Context is passed from Flask: `render_template("page.html", user=user)` → `{{ user }}`.
- With **extends**, the base defines `{% block content %}` that children fill.
- You can register **custom filters** in Flask for project-specific formatting.
- Jinja supports **dicts**, **lists**, **attribute access**, and common tests like `is defined`.

## Examples

### Layout pattern
```html
<!-- templates/layout.html -->
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>{% block title %}My Site{% endblock %}</title>
  </head>
  <body>
    <header>{% include "_nav.html" %}</header>
    <main>{% block content %}{% endblock %}</main>
  </body>
</html>
```

```html
<!-- templates/index.html -->
{% extends "layout.html" %}
{% block title %}Home{% endblock %}
{% block content %}
  <h1>Hello, {{ user|default("world")|e }}</h1>
  <ul>
    {% for item in items %}
      <li>{{ loop.index }}) {{ item|title }}</li>
    {% endfor %}
  </ul>
{% endblock %}
```

### Macro and filter
```html
{% macro pill(text) -%}
  <span class="pill">{{ text|title }}</span>
{%- endmacro %}

{{ pill("flask") }}  {# → <span class="pill">Flask</span> #}
```

## **Why It Matters**
You’ll read and write Jinja every time you return HTML from Flask. Knowing the **official syntax** and patterns speeds up development and prevents bugs with escaping and layout duplication.

## Questions
- ❓When should I move logic from Jinja into Python (keep templates thin)?
- ❓How to create custom **filters** and **tests** in Flask?
- ❓What are common escaping mistakes with `|safe`?

## Related Concepts
- [[render_template() in Flask]] – function that renders Jinja templates.
- [[Jinja2 Templates — Variables and Blocks]] – quick-reference of core syntax.
- [[Base layout template (layout.html)]] – using **extends** and **blocks**.
- [[Static files in Flask]] – linking CSS/JS with `url_for('static', ...)`.
- [[Autoescaping and |safe filter]] – security basics in templates.
- [[POST form data and DevTools payload]] – how data reaches templates.
- [[HTTP GET vs POST]] – methods that feed values into your templates.
- [[CS50 — Week 9 Flask Hub]] – overview of week 9 atoms.

## See also
- [Jinja: Template Designer Documentation](https://jinja.palletsprojects.com/templates/)
- [Flask docs: Templates](https://flask.palletsprojects.com/quickstart/#rendering-templates)
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)

## Terms
[[Jinja2]], [[Template engine]], [[render_template]], [[Blocks]], [[extends]], [[include]], [[Macro]], [[Filter]], [[Autoescape]], [[url_for]]
