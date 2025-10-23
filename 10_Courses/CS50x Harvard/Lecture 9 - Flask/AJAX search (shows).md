---
title: "AJAX search (shows)"
lang_tags: "#lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 11
status: "done"
difficulty: "easy"
date: "2025-10-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---
![[Screenshot 2025-10-22 at 22.28.03 1.png]]
![[Screenshot 2025-10-22 at 22.32.19 1.png]]
## Summary
Client-side search powered by **JavaScript** and a Flask **/search** endpoint. The page listens for the **input** event, calls **fetch** with `?q=...`, and injects results into a `<ul>`. Server can return an **HTML partial** or **JSON**; both patterns appear in CS50’s *shows* example.

## Very simple
> As you type, JS asks the server for matches and updates the list **without reloading** the page (**AJAX**).

## Snippet — HTML partial version
**Flask route:**
```python
# app.py
from cs50 import SQL
from flask import Flask, render_template, request

app = Flask(__name__)
db = SQL("sqlite:///shows.db")

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("SELECT * FROM shows WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    else:
        shows = []
    return render_template("search.html", shows=shows)
```

**Template pieces:**
```html
<!-- index.html -->
<input autocomplete="off" autofocus placeholder="Query" type="search">
<ul></ul>

<script>
  let input = document.querySelector('input');
  input.addEventListener('input', async function () {
    let response = await fetch('/search?q=' + encodeURIComponent(input.value));
    let shows = await response.text();               // server returns HTML <li>…</li>…
    document.querySelector('ul').innerHTML = shows;  // inject directly
  });
</script>
```
```html
<!-- search.html: a tiny partial -->
{% for show in shows %}
  <li>{{ show["title"] }}</li>
{% endfor %}
```

## Snippet — JSON version (safer for XSS, more flexible)
**Flask route:**
```python
# app.py (JSON response)
from flask import jsonify

@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("SELECT * FROM shows WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    else:
        shows = []
    return jsonify(shows)
```

**Client-side render:**
```html
<script>
  let input = document.querySelector('input');
  input.addEventListener('input', async function () {
    let response = await fetch('/search?q=' + encodeURIComponent(input.value));
    let shows = await response.json();
    // build HTML safely from data
    let html = '';
    for (let i in shows) {
      // Basic sanitization when building strings
      let title = String(shows[i].title).replace('<', '&lt;').replace('&', '&amp;');
      html += '<li>' + title + '</li>';
    }
    document.querySelector('ul').innerHTML = html;
  });
</script>
```

## Key Points
- **AJAX** = JS makes background HTTP requests after the page loads.
- Use **input** event for instant search; consider **debounce** (e.g., 200ms) to avoid spam requests.
- SQL uses `LIKE` with `%` wildcards; add `LIMIT` to cap results and keep UI fast.
- Returning **HTML** is quick to ship; returning **JSON** is better for **security** and reuse.
- Always **parameterize** SQL (no string concatenation) and escape when building strings in JS.
- Use `encodeURIComponent` on `q` to keep the URL safe.
- Keep the HTML partial minimal (just the list items) for fast updates.

## **Why It Matters**
This pattern is the basic building block of **live search**, **auto-complete**, and many interactive features. It shows **client-side rendering** working together with Flask routes.

## Questions
- Should we **debounce/throttle** requests? How many ms?
- When do we choose **HTML partials** vs **JSON** APIs?
- How to handle **empty state**, **loading**, and **errors** in the UI?

## Related Concepts
- [[render_template() in Flask]] – server renders the HTML partial.
- [[Jinja templates documentation]] – how the partial is generated.
- [[Insert into database (parameterized)]] – safe SQL pattern with `?` placeholders.
- [[HTTP GET vs POST]] – search uses GET with query string `q`.
- [[MVC (Model View Controller)]] – controller (`/search`) + view (partial) + model (DB).
- [[Jinja loop for select options]] – more server-to-HTML generation patterns.
- [[POST form data and DevTools payload]] – inspecting network requests.
- [[CS50 — Week 9 Flask Hub]] – index for these notes.

## See also
- [CS50x 2024 — Lecture 9: Shows, AJAX & JSON](https://cs50.harvard.edu/x/2024/notes/9/)
- [MDN: Fetch API](https://developer.mozilla.org/docs/Web/API/Fetch_API)
- [MDN: input event](https://developer.mozilla.org/docs/Web/API/HTMLElement/input_event)

## Terms
[[AJAX]], [[fetch API]], [[Event listener]], [[Query string]], [[LIKE operator]], [[jsonify]], [[innerHTML]], [[Debounce]], [[DOM]]
