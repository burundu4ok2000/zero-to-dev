---
title: "Hashing and Hash Tables"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
atom_idx: 07
status: "in-progress"
difficulty: "medium"
date: "2025-09-15"
timecode: "01:39:00"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

## Summary
**Hashing** is a technique that maps input data (**keys**) to specific **indices** in a fixed-size table using a **hash function**.  
A **hash table** is essentially an **array of linked lists** (or buckets) that enables very fast insertion, lookup, and deletion.

Goal: achieve **O(1)** average time for search and insert.

---

## Key Ideas
- **Hash function**: maps a key (like a string) to an integer index.
- **Buckets**: slots in the table where data is stored.
- **Collisions**: when two keys map to the same index.
- **Chaining**: resolving collisions by storing items in a linked list at that bucket.
- **Load factor**: ratio of entries to buckets; impacts performance.

---

## Code Example — Simple Hash Function
```c
#include <ctype.h>

int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}
```
- This maps words by their first letter into a range `0–25`.
- Too simplistic → causes **collisions** (many words start with the same letter).

---

## Improved Hashing
- Use **more characters** of the word.
- Use **large table size** (prime numbers often chosen).
- Example: thousands of buckets instead of 26.

---

## Collision Handling
### 1. **Chaining**
- Each bucket stores a **linked list**.
- Colliding keys are appended to that list.

### 2. **Open Addressing** (not covered in CS50 but common)
- Instead of lists, find the next open slot in the table.

---

## Why It Matters
- Without hashing: searching is **O(n)** (linear search).
- With balanced trees: **O(log n)** search.
- With hashing: **O(1)** average search/insert/delete.

---

## Visual Analogy
- Think of buckets in a row.
- Hash function decides **which bucket** to drop an item in.
- Collisions = multiple items in the same bucket.

---

## Example — Dictionary Storage
```c
typedef struct node {
    char *word;
    struct node *next;
} node;

node *table[N];  // hash table with N buckets
```
- Store words in buckets according to hash function.
- Lookup = hash the word, search only that bucket’s list.

---

## **Why It’s Tricky**
- A bad hash function = too many collisions = slows down to O(n).
- Need balance: fast to compute, spreads keys evenly.

---

## Related Concepts
- [[Linked Lists — Types and Usage]] – chaining collisions.
- [[Data Structures — What & Why]] – tradeoffs arrays vs tables.
- [[Asymptotic Analysis]] – O(1) vs O(log n) vs O(n).
- [[Trees — Binary Search Trees]] – an alternative to hashing.

---

## See Also
- [CS50 Week 5 notes](https://cs50.harvard.edu/x/2025/weeks/5/)
- [Hash Table (Programiz)](https://www.programiz.com/dsa/hash-table)
- [Hash Functions (GeeksforGeeks)](https://www.geeksforgeeks.org/hashing-data-structure/)

## Terms
[[Hash function]], [[Bucket (hash table)]], [[Collision (hashing)]], [[Chaining]], [[Open addressing]], [[Load factor]], [[Rehashing]], [[Modulo operator]]
