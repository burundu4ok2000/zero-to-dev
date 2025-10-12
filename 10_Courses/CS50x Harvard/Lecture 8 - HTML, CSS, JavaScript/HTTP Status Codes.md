---
title: "Internet Primer — HTTP Status Codes"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 12
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

![[Screenshot 2025-10-11 at 16.26.15.png]]

## Summary
**Status codes** tell you what happened with an **HTTP** request.  
They are small numbers in the response like **200**, **404**, **503**.

## Very simple
> Think traffic lights:  
> - 2xx = green (success)  
> - 3xx = detour (redirect)  
> - 4xx = your mistake (client)  
> - 5xx = their mistake (server)

## Key Points
- Code is 3 digits. The **first digit** is the class:  
  - **1xx**: info / in progress.  
  - **2xx**: success (200 OK, 201 Created).  
  - **3xx**: redirect (301 Moved Permanently, 302/307 Temporary).  
  - **4xx**: client errors (400 Bad Request, 401 Unauthorized, 403 Forbidden, **404 Not Found**).  
  - **5xx**: server errors (500 Internal Server Error, 503 Service Unavailable).  
- Redirect flavors: **301** permanent (browsers cache), **302/307** temporary.  
- **304 Not Modified** means “use your cache.”  
- Funny classic: **418 I’m a Teapot** (for fun only).  
- In APIs, errors often come with **JSON** explaining the problem.

## Details
- Browsers follow many 3xx codes automatically.  
- Use the right code: it affects SEO, caching, and client retries.  
- **Idempotent** methods (GET, PUT, DELETE) can be safely retried; **POST** usually not.  
- Prefer **4xx** when the **request** is wrong (e.g., bad JSON), **5xx** when the **server** failed.  
- For maintenance windows, return **503** with a `Retry-After` header.

## Examples
```text
Typical
200 OK
301 Moved Permanently
302 Found
304 Not Modified
400 Bad Request
401 Unauthorized
403 Forbidden
404 Not Found
500 Internal Server Error
503 Service Unavailable
```
```http
HTTP/1.1 404 Not Found
Content-Type: application/json

{"error":"no such item"}
```

## Why It Matters
Reading status codes quickly explains broken links, bad inputs, and server crashes. It’s the fastest way to debug web apps.

## Questions
- ❓When should an API return **422 Unprocessable Entity** vs **400 Bad Request**?  
- ❓How long should clients cache **301** redirects?

## Related Concepts
- [[HTTP and HTTPS]] – where status codes live.  
- [[URLs]] – redirects change a URL to another one.  
- [[Caching and Headers]] – 304 and cache validators.  
- [[TCP IP]] – transport under HTTP.  
- [[DNS Domain Name System]] – what happens before the request.  
- [[Ports how apps share one IP]] – default ports 80/443.  
- [[CDN Content Delivery Network]] – can serve cached 200/304 responses.  
- [[Error Handling in APIs]] – design friendly JSON errors.

## See also
- [MDN — HTTP response status codes](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)
- [RFC 9110 — HTTP Semantics](https://www.rfc-editor.org/rfc/rfc9110#name-status-codes)
- [REST API error handling guide](https://cloud.google.com/apis/design/errors)

## Terms
[[Status code]], [[2xx]], [[3xx]], [[4xx]], [[5xx]], [[Redirect]], [[Cache]], [[Retry-After]], [[Idempotent method]], [[JSON error]]
