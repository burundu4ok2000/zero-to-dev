---
title: "Contiguous Memory · Arrays"  
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: "#tool/os/macos, #tool/editor/vscode, #tool/shell/bash"
atom_idx: 01
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:05:42"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---
![[2025-08-07_15-07-16.png]]

> **Week:** [[Week 3 — Algorithms]]  
> **Course:** [[CS50x Harvard]]

## One Liner
Arrays in C live **contiguously** in memory: elements sit back‑to‑back, so **indexing** is O(1) and sequential loops are cache‑friendly.

## Core Idea
A C **array** reserves a single block of RAM. The block is **contiguous**: address of `a[i+1]` is address of `a[i]` plus `sizeof(element)`. This enables **pointer arithmetic**, fast **iteration**, and predictable **strides**.

### Mental Model
```
base → [ a[0] ][ a[1] ][ a[2] ][ a[3] ] …
addr   0x1000  0x1004  0x1008  0x100C     ← for **int** (4 bytes)
```
Change the type, change the stride: for **char** it’s +1, for **double** it’s +8 (on most platforms).

### Micro‑demo (C)
```c
#include <stdio.h>

int main(void) {
    int a[4] = {13, 21, 34, 55};
    for (int i = 0; i < 4; i++) {
        printf("a[%d]=%d @ %p\n", i, a[i], (void*)&a[i]);
    }
    // Proof of contiguity: &a[i+1] - &a[i] == 1 (in units of element size)
    printf("step = %td\n", &a[1] - &a[0]);
}
```
Reading addresses you’ll see each **element** is exactly one **stride** apart.

## Why It Matters
- **O(1) indexing**: `a[i]` is a simple pointer + offset.
- **Cache locality**: consecutive accesses ride the CPU cache.
- **Interop**: many **algorithms** (e.g., **binary search**, **merge sort**) assume indexable, contiguous storage.

## Gotchas
- **Out‑of‑bounds** is **undefined behavior**; there’s no bounds check.
- Arrays have **fixed size**; they don’t grow. Use **dynamic memory** (e.g., `malloc`) or **vectors** in higher‑level languages.
- `sizeof(a)` inside the same scope is bytes of the whole array; when **decayed** to a **pointer** (e.g., passed to a function), size info is lost.

## Related Concepts
- [[Arrays in C — Basics]] – foundation for indexing and iteration.
- [[Pointer Arithmetic in C]] – how offsets over **contiguous** memory work.
- [[Cache Locality — Why Contiguous Wins]] – performance angle.
- [[Binary Search — Data Preconditions]] – requires random access by index.

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [cppreference: Arrays in C](https://en.cppreference.com/w/c/language/array)
- [What Every Programmer Should Know About Memory](https://people.freebsd.org/~lstewart/articles/cpumemory.pdf)

## Terms
[[array]], [[contiguous memory]], [[index]], [[element]], [[pointer arithmetic]], [[memory address]], [[stride]], [[cache locality]]
