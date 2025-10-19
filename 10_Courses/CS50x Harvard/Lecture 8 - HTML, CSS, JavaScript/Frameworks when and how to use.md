---
title: Frameworks when and how to use
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 21
status: in-progress
difficulty: easy
date: 2025-10-13
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/8/
review_next: 2025-10-23
---

![[Screenshot 2025-10-13 at 10.27.03.png]]

## Summary
**Frameworks** are ready‑made **building blocks** for websites and apps.  
They give you **CSS styles**, **UI components**, or **JavaScript tools** so you can build faster and avoid repeating the same work.

## Very simple
> A framework is like a **toolbox**: buttons, forms, grids, and rules already prepared.  
> You add your content and small custom CSS or JS on top.

## Kinds of frameworks
- **CSS frameworks** (Bootstrap, Tailwind, Bulma): prebuilt **styles**, **grid systems**, **components**.  
- **JS frameworks** (React, Vue, Svelte): help manage **UI state** and build components with **JavaScript**.  
- **Full‑stack frameworks** (Django, Flask, Rails): include server features, templates, and routing.

## Why use them
- **Speed**: ship working pages quickly.  
- **Consistency**: same spacing, colors, and components.  
- **Browser fixes** are handled for you.  
- **Docs** and examples help beginners learn patterns.

## Trade‑offs
- **Extra size**: you may load more CSS/JS than you need.  
- **Learning curve**: you must follow the framework’s **rules** (classes, file structure).  
- **Same‑looking sites** if you do not customize.  
- **Lock‑in**: switching later can take time.

## Quick start examples

### CSS framework via CDN (Bootstrap)
```html
<!-- in <head> -->
<link
  rel="stylesheet"
  href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css">
</head>
<body class="p-4">
  <h1 class="mb-3">Hello</h1>
  <button class="btn btn-primary">Click me</button>
</body>
```
- Classes like `btn` and `btn-primary` give you styled buttons **without** writing custom CSS.

### Utility‑first CSS (Tailwind) via CDN (for demos)
```html
<script src="https://cdn.tailwindcss.com"></script>
<div class="p-6 bg-slate-100 rounded-xl">
  <h2 class="text-xl font-semibold mb-2">Card</h2>
  <p class="text-slate-700">Utility classes style each part.</p>
  <button class="mt-3 px-4 py-2 bg-blue-600 text-white rounded">Save</button>
</div>
```
- You compose small **utility classes** (`p-6`, `bg-blue-600`) to style elements.

### JS component mindset (React idea in plain JS)
You do **not** need React yet, but the **component** idea is useful:
```html
<div id="app"></div>
<script>
  function Button(text) {{           // tiny component
    const b = document.createElement('button');
    b.className = 'btn btn-primary';
    b.textContent = text;
    return b;
  }}
  document.querySelector('#app').append(Button('Hello'));
</script>
```
- A component is a **reusable piece** that renders HTML and handles events.

## When to use a framework
- You need a **grid**, **navbar**, **forms**, and **buttons** fast.  
- You work in a **team** and want shared rules.  
- You are learning and want high‑quality **examples** to copy and then modify.

## When not to
- Small page with **few styles** → plain CSS is simpler and lighter.  
- You need a **very custom** look → write your own CSS or use only a **tiny** helper library.

## Tips
- Start with a CDN while learning, then **install locally** for production.  
- Keep your own **styles.css** to override small things.  
- Use your browser’s **Inspect** to see which classes a component uses.  
- Remove unused CSS/JS before shipping (tree‑shake, PurgeCSS, build steps).

## Related Concepts
- [[HTML Basics and Best Practices]] – frameworks sit on top of clean HTML.  
- [[CSS Basics selectors box model and cascade]] – helps you override framework styles safely.  
- [[DOM Document Object Model]] – components are DOM nodes.  
- [[HTML Hyperlinks a tag]] – common navbar building block.  
- [[URLs]] – how CDNs are linked.  
- [[HTTP and HTTPS]] – delivering framework files.  
- [[HTTP Status Codes]] – debug missing framework assets.  
- [[W3C HTML Validator]] – check your markup even when using frameworks.

## See also
- [Bootstrap — Getting started](https://getbootstrap.com/docs/5.3/getting-started/introduction/)
- [Tailwind — Documentation](https://tailwindcss.com/docs)
- [MDN — Choosing a framework](https://developer.mozilla.org/en-US/docs/Learn/Tools_and_testing/Client-side_JavaScript_frameworks/Introduction)

## Terms
[[framework]], [[library]], [[component]], [[CDN]], [[Bootstrap]], [[Tailwind CSS]], [[grid system]], [[utility classes]], [[override]], [[lock-in]]
