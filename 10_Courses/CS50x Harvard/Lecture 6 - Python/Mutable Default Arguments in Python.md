---
title: "Mutable Default Arguments in Python"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 26
status: "done"
difficulty: "easy"
date: "2025-09-24"
timecode: ""
source: "CS50x Week 6 (Python)"
review_next: ""
---

## One Liner
**Mutable defaults** are evaluated **once at definition time**, then **reused** across calls. Don’t use **list/dict/set** as default values unless you explicitly want to **share state**.

## Explanation
When you write a function like:
```python
def f(x=[]):
    x.append(1)
    return x
```
- Python creates the default **once** when it defines `f`, producing a single list object.  
- Every call without `x` **reuses the same list**.

### What happens
```python
print(f())  # [1]
print(f())  # [1, 1]
print(f())  # [1, 1, 1]
```
That’s surprising at first: the list **keeps growing** because it’s the **same object**.

### Why
Defaults are evaluated at **def time**, not at **call time**. **Immutable** defaults (like **None**, numbers, strings, tuples) are fine. **Mutable** defaults (lists, dicts, sets) can create hidden shared state and bugs.

## Correct Pattern
Use **None** as a sentinel and create a **new object per call**:
```python
def f(x=None):
    if x is None:
        x = []   # new list every call
    x.append(1)
    return x

print(f())  # [1]
print(f())  # [1]
```

## Rule of Thumb
- **Safe**: `def g(n=5)`, `def h(msg="hi")`, `def p(opts=None)`  
- **Dangerous**: `def g(xs=[])`, `def h(cfg={})`, `def p(seen=set())`

## Examples 
```python
# Sharing state accidentally
def append_item(item, bucket=[]):
    bucket.append(item)
    return bucket

print(append_item("a"))  # ['a']
print(append_item("b"))  # ['a', 'b']  ← same list reused
```

```python
# Fixed version
def append_item(item, bucket=None):
    if bucket is None:
        bucket = []
    bucket.append(item)
    return bucket

print(append_item("a"))  # ['a']
print(append_item("b"))  # ['b']
```

## Related Concepts
- [[Vocabulary · Mutable vs Immutable]] – **mutability** rules and `+=` behavior
- [[Python String Concatenation Complexity — s + t vs ''.join]] – **immutability** → **copy** cost
- [[Python Objects — Beginner Notes]] – **object**, **attribute**, **dunder** basics
- [[Python Syntax — Running, Style, Shebang]] – quick REPL tests for this pitfall
- [[Python — Functions & Arguments]] – defaults, `*args`, `**kwargs`
- [[Identity vs Equality (id vs ==) in Python]] – object **identity** vs value **equality**
- [[Immutability & Hashability]] – why some types are safe as **dict** keys
- [[Python — Lists vs Tuples]] – choose **mutable** vs **immutable** sequences

## See Also
- [Default Parameter Values (Python tutorial)](https://docs.python.org/3/tutorial/controlflow.html#default-argument-values)
- [Why default arguments are evaluated once](https://docs.python.org/3/faq/programming.html#why-are-default-values-shared-between-objects)
- [Data model — function objects](https://docs.python.org/3/reference/datamodel.html#function-objects)

## Terms
[[Mutable default argument]], [[Default argument]], [[Definition time]], [[Call time]], [[Sentinel None]], [[None]], [[is operator]], [[Equality (==)]], [[Identity]], [[Shared state]], [[Side effect]], [[Immutability]], [[Mutability]], [[Function signature]], [[Keyword argument]], [[Positional argument]], [[list]], [[dict]], [[set]], [[tuple]], [[defaults]], [[default_factory]], [[Optional (type hint)]], [[Type hint]]