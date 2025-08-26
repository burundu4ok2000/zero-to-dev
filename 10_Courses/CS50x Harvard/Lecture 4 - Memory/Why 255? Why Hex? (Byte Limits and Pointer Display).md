---
title: Why 255? Why Hex? (Byte Limits and Pointer Display)
type_tags: "#type/explainer"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
atom_idx: "18"
status: done
difficulty: easy
date: 2025-08-22
review_next: 2025-09-20
source: https://cs50.harvard.edu/x/2025/weeks/4/
---

## 🧮 Why 255?

255 is the **maximum value** that can be stored in **1 byte** (8 bits):

- 1 byte = 8 bits  
- Each bit has 2 states: 0 or 1  
→ So total combinations: `2^8 = 256`  
→ Values: from `00000000` (0) to `11111111` (255)

```c
Binary:  11111111
Decimal: 255
Hex:     0xFF
```

> ❗ 255 is not 2 bytes.  
> 2 bytes = 16 bits = max value **65535**

---

## 🎨 Where 255 Appears

- **Colors (RGB)**: each channel from 0 to 255
- **ASCII**: fits in 1 byte
- **`unsigned char`**: 0–255
- **Bitmasks**: `0xFF` = one full byte (8 ones)

---

## 🧠 Why Use Hex for Pointers?

### ✅ Human-readable binary
Hex compresses long binary:
```
Binary: 1111 1111 1111 1100
Hex:    0xFFFC
Decimal: 65532  ← harder to read
```


```
F  = 1111 
```

### ✅ Structural alignment
Easy to spot byte-wise layout:
- Hex: `0x1000 → 0x1004 → 0x1008`
- Decimal: `4096 → 4100 → 4104`

### ✅ Standard in debuggers
GDB, LLDB, Valgrind show addresses in hex — compact & readable

### ✅ Machine-friendly
- 1 hex digit = 4 bits  
- 2 hex digits = 1 byte  
- Perfect for memory dumps, instructions, offsets

### ✅ Legacy & convention
Since the 70s, hex became the standard way to show memory addresses.

---

## 🔁 Comparison Table: Hex vs Decimal

|                    | **Hexadecimal**          | **Decimal**               |
|--------------------|--------------------------|---------------------------|
| Base               | 16 (0–F)                 | 10 (0–9)                  |
| Alignment to bits  | 1 hex digit = 4 bits     | No clear alignment        |
| 1 Byte             | `00` to `FF`             | 0 to 255                  |
| Memory dump format | Clean, aligned           | Long, cluttered           |
| Machine use        | Yes (native)             | Rare                      |
| Readability        | Compact & visual         | Bulky for addresses       |

---

## 🧠 Final Thought

Pointers are stored as binary — but hex is the most efficient way to display them:
- Compact
- Human-friendly
- Machine-aligned

