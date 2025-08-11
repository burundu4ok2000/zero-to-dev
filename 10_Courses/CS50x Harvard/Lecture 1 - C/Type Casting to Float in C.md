---
title: "Type Casting to Float in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 33
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-17 at 11.38.16.png]]

---

## **One-liner**

Force **floating-point division** by casting **one operand** to `float` (or `double`); print with the matching **format specifier**.

## Problem

```c
int x = 1;
int y = 3;
printf("%i\n", x / y);   // prints 0   (integer division)
```
Both operands are `int`, so `x / y` performs **integer division**, discarding the fractional part.

## Solution — cast one operand (before the division)

```c
int x = get_int("x: ");
int y = get_int("y: ");

printf("%f\n", (float) x / y);   // 0.333333
```

### Why it works

1. `(float) x` converts `x` from `int` to `float`.  
2. C **promotes** `y` to `float` automatically.  
3. Division runs in **floating point**, preserving decimals.  
4. `%f` tells `printf` to format a floating value.

## Quick tips

- Force floating point with **one cast**: `(float) x / y` or `(double) x / y`.  
- Limit decimals: `printf("%.2f\n", value);`  
- In longer formulas, cast once near the start: `(float) x / y / z` (no need to cast every operand).

## Common pitfalls

- Casting **after** the division: `(float)(x / y)` still does **integer division** first — too late.  
- Wrong **format specifier**: `%i`/`%d` for ints; `%f` for `double` (and `float` promotes to `double` in `printf`).  
- Surprised by `int / int` truncation: it’s by design. Cast when you want real‑number math.

## Related Concepts

- [[Floating Point Precision Limits]] – why decimal results are approximate.  
- [[printf Format Specifiers]] – how `%.nf` controls printed precision.  
- [[Casting in C]] – converting between numeric types and promotions.  
- [[Integer Division in C]] – truncation rules and examples.  
- [[Double Type in C]] – when extra precision helps.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [cppreference — Usual arithmetic conversions](https://en.cppreference.com/w/c/language/conversion#Usual_arithmetic_conversions)  
- [cppreference — printf format specifiers](https://en.cppreference.com/w/c/io/fprintf)

## Terms

[[type cast]], [[float]], [[double]], [[integer division]], [[promotion]], [[printf]], [[format specifier]], [[precision]], [[explicit cast]], [[implicit conversion]], [[truncation]]
