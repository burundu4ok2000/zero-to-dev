---
title: "Route variables with angle brackets"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 14
status: "done"
difficulty: "easy"
date: "2025-10-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-23 at 15.04.29.png]]

## Summary
Flask lets you capture parts of the **URL path** as variables using **angle brackets**. Whatever matches inside `<…>` is passed as an argument to the **view function**. The Python string method `.format(...)` (or an **f-string**) can insert that value into the response.

## The snippet
```python
@app.route("/show/<number>")
def show(number):
    return "You passed in {}".format(number)
```
- `/show/<number>` — the `<number>` part is a **path variable**. Flask captures it from the URL, e.g. `/show/123` → `number == "123"` (as a string by default).
- `def show(number):` — the function parameter **must match** the name inside the brackets; Flask fills it in when calling the function.
- `"You passed in {}".format(number)` — Python **str.format** puts the value into `{}`. Equivalent modern style: `f"You passed in {number}"` (**f-string**).

## Type converters (optional but useful)
By default, path variables are **strings**. You can enforce a type using a **converter**:
```python
@app.route("/show/<int:number>")          # only matches integers
@app.route("/files/<path:subpath>")       # can include slashes
@app.route("/user/<string:username>")     # the default converter
```
If the type doesn’t match (e.g., `/show/abc` for `<int:number>`), Flask returns **404**.

## When to use this vs query strings
- Path variables are great for **identifiers** that are part of the resource path (`/users/42`).  
- **Query strings** (e.g., `?page=2`) are better for **optional parameters** and filters.
- Both are **HTTP GET** patterns; use **POST** for state changes.

## Example end‑to‑end
```python
from flask import Flask
app = Flask(__name__)

@app.route("/square/<int:n>")
def square(n):
    return f"{n} squared is {n*n}"
```
- Visiting `/square/7` returns `7 squared is 49`.

## **Why It Matters**
**Route variables** make clean, readable URLs and pass values straight into your Python code. Adding **converters** improves correctness and makes routes self‑documenting.

## Related Concepts
- [[HTTP GET vs POST]] – when to pass data in the URL vs request body.
- [[render_template() in Flask]] – returning HTML with variables.
- [[AJAX search (shows)]] – GET requests with query strings.
- [[JSON API responses]] – returning data instead of HTML.
- [[MVC (Model View Controller)]] – routing is part of the controller.
- [[Session (cookies) setup]] – request state across pages.
- [[Jinja templates documentation]] – using variables in templates.
- [[CS50 — Week 9 Flask Hub]] – overview for all week 9 atoms.

## See also
- [Flask routing docs](https://flask.palletsprojects.com/en/latest/quickstart/#variable-rules)
- [Python: str.format](https://docs.python.org/3/library/stdtypes.html#printf-style-string-formatting)
- [Python: f-strings](https://docs.python.org/3/reference/lexical_analysis.html#f-strings)

## Terms
[[Route]], [[Path variable]], [[Converter]], [[int converter]], [[Query string]], [[str.format]], [[f-string]], [[404 Not Found]]
