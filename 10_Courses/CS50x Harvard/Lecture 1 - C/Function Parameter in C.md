---
title: "Function Parameter in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 15
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-15 at 17.06.01.png]]

---

## **One-liner**

A **function parameter** lets a function accept **inputs** so callers can customize its behavior without editing the function body.

## Minimal parameterized version

```c
void meow(int n)          // takes an int parameter
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

### Calling it

```c
int main(void)
{
    meow(3);              // prints "meow" three times
}
```

## Anatomy: prototype vs definition

| Piece | Example | Meaning |
|---|---|---|
| **Prototype** | `void meow(int n);` | Declaration placed before first use so the compiler knows the **signature** |
| **Definition** | `void meow(int n) { ... }` | The actual body of the function |
| **Parameter list** | `(int n)` | Names and types of values the function expects |
| **Arguments** | `meow(3)` | Concrete values passed at the **call site** |

## Semantics in C: pass by value

- C passes **by value**: the function receives **copies** of the arguments. Modifying `n` inside `meow` does not change the caller’s variable.  
- To modify caller state, pass a **pointer** (e.g., `int *p`) or a **mutable object** (array via pointer).

```c
void set_to_42(int x) { x = 42; }     // does not affect caller
void set_to_42p(int *px) { *px = 42; } // does affect caller
```

## Multiple parameters and defaults

- Separate parameters with commas: `void draw(char c, int count);`  
- C has **no default arguments**; provide all parameters at each call.  
- Prefer **const** in pointers you don’t modify: `void print(const char *s);`

## Common pitfalls

- Prototype and definition **mismatch** (types/order). Keep them identical.  
- Using parameters **before initialization** (not applicable—parameters are always initialized by the call).  
- Confusing **parameters** (inside the function) with **arguments** (at the call site).  
- Expecting pass‑by‑reference: remember C is **by value** unless you pass a pointer.  
- Shadowing global names with parameter names; prefer **clear, local names**.

## Related Concepts

- [[Function Definition in C]] – structure of return type, name, parameters, and body.
- [[Function Prototype in C]] – why declarations come before use.
- [[Parameters vs Arguments]] – terminology and mental model.
- [[Pass by Value in C]] – how copies are made during calls.
- [[Pointers and Addresses in C]] – pass references to modify caller state.
- [[Header Files in C]] – place prototypes in `.h` for reuse.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [cppreference — Function declarators](https://en.cppreference.com/w/c/language/function_declaration)
- [C FAQ — Parameters vs arguments](https://c-faq.com/decl/paramvsarg.html)

## Terms

[[function]], [[parameter]], [[argument]], [[prototype]], [[definition]], [[signature]], [[call site]], [[pass by value]], [[pointer]], [[const]], [[modifier]], [[shadowing]], [[header file]]
