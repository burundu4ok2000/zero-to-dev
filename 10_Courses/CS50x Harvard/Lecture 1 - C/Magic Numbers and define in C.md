---
title: "Magic Numbers and define in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 25
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-20 at 17.56.21.png]]
![[Screenshot 2025-07-20 at 18.04.31.png]]
![[Screenshot 2025-07-20 at 18.05.16.png]]

---

## **One-liner**

Kill **magic numbers** by naming them once with **#define** or a **const** so your code explains itself and future changes are one‑line edits.

## Problem: magic numbers

A **magic number** is a raw literal (like `86400`, `0.07`, `42`) that appears **without context**. It hides intent and makes global changes risky.

**Bad**

```c
for (int i = 0; i < 86400; i++) { /* ... */ }   // what is 86400?
```

If you later switch semantics (e.g., want hours, not seconds) you must hunt every `86400` and hope you don’t miss any.

## Solution: symbolic constants with **#define**

C’s **preprocessor** runs before compilation and does **text substitution** of tokens:

```c
#define NAME REPLACEMENT
```

**Good**

```c
#define SECONDS_PER_DAY 86400

for (int i = 0; i < SECONDS_PER_DAY; i++) { /* ... */ }
```

Now the meaning is clear, and a single change updates all uses.

> Analogy: **#include** ≈ copy–paste a file. **#define** ≈ find–replace a token.

## Why not just use a variable? (**const**)

```c
const int SECONDS_PER_DAY = 86400;
```

Both approaches remove magic numbers; choose based on constraints:

| Approach | Prefer when | Notes |
|---|---|---|
| **#define** | Need a value usable in **array sizes**, **preprocessor conditionals**, or other compile‑time contexts | No type; pure token replacement |
| **const** variable | Want **type safety**, **scope control**, and debugger visibility | Real object with a type; can take its address |

Many modern codebases prefer **const** by default and use **#define** where the preprocessor’s powers are needed.

## Naming conventions

- Use **ALL_CAPS_WITH_UNDERSCORES**: `MAX_STUDENTS`, `BUFFER_SIZE`.  
- Name the **idea**, not the value: `TAX_RATE`, not `SEVEN_PERCENT`.  
- Avoid generic names like `SIZE`, `VALUE`.

## Scope and order

A **#define** applies from its point of definition to the end of the **translation unit** unless you **#undef** it.

```c
#define LIMIT 10
// LIMIT usable here
#undef LIMIT
// LIMIT no longer usable
```

## Common pitfalls with macros

| Pitfall | Example | Why it bites | Fix |
|---|---|---|---|
| Missing parentheses around parameters | `#define DOUBLE(x) x + x` | `DOUBLE(1+2)` → `1+2+1+2` (precedence surprises) | `#define DOUBLE(x) ((x) + (x))` |
| Trailing semicolon in value | `#define SIZE 50;` | Expands to `50;` inside expressions → compile errors | Don’t put semicolons in **#define** values |
| Overusing function‑like macros | `#define ADD(a,b) ((a)+(b))` | Functions already do this with types and debugging | Prefer real **functions** unless you need macro power |

## Macros vs **inline** functions (preview)

For logic with parameters, a `static inline` function gets **type checking** and debuggability:

```c
static inline int double_int(int x) { return x + x; }
```

## Quick examples

| Goal | Macro / Const |
|---|---|
| Max array length | `#define MAX_LEN 256` |
| π approximation | `const double PI = 3.141592653589793;` |
| Bitmap width & height | `#define WIDTH 1920` / `#define HEIGHT 1080` |
| Derived size | `#define HEADER_BYTES 32` + `#define PACKET_BYTES (HEADER_BYTES + 512)` |

## Checklist before committing

- Any unexplained literals? Replace with a named constant.  
- Name communicates **what**, not **how much**.  
- Prefer **const** where types help; keep **#define** for compile‑time needs.  
- Wrap macro parameters in **parentheses**.

## Related Concepts

- [[Style50 Guidelines]] – code readability standards in CS50.
- [[Refactoring Techniques in C]] – extract and name intent.
- [[Header Files in C]] – place shared **#define** and **const** declarations.
- [[Preprocessor in C]] – how **#define** and **#include** work.
- [[Constant Variables (const) in C]] – typed constants and scopes.
- [[Macros vs Inline Functions]] – when to use each.

## See Also

- [cppreference — Preprocessor macros](https://en.cppreference.com/w/c/preprocessor/replace)  
- [cppreference — const‑qualified type](https://en.cppreference.com/w/c/language/const)  
- [Wikipedia — Magic number (programming)](https://en.wikipedia.org/wiki/Magic_number_(programming))

## Terms

[[magic number]], [[#define]], [[preprocessor]], [[token substitution]], [[const]], [[macro]], [[inline function]], [[translation unit]], [[#undef]], [[array size]], [[compile-time]]
