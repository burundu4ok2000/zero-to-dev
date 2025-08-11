---
title: "CS50 Library · get_Functions"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 10
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

## **One-liner**

CS50’s **get_*** functions provide safe, friendly input with built‑in **input validation**; only `get_string` allocates memory you must **free**.

## Quick table

| **Function** | **Return type** | **Purpose** | **Typical call** |
|---|---|---|---|
| `get_char()`   | `char`   | Read a single character from standard input | `char c = get_char();` |
| `get_double()` | `double` | Read a floating‑point number                | `double d = get_double("Price: ");` |
| `get_float()`  | `float`  | Read a 32‑bit floating‑point number         | `float f = get_float("Ratio: ");` |
| `get_int()`    | `int`    | Read an integer (re‑prompts on bad input)   | `int n = get_int("Age: ");` |
| `get_long()`   | `long`   | Read a 64‑bit integer                       | `long id = get_long("ID: ");` |
| `get_string()` | `string` | Read a line of text, allocating enough space| `string s = get_string("Name: ");` |

> `string` is CS50’s typedef for `char *`.

## Why use them?

- **Input validation**: they keep asking until the input parses as the requested type.  
- **Memory safety**: `get_string` allocates a big enough buffer to hold the line; no buffer overflows.  
- **Ergonomics**: nicer than juggling `scanf`, format strings, and error checks while you’re learning.

## Under the hood (mental model)

- Internally they combine standard I/O (like `fgets`) with numeric parsers (e.g., `strtol`, `strtod`).  
- On parse failure, they **clear the input** and **re‑prompt**.  
- `get_string` allocates on the **heap**; when done, **free** it with `free(s)`.

## Minimal example

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int age = get_int("Age: ");
    string name = get_string("Name: ");

    printf("%s is %i years old.
", name, age);
    free(name);  // only required for get_string
}
```

## Common gotchas

- Forgetting `free(name)` for strings → **memory leak**.  
- Assuming other get_* functions need `free` — they **do not**; they return by value.  
- Mixing `get_*` with raw `scanf` can leave **leftover newlines** in the input buffer. Prefer a single approach per program.

## Related Concepts

- [[Strings in C]] – what `string` really is (`char *`) and how memory works.
- [[Input Validation in C]] – patterns for safe user input.
- [[printf Format Specifiers]] – printing numbers and strings correctly.
- [[Memory Management in C]] – stack vs heap, `malloc`/`free`.
- [[Standard Input and Output (STDIN STDOUT STDERR)]] – where input comes from and output goes.
- [[fgets vs scanf in C]] – lower‑level alternatives you’ll meet later.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [man fgets — file input](https://man7.org/linux/man-pages/man3/fgets.3.html)
- [man strtol — parse integers](https://man7.org/linux/man-pages/man3/strtol.3.html)

## Terms

[[get_char]], [[get_int]], [[get_long]], [[get_float]], [[get_double]], [[get_string]], [[input validation]], [[prompt]], [[heap]], [[malloc]], [[free]], [[stdin]], [[fgets]], [[strtol]], [[memory leak]]
