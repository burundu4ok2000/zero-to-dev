---
title: "Memory Leak — What It Is and How to Fix It"  
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 20
status: "done"
difficulty: "medium"
date: "2025-08-26"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/4/"
review_next: "2025-09-26"
---

![[Screenshot 2025-08-26 at 22.38.14.png]]

---

## Summary
A **memory leak** happens when a program allocates memory on the **heap** but never frees it, causing used memory to grow over time.

## Very simple

> Explain memory leak in simple terms that a 5-year-old would understand:
    1. Imagine borrowing toys and forgetting to return them.
    2. Eventually, you have no space left to play.
    3. Same with computers: memory is borrowed, but never returned.

## Key Points
- Happens in **heap memory**, not stack.
- Caused by forgetting to call `free()` after `malloc()`.
- Leads to programs using more and more memory over time.
- Can crash programs or slow down the whole system.
- Often hard to detect — need special tools or patterns.

## Details
A memory leak in C occurs when a pointer to dynamically allocated memory is lost before `free()` is called. Since the address is lost, there is no way to access or deallocate the memory anymore. The OS won’t reclaim this memory until the program ends — and sometimes not even then.

Unlike stack memory, heap memory is not automatically cleaned up. You must explicitly manage it using `malloc()` and `free()`. If you skip `free()`, memory remains occupied — even if it’s not used.

## Examples
```c
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *x = malloc(sizeof(int) * 10);
    if (x == NULL) return 1;

    x[0] = 42;
    // forget to free x
    return 0;
}
```

## **Why It Matters**
- Can cause **crashes** in long-running apps (e.g. servers, games).
- Makes software inefficient and unstable.
- Crucial in **systems programming**, embedded, and performance-sensitive apps.

## Questions

- ❓How can tools like Valgrind help find memory leaks?
- ❓Are there memory-safe languages that prevent leaks automatically?

## Related Concepts

- [[malloc and free]] – **Dynamic memory** must be managed with `malloc()`/**`free()`**.
- [[Stack vs Heap Memory]] – Leaks occur only on the **heap**.
- [[Pointers in C]] – Losing pointer reference leads to leaks.
- [[Garbage Collection Basics]] – Some languages clean up memory automatically.
- [[Valgrind Basics]] – Tool to **detect memory leaks**.
- [[CS50 Valgrind Demo]] – Example usage in CS50.
- [[Dangling Pointers]] – Related bug when pointer remains but memory is freed.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]]

## See also

- [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html)
- [Memory Leak — Wikipedia](https://en.wikipedia.org/wiki/Memory_leak)
- [CS50 2025 Lecture 4](https://cs50.harvard.edu/x/2025/weeks/4/)

## Terms

[[memory]], [[pointer]], [[heap]], [[free]], [[malloc]], [[leak]], [[memory management]], [[Valgrind]]
