---
title: "Recursion Basics — Drawing a Pyramid"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 12
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "01:44:38"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_19-44-21.png]]

---

## Summary
**Recursion** is when a function calls itself to solve a smaller version of the same problem. A correct recursive solution has a **base case** (stop) and a **recursive case** (shrink the problem), and runs on the **call stack** until the base case is reached.

## Minimal pattern
```c
// Draws a left-aligned pyramid of height n
#include <stdio.h>

void draw(int n) 
{
    if (n <= 0) return;                  // **base case**
    draw(n - 1);                         // **recursive case**: solve smaller problem
    for (int i = 0; i < n; i++) printf("#");
    printf("\n");
}

int main(void) {
    draw(4);
}


```

Output:
```
#
##
###
####
```

## How it works (step-by-step)
- **Base case**: If `n` is less than or equal to 0, do nothing and stop. This keeps the process from going on forever.
- **Recursive case**: First, do the same thing with `n-1`. Then, print the `n`th row.
- The **call stack** is like a pile of boxes. Each box holds a call. As `n` gets bigger, the pile gets taller, up to about `n` boxes high.

## Complexity
- **Time**: printing `1 + 2 + ... + n = n(n+1)/2` characters ⇒ **O(n²)** overall.
- **Space**: extra **O(n)** due to the **call stack** depth (one frame per level).

## Pitfalls & edge cases
- Missing **base case** → infinite recursion → **stack overflow**.
- Doing work **before** the recursive call flips the order (top-heavy pyramid).
- Large `n` risks deep recursion; in C, prefer an **iterative** approach if stack limits are tight.

## Iterative alternative
```c
void draw_iter(int n) 
{
    for (int r = 1; r <= n; r++) {
        for (int i = 0; i < r; i++) printf("#");
        printf("\n");
    }
}
```

## When to use recursion
- Natural **divide-and-conquer** (e.g., **merge sort**, **quick sort**).
- Problems defined in terms of **smaller subproblems** (trees, DFS).  
If recursion only adds stack risk and no clarity, prefer **iteration**.

## Related Concepts
- [[Merge sort]] – recursive split/merge gives **O(n log n)**
- [[Quicksort]] – recursive partitioning; average **O(n log n)**
- [[Call stack]] – where **stack frames** live during recursion
- [[Base case vs Recursive case]] – design pattern for correctness
- [[Stack overflow]] – failure mode when recursion is too deep

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Recursion — Wikipedia](https://en.wikipedia.org/wiki/Recursion_(computer_science))
- [GeeksforGeeks: Recursion basics in C](https://www.geeksforgeeks.org/recursion/)

## Terms
[[Recursion]], [[Base case]], [[Recursive case]], [[Call stack]], [[Stack frame]], [[Stack overflow]], [[Iterative]], [[Divide and conquer]]
