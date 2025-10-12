---
title: "Internet Primer — URLs"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 11
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

![[Screenshot 2025-10-11 at 15.57.11.png]]

## Summary
A **URL** is a web address. It tells the browser **how** to connect, **where** to go, and **what** to ask for.

## Very simple
> Street address for the web:  
> `https://www.example.com/shop?item=book#reviews`

## Key Points
- Parts of a URL:
  - **Scheme**: `http`, `https`, `mailto`, `ftp` — the **protocol** to use.
  - **Host**: domain or IP, like `www.example.com`.
  - **Port**: optional; default is 80 for HTTP, 443 for HTTPS.
  - **Path**: the file or route on the server, like `/shop`.
  - **Query**: extra data after `?`, as `key=value&key2=value2`.
  - **Fragment**: page anchor after `#`, handled by the browser.
- **Origin** = scheme + host + port. The browser’s **CORS** rules use the origin.
- URLs can be **absolute** (`https://site.com/a`) or **relative** (`/a` or `./a`), which use the page’s **base URL**.
- Some characters must be **percent‑encoded** (spaces → `%20`). Keep URLs simple and lowercase.
- Trailing slash matters: `/docs` vs `/docs/` can be different routes.

## Details
- A clean, stable URL helps **SEO** and caching. Avoid leaking secrets in the **query**; use **HTTPS** to protect data.  
- Query parameters are unordered by meaning; servers read them as **key‑value** pairs.  
- Browsers normalize parts (like removing `.` and `..` segments) based on the **URL Standard**.

## Examples
```text
Full form
scheme://user:pass@host:port/path?query#fragment
https://example.org:443/blog/post?id=42#comments
```
```text
Relative → Absolute
Base: https://site.com/app/
./profile   → https://site.com/app/profile
../img/a.png → https://site.com/img/a.png
```
```text
Query string
/search?q=cats&page=2&lang=en
```

## Why It Matters
You use URLs for every request. Understanding parts helps debug **404s**, broken links, CORS errors, and weird redirects.

## Questions
- ❓When should an app put data in the **path** vs the **query**?  
- ❓What can go wrong when mixing **http** and **https** links on the same page?

## Related Concepts
- [[HTTP and HTTPS]] – how requests use URLs.
- [[DNS Domain Name System]] – maps host names to IPs.
- [[TCP IP]] – transport below the request.
- [[Ports how apps share one IP]] – default ports and custom ports.
- [[CORS Cross Origin Resource Sharing]] – origin rules based on URL parts.
- [[Caching and Headers]] – cache keys often include the full URL.
- [[IPv4 Header what’s inside a packet]] – how the request travels.
- [[CDN Content Delivery Network]] – URL routing to the nearest edge.

## See also
- [URL — MDN Web Docs](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Web_mechanics/What_is_a_URL)
- [WHATWG URL Standard](https://url.spec.whatwg.org/)
- [RFC 3986 URI Generic Syntax](https://www.rfc-editor.org/rfc/rfc3986)

## Terms
[[URL]], [[URI]], [[Scheme]], [[Host]], [[Port]], [[Path]], [[Query string]], [[Fragment]], [[Origin]], [[Relative URL]], [[Absolute URL]], [[Percent encoding]], [[Canonical URL]], [[Base URL]]
