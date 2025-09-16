---
title: "Doubly-Linked Lists — Basics and Operations"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 11
status: "in-progress"
difficulty: "medium"
date: "2025-09-16"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---
---

![[Screenshot 2025-09-16 at 17.33.21.png]]

---

## Summary
A **doubly-linked list** is a chain of **nodes** where each node has two pointers: one to the **next** node and one to the **previous** node.  
This makes traversal and deletion more flexible compared to **singly-linked lists**, at the cost of extra memory.

## Very simple
Think of a train: every wagon has a **coupling in front** and **in back**.  
You can move forward and backward along the train.

## Key Points
- Each node stores: **value**, pointer to **next**, pointer to **prev**.
- Head has `prev = NULL`, tail has `next = NULL`.
- Insertion/deletion is easier (no need to find `prev` separately).
- Uses more memory (two pointers instead of one).
- Traversal can go both directions.

---

## Node definition
```c
typedef struct dnode {
    int value;
    struct dnode *prev;
    struct dnode *next;
} dnode;
```

---

## 1) Insert at head
```c
dnode *push_front(dnode *head, int x) {
    dnode *n = malloc(sizeof(dnode));
    if (!n) return head;
    n->value = x;
    n->prev = NULL;
    n->next = head;
    if (head) head->prev = n;
    return n;   // new head
}
```

**ASCII**
```
Before: head -> [15] <-> [9] <-> [13]
Insert 12 at head:

head -> [12] <-> [15] <-> [9] <-> [13]
```

---

## 2) Insert at tail
```c
dnode *push_back(dnode *head, int x) 
{
    dnode *n = malloc(sizeof(dnode));
    if (!n) return head;
    
    n->value = x; 
    n->next = NULL;
    
    if (!head) 
    {     
	    n->prev = NULL; 
	    return n; 
    }
    
    dnode *cur = head;
    
    while (cur->next) cur = cur->next;
    
    cur->next = n;
    
    n->prev = cur;
    
    return head;
}
```

**ASCII**
```
Before: [15] <-> [9] <-> [13]
After:  [15] <-> [9] <-> [13] <-> [10]
```

---

## 3) Delete a node
With a pointer to the victim, just rewire `prev` and `next`.

```c
dnode *erase(dnode *head, dnode *victim) {
    if (!victim) return head;
    
    if (victim->prev)
        victim->prev->next = victim->next;
    else
        head = victim->next;   // victim was head
    
    
    if (victim->next)
        victim->next->prev = victim->prev;
        
    free(victim);
    return head;
}
```

**ASCII**
```
Before: [12] <-> [15] <-> [9]
Delete 15:
         ┌──────────┐
[12] <-> |  [15]    | <-> [9]
         └──────────┘

After:  [12] <-> [9]
```

---

## 4) Traversal (both ways)
```c
void print_forward(dnode *head) 
{
    for (dnode *cur = head; cur; cur = cur->next)
        printf("%d ", cur->value);
}

void print_backward(dnode *tail) 
{
    for (dnode *cur = tail; cur; cur = cur->prev)
        printf("%d ", cur->value);
}
```

---

## **Why It Matters**
- Easier deletions: no need to search for previous node.  
- Traversal in both directions (useful for some algorithms).  
- Tradeoff: extra memory and complexity.  

## Questions
- How do you maintain **tail** pointer for O(1) insert at end?
- What’s the difference in performance vs singly-linked lists?

## Related Concepts
- [[Singly-Linked Lists — Core Operations]] – one-pointer version.
- [[Dynamic Memory Allocation — malloc & free]] – managing node memory.
- [[Pointers in C — Address-of & Dereference]] – moving through nodes.
- [[Stacks]] – can use doubly or singly lists.
- [[Queues]] – can use doubly lists for efficient both ends.
- [[Deques]] – naturally implemented with doubly-linked lists.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]] – heap allocation used for nodes.

## See also
- [Doubly linked list — Wikipedia](https://en.wikipedia.org/wiki/Doubly_linked_list)
- [GeeksforGeeks: Doubly Linked List](https://www.geeksforgeeks.org/doubly-linked-list/)

## Terms
[[Doubly linked list]], [[Node]], [[Head pointer]], [[Tail]], [[Prev pointer]], [[Next pointer]], [[Insert]], [[Delete]]
