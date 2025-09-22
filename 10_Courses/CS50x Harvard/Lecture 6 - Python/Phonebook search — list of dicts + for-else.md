---
title: Phonebook search — list of dicts + for-else
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 14
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 01:51:59
source: https://cs50.harvard.edu/x/2025
review_next: ""
---

![[Screenshot 2025-09-22 at 20.28.40.png]]

## Summary
Simple **phonebook** in Python: store people as a **list of dictionaries** and search by **name**. Use **for–else** to report “not found” if the loop finishes without a **break**.

## Code from the slide (cleaned)
```python
people = [
    {"name": "Yuliia", "number": "+1-617-495-1000"},
    {"name": "David",  "number": "+1-617-495-1000"},
    {"name": "John",   "number": "+1-949-468-2750"},
]

name = input("Name: ")
for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found {number}")
        break
else:
    print("Not found")
```

## Upgrades and idioms
### 0) Direct dictionary phonebook (fast & simple)
![[Screenshot 2025-09-22 at 20.33.00.png]]
```python
# keys are names, values are numbers
people = {
    "Yuliia": "+1-617-495-1000",
    "David":  "+1-617-495-1000",
    "John":   "+1-949-468-2750",
}

name = input("Name: ").strip()

if name in people:                 # O(1) average membership test
    print(f"Number: {people[name]}")
else:
    print("Not found")
```

> Tip: you can write `people.get(name)` to fetch or return `None` (or a default):  
> `print(people.get(name, "Not found"))`


### 1) Case‑insensitive compare (trim spaces)
```python
query = input("Name: ").strip().lower()

for p in people:
    if p["name"].lower() == query:
        print(f"Found {p['number']}")
        break
else:
    print("Not found")
```

### 2) One‑liner lookup with `next()`
```python
query = input("Name: ").strip()
hit = next((p for p in people if p["name"] == query), None)
print(f"Found {hit['number']}" if hit else "Not found")
```

### 3) O(1) lookup via mapping (best for many queries)
```python
# Build an index once
by_name = {p["name"].lower(): p["number"] for p in people}

query = input("Name: ").strip().lower()
if query in by_name:                 # membership test is O(1) average
    print(f"Found {by_name[query]}")
else:
    print("Not found")
```

## Why this matters
- **Dictionaries** give **constant‑time** lookups by key — perfect for phonebooks, indexes, caches.
- A **list of dicts** is flexible and human‑readable; you can later convert to a **dict of dicts** or a **CSV/JSON**.
- **for–else** removes the need for extra **found flags** and keeps search code tidy.

## Edge cases
- Duplicate names? Use a **dict** of **lists** or include a unique **id**.
- Non‑ASCII names: compare with a **normalized** form (e.g., `casefold()`).
- Missing keys: use `p.get("number")` or validate input structure before searching.

## Related Concepts
- [[for-else — loop else for search pattern in Python]]
- [[Dictionaries (dict) — methods and patterns]]
- [[Formatted Strings (f-strings) — Deep Dive]]
- [[Lists and Iteration in Python]]
- [[Input Validation vs Exception Handling]]
- [[Modules and Imports in Python]]
- [[Python Syntactic Sugar — Shortcuts from CS50]]
- [[Truncation vs Floor Division vs True Division — f-string Precision]]

## See Also
- [Python tutorial — Data structures (dicts)](https://docs.python.org/3/tutorial/datastructures.html#dictionaries)
- [Mapping types — dict](https://docs.python.org/3/library/stdtypes.html#mapping-types-dict)
- [PEP 572 `:=` walrus operator](https://peps.python.org/pep-0572/) — handy in comprehensions/filters

## Terms
[[dictionary]], [[list of dicts]], [[key]], [[value]], [[membership test]], [[linear search]], [[hash table]], [[index]], [[normalization]], [[next()]]
