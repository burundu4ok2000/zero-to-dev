---
title: "render_template() in Flask"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 03
status: "done"
difficulty: "easy"
date: "2025-10-22"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-21 at 12.25.59.png]]

## Summary
**render_template()** loads an HTML file from your **templates** folder, fills it with data using **Jinja2**, and returns the final HTML as the **response** to the browser.

## Very simple
> Think of a **template** like a birthday card with blank spaces. `render_template()` writes the names into the blanks and sends the finished card to the user.

## Key Points
- Templates live in a folder named **templates/** at your project root by default.
- Call `render_template("page.html", var=value, ...)` to pass data to the template.
- Uses **Jinja2**: `{{ ... }}` for variables, `{% ... %}` for logic (**blocks**, **extends**, loops, if).
- Auto-escapes HTML by default → prevents simple **XSS** when printing user data.
- Can return a tuple to set status code or headers: `return render_template("oops.html"), 400`.
- Common structure: `layout.html` (base) + child pages (`index.html`, `greet.html`) that **extend** it.
- Keep heavy logic in Python; keep templates **clean and small**.

## Details
- Flask looks for `templates/` next to your app module (or set `template_folder=` in `Flask(...)`).
- Context can be any mappable object; use `**context` to pass many values at once.
- Jinja safely renders text; mark trusted HTML with `|safe` only when you 100% trust it.
- If a template is missing → **TemplateNotFound**. If you forget to `return` the call → route returns **None** → error.
- Use a **base** with `{% block content %}` to avoid repeating `<head>`, nav, etc.

## Examples

### Minimal route with GET/POST and templates
```python
# app.py
from flask import Flask, render_template, request
app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name", "world")
        return render_template("greet.html", name=name)  # pass variable into template
    return render_template("index.html")  # default GET
````

### Base/child templates

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
    <main class="container">
      {% block content %}{% endblock %}
    </main>
  </body>
</html>
```

```html
<!-- templates/index.html -->
{% extends "layout.html" %}
{% block title %}hello{% endblock %}
{% block content %}
  <form action="/" method="post">
    <input name="name" placeholder="Your name" autocomplete="off" autofocus>
    <button type="submit">Greet</button>
  </form>
{% endblock %}
```

```html
<!-- templates/greet.html -->
{% extends "layout.html" %}
{% block title %}greet{% endblock %}
{% block content %}
  <h1>hello, {{ name }}</h1>
{% endblock %}
```

### Returning custom status

```python
return render_template("not_found.html"), 404
```

## **Why It Matters**

Templates separate **presentation** from **logic**. Your Flask code stays clean, and you can build **reusable layouts** that scale when pages multiply.

## Questions

- ❓When should I use `url_for()` in templates to link views or static files?
    
- ❓What are the trade-offs between server-side templates and **single-page apps**?
    
- ❓How to organize large template folders (partials, macros)?
    

## Related Concepts

- [[POST form data and DevTools payload]] – how data reaches your route.
    
- [[Jinja2 Templates — Variables and Blocks]] – syntax used inside templates.
    
- [[HTTP GET vs POST]] – route methods used with forms.
    
- [[Base layout template (layout.html)]] – parent template pattern.
    
- [[Static files in Flask]] – linking CSS/JS via `url_for('static', ...)`.
    
- [[Autoescaping and |safe filter]] – controlling HTML escaping.
    
- [[CS50 — Week 9 Flask Hub]] – index for all week 9 notes.
    

## See also

- [[Flask — Request vs Response Basics]]
    
- [Flask docs: Templates](https://flask.palletsprojects.com/en/3.0.x/quickstart/#rendering-templates)
    
- [Jinja2 Template Designer Documentation](https://jinja.palletsprojects.com/en/3.1.x/templates/)
    
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)
    

## Terms

[[render_template]], [[Jinja2]], [[templates folder]], [[Context dictionary]], [[Autoescape]], [[Base template]], [[Block]], [[extends]] 