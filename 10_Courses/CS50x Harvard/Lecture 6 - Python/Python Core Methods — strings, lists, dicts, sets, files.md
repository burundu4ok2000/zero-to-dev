---
title: "Python Core Methods — strings, lists, dicts, sets, files"
lang_tags: "#lang/python"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 12
status: "in-progress"
difficulty: "easy"
date: "2025-09-22"
timecode: ""
source: "https://docs.python.org/3/"
review_next: ""
---

## Summary
Here’s a compact **cheat‑sheet** of everyday Python **methods** grouped by core **types**. Use these as your go‑to toolbox when solving CS50 tasks and beyond. Examples use simple, readable code.

---

## Strings (`str`) — text
```python
s = "  cs50,Python  "
s.lower()            # '  cs50,python  '
s.upper()            # '  CS50,PYTHON  '
s.strip()            # 'cs50,Python'          # trim spaces (both ends)
s.replace("Python", "C")  # '  cs50,C  '
s.find("cs")         # 2  (−1 if not found)
s.split(",")         # ['  cs50', 'Python  ']
" | ".join(["A", "B"])    # 'A | B'   (join is a str **method**)
s.startswith("  c")  # True
s.endswith("on  ")   # True
"42".isdigit()       # True
"abc".isalpha()      # True
"cs{n}".format(n=50) # 'cs50' (prefer **f-string**: f"cs{50}")
```
Notes: `join` lives on the **separator** string. `strip/lstrip/rstrip` trim whitespace or given chars.

---

## Lists (`list`) — ordered, **mutable**
```python
a = [3, 1, 2]
a.append(4)          # [3,1,2,4]
a.extend([5, 6])     # [3,1,2,4,5,6]
a.insert(1, 99)      # [3,99,1,2,4,5,6]
a.remove(99)         # first matching value removed
a.pop()              # 6 (and list shrinks)
a.index(4)           # 4's position
a.count(3)           # occurrences of 3
a.sort()             # in‑place sort -> [1,2,3,4,5]
a.sort(reverse=True) # descending
sorted(a)            # new sorted **copy**
a.reverse()          # in‑place reverse
a.copy()             # shallow **copy**
a.clear()            # []
```
Gotcha: `b = a` does **not** copy; both names point to the same list.

---

## Dictionaries (`dict`) — key/value **mapping**
```python
d = {"name": "Alice", "age": 20}
d.get("age", 0)      # 20 (or default 0)
d.setdefault("city", "NY")  # insert if missing
d.update({"age": 21})       # merge/overwrite
d.pop("age")         # remove key, return value
d.popitem()          # remove & return last inserted pair
d.keys()             # view of keys
d.values()           # view of values
d.items()            # view of (key, value) pairs
d.clear()
```
Tip: prefer `get` over `in`+index for cleaner error‑free lookups.

---

## Sets (`set`) — unique items, math ops
```python
s = {1, 2, 3}
s.add(4); s.remove(2)         # remove KeyError if missing
s.discard(99)                 # safe remove (no error)
s.update({3, 5})              # union into self
s.pop()                       # remove & return an arbitrary item
s.clear()

a = {1,2,3}; b = {3,4}
a.union(b)                    # {1,2,3,4}
a.intersection(b)             # {3}
a.difference(b)               # {1,2}
a.symmetric_difference(b)     # {1,2,4}
a.issubset(b); a.issuperset(b)
```
Remember: sets are **unordered**; no indexing.

---

## Tuples (`tuple`) — ordered, **immutable**
```python
t = (10, 20, 20)
t.count(20)        # 2
t.index(20)        # 1
```
Use tuples for fixed records or as safe dictionary keys.

---

## Files (`with open(...) as f:`)
```python
with open("data.txt", "w") as f:
    f.write("hello\n")
with open("data.txt") as f:
    f.read()        # entire file as str
    f.readline()    # one line (keeps '\n')
    f.readlines()   # list of lines
    f.seek(0); f.tell()
```
Use the **context manager** (`with ...`) so files close automatically.

---

## Pathlib (`pathlib.Path`) — modern file paths
```python
from pathlib import Path
p = Path("logs") / "app.log"      # join
p.parent.exists()                 # does folder exist?
p.is_file(); p.is_dir()
p.mkdir(parents=True, exist_ok=True)
p.write_text("hi")
txt = p.read_text()
for f in Path(".").glob("*.py"):
    print(f.name)
```
Prefer **Path** over old `os.path` for clarity and safety.

---

## Numbers (quick picks)
```python
(5).bit_length()    # bits needed → 3
(3.0).is_integer()  # True
abs(-7)             # 7  (function, not method)
round(3.14159, 2)   # 3.14 (display rounding)
```
Note: some are **built‑ins** (functions), not methods, but useful alongside methods.

---

## Related Concepts

- [[Python Syntactic Sugar — Shortcuts from CS50]] – handy one‑liners that wrap these **methods**.
- [[Using Module Namespaces — import module vs from module import name]] – where methods live and how to access them.
- [[Exceptions — try/except, else, finally, raise]] – handle method errors like **KeyError** or **IOError**.
- [[Truncation vs Floor Division vs True Division — f-string Precision]] – numeric formatting and division behavior.
- [[Lists and Iteration in Python]] – looping patterns around list **methods**.
- [[Formatted Strings (f-strings) — Deep Dive]] – clean output for values returned by methods.
- [[Modules and Imports in Python]] – organize code that defines your **own methods**.
- [[Python — range() deep dive]] – often paired with list/string operations.

## See Also
- [Python docs — Built-in Types](https://docs.python.org/3/library/stdtypes.html)
- [Python docs — dict, set, list methods](https://docs.python.org/3/tutorial/datastructures.html)
- [Python docs — pathlib](https://docs.python.org/3/library/pathlib.html)

## Terms
[[Method]], [[Object]], [[Mutable]], [[Immutable]], [[In-place]], [[Shallow copy]], [[Mapping]], [[Sequence]], [[View]], [[Context manager]]
