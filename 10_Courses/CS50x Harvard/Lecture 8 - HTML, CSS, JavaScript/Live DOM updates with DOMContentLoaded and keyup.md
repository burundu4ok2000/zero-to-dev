---
title: Live DOM updates with DOMContentLoaded and keyup
lang_tags: "#lang/javascript, #lang/html"
type_tags: "#type/concept"
course_tags: "#course/CS50x"
lecture_tags: "#lecture/Week8"
tool_tags: "#tool/chrome_devtools"
atom_idx: 26
status: in-progress
difficulty: easy
date: 2025-10-15
timecode: ≈2:45:00+
source: https://cs50.harvard.edu/x/2025/weeks/8/
review_next: ""
---

![[Screenshot 2025-10-15 at 22.55.33.png]]

## One Liner
Wire an **event listener** after the **DOM** is ready and update the page on **keyup** to get instant UI feedback.

## What is happening
- The code waits for the document to finish parsing with **DOMContentLoaded**.  
- Then it finds elements using a **selector** via `document.querySelector(...)`.  
- It attaches a **keyup** listener to the `<input>`.  
- On every key press, it reads `input.value` and writes a greeting into a `<p>`.  
- The example uses **innerHTML** with a **template literal** \`hello, ${{input.value}}\` to build the text.

## Minimal pattern you can reuse
```html
<p id="name">hello, whoever you are</p>
<input id="who" type="text" placeholder="Name">

<script>
document.addEventListener('DOMContentLoaded', function () {  // run after DOM exists
  let input = document.querySelector('#who')                 // find input
  let label = document.querySelector('#name')                // find target text

  input.addEventListener('keyup', function () {              // react on typing
    if (input.value) {
      // Safer text-only write:
      label.textContent = `hello, ${input.value}`            // no HTML parsing
    } else {
      label.textContent = 'hello, whoever you are'
    }
  })
})
</script>
```

### Why **DOMContentLoaded** or **defer** matters
Your script fails if it runs **before** the elements exist. Two safe choices:
- Add a listener for **DOMContentLoaded** (like above).  
- Or load your script with **defer** in `<head>` so it runs after parsing:
```html
<script src="app.js" defer></script>
```

## innerHTML vs textContent
- **innerHTML** parses strings as HTML. Fast for templating, but risky if the value comes from users (XSS).  
- **textContent** writes plain text. Use it for user input unless you sanitize.

## Small gotchas to remember
- Make sure your **selector** matches a real element (use `#id` or `.class`).  
- Use the right event: **keyup** for each keystroke, **input** is also good when supporting paste/IME.  
- Keep work in the handler **small**; heavy code on every key press will lag the UI.

## Related Concepts
- [[DOM Document Object Model]] – the tree you read and update.  
- [[JavaScript in HTML and syntax quick compare]] – where scripts live and why **defer** helps.  
- [[Debugging JavaScript in Browser Console]] – fix `null` selectors and timing errors fast.  
- [[CSS Basics selectors box model and cascade]] – selectors you also use from JS.  
- [[HTML Hyperlinks a tag]] – navigation is another user event to listen for.  
- [[URLs]] – how inputs often turn into query strings later.  

## See Also
- https://developer.mozilla.org/en-US/docs/Web/API/Document/DOMContentLoaded_event
- https://developer.mozilla.org/en-US/docs/Web/API/Element/keyup_event
- https://developer.mozilla.org/en-US/docs/Web/API/Node/textContent

## Terms
[[DOMContentLoaded]], [[querySelector]], [[addEventListener]], [[keyup]], [[innerHTML]], [[textContent]], [[Template literal]], [[Event object]], [[Selector]]
