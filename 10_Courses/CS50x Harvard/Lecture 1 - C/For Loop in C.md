---
title: "For Loop in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 13
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-15 at 16.16.34.png]]

---

## **One-liner**

A **for loop** is a compact counting loop: put **initialization**, **condition**, and **update** in one header to iterate predictably.

## Syntax

```c
for (initialization; condition; update)
{
    // body
}
```

## Minimal example

```c
for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}
```

**Output**

```
meow
meow
meow
```

## Structure breakdown

| Part | Example | What it does |
|---|---|---|
| **initialization** | `int i = 0` | Runs once before the loop starts |
| **condition** | `i < 3` | Checked before each iteration; **false** exits the loop |
| **update** | `i++` | Runs after each iteration |

## When to prefer **for**

- You **know the loop count** or clear bounds (`0..N-1`).  
- You’re iterating **array indexes** or **counters**.  
- You want all loop control in the header for **readability**.

Same logic with **while**:

```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```

## Common patterns

### Count down

```c
for (int i = n; i > 0; i--) { /* ... */ }
```

### Step by 2 (or any stride)

```c
for (int i = 0; i < n; i += 2) { /* ... */ }
```

### Iterate array

```c
for (int i = 0; i < len; i++)
{
    sum += a[i];
}
```

## Gotchas

- **Off-by-one** errors: verify whether the last valid index is `i < n` (usual) or `i <= n` (rare).  
- Variable **scope**: `for (int i = ...)` confines `i` to the loop; it’s **not visible** after the loop.  
- Changing the loop variable inside the body can hurt **readability**; keep updates in the header.  
- Beware **infinite loops**: ensure the **update** eventually makes the **condition** false.  
- Use **break** and **continue** sparingly; they can obscure control flow.

## Related Concepts

- [[While Loop in C]] – condition-first loop that can run zero times.
- [[Do While Loop in C]] – body-first loop that runs at least once.
- [[Array Indexing in C]] – bounds and iteration idioms.
- [[Off-by-one Errors]] – how to spot and prevent fencepost mistakes.
- [[Control Flow in C]] – sequencing, selection, and iteration together.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [cppreference — `for` statement](https://en.cppreference.com/w/c/language/for)
- [C FAQ — Loop pitfalls](https://c-faq.com/)

## Terms

[[for loop]], [[counter]], [[initialization]], [[condition]], [[update expression]], [[loop body]], [[scope]], [[off-by-one]], [[break]], [[continue]], [[array index]], [[stride]], [[infinite loop]]
