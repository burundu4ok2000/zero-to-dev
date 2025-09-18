---
title: "Choosing a Data Structure — Practical Guide"
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 00
status: "in-progress"
difficulty: "easy"
date: "2025-09-17"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

---

![[deadeff4-2f73-4776-8baf-e2dcaea62df0.png]]

---

## One‑liner
Pick the structure that matches your dominant operations: **lookup**, **insert/delete**, **ordering**, **prefix**, **random access**, **memory**.

## Very simple
Choosing a data structure is like choosing a **container** for toys:  
- If you need to **grab any toy by name fast**, use a labeled **shelf** (**hash table**).  
- If you need toys in **sorted order**, keep a **tree** (**BST**).  
- If kids take toys only from the **top** or the **front**, use a **stack** or a **queue**.  
- If you just number the slots and jump to slot **i**, that’s an **array**.  
- If you often **insert in the middle**, use a **linked list** (you just relink chains).  
- If you search by **prefix** (starts with...), store letters as a **trie**.

---

## Decision guide (quick rules)

1) **Exact key → value lookup?**  
   - No need for order: **hash table** (average **O(1)**).  
   - Need **sorted order / range queries**: **balanced BST (Binary Search Tree) (average **O(log n)**).  
   - Need **prefix search**: **trie** (time ≈ length of the key).

2) **Access by index i (random access)?**  
   - **array / dynamic array** (vector): **O(1)** access.  
   - If frequent middle inserts/deletes → prefer **linked list** (no shifting).

3) **Push/Pop at one end only?**  
   - **stack** (LIFO) for “last comes out first”.  
   - **queue** (FIFO) for “first comes out first”.

4) **Always take the smallest/largest next?**  
   - **binary heap / priority queue** (insert/extract‑min in **O(log n)**).

5) **Small data (n < ~100)?**  
   - Choose the **simplest** structure that’s easy to debug. Constant factors dominate.

6) **Memory concerns?**  
   - **array** is compact and **cache‑friendly**.  
   - **linked list / trie** add pointer overhead (and more cache misses).  
   - **hash table** needs extra space for **buckets** and may need **resize**.

7) **Growth unknown / many resizes?**  
   - **linked structures** (lists, trees, tries) or **dynamic arrays** that can grow by reallocation.

8) **Concurrency / iteration safety?**  
   - Prefer immutable snapshots or structures with simple iteration (**array**, **vector**).

---

## TL;DR decision table

| **Goal** | **Best pick** | **Why** | **Typical ops** |
|---|---|---|---|
| Fast key → value lookup | **hash table** | average **O(1)**, simple API | insert/find/delete |
| Keep data sorted | **balanced BST** | in‑order traversal yields sorted keys | insert/find/delete **O(log n)** |
| Prefix queries (“starts with…”) | **trie** | cost depends on **key length**, not on **n** | insert/startsWith/find |
| Push/pop one end | **stack** / **queue** | **O(1)** per op, very simple | push/pop, enqueue/dequeue |
| Index by i | **array / dynamic array** | **O(1)** access, best cache locality | a[i], append, slice |
| Many middle inserts | **linked list** | change **pointers**, not shift memory | insert/delete **O(1)** once you have node |
| Always smallest/largest next | **binary heap** | **O(log n)** insert/extract, **O(1)** peek | push, extract‑min/max |

**Heads‑up:** **hash tables with chaining** still **have collisions** — they just **handle** them by keeping a **linked list** in each bucket. Collisions don’t disappear; they stop breaking correctness.

---

## Time complexities (typical)

| **Structure** | **Access** | **Search** | **Insert** | **Delete** | **Notes** |
|---|---:|---:|---:|---:|---|
| **array** | **O(1)** | **O(n)** | end: **O(1)** | end: **O(1)** | middle inserts require shifting (**O(n)**) |
| **singly linked list** | — | **O(n)** | **O(1)** with pointer | **O(1)** with pointer | poor cache locality |
| **stack** | **O(1)** top | **O(n)** | **O(1)** push | **O(1)** pop | LIFO |
| **queue** | **O(1)** ends | **O(n)** | **O(1)** enqueue | **O(1)** dequeue | FIFO |
| **hash table** | — | avg **O(1)** | avg **O(1)** | avg **O(1)** | resize to keep load factor low |
| **BST (balanced)** | — | **O(log n)** | **O(log n)** | **O(log n)** | inorder = sorted |
| **trie** | by char | **O(m)** | **O(m)** | **O(m)** | `m` = key length; memory‑heavy |
| **binary heap** | — | — | **O(log n)** | **O(log n)** | priority queue |

---

## Tiny ASCII decision flow
```
Need order? ── yes ──► BST (balanced) ──► range queries? yes → great
      │
      no
      │
Exact key lookup? ── yes ──► Hash table
      │
      no
      │
Prefix search? ── yes ──► Trie
      │
      no
      │
Index by i? ── yes ──► Array / Vector
      │
      no
      │
Frequent middle insert/delete? ──► Linked list
```

---

## Practical tips
- Keep **interfaces** small (e.g., `map_put`, `map_get`); you can switch implementations later.  
- Measure **load factor** in a **hash table**; resize when it grows too high.  
- Prefer **balanced BSTs** (like AVL/Red‑Black) if worst‑case matters.  
- For **small n**, clarity wins; avoid over‑engineering.  
- Watch **memory locality**: arrays often beat fancy structures in practice.

---

## Related Concepts
- [[Stacks — Push and Pop]] – LIFO container for one‑end ops.
- [[Queues — Enqueue and Dequeue]] – FIFO container for pipelines.
- [[Hash Tables — Arrays and Linked Lists]] – average **O(1)** map/set.
- [[Binary-Search-Trees-Basics-and-Operations]] – ordered map/set.
- [[Tries — Prefix Trees]] – fast prefix lookups.
- [[Singly-Linked Lists — Core Operations]] – pointer rewiring patterns.
- [[Doubly-Linked Lists — Basics and Operations]] – two‑end traversal.
- [[Arrow Operator and Struct Pointers in C]] – syntax glue for node fields.

## See Also
- [Choosing the Right Data Structure (overview)](https://en.wikipedia.org/wiki/Data_structure#Overview)
- [Big‑O Cheat Sheet](https://www.bigocheatsheet.com/)
- [When Hash Tables Beat Trees (and vice versa)](https://stackoverflow.com/questions/31022269/when-to-use-a-hash-table-vs-a-binary-search-tree)

## Terms
[[Array]], [[Linked list]], [[Stack]], [[Queue]], [[Hash table]], [[Trie]], [[BST]], [[Binary heap]], [[Prefix]], [[Load factor]], [[Collision]], [[Chaining]], [[Balanced tree]], [[Random access]]
