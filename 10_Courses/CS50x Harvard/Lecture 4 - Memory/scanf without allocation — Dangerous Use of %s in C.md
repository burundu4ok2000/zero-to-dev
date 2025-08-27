---
title: "scanf without allocation — Dangerous Use of %s in C"  
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 25
status: "done"
difficulty: "medium"
date: "2025-08-27"
timecode: "2:07:30"
source: "https://cs50.harvard.edu/x/2025/weeks/4/"
review_next: "2025-09-27"
---

![[Screenshot 2025-08-27 at 11.34.09 1.png]]

![[Screenshot 2025-08-27 at 11.59.02.png]]


---

## Summary
This code looks simple but is **very dangerous**. Using `scanf("%s", s);` on an **uninitialized pointer** can crash your program or cause memory corruption.

## Very simple

> You ask someone to **write a letter** on a piece of paper — but you never gave them any paper.  
> So they just start scribbling wherever they can. That’s what happens here.

## Key Points
- `char *s;` declares a pointer, but doesn’t point it **anywhere**.
- `scanf("%s", s);` tries to store input **at that location** — but it's **undefined**.
- The program might **crash**, overwrite random memory, or even seem to "work" — but it’s wrong.
- This is **undefined behavior** and a classic bug in C.

## Details

### Code from lecture:

```c
#include <stdio.h>

int main(void)
{
    char *s;
    printf("s: ");
    scanf("%s", s);  // ❌ undefined behavior
    printf("s: %s\n", s);
}
```

- `s` is a pointer, but it doesn’t point to any valid memory.
- `scanf("%s", s)` assumes `s` already points to a writable buffer — but it doesn’t.
- This causes a **segmentation fault**, or worse — **buffer overflow**, if the memory was accidentally writable.

## Safer Alternatives

```c
char s[100];
scanf("%s", s);  // ✅ safe: s is a real array

// OR
char *s = malloc(100);
scanf("%s", s);  // ✅ valid if you free it later
```

## **Why It Matters**
- This kind of bug is **easy to make** and **hard to spot**.
- It can lead to **crashes**, **security vulnerabilities**, or subtle corruption.
- It shows why **C is powerful but dangerous** — you must manage memory **manually**.

## Questions

- ❓Why doesn’t the compiler warn about this?
- ❓How can tools help catch such bugs before runtime?

## Related Concepts

- [[Buffer Overflow — Exploiting Memory via Arrays]] – same type of memory violation.
- [[malloc and free]] – how dynamic memory is correctly allocated.
- [[Pointers in C]] – explains what happens when pointers are uninitialized.
- [[Valgrind Basics]] – helps find invalid reads/writes like this.
- [[Dangling Pointers]] – related concept of invalid memory access.
- [[Stack vs Heap Memory]] – where buffers and pointers usually live.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]]

## See also

- [C Programming FAQ — scanf pitfalls](https://stackoverflow.com/questions/20261617/why-doesnt-scanf-work-properly)
- [Segmentation Fault — Wikipedia](https://en.wikipedia.org/wiki/Segmentation_fault)
- [Valgrind Memory Checker](https://valgrind.org/)

## Terms

[[scanf]], [[pointer]], [[undefined behavior]], [[memory corruption]], [[segmentation fault]], [[malloc]], [[stack]], [[heap]]
