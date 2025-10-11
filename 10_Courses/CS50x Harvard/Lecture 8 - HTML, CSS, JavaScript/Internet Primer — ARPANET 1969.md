---
title: "Internet Primer — ARPANET (1969)"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 01
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

---

![[Screenshot 2025-10-11 at 14.28.51.png]]

---

## Summary
The **ARPANET** was the first large-scale packet-switched network (1969). It connected UCLA, SRI, UCSB, and the University of Utah, showing that computers could talk by sending **packets** via shared lines instead of one dedicated wire per pair.

## Very simple
> Explain ARPANET in simple terms that a 5-year-old would understand:
>     1. Imagine mailing Lego pieces (**packets**) one by one instead of a whole castle at once.
>     2. Each piece has an address so the post office (**routers**) knows where to send it.
>     3. If one road breaks, pieces take another road — the castle still arrives.

## Key Points
- Early growth: east–west links (MIT/BBN/Harvard ⇄ UCLA/SRI/UCSB/Utah) proved coast‑to‑coast routing.
- Birth of the Internet: a small research network funded by ARPA connecting **UCLA**, **SRI**, **UCSB**, **Utah**.
- Used **packet switching** (split messages into small chunks) for **fault tolerance** and better **bandwidth** use.
- Early hardware: **IMPs** (Interface Message Processors) acted like early **routers**.
- Set the stage for **protocols** like **TCP/IP** and later **HTTP**, enabling the modern web.
- Idea shift: 
  #### from **circuit switching** (phone lines) to **packet switching** (shared network).

## Details

### Expansion map (1970–1971)

![[Screenshot 2025-10-11 at 14.39.20.png]]

- New east‑coast nodes joined: **MIT**, **BBN**, **Harvard**. West‑coast cluster added **RAND** and **SDC**.
- Long‑haul leased lines linked the coasts; multi‑hop IMP routing demonstrated **scalability** and resilience.
- **BBN** engineered the early **IMPs**; the host protocol was **NCP** until **TCP/IP** became the internet standard in 1983.

ARPANET proved the **client–server** idea at scale: hosts sent small **packets** with destination **IP-like addressing** between nodes. If a link failed, routing changed dynamically — **resilience** by design. This map (Dec 1969) shows the first four nodes and links. The project’s success led to standardized **protocols** so independent networks could interconnect — the **“internet”** (network of networks).

## Examples
- Analogy: sending a long message split into postcards; each takes possibly different routes but arrives and is reassembled.
- Today: every time a browser requests a page, your device sends **HTTP** requests over **TCP/IP** — the same core idea ARPANET validated.

```text
Timeline (micro)
1969 — 4-node ARPANET goes live (UCLA, SRI, UCSB, Utah)
1970s — more nodes; protocol experiments
1983 — TCP/IP becomes the standard “language” of the internet
```

## **Why It Matters**
Understanding ARPANET explains **why** the web is robust: **packets**, **routing**, and **protocols** let billions of devices communicate even when parts break. This underpins everything we’ll do with **HTML**, **CSS**, and **JavaScript** on top of the network stack.

## Questions
- ❓How did packet switching outperform circuit switching under congestion?
- ❓What problems did TCP/IP fix that NCP didn’t?

## Related Concepts
- [[Client–Server Model]] – groundwork for browsers/servers later in Week 8.
- [[DNS]] – human-friendly names built on top of numeric addressing.
- [[Packet Switching]] – the core idea validated by ARPANET.
- [[OSI vs TCP-IP]] – mental model for where **HTTP**, **TCP**, **IP** live.
- [[Routing and Routers]] – how packets move across networks.
- [[Latency vs Bandwidth]] – speed limits that shape web performance.
- [[HTTP Lifecycle]] – from request to response over TCP.
- [[Web History Milestones]] – context from ARPANET to the modern web.

## See also
- []                                                                       
- [ARPANET — Wikipedia](https://en.wikipedia.org/wiki/ARPANET)
- [Computer History Museum — ARPANET](https://computerhistory.org/blog/august-30-1969-the-arpanet-is-born/)
- [RFC 675 (specifying IP/TCP concepts)](https://www.rfc-editor.org/rfc/rfc675)

## Terms
[[ARPANET]], [[IMP]], [[Packet]], [[Router]], [[Topology]], [[Fault tolerance]], [[Host]], [[Protocol]], [[BBN]], [[NCP]], [[MIT]], [[Harvard]], [[RAND]], [[SDC]]
