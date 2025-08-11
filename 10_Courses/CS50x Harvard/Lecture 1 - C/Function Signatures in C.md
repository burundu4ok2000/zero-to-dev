---
title: "Function Signatures in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 17
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-15 at 17.36.54.png]]
![[Screenshot 2025-07-15 at 17.38.03.png]]

---

## **One-liner**

A **function signature** in C = **return type** + **name** + **parameter list**; it’s how the **compiler** knows how a function is called and what it returns.

## Why type comes first

| Header | Read as | Compiler expectation |
|---|---|---|
| `int main(void)` | “main returns an **int**” | Must **return** an integer status (usually `0`). |
| `void meow(int n)` | “meow returns **nothing** and takes `n`” | Cannot return a value; `n` is an **int** argument. |

`void` before a function name explicitly means “no result”.

## Signature vs definition vs prototype

- **Signature**: the pair of **name** and **parameter types** (plus **return type** for full interface).  
- **Prototype**: a **declaration** ending with `;` that states the signature before use.  
- **Definition**: the full function with a **body** `Ellipsis`.

> Keep the **prototype** and **definition** identical (types and order).

## Minimal patterns

```c
// Prototype first, then definition later
void meow(void);          // prototype

void meow(void)           // definition
{
    printf("meow\n");
}
```

```c
// Parameters shape the signature
int add(int a, int b);    // returns int, takes two ints
```

## Best practices

- Use `(void)` for **no parameters** instead of an empty list.  
- Prefer **explicit types**; avoid old K&R-style declarations.  
- Keep signatures **small and clear**; if a function needs many parameters, consider a **struct** or refactor.  
- When exposing functions across files, put **prototypes in a header** and `#include` it.

## Common pitfalls

- Calling a function **before** its **prototype** → implicit declaration errors.  
- Mismatched **parameter types** or **return type** between prototype and definition.  
- Forgetting that C is **pass by value**: changing parameters doesn’t change caller variables unless you pass **pointers**.  
- Omitting a **return** in a non-`void` function.

## Related Concepts

- [[Function Prototype in C]] – declare the function before use.  
- [[Function Definition in C]] – full body that matches the prototype.  
- [[Function Parameter in C]] – how inputs become part of the signature.  
- [[Return Values and void]] – expressing “no value” vs returning a result.  
- [[Header Files in C]] – sharing prototypes across translation units.  
- [[Compilation and Linking in C]] – why signatures must match across files.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [cppreference — Function declaration](https://en.cppreference.com/w/c/language/function_declaration)  
- [C FAQ — Declarations vs definitions](https://c-faq.com/decl/decldef.html)

## Terms

[[function signature]], [[return type]], [[parameter list]], [[prototype]], [[definition]], [[void]], [[int]], [[argument]], [[parameter]], [[header file]], [[translation unit]], [[linker]]
