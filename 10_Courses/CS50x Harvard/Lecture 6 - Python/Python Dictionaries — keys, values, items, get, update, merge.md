---
title: Python Dictionaries — keys, values, items, get, update, merge
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 22
status: in-progress
difficulty: easy
date: 2025-09-23
timecode: 00:18:50–00:20:55
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

## Summary
A **dictionary** (`dict`) maps **keys** → **values**. Think “label → thing.” Keys must be **hashable** (immutable like `str`, `int`, `tuple`); values can be anything. In modern Python, dicts keep **insertion order**.

## Create
```python
prices = {"cheese": 9, "pepperoni": 10, "vegetable": 11, "buffalo chicken": 12}  # literal
empty  = {}                 # empty dict
also   = dict(cheese=9, pepperoni=10)     # keyword form (keys become strings)
from_pairs = dict([("cheese", 9), ("pepperoni", 10)])   # from (key, value) pairs
by_comp = {x: x*x for x in range(3)}      # dict comprehension
```
> Avoid mutable keys (like `list`, `dict`) — they’re not hashable.

## Read & write
```python
prices["cheese"]        # → 9 (KeyError if missing)
prices.get("bacon", 14) # → 14 (does not insert)
prices["bacon"] = 14    # set / create new key
prices["cheese"] = 8    # update existing
```
Use `get()` when a key **might** be missing; it saves you from a crash.

## Update & merge
```python
prices.update({"veggie": 11, "cheese": 8})  # inplace
a = {"x": 1}; b = {"y": 2, "x": 9}
c = a | b             # Python ≥3.9, returns new dict → {'x': 9, 'y': 2}
a |= b                # inplace merge
```
For nested structures, merge carefully (shallow!).

## Delete
```python
del prices["bacon"]     # KeyError if absent
prices.pop("bacon", None)  # safe remove with default
k, v = prices.popitem()    # remove last inserted (LIFO)
prices.clear()             # empty dict
```

## Iterate (the Pythonic trio)
```python
for key in prices:                # keys
    print(key, prices[key])

for key, value in prices.items(): # pairs
    print(key, value)

for value in prices.values():     # values
    print(value)
```
The **views** `keys()`, `values()`, `items()` are dynamic — they reflect later changes.

## Typical patterns you’ll use a lot
```python
# 1) Counting
from collections import Counter
counts = Counter("banana")       # {'a':3,'b':1,'n':2}
counts.most_common(2)

# 2) Grouping values by key
from collections import defaultdict
groups = defaultdict(list)
for name, score in [("Ann", 9), ("Bob", 7), ("Ann", 8)]:
    groups[name].append(score)   # {'Ann':[9,8], 'Bob':[7]}

# 3) Safe read-modify-write without defaultdict
d = {}
d.setdefault("Ann", []).append(9)

# 4) Sorting by key/value
for k in sorted(prices): 
    print(k, prices[k])
for k, v in sorted(prices.items(), key=lambda kv: kv[1], reverse=True):
    print(k, v)
```

## From the lecture slides (cleaned)
```python
pizzas = { "cheese": 9, "pepperoni": 10, "vegetable": 11, "buffalo chicken": 12 }
pizzas["cheese"] = 8
if pizzas["vegetable"] < 12:
    pass  # do something
pizzas["bacon"] = 14
```
Iteration tip:
```python
for name, price in pizzas.items():
    print(f"{name}: ${price}")
```

## Serialization: JSON <-> dict
```python
import json
data = {"ok": True, "nums": [1,2,3]}
s = json.dumps(data)                  # to JSON string
back = json.loads(s)                  # to Python dict
```
`dict` is your gateway to APIs, config files, and persistence.

## Related Concepts
- [[Python Lists — creation, append/extend, slicing, copy]]
- [[Python Tuples — packing, unpacking, immutability]]
- [[Comprehensions — list/set/dict]]
- [[Enumerate — looping with index]]
- [[Zip — iterate multiple sequences]]
- [[Formatted Strings (f-strings) — Deep Dive]]
- [[Defaultdict and Counter — practical patterns]]

## See Also
- [Built-in Types — dict](https://docs.python.org/3/library/stdtypes.html#mapping-types-dict)
- [collections — defaultdict, Counter](https://docs.python.org/3/library/collections.html)
- [json — encode/decode dicts](https://docs.python.org/3/library/json.html)

## Terms
[[dictionary]], [[mapping]], [[key]], [[value]], [[hashable]], [[view]], [[items()]], [[keys()]], [[values()]], [[get()]], [[setdefault()]], [[update()]], [[merge]], [[popitem()]], [[comprehension]]
