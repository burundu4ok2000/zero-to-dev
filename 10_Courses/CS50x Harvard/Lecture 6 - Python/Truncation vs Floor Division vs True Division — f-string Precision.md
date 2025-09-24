---
title: Truncation vs Floor Division vs True Division — f-string Precision
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 8
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 01:20:51–01:22:15
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

![[Screenshot 2025-09-22 at 17.49.13.png]]
![[Screenshot 2025-09-22 at 17.51.02.png]]
![[Screenshot 2025-09-22 at 18.24.30.png]]

## Summary
**Truncation** means **drop the fractional part** of a number. In Python 3, `/` does **true division** (always returns a **float**), `//` does **floor division** (rounds **down** toward negative infinity), and `int(x)` does **truncation** (rounds **toward zero**). The `f-string` format like `f"{z:.50f}"` controls **how many digits** to show after the decimal point and it **rounds** to that precision.

## Key Points
- `x / y` → **float** result (true division). `1 / 3` → `0.333333333333...` (infinite in math, finite approximation in **binary float**).
- `x // y` → **floor division**. For positives it **looks like** truncation, but for negatives it differs: `-3 // 2 == -2` (floor), while `int(-3/2) == -1` (truncation).
- `int(x)` → **truncate** (toward 0). Examples: `int(3.9) == 3`, `int(-3.9) == -3`.
- `f"{z:.2f}"` → **format specifier**: `:.[precision][type]`, where `type` `f` is **fixed‑point**. It **rounds**, not truncates.
- Printing with many decimals: `f"{z:.50f}"` shows 50 digits after the dot, exposing **floating‑point error**.
- Need exact decimals? Use `decimal.Decimal` or `fractions.Fraction` instead of binary floats.

## Examples

```python
# True vs floor vs truncation
x, y = 7, 3
print(x / y)   # 2.3333333333333335  (true division -> float)
print(x // y)  # 2  (floor division)
print(int(x / y))  # 2  (truncation toward zero)
```

```python
# Negative case: floor != truncation
x, y = -3, 2
print(x // y)      # -2  (floor: down to -2)
print(int(x / y))  # -1  (truncation: toward 0)
```

```python
# Show N decimals with rounding (format spec)
z = 1 / 3
print(f"{z:.3f}")    # 0.333
print(f"{z:.10f}")   # 0.3333333333
print(f"{z:.50f}")   # 50 digits after decimal
```

```python
# Avoiding float issues when you need exact decimal math
from decimal import Decimal, getcontext
getcontext().prec = 28
a = Decimal("1") / Decimal("3")
print(a)              # 0.3333333333333333333333333333
print(f"{a:.10f}")  # 0.3333333333 (format still works)
```

## Mental Model
Think of `/` as **mathematical division**, `//` as **step down to the nearest whole** (even past zero), and `int()` as **chop off the tail** (sign stays, decimals gone). Formatting with `:.2f` is **cosmetic rounding for display**, not changing the underlying value.

## Related Concepts
- [[Division Operators in Python]] – contrasts `/`, `//`, and `%` with examples.
- [[Floating-Point Precision (IEEE 754)]] – why `0.1 + 0.2 != 0.3`.
- [[Formatted Strings (f-strings) — Deep Dive]] – full **format spec** mini-language.
- [[Rounding Strategies in Python]] – `round()`, bankers rounding, and contexts.
- [[Casting vs Coercion]] – where **int()**, **float()** conversions fit.
- [[Negative Numbers Edge Cases]] – behavior of `//`, `%` with signed values.
- [[Decimal and Fraction Modules]] – exact arithmetic for money and ratios.
- [[Printing Numbers — format() vs f-strings]] – performance and readability.

## See Also
- [[CS50x Week 6 — Python (Overview)]]
- [Python docs: Arithmetic operators](https://docs.python.org/3/reference/expressions.html#arithmetic-conversions)
- [Format Specification Mini-Language](https://docs.python.org/3/library/string.html#formatspec)
- [decimal — Decimal fixed point and floating point arithmetic](https://docs.python.org/3/library/decimal.html)

## Terms
[[truncation]], [[true division]], [[floor division]], [[type conversion]], [[precision]], [[fixed-point format]], [[format specifier]], [[rounding]], [[binary floating point]], [[decimal]]
