---
title: "Internet Primer — IP Addressing (IPv4 vs IPv6)"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 04
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

---

![[Screenshot 2025-10-11 at 14.46.50.png]]

---

## Summary
**IP** is the addressing system of the Internet. **IPv4** uses 32‑bit addresses (like 203.0.113.42) and is almost exhausted, so the world is moving to **IPv6** with 128‑bit addresses (like 2001:db8::1), which provides a huge space and modern features.

## Very simple
> Explain IP addresses in simple terms that a 5‑year‑old would understand:
>     1. Every house on the Internet street needs a **number** so messages know where to go.
>     2. Old numbers (**IPv4**) are short and we almost ran out.
>     3. New numbers (**IPv6**) are very long, so there are enough for everything — phones, cars, fridges.

## Key Points
- **IPv4:** 32‑bit → about 4.3 billion unique addresses. Written as four **octets** in decimal (e.g., 192.168.0.10). Common ranges: **private** (10.0.0.0/8, 172.16.0.0/12, 192.168.0.0/16), **loopback** (127.0.0.0/8), **link‑local** (169.254.0.0/16).
- **IPv6:** 128‑bit → unimaginably large space. Hexadecimal groups, shortened with `::` (e.g., 2001:db8:ac10:fe01::1). Has **scopes** and well‑known prefixes (link‑local fe80::/10, unique local fc00::/7, loopback ::1).
- **CIDR prefixes** describe networks: 203.0.113.0/24 (IPv4) or 2001:db8::/32 (IPv6). Routers use **longest‑prefix match**.
- Because IPv4 is scarce, many networks use **NAT** to share one public address. IPv6 usually avoids NAT and gives each device its own global address.
- Address assignment: **DHCPv4** for IPv4; **DHCPv6** or **SLAAC** (self‑config) for IPv6.
- Transition reality: the Internet runs **dual‑stack** (IPv4 and IPv6 together) plus tunnels/translation (e.g., **NAT64/464XLAT**).
- **MTU** is larger on many IPv6 paths; IPv6 does not allow intermediate fragmentation (uses **PMTUD**).

## Details
**IPv4** addresses are split by **subnet masks/CIDR** to organize networks and control routing. Shortage led to **NAT**, which breaks end‑to‑end connectivity and complicates some apps (P2P, VoIP).  
**IPv6** restores end‑to‑end by offering abundant **global unicast** addresses, per‑prefix privacy options, and cleaner header design. It supports multiple addresses per interface (link‑local, global), better neighbor discovery (**NDP**) instead of ARP, and autoconfiguration (**SLAAC**).  
For web apps, the browser prefers IPv6 when available (**Happy Eyeballs** algorithm) so pages load fast even if one family of addresses is slow.

## Examples
```text
IPv4 dotted decimal
192.168.1.7/24  → network 192.168.1.0, host .7

IPv6 compressed
2001:db8:0:0:0:0:0:2  →  2001:db8::2

CIDR idea
10.0.0.0/8   = 16,777,216 addresses
2001:db8::/32 ≈ 79,228,162,514,264,337,593,543,950,336 addresses
```


## Picking which IP to use (simplified, client)
1) Resolve name via DNS → get A (IPv4) and/or AAAA (IPv6) records.
2) Try IPv6 and IPv4 in parallel (Happy Eyeballs); use whichever connects first.

## **Why It Matters**
Addresses decide **reachability** and **performance**. Understanding **IPv4 vs IPv6**, **CIDR**, and **NAT** explains why some services are unreachable from certain networks, why peer‑to‑peer can be hard, and how the modern web is moving back to true end‑to‑end connectivity.

## Questions
- ❓When should a small network enable **IPv6** in production, and how to monitor dual‑stack issues?
- ❓What problems disappear when moving from **NAT** to native **IPv6**? Which security assumptions must change?

## Related Concepts
- [[Routing and Routers]] – forwarding uses longest‑prefix match.
- [[DNS]] – names to addresses (A vs AAAA).
- [[TCP/IP Stack]] – where IP sits under **TCP/UDP**.
- [[MTU and Fragmentation]] – sizing for IPv4 vs IPv6 paths.
- [[Ports and Sockets]] – services per host after addressing.
- [[CDN]] – how anycast and IPv6 improve latency for web content.
- [[IPv6 Transition Mechanisms]] – dual‑stack, NAT64, 6to4, tunnels.
- [[Security Groups and Firewalls]] – filtering rules per IP family.

## See also
- []                                                                        
- [IPv4 — Wikipedia](https://en.wikipedia.org/wiki/IPv4)
- [IPv6 — Wikipedia](https://en.wikipedia.org/wiki/IPv6)
- [RFC 791 — Internet Protocol (v4)](https://www.rfc-editor.org/rfc/rfc791)
- [RFC 8200 — IPv6 Specification](https://www.rfc-editor.org/rfc/rfc8200)

## Terms
[[IPv4]], [[IPv6]], [[CIDR]], [[Subnet mask]], [[Prefix]], [[NAT]], [[DHCPv4]], [[DHCPv6]], [[SLAAC]], [[Link‑local address]], [[Global unicast]], [[Loopback]], [[NDP]], [[Happy Eyeballs]], [[AAAA record]]
