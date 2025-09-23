---
title: "Python Syntax — Running, Style, Shebang"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 25
status: "in-progress"
difficulty: "easy"
date: "2025-09-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/6/"
review_next: ""
---

---

---

## Summary
How to **run** Python, why **style/indentation** matters, and how to make a script **executable** with a **shebang**. Simple rules you’ll use every day.

## Very simple
Write code in a `.py` file and run it with the **interpreter**. Python executes your file **top to bottom**. Clean **indentation** defines blocks. Add a **shebang** and **executable bit** to run a script directly from the shell.

## Key Points
- Use `.py` files for programs; the **REPL** (interactive prompt) is fine for tiny tests.
- Run a file from the terminal:
  ```bash
  python3 <file.py>
  ```
- Python executes the file **top → bottom**. No manual `main()` required.
- **Style is crucial**: tabs vs spaces, consistent **indentation**, and readable code (see **PEP 8**).
- Python uses **indentation** to mark **blocks** (no `{}`); braces are for **dict** literals.
- Make a script directly runnable with a **shebang** (first line) and permissions:
  ```bash
  #!/usr/bin/env python3
  chmod a+x <file.py>
  ./<file.py>
  ```

## Details
- **Interpreter & REPL**: The interpreter loads and executes your code; the **REPL** lets you try one-liners quickly. Great for probing functions, types, or errors.
- **Execution order**: Imports and top-level code run first, then any functions you call. Guard long-running code with `if __name__ == "__main__":` to avoid executing on import.
- **Indentation**: One **indent level** is typically 4 spaces. Tabs/spaces mixing is a bug magnet—pick **spaces** and let the editor handle it.
- **Blocks**: A trailing colon (`:`) starts a new block (after `if`, `for`, `while`, `def`, `class`, etc.). The following indented lines belong to that block.
- **Shebang**: `#!/usr/bin/env python3` asks the OS to find `python3` on `PATH`. Keep it on **line 1** with **no leading spaces**.
- **Permissions**: `chmod a+x file.py` sets the **executable bit** so the OS can launch it like a program.
- **Style**: Follow **PEP 8** for naming, line length, imports, blank lines. Tools like **black**, **flake8**, and **ruff** help automate this.

## Examples
```python
# hello.py
print("hello, world")
```

```bash
# run with interpreter
python3 hello.py
```

```python
#!/usr/bin/env python3
# run_me.py — direct execution via shebang
def greet(name: str) -> None:
    print(f"hi, {{name}}")

if __name__ == "__main__":
    greet("CS50")
```
```bash
chmod a+x run_me.py
./run_me.py
```

```python
# indentation creates blocks
for i in range(3):
    if i % 2 == 0:
        print("even", i)
    else:
        print("odd", i)
```

## Why It Matters
You’ll switch between **REPL** and files constantly. Getting **execution**, **indentation**, and the **shebang** right prevents silly bugs and makes scripts behave like first-class CLI tools.

## Questions
- When should I keep code under `if __name__ == "__main__":`?
- Do I want a script (shebang + `chmod`) or just `python3 file.py`?
- Is my editor enforcing **spaces** and 4-space **indentation**?

## Related Concepts
- [[Python — Files & Modules]] – how imports work; `__name__` and module boundaries
- [[Python — CLI Scripts & Args]] – build small command-line tools with `argparse`
- [[Python — Errors & Tracebacks]] – reading stack traces during execution
- [[Python — Virtual Environments]] – choosing interpreter and dependencies
- [[Python — Style Guide (PEP 8)]] – conventions for names, layout, imports
- [[Python — REPL Tricks]] – quick tests, `dir()`, `_` last value
- [[Unix Permissions Basics]] – `chmod`, executable bit, `PATH`
- [[Shebang & Env]] – portability of `#!/usr/bin/env python3`

## See also
- [Python: Command line and environment](https://docs.python.org/3/using/cmdline.html)
- [Indentation — Python Language Reference](https://docs.python.org/3/reference/lexical_analysis.html#indentation)
- [PEP 8 — Style Guide for Python Code](https://peps.python.org/pep-0008/)
