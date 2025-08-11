---
title: "Do While Loop in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 11
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

## **One-liner**

A **do while** loop runs the body **once unconditionally**, then repeats **while** the condition is true — perfect for **input validation** and **menus**.

## Syntax

```c
do
{
    // body executes at least once
}
while (condition);   // note the semicolon here
```

## Minimal example (validation)

```c
int n;
do
{
    n = get_int("Number: ");
}
while (n < 1);
printf("You entered %i\n", n);
```

## When to use

- Must run the body **at least once** (prompt, menu, retry).  
- The condition depends on **data computed in the body**.  
- You want a clean “**do → check → maybe repeat**” flow.

Prefer **while** when the loop may run **zero** times or the condition is known **before** the body.

## Comparison with while

| Goal | while | do while | Clearer |
|---|---|---|---|
| Prompt until positive | Needs pre-loop read or flag | Read naturally inside loop | **do while** |
| Repeat a menu | Pre-loop input needed | Body-first suits menus | **do while** |
| Possibly skip entirely | Works naturally | Would still run once | **while** |

## Common pitfalls

- Missing the **semicolon** after `while (cond)` → compile error.  
- Using an **uninitialized variable** in the condition → undefined behavior. Initialize or assign in the body first.  
- **Infinite loop**: ensure the body changes something so the condition eventually becomes false.  
- Overusing **do while** where **while** expresses intent better.

## Pattern for menu loops

```c
int choice;
do
{
    printf("1) Play\n2) Settings\n0) Quit\n");
    choice = get_int("Choice: ");
}
while (choice != 0);
```

## Related Concepts

- [[While Loop in C]] – condition-first loop that may run zero times.
- [[Input Validation in C]] – idioms for safe prompting with get_*.
- [[Loop Invariants]] – reasoning about correctness inside loops.
- [[CS50 Library · get_Functions]] – friendly input helpers used in the examples.
- [[Control Flow in C]] – bigger picture: sequence, selection, iteration.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [cppreference — Iteration statements](https://en.cppreference.com/w/c/language/iter) 
- [C FAQ — Do-while vs while](https://c-faq.com/statements/dowhile.html)

## Terms

[[do while]], [[while loop]], [[condition]], [[iteration]], [[input validation]], [[menu loop]], [[semicolon]], [[undefined behavior]], [[loop invariant]], [[infinite loop]]
