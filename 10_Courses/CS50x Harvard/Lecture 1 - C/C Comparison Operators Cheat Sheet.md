---
title: C Comparison Operators Cheat Sheet
lang_tags: "#lang/c"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 4
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/1/
review_next: ""
---
![[Screenshot 2025-07-12 at 13.15.33.png]]

---

## **One-liner**

> Fast reference to C's **\comparison operators\** (`<`, `<=`, `>`, `>=`, \`\==\`, `!=`) and how they evaluate to **\boolean\**-ish `int` values (`1` or `0`).

## Common Commands / Syntax

| **Operator** | **Reads as**                | **True when…**          | **Example** |
| ------------ | --------------------------- | ----------------------- | ----------- |
| `<`          | less-than                   | left < right            | `x < y`     |
| `<=`         | less-than-or-equal          | left ≤ right            | `x <= y`    |
| `>`          | greater-than                | left > right            | `x > y`     |
| `>=`         | greater-than-or-equal       | left ≥ right            | `x >= y`    |
| \`\=\=\`     | equals / equality           | left equals right       | `x == y`    |
| `!=`         | not-equal (**bang equals**) | left differs from right | `x != y`    |

> Heads-up: \`=\` is **\assignment\**, not comparison. `x = 5` stores; `x == 5` compares.

## Frequently Used Patterns

- **Guard clause:** `if (x != 0) { /* safe divide */ }` — reject invalid states early.
- **Range check:** `if (a <= x && x <= b) { ... }` — chain comparisons with **\logical operators\**.
- **Ternary shortcut:** `printf("%s", x == y ? "equal" : "different");` — inline branch with **\ternary operator\**.
- **Char ordering:** `if ('a' < 'Z') { ... }` — comparisons work on **\char codes\**.
- **strcmp for strings:** `if (strcmp(s1, s2) == 0) { /* equal text */ }` — compare C-strings by content, not pointers.

## Shortcuts

- Read `!=` out loud as “**bang equals**”. Helps avoid confusing it with \`\=\=\` in code reviews.
- In debug prints, show the evaluated `int`: `printf("%d\n", x < y);` → prints `1` or `0`.

## Tips & Gotchas

- **\`\=\` vs \`\=\=\`:** `if (x = 1)` assigns and is almost always a bug. Many compilers will warn; add `-Wall -Werror`.
- **Floats lie (a little):** Avoid `if (a == b)` for `float`/`double`; use an **\epsilon\**: `fabs(a - b) < 1e-6`.
- **Pointer vs content:** `if (s1 == s2)` compares addresses, not text. Use `strcmp` for **\C-strings\**.
- **Promotion rules:** Mixed types promote (e.g., `char` → `int`). Know **\usual arithmetic conversions\** to avoid surprises.
- **Boolean is `int`:** In C, comparisons yield `int` `1` or `0`, not a distinct `bool` (unless you `#include <stdbool.h>`).

## Examples

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    if (x != y)
    {
        printf("x and y are different\n");
    }
    else if (x == y)
    {
        printf("x and y are equal\n");
    }

    // Range: 1..10
    int n = get_int("n: ");
    if (1 <= n && n <= 10)
    {
        printf("n in [1,10]\n");
    }

    // Float comparison with epsilon
    double a = 0.1 + 0.2;
    double b = 0.3;
    if (fabs(a - b) < 1e-9)
    {
        printf("a ~= b\n");
    }

    // String comparison
    string s1 = get_string("s1: ");
    string s2 = get_string("s2: ");
    if (strcmp(s1, s2) == 0)
    {
        printf("same text\n");
    }
}
```

## Related Concepts

- [[Logical Operators in C]] – \smth\ with C comparison logic by combining **and/or/not**.
- [[Operator Precedence and Associativity in C]] – \smth\ with comparisons interacting with arithmetic and logical ops.
- [[If / Else Basics (C)]] – \smth\ with branching using comparison results.
- [[While and For Loops (C)]] – \smth\ with loop conditions driven by comparisons.
- [[String Handling with strcmp (C)]] – \smth\ with content equality for C-strings.

## See Also

- [CS50 Shorts — Operators](https://cs50.harvard.edu/x/2025/shorts/operators/)
- [cppreference — Relational operators (C)](https://en.cppreference.com/w/c/language/operator_comparison)
- [cppreference — Equality operators (C)](https://en.cppreference.com/w/c/language/operator_logical#Equality_operators)

## Terms

[[assignment]], [[equality operator]], [[inequality operator]], [[relational operator]], [[boolean]], [[expression]], [[operand]], [[lvalue]], [[rvalue]], [[ternary operator]], [[strcmp]], [[type promotion]]
