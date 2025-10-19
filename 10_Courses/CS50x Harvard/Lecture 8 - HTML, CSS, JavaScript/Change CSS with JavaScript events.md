---
title: Change CSS with JavaScript events
lang_tags: "#lang/javascript, #lang/html, #lang/css"
type_tags: "#type/concept"
course_tags: "#course/CS50x"
lecture_tags: "#lecture/Week8"
tool_tags: "#tool/chrome_devtools"
atom_idx: 27
status: in-progress
difficulty: easy
date: 2025-10-15
timecode: ≈2:47:00+
source: https://cs50.harvard.edu/x/2025/weeks/8/
review_next: ""
---

## One Liner
Use **JavaScript** to listen for a **click** and change styles on the **DOM** (e.g., page **background-color**).

## Screenshot cue
![[Screenshot 2025-10-15 at 23.23.51.png]]

## What the example does
- Three `<button>` elements with ids `red`, `green`, `blue`.
- Script finds the **body** and each button via **`document.querySelector`**.
- Adds a **click** **event listener** to each button.
- Inside the handler, sets an **inline style**: `body.style.backgroundColor = 'red'` and so on.

### Code close to the screenshot
```html
<body>
  <button id="red">R</button>
  <button id="green">G</button>
  <button id="blue">B</button>

  <script>
    let body = document.querySelector('body');

    document.querySelector('#red').addEventListener('click', function () {
      body.style.backgroundColor = 'red';
    });

    document.querySelector('#green').addEventListener('click', function () {
      body.style.backgroundColor = 'green';
    });

    document.querySelector('#blue').addEventListener('click', function () {
      body.style.backgroundColor = 'blue';
    });
  </script>
</body>
```

## A cleaner DRY version
Avoid repeating code. Use **data-attributes** and a single handler. Prefer **`textContent`** for text (not needed here) and try to keep styling in **CSS** when possible.

```html
<body>
  <button data-bg="red">R</button>
  <button data-bg="green">G</button>
  <button data-bg="blue">B</button>

  <script>
    // Run after DOM is parsed (or put script at the end as shown)
    const body = document.body;
    document.querySelectorAll('button[data-bg]').forEach(btn => {
      btn.addEventListener('click', () => {
        body.style.backgroundColor = btn.dataset.bg; // set inline style
      });
    });
  </script>
</body>
```

## Even better: use CSS classes
Inline styles work, but **classes** keep styling in CSS and make future changes easier.

```html
<style>
  .bg-red   { background: red; }
  .bg-green { background: green; }
  .bg-blue  { background: blue; }
</style>

<body>
  <button data-class="bg-red">R</button>
  <button data-class="bg-green">G</button>
  <button data-class="bg-blue">B</button>

  <script>
    const body = document.body;
    function apply(cls) {
      body.classList.remove('bg-red', 'bg-green', 'bg-blue'); // reset
      body.classList.add(cls);
    }
    document.querySelectorAll('button[data-class]').forEach(btn => {
      btn.addEventListener('click', () => apply(btn.dataset.class));
    });
  </script>
</body>
```

## Notes and gotchas
- Make sure the elements exist before you query them. Put `<script>` at the end of `<body>` **or** add `defer` in `<head>` **or** wait for **`DOMContentLoaded`**.
- **`element.style.*`** writes **inline style**. It overrides many CSS rules but can be hard to maintain. Prefer **`classList.add/remove/toggle`**.
- Use **`querySelector`** with `#id`, `.class`, or element names. If it returns **`null`**, your selector didn’t match.
- Events: **`click`** for button presses; **`keyup`**/**`input`** for typing.
- Accessibility: give meaningful button text (`Red`, `Green`, `Blue`) and consider contrast when changing backgrounds.

## Terms
[[DOM]], [[querySelector]], [[addEventListener]], [[click event]], [[inline style]], [[classList]], [[data attribute]], [[DOMContentLoaded]]

## Related Concepts
- [[DOM Document Object Model]] – the tree you select and update.
- [[CSS Basics selectors box model and cascade]] – where styles should live.
- [[JavaScript in HTML and syntax quick compare]] – where to put scripts and why **defer** helps.
- [[Live DOM updates with DOMContentLoaded and keyup]] – input driven updates.
- [[Debugging JavaScript in Browser Console]] – fix null selectors and timing problems.
- [[HTML Hyperlinks a tag]] – another event target; similar listeners apply.

## See Also
- https://developer.mozilla.org/en-US/docs/Web/API/Element/classList
- https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelector
- https://developer.mozilla.org/en-US/docs/Web/API/EventTarget/addEventListener
