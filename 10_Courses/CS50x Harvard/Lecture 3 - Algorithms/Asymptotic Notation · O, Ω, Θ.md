---
title: "Asymptotic Notation · O, Ω, Θ"
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 06
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:23:00–00:27:00"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_15-30-42.png]]
![[2025-08-07_15-33-08.png]]
![[2025-08-07_15-34-42.png]]
![[2025-08-07_15-35-29.png]]

---

## One Liner
The **asymptotic notation** family — **O** (upper bound), **Ω** (lower bound), **Θ** (tight bound) — describes how an algorithm’s **time/space complexity** scales with **n**.

## Why three symbols?
- **O** gives a **ceiling**: your algorithm takes *no more than* this order of work for large **n** (safe **worst‑case** claim).
- **Ω** gives a **floor**: any algorithm (or your algorithm on some inputs) needs *at least* this much work.
- **Θ** pins it **exactly** up to constant factors: both upper and lower match the same order.

Together they let you reason precisely without over‑ or under‑promising.

## When to use which
| Goal | Use | Example statement |
|---|---|---|
| Guarantee an algorithm won’t exceed some cost | **O** | “Linear search is **O(n)** in the worst case.” |
| Prove inherent difficulty / best‑case floor | **Ω** | “Any comparison sort is **Ω(n log n)** comparisons.” |
| Show tight growth rate (best=avg=worst in order) | **Θ** | “Binary search is **Θ(log n)** on a sorted array.” |

## Rules of thumb
- Ignore **constant factors** and **lower‑order terms**: they don’t change the class.
- Log bases differ by a constant: **log₂ n**, **log₁₀ n** → same **O(log n)**.
- Preconditions matter: calling **binary search** requires **sorted** data.
- Quote the **model**: comparison sorts obey **Ω(n log n)**; counting sort sidesteps it by avoiding comparisons.
- Use **amortized** analysis for aggregated operations (e.g., dynamic array growth) and be explicit when you do.

## Mini examples (complementary to the trio)
- **O(1)**: swap two variables; push/pop on a stack.
- **Ω(n)**: searching for a missing value in an **unsorted** array forces looking at every element.
- **Θ(n)**: summing all items once.
- **Θ(log n)**: balanced **BST** search height; binary search steps.
- **O(n log n)**: **merge sort** splits and merges across log n levels.

## Related Concepts
- [[Big-O Notation - Upper Bound (O)]] – ceiling view and pitfalls
- [[Omega Notation - Lower Bound (Ω)]] – floor guarantees and models
- [[Theta Notation - Tight Bound (Θ)]] – exact growth when bounds match
- [[Running Time · Big‑O (O(n), O(n÷2), O(log₂ n))]] – growth curves intuition
- [[Worst-case vs average-case]] – how to choose the right lens
- [[Amortized analysis]] – aggregated cost over sequences of ops

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [MIT OCW 6.006: Asymptotic notation notes](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec2/)

## Terms
[[Asymptotic analysis]], [[Time complexity]], [[Upper bound]], [[Lower bound]], [[Tight bound]], [[Order of growth]], [[Worst-case]], [[Average-case]], [[Best-case]], [[Amortized analysis]]
