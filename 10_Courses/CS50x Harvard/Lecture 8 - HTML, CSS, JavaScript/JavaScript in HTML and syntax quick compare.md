---
title: "JavaScript in HTML and syntax quick compare"
lang_tags: "#lang/html, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 23
status: "in-progress"
difficulty: "easy"
date: "2025-10-15"
timecode: ""
source: "CS50x 2025 Week 8"
review_next: "2025-10-25"
---

![[Screenshot 2025-10-15 at 15.20.57.png]]
![[Screenshot 2025-10-15 at 15.26.18.png]]
![[Screenshot 2025-10-15 at 15.27.17.png]]

## Summary
How to include **JavaScript** in an HTML page with the **script** tag, plus a **beginner** syntax map that compares JavaScript to **C** and **Python**. Keep it practical: where to put scripts, how to avoid slow pages, and the smallest useful patterns for **events** and the **DOM**.

## Very simple
> HTML is **structure**, CSS is **style**, JavaScript is **behavior**.  
> You add JavaScript using the `<script>` tag. Use **external files** and the **defer** attribute to keep the page fast.

## Ways to include JavaScript
### 1) Inline script (quick demos only)
```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Inline JS</title>
    <script>
      document.addEventListener('DOMContentLoaded', () => {
        console.log('Hello from inline JS');
      });
    </script>
  </head>
  <body>Hi</body>
</html>
```
- Good for **tiny** examples. Hard to reuse and test in bigger projects.

### 2) External file (recommended)
```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>External JS</title>
    <script src="/js/app.js" defer></script>
  </head>
  <body>Hi</body>
</html>
```
- Put your code in `/js/app.js`.  
- `defer` = wait for HTML to parse, then run scripts **in order**.

### 3) Async script (independent tool, e.g., analytics)
```html
<script src="https://example.com/analytics.js" async></script>
```
- Starts **downloading** while the page loads and **executes** when ready.  
- Use only when the script **does not** depend on the DOM or on other scripts.

### 4) ES Modules (modern)
```html
<script type="module">
  import { sum } from '/js/utils.js';
  console.log(sum(2, 3));
</script>
```
- Scoped by default (no accidental globals).  
- `type="module"` acts like **defer** automatically.  
- You can split code into files and **import/export**.

## Where to place scripts
- In `<head>` with **defer** (best) → keeps markup & behavior separate and fast.  
- At the **end of `<body>`** if you cannot use defer.  
- Avoid blocking scripts in `<head>` (no `defer/async`) — they **freeze** rendering.

## DOM + Events (core idea)
JavaScript listens for **events** then updates the **DOM**.
```html
<button id="go">Click me</button>
<p id="msg">Hello</p>
<script defer>
  document.getElementById('go').addEventListener('click', () => {
    document.getElementById('msg').textContent = 'Clicked!';
  });
</script>
```
Common events you’ll meet early: `click`, `change`, `input`, `submit`, `keyup`, `keydown`, `mouseover`, `mouseout`, `load`, `touchstart`, `touchmove`.

### Small patterns
**Submit a form (prevent page reload):**
```html
<form id="search">
  <input name="q" type="search" placeholder="Query">
  <button>Search</button>
</form>
<script defer>
  search.addEventListener('submit', (e) => {
    e.preventDefault();                 // stop full page reload
    const q = new FormData(search).get('q');
    console.log('Searching for:', q);
  });
</script>
```

**Toggle a CSS class:**
```html
<button id="t">Toggle</button>
<div id="box" class="hidden">Secret</div>
<style>.hidden { display:none; }</style>
<script defer>
  t.onclick = () => box.classList.toggle('hidden');
</script>
```

## JavaScript vs C vs Python — quick compare
| Idea         | JavaScript                                                     | C                              | Python                           |
| ------------ | -------------------------------------------------------------- | ------------------------------ | -------------------------------- |
| Variables    | `let x = 1;`, `const y = 2;` (block scope). Avoid `var`.       | `int x = 1;` (typed).          | `x = 1` (dynamic).               |
| Functions    | `function f(a) { return a+1; }` or arrow `const f = a => a+1;` | `int f(int a) { return a+1; }` | `def f(a): return a+1`           |
| Blocks       | `{ }`. Semicolons optional but **recommended**.                | `{ }` + required `;`.          | Indentation (no braces, no `;`). |
| Equality     | === strict (type + value), `==` loose (avoid).                 | ==                             | == value, `is` identity.         |
| Arrays/Lists | `[1,2,3]` with `.push()`, `.map()`.                            | `int a[3]` / pointers.         | `[1,2,3]`.                       |
| Dictionaries | **Objects** `{ key: "v" }` and **Map**.                        | `struct` / libs.               | `{"key": "v"}`.                  |
| Strings      | `"hi"`, `'hi'`, backticks **template**: \`hi ${x}\`.           | `"hi"`                         | `'hi'`, `"hi"`, `f"hi {x}"`.     |
| Booleans     | `true`/`false`, plus **truthy/falsy**.                         | `1`/`0`                        | `True`/`False`.                  |
| Printing     | `console.log(x)`                                               | `printf("%d", x)`              | `print(x)`                       |

### Control flow (looks like C, feels like Python)
```js
const n = 3;
if (n > 2) {
  console.log('big');
} else {
  console.log('small');
}

for (let i = 0; i < 3; i++) {
  console.log(i);
}

const nums = [1,2,3];
nums.forEach(x => console.log(x));
```
- JavaScript is **dynamically typed** (like Python) but uses **C‑style** braces and operators.

## Gotchas to remember
- Use **`const`** for values that don’t change, **`let`** for ones that do. Avoid **`var`**.  
- Prefer === over ==  
- `undefined` (missing) vs `null` (intentional empty).  
- Browsers are **case‑sensitive**: `document.getElementById`, not `getElementByID`.  
- Wrap DOM code in **`defer`** or in a `DOMContentLoaded` handler so elements exist.

## Mini glossary
- **DOM**: a tree of nodes (elements) that represents the page.  
- **Event**: a signal from the browser (click, key press, page load).  
- **Handler/Listener**: your function that runs when the event happens.  
- **Module**: a JS file that can **import/export** pieces of code.

## Related Concepts
- [[HTML Basics and Best Practices]] – clean markup before adding scripts.  
- [[DOM Document Object Model]] – what JS reads and changes.  
- [[CSS Basics selectors box model and cascade]] – style around your behavior.  
- [[HTML Hyperlinks a tag]] – navigation that JS can enhance.  
- [[URLs]] – how browsers fetch `/js/app.js`.  
- [[HTTP and HTTPS]] – scripts are just files downloaded by the browser.  
- [[Frameworks when and how to use]] – when to move beyond plain JS.  
- [[Bootstrap quick start]] – example of loading a library with `<script>`.

## See also
- [MDN — HTML script element](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/script)
- [MDN — JavaScript language overview](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Introduction)
- [MDN — Events](https://developer.mozilla.org/en-US/docs/Web/Events)

## Terms
[[JavaScript]], [[script]], [[inline script]], [[external script]], [[defer]], [[async]], [[module]], [[import]], [[export]], [[const]], [[let]], [[var]], [[arrow function]], [[event listener]], [[DOM]], [[template literal]], [[strict equality]]
