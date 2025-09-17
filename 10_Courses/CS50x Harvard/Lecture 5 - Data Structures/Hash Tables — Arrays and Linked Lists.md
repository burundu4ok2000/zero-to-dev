---
title: "Hash Tables — Arrays and Linked Lists"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 14
status: "in-progress"
difficulty: "medium"
date: "2025-09-16"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

---
![[hach tables img.png]]

---

## Summary
A **hash table** is a data structure that uses a **hash function** to map **keys** (like strings) to **indices** in an array.  
It allows very fast average-time **insert**, **lookup**, and **delete** operations — typically **O(1)**.

---

## Very simple
Think of a huge row of **mailboxes**.  
- A **hash function** is like a machine that turns a name into a specific mailbox number.  
- You drop letters (values) into that mailbox.  
- Later, you ask the machine again for the same name, and it gives the same number — you open that mailbox and find your letter.

---

## Key Points
- **Hash function**: converts a key (e.g., a string) → array index.  
- **Collisions**: when two different keys land in the same index.  
- **Collision handling** strategies:  
  - **Chaining**: each bucket is a linked list of keys.  
  - **Open addressing**: search for another empty slot (not covered deeply in CS50).  
- Hash tables with **linked lists (chaining)** handle collisions gracefully.  
- Average case: **O(1)** lookup/insert/delete. Worst case (all keys collide): **O(n)**.  

---

## Details

### Basic Hash Function (toy example)
```c
unsigned int hash(const char *str) {
    unsigned int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }
    return sum % HASH_MAX; // index stays within table size
}
```

This sums ASCII values and uses modulo.  
👉 Simple but not great (many collisions). Real programs use stronger hash functions.

---

### Hash Table with Array of Linked Lists
```c
#define HASH_MAX 100

typedef struct node {
    char *key;
    int value;
    struct node *next;
} node;

node *table[HASH_MAX]; // array of linked list heads
```

---

### Insert (with chaining)
```c
void insert(const char *key, int value) {
    unsigned int idx = hash(key);
    node *n = malloc(sizeof(node));
    n->key = strdup(key);
    n->value = value;
    n->next = table[idx];   // push front
    table[idx] = n;
}
```

**ASCII**
```
index 42: [("cat",7)] -> [("cab",9)] -> NULL
```

---

### Lookup
```c
int find(const char *key) {
    unsigned int idx = hash(key);
    for (node *cur = table[idx]; cur; cur = cur->next) {
        if (strcmp(cur->key, key) == 0)
            return cur->value;
    }
    return -1; // not found
}
```

**ASCII**
```
index 42: [("cat",7)] -> [("cab",9)]
find("cab") → walks list → returns 9
```

---

### Delete
```c
void erase(const char *key) {
    unsigned int idx = hash(key);
    node *cur = table[idx], *prev = NULL;
    while (cur && strcmp(cur->key, key) != 0) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) return; // not found

    if (prev) prev->next = cur->next;
    else table[idx] = cur->next;

    free(cur->key);
    free(cur);
}
```

---

## **Why It Matters**
- Hash tables power **dictionaries**, **maps**, **sets**, **caches**.  
- Almost every modern language runtime (Python, Java, C++) uses them under the hood.  
- Real-world: storing usernames, fast autocomplete, routing (like DNS).  

---

## Questions
- How to pick a **good hash function** for strings?  
- What is the tradeoff between **array size** and collision frequency?  
- When does it make sense to resize or rehash?  

---

## Related Concepts
- [[Queues — Enqueue and Dequeue]] – another dynamic data structure.  
- [[Stacks — Push and Pop]] – LIFO structure vs hashing.  
- [[Singly-Linked Lists — Core Operations]] – used in chaining buckets.  
- [[Doubly-Linked Lists — Basics and Operations]] – alternative for collision chains.  
- [[Dynamic Memory Allocation — malloc & free]] – required for nodes.  
- [[Asymptotic Analysis — O, Ω, Θ]] – hash tables are O(1) average, O(n) worst-case.  
- [[Tries — Prefix Trees]] – another structure for fast string lookup.  

---

## See also
- [Hash table — Wikipedia](https://en.wikipedia.org/wiki/Hash_table)  
- [GeeksforGeeks: Hash Table](https://www.geeksforgeeks.org/hashing-data-structure/)  

---

## Terms
[[Hash table]], [[Hash function]], [[Collision]], [[Chaining]], [[Open addressing]], [[Bucket]], [[Key]], [[Value]]
