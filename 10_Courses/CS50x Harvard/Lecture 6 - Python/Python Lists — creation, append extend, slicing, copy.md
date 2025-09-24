---
title: Python Lists — creation, append/extend, slicing, copy
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 20
status: in-progress
difficulty: easy
date: 2025-09-23
timecode: 00:12:30–00:13:50
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

![[Screenshot 2025-09-23 at 14.44.32.png]]
![[Screenshot 2025-09-23 at 14.44.40.png]]
![[Screenshot 2025-09-23 at 14.45.39.png]]

## Summary
**List** is Python’s go‑to dynamic sequence (like C’s array, but resizable and multi‑type). You can build it empty, from another iterable, or with literals; then **append**, **extend**, **insert**, **slice**, and more.

## Create
```python
nums = []            # literal
nums = list()        # constructor (same as [])
nums = [1, 2, 3]     # with elements
nums = list(range(5))  # from iterable → [0,1,2,3,4]
chars = list("cs50")   # ['c','s','5','0']
```
> Tip: prefer `[]` for brevity; `list()` shines when converting from an iterable.

## Add elements
```python
nums = [1, 2, 3, 4]

nums.append(5)           # → [1,2,3,4,5]  (add one item)
nums.extend([6, 7])      # → [1,2,3,4,5,6,7]  (merge another iterable)
nums.insert(1, 99)       # → [1,99,2,3,4,5,6,7]
nums += [8, 9]           # in-place concat
```
`append` vs `extend`: `append([6,7])` adds **one list** as an item; `extend([6,7])` adds **two items**.

## Remove elements
```python
nums.remove(99)          # remove first matching value
last = nums.pop()        # remove & return last item
n = nums.pop(0)          # remove & return by index
del nums[1:3]            # delete a slice
nums.clear()             # empty list
```

## Indexing & slicing
```python
a = ["a","b","c","d","e"]
a[0]       # 'a'      (first)
a[-1]      # 'e'      (last)
a[1:4]     # ['b','c','d']           # start..end-1
a[:3]      # ['a','b','c']           # from start
a[3:]      # ['d','e']               # to end
a[::2]     # ['a','c','e']           # step
a[::-1]    # ['e','d','c','b','a']   # reverse copy
```
Trick: `a[len(a):] = [5]` appends via slice assignment (from the slide).

## Copying (shallow) & repetition
```python
b = a.copy()       # shallow copy (new list, same inner refs)
c = a[:]           # slicing also copies
d = list(a)        # constructor copy

grid_bad = [[0]*3]*3      # ⚠ same inner list repeated 3 times
grid_ok  = [[0 for _ in range(3)] for _ in range(3)]
```
Use `copy.deepcopy` for nested structures if you need **independent** copies.

## Membership, length, searching
```python
3 in [1,2,3]        # True
len(a)              # size
[1,2,3].index(2)    # 1 (ValueError if missing)
[1,2,2,3].count(2)  # 2
```

## Sort & reverse
```python
nums = [3,1,2]
nums.sort()                     # in-place → [1,2,3]
sorted(nums, reverse=True)      # new list → [3,2,1]
names = ["alice","Bob","carol"]
names.sort(key=str.lower)       # case-insensitive
nums.reverse()                  # in-place reverse
```

## Comprehensions (one-liners)
```python
squares = [x*x for x in range(10)]
evens = [x for x in range(10) if x % 2 == 0]
```
For memory‑friendly aggregation, use a **generator** inside functions like `sum(x*x for x in range(1_000_000))`.

## Idioms you’ll love
```python
# unpack head/tail
head, *tail = [1,2,3,4]   # head=1, tail=[2,3,4]

# safe get last or default
last = a[-1] if a else None

# deduplicate while keeping order
seen = set(); uniq = [x for x in a if (x not in seen and not seen.add(x))]
```

## Related Concepts
- [[List Comprehensions — fast list initialization in Python]]
- [[Python Conditional Expression (Ternary) — one-liner if/else]]
- [[Python Core Methods — strings, lists, dicts, sets, files]]
- [[Lists and Iteration in Python]]
- [[Comprehensions — list/set/dict]]
- [[Generator Expressions — lazy iteration]]
- [[Dictionaries (dict) — methods and patterns]]
- [[Formatted Strings (f-strings) — Deep Dive]]

## See Also
- [Python docs — Lists](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)
- [Built-in Types — list methods](https://docs.python.org/3/library/stdtypes.html#typesseq-list)
- [copy — shallow vs deep copy](https://docs.python.org/3/library/copy.html)

## Terms
[[list]], [[append]], [[extend]], [[insert]], [[slice]], [[indexing]], [[negative index]], [[shallow copy]], [[deep copy]], [[comprehension]], [[membership test]], [[sort]], [[reverse]]
