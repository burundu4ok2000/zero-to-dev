---
title: "Session (cookies) setup"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 09
status: "done"
difficulty: "easy"
date: "2025-10-22"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-21 at 22.24.41.png]]

## Summary
This config enables **sessions** in Flask using the **Flask-Session** extension. A **session** keeps user-specific data across requests (e.g., a username). The browser holds a small **cookie** with a session id; the app stores the actual data on the **server** (here: **filesystem**).

## Very simple
> Think of a coat check. The browser gets a **ticket** (cookie). Your app keeps the **coat** (session data) in a safe place and finds it next time using the ticket number.

## The snippet
```python
from flask import Flask, render_template, request, session
from flask_session import Session

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False     # cookie dies when browser closes
app.config["SESSION_TYPE"] = "filesystem"   # server‑side storage
Session(app)                                 # plug extension into the app
```
- `SESSION_PERMANENT=False` → make the cookie **non‑persistent** (good for logins during labs).
- `SESSION_TYPE="filesystem"` → store data on disk (server) instead of inside the cookie.
- `Session(app)` wires the extension so `session[...]` works in routes.

## Use it in a route
```python
# store and read a name in the session
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        session["name"] = request.form.get("name")  # save to session
        return redirect("/")
    name = session.get("name")  # read from session
    return render_template("index.html", name=name)

@app.route("/logout")
def logout():
    session.clear()  # remove everything from this user's session
    return redirect("/")
```
In the template you can show it with **Jinja**:
```html
{% if name %}You are logged in as {{ name }}.{% else %}You are not logged in.{% endif %}
```

## Key Points
- Flask’s built‑in **session** uses a signed cookie; **Flask‑Session** moves data **server‑side**.
- You still need a **secret key** for signing cookies (Flask sets one for CS50 codespaces; in your own app, set `app.secret_key`).
- Sessions are **per user** and survive across requests until you clear them or the cookie expires.
- Do not put large or sensitive data in the session; keep only small identifiers or flags.

## **Why It Matters**
Sessions let your app remember users between requests (e.g., login state, cart id) without asking them to resend everything each time.

## Questions
- ❓When should I set `SESSION_PERMANENT=True` and a lifetime?
- ❓What data is safe to keep in a session vs database?
- ❓What are other `SESSION_TYPE`s (redis, memcached) and when to use them?

## Related Concepts
- [[Jinja if/else and blocks]] – show different UI based on session state.
- [[render_template() in Flask]] – send `name` into templates.
- [[POST form data and DevTools payload]] – where the value initially comes from.
- [[MVC (Model View Controller)]] – sessions live in the controller layer.
- [[Insert into database (parameterized)]] – store durable data in DB, not session.
- [[Jinja templates documentation]] – template syntax used above.
- [[Jinja loop for select options]]
- [[CS50 — Week 9 Flask Hub]]

## See also
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)

## Terms
[[Session]], [[Cookie]], [[Flask-Session]], [[SESSION_TYPE]], [[SESSION_PERMANENT]], [[session dict]], [[session.clear]], [[Secret key]]
