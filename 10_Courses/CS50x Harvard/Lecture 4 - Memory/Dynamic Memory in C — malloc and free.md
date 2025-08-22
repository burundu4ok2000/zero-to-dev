---
title: "Dynamic Memory in C — malloc and free"  
lang_tags: "#lang/c"                                        
type_tags: "#type/lecture"                                      
course_tags: "#course/cs50x/intoduction_to_CS"                                        
lecture_tags: "#lecture/week_4_Memory"                                    
atom_idx: "26"                                          
status: "done"                                              
difficulty: "medium"                                          
date: "2025-08-22"                             
timecode: "01:07:00"                                          
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                             
review_next: "2025-09-22"                                      
---

## Summary
In C, **dynamic memory allocation** allows you to request memory at runtime using `malloc` (memory allocate) and release it later using `free`. This is essential when the size of data is not known in advance, or when you want data to persist beyond function scope.

## Very Simple

> `malloc` gives you memory. `free` gives it back.

---

## malloc
- Function: `void *malloc(size_t size);`
- Allocates `size` bytes of memory on the **heap**.
- Returns a **pointer** to the first byte of that memory.
- If allocation fails → returns `NULL`.

```c
int *x = malloc(4); // 4 bytes for an int
*x = 42;
```

You must `#include <stdlib.h>` to use `malloc`.

---

## free
- Function: `void free(void *ptr);`
- Frees memory previously allocated by `malloc` (or `calloc`, `realloc`).
- After calling `free`, the pointer becomes **invalid**.

```c
free(x); // x was allocated by malloc
```

⚠️ Never call `free` on a pointer you didn’t get from `malloc`.

---

## Why Use It?
- You don’t always know how much memory you need in advance.
- **Return arrays** from functions (stack data disappears after return).
- Store data that lives beyond one function call.

---

## Example

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = malloc(3 * sizeof(int)); // space for 3 ints
    if (arr == NULL)
    {
        return 1;
    }
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
```

---

## Key Ideas
- malloc returns **heap memory**, not stack.
- You must manually `free()` it — otherwise: **memory leak**.
- Heap memory survives after function return.
- malloc returns a **void pointer** (`void *`), which you must **cast** or assign to appropriate type.

---

## Questions
- ❓ What happens if I forget to `free`?
- ❓ Can I `free` the same pointer twice?
- ❓ What's the difference between `malloc`, `calloc`, `realloc`?

---

## Related Concepts
- [[Pointers in C — Address-of (&) and Dereference (*)]]
- [[Memory Layout of a Program]]
- [[Stack vs Heap]]
- [[Segmentation Faults]]
- [[Garbage Collection vs Manual Memory Management]]

---

## See Also
- [CS50 Notes on Memory](https://cs50.harvard.edu/x/2025/notes/4/)
- [malloc — cppreference](https://en.cppreference.com/w/c/memory/malloc)
- [free — cppreference](https://en.cppreference.com/w/c/memory/free)
- [Memory Leaks — GeeksForGeeks](https://www.geeksforgeeks.org/memory-leak-in-c/)

---

## Terms
[[malloc]], [[free]], [[heap memory]], [[memory leak]], [[void pointer]], [[pointer]], [[dynamic allocation]], [[stack vs heap]]
