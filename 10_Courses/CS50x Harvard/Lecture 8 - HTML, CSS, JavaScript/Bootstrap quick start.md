---
title: Bootstrap quick start
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 22
status: in-progress
difficulty: easy
date: 2025-10-13
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/8/
review_next: 2025-10-23
---

![[Screenshot 2025-10-13 at 10.29.02.png]]

## Summary
**Bootstrap** is a **CSS framework** that gives you ready styles and **components** (buttons, forms, navbars).  
You add Bootstrap to your page and then use special **class** names to get nice design fast.

## Very simple
> Think **lego** for UI. You write normal **HTML**, then add Bootstrap **classes** like `btn`, `container`, `row`, `col`.  
> The framework handles spacing, colors, and responsive layout.

## Add Bootstrap (CDN)
Put this in `<head>`:
```html
<link
  rel="stylesheet"
  href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css">
```
(For JS components like modals, also include the Bootstrap bundle script. For now we focus on CSS.)

## Core ideas (beginner friendly)
- **Containers**: wrap content with `.container` or `.container-fluid` to get nice page margins.
- **Grid system**: create rows with `.row`, columns with `.col`. Use numbers for sizes: `.col-6` means 6/12 width.
- **Spacing** utilities: `m-3` (margin), `p-2` (padding). Add directions: `mt-3`, `px-4`.
- **Typography & colors**: classes like `text-center`, `fw-bold`, `text-muted`, `bg-light`.
- **Buttons**: `btn`, `btn-primary`, `btn-outline-secondary`.
- **Forms**: `form-control` on inputs; `btn` on submit.

## Mini example
```html
<div class="container py-4">
  <h1 class="mb-3">Hello, Bootstrap</h1>

  <div class="row g-3">
    <div class="col-12 col-md-6">
      <div class="p-3 border rounded">Left column</div>
    </div>
    <div class="col-12 col-md-6">
      <div class="p-3 border rounded">Right column</div>
    </div>
  </div>

  <form class="mt-4 d-flex gap-2">
    <input class="form-control" placeholder="Search">
    <button class="btn btn-primary">Search</button>
  </form>
</div>
```
- **Responsive**: on mobile, columns stack; on desktop (`md`), they sit side‑by‑side.
- No custom CSS needed; only **class names**.

## When to use Bootstrap
- You want a **clean layout quickly**.
- You prefer **stable defaults** for spacing, fonts, and colors.
- You are learning and want **good patterns** to copy.

## When not to
- You need a very **custom** look with unusual design. In that case write your own **CSS** or use a smaller library.

## Tips
- Keep your own `styles.css` for small overrides (e.g., custom brand color).
- Read the **Utilities** page: spacing, display, flex helpers will save you time.
- Check the **Components** page for copy‑paste examples (alerts, cards, navbars).
- Remove unused CSS for production if file size matters.

## Related Concepts
- [[CSS Basics selectors box model and cascade]] – understand how the classes work.
- [[HTML Basics and Best Practices]] – Bootstrap sits on top of clean HTML.
- [[Frameworks when and how to use]] – where Bootstrap fits.
- [[DOM Document Object Model]] – components are just DOM nodes with classes.
- [[HTML Hyperlinks a tag]] – style links and nav.
- [[URLs]] – link the CDN in `<head>`.
- [[HTTP and HTTPS]] – how the CSS file is downloaded.

## See also
- [Bootstrap — Getting started](https://getbootstrap.com/docs/5.3/getting-started/introduction/)
- [Bootstrap — Layout & Grid](https://getbootstrap.com/docs/5.3/layout/grid/)
- [Bootstrap — Utilities](https://getbootstrap.com/docs/5.3/utilities/api/)

## Terms
[[Bootstrap]], [[CDN]], [[container]], [[row]], [[column]], [[grid system]], [[utility classes]], [[responsive]], [[form-control]], [[btn]]
