---
title: "Lecture 2 — Arrays: Passing Scalars vs Arrays to Functions"
aliases: 
note_type: lecture_note
course: CS50x Harvard
course_tag: cs50x
module: 
lecture_no: 2
lecture_title: Arrays
lecture_ref: "[[Lecture 2 — Arrays]]"
atom_type: idea
atom_idx: 1
tags:
  - functions
  - arrays
  - memory
  - value
  - reference
status: done
difficulty: medium
date: 2025-08-10
timecode: 00:13:34
source: https://cs50.harvard.edu/x/2025/weeks/2/
related:
  - - Pointers Basics
  - - Function Parameters in C
review_next: 2025-08-17
---


## Summary
In C, scalar variables like integers are passed by value to functions, meaning changes inside the function don't affect the original. However, arrays decay to pointers when passed, allowing functions to mutate the original array.

## Key Points
- Scalars (e.g., int, char) are passed by value: functions receive a copy and cannot change the original.
- Arrays are passed as pointers to their first element: functions can modify the original array through this pointer.
- This behavior explains why attempts to change scalars fail but succeed for arrays.

## Details
When calling a function like set_int(a), C passes a copy of the value of a (e.g., 10). The function modifies its local copy, which is discarded upon return, leaving the original a unchanged.

In contrast, for set_array(b), C passes a pointer to the first element of b. The function uses this pointer to access and modify the same memory location as the original array, so changes persist after the function returns.

This is a key rule in C: arrays "decay" to pointers in function arguments, effectively passing by reference. Scalars are passed by value unless explicitly passed as pointers (e.g., &a).

Memory visualization:

main()
┌─────┐   copy (10)    set_int()
│  a  │──────────────► [ x ]  (modified → 22, then discarded)
└─────┘

┌──────────────┐ pointer   set_array()
│ b[0] b[1]…   │──────────► [array]── modifies b[0] to 22
└──────────────┘

Take-away patterns:
1. To mutate a scalar, pass a pointer: void set_int(int *x) { *x = 22; } and call set_int(&a).
2. Arrays are already passed as pointers, so writes inside the function change the caller's array.
3. Use pointers for shared memory communication beyond return values.

## Examples/Demos
Code from the slide demonstrating the behavior:

```
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = {0, 1, 2, 3};

    set_int(a);     // try to change a
    set_array(b);   // try to change b

    printf("%d %d\n", a, b[0]);
}

// ── helpers ───────────────────────────────────────────
void set_array(int array[4])
{
    array[0] = 22;          // attempt succeeds
}

void set_int(int x)
{
    x = 22;                 // attempt fails
}
```

**Output**

```
10 22
```

| **Call**     | **What C passes under the hood**      | **Result**                                                                |
| ------------ | ------------------------------------- | ------------------------------------------------------------------------- |
| set_int(a)   | **Copy** of a (value 10)              | Function changes its **local** copy; the original a is untouched.         |
| set_array(b) | **Pointer** to the first element of b | Function writes through the pointer, mutating the same memory b occupies. |

![[2025-08-01_17-46-53.png]]

## **Why It Matters**

Understanding pass-by-value vs. array decay to pointers is crucial for managing memory and avoiding bugs in C programs, especially when functions need to modify data. It applies to data structures, algorithms, and system programming where efficient memory access is key.

## Questions

- ❓How does this behavior differ in other languages like Python or Java?
- ❓What happens when passing structs or other compound types?

  

## See also

- [[Lecture 2 — Arrays]]
- [CS50 Lecture 2 Video]({})
-