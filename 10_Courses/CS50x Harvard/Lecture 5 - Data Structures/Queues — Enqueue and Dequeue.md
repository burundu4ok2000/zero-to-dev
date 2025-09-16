---
title: "Queues — Enqueue and Dequeue"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 13
status: "in-progress"
difficulty: "easy"
date: "2025-09-16"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---
![[A_flat-style_digital_illustration_serves_as_an_edu.png]]

---

## Summary
A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle.  
The two main operations are **enqueue** (insert at the back) and **dequeue** (remove from the front).  

## Very simple
Think of people lining up at a coffee shop:  
- New person **joins the line** at the back (enqueue).  
- The person at the **front** gets served and leaves (dequeue).  

---

## Key Points
- **FIFO** order: first element added is the first removed.
- Two implementations:
  1. **Array-based queue** (fixed capacity, uses indices).
  2. **Linked-list-based queue** (dynamic, uses nodes).
- Operations: **enqueue**, **dequeue**, optional **peek**.  

---

## 1) Array-based Queue

### Definition
```c
#define CAPACITY 10

typedef struct {
    int data[CAPACITY];
    int front;
    int rear;
    int size;
} queue;
```

- `front`: index of first element.  
- `rear`: index of last element.  
- `size`: number of elements in the queue.  

---

### Enqueue (insert at rear)
```c
void enqueue(queue *q, int x) {
    if (q->size == CAPACITY) {
        printf("Queue overflow!\n");
        return;
    }
    q->rear = (q->rear + 1) % CAPACITY;
    q->data[q->rear] = x;
    q->size++;
}
```

**ASCII**
```
Before: [28][33][19][  ][  ][  ] (rear=2)
Enqueue 40:

[28][33][19][40][  ][  ] (rear=3)
```

---

### Dequeue (remove from front)
```c
int dequeue(queue *q) {
    if (q->size == 0) {
        printf("Queue underflow!\n");
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return val;
}
```

**ASCII**
```
Before: front=0 -> [28][33][19][40]
Dequeue → removes 28

After: front=1 -> [33][19][40]
```

---

## 2) Linked-list-based Queue

### Node definition
```c
typedef struct qnode {
    int value;
    struct qnode *next;
    struct qnode *prev; // doubly linked list for flexibility
} qnode;

typedef struct {
    qnode *head;  // front
    qnode *tail;  // rear
} queue_ll;
```

---

### Enqueue (add at tail)
```c
void enqueue(queue_ll *q, int x) {
    qnode *n = malloc(sizeof(qnode));
    n->value = x;
    n->next = NULL;
    n->prev = q->tail;
    if (q->tail) q->tail->next = n;
    else q->head = n; // first element
    q->tail = n;
}
```

**ASCII**
```
Before: [12] <-> [15] <-> [9] <-> [13]
Enqueue 10 at tail:

[12] <-> [15] <-> [9] <-> [13] <-> [10]
```

---

### Dequeue (remove at head)
```c
int dequeue(queue_ll *q) {
    if (!q->head) {
        printf("Queue underflow!\n");
        return -1;
    }
    qnode *victim = q->head;
    int val = victim->value;
    q->head = victim->next;
    if (q->head) q->head->prev = NULL;
    else q->tail = NULL; // queue became empty
    free(victim);
    return val;
}
```

**ASCII**
```
Before: head -> [12] <-> [15] <-> [9]
Dequeue → removes 12

After: head -> [15] <-> [9]
```

---

## Why It Matters
- Queues model **real-world waiting lines**.  
- Used in **OS scheduling**, **network buffers**, **BFS algorithms**, and more.  
- Array-based queues are efficient for bounded size.  
- Linked-list queues grow dynamically but cost more memory.  

---

## Related Concepts
- [[Stacks — Push and Pop]] – opposite principle (**LIFO** vs **FIFO**).
- [[Singly-Linked Lists — Core Operations]] – queues can be implemented on top.
- [[Doubly-Linked Lists — Basics and Operations]] – flexible queue implementation.
- [[Dynamic Memory Allocation — malloc & free]] – required for linked nodes.
- [[Asymptotic Analysis — O, Ω, Θ]] – enqueue/dequeue are **O(1)**.

## See also
- [Queue (abstract data type) — Wikipedia](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))
- [GeeksforGeeks: Queue Data Structure](https://www.geeksforgeeks.org/queue-data-structure/)

## Terms
[[Queue]], [[Enqueue]], [[Dequeue]], [[FIFO]], [[Overflow]], [[Underflow]], [[Front pointer]], [[Rear pointer]]
