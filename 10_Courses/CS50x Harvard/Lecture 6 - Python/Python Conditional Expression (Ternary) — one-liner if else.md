---
title: "Python Conditional Expression (Ternary) — one-liner if/else"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 18
status: "in-progress"
difficulty: "easy"
date: "2025-09-23"
timecode: "00:07:00–00:07:05"
source: "https://cs50.harvard.edu/x/2025"
review_next: ""
---

![[Screenshot 2025-09-23 at 12.37.08.png]]
![[Screenshot 2025-09-23 at 12.37.14.png]]

## Summary
Python’s **conditional expression** is a compact **one‑liner if/else**:
```python
value_if_true if condition else value_if_false
```
It is Python’s answer to C’s `cond ? a : b`. Use it when you want a **small** decision in an **expression** (inside an assignment, f‑string, comprehension, etc.).

## Examples
```python
# From the slide (cleaned)
letters_only = True if input().isalpha() else False

# Idiomatic shorthand: the expression is already boolean
letters_only = input().isalpha()

# Inline choice
greeting = f"Hello, {'friend' if vip else 'stranger'}!"

# With numbers
fee = 0 if age < 6 else 10
```

## When to use vs a full if/else
- Good: short value choice on one line, especially inside **f‑strings** or **comprehensions**.
- Avoid: long or nested chains — prefer a normal **if/elif/else** block for readability.

## Pitfalls
- Don’t confuse the order with C: **Python** is `A if cond else B` (C is `cond ? A : B`).  
- Keep the **condition** simple; put heavy logic outside the expression.
- The expression returns a **value**; it does **not** allow statements (e.g., no `print()` on one side and nothing on the other).

## Mental model
Read it as: “take **this** if the **condition** holds, **else** take **that**.” It’s a tiny switch that fits wherever a **value** is expected.

## Related Concepts
- [[If / Elif / Else — control flow]]
- [[Boolean logic and truthiness]]
- [[Formatted Strings (f-strings) — Deep Dive]]
- [[Python Syntactic Sugar — Shortcuts from CS50]]
- [[Input Validation vs Exception Handling]]
- [[For vs While in Python]]
- [[Functions and Side Effects]]
- [[Python — range() deep dive]]

## See Also
- [[CS50x Week 6 — Python (Overview)]]
- [Conditional Expressions (docs)](https://docs.python.org/3/reference/expressions.html#conditional-expressions)

## Terms
[[conditional expression]], [[ternary]], [[truthiness]], [[boolean]], [[f-string]], [[comprehension]], [[control flow]]
