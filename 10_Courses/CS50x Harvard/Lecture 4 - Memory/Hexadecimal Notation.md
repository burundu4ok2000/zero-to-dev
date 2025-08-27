---
title: Hexadecimal Notation
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 1
status: done
difficulty: easy
date: 2025-08-20
timecode: 00:10:18
source: https://cs50.harvard.edu/x/2025/weeks/4/
review_next: 2025-09-20
---

![[Screenshot 2025-08-20 at 15.56.54.png]]

![[Screenshot 2025-08-27 at 14.01.19.png]]
![[Screenshot 2025-08-27 at 14.04.13.png]]
![[Screenshot 2025-08-27 at 14.06.15.png]]
![[Screenshot 2025-08-27 at 14.10.28.png]]





---

## Summary
**Hexadecimal notation** is a base-16 system used in programming to represent numbers more compactly than binary.

## Very simple

> Imagine you have only 10 fingers, so you count from 0 to 9. But what if you had **16 fingers**? You'd need extra symbols: **A = 10**, **B = 11**, ..., **F = 15**. That’s **hex**!

## Key Points
- **Hexadecimal** is base-16: it uses digits `0–9` and letters `A–F`.
- Often used to represent **memory addresses** and **colors** in programming.
- It’s a compact way to represent **binary values** (every hex digit = 4 bits).
- Example: `0x1A` = **1×16 + 10 = 26** in decimal.

## Details
- Binary: `0001 1010` → Hex: `1A`
- Prefix in C is `0x` → like `0xFF`, `0x10`, etc.
- Each digit in hex represents 4 binary bits: `F` → `1111`

## Examples
```c
int x = 0x1F;     // x = 31 in decimal
printf("%x", 255); // prints 'ff'
```

## **Why It Matters**
- Helps programmers read and write binary data easier.
- Essential in **pointer arithmetic**, **memory dumps**, and **low-level debugging**.
- Used in many tools: **debuggers, editors, color pickers (HTML/CSS)**

## Questions
- ❓ Why use hex over decimal in real-world programming?
- ❓ Are hex values faster to process by CPU, or just for readability?

## Related Concepts
- [[Binary Representation]] – used together with {Hexadecimal Notation} to simplify large binary numbers.
- [[Pointers in C]] – addresses are printed in **hexadecimal** by default.
- [[Memory Layout of a Program]] – addresses often shown in hex.
- [[Integer Data Types in C]] – values can be assigned in hex format.
- [[ASCII Table Basics]] – shows hex codes for characters.
- [[Bitwise Operations]] – often applied to hex values.
- [[Signed vs Unsigned]] – hex can represent both forms.
- [[How printf works]] – `%x` is used for hex output.

## See also
- [[Lecture 4 — Memory]]
- [Hexadecimal - Wikipedia](https://en.wikipedia.org/wiki/Hexadecimal)
- [Base converter – RapidTables](https://www.rapidtables.com/convert/number/index.html)

## Terms
[[hexadecimal]], [[binary]], [[bit]], [[byte]], [[memory address]], [[pointer]], [[base-16]], [[printf]]
