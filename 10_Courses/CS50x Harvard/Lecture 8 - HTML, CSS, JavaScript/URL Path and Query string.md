---
title: "URL Path and Query string"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 17
status: "in-progress"
difficulty: "easy"
date: "2025-10-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-19"
---

![[Screenshot 2025-10-12 at 16.49.56.png]]

## Summary
A **URL** has a **path** (what resource) and a **query string** (extra key=value data).  
Query starts with `?`, pairs are joined with `&`, and each pair is `key=value`.

## Very simple
> `https://example.com/path?key=value&lang=en`  
> Path: `/path`  
> Query: `key=value` and `lang=en`

## Key Points
- **Path** identifies the page/route on the server.  
- **Query string** sends small **key-value** data with the request.  
- Characters like spaces must be **percent-encoded** (`%20`).  
- Keys can repeat (`tag=cats&tag=dogs`) — the server decides how to handle arrays.  
- Order usually doesn’t matter; servers read pairs into a map/dictionary.  
- Don’t put secrets in the query (shows up in logs, history). Use **HTTPS** and prefer **POST** for sensitive data.

## Examples
```text
GET /search?q=cs50&page=2 HTTP/1.1
```
```js
// Read query parameters in the browser
const url = new URL(location.href);
url.searchParams.get("q");   // "cs50"
url.searchParams.has("page"); // true

// Build/modify a query
const u = new URL("https://example.com/path");
u.searchParams.set("key", "value");
u.toString(); // "https://example.com/path?key=value"
```

## Why It Matters
Understanding **path** and **query** helps you design clean links, debug requests, and reason about caching and routing.

## Related Concepts
- [[URLs]] – full breakdown of schemes, hosts, ports, paths, queries, fragments.  
- [[HTML Hyperlinks a tag]] – how links carry paths and queries.  
- [[HTTP and HTTPS]] – requests that include the path and query.  
- [[HTTP request logs and headers]] – where queries appear on the server.  
- [[HTTP Status Codes]] – outcomes of those requests.  
- [[DNS Domain Name System]] – resolves the host part of the URL.  
- [[TCP IP]] – the transport under HTTP.

## See also
- [MDN — URLSearchParams](https://developer.mozilla.org/en-US/docs/Web/API/URLSearchParams)
- [MDN — URL basics](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Web_mechanics/What_is_a_URL)
- [RFC 3986 — URI Generic Syntax](https://www.rfc-editor.org/rfc/rfc3986)

## Terms
[[URL]], [[Path]], [[Query string]], [[URL parameter]], [[Percent encoding]], [[URLSearchParams]], [[Fragment]], [[GET]], [[POST]]
