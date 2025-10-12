---
title: "Internet Primer — TCP/IP"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 03
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

---

![[Screenshot 2025-10-11 at 14.46.38.png]]

---

## Summary
**TCP/IP** is the Internet’s core “language.” **IP** moves packets from A→B with best‑effort delivery; **TCP** sits on top to make a reliable, ordered **byte stream** with ports and connections, the foundation for **HTTP/HTTPS**.

## Very simple
> Explain TCP/IP in simple terms that a 5-year-old would understand:
>     1. **IP** is like street rules so any car can drive to any house using addresses.
>     2. **TCP** is like a careful courier: counts boxes, asks “got it?” (**ACKs**), resends missing ones.
>     3. If roads are busy, the courier slows down so streets don’t jam (**congestion control**).

## Key Points
- **Layering (TCP/IP model):** Link → **Internet (IP)** → **Transport (TCP/UDP)** → **Application (HTTP, DNS, …)**. OSI is a 7‑layer teaching model; TCP/IP is what the Internet actually uses.
- **IP:** best‑effort, connectionless; routes packets via **routers** using **addresses** and **TTL**. Versions: **IPv4** (32‑bit) and **IPv6** (128‑bit).
- **TCP:** reliable, ordered, full‑duplex byte stream built on IP. Uses **ports** (e.g., 80, 443) to multiplex many app connections over one IP.
- **3‑way handshake:** `SYN` → `SYN-ACK` → `ACK` establishes a connection; **FIN/RST** closes it.
- Reliability: **sequence numbers**, **ACKs**, **retransmissions**, **sliding window**, **flow control**.
- Performance: **congestion control** (slow start, AIMD), **MSS/MTU** decide packet sizes; too big → fragmentation or PMTUD.
- Alternatives: **UDP** (no handshake; faster but unreliable). Many real‑time apps use UDP with app‑level reliability.
- Security wrapper: **TLS** over TCP → **HTTPS**; encryption/authentication on top of transport.

## Details
**IP** forwards independent **packets** hop by hop. Each packet carries source/destination IPs and a **TTL**. Routers perform **longest‑prefix match** to pick the next hop. **NAT** lets many devices share one public IPv4 address.  
**TCP** turns that flaky delivery into a clean **stream**: it numbers bytes, expects ACKs, and resends lost data. The receiver advertises a **window size** for flow control. Congestion control probes the network, backing off when loss/latency spikes. **Ports** identify the app on each host; a connection is uniquely identified by `{srcIP:srcPort → dstIP:dstPort}` — a **socket pair**.  
For the web, your browser opens a TCP connection to a server (often via **TLS**), sends an **HTTP** request, receives a response, then reuses or closes the connection (**keep‑alive**).

## Examples
```bash
# Raw HTTP over TCP using netcat
nc example.org 80
GET / HTTP/1.1
Host: example.org
Connection: close

```
```text
Port cheat sheet
80  = HTTP       443 = HTTPS
53  = DNS        25  = SMTP      22 = SSH
```

```text
3‑way handshake (simplified)
Client:  SYN  (seq = x)
Server:  SYN-ACK (seq = y, ack = x+1)
Client:  ACK  (ack = y+1)  → connection established
```

## **Why It Matters**
Everything we build in **HTML/CSS/JavaScript** rides on **TCP/IP**. Knowing how **packets**, **ports**, and **handshakes** work explains latency, timeouts, CDNs, and why “the Internet sometimes feels slow.”

## Questions
- ❓When would **UDP** be better than **TCP**, and how do apps add reliability on top of UDP?
- ❓How does **TLS** fit with TCP’s handshake (ALPN, session tickets, 1‑RTT/0‑RTT in modern TLS 1.3)?

## Related Concepts
- [[Routers and Routing]] – where IP forwarding happens.
- [[IP Addressing and Subnets]] – addresses, prefixes, NAT.
- [[UDP vs TCP]] – tradeoffs for reliability vs latency.
- [[HTTP Lifecycle]] – what browsers do over TCP.
- [[TLS and HTTPS]] – encryption/authentication on top of TCP.
- [[Latency vs Bandwidth]] – how congestion control interacts with performance.
- [[Ports and Sockets]] – how multiple connections share an IP.
- [[MTU and Fragmentation]] – packet sizing effects.

## See also
- []                                                                        
- [TCP/IP model — Wikipedia](https://en.wikipedia.org/wiki/Internet_protocol_suite)
- [RFC 791 — Internet Protocol](https://www.rfc-editor.org/rfc/rfc791)
- [RFC 793 — Transmission Control Protocol](https://www.rfc-editor.org/rfc/rfc793)

## Terms
[[TCP]], [[IP]], [[IPv4]], [[IPv6]], [[Packet]], [[Port]], [[Socket]], [[Three‑way handshake]], [[ACK]], [[Sequence number]], [[Window size]], [[Congestion control]], [[MTU]], [[MSS]], [[UDP]], [[TLS]], [[HTTPS]], [[NAT]]
