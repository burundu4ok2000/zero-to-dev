---
title: Week 3 Shorts - Collatz Recursion
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#shorts/week_3_Algorithms/recursion"
tool_tags: ""
atom_idx: 17
status: done
difficulty: easy
date: 2025-08-15
timecode: 11:56
source: https://cs50.harvard.edu/x/2025/shorts/recursion/
review_next: 2025-09-15
---

---

![[Screenshot 2025-08-15 at 19.59.12.png]]
![[Screenshot 2025-08-15 at 19.59.01.png]]

---

## Summary
**Collatz recursion** counts how many steps it takes to reach **1** by repeatedly applying:  
- if **n is even** → `n = n/2`  
- if **n is odd** → `n = 3*n + 1`  

The function returns the number of steps.

## Very simple
Take a number. If it's **even**, cut it in half. If it's **odd**, triple it and add one. Repeat until you see **1**. Count how many moves you made. That's the **Collatz number** for your start.

## Key Points
- Has a clear **base case**: when `n == 1`, **stop** and return **0** steps.
- **Recursive case** adds **1** step then calls itself with the next `n`.
- Uses **modulo** (`n % 2`) to test even vs odd.
- Famous as the **Collatz conjecture**: every positive integer *seems* to reach 1, but nobody has proved it for all numbers.

## Details
C implementation (steps count):
```c
int collatz(int n)
{
    // base case
    if (n == 1)
        return 0;

    // even numbers
    else if (n % 2 == 0)
        return 1 + collatz(n / 2);

    // odd numbers
    else
        return 1 + collatz(3 * n + 1);
}
```

### Example chains
- `n = 1` → steps `0`  
- `n = 2` → `2 → 1` → steps `1`  
- `n = 3` → `3 → 10 → 5 → 16 → 8 → 4 → 2 → 1` → steps `7`  
- `n = 7` → `7 → 22 → 11 → 34 → 17 → 52 → 26 → 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1` → steps `16`

## Examples
### Minimal driver
```c
#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n = get_int("n: ");
    printf("steps: %i\n", collatz(n));
}

int collatz(int n)
{
    if (n == 1) return 0;
    if (n % 2 == 0) return 1 + collatz(n / 2);
    return 1 + collatz(3 * n + 1);
}
```

## Why It Matters
Great practice for **recursion**: spot a **base case**, define the **smaller subproblem**, and combine results (+1 per step). Also a fun gateway to open problems in math.

## Questions
- ❓ How deep can recursion go before you risk **stack overflow** for large `n`?
- ❓ Can you write an **iterative** (loop) version that returns the same step count?

## Related Concepts
- [[Call Stacks — Function Push-Pop Flow]] – how recursive calls push frames.
- [[Recursion Basics — Drawing a Pyramid]] – base vs recursive case patterns.
- [[Merge Sort — Recursion Flow]] – divide-and-conquer recursion tree.
- [[Binary Search — Recursive Implementation]] – another classic recursive function.
- [[Function Parameters & Locals in C]] – what lives in each stack frame.
- [[Memory Layout in C Programs]] – stack vs heap.
- [[Selection Sort — From Summation to O(n²)]] – iterative contrast to recursion.
- [[Return Address and Control Flow]] – where execution resumes after returns.

## See also
- [CS50 Shorts — Recursion](https://cs50.harvard.edu/x/2025/shorts/recursion/)
- [Wikipedia — Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture)
- [Numberphile video on Collatz](https://www.youtube.com/watch?v=094y1Z2wpJg)

## Terms
[[recursion]], [[base case]], [[recursive case]], [[Collatz conjecture]], [[modulo operator]], [[integer division]], [[termination]], [[call stack]]
