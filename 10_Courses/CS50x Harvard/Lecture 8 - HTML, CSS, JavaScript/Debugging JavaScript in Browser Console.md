---
title: "Debugging JavaScript in Browser Console"
lang_tags: "#lang/javascript, #lang/html"
type_tags: "#type/concept"
course_tags: "#course/CS50x"
lecture_tags: "#lecture/Week8"
tool_tags: "#tool/chrome_devtools"
atom_idx: 25
status: "in-progress"
difficulty: "easy"
date: "2025-10-15"
timecode: "≈2:41:00+"
source: "CS50x 2025 Week 8"
review_next: ""
---

![[Screenshot 2025-10-15 at 16.13.54.png]]

## One Liner
Use the **browser console** to see errors, read the **stack trace**, and jump to the exact line in your code. Fix the cause (wrong selector, wrong timing, typo), not just the symptom.

## What we saw on screen
`Uncaught TypeError: Cannot read properties of null (reading 'addEventListener') at hello.html:7:43`  
- **Meaning:** `document.querySelector('form')` returned **null**. You tried to call `.addEventListener` on `null`.  
- **Common reasons:**  
  1) The selector is wrong (no element matches).  
  2) The element exists, but the **script ran too early** (DOM wasn’t parsed yet).  
- **Quick fixes:**  
  - Correct the selector (e.g., `'#myForm'` if the form has `id="myForm"`).  
  - Load JS **after** HTML: put `<script src="app.js" defer></script>` in `<head>` or place the `<script>` tag right **before** `</body>`.

## How to read console errors
- **Red line** = the error message.  
- **file:line:column** (e.g., `hello.html:7:43`) = where to click to open the source.  
- **Stack trace** (lines below) = path of function calls that led to the error.  
- If the error repeats, click the **triangle** to expand hidden frames.

## Fast workflow with DevTools (Chrome/Edge)
1. **Open console:** `Cmd/Ctrl+Shift+J` (or `Opt/Alt+Cmd+I` then Console tab).  
2. Reproduce the bug so the message appears.  
3. Click the **file:line:column** link to jump to **Sources**.  
4. Set a **breakpoint** on the suspicious line, then retry the action.  
5. Inspect **Variables**, **Watch**, and the **Call Stack**; step with **F10/F11**.  
6. Use the `debugger` statement in your code to pause exactly where you want.  
7. Toggle **“Preserve log”** so logs stay after reloads.  
8. Use **Pretty print** in Sources if the code looks minified.

## Handy console methods
- `console.log(x)`, `console.info(x)`, `console.warn(x)`, `console.error(x)` – different levels.  
- `console.table(arrayOrObject)` – quick visual of lists/objects.  
- `console.dir(element)` – inspect DOM node properties.  
- `console.time('t')` / `console.timeEnd('t')` – simple timing.  
- `clear()` – clear the console.  
- Filter by level or keyword to reduce noise.

## Common beginner errors and fixes
- **Cannot read properties of null/undefined** – wrong selector OR JS ran before DOM. Fix selector or use **defer**/**DOMContentLoaded**.  
- **x is not defined** – variable not in scope or script load order wrong. Export/import correctly or move script.  
- **Unexpected token** – syntax typo (missing braces/paren/semicolon or stray chars). Use the line number to find it.  
- **CORS / Mixed Content** – blocked network requests. Use HTTPS and correct CORS settings (server‑side).  
- **Network 404** – your `.js` file path is wrong. Check the **Network** tab for the request URL.

## Mini checklist when wiring events
- Element exists? `document.querySelector('#id') !== null`  
- Script runs after DOM? Use **defer** or add `DOMContentLoaded` listener.  
- Correct event name? (`'submit'`, `'click'`, `'input'`…)  
- Prevent default only when needed: `event.preventDefault()`  
- Log inputs to prove values: `console.log(name.value)`

## Example fixes for our error
**Wrong timing → use defer**
```html
<head>
  <script src="/js/app.js" defer></script>
</head>
```
**Wrong selector → add an id and match it**
```html
<form id="form">
  ...
</form>
<script>
  document.querySelector('#form').addEventListener('submit', (e) => {
    e.preventDefault()
  })
</script>
```

## Related Concepts
- [[JavaScript in HTML and syntax quick compare]] – where to put scripts and why **defer** matters.  
- [[DOM Document Object Model]] – elements, selectors, and the tree you debug.  
- [[URLs]] – broken paths lead to 404s you’ll spot in DevTools.  
- [[HTTP request logs and headers]] – see what your browser actually sent.  
- [[HTTP Status Codes]] – decode 404/500 errors you see in Network tab.  
- [[HTML Hyperlinks a tag]] – navigation actions that also appear in logs.  
- [[CSS Basics selectors box model and cascade]] – selectors you reuse in JS queries.  

## See Also
- https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Tools_and_setup/What_are_browser_developer_tools
- https://developer.mozilla.org/en-US/docs/Web/API/console
- https://developer.mozilla.org/en-US/docs/Learn/Tools_and_testing/Debugging/JavaScript

## Terms
[[Console]], [[DevTools]], [[Stack trace]], [[Breakpoint]], [[debugger statement]], [[console.log]], [[console.error]], [[console.table]], [[querySelector]], [[TypeError]], [[ReferenceError]], [[defer]], [[DOMContentLoaded]]
