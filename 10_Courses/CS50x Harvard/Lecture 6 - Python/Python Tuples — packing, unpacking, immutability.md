---
title: "Python Tuples — packing, unpacking, immutability"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 21
status: "in-progress"
difficulty: "easy"
date: "2025-09-23"
timecode: "00:14:50–00:17:45"
source: "https://cs50.harvard.edu/x/2025"
review_next: ""
---
![[Screenshot 2025-09-23 at 14.52.43.png]]

![[Screenshot 2025-09-23 at 14.59.29.png]]
## Summary
A **tuple** is an **ordered**, **immutable** sequence. Think “lightweight record”: great for pairing related values (like a name and a year) that shouldn’t change. Tuples are iterable, support indexing/slicing, and can be used as **dict keys** and **set** members (they’re **hashable** if their contents are hashable).

## Creating tuples
```python
t = (1, 2, 3)
u = 1, 2, 3            # parentheses optional
single = (42,)         # trailing comma makes a 1‑tuple
empty = ()

tuple_from_list = tuple([1, 2, 3])
list_from_tuple  = list((1, 2, 3))
```

## Access & basics
```python
t[0], t[-1]            # first, last
len(t)                 # length
t.count(2), t.index(3) # count value; find first index
t[1:3]                 # slicing works too
```

## Packing & unpacking (the magic)
```python
name, year = ("George Washington", 1789)
x, y = y, x                                # swap two variables
head, *middle, tail = (1, 2, 3, 4, 5)     # star‑unpack
```
> In loops you can unpack on the fly:
```python
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809),
]

for prez, year in presidents:
    print(f"In {year}, {prez} took office")
```

## Common Python patterns
```python
# 1) Return multiple values
def minmax(seq):
    return min(seq), max(seq)

mn, mx = minmax([3, 1, 4])

# 2) Iterate with index
for i, item in enumerate(["a", "b", "c"], start=1):
    print(i, item)

# 3) Walk two sequences in parallel
for a, b in zip([1, 2, 3], [10, 20, 30]):
    print(a, b)

# 4) Use tuples as dict keys / set members
distances = {("NYC", "LA"): 2451}
visited = {(0, 0), (1, 2)}
```

## Immutability notes
- You **cannot** reassign an element: `t[0] = 9` → `TypeError`.
- A tuple can contain **mutable** objects:
  ```python
  t = ([],)
  t[0].append(1)     # allowed; the list inside changed
  ```
  The tuple’s identity is fixed; contained objects may still mutate.

## Formatting with tuples
```python
prez, year = ("James Madison", 1809)
print("In {1}, {0} took office".format(prez, year))  # from slide
print(f"In {year}, {prez} took office")              # modern f‑string
```

## When to use tuple vs list
- Choose **tuple** for fixed‑size, read‑only groupings (coordinates, database rows, function returns).
- Choose **list** when you will add/remove/reorder items.

## Related Concepts
- [[Python Lists — creation, append/extend, slicing, copy]]
- [[List Comprehensions — fast list initialization in Python]]
- [[Python Conditional Expression (Ternary) — one-liner if/else]]
- [[Enumerate — looping with index]]
- [[Zip — iterate multiple sequences]]
- [[Dictionaries (dict) — methods and patterns]]
- [[Formatted Strings (f-strings) — Deep Dive]]
- [[Unpacking and Star Expressions in Python]]

## See Also
- [Data model — sequence types](https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range)
- [Tuples (tutorial)](https://docs.python.org/3/tutorial/datastructures.html#tuples-and-sequences)
- [collections.namedtuple](https://docs.python.org/3/library/collections.html#collections.namedtuple)

## Terms
[[tuple]], [[immutable]], [[packing]], [[unpacking]], [[star-unpack]], [[hashable]], [[dict key]], [[enumerate]], [[zip]], [[namedtuple]]
