---
title: "Internet Primer — TCP Header (what makes a reliable stream)"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 07
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

---

![[Screenshot 2025-10-11 at 15.16.40.png]]

---

## Summary
The **TCP header** is the label that sits in front of each TCP segment.  
It keeps your bytes in order, confirms delivery, and controls the speed of the connection.

## Very simple
> Think of sending numbered boxes.  
> - **Sequence number** is the box number you send.  
> - **ACK number** is the next box you expect to receive.  
> - Little **flags** are stickers like SYN or FIN to start or finish the talk.

## Key Points
- **Source port / Destination port**: which two apps are talking.  
- **Sequence number**: position of the first byte in this segment.  
- **Acknowledgment number**: the next byte you want from the other side.  
- **Data offset**: size of this header.  
- **Flags**: `URG ACK PSH RST SYN FIN`. Common ones:  
  - **SYN** start, **ACK** acknowledge, **FIN** finish, **RST** reset.  
- **Window size**: how many bytes the receiver can take now (flow control).  
- **Checksum**: quick error check.  
- **Urgent pointer**: rarely used.  
- **Options**: extra features such as **MSS**, **Window Scale**, **SACK**, **Timestamps**.

## Details (in plain words)
- **Ordering**: TCP is a **byte stream**, not messages. Sequence numbers and ACKs keep order.  
- **Reliability**: lost data is resent when ACKs do not arrive in time.  
- **Speed control**: the receiver advertises a **window**; congestion control adjusts the send rate.  
- **Handshake**: `SYN` → `SYN-ACK` → `ACK`. Closing uses `FIN` or emergency `RST`.

## Examples
```text
Handshake flags
Client:  SYN
Server:  SYN, ACK
Client:  ACK
```
```text
Window idea
Receiver says: window = 65535 → sender may send up to that many bytes un‑ACKed.
Window Scale option extends this beyond 65535 for fast networks.
```
```bash
# Show local listeners and connections (Linux/macOS)
lsof -i | head
```

## **Why It Matters**
When pages stall or downloads pause, it is often about **loss**, **window sizes**, or **congestion control**. Reading the TCP header helps you reason about performance problems in real web apps.

## Questions
- ❓What is the difference between **flow control** (window) and **congestion control**?  
- ❓When do modern stacks use **SACK** and **timestamps**?

## Related Concepts
- [[Internet Primer — TCP IP]] – общая структура и логика TCP/IP.
- [[Internet Primer — Ports how apps share one IP]] – порты определяют, какие приложения используют соединение.
- [[Internet Primer — IPv4 Header what’s inside a packet]] – IP-заголовок находится под TCP и несёт адреса и TTL.
- [[TLS and HTTPS]] – шифрование поверх TCP.
- [[UDP vs TCP]] – различия в надёжности и скорости передачи.
- [[Latency vs Bandwidth]] – how windows and ACKs affect speed.  
- [[Packet Capture (tcpdump, Wireshark)]] – see these fields live.  
- [[Congestion Control]] – slow start, AIMD, and friends.

## See also
- []                                                                        
- [RFC 793 — Transmission Control Protocol](https://www.rfc-editor.org/rfc/rfc793)
- [Modern TCP features (window scaling, SACK)](https://en.wikipedia.org/wiki/Transmission_Control_Protocol#TCP_timestamps_and_selective_acknowledgments)

## Terms
[[TCP header]], [[Sequence number]], [[Acknowledgment number]], [[Flags]], [[SYN]], [[ACK]], [[FIN]], [[RST]], [[Window size]], [[Checksum]], [[MSS]], [[SACK]], [[Window scaling]], [[Timestamps]], [[Urgent pointer]], [[Data offset]]
