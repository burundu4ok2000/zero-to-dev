---
title: Python Built-in Keyword Parameters — Cheat Sheet
lang_tags: "#lang/python"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 28
status: done
difficulty: easy
date: 2025-09-24
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

## At a Glance
Common **keyword parameters** in Python core APIs: **key**/**reverse** (sorting), **default** (fallbacks), **start** (offsets), **sep**/**end**/**file**/**flush** (output), **encoding**/**errors**/**newline** (text I/O), **strict** (zip length checks). Prefer **keyword arguments** for clarity and safety.

| Feature / API                                                    | Keyword(s)                                | Example                                        |     |
| ---------------------------------------------------------------- | ----------------------------------------- | ---------------------------------------------- | --- |
| `sorted(iterable, *, key=None, reverse=False)`                   | **key**, **reverse**                      | `sorted(names, key=str.lower, reverse=True)`   |     |
| `list.sort(*, key=None, reverse=False)`                          | **key**, **reverse**                      | `names.sort(key=len)`                          |     |
| `max/min(iterable, *, key=None, default=...)`                    | **key**, **default**                      | `max(words, key=len, default="")`              |     |
| `enumerate(iterable, start=0)`                                   | **start**                                 | `enumerate(data, start=1)`                     |     |
| `zip(*iterables, strict=False)`                                  | **strict**                                | `zip(a, b, strict=True)`                       |     |
| `print(*objs, sep=' ', end='\n', file=..., flush=False)`         | **sep**, **end**, **file**, **flush**     | `print("a","b", sep=", ", end="!\n")`          |     |
| `open(path, mode='r', encoding=None, errors=None, newline=None)` | **encoding**, **errors**, **newline**     | `open(p, "w", encoding="utf-8", newline="\n")` |     |
| `str(b: bytes, encoding='utf-8', errors='strict')`               | **encoding**, **errors** (bytes→str only) | `str(b, encoding="utf-8")`                     |     |
| `bytes(s: str, encoding='utf-8', errors='strict')`               | **encoding**, **errors** (str→bytes only) | `bytes("hi", encoding="utf-8")`                |     |
| `bytearray(s: str bytes, encoding=..., errors=...)`              | **encoding**, **errors**                  | `bytearray("x", encoding="utf-8")`             |     |
| `dict.get(key, default=None)`                                    | **default**                               | `scores.get("ada", default=0)`                 |     |
| `dict.setdefault(key, default=None)`                             | **default**                               | `scores.setdefault("linus", default=1)`        |     |
| `str.split(sep=None, maxsplit=-1)`                               | **sep**, **maxsplit**                     | `"a,b".split(sep=",", maxsplit=1)`             |     |
| `str.replace(old, new, count=-1)`                                | **count**                                 | `"ha ha".replace("ha", "ho", count=1)`         |     |
|                                                                  |                                           |                                                |     |
## Examples 
```python
# Sorting with a key and reverse
names = ["Ada", "grace", "linus"]
print(sorted(names, key=str.lower, reverse=True))
```

```python
# max/min with key and default
words = []
longest = max(words, default="", key=len)  # default used if empty
```

```python
# enumerate with a custom start
for i, ch in enumerate("abc", start=1):
    print(i, ch)   # 1 a / 2 b / 3 c
```

```python
# zip strict: catch length bugs early (3.10+)
list(zip([1,2], ["a"], strict=True))  # ValueError
```

```python
# print controls
print("a", "b", sep=", ", end="!\n")             # a, b!
print("to file", file=open("out.txt", "w"))       # sends to file
```

```python
# Text I/O: encoding/errors
with open("data.txt", "w", encoding="utf-8", newline="\n") as f:
    f.write("Привет")
```

```python
# str/bytes constructors: encoding only when converting
b = bytes("hi", encoding="utf-8", errors="strict")
s = str(b"caf\xc3\xa9", encoding="utf-8", errors="replace")
```

```python
# dict fallbacks
scores = {"ada": 10}
print(scores.get("grace", default=0))     # 0
print(scores.setdefault("linus", default=1))  # inserts 1
```


## Frequently Used Patterns
- **Sort with multiple keys:** `sorted(items, key=lambda x: (x.category, -x.score))`  
- **Stable secondary sort:** first `sorted(..., key=secondary)`, then `sorted(..., key=primary)` (Python sort is **stable**).  
- **Longest/shortest safely:** `max(xs, key=len, default="")` · `min(xs, key=len, default="")`  
- **Enumerate from 1:** `for i, x in enumerate(xs, start=1): ...`  
- **Zip with guard:** `for a, b in zip(a_list, b_list, strict=True): ...` (3.10+)  
- **Pretty printing:** `print(*rows, sep=" | ", end="\n\n")`  
- **Text I/O:** `with open(p, "w", encoding="utf-8", newline="\n") as f: ...`  
- **Bytes/str convert:** `bytes(s, encoding="utf-8")` · `str(b, encoding="utf-8", errors="replace")`

## Shortcuts
- **Key funcs:** `len`, `str.lower`, `operator.itemgetter("name")`, `operator.attrgetter("size")`  
- **Streams:** `import sys; print("...", file=sys.stderr, flush=True)`  
- **Partial call:** `from functools import partial as P; sort_by_len = P(sorted, key=len)`

## Tips & Gotchas
- **range** takes **no** keyword args.  
- `max/min(default=...)` only with the **iterable** form (not the 2-arg comparator form).  
- `sorted(key=...)` must be a **callable**; returning a comparable value.  
- `str(..., encoding=...)` applies only when the first arg is **bytes**.  
- `zip(strict=True)` requires Python **3.10+**.  
- Sorting is **stable**; you can layer sorts by running them in reverse priority order.  
- Use **encoding='utf-8'** and explicit **newline** on cross‑platform text files.

## Related Concepts
- [[Vocabulary · Mutable vs Immutable]] – why **immutable** strings affect API design
- [[Python String Concatenation Complexity — s + t vs ''.join]] – cost model for **immutable** strings
- [[Mutable Default Arguments in Python]] – defaults vs call time
- [[Python Objects — Beginner Notes]] – **objects**, **methods**, **dunder** hooks
- [[Python — Functions & Arguments]] – **positional‑only** `/` and **keyword‑only** `*`
- [[Python — Sorting patterns]] – idioms with **key**/**reverse**
- [[Python — File I/O Basics]] – `open()`, **encoding**, **newline**
- [[Python — Text vs Bytes]] – `str`/`bytes`/**encoding** rules

## See Also

- [Python Built-in Functions — official docs](https://docs.python.org/3/library/functions.html)
- [PEP 570 — Python Positional-Only Parameters](https://peps.python.org/pep-0570/)
- [PEP 3102 — Keyword-Only Arguments](https://peps.python.org/pep-3102/)

## Terms

[[keyword argument]], [[positional-only parameter]], [[keyword-only parameter]], [[key function]], [[reverse]], [[default]], [[start]], [[sep]], [[end]], [[file object]], [[flush]], [[encoding]], [[errors]], [[newline]], [[strict]], [[callable]], [[operator.itemgetter]], [[stable sort]], [[str]], [[bytes]], [[bytearray]], [[dict]], [[sorted]], [[enumerate]], [[zip]], [[print]], [[open]], [[function signature]]
