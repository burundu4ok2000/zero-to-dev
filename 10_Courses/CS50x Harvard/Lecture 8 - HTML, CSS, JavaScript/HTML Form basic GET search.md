---
title: "HTML Form basic GET search"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 18
status: "in-progress"
difficulty: "easy"
date: "2025-10-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-19"
---

![[Screenshot 2025-10-12 at 16.56.52.png]]
![[Screenshot 2025-10-12 at 16.56.55.png]]

## Summary
A tiny **form** that sends a search term to the server using **GET**.  
There’s one **input** with `name="q"` and a **submit** button. When you submit, the browser navigates to the same page (no `action` given) and appends a **query string** like `?q=cats`.

## Very simple
> Form = envelope. The **name** on the input becomes the **key** in the URL’s query: `?q=your-text`.

## Code
```html
<!DOCTYPE html>
<html lang="en">
  <head><title>search</title></head>
  <body>
    <form>
      <input name="q">
      <input type="submit">
    </form>
  </body>
</html>
```


## Example — submit to Google
![[Screenshot 2025-10-12 at 17.01.20.png]]
```html
<form action="https://www.google.com/search" method="get">
  <input name="q" type="search">
  <input type="submit" value="Google Search">
</form>
```
- Clicking **Google Search** builds a URL like  
  `https://www.google.com/search?q=cats` and navigates there.
- If you typed “cats” you will see the query in the address bar:  
  `?q=cats`.

![[Screenshot 2025-10-12 at 17.01.24.png]]

## Example — better input UX
![[Screenshot 2025-10-12 at 17.04.33.png]]
```html
<form action="https://www.google.com/search" method="get">
  <input
    autocomplete="off"
    autofocus
    name="q"
    placeholder="Query"
    type="search">
  <input type="submit" value="Google Search">
</form>
```
- `autocomplete="off"`: don’t show previous entries.  
- `autofocus`: cursor starts here on page load.  
- `placeholder="Query"`: light hint text.  
- `type="search"`: makes a search‑optimized input (may show a clear ✖).

## How it works (step by step)
1. You type into the text box.  
2. You click **Submit** (or press Enter).  
3. Browser builds a URL: current page + `?q=<your text>` (URL‑encoded).  
4. Browser makes a **GET** request to that URL.  
5. The server can read the `q` parameter and respond (e.g., show results).

## Why `name="q"` matters
- The **name** becomes the **key** in the query string.  
- If you change it to `name="search"`, the URL becomes `?search=cats`.

## Add an action and method (recommended)
```html
<form action="/search" method="get">
  <label>
    Search
    <input name="q">
  </label>
  <button type="submit">Submit</button>
</form>
```
- `action` tells the browser where to send the request.  
- `method="get"` puts values in the **URL**; `method="post"` puts them in the **request body**.

## Tips
- Use a `<label>` for accessibility.  
- Don’t put secrets in **GET** queries (they appear in history/logs).  
- Multiple fields create multiple `key=value` pairs: `?q=cats&page=2`.  
- Empty `action` or missing `action` submits to the **same URL**.

## Related Concepts
- [[URLs]] – how paths and queries are formed.  
- [[URL Path and Query string]] – `?key=value` details and examples.  
- [[HTML Hyperlinks a tag]] – links vs form submits.  
- [[HTTP and HTTPS]] – how the request is sent.  
- [[HTTP request logs and headers]] – where you’ll see `?q=...` on the server.  
- [[HTTP Status Codes]] – responses to expect (200/302/etc.).  
- [[DOM Document Object Model]] – the form and inputs are DOM nodes.  
- [[TCP IP]] – the transport beneath HTTP.

## See also
- [MDN — `<form>` element](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/form)
- [MDN — Form submission best practices](https://developer.mozilla.org/en-US/docs/Learn/Forms/Sending_and_retrieving_form_data)
- [MDN — URLSearchParams](https://developer.mozilla.org/en-US/docs/Web/API/URLSearchParams)

## Terms
[[Form]], [[Input]], [[Name attribute]], [[Submit button]], [[GET]], [[POST]], [[Query string]], [[Action attribute]], [[Method attribute]], [[URL encoding]]
