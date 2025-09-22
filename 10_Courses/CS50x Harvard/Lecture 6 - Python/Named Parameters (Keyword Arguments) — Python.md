---
title: "Named Parameters (Keyword Arguments) — Python"
lang_tags: "#lang/python"
type_tags: "#type/termin"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 03
status: "in-progress"
difficulty: "easy"
date: "2025-09-22"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/6/"
review_next: ""
---
![[Screenshot 2025-09-22 at 15.47.38.png]]

![[Screenshot 2025-09-22 at 15.55.14.png]]
## Definition
**Named parameters** (aka **keyword arguments**) let you pass arguments by **name** instead of position. This boosts **readability** and avoids mistakes when functions have many parameters or **defaults**.

**Python terms**: **positional args**, **keyword args**, **defaults**, **keyword‑only args**, `*args`, `**kwargs`.

## Screenshot
[named_parameters_screenshot](sandbox:/mnt/data/Screenshot%202025-09-22%20at%2015.47.38.png)

## Syntax
```py
def greet(name, time="day"):
    print(f"Good {time}, {name}!")

greet("Alice")                        # positional → Good day, Alice!
greet(name="Alice", time="evening")   # named → order doesn’t matter
greet(time="morning", name="Bob")     # named → still OK
```

### Keyword‑only parameters
```py
def scale(value, *, factor=1.0):
    return value * factor

scale(10, factor=2)   # OK
scale(10, 2)          # ❌ TypeError: factor must be named
```

### Collecting keywords dynamically
```py
def connect(**opts):
    # opts is a dict of all keyword args
    print(opts)

connect(host="db", port=5432, ssl=True)
# {'host': 'db', 'port': 5432, 'ssl': True}
```

### Unpacking a dict into named params
```py
params = {"sep": " | ", "end": " \n"}
print("a", "b", **params)   # uses sep and end by name
```

## Rules & Gotchas
- **Order**: positional args first, then keyword args.  
  `fn(1, 2, x=3)` ✅  but `fn(x=3, 1, 2)` ❌  
- **No duplicates**: you can’t pass the **same** parameter twice (positional + named).  
- **Names must match** function parameter names exactly.  
- **Defaults** are evaluated once, at def time (avoid mutable defaults like `[]`).  
- Many built‑ins use named params: `print(sep=..., end=...)`, `sorted(key=..., reverse=...)`.

## Why it matters (CS50 angle)
Compared to C’s positional parameters, Python’s **named arguments** improve **clarity** and **safety** with almost **zero boilerplate**. They’re used everywhere in real codebases and libraries.

## Micro‑examples
```py
# Readable calls
send_email(to="you@example.com", subject="Hi", body="...")

# Clear overloading
open("data.txt", mode="w", encoding="utf-8")

# Safer long parameter lists
plot(x=data, y=labels, color="red", linewidth=2)
```

## Related Concepts
- [[Hello, world — C vs Python]] – compilation vs interpretation mindset.
- [[Concatenation — Python’s + for Strings and Sequences]] – string operations you pass into functions.
- [[Choosing a Data Structure — Practical Guide]] – APIs often expose **keyword** flags.
- [[Hash Tables — Arrays and Linked Lists]] – Python’s dict consumes `**kwargs` (a **hash map**).
- [[Prime Numbers for Hashing — Why Primes Matter and How to Use Them]] – hashing background for dicts.
- [[Queues — Enqueue and Dequeue]] – function params to control behavior.
- [[Binary-Search-Trees-Basics-and-Operations]] – alternative ordered lookups (contrast with dict/kwargs).
- [[Signed vs Unsigned Integers in C — Ranges and Memory]] – shows how Python hides low‑level details.

## See Also
- [Python Tutorial — Defining functions (keyword arguments)](https://docs.python.org/3/tutorial/controlflow.html#keyword-arguments)
- [PEP 3102 — Keyword‑Only Arguments](https://peps.python.org/pep-3102/)
- [Built‑in `print()` parameters](https://docs.python.org/3/library/functions.html#print)

## Terms
[[Keyword argument]] [[Positional argument]] [[Default parameter]] [[Keyword‑only argument]] [[*args]] [[**kwargs]] [[Unpacking]] [[Function signature]] [[Mutable default]]
