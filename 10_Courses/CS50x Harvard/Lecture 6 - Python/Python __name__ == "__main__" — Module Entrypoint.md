---
title: Python __name__ == "__main__" — Module Entrypoint
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 7
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 01:18:10
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

![[Screenshot 2025-09-22 at 17.47.01.png]]

## Summary
`if __name__ == "__main__":` is Python’s **entrypoint guard**. It lets one file act as a **script** (run directly) and also be safely **imported** as a **module** without running **top‑level code** accidentally.

## Why this exists (in simple words)
When you **run** a file, Python sets a special **dunder** (double‑underscore) variable `__name__` to `"__main__"`. When you **import** that same file from somewhere else, `__name__` becomes the file’s **module name** (e.g., `"meow"`). The check runs code **only** in the first case.

## Key Points
- **Script vs module**: the same file can be both. The guard prevents **import side‑effects**.
- **Top‑level code** runs on import. Put demos/CLI calls under the guard.
- Common pattern: define **functions** and **classes** at top level; put `main()` call inside the guard.
- Works great for **unit tests**, **CLI demos**, quick **profiling**, and examples.

## Mental model
Think of the guard as a **door bouncer**: it only lets code through when the file is the **main program**, not when it’s visiting as an **import**.

## Examples

```python
# meow.py
def main():
    meow(3)

def meow(n: int):
    for _ in range(n):
        print("meow")

if __name__ == "__main__":   # entrypoint guard
    main()
```

```python
# other.py
import meow   # safe: does not auto-run meow.main()
# use meow.meow(5) when you want
```

### Quick CLI pattern
```python
# cli.py
import argparse

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", type=int, default=3)
    args = parser.parse_args()
    # real work here

if __name__ == "__main__":
    main()
```

## Common pitfalls
- Forgetting the guard and placing **print()** calls at top level → code runs on import.
- Using `if __name__ is "__main__":` (wrong **identity** operator). Use `==`.
- Hiding logic in the guard. Keep **reusable code** in functions; the guard should just **wire** things.

## Compare to C
C looks for a **main function** by name. Python doesn’t; any callable can be your “main”. The idiom is how we **opt‑in** to an entrypoint.

## Related Concepts

- [[Modules and Imports in Python]] – \smth\ with entrypoints and package structure.
- [[Script vs Module — Python]] – \smth\ contrasting execution contexts.
- [[Command-line Arguments (sys.argv)]] – \smth\ often used inside guarded `main()`.
- [[Unit Tests in Python — Basics]] – \smth\ using the guard to keep tests/demos separate.
- [[Top-level Code Execution]] – \smth\ explains what runs on import.
- [[Functions and Side Effects]] – \smth\ refactor logic out of global scope.
- [[For vs While in Python]] – \smth\ earlier loop control, often called from `main()`.
- [[Error Handling with try/except]] – \smth\ typical pattern inside `main()`.

## See also
- [[CS50x Week 6 — Python (Overview)]]
- [Python Tutorial — Modules](https://docs.python.org/3/tutorial/modules.html)
- [Real Python: if __name__ == "__main__" Idiom](https://realpython.com/if-name-main-python/)

## Terms
[[__name__]], [[__main__]], [[entrypoint guard]], [[module]], [[script]], [[import side-effects]], [[top-level code]], [[dunder]], [[namespace]], [[main()]]
