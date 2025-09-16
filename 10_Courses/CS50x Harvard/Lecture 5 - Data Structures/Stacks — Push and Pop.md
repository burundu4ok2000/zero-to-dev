---
title: "Stacks — Push and Pop"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 12
status: "in-progress"
difficulty: "easy"
date: "2025-09-16"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---
 
---
![[stacksimg.png]]

---

## Summary
A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle.  
The two core operations are **push** (add an item to the top) and **pop** (remove the top item).

## Very simple
Imagine a stack of plates in a cafeteria:  
- You **push** a new plate on top.  
- You **pop** the top plate off.  
You can only work with the top plate at any time.

## Key Points
- **LIFO**: last element in is the first one out.
- Two main operations: **push** and **pop**.
- Optional: **peek/top** — see the top element without removing it.
- Stack can be implemented using **arrays** or **linked lists**.

---

## Details

### Push (add element on top)
```c
void push(int stack[], int *top, int value, int capacity) 
{
    if (*top == capacity - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++(*top)] = value;
}
```

**ASCII**
```
Before: [10] [20] [30] <- top
Push 40:

[10] [20] [30] [40] <- new top
```

---

### Pop (remove element from top)
```c
int pop(int stack[], int *top) 
{
    if (*top < 0) {
        printf("Stack underflow!\n");
        return -1;  // error code
    }
    return stack[(*top)--];
}
```

**ASCII**
```
Before: [10] [20] [30] [40] <- top
Pop:

[10] [20] [30] <- new top
(40 is removed)
```

---

### Peek (look at top without removing)
```c
int peek(int stack[], int top) 
{
    if (top < 0) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}
```

**ASCII**
```
Stack: [10] [20] [30] <- top
Peek = 30
```

---

## **Why It Matters**
Stacks are everywhere:
- Function call management (the **call stack**).
- Undo/redo in editors.
- Expression evaluation (parsers, compilers).
- Backtracking algorithms.

## Questions
- How do stacks differ in **array vs linked list** implementation?
- What’s the real-world cost of **overflow/underflow** checks?

## Related Concepts
- [[Queues]] – opposite structure (**FIFO** instead of **LIFO**).
- [[Call Stacks — Week 3 Shorts]] – stack frames for function calls.
- [[Dynamic Memory Allocation — malloc & free]] – if implementing with linked nodes.
- [[Asymptotic Analysis — O, Ω, Θ]] – push/pop are **O(1)** operations.
- [[Singly-Linked Lists — Core Operations]] – stacks can be built on top of them.
- [[Recursion Basics — Drawing a Pyramid]] – recursion relies on the call stack.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]] – program’s stack segment.

## See also
- [Stack (abstract data type) — Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [GeeksforGeeks: Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)

## Terms
[[Stack]], [[Push]], [[Pop]], [[Peek]], [[LIFO]], [[Overflow]], [[Underflow]]
