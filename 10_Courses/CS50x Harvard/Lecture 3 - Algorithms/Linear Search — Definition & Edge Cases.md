---
title: "Linear Search — Definition & Edge Cases"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 08
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:29:02"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_17-28-56.png]]

---

## Summary
**Linear search** scans an **unsorted array** element-by-element until it finds the **target** or reaches the end. It’s simple, requires no preprocessing, and is the baseline for discussing **time complexity**.

## Definition
Given array `a` of length `n` and value `x`, check `a[0], a[1], …, a[n-1]` in order. **Early exit** on match; otherwise report failure.

## Complexity
- **Best-case**: **O(1)** (target at index 0).
- **Average-case**: **Θ(n)** (~n/2 checks on random data).
- **Worst-case**: **O(n)** (target absent or at last index).
- **Space**: **O(1)** extra.

## Edge Cases & Gotchas
- **Empty array** (`n == 0`) → immediately “not found”.
- **Duplicates** → returns **first** match; define policy if you need **all** indices.
- **Null pointer** / invalid `n` → guard or assert; avoid **undefined behavior**.
- **Type/compare mismatch** (strings): use **strcmp** for C-strings, not `==`.
- Confusing **best** with **Ω(1)** and **worst** with **O(n)** — both are true, but they describe different scenarios.
- If you can maintain **sorted** data, switch to **binary search** (**Θ(log n)**).

## Reference Implementation (C)
```c
#include <stddef.h>  // size_t
int linear_search(const int *a, size_t n, int x) {
    if (!a) return -1;                  // defensive guard
    for (size_t i = 0; i < n; i++) {
        if (a[i] == x) return (int)i;   // found → index
    }
    return -1;                          // not found
}
```

### String Variant (C-strings)
```c
#include <string.h>   // strcmp
int find_name(char *names[], size_t n, const char *who) {
    for (size_t i = 0; i < n; i++) {
        if (names[i] && strcmp(names[i], who) == 0) return (int)i;
    }
    return -1;
}
```

## When it’s still the right choice
- **Tiny n** where constant factors dominate.
- **One-off checks** where building an index (tree/hash) is overkill.
- Streaming data when you only get **one pass**.

## Related Concepts
- [[Data Structures — Why They Matter]] – structure choice drives search costs
- [[Big-O Notation - Upper Bound (O)]] – worst-case lens for guarantees
- [[Omega Notation - Lower Bound (Ω)]] – best-case/limits perspective
- [[Theta Notation - Tight Bound (Θ)]] – when bounds match in order
- [[Binary search]] – upgrade path with **sorted** arrays
- [[Hash table]] – average **O(1)** lookups by key

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Wikipedia: Linear search](https://en.wikipedia.org/wiki/Linear_search)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

## Terms
[[Linear search]], [[Best-case]], [[Worst-case]], [[Average-case]], [[Time complexity]], [[Early exit]], [[Undefined behavior]], [[Binary search]], [[Hashing]]
