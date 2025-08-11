---
title: "While Loop Countdown in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 35
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-15 at 16.00.02.png]]

---

## **One-liner**

A **while loop** repeats a block **as long as** its **condition** is true. You can **count down** or **count up**—pick whichever makes the condition clearest.

## Example 1 — Countdown

```c
int i = 3;
while (i > 0)
{
    printf("meow\n");
    i--;                 // update toward termination
}
```

### Output

```
meow
meow
meow
```

## Example 2 — Count-up (popular pattern)

```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;                 // move toward i == 3
}
```

This version counts **up from 0**, rather than down from 3 — but it does the exact same thing in terms of number of loops.

✅ This is often considered the **most popular and readable loop form**, especially for:

- Beginner-friendly logic (`0 to N`)
- Arrays (which are 0-indexed)
- Aligning with loop constructs like `for` (which often follow the same structure)

## Visual trace

| i | i < 3? | Output  |
|---|--------|---------|
| 0 | true   | meow    |
| 1 | true   | meow    |
| 2 | true   | meow    |
| 3 | false  | (stop)  |

## Key concepts recap

| Concept | Explanation |
|---|---|
| `while (condition)` | Executes the block as long as the **condition** is true |
| `i++` / `i--` | Update step that moves toward loop **termination** |
| Loop termination | Happens when the condition becomes **false** |

## When to use **while**

- Iterations not known upfront (read until **sentinel**, loop until a **condition** flips).  
- Prefer **condition-first** style (may run **zero** times) vs **do while** (runs at least once).  
- Want a shape like `for` but with flexible **initialization** or **update** placement.

## Common pitfalls

- **Forgetting the update** (`i--`/`i++`) → **infinite loop**.  
- **Off-by-one** errors: decide `< n` or `<= n-1`.  
- Mutating the condition variable in multiple places → hard to reason; keep updates consistent.  
- Wrong **format specifier** when printing counters (use `%i`/`%d`).

## Pattern variants

```c
// loop until user types 0 (sentinel)
int n;
while ((n = get_int("n (0 to stop): ")) != 0) { /* ... */ }

// iterate array of length len
int i = 0;
while (i < len) { /* use a[i] */ i++; }
```

## Related Concepts

- [[Lecture 1 - C]] – lecture context for while/for/do-while.  
- [[For Loop in C]] – compact counting loop for known bounds.  
- [[Do While Loop in C]] – body-first loop that runs at least once.  
- [[Incrementing a variable in C]] – `i++`, `++i`, and `+=`.  
- [[Off-by-one Errors]] – spotting and preventing fencepost mistakes.  
- [[Conditionals Overview in C]] – the checks that drive loop conditions.  
- [[Control Flow in C]] – where loops fit among sequence/selection.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [cppreference — Iteration statements](https://en.cppreference.com/w/c/language/iteration_statements)  
- [C FAQ — while loop patterns](https://c-faq.com/)

## Terms

[[while loop]], [[loop condition]], [[iteration]], [[counter]], [[decrement]], [[post-increment]], [[loop termination]], [[sentinel]], [[infinite loop]], [[fencepost problem]]
