---
title: "Merge Sort — Human Demo of Divide & Conquer"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 13
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "01:58:19"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_20-16-30.png]]

---

## Summary
**Merge sort** embodies **divide & conquer**: split the array in half, **recursively** sort each half, then **merge** the two sorted halves. The merge work per level is **O(n)** and there are **log₂ n** levels, yielding **O(n log n)** time and **O(n)** extra space.

## Human demo logic
1. **Divide**: keep halving the list until each sublist has size 1 (already sorted).
2. **Conquer**: merge neighboring sublists by repeatedly taking the **smaller front** element.
3. **Combine**: merged runs grow 1→2→4→… until the entire list is sorted.

## Properties
- **Time**: **Θ(n log n)** in best/avg/worst cases (work is uniform across levels).
- **Space**: **Θ(n)** auxiliary buffer for merging.
- **Stable**: equal keys preserve input order (with a standard merge).
- **Parallel-friendly**: independent halves can be processed concurrently.

## Pseudocode (C-ish)
```c
void merge(int a[], int l, int m, int r) 
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void merge_sort(int a[], int l, int r) {
    if (l >= r) return;                  // base case: size 0 or 1
    int m = l + (r - l) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, r);
}
```

## Why O(n log n)?
- The recursion makes **log₂ n** levels (split in half each time).
- Each level merges **n** total elements across subproblems.
- Total ≈ **n × log₂ n** operations (drop constants → **O(n log n)**).

## When to use
- Large arrays where **O(n²)** sorts are too slow.
- When **stability** matters (e.g., multi-key sorting).
- External/linked-list variants can be adapted to reduce memory overhead.

## Pitfalls
- Forgetting the **auxiliary buffer** (can’t merge in place straightforwardly).
- Off-by-one errors in indices during merge.
- For very small subarrays, switching to **insertion sort** can improve constants.

## Related Concepts
- [[Recursion Basics — Drawing a Pyramid]] – recursion pattern and stack depth
- [[Selection Sort — From Summation to O(n²)]] – baseline quadratic to compare
- [[Quicksort]] – average **O(n log n)** with in-place partitioning
- [[Asymptotic Notation · O, Ω, Θ]] – formal proof intuition for **n log n**
- [[Running Time Growth · Big O]] – interpreting curve differences

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Merge sort — Wikipedia](https://en.wikipedia.org/wiki/Merge_sort)
- [MIT OCW 6.006 lecture notes on sorting](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec3/)

## Terms
[[Merge sort]], [[Divide and conquer]], [[Recursion]], [[Merge step]], [[Stability]], [[Auxiliary space]], [[Time complexity]]
