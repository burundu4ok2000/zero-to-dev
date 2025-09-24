---
title: for (while) else LOOP in Python
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 13
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 01:46:08–01:46:39
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---


![[Screenshot 2025-09-22 at 20.00.12.png]]

## Summary
Python has a special loop syntax: **for–else** (also works with **while–else**). The `else` block runs **only if the loop finished normally** (no **break**). It’s perfect for the **search pattern**: scan items, **break** when found, otherwise run `else:` to report “not found”.

## Key Points
- `else` here is **not** paired with `if` — it is attached to the **loop**.
- `else` runs when the loop **exhausts** the iterable (or the condition becomes false) **without** hitting `break`.
- If you `break`, the `else` block **skips**.
- Works for both `for` and `while` loops.
- This avoids extra **flag variables** like `found = False`.
- If the iterable is **empty**, the loop body won’t run and `else` **will** run.

## Examples

```python
# Search in a list using for-else
names = ["Yuliia", "David", "John"]
name = input("Name: ")

for n in names:
    if name == n:
        print("Found")
        break
else:
    print("Not found")
```

```python
# Using while-else (same rule: else runs if no break)
i = 0
while i < len(names):
    if names[i] == name:
        print("Found")
        break
    i += 1
else:
    print("Not found")
```

```python
# Nested loops: else belongs to the nearest loop
for row in grid:
    for cell in row:
        if cell == target:
            print("hit"); break
    else:
        # runs only if inner loop didn't break (no target in this row)
        continue
    break  # found somewhere: break outer too
```

## Mental Model
Think of `break` as pulling the **emergency stop** on the loop train. The `else` is the **end‑of‑line** announcement — it plays **only** if the train arrived normally, not if you yanked the brake.

## Common Pitfalls
- Writing:

  ```python
  for x in items:
      if cond(x):
          ...
  else:      # ← this else pairs with for, not the if
      ...
  ```
- Expecting `else` to run after a `continue` — it still runs; only `break` cancels it.
- Breaking the **inner** loop but putting `else` on the **outer** loop by mistake.

## Related Concepts
- [[For vs While in Python]]
- [[Using Module Namespaces — import module vs from module import name]]
- [[Exceptions — try/except, else, finally, raise]]
- [[Lists and Iteration in Python]]
- [[Truncation vs Floor Division vs True Division — f-string Precision]]
- [[Python Syntactic Sugar — Shortcuts from CS50]]
- [[Zero-based Indexing]]
- [[Off-by-one Errors]]

## See Also
- [[CS50x Week 6 — Python (Overview)]]
- [Python docs — for and while statements](https://docs.python.org/3/reference/compound_stmts.html#the-for-statement)
- [Real Python — For-Else in Python](https://realpython.com/python-for-else/)

## Terms
[[for-else]], [[break]], [[continue]], [[loop]], [[search pattern]], [[flag variable]], [[iteration]], [[while-else]]
