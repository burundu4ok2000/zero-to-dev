---
title: "Valgrind for CS50 · Detecting Memory Leaks and Invalid Access"  
lang_tags: "#lang/c"                                      
type_tags: "#type/tool"                                 
course_tags: "#course/cs50x/intoduction_to_CS"             
lecture_tags: "#lecture/week_4_Memory"                     
tool_tags: "#tool/valgrind"                                              
status: "done"                                              
difficulty: "medium"                                       
date: "2025-08-22"                                            
review_next: "2025-09-22"                               
---

## One-liner

**Valgrind** is a debugging tool that checks your C programs for **memory leaks**, **invalid reads/writes**, and **unfreed heap allocations** — extremely useful for CS50 and beyond.

---

## What is Valgrind?

Valgrind runs your program inside a special environment and watches every memory access. It can tell you:

- If you forgot to `free()` memory
- If you're reading from or writing to memory you shouldn't
- If you're using uninitialized memory
- Where exactly in your code the issue happened

---

## Why CS50 Uses Valgrind

In Week 4, you begin working with **pointers**, **malloc**, and **arrays** — which can easily lead to **memory bugs**.

Valgrind helps catch these **silent errors** early:

```sh
valgrind ./program
```

You’ll see output like:

```sh
//==1234== 40 bytes in 1 blocks are definitely lost in loss record 1 of 2
//==1234==    at 0x4C2F1F3: malloc (vg_replace_malloc.c:299)
//==1234==    by 0x10869B: main (memory.c:5)
```

This means: **you forgot to free something malloc’ed on line 5**.

---

## How to Use It in CS50 IDE

In the CS50 IDE (based on Ubuntu):

1. Compile your code with debugging symbols:
   ```sh
   clang -g -o program program.c
   ```

2. Run Valgrind:
   ```sh
   valgrind ./program
   ```

3. Add `--leak-check=full` for full report:
   ```sh
   valgrind --leak-check=full ./program
   ```

---

## Output Interpretation

| Message                             | Meaning |
|-------------------------------------|---------|
| `definitely lost`                   | You forgot to `free()` memory |
| `indirectly lost`                   | A pointer inside another struct was lost |
| `invalid read/write`                | You're accessing memory that isn't yours |
| `uninitialised value`               | You're using a variable before assigning a value |

---

## Best Practices

- Always compile with `-g` so Valgrind can show line numbers.
- Run Valgrind after big changes or if you use `malloc`.
- Fix the **first reported error first** — others may be side effects.

---

## Related Concepts

- [[Dynamic Memory in C — malloc and free]]
- [[What is a Memory Leak? · Causes, Consequences, Prevention]]
- [[Segmentation Faults]]
- [[Pointers in C — Address-of (&) and Dereference (*)]]
- [[Null Pointers and Invalid Access]]
- [[CS50 Debugging Tools Overview]]

---

## See Also

- [Valgrind Official Docs](https://valgrind.org/docs/)
- [Using Valgrind (CS50 Shorts)](https://www.youtube.com/watch?v=RZ4Sn-Y7AP8)
- [Valgrind Tutorial — GfG](https://www.geeksforgeeks.org/valgrind-tool-in-linux/)

---

## Terms

[[valgrind]], [[memory leak]], [[heap memory]], [[malloc]], [[invalid access]], [[debugging tool]], [[pointer errors]], [[memory checker]]
