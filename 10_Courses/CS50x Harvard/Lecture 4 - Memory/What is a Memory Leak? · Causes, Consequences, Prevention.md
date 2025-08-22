---
title: "What is a Memory Leak? · Causes, Consequences, Prevention"  
lang_tags: "#lang/c"                                      
type_tags: "#type/concept"                                 
course_tags: "#course/cs50x/intoduction_to_CS"             
lecture_tags: "#lecture/week_4_Memory"                     
tool_tags: ""                                              
status: "done"                                             
difficulty: "medium"                                       
date: "2025-08-22"                                            
review_next: "2025-09-22"                               
---

## One-liner

A **memory leak** happens when a program allocates memory but fails to release it, causing used memory to build up over time.

---

## What is a Memory Leak?

In C and other low-level languages, if you `malloc` memory but **never call `free()`**, that memory stays reserved, even if you no longer need it.

This leads to:
- Wasted memory
- Performance degradation
- Potential crashes

High-level languages (Python, Java, etc.) use **garbage collectors**, but even they can suffer from memory leaks in some cases.

---

## Symptoms

- Program uses more and more RAM over time
- System slows down
- App crashes with “Out of Memory”
- Memory monitors show constantly rising usage

---

## Causes

- Forgetting to `free()` memory
- Losing the reference (pointer) to allocated memory
- Circular references (in GC languages)
- Repeated allocations without cleanup

---

## Code Example (C)

```c
int *arr = malloc(1000 * sizeof(int));
// but forgot to free(arr);
// this block is lost if 'arr' is overwritten or goes out of scope
```

---

## Why It Matters

- Memory is limited, especially in mobile or embedded devices.
- Leaks lead to instability over time.
- Can expose sensitive data if memory is not zeroed and freed.
- In long-running systems (servers), this is fatal.

---

## Prevention

| Practice | Description |
|---------|-------------|
| `free()` every `malloc()` | Always pair allocation with deallocation |
| Check for `NULL` | malloc might fail — always verify |
| Use tools | Valgrind, AddressSanitizer (Clang), Dr. Memory |
| Avoid complexity | Simple ownership rules, centralized cleanup |
| In modern C++ | Prefer RAII / smart pointers (`std::unique_ptr`) |

---

## Related Concepts

- [[Dynamic Memory in C — malloc and free]]
- [[Pointers in C — Address-of (&) and Dereference (*)]]
- [[Stack vs Heap]]
- [[Garbage Collection vs Manual Memory Management]]
- [[Segmentation Faults]]
- [[Null Pointers and Invalid Access]]
- [[How Operating Systems Manage Memory]]

---

## See Also

- [Memory Leaks in C — GeeksForGeeks](https://www.geeksforgeeks.org/memory-leak-in-c/)
- [Valgrind — Official Documentation](https://valgrind.org/docs/)
- [StackOverflow – Why is a memory leak bad?](https://stackoverflow.com/questions/257288/)

---

## Terms

[[memory leak]], [[malloc]], [[free]], [[heap memory]], [[garbage collector]], [[null pointer]], [[memory management]]
