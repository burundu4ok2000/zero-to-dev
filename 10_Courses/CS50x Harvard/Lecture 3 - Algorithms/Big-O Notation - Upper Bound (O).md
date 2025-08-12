---
title: "Big-O Notation - Upper Bound (O)"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 05
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:23:23"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_15-34-42.png]]
[[2025-08-07_15-34-42.png]]

---

## Summary
**Big-O** is an **upper bound**: it says your algorithm runs in **no more than** some function of **n** for sufficiently large inputs. It’s the safe ceiling engineers quote for **worst‑case** behavior, ignoring **constant factors** and **lower-order terms**.

## Reading the slide
Common classes you’ll meet all semester:
- **O(1)**  — constant time (e.g., simple arithmetic, index access in an array).
- **O(log n)** — halves/thirds the problem each step (**binary search**, balanced trees).
- **O(n)** — touches each element once (**linear scan**, streaming pass).
- **O(n log n)** — divide‑and‑conquer (**merge sort**, average **quick sort**).
- **O(n²)** — double nested loops (naïve comparisons, **bubble/selection sort**).

## When to use **O**
- Describing **worst‑case** cost of your algorithm or data structure operation.
- Communicating scalability without drowning in machine‑dependent constants.
- Providing guarantees: “Insert is **O(log n)**”, “Sort is **O(n log n)**”.

## Core rules
- Drop constants: **O(2n)** → **O(n)**; **O(n/2)** → **O(n)**.
- Drop lower orders: **O(n² + n)** → **O(n²)**.
- Preconditions matter: calling **binary search** on unsorted data is not **O(log n)**—it’s just **wrong**.

## Examples
```c
// O(1): constant-time update
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
```

```c
// O(n): single pass
int count_positives(const int *a, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) if (a[i] > 0) c++;
    return c;
}
```

```text
O(n log n): merge sort idea
- Split the array in half (log n levels),
- Merge linear work per level (n),
- Total work ≈ n · log n.
```

```c
// O(n^2): pairwise comparison
int pairs_equal(const int *a, int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j]) c++;
    return c;
}
```

## Pitfalls
- **Average vs worst case**: a hash table lookup is often **amortized O(1)** but **worst‑case O(n)**. Be explicit.
- **Asymptotics ≠ performance**: a well‑tuned **O(n)** can beat a sloppy **O(log n)** for small **n**.
- **Hidden constants**: “constant‑time” can still be slow if the constant is huge.

## Related Concepts
- [[Theta notation - Tight Bound (Θ)]] – when best/average/worst match in order
- [[Omega Notation - Lower Bound (Ω)]] – floor guarantees and model limits
- [[Merge sort]] – canonical **O(n log n)** sort
- [[Quicksort]] – average **O(n log n)**, worst **O(n²)** without good pivots
- [[Balanced binary search tree]] – **O(log n)** search/insert/delete
-  [[Asymptotic Notation · O, Ω, Θ]] – family: **O**, **Ω**, **Θ**

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- [MIT OCW 6.006: Asymptotic notation notes](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec2/)

## Terms
[[Big-O notation]], [[Upper bound]], [[Time complexity]], [[Asymptotic analysis]], [[Worst-case]], [[Lower-order terms]], [[Constant factors]]
