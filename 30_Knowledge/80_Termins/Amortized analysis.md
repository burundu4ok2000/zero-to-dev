---
title: Amortized analysis
lang_tags: ""
type_tags: "#type/concept"
tool_tags: ""
status: in-progress
difficulty: medium
date: 2025-08-14
source: "#course/cs50x/intoduction_to_CS"
review_next: 2025-09-14
---

---
## **One-liner

> **Amortized analysis** spreads the cost of rare **expensive operations** over a **sequence of operations**, giving an **average cost per operation** (e.g., **amortized O(1)** appends in a **dynamic array**).

## Examples

### Example 1
```c
// Dynamic array push with doubling: occasional O(n) resize → amortized O(1)
typedef struct {
    int *data;
    int size;
    int cap;
} vec;

void push(vec *v, int x) {
    if (v->size == v->cap) {                 // resize (expensive, but rare)
        v->cap = v->cap ? v->cap * 2 : 1;
        int *new_data = realloc(v->data, v->cap * sizeof(int));
        if (!new_data) exit(1);
        v->data = new_data;
    }
    v->data[v->size++] = x;                  // cheap, O(1)
}
````

### **Example 2 (optional)**

```python
# Binary counter: flipping many bits occasionally, but amortized O(1) per increment
bits = [0]*8  # little-endian
def increment(bits):
    i = 0
    while i < len(bits) and bits[i] == 1:
        bits[i] = 0   # flip back to 0
        i += 1
    if i < len(bits):
        bits[i] = 1
```

##  Related Terms

[[Linear Search — Definition & Edge Cases]], [[Selection Sort — From Summation to O(n²)]], [[Merge Sort — Recurrence Tree and O(n log n)]], [[Data Structures — Why They Matter]], [[Big-O notation]], [[Dynamic array]], [[Amortized O(1)]], [[Potential method]]

  

## See also

- [MIT 6.006 — Amortized Analysis (lecture notes)](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/lecture-6-amortized-analysis/)
- [Stanford CS166 — Amortized Analysis (slides)](https://stanford.edu/class/cs166/lectures/01/Small01.pdf)
- [CLRS — Chapter 17: Amortized Analysis (book reference)](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)
