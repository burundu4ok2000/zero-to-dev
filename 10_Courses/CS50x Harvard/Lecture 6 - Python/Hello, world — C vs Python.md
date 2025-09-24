---
title: Hello, world — C vs Python
lang_tags: "#lang/c #lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 1
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: —
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---
---
![[Screenshot 2025-09-22 at 14.25.49.png]]

---

## Summary
**Python** prints *hello, world* in **one line** and runs **without a manual compile step**.  
**C** needs a **compiler**, a **main** function, **headers**, and produces an **executable** you then run.

---

## Very simple
- In **C**, you first **build** (compile) your program, then **run** it.  
- In **Python**, you just **run** the script. The interpreter handles the rest.

---

## Side‑by‑side

### C (compiled)
```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

**Build & run**
```bash
clang hello.c -o hello
./hello
```

### Python (interpreted)
```py
print("hello, world")
```

**Run**
```bash
python hello.py
```

---

## What’s different (fast checklist)
- **Compile step**: C uses a **compiler** to create an **executable**; Python uses an **interpreter** (it compiles to **bytecode** internally, but you don’t manage it).  
- **Boilerplate**: 
  C requires **#include**,  **main()** and **;** 
 Python doesn’t.  
- **Typing**: C is **static** (types at compile time). Python is **dynamic** (types at run time).  
- **Speed vs speed‑to‑write**: C often runs faster; Python is faster to write and iterate.  
- **Portability**: Python scripts run anywhere there’s a Python **runtime**; C executables are built per **platform**.

---

## ASCII mental model
```
C:   hello.c ──[compiler]──► hello (binary) ──► run
PY:  hello.py ──[interpreter]───────────────► run
```

---

## Why this matters (CS50 angle)
Week 6 shifts from **low‑level C** (manual memory, compilation) to **high‑level Python** (rich built‑ins, quick iteration). You’ll reuse the same **algorithms** but write far less code.

---

## Related Concepts

- [[Stacks — Push and Pop]] – used under the hood by runtimes.
- [[Queues — Enqueue and Dequeue]] – task pipelines; easy to demo in Python.
- [[Hash Tables — Arrays and Linked Lists]] – Python’s **dict** uses hashing.
- [[Tries — Prefix Trees]] – algorithmic contrast to hashing for strings.
- [[Binary-Search-Trees-Basics-and-Operations]] – ordered structures vs hashing.
- [[Choosing a Data Structure — Practical Guide]] – when to pick which.
- [[Signed vs Unsigned Integers in C — Ranges and Memory]] – C‑specific detail you won’t juggle in Python.
- [[Arrow Operator and Struct Pointers in C]] – why Python feels simpler.

---

## See Also
- [CS50x — Week 6 (Python)](https://cs50.harvard.edu/x/2025/weeks/6/)
- [Python `print()` docs](https://docs.python.org/3/library/functions.html#print)
- [Compiled vs. interpreted languages (Wikipedia)](https://en.wikipedia.org/wiki/Interpreted_language)

---

## Terms
[[Compiler]], [[Interpreter]], [[Bytecode]], [[Runtime]], [[Script]], [[Executable]], [[Shebang]], [[Static typing]], [[Dynamic typing]], [[Print]]
