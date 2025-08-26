---
title: "Memory Layout of a Program — Stack, Heap, Globals, Machine Code"  
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 21
status: "done"
difficulty: "medium"
date: "2025-08-26"
timecode: "1:47:00–1:49:00"
source: "https://cs50.harvard.edu/x/2025/weeks/4/"
review_next: "2025-09-26"
---

![[Screenshot 2025-08-26 at 22.38.14.png]]
![[Screenshot 2025-08-26 at 22.50.53.png]]

---

## Summary
The memory layout of a running C program is divided into distinct **regions**: machine code, globals, **heap**, and **stack** — each with a specific role. Understanding this helps explain how variables, memory allocation, and function calls work under the hood.

## Very simple

> Imagine memory like a tall building with different floors:
> - At the top: **machine code** (your program's instructions)
> - Below it: permanent stuff like **global variables**
> - In the middle: two elevators — one grows **down** (heap), the other grows **up** (stack)
> - If they crash into each other — game over.

## Key Points
- **Machine code** is at the top — it’s the compiled instructions, read-only.
- **Globals** store global and static variables.
- **Heap** grows downward, used for dynamic memory (`malloc()`).
- **Stack** grows upward, used for function calls and local variables.
- If stack and heap grow too much, they **collide**, causing a crash.
- When you call a function, its variables go onto the **stack** (in a frame).
- When the function returns, its stack frame is **popped off**.

## Details

### Memory Layout from Top to Bottom
| Region         | Description                              |
|----------------|-------------------------------------------|
| Machine Code   | Actual instructions of the program        |
| Globals        | Variables defined globally or as static   |
| Heap (↓)       | Dynamic memory — grows downward           |
| Stack (↑)      | Function frames — grows upward            |

---

- The **heap** is used when we do something like `malloc`. You can think of it as space you **manually request**.
- The **stack** is automatically used every time you call a function. It stores function-specific data like parameters and local variables.
- When `main()` calls `swap()`, a **new stack frame** is added on top of `main()`. When `swap()` ends, that frame is removed.
- This is how **nested function calls** work — like stacking dishes. Last called = first returned (LIFO).

## Examples

```c
void swap(int a, int b)
{{
    int tmp = a;
    a = b;
    b = tmp;
}}

int main(void)
{{
    int x = 1;
    int y = 2;
    swap(x, y);
}}
```

### Stack Trace (Illustrated)

```
STACK (grows ↑)

|  swap() frame  | ← created when swap is called
|  main() frame  |
+----------------
```

## **Why It Matters**

- Helps debug issues like **stack overflow**, **memory leaks**, or **dangling pointers**.
- Helps understand how **variables live and die**, and what happens during a **function call**.
- Understanding this layout is critical for **systems programming**, **security**, and **low-level debugging**.

## Questions

- ❓What happens if the stack grows too big?  
- ❓Can heap and stack overlap?

## Related Concepts

- [[Call Stack in C]] – explains how **function calls** are stacked and returned.
- [[Stack vs Heap Memory]] – comparison of their use and behavior.
- [[malloc and free]] – how heap memory is allocated and released.
- [[Pointers in C]] – allow access to different memory regions.
- [[Memory Leak — What It Is and How to Fix It]] – when heap memory isn't freed.
- [[Recursion Basics — Drawing a Pyramid]] – recursive calls build deep stack frames.
- [[Dangling Pointers]] – caused by improper memory access.
- [[Valgrind Basics]] – tool to inspect memory issues.

## See also

- [CS50 Lecture 4 Notes](https://cs50.harvard.edu/x/2025/weeks/4/)
- [Stack vs Heap — GeeksForGeeks](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/)
- [Memory Layout in C — Tutorialspoint](https://www.tutorialspoint.com/memory-layout-of-c-program)

## Terms

[[stack]], [[heap]], [[memory layout]], [[machine code]], [[global variables]], [[stack frame]], [[malloc]], [[stack overflow]], [[stack trace]], [[recursion]]
