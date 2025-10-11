---
title: "Internet Primer — IPv4 Header (what’s inside a packet)"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 05
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

---

![[Screenshot 2025-10-11 at 14.51.48.png]]

---

## Summary
This is an **IPv4 header**. It’s the small label in front of every **IP packet**.  
Routers read this label to deliver the packet. The fields are tiny helpers: addresses, size, lifetime, and which upper **protocol** (like **TCP** or **UDP**) the data belongs to.

## Very simple
> Think of a postcard:
> - From and To = **Source** and **Destination address**.  
> - Max hops before it is thrown away = **TTL**.  
> - Which mailbox to give it to next = **Protocol** (TCP? UDP?).  
> - Total length = how big the postcard is.

## Key Points
- **Version & IHL**: says “IPv4” and how long the header is.  
- **Total Length**: header + data size (max 65,535 bytes).  
- **Identification, Flags, Fragment Offset**: used when a packet is split into pieces (**fragmentation**).  
- **TTL (Time To Live)**: starts high, minus 1 at each router; 0 → drop.  
- **Protocol**: 6 = TCP, 17 = UDP, 1 = ICMP, etc.  
- **Header Checksum**: quick error check for the header only.  
- **Source / Destination**: the two IPs.  
- **Options & Padding**: rarely used extras.

## Details (fields in plain words)
- **Version**: 4 means IPv4.  
- **IHL**: header length in 32‑bit words (usually 20 bytes).  
- **Type of Service (DSCP/ECN)**: hints for priority or low‑latency.  
- **Identification / Flags / Offset**: let the receiver put fragments back together.  
- **TTL**: prevents forever loops; enables **traceroute**.  
- **Protocol**: tells the OS which next layer should read the data.  
- **Header Checksum**: protects against bit flips in the header.  
- **Addresses**: who sent it and who should receive it.  
- **Options**: legacy stuff; most packets don’t use them.

## Examples
```text
Traceroute idea
We send packets with TTL = 1, 2, 3, …
Each router that hits TTL=0 replies with ICMP → we learn the path.
```
```text
Fragmentation
If a link’s MTU is too small, a big IPv4 packet can be split into pieces.
IPv6 handles this differently (no middle‑box fragmentation).
```

## **Why It Matters**
When pages load slowly, the reason can be in these fields: wrong **MTU**, low **TTL**, or a blocked **protocol**. Knowing the header helps debug real web issues.

## Questions
- ❓How does **PMTUD** avoid fragmentation?  
- ❓Why does **IPv6** remove in‑network fragmentation?

## Related Concepts
- [[Internet Primer — ARPANET 1969]] – контекст ARPANET: где всё началось.  
- [[Internet Primer — Routers]] – маршрутизаторы читают и пересылают IP-заголовки.  
- [[Internet Primer — TCP IP]] – протокол TCP/IP работает поверх IP.  
- [[Internet Primer — IP Addressing IPv4 vs IPv6]] – адресное пространство IPv4 и IPv6.  
- [[Internet Primer — IPv4 Header what’s inside a packet]] – структура и поля IPv4-заголовка.  
- [[TTL Time To Live]] – предел количества переходов.  
- [[Fragmentation vs MTU]] – как размер пакета влияет на доставку.  
- [[ICMP]] – сообщения, используемые ping и traceroute.


## See also
- []                                                                        
- [IPv4 header — Wikipedia](https://en.wikipedia.org/wiki/IPv4#Header)
- [Traceroute explained (Cloudflare)](https://www.cloudflare.com/learning/network-layer/what-is-traceroute/)

## Terms
[[IPv4 header]], [[TTL]], [[Protocol field]], [[Checksum]], [[Fragmentation]], [[ICMP]], [[MTU]]
