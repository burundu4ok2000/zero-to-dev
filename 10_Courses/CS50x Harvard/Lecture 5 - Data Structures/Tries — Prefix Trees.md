---
title: "Tries — Prefix Trees"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 08
status: "in-progress"
difficulty: "medium"
date: "2025-09-16"
timecode: "01:53:00"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---
![[Screenshot 2025-09-15 at 20.46.46.png]]
## Summary
A **trie** (pronounced “try”) is a **prefix tree** for fast **string** lookups by **prefix**. Each **node** stores **pointers** to children (one per possible character) plus a boolean **sentinel** flag marking the end of a word. Lookup, insert, and prefix checks take **O(m)** time where `m` is the word length, independent of how many words are stored.

## Very simple
Think subway map: every **station** is a letter. Follow stations to spell a word. If a station has a dot (**is_word**), that path is a complete word.

## Key Points
- **Node structure**: child **pointer** array (size = alphabet) + **is_word** flag.
- **Traversal**: one step per character ⇒ **O(m)** time.
- No **collisions**, unlike a **hash table**.
- Memory-heavy when alphabet is large (many **NULL** child slots).
- Great for **prefix** ops (**autocomplete**, **spell‑check**).
- Variants: **compressed trie** (aka **radix tree**), **ternary search tree**, **bitwise trie**.

## Details
- **Alphabet**: For lowercase English letters, use 26 children per node. For Unicode, switch to a **map/dictionary** child container to save memory.
- **Normalization**: Lowercase and skip non‑letters on insert/search to keep the automaton clean.
- **Deletion**: Unset **is_word** and optionally free nodes that become leaf+not‑word to reclaim memory.
- **Space trade‑offs**: Dense **array** child storage is fast but big; sparse **hash map**/map storage is smaller but a tad slower.
- **Safety**: Always check **malloc** results; **free** the whole trie with a post‑order traversal.

## Examples
```c
// Minimal C implementation (lowercase a–z)
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHA 26

typedef struct trie_node {
    bool is_word;
    struct trie_node *child[ALPHA];
} node;

node *new_node(void) {
    node *n = malloc(sizeof(node));
    if (!n) return NULL;
    n->is_word = false;
    for (int i = 0; i < ALPHA; i++) 
    n->child[i] = NULL;
    return n;
}

void insert(node *root, const char *word) {
    node *t = root;
    for (const unsigned char *p = (const unsigned char *)word; *p; p++) 
    {
        int c = tolower(*p);
        if (c < 'a' || c > 'z') continue;          // normalize
        int idx = c - 'a';
        if (!t->child[idx]) 
        t->child[idx] = new_node();
        t = t->child[idx];
    }
    t->is_word = true;
}

bool contains(node *root, const char *word) {
    node *t = root;
    for (const unsigned char *p = (const unsigned char *)word; *p; p++) {
        int c = tolower(*p);
        if (c < 'a' || c > 'z') continue;
        int idx = c - 'a';
        if (!t->child[idx]) return false;
        t = t->child[idx];
    }
    return t->is_word;
}

bool starts_with(node *root, const char *prefix) {
    node *t = root;
    for (const unsigned char *p = (const unsigned char *)prefix; *p; p++) {
        int c = tolower(*p);
        if (c < 'a' || c > 'z') continue;
        int idx = c - 'a';
        if (!t->child[idx]) return false;
        t = t->child[idx];
    }
    return true;
}
```

**ASCII path example** (words: `a`, `an`, `ant`, `art`)
```
(root)
  └─ a •
      ├─ n •
      │  └─ t •
      └─ r
         └─ t •
```
A dot (**•**) means **is_word = true**.

## **Why It Matters**
Tries give predictable **O(m)** time for **prefix** queries, making them perfect for **autocomplete**, **spell‑checkers**, **dictionary** apps, and **routing** (URLs, IPs, command dispatch). They also make **prefix counting** trivial (store counts per node).

## Questions
- How to generalize to **Unicode** efficiently (e.g., **UTF‑8**) without exploding memory?
- When does a **hash table** beat a trie in practice for whole‑word lookups?
- Do you need **compressed edges** (**radix tree**) to cut memory?

## Related Concepts
- [[Hash Tables — Collisions & Chaining]] – alternative **O(1)** average lookup; compare memory vs trie.
- [[Trees — Data Structures (Overview)]] – parent/child model applied to many structures.
- [[Binary Search Tree — Basics]] – ordered keys with **O(log n)** average operations.
- [[Asymptotic Analysis — O, Ω, Θ]] – reason about **O(m)** vs **O(1)/O(log n)**.
- [[Dynamic Memory Allocation — malloc & free]] – managing nodes on the **heap**.
- [[Pointers in C — Address-of & Dereference]] – moving through child **pointers** safely.
- [[Radix Tree (Compressed Trie)]] – merge single‑child chains to save space.
- [[Ternary Search Tree]] – character‑wise BST variant with lower memory footprint.

## See also
- [[CS50x Harvard — Week 5 Data Structures]]  
- [Trie — Wikipedia](https://en.wikipedia.org/wiki/Trie)
- [Trie — cp‑algorithms](https://cp-algorithms.com/string/trie.html)
- [Ternary Search Trees — Algorithms, 4e (Princeton)](https://algs4.cs.princeton.edu/52trie/)

## Terms
[[Trie]], [[Prefix]], [[Sentinel flag]], [[Node]], [[Pointer]], [[Child pointer array]], [[Root node]], [[Leaf node]], [[Autocomplete]], [[Dictionary ADT]], [[O(m)]], [[Alphabet size]], [[NULL pointer]]
