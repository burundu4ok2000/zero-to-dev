---
title: Division (true vs floor division) in Python
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 31
status: done
difficulty: easy
date: 2025-09-24
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

## One Liner
`/` is **true division** (always returns a **float**). `//` is **floor division** (rounds **down** toward −∞ to an **integer** for ints, or a **float** if any operand is float).

## Explanation
- **True division `/`**: computes the exact quotient as a **float**, even for integers: `7 / 2 == 3.5`.
- **Floor division `//`**: computes `math.floor(a / b)`. With integers → result is `int`; 
  
- if any operand is `float` → result is `float` (e.g., `3.0`). 
  
- Works with negatives by flooring toward **−∞**: `-7 // 2 == -4` (since `-3.5` floors to `-4`).

### Relation to `%` and `divmod`
For numbers `a` and `b != 0`:
```python
a == b * (a // b) + (a % b)
# modulo sign follows the divisor:  7 % 2 == 1,  -7 % 2 == 1,  7 % -2 == -1
q, r = divmod(a, b)  # q == a // b and r == a % b
```

## Examples
```python
7 / 2    # 3.5      true division
7 // 2   # 3        floor division (int)
7.0 // 2 # 3.0      floor division (float because operand is float)

-7 / 2   # -3.5     true division
-7 // 2  # -4       floor(-3.5) → -4
-7 % 2   # 1        because a == b*q + r → -7 == 2*(-4) + 1
```

```python
# Using results together
q = 19 // 4   # 4
r = 19 % 4    # 3
assert 19 == 4*q + r
```

## When to use which
- Use **`/`** for real‑valued math, averages, ratios, and when you need decimals.
- Use **`//`** to **count full chunks** or **index pages**: `page = idx // per_page`.
- For **negative** values, double‑check logic: floor vs truncate can differ (`-3.5` → floor `-4`, trunc `-3`).

## Rounding vs Floor
- `math.floor(x)` → round down toward **−∞**.
- `math.trunc(x)` → chop toward **0**.
- `round(x)` → bankers’ rounding to nearest (ties to even) for floats.

## Edge Cases
- **Division by zero** raises **ZeroDivisionError** for both `/` and `//` (including floats).
- With **Decimal** and **Fraction** from `decimal`/`fractions`, `/` and `//` follow those types’ rules (exact rational vs context‑aware decimal).

## Examples 
```python
# Pagination
n_items = 53
page_size = 10
pages = n_items // page_size  # 5 full pages
last_page_len = n_items % page_size  # 3 leftover
```

```python
# Average (mean) must use true division
avg = sum(values) / len(values)
```

## Terms
[[true division]], [[floor division]], [[float]], [[int]], [[negative numbers]], [[math.floor]], [[math.trunc]], [[round]], [[ZeroDivisionError]], [[modulo %]], [[divmod]], [[operator precedence]], [[type coercion]], [[Decimal]], [[Fraction]]

## Related Concepts
- [[Python — Numbers (int/float)]] – numeric types and behavior
- [[Python — Modulo % and divmod]] – the remainder identity and edge cases
- [[Python — Rounding (round, floor, trunc)]] – picking the right rounding mode
- [[Python Objects — Beginner Notes]] – types, **dunder** methods and protocols
- [[Python Syntax — Running, Style, Shebang]] – quick REPL checks
- [[Vocabulary · Mutable vs Immutable]] – why numeric **immutability** matters
- [[Python String Concatenation Complexity — s + t vs ''.join]] – cost model for immutable types
- [[Mutable Default Arguments in Python]] – function defaults nuance

## See Also
- [Python: Binary arithmetic operations](https://docs.python.org/3/reference/expressions.html#binary-arithmetic-operations)
- [math — floor, trunc, and related](https://docs.python.org/3/library/math.html)
- [fractions.Fraction](https://docs.python.org/3/library/fractions.html) · [decimal.Decimal](https://docs.python.org/3/library/decimal.html)
