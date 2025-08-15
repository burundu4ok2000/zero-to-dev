---
title: "Merge Sort — Recurrence Tree and O(n log n)"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 14
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "02:00:41"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_20-21-14.png]]

---

## Summary
Why **merge sort** runs in **O(n log n)**: the **recurrence tree** shows **log₂ n** levels of recursion, each performing **Θ(n)** work to **merge**. Summing level costs yields **Θ(n log n)** total time and **Θ(n)** extra space for the auxiliary buffer.
## Recurrence and Level-Cost View

- Work for each call: **T(n) = 2·T(n/2) + Θ(n)**. This means we do two smaller sorts and then combine them.
- **Tree depth**: When we split the problem in half each time, we get about **log₂ n** levels until the pieces are size 1.
- **Cost at each level**: At each level, all the merges together cost about **n**. So, each level costs **Θ(n)**.
- **Total work**: Since there are about **log₂ n** levels and each costs **Θ(n)**, the total work is **Θ(n log n)**.

```
Level 0:       n          →  Θ(n)
Level 1:   n/2 + n/2      →  Θ(n)
Level 2: n/4 + n/4 + ...  →  Θ(n)
...
Level log n:   n·(1/n)×n?  →  Θ(n) across the level
Sum over levels = Θ(n log n)
```

## Master Theorem (sanity check)
`T(n) = a·T(n/b) + f(n)` with `a = 2`, `b = 2`, `f(n) = Θ(n)` ⇒ `n^{log_b a} = n`.  
Since `f(n) = Θ(n^{log_b a})`, we are in **Case 2** ⇒ **T(n) = Θ(n log n)**.

## Why the space is Θ(n)
The **merge** needs temporary storage proportional to the current subarray size. Even though subproblems exist at different recursion levels, merges happen level-by-level; peak auxiliary space is **Θ(n)**.

## Pitfalls
- **In-place merge** is nontrivial; ignoring the extra buffer leads to incorrect complexity claims.
- Off-by-one errors when splitting and merging ranges (`mid = l + (r - l)/2` is safer).
- Confusing **number of levels** (logarithmic) with **work per level** (linear).

## Related Concepts
- [[Merge Sort — Human Demo of Divide & Conquer]] – intuition before the math
- [[Recursion Basics — Drawing a Pyramid]] – base/recursive cases and stack depth
- [[Selection Sort — From Summation to O(n²)]] – quadratic baseline to compare
- [[Asymptotic Notation · O, Ω, Θ]] – language for bounds
- [[Running Time Growth · Big O]] – curve intuition (linear vs log-linear)

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Master Theorem — Wikipedia](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms))
- [MIT OCW 6.006 Notes: Recurrences & Tree Method](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec2/)

## Terms
[[Recurrence relation]], [[Recurrence tree]], [[Master theorem]], [[Merge sort]], [[Time complexity]], [[Auxiliary space]], [[Divide and conquer]], [[Asymptotic analysis]]
