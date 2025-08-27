---
title: "Stack Allocation vs Malloc — Memory Management in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 26
status: "done"
difficulty: "medium"
date: "2025-08-27"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/4/"
review_next: "2025-09-27"
---

## **One-liner

> `char s[100];` uses stack memory. `char *s = malloc(100);` uses heap memory. They differ in lifetime, flexibility, and responsibility.

## Very simple

> Stack is like a **temporary box** on your desk — used while you work, cleared when you leave.  
> Malloc gives you a **locker in the hallway** — it's yours until you **manually return the key** (`free()`).

## The Big Idea 
In C, memory can be allocated in two main ways:
1. **Stack Allocation** — fast, simple, and automatic
2. **Heap Allocation** (`malloc`) — flexible but manual

Understanding when and why to use each is key to writing safe and efficient programs.

## Key Characteristics 

| Feature                    | Stack (`char s[100];`)        | Heap (`char *s = malloc(100);`)    |
|----------------------------|-------------------------------|-------------------------------------|
| **Memory Region**         | Stack                         | Heap                                |
| **Allocated at**          | Compile time                  | Runtime                             |
| **Lifetime**              | Until function exits          | Until you call `free()`             |
| **Size Flexibility**      | Fixed                         | Dynamic / Resizable (`realloc`)     |
| **Performance**           | Very fast                     | Slower (system call)                |
| **Manual free needed?**   | ❌ No                         | ✅ Yes                              |
| **Scope**                 | Local                         | Pointer can be passed around        |
| **Risk**                  | Stack Overflow                | Memory Leak / Dangling Pointer      |

## ASCII Diagrams

### 🧠 Stack Allocation (simple, scoped)
```
+----------------------------+
| main() local vars         |
|---------------------------|
| char s[100];              | ← exists only inside this function
+----------------------------+
| other function frames...  |
+----------------------------+
(Stack grows ↓)
```

### 💾 Heap Allocation (manual, long-lived)
```
+---------------------------+
| Heap memory               |
|---------------------------|
| malloc(100) → pointer →   | ← persists even after function ends
| your buffer               |
+---------------------------+
(Heap grows ↑)
```

## Examples 

### Stack

```c
void greet() {
    char name[100];
    scanf("%s", name);
    printf("Hello, %s\n", name);
}  // name disappears here
```

### Heap

```c
char *name = malloc(100);
scanf("%s", name);
printf("Hello, %s\n", name);
free(name);  // must release manually
```

## When to use what?

### ✅ Use **stack** when:
- Size is fixed and small
- You don’t need the data after the function ends

### ✅ Use **malloc** when:
- You need variable size
- You want the memory to persist beyond a function
- You build dynamic structures (linked lists, trees, graphs)
- You need large buffers (stack is small!)

## Memory Size Differences

```
Stack: ~1–8 MB (can crash with big arrays)
Heap:  up to GBs (limited by system RAM)
```

Example:
```c
int big_array[1000000]; // ❌ stack overflow
int *big_array = malloc(1000000 * sizeof(int)); // ✅ works fine
```

## Gotchas & Dangers

- ❗ Forgetting `free()` = **memory leak**
- ❗ Losing pointer = leak you can’t recover
- ❗ Freeing stack memory = undefined behavior
- ❗ Heap allocations are slower and must be checked for NULL

## Related Concepts

- [[malloc and free]] – main functions for heap management.
- [[Stack vs Heap Memory]] – core distinction of lifetime and structure.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]]
- [[Memory Leak — What It Is and How to Fix It]]
- [[Dangling Pointers]] – when pointer points to freed memory.
- [[Valgrind Basics]] – detects leaks and misuse.

## See Also

- [C Programming: Stack vs Heap](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/)
- [Valgrind Leak Checks](https://valgrind.org/)
- [malloc() vs array allocation](https://stackoverflow.com/questions/4412747/why-use-malloc-instead-of-array-declaration)

## Terms

[[stack]], [[heap]], [[malloc]], [[free]], [[memory allocation]], [[realloc]], [[pointer]], [[scope]], [[lifetime]]
