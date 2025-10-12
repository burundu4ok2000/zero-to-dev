---
title: "W3C HTML Validator"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 19
status: "in-progress"
difficulty: "easy"
date: "2025-10-12"
timecode: ""
source: "https://validator.w3.org/"
review_next: "2025-10-26"
---

![[Screenshot 2025-10-12 at 18.30.54.png]]

## Summary
**validator.w3.org** is the official **W3C** checker for **HTML**.  
It finds **broken markup** (bad nesting, missing attributes, duplicate `id`s, unclosed tags) and points you to the exact line.

## Very simple
> Paste a **URL**, upload a **file**, or paste **HTML** → get a list of **errors** and **warnings** with human‑readable tips.

## Key Points
- Three ways to validate: **by URL**, **by file upload**, **by direct input**.  
- Messages are **Errors** (must fix) and **Warnings** (should fix).  
- Great for catching **accessibility** issues (e.g., missing `alt`), **doctype** problems, and **character encoding** mistakes.  
- It validates **HTML**, not your **CSS** or **JavaScript** logic.  
- Clean validation helps with **SEO**, **cross‑browser** behavior, and maintainability.

## Workflow
- Run it when a page looks weird or after big refactors.  
- Fix from **top to bottom**: one error often causes many follow‑ups.  
- Add to CI using the **Nu HTML Checker** CLI (`vnu.jar`) if you want automated checks.

## Related Concepts
- [[HTML Basics and Best Practices]] – write semantic, valid **HTML**.  
- [[DOM Document Object Model]] – what the browser builds from your markup.  
- [[HTML Hyperlinks a tag]] – common source of `href`/`target` mistakes.  
- [[URLs]] – validate correct, absolute vs relative links.  
- [[HTTP and HTTPS]] – how pages get fetched for validation by URL.  
- [[HTTP Status Codes]] – the validator must reach your page (avoid 404/500).  
- [[DNS Domain Name System]] – URL by‑name lookups before validation.  
- [[HTML Form basic GET search]] – forms often reveal missing labels or names.

## See also
- [W3C — Markup Validation Service](https://validator.w3.org/)
- [Nu HTML Checker (v.Nu) docs](https://validator.github.io/validator/)
- [MDN — HTML validators and linting](https://developer.mozilla.org/en-US/docs/Learn/HTML/Introduction_to_HTML/Getting_started#checking_your_work)

## Terms
[[W3C Validator]], [[HTML validation]], [[Error message]], [[Warning message]], [[Doctype]], [[Character encoding]], [[Accessibility]], [[Nu HTML Checker]]
