---
title: "assert Statement in Python"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 29
status: "done"
difficulty: "easy"
date: "2025-09-24"
timecode: ""
source: "CS50x Week 6 (Python)"
review_next: ""
---

## One Liner
**assert** checks a **condition** at runtime and raises **AssertionError** if it is **False**.

## Explanation
`assert` is a built‑in statement for quick **sanity checks** while running code.  
- If the condition is **True** → execution continues.  
- If the condition is **False** → **AssertionError** is raised (optionally with your message).  
- Assertions can be **disabled** when Python runs with the **-O** optimization flag.

## Examples
```python
# Basic equality check
assert s1 == s2

# With a message
assert s1 == s2, "strings do not match!"
```

```python
# Guarding assumptions inside a function
def divide(a, b):
    assert b != 0, "division by zero!"
    return a / b
```

## Best Practices
- Use **assert** for developer‑time **invariants** and **internal assumptions**.  
- Prefer **if ...: raise ValueError(...)** for **user input validation** and production checks.  
- Keep assert messages **short** and **actionable**.  
- For tests, frameworks like **pytest** leverage plain `assert`.

## Heads‑up
- Running Python with **-O** removes `assert` statements at bytecode compile time.  
- Don’t rely on `assert` for security, access control, or external input validation.

## Related Concepts
- [[Mutable Default Arguments in Python]] – behavior depends on **definition vs call time**
- [[Vocabulary · Mutable vs Immutable]] – background on **immutability**
- [[Python String Concatenation Complexity — s + t vs ''.join]] – costs from **immutability**
- [[Python Built-in Keyword Parameters — Cheat Sheet]] – useful **keywords** you’ll meet
- [[Python Objects — Beginner Notes]] – objects, **attributes**, **dunder** basics
- [[Python — Errors & Tracebacks]] – reading **AssertionError** and stack frames
- [[Identity vs Equality (id vs ==) in Python]] – avoid confusion in checks
- [[Python — Functions & Arguments]] – where you often place **asserts**

## See Also
- [Python Tutorial: Assertions](https://docs.python.org/3/tutorial/errors.html#assertion-error)
- [Python Language Reference: assert statement](https://docs.python.org/3/reference/simple_stmts.html#the-assert-statement)
- [pytest — Assertions in tests](https://docs.pytest.org/en/stable/how-to/assert.html)

## Terms

[[assert]], [[AssertionError]], [[invariant]], [[precondition]], [[postcondition]], [[sanity check]], [[runtime check]], [[debug]], [[-O optimization]], [[raise]], [[ValueError]], [[Exception]], [[pytest]], [[unit test]], [[boolean expression]], [[defensive programming]], [[input validation]], [[contract programming]], [[traceback]], [[stack trace]]