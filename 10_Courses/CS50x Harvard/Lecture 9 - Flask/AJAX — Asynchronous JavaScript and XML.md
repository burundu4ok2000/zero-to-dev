---
title: "AJAX — Asynchronous JavaScript and XML"
lang_tags: "#lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 17
status: "done"
difficulty: "easy"
date: "2025-10-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

## Summary
**AJAX** stands for **Asynchronous JavaScript and XML**. It means: use **JavaScript** in the browser to make **HTTP** requests **in the background** and then update parts of the page (**DOM**) **without a full reload**. Today we often send **JSON** instead of **XML** — the name stuck from older times.

## What is XML? Why is it in the name?
**XML** = **Extensible Markup Language**. It’s a text format (like HTML) for structured data. In early web apps, servers commonly returned XML, so the term **AJAX** included it. Modern apps usually return **JSON** (lighter, native to JS). Tools like **XMLHttpRequest** (XHR) and the **Fetch API** can fetch **any** type: JSON, HTML, text, or XML — not limited to XML.

## How AJAX feels (CS50‑style plain words)
- The page stays on the same URL.  
- **JS** sends a request (`fetch('/score')`).  
- Server replies with **data** (often **JSON**).  
- JS changes the DOM: updates score/time/list without reloading.

## Minimal patterns

### 1) Fetch JSON and update a score
```html
<div id="score">0</div>
<script>
async function refreshScore() {
  const res = await fetch('/score');          // GET data
  const data = await res.json();              // { value: 42 }
  document.querySelector('#score').textContent = data.value;
}
setInterval(refreshScore, 2000);               // poll every 2s
refreshScore();
</script>
```

### 2) Search-as-you-type (GET + query string)
```html
<input id="q" autocomplete="off" placeholder="Search">
<ul id="results"></ul>
<script>
const q = document.querySelector('#q');
const list = document.querySelector('#results');

q.addEventListener('input', debounce(async () => {
  const res = await fetch('/search?q=' + encodeURIComponent(q.value));
  const items = await res.json();             // [{title:"The Office"}, ...]
  list.innerHTML = '';
  for (const it of items) {
    const li = document.createElement('li');  // safe DOM build (no innerHTML)
    li.textContent = it.title;
    list.appendChild(li);
  }
}, 200));

function debounce(fn, ms){ let t; return (...a)=>{ clearTimeout(t); t=setTimeout(()=>fn(...a), ms) } }
</script>
```

### 3) Old school XHR (for legacy code)
```js
const xhr = new XMLHttpRequest();
xhr.open('GET', '/score');
xhr.onload = () => console.log(JSON.parse(xhr.responseText));
xhr.send();
```

## When to use AJAX
- Live UI updates (scores, timers, notifications).  
- Typeahead search and pagination.  
- Submitting small forms without leaving the page.  
- Pulling JSON from your own Flask route or a public API.

## Gotchas
- Always **escape/sanitize** before injecting into HTML (use `textContent`).  
- Handle failures: `if (!res.ok) ...`.  
- Consider **debounce** or **throttle** to avoid spamming the server.  
- For high‑frequency updates, consider **Server‑Sent Events** or **WebSockets** later.

## Related Concepts
- [[JSON API responses]] – return JSON from Flask with `jsonify`.
- [[AJAX search (shows)]] – CS50’s live search pattern.
- [[render_template() in Flask]] – server‑rendered vs client‑rendered.
- [[GET vs POST route methods]] – how forms and fetch choose methods.
- [[POST form data and DevTools payload]] – inspect network requests.
- [[MVC (Model View Controller)]] – controller returns data; view updates DOM.
- [[Session (cookies) setup]] – state across multiple AJAX calls.
- [[Jinja templates documentation]] – when you still render HTML server‑side.

## See also

- [MDN: Ajax glossary — what it means today](https://developer.mozilla.org/en-US/docs/Glossary/AJAX). ([MDN Web Docs](https://developer.mozilla.org/en-US/docs/Glossary/AJAX?utm_source=chatgpt.com "Ajax - Glossary | MDN - Mozilla"))
    
- [MDN: Fetch API (modern way)](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API). ([MDN Web Docs](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API?utm_source=chatgpt.com "Fetch API - MDN Web Docs"))
    
- [MDN: XMLHttpRequest (legacy API, not just XML)](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest). ([MDN Web Docs](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest?utm_source=chatgpt.com "XMLHttpRequest - Web APIs | MDN"))
    
- [CS50x 2025 — Week 9 (Flask, AJAX, JSON)](https://cs50.harvard.edu/x/notes/9/). ([edX](https://cs50.harvard.edu/x/notes/9/?utm_source=chatgpt.com "Lecture 9 - CS50x 2025"))
    

## Terms

[[AJAX]] · [[Asynchronous]] · [[JavaScript]] · [[XML]] · [[JSON]] · [[Fetch API]] · [[XMLHttpRequest]] · [[DOM]] · [[HTTP GET]] · [[HTTP POST]]