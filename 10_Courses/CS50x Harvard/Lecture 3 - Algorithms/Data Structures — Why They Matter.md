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
Why **data structures** are important: they help one variable hold **lots of things** easily. They also affect how fast and how much space your program uses. Picking the right data structure is often more helpful than making small code changes.

## Big idea
A **data structure** is a way to organize **memory** and **how to do things** like **add**, **find**, **remove**, or **go through** the data. Using different data structures can make these tasks faster or slower. For example, some can do these tasks in **O(n)** time, while others can do them in **O(log n)** or **O(1)** time.

## Examples you just met
- **Array**: a group of items next to each other. It is quick to find an item by its position (index). But adding or removing items in the middle takes more time. Arrays are good for going through all items one by one and work well with computers' memory.
- **Struct**: a way to put different types of information together in one **record**. For example, a `person` can have a `name` and a `number`. Using structs makes the data easier to read and find nearby information.
- **Array of structs**: a list of many records, like a table. It helps find data by a specific **field**. Later, it can be changed to faster types like **sorted arrays** or **hash tables** without changing how the program works.

## Choosing structures (quick heuristics)
-If you need to quickly find items in any order and the size is small and fixed, use an **array**.  
If you want to group different pieces of information together, make a **struct**. This makes it easier to access data with dots and reduces mistakes.  
If you will search for items often using a key, start with a **sorted array** and use **binary search**. Later, you can switch to a **hash table** or **tree** for faster searching.  
Always ask: what are the most important tasks, and how hard are they to do?

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
