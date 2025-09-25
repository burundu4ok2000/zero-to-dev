---
title: Rewriting credit.c into credit.py
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 33
status: done
difficulty: easy
date: 2025-09-25
timecode: ""
source: "Refactor log: credit.c → credit.py"
review_next: ""
---

## One Liner
We transformed a brittle **C** implementation of **Luhn** into a compact, readable **Python** function: single **parameter**, clean **list comprehension**, and a right‑to‑left loop with **reversed** + **enumerate**. Fewer lines, fewer bugs, same math.

## What I Learned (high‑impact)
- Design a sane **function signature**: `def luhn(number: str) -> bool` (+ **type annotations**).
- Replace manual digit slicing (`% 10`, `// 10 % 10`, …) with a **list comprehension** over `str(ccn)`.
- Count from the **right** using **reversed** + **enumerate** instead of awkward index math.
- Return a **boolean expression** directly: `return total % 10 == 0`.
- Prefer **guard clauses** for validation (`if not number.isdigit(): raise ValueError(...)`).

## Before — C (length check + digit extraction)
```c
// length guard (fragment)
if (credit_card_length < 0) {
    printf("INVALID\n");
    return 0;
}

// digit extraction (manual, positional)
num1 = ccn % 10;
num2 = ccn / 10 % 10;
num3 = ccn / 100 % 10;
...
num16 = ccn / 1000000000000000 % 10;
```
Pain points: fixed **16‑digit** assumption, dozens of **positional divides**, boilerplate impossible to maintain.

## After — Python (clean & general)
### 1) Length check (readable)
```python
if len(s) not in (13, 15, 16):
    print("INVALID")
    sys.exit()
```
A tuple is fine, intent is clear.

### 2) Digit extraction (one liner)
```python
digits = [int(d) for d in str(ccn)]
```
Boom — converts the whole number into digits.  
Index naturally: `digits[0]` (first), `digits[-1]` (last).

## The Luhn core (final form)
```python
def luhn(number: str) -> bool:
    # Return True if number passes the Luhn check.
    if not number.isdigit():
        raise ValueError("number must contain only digits")

    digits = [int(d) for d in number]
    total = 0
    for i, d in enumerate(reversed(digits)):   # rightmost → left
        if i % 2 == 1:                         # every second digit from the right
            d *= 2
            if d > 9:
                d -= 9                         # digit-sum trick (12 → 3)
        total += d
    return total % 10 == 0
```

## Why the Python version wins
- Works for **13/15/16/19** digits — no hard‑coded arity.
- Uses idiomatic **Python loops** and **comprehensions**; far fewer moving parts.
- Easier to test, easier to extend, and trivially reusable.

## Related Concepts
- [[Python Objects — Beginner Notes]] – functions, **methods**, **dunder**
- [[Python Syntax — Running, Style, Shebang]] – quick CLI runs
- [[Python Sequences — list vs tuple vs range]] – choose your sequence
- [[Python Built-in Keyword Parameters — Cheat Sheet]] – `enumerate`, `print`, `open`
- [[assert Statement in Python]] – quick sanity checks in tests
- [[Python Division — / vs // (true vs floor division)]] – `%`/`//` rules used here
- [[Vocabulary · Mutable vs Immutable]] – **str** immutability background
- [[Python String Concatenation Complexity — s + t vs ''.join]] – cost model for **str**

## See Also
- [Luhn algorithm — Wikipedia](https://en.wikipedia.org/wiki/Luhn_algorithm)
- [Python docs — enumerate](https://docs.python.org/3/library/functions.html#enumerate)
- [Python docs — built-in types (str, list)](https://docs.python.org/3/library/stdtypes.html)

## Terms
[[refactor]], [[Luhn algorithm]], [[function signature]], [[type annotation]], [[list comprehension]], [[enumerate]], [[reversed]], [[guard clause]], [[boolean expression]], [[isdigit]], [[floor division]], [[modulo %]], [[credit card number]], [[input validation]], [[early exit]]
