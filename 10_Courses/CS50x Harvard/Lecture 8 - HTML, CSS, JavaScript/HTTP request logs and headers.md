---
title: "Internet Primer — HTTP request logs and headers"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 14
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---
![[IMG_5847.png]]


## Summary
The lines in the terminal are **server access logs**.  
Each line describes an **HTTP request** your browser sent: time, what it asked for, and some **headers** like the **User-Agent** string. This is **not a cookie**; cookies are separate headers.

## Very simple
> You visit a page → your browser says “GET /index.html, I am Chrome on macOS” → the server writes that sentence to a log file.

## Quick list of fields you can see
- **Timestamp** — when the server received the request.  
- **Method and path** — `GET /` or `GET /index.html`.  
- **Protocol** — implicitly HTTP/1.1 or HTTP/2, often logged.  
- **User-Agent** — long string that identifies the browser and OS (e.g., `Mozilla/5.0 ... Chrome/130.0.0.0`).  
- Often also logged: **status code** (200/404), **response size**, **referrer**, **client IP**.

## How the server gets this info
- Your browser adds **HTTP headers** automatically (e.g., **User-Agent**, **Accept**, **Cookie** if any).  
- The **IP address** comes from the network connection.  
- The web server (or framework) prints selected fields into its **access log** using a format string (Common or Combined Log Format).  
- No extra permission is needed — this is standard for HTTP. Cookies are different: they are sent only if the site set them earlier.

## Why we have these instruments
- **Debugging** — see which files were requested and by whom.  
- **Performance** — measure latency and sizes.  
- **Security** — spot weird traffic, brute force, or crawlers.  
- **Analytics** — count visits and track popular pages (respecting privacy laws).

## Example log line (annotated)
```text
[Wed Oct 23 14:27:22 GMT-0400] "GET /index.html" "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) Chrome/130.0.0.0 Safari/537.36"
^ time                                  ^ method+path           ^ user agent header
```

## Not cookies, but headers
- **Cookies** travel in `Cookie:` and `Set-Cookie:` headers and can store session IDs, preferences, etc.  
- **User-Agent** is a different header; it does **not** identify you personally, but it can help with **fingerprinting** when combined with other data.

## **Why It Matters**
Reading logs helps you connect browser behavior to server results. It’s the fastest way to understand **what request happened** and **how the server replied**.

## Related Concepts
- [[HTTP and HTTPS]] – requests and responses.  
- [[URLs]] – what the `GET /path` refers to.  
- [[HTTP Status Codes]] – codes you’ll see in logs.  
- [[TCP IP]] – transport below HTTP.  
- [[Ports how apps share one IP]] – servers listen on 80 or 443.  
- [[DNS Domain Name System]] – resolves the host before the request.  
- [[Caching and Headers]] – headers logged with responses.  
- [[Cookies and Sessions]] – how state is carried in HTTP.

## See also
- [Common Log Format — Wikipedia](https://en.wikipedia.org/wiki/Common_Log_Format)
- [User-Agent header — MDN](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/User-Agent)
- [Nginx log format guide](https://nginx.org/en/docs/http/ngx_http_log_module.html)

## Terms
[[Access log]], [[User Agent]], [[HTTP header]], [[Request line]], [[Status code]], [[Client IP]], [[Referrer]], [[Cookie]], [[Set-Cookie]], [[Fingerprinting]]
