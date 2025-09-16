---
title: "Structs in C — Dereferencing with Parentheses"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 09
status: "in-progress"
difficulty: "easy"
date: "2025-09-16"
timecode: "05:44"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

// Место для фото материалов

![[Screenshot 2025-09-15 at 21.45.07.png]]

---

## Summary
When accessing a **struct** field via a **pointer**, parentheses are needed: `(*mycar).year`.  
This is because the **. (dot)** operator has higher precedence than **\*** (dereference).  

## Very simple
Think of it like math: in `a + b * c`, multiplication happens first.  
Here, the **dot** happens first unless you use parentheses, so we write `(*ptr).field`.

## Key Points
- `.` (dot) → field access has **higher precedence** than `*`.
- Without parentheses: `*mycar.year` means `*(mycar.year)`, which is wrong.
- Correct: `(*mycar).year` → dereference first, then access `.year`.
- Shortcut: `mycar->year` does the same thing and is easier to read.

## Details
In C:
- Operator precedence: `.` and `->` are very high (evaluated before `*`).
- So `*mycar.year` = take `mycar.year` (invalid if `mycar` is a pointer).
- Parentheses force the correct order: dereference, then field access.

## Examples
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
} car;

int main(void) {
    car *mycar = malloc(sizeof(car));
    (*mycar).year = 2011;   // explicit with parentheses
    mycar->year = 2011;     // shorthand operator
    printf("%d\n", mycar->year);
    free(mycar);
}
```

ASCII view:
```
mycar (pointer) ---> [ year: 2011 ]
```

## **Why It Matters**
Understanding precedence prevents **bugs**.  
Using `->` is cleaner and avoids mistakes, but knowing why `(*ptr).field` works is key for reading old code.

## Questions
- When should you prefer `(*ptr).field` vs `ptr->field`?
- How does operator precedence chart explain this?

## Related Concepts
- [[Pointers in C — Address-of & Dereference]] – explains `*` and `&`.
- [[Structures in C — Definition & Usage]] – intro to structs.
- [[Operator Precedence in C]] – why `.` wins over `*`.
- [[Dynamic Memory Allocation — malloc & free]] – why we get `struct` via pointer.
- [[Syntax Sugar — Arrow Operator ->]] – shorthand for `(*ptr).field`.

## See also
- [C Operator Precedence — cppreference](https://en.cppreference.com/w/c/language/operator_precedence)
- [Structs and Pointers in C (GeeksforGeeks)](https://www.geeksforgeeks.org/pointer-to-structure-in-c/)

## Terms
[[Pointer]], [[Dereference]], [[Struct]], [[Dot operator]], [[Arrow operator]], [[Operator precedence]]
