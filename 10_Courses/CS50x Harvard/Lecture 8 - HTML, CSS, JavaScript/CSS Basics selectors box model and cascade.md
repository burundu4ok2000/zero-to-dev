---
title: "CSS Basics selectors box model and cascade"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 20
status: "in-progress"
difficulty: "easy"
date: "2025-10-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-19"
---

![[Screenshot 2025-10-12 at 18.31.51.png]]

## Summary
**CSS** styles the HTML **DOM**. You write **rules** as ``selector {{ property: value; }}``.  
The browser decides which rules win using the **cascade** and **specificity**. Every element is a **box** with content, padding, border, and margin.

## Very simple
> HTML = structure, CSS = paint. Pick elements with a **selector**, set **properties** with **values**.

## Key Points
- Place CSS via **external file** `<link rel="stylesheet" href="styles.css">`, **`<style>`** in the page, or **inline** `style=""` (avoid inline in real apps).  
- A rule is **selector → declaration block**: `{{ property: value; }}`.  
- **Specificity** order: inline > id `#id` > class `.class` > tag `p` > universal `*`. Later rules with same specificity **override** earlier ones.  
- **Box model**: `width/height` apply to the **content**; add `padding`, `border`, `margin`. `box-sizing: border-box;` makes sizing easier.  
- Layout: **flexbox** for rows/columns, **grid** for 2D layouts, **position** for fine control.  
- Units: **px**, **%**, **em/rem**, **vh/vw**. Colors: keywords, hex, `rgb()`, `hsl()`.

## Examples
```html
<link rel="stylesheet" href="styles.css">
<h1 class="title">Hello</h1>
<p id="lead">Intro</p>
```
```css
/* selectors */
h1 { color: royalblue; }
#lead { font-weight: 600; }
.title { margin-bottom: 0.5rem; }

/* box model */
.card { padding: 1rem; border: 1px solid #ddd; margin: 1rem 0; }

/* flex layout */
.row { display: flex; gap: 1rem; }
.row > .col { flex: 1; }
```

## Why It Matters
Good CSS makes content readable on every device. Knowing **specificity** and the **box model** prevents bugs and layout fights.

## Related Concepts
- [[HTML Basics and Best Practices]] – CSS needs clean semantic HTML.
- [[DOM Document Object Model]] – CSS selects and styles DOM nodes.
- [[HTML Hyperlinks a tag]] – style navigation states.
- [[URLs]] – how CSS files are linked and fetched.
- [[HTTP and HTTPS]] – the requests that deliver stylesheets.
- [[HTTP Status Codes]] – diagnose missing CSS files.
- [[W3C HTML Validator]] – catch broken markup that breaks CSS.

## See also
- [MDN — Learn CSS](https://developer.mozilla.org/en-US/docs/Learn/CSS)
- [MDN — Selectors](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Selectors)
- [MDN — Cascade and specificity](https://developer.mozilla.org/en-US/docs/Web/CSS/Cascade)

## Terms
[[selector]], [[declaration]], [[property]], [[value]], [[specificity]], [[cascade]], [[inheritance]], [[box model]], [[padding]], [[border]], [[margin]], [[display]], [[flexbox]], [[grid]], [[rem]], [[viewport units]], [[box-sizing]]
