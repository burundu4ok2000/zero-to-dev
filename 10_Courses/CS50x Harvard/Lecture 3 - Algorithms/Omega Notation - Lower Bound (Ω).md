---
title: "Omega Notation - Lower Bound (Ω)"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 04
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:25:21"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_15-33-08.png]]

---

## Summary
**Ω (omega)** gives a **lower bound** on running time: for sufficiently large **n**, the algorithm will take **at least** some function **f(n)** steps on **some inputs**. It complements **Θ** (tight bound) and **O** (upper bound) without duplicating them.

## Where Ω shines
- Proving that no algorithm (in a given model) can beat a certain speed. Example: any **comparison-based sort** needs **Ω(n log n)** comparisons.
- Showing the **best possible** case for your own algorithm (e.g., early exit yields **Ω(1)**).

## What Ω is *not*
- Not automatically the **best-case**; it’s a **mathematical floor**. Best-case is one way to *witness* a lower bound, but Ω statements can be model-wide (e.g., all comparison sorts).
- Not a performance promise for every input; it says there **exist inputs** that require at least that much work.

## Examples
```c
// Membership in an UNSORTED array → Ω(n) in the worst case
int contains_unsorted(const int *a, int n, int x) {
    for (int i = 0; i < n; i++)               // may have to look at every element
        if (a[i] == x) return 1;
    return 0;
}
// For some inputs (x absent), any algorithm must inspect all n → Ω(n).
```

```c
// Early-exit check → Ω(1) best case
int starts_with_letter_a(const char *s) {
    return s && s[0] == 'A';   // constant work if string present
}
```

```text
Comparison sorting lower bound (model: key comparisons):
Any algorithm must perform Ω(n log n) comparisons on some inputs.
Sketch: Decision-tree height for all n! orderings is at least log2(n!) ≈ n log2 n.
```

## Pitfalls
- **Conflating Ω with best-case**: best-case is a *specific scenario*; Ω can be broader, proving inherent difficulty.
- **Model mismatch**: the Ω(n log n) bound is for **comparison** sorts; counting sort can be **O(n + k)** because it doesn’t compare keys.
- **Asserting Ω without witness**: always know *which inputs* force the lower bound or *which model* you’re in.

## Related Concepts
- [[Asymptotic Notation · O, Ω, Θ]] – family: **O**, **Ω**, **Θ**
- [[Comparison model]] – the assumption behind the sorting lower bound
- [[Decision tree argument]] – tool to prove Ω(n log n) for sorting
- [[Counting sort]] – escapes the comparison bound via **bucketing**
- [[Worst-case vs average-case]] – different lenses to apply bounds
- [[Linear scan]] – yields Ω(n) on absence cases

## See Also
- [Big Omega notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation#Big_Omega_notation)
- [Lower bounds for sorting (MIT OCW 6.006 notes)](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec12/)
- [CLRS: Comparison sorts and decision trees](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms-4e/)

## Terms
[[Omega notation]], [[Lower bound]], [[Decision tree]], [[Comparison sort lower bound]], [[Best-case]], [[Worst-case]], [[Unsorted search]], [[Model of computation]]
