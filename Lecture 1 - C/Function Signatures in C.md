

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]
> [[Function Parameter in C]][[Function Prototype in C]][[Function Definition in C]]

---

## Why type comes first

| Header             | Read as                                 | Compiler expectation |
|--------------------|-----------------------------------------|----------------------|
| `int main(void)`   | “main **returns an int**”               | Must `return` an integer status (usually `0`). |
| `void meow(int n)` | “meow **returns nothing** and takes `n`”| Cannot return a value; `n` is an `int` argument. |

*`void` before a function name **explicitly means “no output”**.*
.

![[Screenshot 2025-07-15 at 17.36.54.png]]



## Quick rules

1. **Return type first** – tells the compiler what the function gives back (`int`, `void`, etc.). 

---

![[Screenshot 2025-07-15 at 17.38.03.png]]