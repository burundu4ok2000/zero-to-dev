---
title: "If If If Else Pattern in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 20
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-19 at 20.45.13.png]]

---

## **One-liner**

The **if / if / if / else** pattern means only the **last if** is paired with the **else**; earlier **if** blocks are **independent** and can all run.

## What this pattern looks like

```c
if (cond1)
{
    // branch 1
}
if (cond2)
{
    // branch 2
}
if (cond3)
{
    // branch 3
}
else
{
    // branch 4
}
```

Only the **final** `if` attaches to `else`. The first two `if`s are separate tests.

## Execution model

1. Evaluate `cond1`. If true → run branch 1.  
2. Evaluate `cond2`. If true → run branch 2.  
3. Evaluate `cond3`. If true → run branch 3, **else** run branch 4.

Branches 1 and 2 **don’t block each other**. One, both, or neither may execute regardless of what happens with `cond3`.

## When (rarely) to use

- Multiple **independent** side‑effects plus a final mutually exclusive choice.  
- **Logging** or accumulating flags, then a final fallback action.  
- Mirroring a **truth table** literally for clarity.

## Common misunderstanding

Intended ladder:

```c
if (cond1) { … }
else if (cond2) { … }
else if (cond3) { … }
else { … }
```

Accidentally writing independent `if`s leads to **more than one** block executing unexpectedly.

## How to refactor

| Intention | Safer structure |
|---|---|
| Exactly one branch should run | **if / else if / else** chain |
| Possibly many branches run | Separate **if** statements (no trailing `else`) |
| One variable vs many constants | **switch** (for discrete cases) |

## Anti‑pattern warning

```c
if (score >= 90) { grade = 'A'; }
if (score >= 80) { grade = 'B'; }
if (score >= 70) { grade = 'C'; }
else             { grade = 'F'; }
```

A score of 95 sets `'A'` then **overwrites** with `'B'`. Use a ladder:

```c
if (score >= 90)       grade = 'A';
else if (score >= 80)  grade = 'B';
else if (score >= 70)  grade = 'C';
else                   grade = 'F';
```

## Checklist

- Should **only one** branch run? Use a ladder.  
- Attach the `else` to the **intended** `if` (brace/indent consistently).  
- Don’t mix independent `if`s with a single `else` unless you truly need that pairing.

## Related Concepts

- [[Conditionals Overview in C]] – choosing between **if**, **switch**, and **ternary**.
- [[Switch Statement in C]] – when cases are discrete and mutually exclusive.
- [[Logical Operators in C]] – compose **boolean expressions** correctly.
- [[Comparison Operators in C]] – inputs to your conditions.
- [[Control Flow in C]] – where selection fits among sequence/loops.
- [[Refactoring Techniques in C]] – make intent explicit with structure.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [cppreference — Selection statements](https://en.cppreference.com/w/c/language/selection)
- [Wikipedia — Dangling else](https://en.wikipedia.org/wiki/Dangling_else)

## Terms

[[if statement]], [[else if]], [[else]], [[dangling else]], [[boolean expression]], [[branch]], [[truth table]], [[refactoring]]
