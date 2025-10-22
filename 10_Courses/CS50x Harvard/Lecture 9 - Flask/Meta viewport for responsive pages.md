---
title: Week 9 Flask — Meta viewport for responsive pages
lang_tags: "#lang/html"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 1
status: done
difficulty: easy
date: 2025-10-22
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/9/
review_next: ""
---

![[Screenshot 2025-10-21 at 00.15.00.png]]

## Summary
A single HTML **meta viewport** tag tells the browser how to size and zoom the page on phones. It makes our Flask pages look **responsive** on mobile while staying fine on desktop.

## Very simple
> Imagine reading a tiny book on a small phone. The **viewport** line says: “Make the page the size of the phone and don’t zoom out.” So text is readable and buttons are tappable.

## Key Points
- Put this line **once** inside `<head>`:
  ```html
  <meta name="viewport" content="width=device-width, initial-scale=1">
  ```
- **width=device-width** → page width matches the device screen in CSS pixels.
- **initial-scale=1** → no auto-zoom; 1 CSS px ≈ 1 device-adjusted px at load.
- Without it, mobile browsers usually **shrink** the page (looks tiny, hard to tap).
- Not a Flask feature — it’s plain **HTML**, but every Flask template served to phones should include it.
- Works great with **responsive CSS** (e.g., **media queries**) and mobile-friendly forms.
- Avoid disabling zoom (`user-scalable=no`) — hurts accessibility.

## Details
- Browsers simulate a big “desktop width” on phones unless you set the **viewport**. This tag switches to **device width**, so layouts and **CSS breakpoints** behave as expected.
- `initial-scale=1` aligns the starting zoom. Users can still pinch-zoom unless you block it (don’t).
- You may also see `maximum-scale`, `minimum-scale`, or `viewport-fit=cover` (for notches). Keep defaults unless you have a specific need.
- **Tip:** Put the tag in your base template so **all** pages inherit it.

## Examples

### 1) Minimal Flask app serving a template with viewport
```python
# app.py
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

if __name__ == "__main__":
    app.run(debug=True)
```

```html
<!-- templates/index.html -->
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>hello</title>
  </head>
  <body>
    <form action="/greet" method="get">
      <input autocomplete="off" autofocus name="name" placeholder="Your name">
      <button type="submit">Greet</button>
    </form>
  </body>
</html>
```

```html
<!-- templates/greet.html (example structure) -->
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Greet</title>
  </head>
  <body>
    <p>Hello, {{ name }}!</p>
  </body>
</html>
```

### 2) Base template pattern (recommended)
```html
<!-- templates/base.html -->
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>{% block title %}My Site{% endblock %}</title>
    {% block head_extra %}{% endblock %}
  </head>
  <body>
    {% block content %}{% endblock %}
  </body>
</html>
```
```html
<!-- templates/index.html -->
{% extends "base.html" %}
{% block title %}hello{% endblock %}
{% block content %}
  <form action="/greet" method="get">
    <input autocomplete="off" autofocus name="name" placeholder="Your name">
    <button type="submit">Greet</button>
  </form>
{% endblock %}
```

## **Why It Matters**
Real users open your Flask app on phones. The **viewport** tag is the first step to **responsive design**, making forms usable, text readable, and layouts correct.

## Questions
- ❓When would I change `initial-scale` or add `viewport-fit=cover`?
- ❓How do **CSS media queries** interact with this tag on very high-DPI screens?
- ❓What accessibility issues happen if I disable user zoom?

## Related Concepts
- [[Flask — Request vs Response Basics]] – foundation for serving any HTML.
- [[Jinja2 Templates — Variables and Blocks]] – rendering dynamic values into templates.
- [[HTTP GET vs POST]] – forms like in the example use these methods.
- [[Forms and Input Validation (Flask)]] – make inputs safe and user-friendly.
- [[Static vs Dynamic Content]] – where CSS/JS live vs rendered pages.
- [[CSS Media Queries]] – adapt layouts to screen sizes.
- [[Mobile-First CSS]] – design strategy that pairs with the viewport tag.
- [[CS50 — Week 9 Flask Hub]] – anchor page for all week 9 atoms.

## See also
- [[HTML — Head Element]]                                                   
- [MDN: Using the viewport meta tag](https://developer.mozilla.org/en-US/docs/Web/HTML/Viewport_meta_tag)
- [web.dev: Responsive design basics](https://web.dev/learn/design/responsive-design/)
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)

## Terms
[[meta viewport]], [[Viewport]], [[Responsive Design]], [[Mobile-first design]], [[Device width]], [[Initial scale]], [[Media queries]], [[Form]], [[GET method]]
