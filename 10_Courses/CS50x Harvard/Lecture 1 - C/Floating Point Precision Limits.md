---
title: "Floating Point Precision Limits"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 12
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

## **One-liner**

**Floating point** arithmetic is inherently approximate because real numbers are squeezed into a fixed number of bits, so tiny **rounding errors** are normal.

## Big idea

- **Finite bits ≠ infinite digits**: `float` (32‑bit, **single precision**) and `double` (64‑bit, **double precision**) can represent only a subset of real numbers.
- **Some fractions are impossible in binary**: values like 1/3 or 0.1 become repeating binaries and must be rounded.
- **More bits reduce, not eliminate, error**: a `double` pushes error farther out, but it is still an approximation.
- **Design assumption**: treat floating‑point results as **approximate**, never as exact math.

## Quick demo

```c
#include <stdio.h>

int main(void)
{
    double a = 0.1 + 0.2;     // not exactly 0.3 in binary
    printf("%.17f\n", a);    // prints 0.30000000000000004 on many systems

    // compare with an epsilon (tolerance), not ==
    double b = 0.3;
    double eps = 1e-12;
    if ( (a > b ? a - b : b - a) < eps )
        puts("close enough");
}
```

## Practical implications

- Avoid \`\=\=\` on floats. Use an **epsilon** check when comparing results.
- Printing more digits reveals the stored approximation (`%.9f`, `%.17f`).
- For money, prefer **fixed‑point** or decimal types to avoid rounding pennies.
- Be mindful of **catastrophic cancellation**: subtracting nearly equal numbers can lose significant digits.

## Mitigation strategies (starter pack)

| Need | Try |
|---|---|
| Exact decimal math (finance) | **Fixed‑point** libraries or decimal types |
| Higher precision (science) | **Arbitrary precision** libs (GMP/MPFR), Python `decimal` |
| Robust comparisons | **Epsilon** comparisons, avoid equality checks |
| Stable algorithms | Rearrange math to reduce cancellation; accumulate from small to large |

## Related Concepts

- [[Float Type in C]] – size, range, and formatting basics.
- [[Double Type in C]] – more precision and when to use it.
- [[printf Format Specifiers]] – printing with `%.nf` to inspect precision.
- [[Casting in C]] – converting between integer, float, and double.
- [[Numeric Stability]] – algorithm choices that limit error growth.
- [[Fixed-Point Arithmetic]] – exact decimal math for money.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [Goldberg: What Every Computer Scientist Should Know About Floating‑Point Arithmetic](https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html)
- [floating‑point‑gui.de — A practical guide to floating point](https://floating-point-gui.de/)

## Terms

[[floating point]], [[single precision]], [[double precision]], [[binary fraction]], [[rounding error]], [[machine epsilon]], [[ULP]], [[cancellation]], [[epsilon comparison]], [[fixed-point]], [[arbitrary precision]]
