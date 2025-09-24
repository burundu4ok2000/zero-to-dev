---
title: Using Module Namespaces — import module vs from module import name
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 10
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 01:35:40
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

![[Screenshot 2025-09-22 at 19.13.32.png]]

## Summary
When you `import cs50`, you get a **module** object named `cs50`. To use things from it, you call them with **dot notation** (a **qualified name**): `cs50.get_int(...)`. This keeps your own names separate from the module’s names — a clean **namespace** that prevents **name collisions**. Alternative imports exist, but they trade convenience for a higher risk of clashes.

> Minor fix: functions look like `cs50.get_int(...)`, not `cs50.and()` — the dot just means “from this module”.

## Key Points
- **import module** — safest. Use a **module prefix** every time:  
  ```python
  import cs50
  n = cs50.get_int("Height: ")
  ```
- **from module import name** — pulls a symbol into your current **namespace** (no prefix):  
  ```python
  from cs50 import get_int
  n = get_int("Height: ")
  ```
  Handy, but now `get_int` could **shadow** your own function or collide with another library.
- **Aliases** make names shorter while staying explicit:  
  ```python
  import cs50 as c50           # module alias
  from cs50 import get_int as gi   # symbol alias
  ```
- Avoid `from module import *` — it **pollutes** your namespace and makes code harder to read/debug.
- You can import multiple modules; each has its **own namespace**: `math.sqrt`, `random.randint`, `cs50.get_int`.
- Readability beats brevity. CS50 style prefers **explicit** access (`cs50.get_int`) in beginner code to avoid collisions.

## Mental Model
Think of a module as a labeled **toolbox**. `import cs50` brings the **box** to your desk. `cs50.get_int` means “use the **get_int** tool from the **cs50** box.” Using `from cs50 import get_int` dumps that tool on the desk by itself — less typing, but easier to mix up with other tools named **get_int**.

## Examples

```python
# Safer, explicit
import cs50

while True:
    n = cs50.get_int("Height: ")
    if n > 0:
        break

for _ in range(n):
    print("#")
```

```python
# Convenience import (risk of collision if you also define get_int)
from cs50 import get_int

n = get_int("Height: ")
```

```python
# Aliasing to balance brevity and clarity
import cs50 as c50
n = c50.get_int("Height: ")
```

```python
# Anti-pattern: wildcard import
from cs50 import *
# Now you can't tell where names came from (and you might overwrite them).
```

## Common Pitfalls
- Defining your own `get_int()` after `from cs50 import get_int` → your version **overwrites** it.
- Importing two libraries that both provide `parse()`, `load()`, or similar names → collisions unless you **prefix** or **alias**.
- Forgetting the module prefix after `import module` → `NameError: name 'get_int' is not defined`.

## Related Concepts
- [[Modules and Imports in Python]] – where modules live, how Python finds them (**sys.path**).
- [[Namespace and Scope]] – how **names** resolve (LEGB rule).
- [[Package Structure (__init__.py)]] – organizing many modules.
- [[Virtual Environments (venv)]] – managing third‑party libraries safely.
- [[Exceptions — try/except, else, finally, raise]] – handling errors raised by module calls.
- [[CS50 Library for Python]] – quick reference for common helpers.
- [[Script vs Module — Python]] – running vs importing.
- [[__name__ == "__main__"]] – entrypoint guard for files that can be imported too.

## See Also
- [[CS50x Week 6 — Python (Overview)]]
- [Python tutorial: Modules](https://docs.python.org/3/tutorial/modules.html)
- [PEP 8 — Imports](https://peps.python.org/pep-0008/#imports)

## Terms
[[module]], [[namespace]], [[import]], [[from import]], [[alias]], [[qualified name]], [[dot notation]], [[name collision]], [[shadowing]], [[wildcard import]]
