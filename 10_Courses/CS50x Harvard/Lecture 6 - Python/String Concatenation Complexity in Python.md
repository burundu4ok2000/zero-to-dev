---
title: String Concatenation Complexity in Python
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
status: done
difficulty: easy
date: 2025-09-24
source: ""
review_next: ""
---

## One Liner
**Concatenating strings** with `s + t` copies **all characters** from both operands, so it runs in **O(len(s) + len(t))**; for many appends use **str.join** (one pass).

## Problem
Why is `s + t` “slow” for big strings or inside loops?

## Core Idea
- **Strings are immutable** in Python: any “change” makes a **new object**.
- To compute `u = s + t`, Python must **allocate** a new string and **copy** every char from **s** and **t** into it.
- If `|s| = m` and `|t| = n`, cost is **m + n** character copies → **O(m + n)**.

## Example
```python
s = "a" * 1000
t = "b" * 2000
u = s + t  # copies 1000 + 2000 = 3000 chars
```

Even as a one‑liner, Python had to walk all 3000 characters to build `u`.

## Anti‑Pattern (+= in a loop)
```python
s = ""
for i in range(100_000):
    s += "x"        # builds a NEW string each time (growing copies) → O(n^2)
```

## Faster Pattern
```python
parts = []
for i in range(100_000):
    parts.append("x")   # list mutates in place (cheap)
s = "".join(parts)      # one O(n) pass to build the final string
```

## Why It Matters
- Repeated `+` on **immutable** strings causes **quadratic** time and memory churn.
- **str.join** (or an **io.StringIO**/**list buffer**) builds once, in a single **linear** pass.

## Bench‑Ready Snippets (drop into REPL)
```python
import time

def bench_plus_eq(n=20000):
    s = ""
    t0 = time.perf_counter()
    for _ in range(n):
        s += "x"
    return time.perf_counter() - t0

def bench_join(n=20000):
    parts = []
    t0 = time.perf_counter()
    for _ in range(n):
        parts.append("x")
    s = "".join(parts)
    return time.perf_counter() - t0
```

## When is `+` fine?
- A **small, fixed** number of concatenations (e.g., `"hello, " + name`).
- Building **f‑strings** or **format** results once.
- Anything **not** inside a large or unknown‑size loop.

## Gotchas
- `+=` on **immutable** types (like **str**) falls back to **__add__** → **new object**.  
  On **mutable** sequences (like **list**), `+=` may use **__iadd__** → **in‑place**.
- Mixed types? Convert first to avoid surprises (e.g., `str(x)`).
- For streaming output, consider **io.StringIO** to avoid massive intermediate lists.

## TL;DR
- `s + t` is **O(len(s) + len(t))** due to **immutability** and **full copy**.
- In loops/builders choose **"".join(parts)** or **StringIO** for **O(n)** total work.

## Related Concepts
- [[Vocabulary · Mutable vs Immutable]] – **mutability** rules, `+=` behavior
- [[Python Objects — Beginner Notes]] – **object**, **attribute**, **dunder** basics
- [[Python Syntax — Running, Style, Shebang]] – REPL vs files, quick tests with `time`
- [[Python — Lists vs Tuples]] – pick **mutable** vs **immutable** sequences
- [[Identity vs Equality (id vs ==) in Python]] – object **identity** vs value **equality**
- [[Immutability & Hashability]] – why **dict/set** keys need **hashable** types
- [[Python — Data Model Magic Methods]] – **__add__**, **__iadd__**, **__hash__**
- [[Garbage Collection in Python]] – life‑cycle of old strings

## See Also
- [str.join — docs](https://docs.python.org/3/library/stdtypes.html#str.join)
- [timeit — measure small code snippets](https://docs.python.org/3/library/timeit.html)
- [Why Python strings are immutable (FAQ)](https://docs.python.org/3/faq/design.html#why-are-python-strings-immutable)

## Terms
[[String concatenation]], [[Immutability]], [[Mutability]], [[Time complexity]], [[O(n)]], [[O(n^2)]], [[Allocation]], [[Copy]], [[Buffer]], [[str.join]], [[__add__]], [[__iadd__]], [[StringIO]], [[Garbage collector]]

