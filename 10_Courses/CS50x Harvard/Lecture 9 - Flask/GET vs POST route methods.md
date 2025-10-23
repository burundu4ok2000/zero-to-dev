---
title: "GET vs POST route methods"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 15
status: "done"
difficulty: "easy"
date: "2025-10-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-23 at 15.07.21.png]]

## Summary
Flask routes handle **GET** by default. To accept **POST** (e.g., HTML form submits), you must declare it with the `methods=[...]` option on the **route decorator**. Inside the view, read submitted form fields with **`request.form.get(...)`**. The call to **`apology(...)`** in CS50 examples is just a **helper** that returns an error page—it's *not* a Flask builtin.

## Very simple
> By default, your function answers only **GET**. If a form **POSTs** to it, Flask says “method not allowed” unless you add `methods=['GET','POST']`. Then you read inputs from `request.form`.

## The snippet (explained)
```python
@app.route("/login", methods=["GET", "POST"])
def login():
    if not request.form.get("username"):
        return apology("must provide username")
```
- `methods=["GET", "POST"]` — enable both methods for this route. Without it, POST would return **405 Method Not Allowed**.
- `request.form.get("username")` — read the `"username"` field from the **POST body** (form data). Returns `None` if missing. Use `request.args.get(...)` for **query string** values instead.
- `apology("...")` — a CS50 **helper** that renders an error response (often an HTML template with the message). Replace with your own error page or `return "message", 400`.

## Typical pattern
```python
from flask import Flask, render_template, request, redirect, url_for
app = Flask(__name__)

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form.get("username", "").strip()
        password = request.form.get("password", "")

        if not username:
            return apology("must provide username")      # or return render_template("error.html", msg=...)
        if not password:
            return apology("must provide password")

        # TODO: check credentials, set session, then redirect
        return redirect(url_for("index"))                # PRG: avoid resubmits

    # GET: show the form
    return render_template("login.html")
```
**Notes**
- `request.method` reads the actual HTTP method.
- `.get(key, default)` lets you supply a fallback value.
- Use **HTTPS** and do server-side validation for real logins.

## Why **request.form**?
- When a form posts with `method="post"` and default `enctype`, the browser sends fields as **application/x-www-form-urlencoded** in the **request body**.
- Flask parses that into an **ImmutableMultiDict** exposed as `request.form`. For files (uploads) use `request.files` and `enctype="multipart/form-data"`.

## Quick compare
- **GET**: parameters in URL (`/login?username=...`), used for **read-only** actions; cacheable; length-limited.
- **POST**: parameters in **body**, used for **state changes**; not cached by default; no practical length limit (but server may cap).

## **Why It Matters**
Understanding **methods** and **request.form** is the core of handling forms securely and correctly. You decide which routes change state (**POST**) and which simply fetch data (**GET**).

## Questions
- When should I return **400** vs render a friendly error page?
- How to protect **POST** routes from **CSRF**?
- When to use **PUT/PATCH/DELETE** for APIs?

## Related Concepts
- [[HTTP GET vs POST]] – deeper comparison and when to use each.
- [[POST form data and DevTools payload]] – see how form data travels.
- [[render_template() in Flask]] – rendering the login form and errors.
- [[Session (cookies) setup]] – keeping a user logged in.
- [[JSON API responses]] – methods beyond HTML forms.
- [[MVC (Model View Controller)]] – controller logic for forms.
- [[Jinja if/else and blocks]] – show messages on the page.
- [[CS50 — Week 9 Flask Hub]] – hub for week 9 notes.

## See also
- [Flask routing — methods](https://flask.palletsprojects.com/en/latest/quickstart/#http-methods)
- [Flask Request — form and files](https://flask.palletsprojects.com/en/latest/api/#flask.Request.form)
- [CS50x Week 9 — Flask](https://cs50.harvard.edu/x/2025/weeks/9/)

## Terms
[[GET]], [[POST]], [[methods parameter]], [[Route decorator]], [[request.form]], [[request.args]], [[HTTP 405]], [[apology helper]], [[PRG pattern]], [[CSRF]]
