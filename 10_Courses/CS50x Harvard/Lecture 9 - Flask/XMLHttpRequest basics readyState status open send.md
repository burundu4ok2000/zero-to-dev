---
title: "XMLHttpRequest basics readyState status open send"
lang_tags: "#lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 18
status: "done"
difficulty: "easy"
date: "2025-10-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---
![[Screenshot 2025-10-23 at 16.07.22.png]]

![[Screenshot 2025-10-23 at 16.11.47.png]]

## Summary
wser talk to the server **without page reload**. Two key properties: **readyState** (0→4) and **status** (HTTP code). Two core methods: **open()** to configure the request, **send()** to actually send it. Use a **readystatechange** handler to know when the response is ready (**readyState == 4**) and then check **status == 200**.

## Minimal example
```html
<script>
  const xhr = new XMLHttpRequest();
  xhr.open("GET", "/time");            // set method + URL
  xhr.onreadystatechange = function () {
    if (xhr.readyState === 4) {        // DONE
      if (xhr.status === 200) {        // OK
        document.querySelector("#t").textContent = xhr.responseText;
      } else {
        console.error("HTTP error:", xhr.status);
      }
    }
  };
  xhr.send();                          // fire!
</script>
<div id="t">--:--</div>
```

## What those pieces mean
- **readyState**: `0` **UNSENT**, `1` **OPENED**, `2` **HEADERS_RECEIVED**, `3` **LOADING**, `4` **DONE**.  
- **status**: numeric **HTTP status code** (e.g., `200` OK, `404` Not Found). Before completion it can be `0`.  
- **open(method, url, async=true)**: initializes the request (do this before `send()`).  
- **send(body?)**: sends the request; returns immediately when **async**; may take an optional **body** for POST/PUT.  
- **readystatechange** event: fires whenever **readyState** changes (0→4).

## Tips
- Prefer **JSON** responses; parse with `JSON.parse(xhr.responseText)`.  
- For modern code, use **Fetch API** (cleaner promises) unless you must support old patterns.  
- Avoid injecting untrusted text with `innerHTML`; prefer `textContent`.

## Related Concepts
- [[AJAX — Asynchronous JavaScript and XML]] – background requests idea.
- [[JSON API responses]] – server sends JSON; client renders.
- [[AJAX search (shows)]] – instant search pattern.
- [[GET vs POST route methods]] – choosing the method.
- [[POST form data and DevTools payload]] – inspect network calls.
- [[MVC (Model View Controller)]] – controller returns data for the view.
- [[Jinja templates documentation]]
- [[render_template() in Flask]]

## See also
- [MDN: XMLHttpRequest — overview](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest)
- [MDN: readyState values](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/readyState)
- [MDN: status](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/status)
- [MDN: open()](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/open)
- [MDN: send()](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/send)
- [MDN: readystatechange event](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/readystatechange_event)

## Terms
[[XMLHttpRequest]], [[readyState]], [[status]], [[open()]], [[send()]], [[readystatechange]], [[HTTP status code]], [[AJAX]], [[Fetch API]]
