---
title: "Internet Primer — HTTP and HTTPS"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 10
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

![[Screenshot 2025-10-11 at 15.45.33.png]]
![[Screenshot 2025-10-11 at 15.45.39.png]]

## Summary
**HTTP** is the rule set for browser ↔ server talk: **request → response**.  
**HTTPS** is HTTP with **TLS** encryption. Same flow, but private and safe.

## Very simple
> Cafe model: you place an **order** (request), kitchen sends a **dish** (response).  
> With HTTPS, the tray is in a **locked box** so no one peeks or swaps your food.

## Key Points
- **Methods**: GET (read), POST (send data), PUT/PATCH (update), DELETE (remove), HEAD (headers only).  
- **URL** = scheme + host + path + query (e.g., `https://site.com/products?id=7`).  
- **Headers** carry metadata (Host, User-Agent, Accept, Cookie).  
- **Body** optional (forms, JSON).  
- **Status codes**: 2xx success, 3xx redirect, 4xx client error, 5xx server error.  
- **Ports**: HTTP 80, HTTPS 443.  
- **Stateless**: sites use **cookies/sessions/tokens** to remember you.  
- **HTTPS adds**: encryption, integrity, and identity (certificates from CAs).

## Details
- Request line: `GET /index.html HTTP/1.1`  
- Response line: `HTTP/1.1 200 OK`  
- Modern web: **HTTP/2** multiplexes streams; **HTTP/3** runs over **QUIC/UDP** for lower latency.  
- Browsers block **mixed content** (HTTPS page loading HTTP assets).  
- Cross-site rules: **CORS** limits JS access to other origins.

## Examples
```http
GET / HTTP/1.1
Host: example.org
Accept: text/html
Connection: close
```
```http
HTTP/1.1 200 OK
Content-Type: text/html; charset=utf-8
Content-Length: 125

<html>...</html>
```
```bash
# Quick checks
curl -I https://example.org              # headers only
curl -s https://example.org | head -n 5  # first lines of body
```
```js
// Simple fetch in the browser
fetch("https://api.example.org/items", {
  method: "POST",
  headers: { "Content-Type": "application/json" },
  body: JSON.stringify({ name: "book", price: 12 })
}).then(r => r.json()).then(console.log);
```

## Why It Matters
Every web app uses HTTP/HTTPS. Knowing methods, codes, and headers makes debugging easy and keeps user data safe.

## Questions
- ❓When use POST vs PUT for APIs?  
- ❓Why choose 301 (permanent) vs 302/307 (temporary) redirect?

## Related Concepts
- [[Internet Primer — TCP IP]] – transport under HTTP/HTTPS.  
- [[Internet Primer — Ports how apps share one IP]] – ports 80 and 443.  
- [[Internet Primer — DNS Domain Name System]] – resolve names to IPs.  
- [[Internet Primer — IPv4 Header what’s inside a packet]] – how requests travel.  
- [[TLS and HTTPS]] – deeper dive into certificates and TLS.  
- [[CORS Cross Origin Resource Sharing]] – browser security for cross‑site calls.  
- [[CDN Content Delivery Network]] – faster delivery of HTTP responses.  
- [[Caching and Headers]] – Cache-Control, ETag, Last-Modified.

## See also
- [HTTP — MDN Web Docs](https://developer.mozilla.org/en-US/docs/Web/HTTP)
- [HTTPS — MDN Web Docs](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview#https)
- [curl tutorial](https://curl.se/docs/manual.html)

## Terms
[[HTTP]], [[HTTPS]], [[TLS]], [[Certificate]], [[Certificate Authority]], [[Status code]], [[Header]], [[Method]], [[Cookie]], [[Session]], [[Token]], [[SNI]], [[HSTS]], [[CORS]], [[Origin]], [[Cache-Control]], [[ETag]]
