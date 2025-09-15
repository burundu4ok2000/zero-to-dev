---
title: "Structs in C — Defining and Self-Referencing"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 02
status: "in-progress"
difficulty: "medium"
date: "2025-09-13"
timecode: "00:05:00"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

---


![[Screenshot 2025-09-13 at 22.15.59.png]]

---

## Summary
A **struct** in C is a custom data type that groups multiple variables together.  
A struct can also **reference itself**, which allows us to build data structures like **linked lists**.

## Very simple
Think of a struct as a **box with compartments**. Each compartment can hold a different kind of thing (number, text, etc.).  
A self-referencing struct is like a box that can point to another box of the same kind — forming a chain.

## Key Points
- A **struct** groups related variables under one name.  
- Use `typedef` to create an alias for easier usage.  
- **Self-referencing** is when a struct contains a pointer to itself (like `struct node *next;`).  
- This is required for structures like **linked lists**, **trees**, and **graphs**.  
- The keyword `struct` must still be written inside the definition, even if we later use the alias.

## Details
When defining a self-referencing struct, C requires the word `struct` before the type name, because the alias (`node`) is not yet fully defined inside the body.  
That’s why we write:

```c
typedef struct node {
    int number;
    struct node *next; // must use 'struct node' here, not just 'node'
} node;
```

Without `struct node`, the compiler doesn’t yet recognize `node` inside its own definition.  
After the struct is fully defined, we can use `node` directly.

## Examples
### Example 1: Simple struct without self-reference
```c
typedef struct {
    char name[50];
    int age;
} person;

person p1 = {"Alice", 25};
```

### Example 2: Self-referencing struct (linked list node)
```c
typedef struct node {
    int number;
    struct node *next;
} node;

node *head = NULL;
```

### Example 3: Same idea with different name
```c
typedef struct element {
    float value;
    struct element *next;
} element;
```

## **Why It Matters**
Structs allow programmers to model **complex data** beyond primitive types.  
Self-referencing structs make **dynamic data structures** like linked lists possible.

## Questions
- ❓ Why can’t we just write `node *next;` instead of `struct node *next;`?
- ❓ How does the compiler know when the struct definition is complete?

## Related Concepts
- [[Data Structures — What & Why]] – structs are the building blocks.  
- [[Linked Lists — Intro]] – use self-referencing structs.  
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]] – explains where struct instances live.  
- [[Pointers in C — Address-of & Dereference]] – needed to handle `*next`.  
- [[Dynamic Memory Allocation — malloc & free]] – create structs on the heap.  
- [[Arrays — Basics]] – contrast with structs for grouping data.  
- [[Hash Tables — Key-Value Storage]] – often built with linked lists.  
- [[Recursion Basics — Drawing a Pyramid]] – trees rely on recursive structs.

## See also
- [[CS50x Harvard]]  
- [C Tutorial: Structures](https://www.programiz.com/c-programming/c-structures)  
- [Self-referential structures in C](https://www.geeksforgeeks.org/self-referential-structures/)  

## Terms
[[Struct]], [[typedef]], [[Linked list]], [[Pointer]], [[Dynamic memory]], [[Node]], [[Tree]], [[Graph]]
