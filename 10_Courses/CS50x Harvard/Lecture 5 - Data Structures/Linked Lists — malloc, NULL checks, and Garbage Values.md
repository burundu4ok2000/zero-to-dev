---
title: "Linked Lists — malloc, NULL checks, and Garbage Values"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 03
status: "in-progress"
difficulty: "medium"
date: "2025-09-15"
timecode: "00:43:31"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

---

// Место для фото материалов

![[Screenshot 2025-09-15 at 17.13.12.png]]
![[Screenshot 2025-09-15 at 17.18.44.png]]

---

## Summary
When using `malloc` to allocate memory for a new node in a **linked list**, always check if the result is `NULL`.  
Also, initialize pointers to `NULL` immediately to avoid **garbage values**.  
Use `n->field` as a shorthand for `(*n).field` to access struct members via a pointer.

## Very simple
It’s like asking for a new empty box. If the store says “no boxes” (NULL), stop right away.  
And when you do get a box, label the “next” pointer as empty (`NULL`), so you don’t accidentally follow random garbage.  
The arrow `->` is just a shortcut: instead of opening the box (`*`) and then looking inside (`.`), you just use one symbol.

## Key Points
- **Check malloc result**: memory allocation can fail, and if `malloc` returns `NULL`, we must handle it safely.  
- **Parentheses around pointer dereference**: writing `(*n).value` is equivalent to `n->value`. Parentheses are needed for correctness but programmers usually prefer `->`.  
- **Arrow operator `->`** = shorthand for `(*ptr).field`.  
- **Initialize to NULL**: setting `n->next = NULL;` prevents uninitialized (garbage) pointers, which could otherwise cause crashes.  
- **Garbage value** = leftover random data in memory when not explicitly initialized.

## Details
### malloc check
```c
node *n = malloc(sizeof(node));
if (n == NULL)
{
    return 1; // error handling if memory allocation failed
}
```

### Parentheses vs arrow
```c
(*n).number = 42;   // explicit dereference with parentheses
n->number = 42;     // equivalent shorthand, more common in practice
```
- The dot `.` has higher precedence than `*`, so `*n.number` would be invalid.  
- That’s why we either write `(*n).field` or use the cleaner shorthand `n->field`.

### Initializing pointers to NULL
```c
n->next = NULL; // ensures we don’t “walk” into random memory
```

## Examples
```c
typedef struct node {
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        n->number = get_int("Number: "); // using arrow
        n->next = NULL; // avoid garbage
    }
}
```

## **Why It Matters**
Failing to check `malloc` or initialize pointers leads to **segmentation faults**, crashes, or security bugs.  
#### Good practice: **defensive programming** — always assume memory may fail or contain junk.  

Using `->` makes code shorter and easier to read when working with structs via pointers.

## Questions
- ❓ Is it always best practice to check `malloc`, even in small programs?  
- ❓ Are there cases where leaving memory uninitialized is intentional?  
- ❓ Are there stylistic cases where `(*n).field` is preferred over `n->field`?

## Related Concepts
- [[Structs in C — Defining and Self-Referencing]] – node definition used here.  
- [[Pointers in C — Address-of & Dereference]] – explains `(*n).field` and `n->field`.  
- [[Dynamic Memory Allocation — malloc & free]] – core of creating nodes.  
- [[Linked Lists — Intro]] – context where malloc is repeatedly used.  
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]] – malloc allocates on the heap.  
- [[Data Structures — What & Why]] – linked lists as a fundamental data structure.  
- [[Asymptotic Analysis]] – efficiency of linked lists vs arrays.  
- [[Recursion Basics — Drawing a Pyramid]] – trees also require initialized pointers.

## See also
- [C malloc tutorial](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)  
- [Why initialize pointers to NULL](https://stackoverflow.com/questions/4138422/why-set-pointers-to-null-in-c)  
- [C arrow operator](https://www.geeksforgeeks.org/arrow-operator-in-c-c-with-examples/)  

## Terms
[[malloc]], [[NULL]], [[Garbage value]], [[Pointer]], [[Dereference]], [[Linked list]], [[Dynamic memory]], [[Heap]], [[Arrow operator]]
