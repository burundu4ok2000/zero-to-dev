---
title: Binary Example - "CS Trivia"
lang_tags: 
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: ""
atom_idx: 5
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/0/
review_next: ""
---

![[Screenshot 2025-06-23 at 18.14.48.png]]

---

## **One-liner**

Binary **01000000** equals **64** in decimal; in **ASCII** that’s **@** — a tidy bit of **CS trivia** that cements **bit positions** and **powers of two**.

## Bit layout (8‑bit)

| Bit index (MSB→LSB) | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|---|---|---|---|---|---|---|---|---|
| Power of two | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
| Bits in 01000000 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |

Only the **2^6** place is **1**, so the value is **64**.

```text
01000000₂ = 64₁₀
```

## ASCII connection

ASCII maps integers **0..127** to characters. The code **64** corresponds to **'@'**. Knowing a few anchors (like 48 → '0', 65 → 'A', 97 → 'a') helps you sanity‑check data and debug encodings quickly.

## Why this matters

- Strengthens your mental model of **bits**, **bytes**, and **positional notation**.  
- Bridges number systems with **character encoding** (text is just numbers).  
- Shows how a single **bit** flips meaning — set bit 5 instead and you get **32**.

## Quick practice

- What is `00100000₂`? → **32** (ASCII 32 is space `' '`).  
- What is `01000001₂`? → **65** (ASCII 'A').

## Related Concepts

- [[ASCII Basics]] – the code chart from integers to characters.  
- [[ASCII and Its Limitations]] – why ASCII tops out at 127 and where **Unicode** comes in.  
- [[Binary Number System]] – base‑2 representation and conversion.  
- [[Bit and Byte]] – storage units you flip and pack.  
- [[Binary to Decimal Conversion]] – step‑by‑step methods.  
- [[Character Encoding]] – broader context beyond ASCII.

## See Also

- [CS50x 2025 — Week 0 overview](https://cs50.harvard.edu/x/2025/weeks/0/)  
- [Wikipedia — Binary number](https://en.wikipedia.org/wiki/Binary_number)  
- [Wikipedia — ASCII](https://en.wikipedia.org/wiki/ASCII)

## Terms

[[binary]], [[bit]], [[byte]], [[most significant bit]], [[least significant bit]], [[power of two]], [[decimal]], [[ASCII]], [[character code]], [[encoding]]
