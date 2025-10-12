---
title: "Internet Primer — DNS (Domain Name System)"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 08
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

---

![[Screenshot 2025-10-11 at 15.23.24.png]]

---

## Summary
**DNS** is the **Domain Name System** — it turns names like `google.com` into IP addresses that computers can understand.  
It’s like a phonebook for the Internet.

## Very simple
> Imagine you want to call “Google”. You know the name, not the number.  
> DNS is the helper who looks up the number (IP address) for you.

## Key Points
- Humans use **domain names** (easy to remember). Computers use **IP addresses**.  
- **DNS** translates names → IPs. Example: `www.harvard.edu` → `23.185.0.2`.  
- This process is called a **DNS lookup**.  
- DNS servers work in a chain:
  1. **Root servers** (".") know where to find top-level domains like `.com`, `.org`.  
  2. **TLD servers** know where each website’s domain is managed.  
  3. **Authoritative servers** return the actual IP address.  
- Your computer or browser **caches** results so you don’t have to ask every time.  
- Common DNS record types:
  - **A** → maps a name to an IPv4 address.  
  - **AAAA** → maps to an IPv6 address.  
  - **CNAME** → alias (points to another name).  
  - **MX** → mail server.  
  - **TXT** → metadata like SPF, verification, etc.

## Details
When you visit a website:
1. Browser checks local cache.  
2. If not found → asks your **DNS resolver** (usually from your ISP or public like Google `8.8.8.8`).  
3. The resolver walks up the chain (root → TLD → authoritative).  
4. The final IP is sent back to your browser.  
5. Browser connects via **TCP/IP** to that address.  

Modern networks use **DNS over HTTPS (DoH)** or **DNS over TLS (DoT)** for privacy — to hide your lookups from being read in plain text.

## Examples
```text
$ nslookup cs50.harvard.edu
Server:  8.8.8.8
Address: 8.8.8.8#53

Non-authoritative answer:
Name: cs50.harvard.edu
Address: 34.194.29.6
```
```text
Common public DNS servers
8.8.8.8     Google
1.1.1.1     Cloudflare
9.9.9.9     Quad9
208.67.222.222  OpenDNS
```

## **Why It Matters**
Every web request starts with DNS. Without it, you’d have to remember numeric IPs.  
Knowing DNS helps debug slow page loads, connection errors, and configuration issues when deploying sites.

## Questions
- ❓What happens if a DNS record changes while your browser cache still holds the old one?  
- ❓How do **CDNs** use DNS to route users to nearby servers?

## Related Concepts
- [[TCP IP]] – DNS runs over UDP/TCP using port 53.  
- [[IP Addressing IPv4 vs IPv6]] – IPs that DNS resolves to.  
- [[Routers]] – route the packets once DNS finds the address.  
- [[Ports how apps share one IP]] – DNS uses specific ports.  
- [[ARPANET 1969]] – early Internet groundwork.  
- [[IPv4 Header what’s inside a packet]] – how DNS requests travel in packets.  
- [[HTTP Lifecycle]] – what happens after DNS gives the IP.  
- [[CDN Content Delivery Network]] – uses DNS for smart routing.

## See also
- []                                                                        
- [DNS — Wikipedia](https://en.wikipedia.org/wiki/Domain_Name_System)
- [Cloudflare Learning — What is DNS?](https://www.cloudflare.com/learning/dns/what-is-dns/)
- [How DNS Works (animated)](https://howdns.works/)

## Terms
[[DNS]], [[DNS resolver]], [[Root server]], [[TLD]], [[Authoritative server]], [[A record]], [[AAAA record]], [[CNAME]], [[MX record]], [[TXT record]], [[DNS cache]], [[DNS over HTTPS]], [[DNS over TLS]]
