---
title: "CrowdStrike Crash — Real-World Buffer Overflow Case"  
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 24
status: "done"
difficulty: "medium"
date: "2025-08-27"
timecode: "1:58:50–2:00:00"
source: "https://cs50.harvard.edu/x/2025/weeks/4/"
review_next: "2025-09-27"
---

![[Screenshot 2025-08-27 at 11.25.26.png]]
![[Screenshot 2025-08-27 at 11.25.35.png]]

---

## Summary
In July 2024, **CrowdStrike** caused a massive system outage worldwide due to a simple **buffer over-read**: a software component tried to read past the end of an input array — just one element too far.

## Very simple

> Imagine you expect **20 guests**, but ask for the **21st chair**.  
> The chair doesn’t exist — and when someone tries to sit there, **everything crashes**.

## Key Points
- A real-world **out-of-bounds read** crashed Windows systems globally.
- The bug was in **CrowdStrike’s Content Interpreter**.
- It tried to **compare a 21st input value**, even though only **20 values were valid**.
- Result: **memory access beyond array bounds**, leading to **system crash**.
- This is a classic example of a **buffer overflow bug** in the wild.

## Details

The relevant part of the public incident report stated:

> *"Interpreter expected only 20 values. Therefore, the attempt to access the 21st value produced an out-of-bounds memory read beyond the end of the input data array and resulted in a system crash."*

This small mistake in memory access logic led to:
- BSOD (Blue Screen of Death) on millions of Windows machines.
- Downtime for banks, airlines, hospitals.
- Emergency global patch rollout.

## **Why It Matters**
- Even **tiny bugs** in memory handling can lead to **catastrophic consequences**.
- This is why **buffer overflows are critical** to understand and prevent.
- Reinforces the need for:
  - **Memory-safe languages** (e.g. Rust)
  - **Better testing and fuzzing**
  - **Static analysis tools**

## Questions

- ❓Could this have been caught with better unit testing?
- ❓Would a memory-safe language have prevented this?

## Related Concepts

- [[Buffer Overflow — Exploiting Memory via Arrays]] – how over-reads corrupt memory.
- [[Stack vs Heap Memory]] – overflows can happen in both.
- [[Valgrind Basics]] – tool to catch these issues before deployment.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]]
- [[malloc and free]] – where many of these bugs originate.
- [[Pointers in C]] – they enable but also endanger memory safety.
- [[Memory Leak — What It Is and How to Fix It]]
- [[Stack Overflow vs Heap Overflow — Memory Crashes Explained]]

## See also

- [CrowdStrike Crash Explained — Ars Technica](https://arstechnica.com/information-technology/2024/07/crowdstrike-update-caused-massive-windows-crashes/)
- [Out-of-Bounds Read — CWE-125](https://cwe.mitre.org/data/definitions/125.html)
- [How Buffer Overflows Work](https://www.geeksforgeeks.org/buffer-overflow-attack-with-example/)

## Terms

[[buffer overflow]], [[out-of-bounds read]], [[memory corruption]], [[crash]], [[CrowdStrike]], [[array bounds]], [[interpreter bug]], [[BSOD]], [[CWE-125]]
