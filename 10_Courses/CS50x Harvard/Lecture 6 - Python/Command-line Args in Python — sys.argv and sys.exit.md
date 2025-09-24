---
title: Command-line Args in Python — sys.argv and sys.exit
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 15
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 01:57:00–02:00:30
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

## Summary
This note shows how to read **command‑line arguments** with `sys.argv` and how to return **exit codes** using `sys.exit()`. Two import styles appear in CS50:
- `from sys import argv` (convenient name)
- `import sys` then use `sys.argv` and `sys.exit()` (more explicit, avoids name collisions)

## Key Points
- `argv` is a **list** of strings; index 0 is the **script name**.
- Check `len(sys.argv)` to validate arguments.
- Return a **non‑zero** exit code (e.g., `1`) to signal **error**, `0` for **success**.
- Prefer `import sys` in teaching code so it’s clear which names come from the module.
- For bigger CLIs, switch to [[argparse]] for flags like `-n 3`.

## Code — minimal greet
```python
from sys import argv               # style 1
if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")
```
```python
import sys                         # style 2 (explicit)
if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)                    # error
print(f"hello, {sys.argv[1]}")
sys.exit(0)                        # success
```

## Exit status in shell
- After running a program, shells expose the status in `$?` (bash/zsh).  
  Example:
  ```text
  $ python exit.py David
  hello, David
  $ echo $?
  0
  ```
- A failing run prints an error and typically exits with `1`:
  ```text
  $ python exit.py
  Missing command-line argument
  $ echo $?
  1
  ```

## Tips & Pitfalls
- Don’t index `argv[1]` without checking length — it raises [[IndexError]].
- Keep validation near the top of `main()`; `return` or `sys.exit()` early.
- Use `sys.exit("message")` to both print the message (to stderr) and exit with code `1`.
- For multiple names, join: `print("hello, " + " ".join(sys.argv[1:]))`.
- Mixing `from sys import argv` with `import sys` is fine, but choose one style per file.

## Related Concepts
- [[Using Module Namespaces — import module vs from module import name]]
- [[__name__ == "__main__"]]
- [[Exceptions — try/except, else, finally, raise]]
- [[Formatted Strings (f-strings) — Deep Dive]]
- [[Input Validation vs Exception Handling]]
- [[Python Syntactic Sugar — Shortcuts from CS50]]
- [[for-else — loop else for search pattern in Python]]
- [[Modules and Imports in Python]]

## See Also
- [Python docs — sys module](https://docs.python.org/3/library/sys.html)
- [Python docs — argparse](https://docs.python.org/3/library/argparse.html)
- [POSIX — exit status](https://pubs.opengroup.org/onlinepubs/9699919799/functions/exit.html)

## Terms
[[command-line argument]], [[argv]], [[exit code]], [[sys module]], [[stderr]], [[IndexError]], [[validation]], [[argparse]], [[shell]], [[status code]]
