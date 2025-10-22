---
title: "Jinja loop for select options"
lang_tags: "#lang/html"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 05
status: "done"
difficulty: "easy"
date: "2025-10-22"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-21 at 14.18.01.png]]

## Summary
This snippet uses **Jinja2** to **loop** over a Python list called `sports` and generate many HTML `<option>` elements inside a `<select>`. The syntax with `{% ... %}` is **control flow** (a loop), and `{{ ... }}` prints a **variable**.

## The snippet
```html
<select name="sport" required>
  <option disabled selected value="">Sport</option>
  {% for sport in sports %}
    <option value="{{ sport }}">{{ sport }}</option>
  {% endfor %}
</select>
```
- `{% for sport in sports %}` … `{% endfor %}` — Jinja **for-loop** (not Python, but similar).
- `{{ sport }}` — insert the current item’s value as text (Jinja **expression**).
- `value="{{ sport }}"` — sets the HTML **value** that will be submitted.
- `>{{ sport }}` — the `>` closes the opening `<option ...>` tag; the text node after it becomes the **label** the user sees.

## Key Points
- **Value vs label:** the part inside the tag `>{{ sport }}` is the label; the `value="..."` is what gets sent on submit (`request.form["sport"]`).
- Jinja runs on the **server** when you call **render_template()**. The browser sees only the **final HTML**.
- If `sports = ["soccer","tennis"]`, the loop becomes two `<option>` rows.
- **Autoescape:** `{{ sport }}` is HTML-escaped by default → safe if values come from users.
- You can **preselect** one option by adding `selected` conditionally.

## Examples

### 1) Minimal Flask route that renders the list
```python
# app.py
from flask import Flask, render_template, request
app = Flask(__name__)

SPORTS = ["Soccer", "Basketball", "Tennis"]

@app.route("/", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        chosen = request.form.get("sport")  # value from the <select>
        return f"You picked: {chosen}"
    return render_template("index.html", sports=SPORTS)
```

```html
<!-- templates/index.html -->
<form action="/" method="post">
  <input name="name" placeholder="Name" autocomplete="off" autofocus>
  <select name="sport" required>
    <option disabled selected value="">Sport</option>
    {% for sport in sports %}
      <option value="{{ sport }}">{{ sport }}</option>
    {% endfor %}
  </select>
  <button type="submit">Register</button>
</form>
```

### 2) Label different from value (common pattern)
```python
# values sent to server, labels shown to user
SPORTS = [
    ("soccer", "Soccer ⚽"),
    ("basketball", "Basketball 🏀"),
    ("tennis", "Tennis 🎾"),
]
```
```html
<select name="sport" required>
  <option disabled selected value="">Sport</option>
  {% for value, label in sports %}
    <option value="{{ value }}">{{ label }}</option>
  {% endfor %}
</select>
```

### 3) Preselect a value
```python
return render_template("index.html", sports=SPORTS, selected="tennis")
```
```html
{% for value, label in sports %}
  <option value="{{ value }}" {{ "selected" if value == selected else "" }}>{{ label }}</option>
{% endfor %}
```

## **Why It Matters**
Dynamic `<select>`s avoid hardcoding choices and keep Python as the **single source of truth**. It’s cleaner, safer, and easier to maintain than writing many `<option>` rows by hand.

## Questions
- ❓When should I use `(value, label)` pairs vs plain strings?
- ❓How to handle an **"Other"** option with a free-text input?
- ❓How to validate that the submitted value is in the allowed list on the server?

## Related Concepts
- [[render_template() in Flask]] – function that processes Jinja and returns HTML.
- [[Jinja2 Templates — Variables and Blocks]] – `{{ ... }}` vs `{% ... %}` basics.
- [[POST form data and DevTools payload]] – where the `<select>` submission goes.
- [[HTTP GET vs POST]] – choosing a method for forms.
- [[Form validation (server-side)]] – make sure the chosen sport is allowed.
- [[Autoescaping and |safe filter]] – why `{{ ... }}` output is safe by default.
- [[Base layout template (layout.html)]] – avoid repeating boilerplate.
- [[CS50 — Week 9 Flask Hub]] – hub for all week 9 notes.

## See also
- [Jinja: Template Designer Documentation](https://jinja.palletsprojects.com/templates/)
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)

## Terms
[[Jinja2]], [[for loop]], [[Template variable]], [[HTML select]], [[option tag]], [[value attribute]], [[Autoescape]], [[request.form]]
