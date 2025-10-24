---
title: "AJAX dropdown example (XHR + infodiv)"
lang_tags: "#lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 19
status: "done"
difficulty: "easy"
date: "2025-10-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

## One‑liner
A `<select>` triggers `cs50Info(this.value)`, which uses **XMLHttpRequest** to fetch `name + ".html"` and inject the returned snippet into `#infodiv` (no full page reload).

## The core snippet
```html
<select name="staff" onchange="cs50Info(this.value)">
  <option value="">Select someone</option>
  <option value="bowden">Rob Bowden</option>
  <option value="chan">Zamyla Chan</option>
  <option value="malan">David J. Malan</option>
  <option value="zlatkova">Maria Zlatkova</option>
</select>

<div id="infodiv">Information goes here</div>
<script src="https://code.jquery.com/jquery-3.7.1.min.js"></script>
<script src="ajax.js"></script>
```

```js
// ajax.js
function cs50Info(name) {
  if (name === "") return;                           // guard

  var ajax = new XMLHttpRequest();                   // XHR object
  ajax.onreadystatechange = function () {            // fires on state changes
    if (ajax.readyState === 4 && ajax.status === 200) {
      $('#infodiv').html(ajax.responseText);         // inject snippet
    }
  };

  ajax.open('GET', name + '.html', true);            // define request
  ajax.send();                                       // send async
}
```
Each `*.html` file (e.g., `chan.html`) is a small HTML fragment (not a full page) with a name, an `<img>`, and a few `<p>` lines—perfect for dropping into the page.

## How it works (step‑by‑step)
1) User selects a person → `onchange` calls `cs50Info(this.value)` with a slug like `"chan"`.  
2) **XHR** is created; we attach a callback to `onreadystatechange`.  
3) When **readyState** becomes `4` (**DONE**) and **status** is `200` (**OK**), we grab `ajax.responseText` and put it into `#infodiv`.  
4) `open('GET', name + '.html', true)` sets up the URL; `send()` fires the request.  
5) Only the **infodiv** updates; the rest of the page stays as‑is → **AJAX** UX.

## Same idea with modern **fetch**
```js
async function cs50InfoFetch(name) {
  if (!name) return;
  const res = await fetch(name + '.html', { headers: { 'Accept': 'text/html' } });
  if (!res.ok) return;                        // handle errors
  const html = await res.text();
  document.querySelector('#infodiv').innerHTML = html; // controlled snippets
}
```

## Notes
- jQuery’s `$('#infodiv').html(...)` inserts HTML; use it only with **trusted** snippets. For untrusted text, prefer `.text()` / `textContent` to avoid **XSS**.  
- This example fetches **HTML**; many apps return **JSON** and let JS build the DOM manually.

## Related Concepts
- [[AJAX — Asynchronous JavaScript and XML]]
- [[XMLHttpRequest basics readyState status open send]]
- [[JSON API responses]]
- [[GET vs POST route methods]]
- [[render_template() in Flask]]
- [[Jinja templates documentation]]
- [[Route variables with angle brackets]]
- [[Session (cookies) setup]]

## See also
- CS50x — **AJAX** short (transcript & video): how `onchange`, **readyState**/`status`, and `name + ".html"` work.  
  https://cs50.harvard.edu/x/2021/shorts/ajax/  
- CS50x 2025 Notes — **JSON/AJAX** example using `fetch('/search')` and `jsonify` in Flask.  
  https://cs50.harvard.edu/x/notes/9/#json  
- jQuery `.html()` (inserting HTML):  
  https://api.jquery.com/html/
