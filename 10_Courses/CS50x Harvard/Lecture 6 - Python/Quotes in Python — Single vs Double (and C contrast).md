---
title: "Quotes in Python — Single vs Double (and C contrast)"
lang_tags: "#lang/python #lang/c"
type_tags: "#type/termin"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 04
status: "in-progress"
difficulty: "easy"
date: "2025-09-22"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/6/"
review_next: ""
---

## Definition
In **Python**, single quotes `'...'` and double quotes `"..."` both create a **string literal**. There is **no separate char type**; a single character is just a **string** of length 1.  
In **C**, `'c'` is a **char** and `"...\0"` is a **NUL‑terminated string** — big difference.

---

## Very simple
- Python: `'A' == "A"` → `True`; `type('A')` is **str**.  
- C: `'A'` (one **char**) vs `"A"` (two **chars**: `'A'` and **'\0'**).

---

## Python basics
```py
# Same thing
s1 = 'hello'
s2 = "hello"
assert s1 == s2

# Choose quotes to avoid backslashes
quote = "I'm fine."          # OK (uses double quotes)
dialog = 'He said "hi".'     # OK (uses single quotes)

# Escapes if you need the same quote inside
escaped = 'I\'m fine'
also_ok = "He said \"hi\""

# One character is still a string
ch = 'A'
len(ch)           # 1
type(ch)          # <class 'str'>
```

### Triple quotes & docstrings
```py
text = """multi
line"""
def f(): 
    """This is a docstring"""
    pass
```
Triple `"""..."""` or `'''...'''` support **multiline** strings and **docstrings**.

### Bytes and raw strings
```py
b = b"abc"         # bytes literal (single or double quotes both fine)
path = r"C:\\tmp"  # raw string: backslashes are not escapes
```

---

## When to use which
- Pick one style in a project and **be consistent** (PEP 8).  
- Use the **other** when it avoids **escaping**: `"can't"` or `'he said "hi"'`.  
- For user‑visible messages, **f‑strings** are great: `f"Hello, {name}!"`.

---

## C contrast (why Python feels easier)
```c
// C
char ch = 'A';           // one char
char *s = "A";           // two chars: 'A' and '\0' (null terminator)
printf("%c %s\n", ch, s);
```
- **C** has **char** vs **string** and needs a **null terminator** `\0`.  
- **Python** strings are **immutable** sequences of **Unicode** code points; no manual `\0` involved.

---

## Gotchas
- Mixing types: **concatenation** needs strings → use **str()** or **f‑strings**.  
- Don’t rely on which quote `repr(obj)` chooses when printing — it’s implementation detail.  
- Raw strings can’t end with a single backslash (`r"\"` is invalid).

---

## Related Concepts
- [[Hello, world — C vs Python (Lecture 6 intro)]] – compile vs interpret mindset.
- [[Concatenation — Python’s + for Strings and Sequences]] – joining strings.
- [[Named Parameters (Keyword Arguments) — Python]] – readable function calls.
- [[Choosing a Data Structure — Practical Guide]] – strings vs bytes choices.
- [[Hash Tables — Arrays and Linked Lists]] – Python’s **dict** with string keys.
- [[Prime Numbers for Hashing — Why Primes Matter and How to Use Them]] – hashing those strings.
- [[Signed vs Unsigned Integers in C — Ranges and Memory]] – C’s low‑level types (contrast).

## See Also
- [Python docs — String & Bytes literals](https://docs.python.org/3/reference/lexical_analysis.html#string-and-bytes-literals)
- [PEP 8 — Quotes guidance](https://peps.python.org/pep-0008/#string-quotes)
- [C strings vs chars (cppreference)](https://en.cppreference.com/w/c/language/string_literal)

## Terms
[[String literal]] [[Char]] [[Null terminator (\0)]] [[Unicode]] [[Escape sequence]] [[Docstring]] [[Triple quotes]] [[Raw string]] [[Bytes]] [[f-string]]
