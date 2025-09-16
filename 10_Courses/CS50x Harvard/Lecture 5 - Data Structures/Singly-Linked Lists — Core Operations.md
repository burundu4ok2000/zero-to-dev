---
title: "Singly-Linked Lists — Core Operations"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 10
status: "in-progress"
difficulty: "medium"
date: "2025-09-16"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---
--- 

![[Screenshot 2025-09-16 at 15.12.50.png]]

---

## Summary
A **singly linked list** is a chain of **nodes** where each node stores **data** and a **next pointer** to the following node. You work with the list by updating **pointers** carefully so you never **break the chain**.

## Very simple
Imagine a line of people holding hands. Each person points to who comes next. If you remove someone, you must make the previous person hold the next one’s hand, or the line splits.

## Key Points
- Head **pointer** names the first **node**; empty list ⇒ **NULL**.
- Each operation is about rewiring the **next** pointers safely.
- Typical costs: **search O(n)**, **insert at head O(1)**, **delete with prev pointer O(1)**.
- Always check for **NULL** and avoid **memory leaks** with `free`.

---

## 1) Create a linked list when it doesn’t already exist
**Goal:** allocate the first **node** and set **head**.

```c
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

node *push_front(node *head, int x) {
    node *n = malloc(sizeof(node));
    if (!n) return head;          // allocation failed
    n->value = x;
    n->next  = head;              // new node points to old head
    return n;                     // new head
}
```

**ASCII**
```
Before:  head -> NULL

Make n:  [x|•] -> head

After:   head
           |
           v
          [x|•] -> NULL
```
`[x|•]` means the **data** and a **next pointer**.

---

## 2) Search through a linked list to find an element
**Goal:** walk the chain until value found (or end).

```c
#include <stdbool.h>

bool contains(node *head, int target) {
    for (node *cur = head; cur != NULL; cur = cur->next) {
        if (cur->value == target) return true;
    }
    return false;
}
```
**ASCII**
```
head -> [3|•] -> [7|•] -> [9|•] -> NULL
               ^ search hits here if target = 7
```
**Complexity:** **O(n)** time, **O(1)** space.

---

## 3) Insert a new node into the linked list
### a) Insert at head (**O(1)**)
```c
head = push_front(head, x);
```
**ASCII**
```
Before: head -> [A] -> [B] -> NULL
Insert X at head:
head -> [X] -> [A] -> [B] -> NULL
```

### b) Insert after a given node (**O(1)** if you already have pointer to `prev`)
```c
void insert_after(node *prev, int x) {
    if (!prev) return;
    node *n = malloc(sizeof(node));
    if (!n) return;
    n->value = x;
    n->next  = prev->next;   // 1) new points to next
    prev->next = n;          // 2) prev points to new
}
```
**ASCII (order matters!)**
```
prev -> [A] -> [B]
               ^ old next

Step1:  [A] -> [n=X] -> [B]
Step2:  prev->next = n  (the chain never breaks)
```

### c) Insert at tail (**O(n)** without tail pointer)
```c
node *push_back(node *head, int x) {
    node *n = malloc(sizeof(node));
    if (!n) return head;
    n->value = x; n->next = NULL;
    if (!head) return n;
    node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}
```

---

## 4) Delete a single element from a linked list
Two common cases: **delete by value** (need to find **prev**) or **delete after prev** when you already have it.

```c
node *erase_first(node *head, int target) {
    if (!head) return NULL;

    // case: remove head
    if (head->value == target) {
        node *tmp = head->next;
        free(head);
        return tmp;                 // new head
    }

    // general case: find prev of node to remove
    node *prev = head;
    while (prev->next && prev->next->value != target)
        prev = prev->next;

    if (prev->next) {               // found target
        node *victim = prev->next;
        prev->next = victim->next;  // bypass
        free(victim);
    }
    return head;
}
```

**ASCII (bypass the victim)**
```
Before: head -> [A] -> [V] -> [B] -> NULL
                      ^ victim

Rewire:        [A] ---------> [B]
               (free [V])

After:  head -> [A] -> [B] -> NULL
```
**Rule of thumb:** rewire pointers **before** calling `free`.

---

## 5) Delete an entire linked list
Walk and free every node to avoid leaks.

```c
void clear(node *head) {
    while (head) {
        node *next = head->next;  // save next
        free(head);               // free current
        head = next;              // advance
    }
}
```
**ASCII**
```
head -> [A] -> [B] -> [C] -> NULL
free A; head -> [B] -> [C] -> NULL
free B; head -> [C] -> NULL
free C; head -> NULL
```

---

## **Why It Matters**
**Linked lists** trade **O(1)** inserts/deletes (given a **prev pointer**) for **O(n)** search. They shine when you do many local updates and don’t need random access like arrays do. Mastering the pointer rewiring pattern prevents **segfaults** and **memory leaks**.

## Questions
- How would you implement a **sorted insert** preserving order?
- What changes for a **doubly linked list** (extra `prev` pointer)?
- How to write an **iterator**-style traversal API?

## Related Concepts
- [[Pointers in C — Address-of & Dereference]] – you rewire **next** via **pointers**.
- [[Dynamic Memory Allocation — malloc & free]] – ownership and **free** rules.
- [[Asymptotic Analysis — O, Ω, Θ]] – time for search vs insert/delete.
- [[Singly Linked List — Edge Cases]] – empty list, one element, head deletion.
- [[Doubly-Linked Lists — Basics]] – adds **prev**, simplifies deletions.
- [[Stacks]] – can be implemented on top of a singly linked list.
- [[Queues]] – linked-list **enqueue/dequeue** patterns.
- [[Hash Tables — Separate Chaining]] – buckets are often **linked lists**.

## See also
- [Linked list — Wikipedia](https://en.wikipedia.org/wiki/Linked_list)
- [Singly Linked List (GeeksforGeeks)](https://www.geeksforgeeks.org/data-structures/linked-list/)

## Terms
[[Linked list]], [[Node]], [[Head pointer]], [[Tail]], [[Next pointer]], [[NULL]], [[Insert]], [[Delete]], [[Search]], [[Bypass]], [[Memory leak]]
