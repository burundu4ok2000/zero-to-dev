---
title: Exceptions — try/except, else, finally, raise
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 9
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 01:28:11
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

![[Screenshot 2025-09-22 at 18.41.43.png]]

![[Screenshot 2025-09-22 at 18.44.38.png]]

## Summary
An **exception** is Python’s way to say “something went wrong” **without** returning a weird value. You **raise** an exception where the error happens, and you **catch** it with **try/except** so your program can **handle** the situation instead of crashing.

## Key Points
- **try/except**: Put risky code under **try**. Handle specific errors with **except** blocks (e.g., **ValueError**, **ZeroDivisionError**).
- **else**: Runs **only if no exception** happened in the try block — great for the “happy path” work.
- **finally**: Runs **always** (success or failure) — perfect for cleanup like closing files or network sockets.
- **raise**: Create/forward an exception yourself: `raise ValueError("x must be > 0")`.
- **EAFP** (“**E**asier to **A**sk **F**orgiveness than **P**ermission”): try the action and handle exceptions — the Pythonic style.
- **LBYL** (“**L**ook **B**efore **Y**ou **L**eap”): pre-check everything with **if** conditions. In Python, prefer **EAFP** when it’s safe.
- **Traceback** shows the **call stack** where the exception traveled. Read from bottom to top: last frame is where it blew up.

## Patterns

```python
# 1) Safe input + division
try:
    x = int(input("x: "))
    y = int(input("y: "))
    print(x / y)
except ValueError:
    print("x and y must be integers")
except ZeroDivisionError:
    print("cannot divide by zero")
else:
    print("division ok")       # runs only if no exception above
finally:
    print("done")              # always runs
```

```python
# 2) Raising your own exception (guarding invariants)
def percent(p: float) -> float:
    if not (0.0 <= p <= 1.0):
        raise ValueError("p must be between 0 and 1")
    return p
```

```python
# 3) Bundling exceptions and re-raising
try:
    risky()
except (IOError, OSError) as e:
    log(e)
    raise                     # re-throw after logging
```

```python
# 4) EAFP style for dict access
# instead of: if "key" in d: use LBYL
try:
    value = d["key"]          # EAFP
except KeyError:
    value = default
```

## Mental Model
An exception is a **message with a parachute**: it jumps up the **call stack** until someone catches it. If nobody does, Python prints a **traceback** and exits. Use **specific** exceptions first, a generic `except Exception as e` last (if at all). Keep the **try** block **small** — only the line(s) that can fail.

## Related Concepts
- [[Input Validation vs Exception Handling]] – where to **LBYL** instead of **EAFP**.
- [[Tracebacks and Call Stack]] – how to read error messages effectively.
- [[Custom Exceptions in Python]] – creating your own exception classes.
- [[File I/O — open/read/write/close]] – typical **finally** cleanup.
- [[Division Operators in Python]] – ties to **ZeroDivisionError** from earlier note.
- [[Formatted Strings (f-strings) — Deep Dive]] – reporting errors clearly.
- [[Functions and Side Effects]] – keep raising/handling logic clean.
- [[Testing — pytest basics]] – asserting that code **raises**.

## See Also
- [[CS50x Week 6 — Python (Overview)]]
- [Python docs: Errors and Exceptions](https://docs.python.org/3/tutorial/errors.html)
- [Python docs: Exceptions (reference)](https://docs.python.org/3/library/exceptions.html)

## Terms
[[exception]], [[try/except]], [[else]], [[finally]], [[raise]], [[traceback]], [[call stack]], [[EAFP]], [[LBYL]], [[ZeroDivisionError]], [[ValueError]]
