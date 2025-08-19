---
title: "Sorting Algorithms — Selection vs Bubble vs Merge (Cheat Sheet)"
lang_tags: "#lang/c"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 16
status: "done"
difficulty: "easy"
date: "2025-08-19"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-19"
---

![[2025-08-07_19-59-33.png]]

## One Liner
Side‑by‑side reference for **selection sort**, **bubble sort**, and **merge sort** — their **time complexity**, **space**, **stability**, and when each one makes sense.

---

## TL;DR Comparison
| Algorithm | **Best** | **Average** | **Worst** | **Space** | **Stable** | **In‑place** | Typical Use |
|---|---|---|---|---|---|---|---|
| Selection | **Θ(n²)** | **Θ(n²)** | **Θ(n²)** | **O(1)** | No (typically) | Yes | Tiny arrays; predictable comparisons |
| Bubble    | **Θ(n)** (early exit) | **Θ(n²)** | **Θ(n²)** | **O(1)** | Yes (classic) | Yes | Pedagogy; nearly‑sorted data |
| Merge     | **Θ(n log n)** | **Θ(n log n)** | **Θ(n log n)** | **Θ(n)** | Yes | No (array variant) | Large data; stable sort needs |

> Notes: **Stability** preserves equal‑key order; **In‑place** means extra **auxiliary space** is **O(1)**.

---

## Cheatsheet — Selection Sort
- **Idea**: repeatedly select the **minimum** from the unsorted suffix and **swap** to the front.
- **Complexity**: fixed **(n−1)+(n−2)+…+1 = Θ(n²)** **comparisons**; ≤ **n−1** **swaps**; **O(1)** space.
- **Properties**: Not **stable** by default; **in‑place**; order of input doesn’t change comparison count.
- **Good for**: very small **n**, code clarity, constrained memory.
- **C stub**:
```c
void selection_sort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
	    int m=i;
        for(int j=i+1;j<n;j++)
        if(a[j]<a[m]) m=j;
        if(m!=i)
        {
        int t=a[i];
        
        a[i]=a[m];
        
        a[m]=t;
        }
    }
}
```

---

## Cheatsheet — Bubble Sort
- **Idea**: repeatedly **bubble up** the largest element by swapping **adjacent** out‑of‑order pairs.
- **Complexity**: worst **Θ(n²)** swaps/comparisons; **best Θ(n)** with early‑exit pass (no swaps); **O(1)** space.
- **Properties**: **Stable**, **in‑place**; great for spotting invariants; slow for large **n**.
- **Good for**: nearly‑sorted sequences where early exit triggers quickly.
- **C stub** (with early exit):
```c
bool bubble_sort(int a[], int n){
    bool swapped; 
    do
    {
        swapped=false;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]>a[i])
            {
            int t=a[i-1];
            
            a[i-1]=a[i];
            
            a[i]=t;
            
            swapped=true;
            }
        }
        n--;                 // last element fixed
    }while(swapped);
    return true;
}
```

---

## Cheatsheet — Merge Sort
- **Idea**: **divide & conquer** — split, **recursively** sort halves, **merge** linearly.
- **Complexity**: **Θ(n log n)** across cases; **Θ(n)** **auxiliary space** for merge buffer.
- **Properties**: **Stable** (array version), not **in‑place**; parallel‑friendly; consistent performance.
- **Good for**: large arrays, when **stability** matters, or predictable throughput is needed.
- **C stub** (sketch):
```c
void merge_sort(int a[], int l, int r)
{
    if(l>=r) 
    return;
    
    int m=l+(r-l)/2;
    
    merge_sort(a,l,m); 
    merge_sort(a,m+1,r);
    merge(a,l,m,r); 
    // merges using a temp buffer
}
```

---

## When to choose what
- Pick **merge sort** for big data or when **stable** ordering is needed.  
- Keep **bubble** for teaching and for **nearly‑sorted** inputs where it can finish in **Θ(n)**.  
- Use **selection** when memory is tight and **swap cost** must be minimal (≤ n−1).

## Pitfalls
- Claiming **O(log n)** without meeting **preconditions** (e.g., sorted data for **binary search**, not a sort itself).  
- Forgetting that merge needs **auxiliary space** and is not **in‑place** in the array variant.  
- Assuming bubble is always quadratic — with **early exit**, best case is **linear**.

## Related Concepts
- [[Selection Sort — From Summation to O(n²)]] – the arithmetic‑series proof
- [[Merge Sort — Human Demo of Divide & Conquer]] – intuition first
- [[Merge Sort — Recurrence Tree and O(n log n)]] – formal bound
- [[Sort Race — Selection vs Merge vs Bubble (Visualized)]] – growth curves in one picture
- [[Recursion Basics — Drawing a Pyramid]] – mechanics you need for merge sort
- [[Asymptotic Notation · O, Ω, Θ]] – the language of the bounds

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [Sorting Algorithm Animations](https://www.toptal.com/developers/sorting-algorithms)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

## Terms
[[Selection sort]], [[Bubble sort]], [[Merge sort]], [[Time complexity]], [[Space complexity]], [[Stability]], [[In‑place]], [[Auxiliary space]], [[Divide & conquer]]
