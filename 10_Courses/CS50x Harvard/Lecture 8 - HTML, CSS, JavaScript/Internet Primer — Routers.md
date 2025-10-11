---
title: "Internet Primer — Routers"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 02
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

---

![[Screenshot 2025-10-11 at 14.39.48.png]]

---

## Summary
**Routers** are specialized computers that move **packets** between networks. They read the **IP header**, consult a **routing table**, and forward each packet toward its next hop, choosing the best path available.

## Very simple
> Explain routers in simple terms that a 5-year-old would understand:
>     1. Each letter (packet) has an address on the envelope (IP).
>     2. A post office (router) looks at the address and decides which truck (link) to use next.
>     3. If a road is blocked, the post office picks a different road — the letter still gets closer to home.

## Key Points
- Work at **Layer 3** (network layer): they use **IP addresses** and **prefixes** (e.g., 192.168.0.0/24) to decide where to send packets.
- Keep a **routing table** built manually (**static routes**) or by **routing protocols** like **OSPF** and **BGP**.
- Use **TTL** (time‑to‑live) to prevent loops; when TTL hits zero, the router drops the packet and sends **ICMP** back.
- Perform **NAT** at the edge of home/office networks, translating many private addresses to one public address.
- Distinct from **switches** (Layer 2 MAC forwarding) and **modems** (signal conversion).
- Core metrics that shape the web: **latency**, **bandwidth**, **loss**, and **jitter** — routers juggle queues and policies to balance them.
- Tools that reveal paths: **traceroute**, **ping** show hops and delays.

## Details
Routers process each packet independently (**packet switching**). The **IP header** contains source/destination addresses and the **TTL** counter. A router performs a **longest‑prefix match** against its routing table to choose an outgoing interface. Routes can be learned:  
- **Inside an autonomous system** (one organization) with **OSPF/IS‑IS** (shortest‑path algorithms like Dijkstra).  
- **Between autonomous systems** with **BGP**, which is policy‑driven (business relationships, not just shortest paths).  
Edge routers often apply **NAT** and **firewall** rules. Congestion can cause **bufferbloat**; smart queueing (**AQM**, **RED**, **FQ‑CoDel**) reduces latency spikes. For the web, all your **HTTP** over **TCP/IP** rides through dozens of routers, one hop at a time.

## Examples
```text
Mental model
Browser → default gateway (home router) → ISP router(s) → IXP/core → destination data center → server
Each arrow is a "hop"; each hop = one router forwarding your packet.
```

```text
Traceroute (conceptual)
1  192.168.0.1   5 ms  (home router)
2  10.12.34.1    9 ms  (ISP edge)
3  203.0.113.5  15 ms  (ISP core)
…
N  93.184.216.34 45 ms (example.org)
```

## **Why It Matters**
Every click in a browser becomes hundreds of packets navigating via routers. Understanding **routing**, **NAT**, and **latency** explains page load times, **CDNs**, and why some connections feel slow even with fast internet.

## Questions
- ❓What’s the practical difference between **BGP** (policy‑based) and **OSPF** (shortest‑path) in a real web request?
- ❓How do **CDNs** place servers to reduce the number of **hops**?

## Related Concepts
- [[Packet Switching]] – routers forward packets independently; contrast with circuit switching.
- [[Routing and Routers]] – umbrella note for algorithms and device roles.
- [[IP Addressing and Subnets]] – prefixes and longest‑prefix match choose next hop.
- [[DNS]] – how names become IPs before routing begins.
- [[Latency vs Bandwidth]] – performance axes observed across hops.
- [[Traceroute and Ping]] – tools to observe routers along a path.
- [[NAT and Private Networks]] – why many devices can share one public IP.
- [[BGP vs OSPF]] – inter‑domain vs intra‑domain routing models.

## See also
- []                                                                        
- [Router — Wikipedia](https://en.wikipedia.org/wiki/Router_(computing))
- [Cloudflare Learning: What is routing?](https://www.cloudflare.com/learning/network-layer/what-is-routing/)
- [RFC 791 — Internet Protocol](https://www.rfc-editor.org/rfc/rfc791)

## Terms
[[Router]], [[Packet]], [[IP address]], [[Routing table]], [[Prefix/Subnet]], [[TTL]], [[ICMP]], [[NAT]], [[BGP]], [[OSPF]], [[Traceroute]]
