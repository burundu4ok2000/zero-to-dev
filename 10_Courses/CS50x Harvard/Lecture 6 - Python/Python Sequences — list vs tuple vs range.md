---
title: Python Sequences — list vs tuple vs range
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 30
status: done
difficulty: easy
date: 2025-09-24
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

## One Liner
**list** is **mutable** and backed by a **dynamic array**; **tuple** is **immutable** and slightly leaner; **range** is a **lazy arithmetic progression** — a compact “recipe” for numbers.

## Concept
### 1) list
- **Mutable** → you can change it **in place**.
- Backed by a **dynamic array** under the hood.
- Great when contents change often.

```python
xs = [1, 2, 3]
xs.append(4)     # [1, 2, 3, 4]
xs[0] = 99       # [99, 2, 3, 4]
```

### 2) tuple
- **Immutable** → once created, cannot be changed.
- Good for **fixed** collections (e.g., coordinates `(x, y)`).
- Often smaller/faster than lists because Python can optimize them; also **hashable** if all items are hashable.

```python
coords = (10, 20)
# coords[0] = 99  # ❌ TypeError: 'tuple' object does not support item assignment
```

### 3) range
- Not a real **container** of stored elements.
- A **lazy** **arithmetic progression**: remembers **start/stop/step**.
- Generates items on **iteration**, tiny **memory footprint**.

```python
r = range(0, 10, 2)
print(r)        # range(0, 10, 2)
list(r)         # [0, 2, 4, 6, 8]
```

## Key Differences
- **list** = box of values, **editable** (mutable).
- **tuple** = box of values, **frozen** (immutable), can be **hashable**.
- **range** = **recipe** for numbers, not the numbers themselves, **memory‑efficient**.

## Rule of Thumb
- Need to **mutate** → use **list**.
- Need **fixed**, possibly **hashable** collection → use **tuple**.
- Need a **sequence of numbers** without memory bloat → use **range**.

## Examples 
```python
# Memory taste: big numeric sequence
n = 1_000_000
a = list(range(n))     # large memory
b = tuple(range(n))    # also large
c = range(n)           # tiny: just start/stop/step
```

```python
# Hashable keys
points = {(1, 2): "A"}     # tuple key OK
# {( [1, 2] ): "A"}       # ❌ list is unhashable
```

## Related Concepts
- [[Vocabulary · Mutable vs Immutable]] – rules of **mutability** vs **immutability**
- [[Python Objects — Beginner Notes]] – **object**, **attribute**, **method**, **dunder**
- [[Python String Concatenation Complexity — s + t vs ''.join]] – cost from **immutability**
- [[Mutable Default Arguments in Python]] – pitfalls of **mutable** defaults
- [[Python Built-in Keyword Parameters — Cheat Sheet]] – APIs like `sorted`, `zip(strict=...)`
- [[Identity vs Equality (id vs ==) in Python]] – **identity** vs **value** checks
- [[Python — Lists vs Tuples]] – deeper selection guide
- [[Python — Iteration & Generators]] – **lazy** patterns beyond `range`

## See Also
- [Built-in Types — list](https://docs.python.org/3/library/stdtypes.html#list)
- [Built-in Types — tuple](https://docs.python.org/3/library/stdtypes.html#tuple)
- [Built-in Types — range](https://docs.python.org/3/library/stdtypes.html#range)

## Terms 
[[sequence type]], [[mutable sequence]], [[immutable sequence]], [[dynamic array]], [[contiguous memory]], [[append]], [[item assignment]], [[slicing]], [[indexing (O(1))]], [[hashable]], [[tuple packing]], [[tuple unpacking]], [[membership test (in)]], [[iterable]], [[iterator]], [[random access]], [[range object]], [[arithmetic progression]], [[start/stop/step]], [[lazy evaluation]], [[memory footprint]], [[amortized O(1)]], [[generator expression]], [[slice object]]