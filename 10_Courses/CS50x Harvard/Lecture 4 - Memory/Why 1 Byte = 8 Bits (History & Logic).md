---
title: "Why 1 Byte = 8 Bits (History & Logic)"  
lang_tags: "#lang/c #lang/machine_architecture"                                      
type_tags: "#type/concept"                                      
course_tags: "#course/cs50x/intoduction_to_CS"                                      
lecture_tags: "#lecture/week_4_Memory"                                      
atom_idx: 12                                            
status: "done"                                              
difficulty: "easy"                                           
date: "2025-08-22"                              
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                               
review_next: "2025-09-20"                                    
---

## Summary

A **byte** is defined as 8 bits in almost all modern systems — but this wasn’t always the case. The 8-bit byte became a standard due to historical, technical, and practical reasons related to text encoding, memory architecture, and compatibility.

---

## 🧠 Why 8 Bits?

### 🔡 1. Text Encoding (ASCII)
- **ASCII** uses 7 bits to represent characters (128 possible symbols).
- Adding **1 more bit** (total 8) allowed:
  - Extended characters (e.g. `é`, `ç`)
  - Control codes
- This made it ideal to store 1 character per **8-bit byte**.

### ⚙️ 2. Hardware Simplicity
- Early CPUs operated on **8-bit registers**.
- Memory buses, ALUs, and instructions could easily be aligned with 8-bit chunks.

### 📐 3. Power of 2
- 8 = `2³` → clean alignment with **binary logic**.
- `2⁸ = 256` values → perfect range for:
  - Unsigned: 0–255
  - Signed: –128 to 127

### 📦 4. File & Memory Structures
- File formats, encodings (UTF-8), network packets — all structured around bytes.
- Reading/writing in **8-bit blocks** became universal.

---

## ❗ Byte ≠ 8 Bits? Rare Exceptions

Before the 1970s, "byte" meant **any unit of storage** (often 6, 9, or 12 bits).

| System         | Byte Size | Notes                                  |
|----------------|-----------|----------------------------------------|
| IBM 1401       | 6 bits    | Text-oriented commercial machine       |
| CDC 6600       | 12 bits   | Scientific computing                   |
| PDP-10         | 9 bits    | Byte size configurable (1–36 bits!)    |
| GE-600 Series  | 9 bits    | Packed numeric encoding                |

Even in modern C:
```c
CHAR_BIT >= 8  // but could be >8 on some exotic hardware
```

---

## 🧠 Why It Matters

- 8-bit bytes are now **hard-coded into standards**:
  - C, C++, Python: `char` = 1 byte = 8 bits
  - Networking, protocols, memory pages — all assume 8-bit alignment
- Helps explain:
  - Why `unsigned char` goes from 0 to 255
  - Why RGB values max out at 255 (`0xFF` = 8 bits)

---

## See Also
- [[What is a Bit and a Byte]]
- [[Why 255? (1 Byte Limit Explained)]]
- [[Hex vs Decimal — Machine-Level Perspective]]
- [[Memory Addressing Basics]]
- [Wikipedia — Byte History](https://en.wikipedia.org/wiki/Byte)

## Terms
[[bit]], [[byte]], [[ASCII]], [[CHAR_BIT]], [[memory bus]], [[word size]], [[register]], [[8-bit architecture]]
