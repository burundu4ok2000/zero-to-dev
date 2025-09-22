---
title: Loops in Python — for + range()
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 6
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 01:03:57
source: https://cs50.harvard.edu/x/2025
review_next: ""
---

---

![[Screenshot 2025-09-22 at 17.10.09.png]]

---

## Summary
A **loop** repeats code. In Python, **for** with **range()** is the clean way to “repeat N times”, just like Scratch’s **repeat** block.

## Very simple

> Explain {for with range} in simple terms that a 5-year-old would understand:
    1. Imagine a row of boxes with numbers 0, 1, 2.
    2. We point to each box one by one.
    3. Each time we point, we say **meow** — that’s the loop doing its job.

## Key Points
- **range(n)** produces 0..n-1 — **zero-based** and **exclusive** of n.
- **for i in range(n):** runs the loop body **n** times; **i** is the **counter** for the current **iteration**.
- You can set **start**, **stop**, **step**: `range(start, stop, step)`.
- If you don’t need the loop variable, use `_` by convention.
- Classic pitfall: **off-by-one** errors — remember `range(3)` gives 0,1,2 (three iterations).
- Printing is slow; for big outputs prefer building a **string** once.

## Details
Python’s **range()** is a **lazy** sequence of integers — it doesn’t allocate a full list; it generates values on demand. That keeps memory low and loops fast for large counts. The **for** loop reads each value from **range()** and runs the block (the **body**) once per value.

## Examples

```python
# 1) Repeat 3 times
for i in range(3):
    print("meow")
````

```python
# 2) Start/stop/step
for i in range(2, 8, 2):   # 2, 4, 6
    print(i)
```

```python
# 3) Counter not used
for _ in range(5):
    do_something()
```

```python
# 4) Avoiding slow many prints
print("meow\n" * 3, end="")  # build once, print once
```

```python
# 5) Summation pattern
total = 0
for x in range(1, 101):   # 1..100
    total += x
print(total)
```

## **Why It Matters**

Most real programs need repetition: reading many inputs, retrying network calls, iterating over data. **for + range()** is the simplest reliable building block before you move on to looping over **lists**, **strings**, and other **iterables**.

## Questions

- ❓When to use **for + range()** vs a **while** loop?
    
- ❓Why does `range(n)` exclude `n` and how does that prevent errors?
    
- ❓What changes when looping over a **list** directly vs `range(len(list))`?
    

## Related Concepts

- [[For vs While in Python]] – \smth\ with this note by comparing control flow and typical use cases.
    
- [[Zero-based Indexing]] – \smth\ with `range()` because indices start at 0.
    
- [[Off-by-one Errors]] – \smth\ with loops; common bug when setting bounds.
    
- [[Python — print() basics]] – \smth\ with output inside loops.
    
- [[Python — range() deep dive]] – \smth\ expanding on start/stop/step and memory.
    
- [[Lists and Iteration in Python]] – \smth\ using `for item in list` instead of counters.
    
- [[String Multiplication and Join]] – \smth\ for building output efficiently.
    
- [[Scratch vs Python — Loops]] – \smth\ mapping repeat blocks to `for`.
    

## See also

- [[CS50x Week 6 — Python (Overview)]]
    
- [Python tutorial: for statements](https://docs.python.org/3/tutorial/controlflow.html#for-statements)
    
- [Python docs: range()](https://docs.python.org/3/library/stdtypes.html#range)
    

## Terms

[[loop]], [[for-loop]], [[range()]], [[iteration]], [[counter]], [[zero-based indexing]], [[off-by-one error]], [[string]]

