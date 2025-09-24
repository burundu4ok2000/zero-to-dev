---
title: "Concatenation — Python’s + for Strings and Sequences"
lang_tags: "#lang/python"
type_tags: "#type/termin"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 02
status: "in-progress"
difficulty: "easy"
date: "2025-09-22"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/6/"
review_next: ""
---
---

![[Screenshot 2025-09-22 at 14.45.39.png]]

---

## Definition
**Concatenation** is joining values end‑to‑end to form a single value. In Python, the **+ operator** concatenates **strings** and other **sequences** (like **lists** and **tuples**).

## Syntax (Python)
```py
"a" + "b"           # → "ab"
"hello, " + name    # → "hello, Alice" (if name == "Alice")
[1, 2] + [3, 4]     # → [1, 2, 3, 4]

(1, 2) + (3,)       # → (1, 2, 3)  NOTE: (1, 2) + (3) won't work! 
                    # because it is <class 'tuple'> 
                    # NOT <class 'int'>
                    
b"hi" + b"!"        # → b"hi!"
```

## Notes & gotchas
- **Types must match**: `"age: " + 20` raises **TypeError**; use **str(20)** or **f-strings**: `f"age: {20}"`.
- **Strings are immutable** (cannot change in place). `"a" + "b"` makes a **new string**. 
- **SPEED**: Repeating `+` in a loop can be slow (**O(n^2)**). Use **"".join(pieces)** when concatenating **many** substrings.
- `+=` on **strings** still creates a new object; `+=` on **lists** extends **in place** (same object).  
  ```py
  s = "a"; s += "b"     # new string object
  xs = [1]; xs += [2]   # modifies xs in place → [1, 2]
  ```
- Time complexity for `s + t` is **O(len(s)+len(t))**.
- Decimal + strings don’t mix; convert explicitly: `str(num)` or use **formatting**/**f-strings**.

## Alternatives
- **join**: fastest for many strings → `result = "".join(list_of_parts)`.
- **format / f-strings**: `f"{first} {last}"` (readable; converts types for you).
- **list.extend** or **itertools.chain** for large list concatenation.

## Micro‑examples
```py
# Good: f-strings handle types
year = 2025
msg = f"Happy {year}!"         # "Happy 2025!"

# Good: join for many small parts
parts = ["he", "ll", "o"]
"".join(parts)                 # "hello"

# Good: extend list efficiently
xs = [1, 2]; xs.extend([3, 4]) # [1, 2, 3, 4]

# Careful: mismatched types
"score: " + 100                # TypeError
```

## Notice about `"".join` function

```python
parts = ["a", "b", "c"]

"".join(parts)   # "abc"   
"-".join(parts)  # "a-b-c" 
" ".join(parts)  # "a b c" 
```
## Why it matters (CS50 angle)
Python makes **string handling** trivial: no manual buffers, no `printf` formatting headaches. Understanding **concatenation** helps you write clean **I/O**, quick **scripts**, and avoid performance traps by switching to **join** when building big strings.

## Related Concepts
- [[Hello, world — C vs Python]] – first contrast of boilerplate vs one‑liner.
- [[Hash Tables — Arrays and Linked Lists]] – Python’s **dict** uses hashed **string** keys you might build by concatenation.
- [[Prime Numbers for Hashing — Why Primes Matter and How to Use Them]] – if you hash concatenated strings.
- [[Choosing a Data Structure — Practical Guide]] – choose **list** vs **string** based on operations.
- [[Signed vs Unsigned Integers in C — Ranges and Memory]] – contrast with Python’s dynamic integers.
- [[Arrow Operator and Struct Pointers in C]] – why Python concatenation feels simpler than C string handling.
- [[Binary-Search-Trees-Basics-and-Operations]] – ordered structures; useful when concatenation builds sortable keys.
- [[Queues — Enqueue and Dequeue]] – sequence operations vs concatenation/extend.

## See Also
- [[Hello, world — C vs Python]]
- [Python docs: Sequence types](https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range)
- [Python docs: str.join](https://docs.python.org/3/library/stdtypes.html#str.join)

## Terms
[[Concatenation]] [[String]] [[Sequence]] [[Operator]] [[Immutable]] [[TypeError]] [[f-string]] [[join()]] [[extend()]] [[Bytes]]
