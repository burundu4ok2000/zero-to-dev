---
title: Rewriting credit.c into credit.py
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 33
status: done
difficulty: easy
date: 2025-09-25
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

## One Liner
From a **16‑arg, copy‑paste heavy C program** to a **compact, general Python script** using **list comprehension**, **reversed + enumerate**, and clean **brand detection**. Same math, radically better readability and extensibility.

## Problem
The C version hard‑codes **16 separate digits**, relies on manual `%`/`/` extraction, and repeats brand/Luhn checks. It only works cleanly for **16‑digit** numbers and is painful to extend to **13/15/19**.

## Before — C (monolithic & brittle)
```c
// Input and length check
long ccn = get_long("Number: ");
int credit_card_length = credit_card_length_checker(ccn);
if (credit_card_length < 0) {
    printf("INVALID\n");
    return 0;
}

// Manual digit extraction
int num1 = ccn % 10;
int num2 = ccn / 10 % 10;
int num3 = ccn / 100 % 10;
...
int num16 = ccn / 1000000000000000 % 10;

// Brand checks with duplicated Luhn calls
if ((credit_card_length == 16) && num16 == 4) {
    if (validate_luhn_algorithm(num1, ..., num16)) printf("VISA\n"); else printf("INVALID\n");
    return 0;
}
/* more duplicated if/else for VISA(13), AMEX(15), MASTERCARD(16) ... */

// Luhn with 16 parameters
bool validate_luhn_algorithm(int num1, ..., int num16) { /* repeated arithmetic */ }
```
**Symptoms**
- **Too many parameters** (`num1..num16`) → unmaintainable signature.  
- **Rigid length logic** → doesn’t naturally cover 13/15/19 digits.  
- **Repeated work** → brand checks each re‑run Luhn and branch deeply.  
- **Arithmetic noise** → `% 10`, `/ 10` ladders obscure intent.

## After — Python (concise & general)
```python
from cs50 import get_int

def validate_luhn_algorithm(number: str) -> bool:
    digits = [int(d) for d in number]
    total = 0
    for i, d in enumerate(reversed(digits)):  # rightmost → left
        if i % 2 == 1:                         # every second digit
            doubled = d * 2
            total += doubled // 10 + doubled % 10   # or: d = d*2 - 9 if d > 4
        else:
            total += d
    return total % 10 == 0

s = str(get_int("Number: "))

if validate_luhn_algorithm(s):
    if len(s) in (13, 16) and s[0] == "4":
        print("VISA")
    elif len(s) == 15 and s[:2] in ("34", "37"):
        print("AMEX")
    elif len(s) == 16 and 51 <= int(s[:2]) <= 55:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
```
**Wins**
- **One parameter** `number: str` with **type annotations**.  
- **Digit extraction** in **one line**: `digits = [int(d) for d in str(ccn)]` (no `%/` gymnastics).  
- **Right‑to‑left** indexing: `reversed(...) + enumerate(...)` → no `len - i - 1` hacks.  
- **Single Luhn call**, then **brand detection** by **prefix** and **length**.  
- Easy to extend to **19 digits** if needed.

## The “beauty” upgrades you added
1) **Length check** becomes a readable membership test:
```python
if validate_luhn_algorithm(s):
    if len(s) in (13, 16) and s[0] == "4":
        print("VISA")
    elif len(s) == 15 and s[:2] in ("34", "37"):
        print("AMEX")
    elif len(s) == 16 and 51 <= int(s[:2]) <= 55:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
```
2) **Digit extraction** collapses all the C math to one comprehension:
```python
digits = [int(d) for d in str(ccn)]
```
Index naturally: `digits[0]` (first), `digits[-1]` (last).

## What You Learned (high‑impact)
- **Function signatures** that scale: `def luhn(number: str) -> bool`.  
- **List comprehension** as an idiom to replace repetitive loops/arithmetics.  
- **`reversed` + `enumerate`** to express “from right” positions cleanly.  
- Returning a **boolean expression** directly (no `if/else` wrapper).  
- **Prefix/length** brand logic with **slicing** and **tuples**.  
- Clean early exits (**guard clauses**) instead of deep `else` towers.

## Optional micro‑polish
- For doubling step, a common idiom is: `d = d*2 - 9 if d > 4 else d` (same as digit‑sum).  
- Replace CS50 I/O with standard `input()` to run outside the course runtime.  
- Extract brand detection into `def brand(s: str) -> str` for unit testing.

## Related Concepts
- [[Python Objects — Beginner Notes]]
- [[Python Syntax — Running, Style, Shebang]]
- [[Python Sequences — list vs tuple vs range]]
- [[Python Built-in Keyword Parameters — Cheat Sheet]]
- [[assert Statement in Python]]
- [[Python Division — / vs // (true vs floor division)]]
- [[Vocabulary · Mutable vs Immutable]]
- [[Python String Concatenation Complexity — s + t vs ''.join]]

## See Also
- [Luhn algorithm — Wikipedia](https://en.wikipedia.org/wiki/Luhn_algorithm)
- [Python docs — enumerate](https://docs.python.org/3/library/functions.html#enumerate)
- [Python docs — built‑in types (str, list)](https://docs.python.org/3/library/stdtypes.html)

## Terms
[[refactor]], [[Luhn algorithm]], [[function signature]], [[type annotation]], [[list comprehension]], [[reversed]], [[enumerate]], [[string slicing]], [[startswith]], [[prefix]], [[BIN range]], [[boolean expression]], [[guard clause]], [[input validation]], [[modulo %]], [[floor division]]
