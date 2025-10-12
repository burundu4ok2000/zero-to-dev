---
title: "Internet Primer — DHCP (Dynamic Host Configuration Protocol)"
lang_tags: "#lang/html, #lang/css, #lang/javascript"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_8_HTML_CSS_JavaScript"
tool_tags: ""
atom_idx: 09
status: "in-progress"
difficulty: "easy"
date: "2025-10-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/8/"
review_next: "2025-10-18"
---

---

![[Screenshot 2025-10-11 at 15.39.05.png]]

---

## Summary
**DHCP** stands for **Dynamic Host Configuration Protocol**.  
It automatically gives devices their network settings — such as **IP address**, **subnet mask**, **gateway**, and **DNS server** — so users don’t need to set them manually.

## Very simple
> When your laptop joins Wi‑Fi, it asks: “Can someone give me an address?”  
> The **router (DHCP server)** answers: “Sure — here’s one!”

## Key Points
- **DHCP server** (usually your router) assigns temporary IPs to devices.  
- The device is a **DHCP client** — it asks for configuration.  
- It works in four steps called **DORA**:  
  1. **Discover** — client sends a broadcast: “Any DHCP servers here?”  
  2. **Offer** — a server replies with an IP offer.  
  3. **Request** — client accepts the offer.  
  4. **Acknowledge** — server confirms and records the lease.  
- The assigned IP is valid for a limited time (**lease**). When the lease ends, the client can renew it.  
- DHCP can also pass extra info: DNS servers, default gateway, MTU size, etc.  
- Works mostly over **UDP**, ports **67 (server)** and **68 (client)**.  

## Details
Without DHCP, every computer would need its IP and subnet configured by hand — messy and error‑prone.  
Home routers run a built‑in DHCP service. In larger networks, companies use dedicated DHCP servers to manage many devices.  
When you reconnect to the same network, DHCP often gives you the same address again (called a **sticky lease**).  
Static IPs can still be set manually for servers that must stay at fixed addresses.

## Examples
```text
Typical home DHCP lease
192.168.0.100 → Laptop
192.168.0.101 → Phone
192.168.0.102 → Printer
Gateway: 192.168.0.1
DNS: 1.1.1.1
Lease time: 24 hours
```
```bash
# Check current DHCP lease on macOS/Linux
ipconfig getpacket en0
# or
cat /var/lib/dhcp/dhclient.leases
```

## **Why It Matters**
Every device on a network must have a unique IP address. DHCP makes this automatic and scalable.  
Understanding DHCP helps you fix “no internet” problems — they often happen when DHCP fails.

## Questions
- ❓What happens if two DHCP servers respond at the same time?  
- ❓How does DHCPv6 differ from DHCPv4?

## Related Concepts
- [[IP Addressing IPv4 vs IPv6]] – DHCP assigns these addresses.  
- [[Routers]] – routers often act as DHCP servers.  
- [[DNS Domain Name System]] – DHCP tells clients which DNS server to use.  
- [[ARPANET 1969]] – early networks before DHCP existed.  
- [[TCP IP]] – DHCP messages travel over UDP in the IP layer.  
- [[Ports how apps share one IP]] – uses ports 67 and 68.  
- [[IPv4 Header what’s inside a packet]] – defines how DHCP packets are transported.  
- [[Network Configuration]] – broader topic of how devices join and talk on networks.

## See also
- []                                                                        
- [DHCP — Wikipedia](https://en.wikipedia.org/wiki/Dynamic_Host_Configuration_Protocol)
- [How DHCP works (Cloudflare)](https://www.cloudflare.com/learning/network-layer/what-is-dhcp/)
- [DHCP Explained (Cisco)](https://www.cisco.com/c/en/us/products/ios-nx-os-software/dynamic-host-configuration-protocol-dhcp/index.html)

## Terms
[[DHCP]], [[Lease]], [[DHCP server]], [[DHCP client]], [[Discover Offer Request Acknowledge]], [[UDP port 67]], [[UDP port 68]], [[Gateway]], [[Subnet mask]], [[Static IP]]
