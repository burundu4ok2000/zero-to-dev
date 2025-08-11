---
title: "Function Prototype in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 16
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-15 at 16.56.19.png]]

---

## **One-liner**

A **function prototype** is a one‑line **declaration** that tells the **compiler** a function’s **name**, **return type**, and **parameters** before it’s used.

## Why add a prototype?

- C compiles **top‑to‑bottom**; without a prior **declaration**, the compiler can’t verify a call in `main`.  
- A prototype lets `main` appear first while keeping full **definitions** below or in other files.  
- In multi‑file programs, prototypes live in **header files** (`.h`) that you `#include` where needed.

## Minimal pattern

```c
#include <stdio.h>

void meow(void);           // prototype

int main(void)
{
    for (int i = 0; i < 3; i++) { meow(); }
}

void meow(void)            // definition
{
    printf("meow\n");
}
```

## Anatomy of a prototype

| Piece | Example | Meaning |
|---|---|---|
| **Return type** | `void` | What the function returns |
| **Name** | `meow` | Identifier you call |
| **Parameter list** | `(void)` | Expected **parameters** (none here) |
| **Semicolon** | `;` | Ends the **declaration** (no body) |

## Best practices

- Put prototypes **above `main`** or into a **header file** and `#include` it.  
- Keep **prototype** and **definition** **identical** (types/order).  
- Prefer explicit parameter lists (`(void)` for none) to avoid old‑style declarations.

## Common pitfalls

- Skipping the prototype → **implicit declaration** errors/warnings.  
- Mismatched signatures between **declaration** and **definition**.  
- Declaring in a `.c` file but forgetting to share via a **header** for other translation units.

## Related Concepts

- [[Function Definition in C]] – structure and placement of the full body.
- [[Header Files in C]] – organize and reuse **declarations** across files.
- [[Compilation and Linking in C]] – how separate files become one program.
- [[Parameters vs Arguments]] – matching the call to the signature.
- [[Return Values and void]] – expressing “no value” correctly.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [cppreference — Function declaration](https://en.cppreference.com/w/c/language/function_declaration)
- [C FAQ — Declarations vs definitions](https://c-faq.com/decl/decldef.html)

## Terms

[[function prototype]], [[declaration]], [[definition]], [[header file]], [[signature]], [[parameter]], [[argument]], [[compiler]], [[translation unit]], [[linker]]
