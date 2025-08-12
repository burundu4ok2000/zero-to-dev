---
title: "Data Structures — Why They Matter"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 07
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:50:05"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_17-58-20.png]]
[[2025-08-07_17-58-20.png]]

---

## Summary
Why **data structures** matter: they let one variable manage **bunches of things** efficiently, shaping your algorithm’s **time** and **space** costs. Choosing the right container is often a bigger win than micro-optimizing code.

## Big idea
A **data structure** packages **layout of memory** and **operations** (insert, search, delete, iterate). With the same algorithmic goal, swapping the structure can change complexity from **O(n)** to **O(log n)** or **O(1)**.

## Examples you just met
- **Array**: contiguous block; fast **indexing** O(1), slow **insertion in middle** O(n). Great for **sequential scans** and cache friendliness.
- **Struct**: groups heterogeneous fields into one **record** (e.g., `person { name; number; }`), improving locality and readability over parallel arrays.
- **Array of structs**: model a **table** of records; enables searching by **field** and later upgrades to **sorted** arrays or **hash tables** without rewriting callers.

## Choosing structures (quick heuristics)
- Need **random access** and small, fixed size → use an **array**.
- Need to bundle attributes → define a **struct** (clean **dot access** and fewer bugs).
- Expect lots of lookups by key → start with a **sorted array** (binary search) or plan to switch to a **hash table / tree** later.
- Always ask: what are the **hot operations** and their **complexities**?

## Pitfalls
- Forcing everything into arrays → painful **O(n)** inserts/deletes.
- Parallel arrays for related fields → **brittle** and error-prone vs a single **struct**.
- Ignoring invariants (**sortedness**) and then claiming **O(log n)**.

## Related Concepts
- [[Abstract Data Type (ADT)]] – behavior-first view that a **data structure** implements
- [[Arrays vs Linked Lists]] – trade-offs in **contiguity**, **inserts**, and **cache**
- [[Hash table]] – average **O(1)** lookups by key
- [[Balanced binary search tree]] – all ops **O(log n)** with ordering
- [[Space complexity]] – memory cost side of the trade-off

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

## Terms
[[Data structure]], [[Array]], [[Struct]], [[Record]], [[Field]], [[Indexing]], [[Insertion]], [[Sorted array]], [[Hashing]], [[Binary search]]
