---
title: "Stack Overflow vs Heap Overflow — Memory Crashes Explained"  
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 22
status: "done"
difficulty: "medium"
date: "2025-08-27"
timecode: "1:49:00–1:50:00"
source: "https://cs50.harvard.edu/x/2025/weeks/4/"
review_next: "2025-09-27"
---

![[Screenshot 2025-08-27 at 11.10.04.png]]

---

## Summary
**Stack Overflow** and **Heap Overflow** are two types of memory errors that crash programs. Both happen when memory regions grow too large and cross their allowed boundaries.

## Very simple

> Imagine you’re stacking boxes on top of each other (**stack**), or laying them out in a line (**heap**).  
> If you stack too high — it falls over.  
> If your line of boxes runs out of space — it spills into someone else’s stuff. That’s a crash!

## Key Points
- **Stack Overflow** happens when too many function calls fill up the stack.
- Often caused by **infinite recursion** or too many nested calls.
- **Heap Overflow** occurs when a program writes beyond allocated heap memory.
- Often caused by **bad indexing**, like writing outside an array from `malloc`.
- Both lead to **undefined behavior**, crashes, or security vulnerabilities.

## Details

### Stack Overflow
- Each function call takes space on the **stack**.
- When the stack limit is exceeded, the program **crashes**.
- Very common in **recursion without a base case**.

```c
void boom(void)
{
    boom();  // no base case
}

int main(void)
{
    boom();  // will cause stack overflow
}
```

### Heap Overflow
- Happens when you **write past the boundary** of dynamically allocated memory.
- Unlike stack overflow, heap overflow often silently corrupts data before crashing.

```c
int *arr = malloc(3 * sizeof(int));
arr[3] = 42; // invalid — index 3 is out of bounds!
```

## **Why It Matters**
- Both are serious bugs in C and low-level languages.
- They can be used by attackers to **exploit** systems (buffer overflows).
- Understanding them is essential for safe memory management and debugging.

## Questions

- ❓How can we detect a heap overflow before it breaks something?
- ❓Are there protections in modern OSes or compilers against stack overflows?

## Related Concepts

- [[malloc and free]] – improper use leads to heap issues.
- [[Stack vs Heap Memory]] – understanding the growth directions helps explain both overflows.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]] – where overflow happens.
- [[Recursion Basics — Drawing a Pyramid]] – example of stack overflow risk.
- [[Valgrind Basics]] – tool to detect memory overflows and leaks.
- [[Dangling Pointers]] – related to misuse of memory.
- [[Memory Leak — What It Is and How to Fix It]]
- [[Call Stack in C]]

## See also

- [GeeksForGeeks — Stack vs Heap Overflow](https://www.geeksforgeeks.org/stack-vs-heap-overflow/)
- [Valgrind for memory errors](https://valgrind.org/)
- [Stack Overflow (Wikipedia)](https://en.wikipedia.org/wiki/Stack_overflow)

## Terms

[[stack]], [[heap]], [[stack overflow]], [[heap overflow]], [[recursion]], [[memory corruption]], [[malloc]], [[array bounds]], [[crash]], [[valgrind]]
