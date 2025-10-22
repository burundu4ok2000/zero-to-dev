---
title: "Shopping cart (bookshop) with session"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 10
status: "done"
difficulty: "easy"
date: "2025-10-22"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---
![[Screenshot 2025-10-21 at 23.27.05.png]]
## Summary
A minimal “bookshop” uses **server-side session** as a tiny **cart** (a Python list of book IDs). The app lists books from a **SQL** table, adds an item to the cart on **POST**, then shows the cart on **GET** by querying those IDs. This is classic **POST→Redirect→GET** with **Jinja** templates.

## How David planned it
- Configure **Flask-Session** and connect to a DB (e.g., `store.db` with a `books` table).
- Home `"/"`: query `SELECT * FROM books` and render `books.html` with an **Add to Cart** form for each book (hidden `id` field).
- `"/cart"` route:
  - **Ensure the cart exists** in `session` (a list).
  - On **POST**: read `id` from the form and **append** to `session["cart"]`, then **redirect** to `"/cart"`.
  - On **GET**: `SELECT * FROM books WHERE id IN (?)` using the IDs from the session and render `cart.html`.
- Templates: loop through `books` to show titles and an **Add to Cart** button; loop through cart results to display chosen books.

## The snippet (cleaned)
```python
from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

app = Flask(__name__)

# Sessions stored server-side
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

db = SQL("sqlite:///store.db")

@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("books.html", books=books)

@app.route("/cart", methods=["GET", "POST"])
def cart():
    # ensure cart exists
    if "cart" not in session:
        session["cart"] = []

    if request.method == "POST":
        book_id = request.form.get("id")
        if book_id:
            session["cart"].append(book_id)
        return redirect("/cart")  # PRG

    # GET → show cart
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)
```

## Why this snippet is interesting
- **Session as list** → simplest cart. No login required; each browser gets its own cart.
- **Hidden `<input name="id">`** in `books.html` carries the selected book’s ID with each **POST**.
- **PRG pattern** avoids duplicate inserts on refresh and gives a clean `/cart` URL.
- **Parameterized SQL (`?`)** prevents **SQL injection** and handles escaping.
- **Server-side sessions** (Flask‑Session) keep cart data off the client cookie and under app control.

## Notes & tips
- Initialize with `session.setdefault("cart", [])` before appending.
- Optionally validate `book_id` exists in the DB before adding.
- Consider `session.clear()` or a “Remove” button to empty the cart.

## Examples (templates)
```html
<!-- templates/books.html -->
{% extends "layout.html" %}
{% block body %}
  <h1>Books</h1>
  {% for book in books %}
    <h2>{{ book["title"] }}</h2>
    <form action="/cart" method="post">
      <input type="hidden" name="id" value="{{ book['id'] }}">
      <button type="submit">Add to Cart</button>
    </form>
  {% endfor %}
{% endblock %}
```

```html
<!-- templates/cart.html -->
{% extends "layout.html" %}
{% block body %}
  <h1>Your Cart</h1>
  <ul>
    {% for book in books %}
      <li>{{ book["title"] }}</li>
    {% endfor %}
  </ul>
{% endblock %}
```

## **Why It Matters**
This is the smallest end‑to‑end example of **state** in web apps: database → **controller** → **session** → template. It mirrors how real shops track carts.

## Questions
- How to prevent duplicate IDs in `session["cart"]`?
- When should carts move from **session** to a **DB** table tied to a logged‑in user?
- How to remove items or show counts?

## Related Concepts
- [[Session (cookies) setup]] – enabling Flask‑Session.
- [[Jinja if/else and blocks]] – show empty‑cart vs items.
- [[render_template() in Flask]] – controller → view glue.
- [[Insert into database (parameterized)]] – safe SQL building blocks.
- [[Jinja loop for select options]] – looping in templates.
- [[POST form data and DevTools payload]] – where `id` comes from.
- [[MVC (Model View Controller)]] – where each piece fits.
- [[Meta viewport for responsive pages]] – base HTML hygiene.

## See also
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)

## Terms
[[Session]], [[Cart]], [[POST]], [[Redirect]], [[GET]], [[Hidden input]], [[Parameterized query]], [[IN clause]], [[Template loop]]
