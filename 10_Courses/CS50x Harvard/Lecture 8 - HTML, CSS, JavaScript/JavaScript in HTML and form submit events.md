---
title: JavaScript in HTML and form submit events
lang_tags: "#lang/en"
type_tags: "#type/concept"
course_tags: "#course/CS50x"
lecture_tags: "#lecture/Week8"
tool_tags: ""
atom_idx: 24
status: in-progress
difficulty: easy
date: 2025-10-15
timecode: ≈2:33:00–2:41:00
source: https://cs50.harvard.edu/x/2025/weeks/8/
review_next: ""
---

## One Liner
Put **JavaScript** inside **HTML** with `<script>...</script>` or by linking a `.js` file, then use **event listeners** to react to user actions like a form **submit**.

## TL;DR
- Inline script: place JS code between `<script>...</script>` (often at the end of `<body>`).  
- External script: `<script src="scripts.js"></script>` keeps code separate and reusable.  
- Listen for events: `form.addEventListener('submit', handler)` runs your function when the user submits the form.  
- Stop the page from reloading: call `event.preventDefault()` inside the handler.  
- Read input from the page: `document.querySelector('#name').value` grabs the value of an input with `id="name"`.

## Why this matters
**Forms** send data to servers. With **JavaScript**, you can validate, show messages, or change the page **before** the request is sent. This makes the UI feel faster and safer.

## How it works (from David’s examples)
1) **Named handler function**
```html
<form>
  <input id="name" name="name" placeholder="Name" type="text">
  <input type="submit">
</form>

<script>
  function greet(event) {
    let name = document.querySelector('#name').value
    alert('hello, ' + name)
    event.preventDefault()      // stop default submit + reload
  }

  let form = document.querySelector('form')
  form.addEventListener('submit', greet)
</script>
```
- The browser fires a **submit** event on the `<form>`.  
- `addEventListener` wires that event to `greet`.  
- Inside `greet`, we read the input and **prevent** the default page reload.

2) **Anonymous (inline) handler**
```html
<script>
  let form = document.querySelector('form')
  form.addEventListener('submit', function(event) {
    alert('hello, ' + document.querySelector('#name').value)
    event.preventDefault()
  })
</script>
```
- Instead of naming a function, we pass an **anonymous function** directly.  
- Both patterns are fine; anonymous is compact, named is easier to reuse and test.

## Small best practices
- Prefer **external** `.js` files for anything non‑trivial. Easier to cache, reuse, and debug.  
- Put `<script>` tags **just before `</body>`** (or use `defer` on `<script src=...>`) so HTML loads first.  
- Always call **`preventDefault()`** when you want to handle the submit **without** a page refresh.  
- Use **`querySelector`** to find elements by CSS selector; keep **ids** unique.  
- Show messages with `alert` only for demos; in real apps render text into the DOM.

## Examples in one glance
- **Grab form**: `document.querySelector('form')`  
- **Listen**: `form.addEventListener('submit', handler)`  
- **Read value**: `document.querySelector('#name').value`  
- **Stop reload**: `event.preventDefault()`  
- **Pop up**: `alert('hello, ' + name)`

## Common mistakes
- Forgetting to **close** `</script>` even when using `src`.  
- Using `return false` instead of `event.preventDefault()` (works in some cases but is unclear).  
- Selecting the wrong element (e.g., `'input'` instead of `'#name'`).  
- Naming clashes: using the same **id** for multiple elements.

## Terms
[[script tag]], [[external script]], [[event listener]], [[submit event]], [[preventDefault]], [[querySelector]], [[anonymous function]], [[DOM]]

## Related Concepts
- [[DOM Document Object Model]] – where elements live; events fire on these nodes.  
- [[HTML Hyperlinks a tag]] – navigation vs. forms; both trigger requests.  
- [[URLs]] – form **GET** builds query strings like `?q=value`.  
- [[HTTP request logs and headers]] – see what the browser actually sends.  
- [[HTTP Status Codes]] – what the server answers after a submit.  
- [[HTML Forms basics]] – new note to collect `<form>`, `<input>`, attributes.  
- [[GET vs POST]] – new note about methods and when to use them.  
- [[Client side validation]] – new note for checking input before sending.

## See Also
- [MDN: Using the script element](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/script)
- [MDN: addEventListener](https://developer.mozilla.org/en-US/docs/Web/API/EventTarget/addEventListener)
- [MDN: Preventing form submissions](https://developer.mozilla.org/en-US/docs/Learn/Forms/Form_validation#no_submit)
