---
title: "Internet Primer — Ports (how apps share one IP)"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 06
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

---

![[Screenshot 2025-10-11 at 15.09.48.png]]

---

## Summary
A **port** is a number that marks a conversation on a device.  
Think: **IP = building address**, **port = apartment number**. Many apps can talk at once on one IP because each uses a different port.

## Very simple
> When your browser opens a website, it dials the server’s **number** (port).  
> Example: HTTPS usually uses **443**. SSH uses **22**.

## Key Points
- Range: **0–65535**.  
  - **0–1023** = well‑known (80 HTTP, 443 HTTPS, 22 SSH, 25 SMTP, 53 DNS).  
  - **1024–49151** = registered (apps).  
  - **49152–65535** = dynamic/ephemeral (clients pick these temporarily).
- A full connection is **IP + port** on both ends. (Your laptop uses a high **ephemeral port** → server’s port **443**.)
- Servers **listen** on a port; clients **connect** from a short‑lived port. Multiple tabs can still share one server port.
- **Firewalls/NAT** can block or translate ports. “Port forwarding” lets the internet reach a device behind NAT.
- Tools: `curl` (HTTP), `nc` (manual TCP), `ss -tulpn` or `lsof -i` (see what’s listening).

## Details
- Ports live in the **Transport layer** (**TCP** and **UDP**).  
- Web today mostly uses **HTTPS :443**. Some APIs still use **HTTP :80** for testing.  
- Games/voice/video often use **UDP** ports for lower delay.  
- One machine can run many services at once because each has its own port number.

## Examples
```bash
# Talk to a server port manually
nc example.org 80
GET / HTTP/1.1
Host: example.org
Connection: close

```
```text
Common ports
80  HTTP   443 HTTPS   22 SSH   25 SMTP   53 DNS   8080 Alt-HTTP
```

## **Why It Matters**
If a page won’t load, a **blocked port** or **wrong service port** may be the reason.  
Knowing ports helps read error messages and open the right services in the cloud.

## Questions
- ❓Why do browsers restrict some non‑standard ports?  
- ❓When should an app choose **UDP** vs **TCP** for its port?

## Related Concepts
- [[TCP/IP Stack]] – where **ports** live (Transport layer).  
- [[Sockets]] – the idea of IP + port as one endpoint.  
- [[NAT and Port Forwarding]] – how home routers map ports.  
- [[Firewall Rules]] – allow/deny by port numbers.  
- [[DNS]] – resolve a name before connecting to a port.  
- [[HTTPS and TLS]] – encryption on top of TCP :443.  
- [[HTTP Lifecycle]] – request/response over a port.  
- [[UDP vs TCP]] – choosing ports per protocol.

## See also
- []                                                                        
- [List of TCP and UDP port numbers (Wikipedia)](https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers)
- [Cloudflare Learning — What is a port?](https://www.cloudflare.com/learning/network-layer/what-is-a-computer-port/)

## Terms
[[Port]], [[Ephemeral port]], [[Well‑known port]], [[Registered port]], [[Socket]], [[Service]], [[Firewall]], [[NAT]]
