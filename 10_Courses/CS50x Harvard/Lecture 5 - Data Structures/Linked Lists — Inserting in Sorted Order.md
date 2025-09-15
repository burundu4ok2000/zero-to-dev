---
title: "Linked Lists — Inserting in Sorted Order"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 06
status: "in-progress"
difficulty: "medium"
date: "2025-09-15"
timecode: "01:15:00"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

## Summary
Insert a **node** into a **linked list** so the list stays **sorted**. We **traverse** the list, find the right spot, and **rewire** **pointers** around that position.

## Very simple
Like putting a new book onto a shelf that’s already sorted: you slide it **between** neighbors so the order stays correct.

## Key Points
- **Linked list** = **nodes** with **data** + **next pointer**.
- Three cases: **insert at head**, **append at tail**, **insert in middle**.
- Change only two **pointers** in the middle case: `n->next` and `prev->next`.
- Guard against **NULL** when peeking at `ptr->next`.
- Time: **O(n)** (walk to position). Space: **O(1)**.

## Details
### Setup
```c
typedef struct node {
    int number;
    struct node *next;
} node;

node *list = /* existing sorted list */;
node *n = malloc(sizeof(node));
if (n == NULL) return 1;
n->number = x;     // value to insert
n->next = NULL;
```

### Case 1 — insert at **head** (new smallest)
```c
if (list == NULL || n->number < list->number) {
    n->next = list;
    list = n;
}
```

### Case 2 — insert at **tail** (new largest)
```c
for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
    if (ptr->next == NULL) {
        ptr->next = n;
        break;
    }
}
```

### Case 3 — insert in the **middle**
```c
for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
    // ensure ptr->next exists before peeking into it
    if (ptr->next != NULL && n->number < ptr->next->number) {
        n->next = ptr->next;  // 1) hook new node to the successor
        ptr->next = n;        // 2) hook predecessor to new node
        break;
    }
    // optional: if tail reached, append
    if (ptr->next == NULL) {
        ptr->next = n;
        break;
    }
}
```

### Why it’s safe
We never lose the remainder of the list because we set `n->next` **before** reassigning `ptr->next`.  
Always check `ptr->next != NULL` before reading `ptr->next->number` to avoid dereferencing **NULL**.

### Visual
Start: `1 → 2 → 4`  
Insert `3` → `1 → 2 → 3 → 4`

## **Why It Matters**
- Keeps data **sorted at all times** without re-sorting later.
- Used in **priority queues**, **event schedules**, **ordered sets**.
- Trains precise **pointer** choreography; mistakes here cause **segfaults**.

## Example (complete function)
```c
void sorted_insert(node **plist, int x) {
    node *n = malloc(sizeof(node));
    if (n == NULL) return;      // production: handle error
    n->number = x;
    n->next = NULL;

    node *list = *plist;
    if (list == NULL || x < list->number) {
        n->next = list;
        *plist = n;
        return;
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
        if (ptr->next == NULL || x < ptr->next->number) {
            n->next = ptr->next;
            ptr->next = n;
            return;
        }
    }
}
```

## Related Concepts
- [[Linked Lists — Types and Usage]] – overview and traversal patterns.
- [[Linked Lists — Freeing Memory]] – clean up after operations.
- [[Structs in C — Defining and Self-Referencing]] – node type.
- [[Linked Lists — malloc, NULL checks, and Garbage Values]] – defensive allocation.
- [[Data Structures — What & Why]] – when lists beat arrays.
- [[Stacks — LIFO Principle]] – head-only inserts.
- [[Queues — FIFO Principle]] – tail-only inserts.
- [[Asymptotic Analysis]] – compare insertion costs with arrays.

## See also
- [Sorted insert for singly linked list (GfG)](https://www.geeksforgeeks.org/sorted-insert-for-singly-linked-list/)
- [Linked list insertion patterns (Programiz)](https://www.programiz.com/dsa/linked-list-insertion)
- [CS50 Week 5 notes](https://cs50.harvard.edu/x/2025/weeks/5/)
