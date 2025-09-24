---
title: Merge Sort
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#shorts/week_3_Algorithms/merge_sort"
tool_tags: ""
atom_idx: 18
status: done
difficulty: hard
date: 2025-08-16
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/3/
review_next: 2025-09-16
---

## Summary
**Merge sort** is a **divide-and-conquer** sorting algorithm: **split** the array into halves until pieces are size 0/1, then **merge** the sorted halves back together. Runs in **O(n log n)** time, typically uses **O(n)** extra memory.

## Very simple
You and a friend sort cards like this: you each sort your half (easy because it's small), then you **merge** your two neat piles by always taking the **smaller top card**. Keep doing this until one big sorted pile remains.

## Key Points
- **Divide and conquer**: recursively split array into left/right halves.
- **Conquer**: sort each half (recursively) until **base case** (length ≤ 1).
- **Combine (merge)**: walk two sorted halves with **two pointers**, copy the smaller element each time.
- Deterministic **O(n log n)** time in best/avg/worst; **stable** if merge keeps equal-order; not **in‑place** in the simple implementation (needs **auxiliary array**).
- Two styles: **Top‑down** (recursive) and **Bottom‑up** (iterative width = 1, 2, 4, …).

## Details

### 1) Splitting (conceptual)
```
[38 27 43 3          9 82 10]

             split
             
[38 27 43 3]         [9 82 10]

     split             split
     
[38 27]  [43 3]     [9 82]  [10]

 split     split      split

[38] [27] [43] [3]  [9] [82] [10]

(base cases: size 1)
```

### 2) Merging (two-pointer walk)
```
Left:  [27 38]      i -> 0
Right: [3 43]       j -> 0
Out:   []

compare L[i]=27 vs R[j]=3  -> take 3
Out: [3]
compare 27 vs 43 -> take 27
Out: [3 27]
compare 38 vs 43 -> take 38
Out: [3 27 38]
append rest of Right -> 43
Out: [3 27 38 43]   (sorted)
```

### 3) Full pass (annotated)
```
Start:
[38 27 43 3 9 82 10]

Split until size 1, then merge up:

[38] [27] [43] [3] [9] [82] [10]
  \  /       \  /     \   /     |
 [27 38]    [3 43]   [9 82]    [10]
      \        /         \        |
     [3 27 38 43]       [9 10 82]
              \           /
          [3 9 10 27 38 43 82]   ← final
```

### 4) Complexity (why O(n log n)?)
- The array is split in half **log₂ n** times (tree height).  
- Each level merges **n** total elements (linear work).  
- Total work ≈ `n * log n`; extra memory ≈ **n** for the temp buffer.

## Examples

### Minimal C implementation (top‑down, stable)
```c
#include <stdio.h>
#include <string.h>   // for memcpy

static void merge(int *a, int l, int m, int r, int *tmp)
{
    int i = l, j = m, k = l;
    while (i < m && j < r)
        tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++]; // stable on equals
    while (i < m) tmp[k++] = a[i++];
    while (j < r) tmp[k++] = a[j++];
    memcpy(a + l, tmp + l, (r - l) * sizeof(int));
}

static void merge_sort_rec(int *a, int l, int r, int *tmp)
{
    if (r - l <= 1) return;            // base case: size 0/1
    int m = l + (r - l) / 2;
    merge_sort_rec(a, l, m, tmp);
    merge_sort_rec(a, m, r, tmp);
    merge(a, l, m, r, tmp);            // combine
}

void merge_sort(int *a, int n)
{
    int tmp[n];                        // auxiliary buffer O(n)
    merge_sort_rec(a, 0, n, tmp);
}
```

### Bottom‑up idea (iterative)
```
for width = 1; width < n; width *= 2:
    for i = 0; i < n; i += 2*width:
        merge(a[i : i+width], a[i+width : i+2*width])
```

## **Why It Matters**
Compared to **selection**/**bubble sort** `O(n^2)`, **merge sort** scales to huge `n`. It’s a reference **stable** sort and a stepping stone to **external sorting** (sorting data from disk) and to analyzing **recurrence relations**.

## Questions
- ❓ How would you make it **in‑place** (no extra array)? What are trade‑offs?
- ❓ When is **bottom‑up** preferable (e.g., avoiding recursion limits)?
- ❓ Why is merge sort **cache‑friendly** compared to quicksort on some inputs?

## Related Concepts
- [[Call Stacks — Function Push-Pop Flow]] – recursion frames used by top‑down merge sort.
- [[Recursion Basics — Drawing a Pyramid]] – base vs recursive case template.
- [[Merge Sort — Recurrence Tree and O(n log n)]] – derive the work per level.
- [[Sort Race — Selection vs Merge vs Bubble (Visualized)]] – comparative behavior.
- [[Selection Sort — From Summation to O(n²)]] – quadratic baseline for contrast.
- [[Binary Search — Recursive Implementation]] – another divide‑and‑conquer routine.
- [[Asymptotic Notation · O, Ω, Θ]] – complexity reasoning for algorithms.
- [[Stable vs Unstable Sorts]] – property of reordering equal keys.

## See also
- [CS50 Shorts — Merge Sort](https://cs50.harvard.edu/x/2025/shorts/merge_sort/)
- [Wikipedia — Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
- [VisuAlgo — Merge Sort](https://visualgo.net/en/sorting?slide=9)

## Terms
[[divide and conquer]], [[merge]], [[two-pointer technique]], [[stable sort]], [[in-place]], [[auxiliary array]], [[recurrence]], [[base case]], [[time complexity]], [[space complexity]]
