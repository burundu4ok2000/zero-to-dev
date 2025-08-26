---
title: Garbage Values and Crashes in C
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 15
status: done
difficulty: medium
date: 2025-08-22
timecode: 00:38:12
source: https://cs50.harvard.edu/x/2025/weeks/4/
review_next: 2025-09-22
---

![[Screenshot 2025-08-22 at 18.44.54.png]]

---

## Summary
**Garbage values** are unpredictable data left in memory when variables are used before being initialized. This can lead to **crashes** and undefined behavior in C programs.

## Very simple

> If you take a random box from your attic and assume there’s a sandwich inside… you’re gonna have a bad time. Same with C memory.

## Key Points
- C does **not** automatically initialize variables → they may contain **random bits**.
- Using these uninitialized variables can cause **unexpected results** or **crashes**.
- These values are called **garbage values**.
- Common cause of **undefined behavior** in C.
- Always initialize variables **before using them**.

## Details
- C leaves memory in the state it was last used → new variables may pick up leftover data.
- No warnings unless you use a tool like **Valgrind**.
- Example:
```c
int x;
printf("%i", x);  // garbage value!
```
- Memory might contain old values from other parts of your program or system.

## Examples
```c
int x;
if (x == 42)     // x might be any number here
{
    printf("Meaning of life\n");
}
```
- May work sometimes, crash other times — that's the danger.

## **Why It Matters**
- Preventing bugs and crashes in low-level programming.
- Essential for writing **reliable C code**.
- Connects to **pointers**, **heap memory**, and tools like **Valgrind**.

## Questions
- ❓ Does the compiler *ever* initialize variables by default?
- ❓ What are other symptoms of using garbage values?

## Related Concepts
- [[Pointers in C — Address-of (&) and Dereference (*)]] – use memory directly, garbage values affect behavior.
- [[Dynamic Memory Allocation in C]] – `malloc` returns uninitialized memory.
- [[Valgrind for CS50 · Detecting Memory Leaks and Invalid Access]] – helps detect use of garbage values.
- [[What is a Memory Leak? · Causes, Consequences, Prevention]] – not initializing memory may lead to leaks.
- [[Segmentation Faults]] – garbage pointers may cause crashes.
- [[Pointer Arithmetic in C]] – garbage values impact pointer offsets.
- [[Memory Layout of a Program]] – stack space might retain garbage values.

## See also
- [Valgrind Documentation](https://valgrind.org/docs/manual/)
- [CS50 Week 4 Notes](https://cs50.harvard.edu/x/2025/notes/4/)
- [GeeksforGeeks – Uninitialized Variables in C](https://www.geeksforgeeks.org/what-are-garbage-values-in-c/)

## Terms
[[garbage value]], [[memory initialization]], [[undefined behavior]], [[valgrind]], [[stack memory]], [[crash]], [[c language]]
