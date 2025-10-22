---
title: "JSON API responses"
lang_tags: "#lang/json"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 12
status: "done"
difficulty: "easy"
date: "2025-10-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---
![[Screenshot 2025-10-22 at 22.46.27.png]]
![[Screenshot 2025-10-22 at 22.46.31.png]]
![[Screenshot 2025-10-22 at 22.46.34.png]]

## Summary
Instead of returning **HTML**, the `/search` endpoint returns **JSON**. The browser uses **fetch** to get the data and renders the list **client‑side**. This turns the route into a small **API** that other pages (or apps) can reuse.

## Very simple
> Server sends **data**, not markup. Browser builds the **markup** itself.

## Server — Flask returning JSON
```python
# app.py
from cs50 import SQL
from flask import Flask, jsonify, request

app = Flask(__name__)
db = SQL("sqlite:///shows.db")

@app.route("/search")
def search():
    q = request.args.get("q", "")
    rows = db.execute("SELECT id, title, year, episodes FROM shows WHERE title LIKE ? LIMIT 50",
                      "%" + q + "%")
    return jsonify(rows)  # Content-Type: application/json
```
- `jsonify(rows)` serializes rows to **JSON** and sets **Content-Type: application/json**.
- Keep SQL **parameterized** (`?`) and **LIMIT** the results.

## Client — render from JSON (no page reload)
```html
<input autocomplete="off" autofocus placeholder="Query" type="search">
<ul id="results"></ul>

<script>
  const input = document.querySelector('input');
  const list  = document.querySelector('#results');

  input.addEventListener('input', debounce(async () => {
    const response = await fetch('/search?q=' + encodeURIComponent(input.value), {
      headers: { 'Accept': 'application/json' }
    });
    const shows = await response.json();

    list.innerHTML = '';                       // clear
    for (const show of shows) {                // build DOM safely
      const li = document.createElement('li');
      li.textContent = `${show.title} (${show.year})`;
      list.appendChild(li);
    }
  }, 200));  // small debounce so we don't spam the server

  function debounce(fn, ms) { let t; return (...a) => (clearTimeout(t), t=setTimeout(() => fn(...a), ms)); }
</script>
```
- Use `textContent` (not `innerHTML`) to avoid **XSS** when inserting user-controlled data.
- `Accept: application/json` is optional but clarifies intent.

## Why this upgrade is useful
- **Security:** avoid injecting HTML from the server into the page.
- **Reusability:** the same `/search` endpoint can power other pages or a mobile app.
- **UX:** quicker updates (no full refresh), smoother typing with **AJAX**.
- **Separation of concerns:** Flask handles **data**, JS handles **view**.

## Error handling & status codes
```python
@app.route("/search")
def search():
    q = request.args.get("q", "").strip()
    if not q:
        return jsonify({"error": "missing q"}), 400
    rows = db.execute("SELECT id, title FROM shows WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    return jsonify(rows), 200
```
```js
const res = await fetch('/search?q=' + encodeURIComponent(q));
if (!res.ok) {
  const err = await res.json();
  // show a friendly message
}
```

## **Why It Matters**
Most modern sites use **JSON APIs** under the hood. Learning to return JSON from Flask and render it with **fetch** is a core skill for building fast, interactive interfaces.

## Questions
- When should we choose **HTML partial** vs **JSON**?
- How would we paginate results when there are thousands of rows?
- How to cache recent queries on the client to reduce network calls?

## Related Concepts
- [[AJAX search (shows)]] – earlier HTML‑partial and JSON variants.
- [[render_template() in Flask]] – server-rendered pages versus API responses.
- [[POST form data and DevTools payload]] – inspecting requests/responses.
- [[Insert into database (parameterized)]] – safe SQL for all endpoints.
- [[Jinja templates documentation]] – if you still render HTML server‑side.
- [[MVC (Model View Controller)]] – API = controller returns data, not views.
- [[Session (cookies) setup]] – state is separate from API payloads.
- [[Jinja loop for select options]] – other server-to-HTML rendering patterns.

## See also
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)
- [MDN: Working with JSON](https://developer.mozilla.org/docs/Learn/JavaScript/Objects/JSON)
- [MDN: Fetch API](https://developer.mozilla.org/docs/Web/API/Fetch_API)

## Terms
[[JSON]], [[API]], [[jsonify]], [[Content-Type application/json]], [[Fetch API]], [[AJAX]], [[XSS]], [[Debounce]], [[Client-side rendering]]
