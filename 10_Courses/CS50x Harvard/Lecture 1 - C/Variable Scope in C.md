---
title: "Variable Scope in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 34
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-15 at 17.23.18.png]]

---

## **One-liner**

**Scope** controls **where a name is visible** and for **how long it lives**. In C: **function scope** for parameters/locals, **block scope** for variables inside braces, and **file scope** for globals.

## Example

```c
#include <cs50.h>
#include <stdio.h>

void meow(int n);          // prototype

int main(void)
{
    int n = get_int("Number: ");   // n lives only inside main
    meow(n);
}

void meow(int n)           // parameter n lives only inside meow
{
    for (int i = 0; i < n; i++)    // i lives only inside the loop
    {
        printf("meow\n");
    }
}
```

## What “scope” means

| Level | Variables visible | Lifetime |
|---|---|---|
| **Function scope** | `n` in `main`, `n` in `meow` | From function entry to return |
| **Block scope** | `i` inside the `for` body | From `{` to matching `}` |
| **File (global) scope** | Globals declared at top of a `.c` file | Entire program run |

Notes

- A name is only accessible **inside the braces** where it is declared.  
- Reusing the same name in different functions is fine; they are **distinct variables**.  
- Passing `n` to `meow(n)` copies the value — C is **pass by value**.

## Why scope matters

- Prevents **name collisions** across functions and blocks.  
- Keeps data **private** to where it’s needed (less coupling).  
- Helps avoid **use-after-lifetime** bugs.

## Common pitfalls

- **Using a variable outside its block**: it no longer exists after `}`.  
- **Shadowing** a name in an inner block can hide the outer variable; prefer clearer names.  
- Overusing **globals** makes testing and reasoning harder; pass values as **parameters** instead.

## Rules of thumb

1. Declare variables **as close as possible** to first use.  
2. Prefer **function parameters** over globals to pass data in.  
3. Keep loop counters and temporaries **inside** the smallest block.  
4. For cross-file visibility, expose **prototypes** in headers; keep globals `static` if they must exist.

## Related Concepts

- [[Function Parameter in C]] – inputs live in function scope.  
- [[Function Definition in C]] – where locals are declared and used.  
- [[For Loop in C]] – typical home of block-scoped counters.  
- [[Pass by Value in C]] – arguments are copied on call.  
- [[Header Files in C]] – expose interfaces without globals.  
- [[Static Keyword in C]] – limits file-scope visibility.  
- [[Scope and Lifetime in C]] – deeper dive into visibility vs duration.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [cppreference — Identifier scope in C](https://en.cppreference.com/w/c/language/scope)  
- [GCC — `-Wshadow` warning](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wshadow)

## Terms

[[scope]], [[block scope]], [[function scope]], [[file scope]], [[global variable]], [[local variable]], [[lifetime]], [[visibility]], [[parameter]], [[shadowing]], [[name collision]], [[static]], [[header file]]
