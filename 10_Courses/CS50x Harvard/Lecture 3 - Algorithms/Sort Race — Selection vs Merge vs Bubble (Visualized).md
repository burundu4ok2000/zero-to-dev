---
title: "Sort Race — Selection vs Merge vs Bubble (Visualized)"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 15
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "02:05:15"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_19-59-33.png]]

---

## Summary
A side‑by‑side **visual race** of **selection sort**, **merge sort**, and **bubble sort** makes the complexity gaps visceral: **O(n log n)** algorithms pull away as **n** grows, while **O(n²)** sorts stall under quadratic work.

## What to watch for
- **Startup vs scaling**: for tiny arrays, constant factors hide differences; as **n** increases, **log‑linear** growth wins decisively.
- **Work profile**: **selection** does a fixed set of **comparisons** each pass; **bubble** repeatedly **swaps** neighbors (often more data movement); **merge** spends effort in linear **merge** phases after recursive splits.
- **Stability**: **merge sort** is **stable** by default; **selection/bubble** are typically **unstable**/**stable** respectively (implementation‑dependent for selection).

## Complexity snapshot
- **Selection**: **Θ(n²)** comparisons, ≤ **n−1** swaps, **O(1)** extra space (in‑place).  
- **Bubble**: **Θ(n²)** comparisons and swaps in the worst case; can early‑exit when already sorted.  
- **Merge**: **Θ(n log n)** time across cases; **Θ(n)** extra space; naturally **stable**.

## Practical takeaways
- Prefer **merge sort** (or other **O(n log n)** sorts) once **n** passes classroom sizes.  
- **Bubble** is pedagogical: fine for teaching invariants and **adjacent swaps**, not for production.  
- **Selection** has predictable comparisons but still quadratic; OK for **very small** **n** or constrained environments.

## Related Concepts
- [[Selection Sort — From Summation to O(n²)]] – why comparisons add up quadratically
- [[Merge Sort — Human Demo of Divide & Conquer]] – intuition for the split/merge
- [[Merge Sort — Recurrence Tree and O(n log n)]] – formal **n log n** reasoning
- [[Recursion Basics — Drawing a Pyramid]] – recursion mechanics behind merge sort
- [[Running Time Growth · Big O]] – curve intuition across classes

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Sorting Algorithm Animations](https://www.toptal.com/developers/sorting-algorithms)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

## Terms
[[Selection sort]], [[Bubble sort]], [[Merge sort]], [[Time complexity]], [[Stability]], [[In-place]], [[Swap]], [[Comparison]], [[Auxiliary space]]
