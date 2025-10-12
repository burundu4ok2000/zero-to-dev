---
title: "HTML Hyperlinks a tag"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 15
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---
![[IMG_5848.png]]


## Summary
Hyperlinks in **HTML** use the **`<a>`** tag with an **`href`**.  
Links can point to pages, files, places on the same page, emails, or phones.

## Very simple
> A link is a **door**. `href` is the **address** of the room it opens.

## Key Points
- Basic form: `<a href="URL">text</a>`
- **Absolute URL** goes to other sites: `https://example.com/about`  
- **Relative URL** stays in your site: `about.html`, `./img/a.png`, `../index.html`
- Link to a spot on the page: add **id** and use a **fragment**: `<a href="#contact">Contact</a>`
- Open in new tab: `target="_blank"` and add `rel="noopener noreferrer"` for safety
- Good link text: describe the destination (“View schedule”), not “click here”
- You can wrap images: `<a href="..."><img src="..."></a>`
- Special schemes: `mailto:help@site.com`, `tel:+123456789`

## Details
- Browsers resolve **relative URLs** using the current page’s **base URL**.  
- `download` on `<a>` suggests saving instead of navigating.  
- Use **navigation lists** and a clear structure so links are easy to spot and tab to.  
- Accessibility: ensure color contrast and an underline or other visible cue.

## Examples
```html
<!-- Absolute vs relative -->
<p><a href="https://www.harvard.edu">Harvard</a></p>
<p><a href="image.html">Go to image page</a></p>

<!-- In‑page link -->
<h2 id="contact">Contact</h2>
<p>Jump <a href="#contact">to Contact</a></p>

<!-- New tab safely -->
<a href="https://developer.mozilla.org" target="_blank" rel="noopener noreferrer">MDN Docs</a>

<!-- Mail and phone -->
<a href="mailto:hello@example.com">Email us</a>
<a href="tel:+15551234567">Call us</a>
```

## Why It Matters
Links connect your site together and to the web. Clean, descriptive links improve **UX**, **SEO**, and accessibility.

## Questions
- ❓When should you open a link in a new tab vs the same tab?  
- ❓How do relative links change when you move a page into a subfolder?

## Related Concepts
- [[URLs]] – how paths, queries, and fragments are formed.
- [[HTTP and HTTPS]] – what requests happen when you click a link.
- [[DNS Domain Name System]] – resolves the host in absolute links.
- [[DOM Document Object Model]] – links are nodes in the document tree.
- [[HTML Images img tag]] – wrap images with links.
- [[Navigation and Sitemaps]] – organizing internal links.
- [[Accessibility Basics]] – making links usable for everyone.
- [[Caching and Headers]] – linked assets and pages can be cached.

## See also
- [MDN — `<a>` element](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/a)
- [MDN — URL basics](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Web_mechanics/What_is_a_URL)
- [WebAIM — Links and Hypertext](https://webaim.org/techniques/hypertext/)

## Terms
[[Anchor tag a]], [[href]], [[Absolute URL]], [[Relative URL]], [[Fragment]], [[target attribute]], [[rel attribute]], [[noopener]], [[noreferrer]], [[mailto]], [[tel]], [[Download attribute]]
