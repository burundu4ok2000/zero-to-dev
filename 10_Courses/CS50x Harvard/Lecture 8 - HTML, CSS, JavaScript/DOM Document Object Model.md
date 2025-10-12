---
title: "DOM Document Object Model"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 13
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

![[IMG_5846.PNG]]

## Summary
The **DOM** is a **tree** in memory that represents your HTML page.  
Each tag becomes a **node** (like `html`, `head`, `body`, `title`). Text inside tags is a **text node**. JavaScript can read and change this tree to update the page without reloading.

## Very simple
> Think of a family tree for the page. `html` is the root parent. `head` and `body` are its children. Change a node → the page on screen updates.

## Key Points
- **document** is the entry point to the DOM.
- **Element nodes** hold tags; **text nodes** hold words.
- Nodes have **parent → children** relationships.
- Common JS APIs:
  - **`document.querySelector()`** to find an element.
  - **`element.textContent` / `innerHTML`** to change content.
  - **`element.setAttribute()`** to set attributes.
  - **`element.classList.add/remove/toggle`** to change classes.
  - **`element.append()` / `remove()`** to add or delete nodes.
- **Events** (click, input, submit) fire on nodes. Use **`addEventListener()`**.
- Events **bubble** up the tree; you can stop defaults with **`event.preventDefault()`**.
- Too many DOM changes cause **reflow/repaint**; batch updates for performance.

## Examples
```html
<body>
  <h1 id="title">Hello</h1>
  <button id="btn">Change</button>
</body>
<script>
  const h1 = document.querySelector("#title");
  const btn = document.querySelector("#btn");
  btn.addEventListener("click", () => {
    h1.textContent = "Hello, DOM";
    h1.classList.toggle("highlight");
  });
</script>
```
```css
.highlight { font-weight: bold; }
```

## Why It Matters
The DOM is how **JavaScript** talks to the page. Understanding the tree makes it easy to build interactions, validate forms, and change styles dynamically.

## Questions
- ❓When should you prefer `textContent` over `innerHTML`?  
- ❓How does **event delegation** use bubbling to handle many items with one listener?

## Related Concepts
- [[URLs]] – browser goes to a URL and loads HTML that becomes the DOM.
- [[HTTP and HTTPS]] – how the HTML file arrives.
- [[HTML Hyperlinks a tag]] – links are DOM nodes that navigate.
- [[TCP IP]] – transport that delivers the HTML.
- [[IPv4 Header what’s inside a packet]] – the packet carrying the HTML.
- [[DNS Domain Name System]] – resolves the host before loading the page.
- [[CSS Basics selectors and cascade]] – CSS selects DOM nodes to style.
- [[JavaScript Events and the DOM]] – deeper dive into event flow and listeners.

## See also
- [MDN — DOM introduction](https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model/Introduction)
- [MDN — querySelector](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelector)
- [MDN — addEventListener](https://developer.mozilla.org/en-US/docs/Web/API/EventTarget/addEventListener)

## Terms
[[DOM]], [[Node]], [[Element]], [[Text node]], [[Attribute]], [[querySelector]], [[textContent]], [[innerHTML]], [[classList]], [[append]], [[remove]], [[Event]], [[addEventListener]], [[Event bubbling]], [[preventDefault]], [[Reflow]], [[Repaint]]
