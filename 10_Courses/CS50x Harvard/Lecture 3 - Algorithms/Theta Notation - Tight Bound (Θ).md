---
title: "Theta Notation - Tight Bound (Θ)"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 03
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:26:39"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_15-30-42.png]]


---

## Summary
**Θ (theta)** expresses a **tight bound**: the running time grows *both* no faster than and no slower than some function of **n**. Use it when an algorithm’s **best-, average-, and worst-case** are the **same order** asymptotically.

## Big picture (for the trio)
- This note: **Θ** — the **tight bound** view (what it *is exactly* up to constants).
- Next note: **Ω** — the **lower bound** (what any input guarantees at least).
- Next note: **O** — the **upper bound** (a safe ceiling you won’t exceed).
Together they form a non-duplicating toolkit for **asymptotic analysis**.

## When Θ applies (and when it doesn’t)
- Applies when work is **proportional** to **n** every time → e.g., “print all n numbers once” is **Θ(n)**.
- Doesn’t apply to algorithms whose **cases differ by order**. Example: linear search in an **unsorted** array is **best-case Θ(1)** (found at index 0) but **worst-case Θ(n)** — so the algorithm itself isn’t **Θ(n)** overall; we prefer **O(n)** for its **upper bound**.
- For **binary search** on a **sorted** array, every successful/unsuccessful search takes **Θ(log n)** steps → same order in all cases.

## Plain-English definition
There exist positive constants **c₁, c₂, n₀** such that for all **n ≥ n₀**,
`c₁ · f(n) ≤ T(n) ≤ c₂ · f(n)`.
Intuition: **T(n)** is “sandwiched” between two constant-scaled copies of **f(n)**.

## Examples
```c
// Always touches each element exactly once → Θ(n)
long sum(const int *a, int n) {
    long s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s;
}
```
```c
// Binary search on sorted array → Θ(log n)
int bsearch_int(const int *a, int n, int x) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] < x) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
```

## Pitfalls
- **Dropping prerequisites**: claiming **Θ(log n)** without **sorted** data (binary search assumption).
- **Overusing Θ**: if **best ≠ worst** by order, prefer **O**/**Ω** to describe bounds separately.
- **Ignoring constants** is fine for notation, but they still matter for real runtimes on small **n**.

## Related Concepts
- [[Asymptotic notation]] – umbrella term for **O**, **Ω**, **Θ**
- [[Upper bound (Big-O)]] – complements **Θ** with a ceiling guarantee
- [[Lower bound (Omega)]] – complements **Θ** with a floor guarantee
- [[Worst-case vs average-case]] – when bounds diverge, **Θ** may be inapplicable
- [[Binary search]] – canonical **Θ(log n)** routine
- [[Linear scan]] – canonical **Θ(n)** routine

## See Also
- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Asymptotic notation — GeeksforGeeks](https://www.geeksforgeeks.org/analysis-of-algorithms-set-3asymptotic-notations/)
- [CLRS, 3rd ed. — Asymptotic notation (chapter 3)](https://mitpress.mit.edu/9780262033848/introduction-to-algorithms/)

## Terms
[[Theta notation]], [[Tight bound]], [[Asymptotic analysis]], [[Worst-case]], [[Best-case]], [[Average-case]], [[Binary search]], [[Linear time]]
