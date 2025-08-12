---
title: "Running Time · Big‑O (O(n), O(n÷2), O(log₂ n))"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 02
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:21:10"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_15-24-59.png]]
[[2025-08-07_15-24-59.png]]

![[2025-08-07_15-24-37.png]]
[[2025-08-07_15-24-37.png]]

---

## Summary
A quick visual for **Big-O** growth rates: **O(n)** (linear), **O(n÷2)** (same linear class; constant factor), and **O(log₂ n)** (logarithmic). Shows how **runtime** scales with **input size n**.

## Key Points
- **Big-O** measures **order of growth** of **running time** (or **space**) as **n** grows.
- **O(n÷2) ≡ O(n)** — constant factors don’t change the class; we drop them in **asymptotic analysis**.
- **O(log₂ n)** comes from repeatedly cutting the problem size (e.g., **binary search** halves the search space each step).
- For small **n** linear can look fast, but as **n → large**, **logarithmic** growth dominates.
- Focus on **worst‑case** unless otherwise stated; it provides a safe upper bound.

## Details
- If an algorithm does a loop over every element once, its time is proportional to **n** → **O(n)**.
- If it does a constant‑fraction of that work, like **n/2** checks, we still write **O(n)** because constants are ignored.
- **O(log₂ n)** arises when each step reduces the problem size by a constant factor (½, ⅓, etc.). A classic example is **binary search** on a **sorted** array.
- When comparing algorithms, constants and low‑order terms matter in practice for small inputs, but **asymptotics** tell you how it scales.

## Examples
```c
// Linear scan: O(n)
int linear_search(int a[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target) return i;
    }
    return -1;
}
```

```c
// Binary search (array must be sorted): O(log2 n)
int binary_search(int a[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

## **Why It Matters**
Choosing between **linear** and **logarithmic** algorithms is the difference between hours and milliseconds at scale. It guides data‑structure choices (arrays vs trees/indices) and informs real‑world performance budgeting.

## Questions
- ❓ What real data in the course can we speed up by swapping **linear search** for **binary search**?
- ❓ Where do we see **logarithmic** behavior beyond searching (e.g., tree height, divide‑and‑conquer sorts)?

## Related Concepts
- [[Algorithm analysis]] – connects the curve shapes with proof techniques and bounds
- [[Merge sort]] – divide‑and‑conquer with O(n log n) running time
- [[Selection sort]] – simple O(n²) baseline to contrast with faster methods
- [[Bubble sort]] – another O(n²) algorithm for comparison
- [[Worst-case vs average-case]] – different lenses on performance guarantees
- [[Binary search tree]] – data structure whose height gives O(log n) operations
-  [[Asymptotic Notation · O, Ω, Θ]] – family: **O**, **Ω**, **Θ**

## See also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Khan Academy: Intro to Big‑O notation](https://www.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/big-o-notation)

## Terms
[[Big-O notation]], [[Linear time]], [[Logarithmic time]], [[Binary search]], [[Time complexity]], [[Order of growth]], [[Constant factors]], [[Asymptotic analysis]]
