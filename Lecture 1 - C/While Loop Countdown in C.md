> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]

![[Screenshot 2025-07-15 at 16.00.02.png]]

---

## Example 1 — Countdown

```c
int i = 3;
while (i > 0)
{
    printf("meow\n");
    i--;
}
```

### Output

```
meow
meow
meow
```

---

## Example 2 — Count-up (popular pattern)

```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```

This version counts **up from 0**, rather than down from 3 — but it does the exact same thing in terms of number of loops.

✅ This is often considered the **most popular and readable loop form**, especially for:

- Beginner-friendly logic (`0 to N`)
- Arrays (which are 0-indexed)
- Aligning with loop constructs like `for` (which often follow the same structure)

---

## Visual trace

| i | i < 3? | Output  |
|---|--------|---------|
| 0 | true   | meow    |
| 1 | true   | meow    |
| 2 | true   | meow    |
| 3 | false  | (stop)  |

---

## Key Concepts Recap

| Concept        | Explanation |
|----------------|-------------|
| `while (condition)` | Executes the block as long as the condition is true |
| `i++`           | Post-increment — adds 1 to `i` after each iteration |
| Loop termination | Happens when the condition becomes false (`i < 3` fails at `i = 3`) |

---

## Notes

- The choice between counting **up or down** is stylistic unless logic requires one.
- Count-up loops are common when indexing arrays:  
  ```c
  while (i < length) { … }
  ```