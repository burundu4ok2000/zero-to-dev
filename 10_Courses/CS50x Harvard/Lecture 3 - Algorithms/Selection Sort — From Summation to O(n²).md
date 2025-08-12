---
title: "Selection Sort — From Summation to O(n²)"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 11
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "01:18:43"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_18-44-26.png]]

---

## Summary
**Selection sort** repeatedly selects the **minimum** remaining element and swaps it into place. Its **time complexity** is **O(n²)** because the number of **comparisons** forms an **arithmetic series** that grows quadratically with **n**.

## Algorithm snapshot
1. For each index `i` from `0` to `n-2`:
   - Scan the suffix `i..n-1` to find the **min index** `m`.
   - **Swap** `a[i]` and `a[m]` (if different).
- Data moves are at most **n−1 swaps**; the cost is dominated by **comparisons**.

## From summation to O(n²)
- On pass 1 you compare up to **n−1** times, then **n−2**, …, **2**, **1**.  
- Total comparisons:  
  `(n−1) + (n−2) + … + 2 + 1 = n(n−1)/2`  
- Drop constants and lower-order terms → **Θ(n²)** comparisons → **O(n²)** running time.

### Why constants drop
- `n(n−1)/2 = (1/2)n² − (1/2)n`.  
  As **n** grows, the **n²** term dominates; multiply by a constant or add a lower-order term and the **Big‑O** class stays the same.

## Properties & edge cases
- **In-place**: **O(1)** extra space.  
- **Unstable** by default (equal keys can swap order).  
- Performs the **same** comparisons regardless of initial order (best = worst = average by **order**).  
- Small **n**: constants might make it acceptable; large **n**: quadratic quickly becomes impractical.

## Reference C code (compact)
```c
void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)      // (n-1) + (n-2) + ... + 1 comparisons total
            if (a[j] < a[m]) m = j;
        if (m != i) { int t = a[i]; a[i] = a[m]; a[m] = t; }  // at most n-1 swaps
    }
}
```

## When to use (rarely)
- Educational baseline; acceptable for tiny arrays or when **code simplicity** beats performance.  
- Otherwise prefer **O(n log n)** sorts (e.g., **merge sort**, **quicksort** average case).

## Related Concepts
- [[Selection Sort — What O(n²) Means in Practice]] – interpreting the quadratic cost
- [[Merge sort]] – **O(n log n)** via divide-and-conquer
- [[Quicksort]] – average **O(n log n)**, worst **O(n²)**
- [[Asymptotic Notation · O, Ω, Θ]] – formal language for the summation
- [[Running Time Growth · Big O]] – curve comparison and intuition

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

## Terms
[[Selection sort]], [[Minimum]], [[Swap]], [[Comparison]], [[Arithmetic series]], [[Time complexity]], [[In-place]], [[Stability]]
