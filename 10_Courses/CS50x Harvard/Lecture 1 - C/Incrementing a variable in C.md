---
title: "Incrementing a variable in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 22
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-12 at 13.27.37.png]]
![[Screenshot 2025-07-12 at 13.27.40.png]]
![[Screenshot 2025-07-12 at 13.27.45.png]]

---

## **One-liner**

There are three idiomatic ways to add **1** to a variable in C — **counter = counter + 1**, **counter += 1**, and **counter++** — choose the one that keeps intent clearest.

## Three equivalent forms

| **Syntax** | **Reads as** | **What happens** | **Typical use** |
|---|---|---|---|
| `counter = counter + 1;` | “counter equals counter plus one” | Recomputes the right‑hand side and stores it back. | Very explicit; great for teaching or adding > 1 with a variable. |
| `counter += 1;` | “counter plus‑equals one” | **Compound assignment** adds the RHS and assigns the result. | Concise; scales to `+= step`. |
| `counter++;` | “counter plus plus” | **Post‑increment** adds 1. In an expression, yields the **old** value. | Common in **for loops** and simple increments. |

> `++counter;` (**pre‑increment**) also adds 1 but yields the **new** value when used inside an expression. As a standalone statement, `counter++;` and `++counter;` behave the same.

## Which should you choose?

- Use **counter++** in loop headers and simple “step by one” updates.  
- Use **+= step** when the increment varies (e.g., `i += 2`, `i += stride`).  
- Use **counter = counter + n** for maximum explicitness or when the **addend is a variable** and you want readability.

Modern compilers typically compile these to equivalent machine code under optimization — prefer **clarity** for humans.

## Pitfalls to avoid

- Don’t combine multiple increments of the **same variable** in one expression; many forms are **undefined behavior** in C (e.g., `i = i++` or `i = i++ + ++i`). Keep increments **separate statements**.  
- Beware of using **post‑increment** inside larger expressions if you rely on the value **before** the increment — it can be confusing to readers.  
- Remember **operator precedence**: `*p++` increments the **pointer**, not the value pointed to (`(*p)++` increments the value).

## Related Concepts

- [[For Loop in C]] – typical home of `i++` in counting loops.  
- [[Compound Assignment Operators in C]] – `+=`, `-=`, and friends.  
- [[Operator Precedence in C]] – how `*p++` parses.  
- [[Undefined Behavior in C]] – why `i = i++` is not allowed.  
- [[Post vs Pre Increment in C]] – value produced by `i++` vs `++i`.  
- [[While Loop in C]] – alternative loop where increments sit inside the body.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [cppreference — Increment and decrement operators](https://en.cppreference.com/w/c/language/operator_incdec)  
- [C FAQ — Sequence points and undefined behavior](https://c-faq.com/expr/seqpoints.html)

## Terms

[[increment operator]], [[post-increment]], [[pre-increment]], [[compound assignment]], [[expression]], [[lvalue]], [[sequence point]], [[undefined behavior]], [[operator precedence]], [[side effect]]
