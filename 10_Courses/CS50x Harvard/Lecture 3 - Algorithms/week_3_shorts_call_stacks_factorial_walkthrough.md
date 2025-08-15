---
title: Week 3 Shorts — Call Stacks — factorial walkthrough
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#shorts/week_3_Algorithms/call_stacks"
tool_tags: ""
atom_idx: 16
status: done
difficulty: easy
date: 2025-08-15
timecode: 05:55
source: https://cs50.harvard.edu/x/2025/shorts/call_stacks/
review_next: 2025-09-15
---

---

// Место для фото материалов

![[Screenshot 2025-08-15 at 18.57.42.png]]

---

## Summary
A **call stack** is a LIFO (**Last In, First Out**) structure the program uses to track which function is running. Each call pushes a **stack frame**; finishing a function pops its frame.

## Very simple
Imagine stacking boxes. Calling a function puts a new box on top (**push**). When it finishes, you remove the top box (**pop**). Only the top box is being opened right now.

## Key Points
- **Push** on call; **pop** on return. Only the **top frame** executes.
- A frame holds **parameters**, **locals**, and a **return address** (where to jump back).
- **Recursion** grows the stack one frame per call until the **base case** returns.
- Order of operations for `printf("%i\n", fact(5))` is “evaluate argument first, then call `printf`.”

## Details
Code in the slide:
```c
int fact(int n) { 
    if (n == 1) return 1; 
    else return n * fact(n-1);
}

int main(void) {
    printf("%i\n", fact(5));
}
```

### ASCII Walkthrough (annotated)
Top of the drawing = **top of stack** (currently running).

**1) Program starts (`main` pushed):**
```
[ main ]                               ← push main
```

**2) `main` evaluates argument `fact(5)` → calls `fact(5)`:**
```
[ fact(5) ]                            ← push fact(5)
[ main ]
```

**3) `fact(5)` calls `fact(4)`:**
```
[ fact(4) ]                            ← push
[ fact(5) ]
[ main ]
```

**4) `fact(4)` calls `fact(3)`:**
```
[ fact(3) ]                            ← push
[ fact(4) ]
[ fact(5) ]
[ main ]
```

**5) `fact(3)` calls `fact(2)`:**
```
[ fact(2) ]                            ← push
[ fact(3) ]
[ fact(4) ]
[ fact(5) ]
[ main ]
```

**6) `fact(2)` calls `fact(1)` (base case):**
```
[ fact(1) ]                            ← push
[ fact(2) ]
[ fact(3) ]
[ fact(4) ]
[ fact(5) ]
[ main ]
```

**7) `fact(1)` returns 1:**
```
[ fact(2) ]                            ← pop fact(1), resume fact(2)
[ fact(3) ]
[ fact(4) ]
[ fact(5) ]
[ main ]
```

**8) `fact(2)` computes 2 * 1 → returns 2:**
```
[ fact(3) ]                            ← pop fact(2), resume fact(3)
[ fact(4) ]
[ fact(5) ]
[ main ]
```

**9) `fact(3)` computes 3 * 2 → returns 6:**
```
[ fact(4) ]                            ← pop fact(3), resume fact(4)
[ fact(5) ]
[ main ]
```

**10) `fact(4)` computes 4 * 6 → returns 24:**
```
[ fact(5) ]                            ← pop fact(4), resume fact(5)
[ main ]
```

**11) `fact(5)` computes 5 * 24 → returns 120 to `main`:**
```
[ main ]                               ← pop fact(5), resume main
```

**12) `main` now calls `printf` with 120:**
```
[ printf ]                              ← push printf
[ main ]
```

**13) `printf` finishes → prints `120` → returns to `main`:**
```
[ main ]                               ← pop printf, resume main
```

**14) `main` returns → program ends:**
```
<empty>                                 ← pop main
```

## **Why It Matters**
Grasping the call stack helps diagnose **stack overflow**, reason about **recursion depth**, read **stack traces**, and avoid bugs from uninitialized locals.

## Questions
- ❓ Where is the **return address** saved and how do debuggers show it?  
- ❓ What is the typical stack size on your OS/toolchain, and how deep could `fact(n)` go?

## Related Concepts
- [[Recursion Basics — Drawing a Pyramid]] – explicit base case and growth/return pattern.
- [[Merge Sort — Recursion Flow]] – stack depth is `O(log n)` for balanced divide & conquer.
- [[Binary Search — Recursive Implementation]] – shows base/recursive cases and returns.
- [[Function Parameters & Locals in C]] – data that lives inside each stack frame.
- [[Debugging Step Into vs Step Over]] – frames change as you step into/over calls.
- [[Memory Layout in C Programs]] – stack vs heap vs globals.
- [[Return Address and Control Flow]] – where the CPU goes after `ret`.
- [[Selection Sort — From Summation to O(n²)]] – contrast with iterative algorithms.

## See also
- [[Merge Sort — Recurrence Tree and O(n log n)]]
- [CS50 Shorts — Call Stacks](https://cs50.harvard.edu/x/2025/shorts/call_stacks/)
- [Wikipedia: Call stack](https://en.wikipedia.org/wiki/Call_stack)

## Terms
[[stack]], [[push]], [[pop]], [[stack frame]], [[base case]], [[recursion]], [[return address]], [[stack overflow]]
