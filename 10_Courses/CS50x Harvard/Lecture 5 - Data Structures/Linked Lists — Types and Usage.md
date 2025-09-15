---
title: "Linked Lists — Types and Usage"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 04
status: "in-progress"
difficulty: "medium"
date: "2025-09-15"
timecode: "00:50:00"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

---

![[Screenshot 2025-09-15 at 18.01.50.png]]

---

## Summary
A **linked list** is a data structure where each element (node) stores both a value and a reference (pointer) to the next element.  
Unlike arrays, linked lists can grow and shrink dynamically.  
They can be **singly linked**, **doubly linked**, or **circularly linked** depending on how nodes point to each other.

## Very simple
Imagine a **chain of paperclips**. Each clip holds the next one.  
- If clips only point one way → singly linked list.  
- If clips point both forward and backward → doubly linked list.  
- If the last clip connects back to the first → circular linked list.

## Key Points
- Each node = **data field + pointer(s)**.  
- **Dynamic size**: no need to know in advance how many elements.  
- **Efficient insertion/deletion**: no shifting like in arrays.  
- **Access time**: slower than arrays (must walk through nodes).  
- Types:
  - **Singly linked list** → each node points to the next.  
  - **Head insertion** vs **tail insertion**: defines how new nodes are linked (start vs end).  
  - **Doubly linked list** → nodes point to both previous and next.  
  - **Circular linked list** → last node points back to the head.

## Details
### Singly Linked List
```c
typedef struct node {
    int number;
    struct node *next;
} node;
```
- Linking **newest node at the head** → list grows backwards (latest points to previous).  
- Linking **at the tail** → list grows in insertion order.

### Doubly Linked List
```c
typedef struct dnode {
    int number;
    struct dnode *prev;
    struct dnode *next;
} dnode;
```
- Allows traversal in both directions.  
- Useful for undo/redo, navigation (back/forward).

### Circular Linked List
```c
typedef struct node {
    int number;
    struct node *next;
} node;

// tail->next points back to head
```
- Traversal can loop forever.  
- Often used in scheduling (round-robin).

## Examples
### Traversal of singly linked list
```c
node *ptr = list;
while (ptr != NULL)
{
    printf("%i\n", ptr->number);
    ptr = ptr->next;
}
```

### Diagram
(list → 3 → 2 → 1, `ptr` walking through each node).

## **Why It Matters**
- **Flexibility**: grow/shrink dynamically without reallocating.  
- **Insertion/Deletion**: fast (O(1)) once the pointer is known.  
- **Trade-off**: slower access (O(n)), more memory (extra pointers).  
- **Use cases**: implementing stacks, queues, adjacency lists in graphs, dynamic memory managers.

## Questions
- ❓ When is a doubly linked list better than a singly linked one?  
- ❓ What are real-world cases for circular linked lists?  

## Related Concepts
- [[Structs in C — Defining and Self-Referencing]] – linked lists require self-referencing structs.  
- [[Linked Lists — malloc, NULL checks, and Garbage Values]] – safe allocation and initialization.  
- [[Stacks — LIFO Principle]] – can be implemented with linked lists.  
- [[Queues — FIFO Principle]] – can be implemented with linked lists.  
- [[Hash Tables — Key-Value Storage]] – often use linked lists for collision handling.  
- [[Dynamic Memory Allocation — malloc & free]] – building blocks for linked lists.  
- [[Pointers in C — Address-of & Dereference]] – essential for navigation.  
- [[Data Structures — What & Why]] – linked lists as fundamental structures.

## See also
- [[CS50x Harvard]]  
- [GeeksforGeeks — Types of Linked Lists](https://www.geeksforgeeks.org/types-of-linked-list/)  
- [TutorialsPoint — Linked Lists in C](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)  

## Terms
[[Linked list]], [[Singly linked list]], [[Doubly linked list]], [[Circular linked list]], [[Node]], [[Pointer]], [[Traversal]], [[Dynamic memory]]
