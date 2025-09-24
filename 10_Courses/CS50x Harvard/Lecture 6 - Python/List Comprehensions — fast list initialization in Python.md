---
title: List Comprehensions — fast list initialization in Python
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 19
status: in-progress
difficulty: easy
date: 2025-09-23
timecode: 00:11:48
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

![[Screenshot 2025-09-23 at 14.00.28.png]]

## Summary
**List comprehension** is a compact way to build a list from an **iterable** (like `range`, another list, or a file). It packs the loop, optional filtering, and transformation into one readable expression.

```python
nums = [x for x in range(500)]
# read as: "for each x from range(500), put x into the new list"
```

## Core patterns
```python
# 1) Transform
squares = [x * x for x in range(10)]

# 2) Filter (keep only if condition is True)
evens = [x for x in range(10) if x % 2 == 0]

# 3) Transform + conditional expression
labels = ["even" if x % 2 == 0 else "odd" for x in range(5)]

# 4) Clean & normalize
clean = [s.strip().lower() for s in names if s]

# 5) Nested loops (left-to-right like normal loops)
pairs = [(a, b) for a in "ab" for b in "01"]   # ('a','0'), ('a','1'), ...

# 6) Flatten a 2D list
flat = [cell for row in grid for cell in row]
```

## Why it’s good
- Fewer lines than `for` + `append`, often faster.
- Expresses the **intent** (“build from X with rule Y”) in one place.
- Plays nicely inside other expressions, e.g., `sum(x*x for x in range(n))`.

## Generator expression vs list comprehension
Use **parentheses** to get a **generator** (lazy values, saves memory):
```python
total = sum(x * x for x in range(1_000_000))  # no giant list in RAM
```
Use **brackets** when you actually need the list:
```python
data = [x * x for x in range(1000)]
```

## Pitfalls
- Don’t create **nested puzzles**; if it’s hard to read, switch to a normal loop.
- Beware `[ [0]*3 ]*3` (reference duplication). Prefer: `[[0 for _ in range(3)] for _ in range(3)]`.
- The loop variable is local to the comprehension (no leaking in Python 3).

## Mental model
Think: 
```python
new_list = [result for item in source if condition]
```
 It’s just a loop you can fit **inside brackets**.

## Related Concepts
- [[Python Syntactic Sugar — Shortcuts from CS50]]
- [[For vs While in Python]]
- [[Python — range() deep dive]]
- [[If / Elif / Else — control flow]]
- [[Formatted Strings (f-strings) — Deep Dive]]
- [[Comprehensions — list/set/dict]]
- [[Lists and Iteration in Python]]
- [[Generator Expressions — lazy iteration]]

## See Also
- [[CS50x Week 6 — Python (Overview)]]
- [Python docs — Data structures (list comprehensions)](https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions)
- [PEP 202 — List Comprehensions](https://peps.python.org/pep-0202/)

## Terms
[[list comprehension]], [[iterable]], [[filter]], [[transform]], [[conditional expression]], [[generator expression]], [[flatten]], [[nested comprehension]]
