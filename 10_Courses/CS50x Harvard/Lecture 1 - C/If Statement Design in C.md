---
title: "If Statement Design in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 21
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

## **One-liner**

Choose between **separate ifs** and an **if / else if / else ladder** based on intent: **independent** checks vs **mutually exclusive** branches.

## Comparing the two approaches

| Pattern | Example code | Tests per run | Pros | Cons |
|---|---|---|---|---|
| **Standalone if × 3** | `if (x < y) { … }`<br>`if (x > y) { … }`<br>`if (x == y) { … }` | Always **3** | Simple; each block independent | Wastes extra checks after a match; hides exclusivity |
| **if … else if … else** | `if (x < y) { … }`<br>`else if (x > y) { … }`<br>`else { … }` | **1–2** (chain stops once a match is found) | Short‑circuits; signals exclusivity | Slightly more syntax to remember |

## Scaling up

Need more than three branches? Extend the ladder:

```c
if (grade >= 90)      { /* ... */ }
else if (grade >= 80) { /* ... */ }
else if (grade >= 70) { /* ... */ }
else                  { /* below 70 */ }
```

Or, when checking **one** variable against many **discrete values**, prefer a **switch**.

## Rules of thumb

- Use **else if / else** when **only one** branch should run.  
- Use **separate ifs** when **multiple** branches might all need to run.  
- For **4+** options on the **same** variable, consider a **switch** for readability.

> Performance note: compilers optimize both well, but clear intent prevents accidental double‑work and bugs in real code.

## Gotchas

- Accidental **dangling else**: ensure your `else` pairs with the intended `if` (brace and indent consistently).  
- Overlapping conditions in separate `if`s can fire **multiple** branches unless that’s truly intended.  
- Repeating expensive predicates across several `if`s — compute once, reuse a variable.

## Related Concepts

- [[Conditionals Overview in C]] – picking between if, switch, and ternary.
- [[If If If Else Pattern in C]] – how an `else` binds only to the nearest `if`.
- [[Switch Statement in C]] – when cases are discrete and exclusive.
- [[Logical Operators in C]] – composing boolean expressions.
- [[Comparison Operators in C]] – the inputs to your conditions.
- [[Control Flow in C]] – where selection fits among sequence and loops.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [cppreference — Selection statements](https://en.cppreference.com/w/c/language/selection)
- [Wikipedia — Dangling else](https://en.wikipedia.org/wiki/Dangling_else)

## Terms

[[if statement]], [[else if]], [[else]], [[boolean expression]], [[mutually exclusive]], [[dangling else]], [[switch statement]], [[branch]], [[predicate]], [[short-circuit]]
