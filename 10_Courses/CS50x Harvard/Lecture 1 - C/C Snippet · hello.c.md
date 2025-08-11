---
title: C Snippet · hello.c
lang_tags: "#lang/c"
type_tags: "#type/snippet"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: "#tool/shell/bash"
atom_idx: 5
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/1/
review_next: ""
---

---

## **One-liner**

Minimal C program that prints text to the terminal using **printf**, with **#include** pulling in the **standard library** header and **main** as the **entry point** returning an **exit status**.

## Common Commands / Syntax

| **Task**                        | **Command / Code**          | **Notes**                                                      |
| ------------------------------- | --------------------------- | -------------------------------------------------------------- |
| Create source file              | `code hello.c`              | Any editor works.                                              |
| Include standard I/O header     | `#include <stdio.h>`        | **\preprocessor directive\** adds prototypes for **\printf\**. |
| Define entry point              | `int main(void) { ... }`    | **\return type\** is `int`. `void` = no params.                |
| Print a line                    | `printf("hello, world\n");` | `\n` = **\newline\**; end statement with `;`.                  |
| Build with clang                | `clang -o hello hello.c`    | Produces an executable `hello`.                                |
| Build with CS50 make            | `make hello`                | CS50 alias wraps **\clang\** with sane defaults.               |
| Run                             | `./hello`                   | Executes the compiled binary.                                  |
| Inspect exit status (Unix)      | `echo $?`                   | `0` = success; non‑zero = error.                               |
| Show assembly (peek under hood) | `clang -S hello.c`          | Emits `.s` for learning.                                       |

## Frequently Used Patterns

- **Format string with placeholders:** `printf("%d\n", x);` — print an **\int\**; `%f`, `%s`, etc. for other types.  
- **Two common main signatures:** `int main(void)` and `int main(int argc, char *argv[])` — second form accepts **\command‑line arguments\**.  
- **Conventional success return:** `return 0;` — in **\main\**, falling off the end implicitly returns 0 in standard C.

## Shortcuts

- Build & run quickly (bash): ``clang -o hello hello.c && ./hello``  
- Rebuild only when changed: use `make hello`, then just run `./hello`.

## Tips & Gotchas

- Forgetting `\n` means the shell prompt may appear on the same line — add a **\newline\**.  
- Missing header → implicit declaration errors; always `#include <stdio.h>` before using **\printf\**.  
- A stray missing semicolon `;` usually breaks the previous line, not the current one — read the compiler error carefully.  
- Only **\main\** gets the implicit `return 0;` on fall‑through; other functions must **\return\** explicitly.

## Examples

```c
// hello.c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
    return 0;
}
```

```bash
$ make hello     # or: clang -o hello hello.c
$ ./hello
hello, world
$ echo $?
0
```

## Related Concepts

- [[C Program Structure]] – scaffolding for headers, **\functions\**, and **\main\**.
- [[printf — formatted output]] – deeper dive into **\format string\** and specifiers.
- [[Compilation Pipeline (preprocess → compile → link)]] – where **\#include\** fits in.
- [[Exit Status (Unix)]] – conventions for shell integration and `echo $?`.
- [[Command-line arguments (argc, argv)]] – alternative **\main signature\**.

## See Also

- [CS50x 2025 — Course homepage](https://cs50.harvard.edu/x/2025)
- [man 3 printf — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [cppreference — main function](https://en.cppreference.com/w/c/language/main_function)

## Terms

[[include]], [[stdio.h]], [[main function]], [[return statement]], [[preprocessor directive]], [[newline character]], [[clang compiler]], [[format string]]
