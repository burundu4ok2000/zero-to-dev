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
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Search Example</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #f4f4f9;
        }
        .search-container {
            background-color: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            width: 300px;

        }
        input[type="text"] {
            width: 100%;
            padding: 10px;
            margin-bottom: 10px;
            border: 1px solid #ccc;
            border-radius: 4px;
        }
        button {
            padding: 10px 20px;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }
        button:hover {
            background-color: #0056b3;
        }
        ul {
            list-style-type: none;
            padding: 0;
        }
        li {
            padding: 10px 0;
            border-bottom: 1px solid #ddd;
        }
    </style>
</head>
<body>
    <div class="search-container">
        <input type="text" id="searchInput" placeholder="Search...">
        <button onclick="searchResults()">Search</button>
        <ul id="searchResults"></ul>
    </div>
    <script>
        function searchResults() {
            const searchInput = document.getElementById('searchInput');
            const resultsList = document.getElementById('searchResults');
            const searchQuery = searchInput.value.toLowerCase();
            // Simulated search results
            const simulatedResults = [
                { title: 'The Office' },
                { title: 'Breaking Bad' },
                { title: 'Friends' },
                { title: 'Game of Thrones' }
            ];
            // Filter results based on the search query
            const filteredResults = simulatedResults.filter(item => item.title.toLowerCase().includes(searchQuery));

            // Clear existing results
            resultsList.innerHTML = '';

            // Display results
            filteredResults.forEach(result => {
                const resultItem = document.createElement('li');
                resultItem.textContent = result.title;
                resultsList.appendChild(resultItem);
            });
        }
    </script>
</body>
</html>
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