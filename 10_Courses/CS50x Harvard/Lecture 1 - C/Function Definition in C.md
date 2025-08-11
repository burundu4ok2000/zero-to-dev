---
title: "Function Definition in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 14
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-15 at 16.31.27.png]]

---

## **One-liner**

A **function definition** gives a **return type**, a **name**, **parameters**, and a **body** of code to run when the function is **called**.

## Minimal example

```c
void meow(void)
{
    printf("meow\n");
}
```

## Anatomy (map the pieces)

| Part | In this case | Meaning |
|---|---|---|
| **Return type** | `void` | Function **returns nothing** |
| **Name** | `meow` | **Identifier** you use to call it |
| **Parameters** | `void` | Accepts **no arguments** |
| **Body** | `{ ... }` | Statements that run on call |

## Why define functions?

- **Avoid repetition**: write logic once, **call** it many times.  
- **Improve readability**: `meow();` is clearer than repeating a line.  
- **Encapsulate logic**: hide details behind a **name** and **interface**.

## Calling and prototypes

```c
// Option A: define above main
void meow(void)
{
    printf("meow\n");
}

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}
```

```c
// Option B: prototype above, definition below
void meow(void);   // function prototype (declaration)

int main(void)
{
    meow();
}

void meow(void)    // function definition
{
    printf("meow\n");
}
```

## Evolving the interface

```c
void meow_times(int times)      // parameters give inputs
{
    for (int i = 0; i < times; i++) { printf("meow\n"); }
}

int main(void)
{
    meow_times(3);              // arguments flow into parameters
}
```

## Common pitfalls

- Forgetting the **prototype** when the definition appears **after `main`** (older compilers may warn).  
- Mismatch between **prototype** and **definition** (types, names, or `void` vs parameters).  
- Returning a value from a function declared **`void`**, or not returning a value from a **non-void** function.  
- Reusing the same **identifier** for different functions in the same scope.  
- C89 vs C99: declaring loop variables in headers (e.g., `for (int i = ...)`) requires modern C; stick to **C11** in CS50.

## Related Concepts

- [[Why break out functions]] – motivation and benefits of decomposition.
- [[Function Prototype in C]] – declaring the interface before use.
- [[Return Values and void]] – when to return and when not to.
- [[Parameters vs Arguments]] – terminology and call semantics.
- [[Scope and Lifetime in C]] – visibility of names and variables.
- [[Header Files in C]] – placing prototypes in `.h` for reuse.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [cppreference — Function definition](https://en.cppreference.com/w/c/language/function_definition)
- [C FAQ — Declarations vs definitions](https://c-faq.com/decl/decldef.html)

## Terms

[[function definition]], [[function call]], [[return type]], [[identifier]], [[parameter]], [[argument]], [[prototype]], [[declaration]], [[definition]], [[body]], [[interface]], [[scope]], [[header file]]
