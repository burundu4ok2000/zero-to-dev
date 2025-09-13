---
title: "Data Structures — What & Why"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 01
status: "in-progress"
difficulty: "easy"
date: "2025-09-13"
timecode: "00:00:00"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

---


![[data_structures_intro.png]]

---

## Summary
**Data structures** are ways to organize and store data in a computer so it can be used efficiently.

## Very simple
Imagine your toys: if they’re in one big pile, it’s hard to find the one you want. But if you put them in boxes (cars in one, dolls in another), it’s faster to find. That’s what data structures do for computers.

## Key Points
- **Data structure** = method to organize data in memory.
- They help with **efficiency** — faster search, insert, delete.
- Different tasks need different structures (like arrays, linked lists, stacks, queues, trees, hash tables, tries).
- Picking the right structure can change performance a lot.

## Details
Computers deal with huge amounts of information. Without structure, operations become slow or impossible.  
Common data structures balance trade-offs:

- **Arrays** → fast access, fixed size.  
```c
// Example of array
int numbers[5] = {1, 2, 3, 4, 5};
printf("%d", numbers[2]); // prints 3
```

- **Linked lists** → flexible size, slower access.  
```c
// Linked list node definition
typedef struct node {
    int number;
    struct node *next;
} node;
```

- **Stacks (LIFO)** → Last In, First Out.  
```c
// Stack using array
int stack[10];
int top = -1;

// push
stack[++top] = 5;

// pop
int x = stack[top--];
```

- **Queues (FIFO)** → First In, First Out.  
```c
// Queue using array
int queue[10];
int front = 0, rear = 0;

// enqueue
queue[rear++] = 7;

// dequeue
int y = queue[front++];
```

- **Hash tables** → near-instant lookup using keys.  
```c
// Very simple hash function example
int hash(int key) {
    return key % 10;
}
```

- **Trees** → hierarchical structure.  
```c
// Binary tree node
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;
```

- **Tries** → specialized tree for words/prefixes.  
```c
// Trie node (each letter is a child)
typedef struct node {
    bool is_word;
    struct node *children[26];
} node;
```

## **Why It Matters**
Efficient programs depend not only on algorithms, but also on the **right data structures**.  
Choosing the wrong structure can make even a good algorithm run poorly.

## Questions
- ❓ How do I know which data structure to pick for a given problem?
- ❓ What are the trade-offs between arrays and linked lists?

## Related Concepts
- [[Arrays — Basics]] – foundation for many data structures.
- [[Linked Lists — Intro]] – alternative to arrays with dynamic memory.
- [[Stacks — LIFO Principle]] – special ordering rule.
- [[Queues — FIFO Principle]] – another ordering structure.
- [[Hash Tables — Key-Value Storage]] – powerful lookup tool.
- [[Tries — Prefix Trees]] – used for words and autocomplete.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]] – context where data lives.
- [[Asymptotic Analysis]] – helps measure efficiency of data structures.

## See also
- [[CS50x Harvard]]  
- [GeeksforGeeks — Data Structures](https://www.geeksforgeeks.org/data-structures/)  
- [Wikipedia — Data Structure](https://en.wikipedia.org/wiki/Data_structure)  

## Terms
[[Arrays]], [[Linked list]], [[Stack]], [[Queue]], [[Hash table]], [[Tree]], [[Trie]], [[Data structure]]
