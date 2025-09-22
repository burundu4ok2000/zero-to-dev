---
title: "Python Built-in Data Types — Quick Guide"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 05
status: "in-progress"
difficulty: "easy"
date: "2025-09-22"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/6/"
review_next: ""
---
---

![[Screenshot 2025-09-22 at 16.15.38.png]]
---

## One Liner
Python ships with rich **built‑in types** (numbers, **strings**, **sequences**, **mappings**, **sets**) so you can model data without writing structures from scratch.


---

## Core families
- **Numbers**: **int** (arbitrary precision), **float** (IEEE‑754 double), **complex**.  
- **Text**: **str** (Unicode).  
- **Binary**: **bytes** (immutable), **bytearray** (mutable).  
- **Sequences**: **list** (mutable), **tuple** (immutable), **range** (lazy, arithmetic progression).  
- **Mapping**: **dict** (hash table of key → value).  
- **Sets**: **set** (mutable), **frozenset** (immutable).  
- **Singleton**: **None** (no value).

### Mutability & order
| Type | Ordered? | Mutable? | Typical use |
|---|---|---|---|
| **list** | yes | yes | growing/reshaping sequences |
| **tuple** | yes | no | fixed records, dict keys |
| **range** | yes (iterable) | no | loops, indices |
| **dict** | yes (insertion‑ordered) | yes | labeled data, maps |
| **set** | no (mathematical) | yes | membership tests, unique items |
| **str** | yes | no | text |
| **bytes** | yes | no | raw I/O |
| **bytearray** | yes | yes | mutable binary buffer |

> **Rule of thumb**: choose **immutable** for safety/keys, **mutable** for editing in place.

---

## Micro‑snippets

### Numbers
```py
n = 2**100                 # big int
pi = 3.14159               # float
z = 3 + 4j                 # complex
```

### Strings
```py
name = "Alice"
name.upper()               # "ALICE"
name[0]                    # "A"
len(name)                  # 5
```

### Lists & tuples
```py
xs = [10, 20, 30]
xs.append(40)              # mutate
point = (51.5, -0.12)      # immutable pair (lat, lon)
```

### Dict (hash map)
```py
user = {"id": 7, "name": "Ada"}
user["name"]               # "Ada"
user.get("age", 0)         # default if missing
```

### Sets
```py
seen = set()
seen.add("cs50")
"cs50" in seen             # True
{"a","b"} | {"b","c"}      # union → {'a','b','c'}
```

### Range & iteration
```py
for i in range(3):         # 0,1,2
    ...
list(range(2, 10, 2))      # [2, 4, 6, 8]
```

---

## Performance hints (typical)
- **list append/pop end**: **O(1)** amortized; insert/delete in middle **O(n)**.  
- **dict / set**: average **O(1)** insert/lookup (hashing); watch **collisions** & **load factor**.  
- **tuple/str**: new object on changes; concatenating many strings → use **"".join(...)**.

---

## Patterns to remember
- Use **tuple** for fixed‑size records: `(row, col)` or `(lat, lon)`.  
- Use **dict** for labeled data & configuration; keys must be **hashable** (immutable).  
- Use **set** for **membership** and **uniqueness** checks.  
- Use **bytes/bytearray** for files, sockets, network protocols.  
- Use **range** in loops; it doesn’t allocate a big list.

---

## Gotchas
- **Mutable default args**: don’t do `def f(x, acc=[])`; use `None` then create inside.  
- **Copying**: `xs2 = xs` doesn’t copy; use `xs.copy()` / `list(xs)` / `copy.deepcopy`.  
- **Dict key rules**: keys must be **hashable** (e.g., str, int, tuple of immutables).

---

## Related Concepts
- [[Hello, world — C vs Python (Lecture 6 intro)]] – moving from low‑level to high‑level types.
- [[Concatenation — Python’s + for Strings and Sequences]] – string/list joins.
- [[Named Parameters (Keyword Arguments) — Python]] – many built‑ins accept **keyword args**.
- [[Choosing a Data Structure — Practical Guide]] – when to pick list vs set vs dict.
- [[Hash Tables — Arrays and Linked Lists]] – background for **dict**/**set**.
- [[Tries — Prefix Trees]] – alternative for prefix lookups.
- [[Prime Numbers for Hashing — Why Primes Matter and How to Use Them]] – why hashing spreads keys.
- [[Quotes in Python — Single vs Double (and C contrast)]] – string literal basics.

## See Also
- [Python data model](https://docs.python.org/3/reference/datamodel.html)
- [Built‑in types — docs](https://docs.python.org/3/library/stdtypes.html)
- [Time complexity of operations (wiki)](https://wiki.python.org/moin/TimeComplexity)

## Terms
[[Int]] [[Float]] [[Complex number]] [[String]] [[Bytes]] [[Bytearray]] [[List]] [[Tuple]] [[Range]] [[Dictionary]] [[Set]] [[Frozenset]] [[None]] [[Mutability]] [[Immutability]] [[Sequence]] [[Mapping]] [[Hashable]] [[Membership test]] [[Time complexity]]