---
title: "HTML Basics and Best Practices"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 16
status: "in-progress"
difficulty: "easy"
date: "2025-10-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-19"
---

![[IMG_5844.PNG]]

## Summary
**HTML** describes the **structure** and **meaning** of a web page.  
It is **markup**, not a programming language. Browsers read HTML, build a **DOM tree**, then **CSS** styles it and **JavaScript** adds behavior.

## Very simple
> Think LEGO. Each **tag** is a brick, **attributes** are stickers, and the **DOM** is the finished model the browser builds.

## Core mental model
- An HTML file is plain text with **elements** like `<p>`, `<a>`, `<img>`.
- Elements **nest** to form a **tree** (the **DOM**).
- Prefer **semantic** elements — they describe what content **is**, not how it looks.

## Minimal skeleton
```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Hello</title>
    <link rel="stylesheet" href="styles.css">
  </head>
  <body>
    <h1>Hello, world</h1>
    <script src="app.js" defer></script>
  </body>
</html>
```

## Head vs Body
- `<head>`: metadata for browsers/search engines: `<title>`, `<meta>`, `<link>`, `<script>`, `<style>`.
- `<body>`: visible content and interactive elements.

## Common elements you will use a lot
- **Text & headings**: `<h1>` … `<h6>`, `<p>`, `<strong>`, `<em>`, `<br>`.
- **Grouping**: `<div>` (block), `<span>` (inline).
- **Semantic layout**: `<header>`, `<main>`, `<nav>`, `<section>`, `<article>`, `<aside>`, `<footer>`.
- **Links & media**: `<a href="...">`, `<img src="..." alt="...">`, `<video>`, `<audio>`.
- **Lists**: `<ul>` / `<ol>` with `<li>`.
- **Tables**: `<table>`, `<thead>`, `<tbody>`, `<tr>`, `<th>`, `<td>` (for tabular data only).
- **Forms**: `<form>`, `<label>`, `<input>`, `<textarea>`, `<select>`, `<button>`.

## Attributes to remember
- **Global**: `id`, `class`, `title`, `hidden`, `tabindex`, `lang`, `data-*`, `aria-*`.  
- **Links & images**: `href`, `target="_blank"`, `rel="noopener noreferrer"`, `src`, `alt`.  
- **Form**: `name`, `value`, `required`, `placeholder`, `min`, `max`, `pattern`, `type`.

## Links in practice
```html
<!-- Absolute vs relative -->
<p><a href="https://www.example.com">External</a></p>
<p><a href="about.html">Internal page</a></p>

<!-- Same‑page jump -->
<a href="#contact">Jump to contact</a>
<h2 id="contact">Contact</h2>
```

## Lists
```html
<ul>
  <li>Apples</li>
  <li>Bananas</li>
</ul>

<ol>
  <li>First</li>
  <li>Second</li>
</ol>
```

## Tables for data
```html
<table>
  <thead>
    <tr><th>City</th><th>Population</th></tr>
  </thead>
  <tbody>
    <tr><td>Boston</td><td>675,647</td></tr>
    <tr><td>Cambridge</td><td>118,403</td></tr>
  </tbody>
</table>
```

## Forms — the essentials
```html
<form action="/subscribe" method="post">
  <label for="email">Email</label>
  <input id="email" name="email" type="email" required>
  <button type="submit">Subscribe</button>
</form>
```
- `action` = where to send the data; `method` = **GET** (query string) or **POST** (request body).
- Connect `<label>` to `<input>` with matching `for`/`id` for accessibility.
- Use the right `type` (`email`, `number`, `date`, `checkbox`, `radio`, `file`) for built‑in validation.

## Accessibility basics
- Use **semantic elements** so screen readers understand the page.
- **Images need `alt`**. If decorative, use empty `alt=""`.
- **Headings** in order (`h1` then `h2`, …). Avoid skipping levels.
- Provide **labels** for all form fields.
- Ensure links are visually obvious (underline or a clear style).

## SEO and metadata
```html
<head>
  <title>My Page</title>
  <meta name="description" content="Short summary for search results.">
  <meta property="og:title" content="My Page">
  <meta property="og:description" content="Social preview text.">
  <meta property="og:type" content="website">
</head>
```
- Clear **title** and **description** help search and sharing.
- Prefer one main `<h1>` per page.

## Performance tips
- Keep HTML clean; avoid deep nesting.
- Use `defer` on scripts or place them at the end of `<body>`.
- Compress and correctly size images.

## DevTools and validation
- Right‑click → **Inspect** to view and edit the live DOM.
- Validate at the **W3C Validator** to catch markup errors.
- Use the **Network** tab to see which resources your HTML loads.

## Safety notes
- Avoid injecting untrusted HTML. Prefer `textContent` over `innerHTML` in JS.
- If you use `target="_blank"`, pair it with `rel="noopener noreferrer"`.

## Common pitfalls
- Missing required attributes (e.g., `alt` on `img`).
- Using tables for layout (don’t).  
- Missing `<label>` for inputs.  
- Overusing `<div>` instead of semantic tags.

## Why It Matters
HTML is the **foundation**. Clear, semantic structure makes CSS styling easier, accessibility better, and JavaScript simpler.

## Related Concepts
- [[DOM Document Object Model]] – how the browser represents your HTML.
- [[HTML Hyperlinks a tag]] – linking within and across pages.
- [[URLs]] – how href and src are formed.
- [[HTTP and HTTPS]] – how HTML is transferred.
- [[HTTP Status Codes]] – responses the browser gets when fetching pages.
- [[DNS Domain Name System]] – resolves domain names found in links.
- [[TCP IP]] – transport under HTTP.
- [[IPv4 Header what’s inside a packet]] – packet format that carries HTML.

## See also
- [MDN — HTML elements reference](https://developer.mozilla.org/en-US/docs/Web/HTML/Element)
- [MDN — HTML beginner guide](https://developer.mozilla.org/en-US/docs/Learn/Getting_started_with_the_web/HTML_basics)
- [W3C Markup Validation Service](https://validator.w3.org/)

## Terms
[[HTML]], [[Element]], [[Attribute]], [[Semantic HTML]], [[Head]], [[Body]], [[Heading]], [[Paragraph]], [[Link]], [[Image]], [[List]], [[Table]], [[Form]], [[Input types]], [[Label]], [[ARIA]], [[Alt text]], [[Viewport meta tag]], [[Open Graph]], [[Defer attribute]], [[Validation]]
