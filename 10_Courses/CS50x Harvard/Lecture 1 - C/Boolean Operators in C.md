---
title: Boolean Operators in C
lang_tags: "#lang/c"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 3
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/1/
review_next: ""
---

## One-liner

Quick reference to C’s **\logical\** operators — `&&`, `||`, `!` — with rules for **\truthy\**/**\falsy\**, **\short-circuit\**, and common **\gotchas\** vs **\bitwise\** `&`/`|`.

---

## Core operators

| Operator | Name                    | Meaning                                    | Example                     | Result (if `x=5`, `y=7`) |
|---------:|-------------------------|--------------------------------------------|-----------------------------|--------------------------|
| `&&`     | **\logical and\**       | true if **both** operands are true         | `(x < y) && (x > 0)`        | `1`                      |
| `\|\|`   | **\logical or\**        | true if **either** operand is true         | `(x == 5) \|\| (y == 10)`   | `1`                      |
| `!`      | **\logical not\**       | flips a boolean value                      | `!(x == 5)`                 | `0`                      |

In C, “true” is any **non-zero** int; “false” is `0`. With `<stdbool.h>` you get **\bool\**, **\true\**, **\false\`** (aliased to C’s underlying **\_Bool\**).

---

## Short-circuit semantics

- `a && b` evaluates `a` first. If `a` is **falsey** (`0`), `b` is **not evaluated**.  
- `a || b` evaluates `a` first. If `a` is **truthy** (non-zero), `b` is **not evaluated**.  

This is guaranteed behavior and is crucial for **\guard clauses\** and **\null checks\**:

```c
if (p != NULL && p->len > 0) { /* safe: right side only runs if p != NULL */ }
````

---

## **Precedence & associativity**

- Precedence (high → low): !  >  &&  >  ||.
    
- All three are **left-associative** (except unary !, which is prefix).
    
- When in doubt, **parenthesize** to avoid surprises in **\operator precedence**.
    

---

## **Common pitfalls (a rogues’ gallery)**

- Don’t confuse *_\logical*_ with **\bitwise**:
    
    - && / || work on *_\truthiness*_ and **short-circuit**.
        
    - & / | operate **bitwise** on integers and **always** evaluate both sides.
        
    
- Avoid assignments in conditions unless intentional:
    

```
if ((n = read(fd, buf, SZ)) > 0) { ... }   // OK but be explicit with ()
if (flag = check()) { ... }                // easy to confuse with == → be careful
```

-   
    
- Mixed integer values as booleans are allowed but noisy. Prefer <stdbool.h> for **\clarity**.
    

---

## **Idiomatic patterns**


// 1) Guarded access
if (ptr && ptr->next) { use(ptr->next); }

// 2) Range check
if (0 <= i && i < n) { ... }

// 3) De Morgan to invert complex logic
// !(A && B)  == (!A || !B)
// !(A || B)  == (!A && !B)
if (!(is_admin || is_owner)) deny();

// 4) Using <stdbool.h>
\#include <stdbool.h>
bool ok = (count > 0) && ready;
if (!ok) { /* handle */ }


---

## **Quick checklist**

- Use &&/|| (not &/|) for control flow.
    
- Rely on *_\short-circuit*_ for safe chained checks.
    
- Keep comparisons explicit; avoid clever coercions.
    
- Parenthesize complex conditions for readability.
    

---

## **Related Concepts**

- [[Comparison operators in C]] – pairs naturally with *_\logical*_ operators to build conditions
    
- [[Operator precedence in C]] – governs parse order for !, &&, ||
    
- [[Short-circuit evaluation]] – guarantees on skipping right-hand expressions
    
- [[Truthy and falsy in C]] – how non-zero ints act as *_\boolean*_ values
    
- [[Bitwise operators in C]] – contrast with &&/|| semantics
    

  

## **See Also**

- [C reference: logical operators (cppreference)](https://en.cppreference.com/w/c/language/operator_logical)
    
- [stdbool.h (cppreference)](https://en.cppreference.com/w/c/types/boolean)
    
- [CS50x 2025 — Week 1](https://cs50.harvard.edu/x/2025/weeks/1/)
    

  

## **Terms**

  

[[logical and]], [[logical or]], [[logical not]], [[short-circuit]], [[truthy]], [[falsy]], [[operator precedence]], [[associativity]], [[bitwise operators]], [[_Bool]], [[stdbool.h]], [[guard clause]]

