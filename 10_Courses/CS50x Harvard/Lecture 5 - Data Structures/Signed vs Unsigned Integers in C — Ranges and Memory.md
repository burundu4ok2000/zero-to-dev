---
title: "Signed vs Unsigned Integers in C — Ranges and Memory"
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 16
status: "in-progress"
difficulty: "easy"
date: "2025-09-17"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---
![[cover_signed_unsigned.png]]
## Summary
**Signed** integers can store negative and positive numbers. **Unsigned** integers store only non‑negative numbers.  
They take the **same memory** for the same base type (e.g., `sizeof(int) == sizeof(unsigned int)`), but the **range** is split differently.

- **Unsigned (N bits)**: from **0** to **2^N − 1**.  
- **Signed (N bits, two’s complement)**: from **−2^(N−1)** to **2^(N−1) − 1**.

> In C, exact sizes are **implementation‑defined**. Use `sizeof(type)` and `<limits.h>` to get the real numbers on your system.

---

## Very simple
Imagine each integer as **N light bulbs** (bits).  
- **Unsigned** uses **all bulbs** for the magnitude → more positive numbers.  
- **Signed** uses one bit to represent **negative** values (via **two’s complement**) → half positive, half negative.

```
8-bit unsigned:  [00000000 .. 11111111]  →  0 .. 255
8-bit signed  :  [10000000 .. 01111111]  →  -128 .. 127
```

---

## Key Points
- **Memory**: same bytes for signed/unsigned of the same base type.  
- **Range**: unsigned gives you about **twice** the positive range.  
- **Two’s complement**: the common representation of signed integers in modern systems.  
- **Overflow**: unsigned **wraps around** (mod `2^N`); signed overflow is **undefined behavior** in C.  
- **Mixing types**: in expressions, C may **promote** to unsigned, which can surprise you.  
- **`char` gotcha**: plain `char` may be **signed or unsigned** depending on compiler; use `signed char` / `unsigned char` for clarity.

---

## Typical ranges (by bit‑width)
> Real sizes may differ. This table shows **common** modern targets.

| **Type (typical)** | **Bits** | **Signed range** | **Unsigned range** |
|---|---:|---:|---:|
| `char` | 8  | −128 … 127 | 0 … 255 |
| `short` | 16 | −32768 … 32767 | 0 … 65535 |
| `int` | 32 | −2_147_483_648 … 2_147_483_647 | 0 … 4_294_967_295 |
| `long` (LP64) | 64 | −9_223_372_036_854_775_808 … 9_223_372_036_854_775_807 | 0 … 18_446_744_073_709_551_615 |
| `long long` | 64 | same as above | same as above |

> On Windows (LLP64), `long` is 32‑bit. Always check with `sizeof(long)`.

---

## Get exact sizes & ranges on **your** machine
```c
#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("sizeof(int) = %zu bytes\n", sizeof(int));
    printf("INT_MIN = %d, INT_MAX = %d\n", INT_MIN, INT_MAX);
    printf("UINT_MAX = %u\n", UINT_MAX);

    printf("sizeof(long) = %zu bytes\n", sizeof(long));
    printf("LONG_MIN = %ld, LONG_MAX = %ld\n", LONG_MIN, LONG_MAX);
    printf("ULONG_MAX = %lu\n", ULONG_MAX);

    printf("CHAR_BIT = %d\n", CHAR_BIT);
    printf("SCHAR_MIN = %d, SCHAR_MAX = %d, UCHAR_MAX = %u\n",
           SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
}
```

---

## Bit intuition (two’s complement)
To get `−x` from `x` (same width): **invert bits** and **add 1**.

Example with 8 bits (`5` → `00000101`):
```
~00000101 = 11111010
+       1 = 11111011  ← this is −5
```

---

## Pitfalls & gotchas
- **Wraparound** (unsigned): `0u - 1u` becomes the **maximum** unsigned value.  
- **Signed overflow**: `INT_MAX + 1` is **undefined** (don’t rely on wrap).  
- **Comparisons**: `-1 < (unsigned)1` is **false** because `-1` converts to a huge unsigned.  
- **Right shift**: for signed types the behavior can be **implementation‑defined** (arithmetic vs logical). For unsigned it is logical (fills with zeros).  
- **I/O formats**: use the correct `printf` specifiers (`%u`, `%lu`, `%zu`, etc.).

---

## When to pick which
- Choose **unsigned** when the value is **never negative** and you want extra **positive range** (sizes, bitmasks, counts).  
- Choose **signed** for anything that can be **negative**, or when you do **arithmetic** that might cross zero.  
- In public APIs, favor **explicit widths** (`uint32_t`, `int64_t` from `<stdint.h>`) for clarity.

---

## Related Concepts
- [[Dynamic Memory Allocation — malloc & free]] – store integers in heap objects.
- [[Asymptotic Analysis — O, Ω, Θ]] – size doesn’t change big‑O, but affects constants.
- [[Hash Tables — Arrays and Linked Lists]] – often use **unsigned** for indices/hashes.
- [[Queues — Enqueue and Dequeue]] – counts and indices often **unsigned**.
- [[Stacks — Push and Pop]] – overflow checks with signed vs unsigned.
- [[Binary-Search-Trees-Basics-and-Operations]] – keys can be either; compare consistently.
- [[Arrow Operator and Struct Pointers in C]] – structs with integer fields.

## See Also
- C integer types (cppreference)
- limits.h reference (cppreference)
- Two’s complement (Wikipedia)

## Terms
**Signed**, **Unsigned**, **Two’s complement**, **Overflow**, **Wraparound**, **Promotion**, **Conversion**, **Range**, **Width**, **Byte**, **Bit**
