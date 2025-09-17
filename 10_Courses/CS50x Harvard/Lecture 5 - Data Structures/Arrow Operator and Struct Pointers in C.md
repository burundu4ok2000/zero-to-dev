---
title: "Arrow Operator and Struct Pointers in C"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 01
status: "in-progress"
difficulty: "easy"
date: "2025-09-17"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

---

![[cover_arrow_operator.png]]

---

## Summary
In C, the **arrow operator** (`->`) is used to access fields of a **struct** through a **pointer**. It is shorthand for `(*ptr).field`.  
This operator is crucial for building data structures like **linked lists**, **hash tables**, and **trees**, where nodes are dynamically allocated and connected with pointers.

## Very simple
Think of a **struct** as a **box with slots**.  
- With a **dot (`.`)** you open the box directly.  
- With an **arrow (`->`)** you first follow the **address** (pointer) to the box, and then open the slot.

## Key Points
- `.` is used when you have the struct itself.  
- `->` is used when you have a **pointer to a struct**.  
- `ptr->field` is exactly the same as `(*ptr).field`.  
- Without a struct, `->` cannot be used, because there are no named fields.

## Examples

### Struct definition
```c
typedef struct {
    char *name;
    int year;
} car;
```

### Dot access
```c
car mycar;
mycar.year = 2020;
```

### Arrow access
```c
car *p = &mycar;
p->year = 2020;      // same as (*p).year = 2020;
```

### With malloc (common in data structures)
```c
car *q = malloc(sizeof(car));
if (q) {
    q->name = strdup("Civic");
    q->year = 2018;
    free(q->name);
    free(q);
}
```

## Visual
```
[ mycar box ]
+-----------+
| name | -- |
| year |2020|
+-----------+

p → address of mycar
p->year → go to mycar, open 'year' slot
```

## Why It Matters
- Dynamic memory (via **malloc**) gives you **pointers to structs**.
- Most advanced data structures are made of structs linked together with pointers.
- Using `->` keeps code clean; otherwise you’d write `(*ptr).field` everywhere.

## Related Concepts
- [[Singly-Linked Lists — Core Operations]] – nodes use `->next`.
- [[Doubly-Linked Lists — Basics and Operations]] – nodes use `->prev` and `->next`.
- [[Hash Tables — Arrays and Linked Lists]] – bucket nodes use `->key` and `->value`.
- [[Dynamic Memory Allocation — malloc & free]]
- [[Pointers in C — Address-of & Dereference]]
- [[Structures in C]]

## See also
- [Arrow operator — C reference](https://en.cppreference.com/w/c/language/operator_member_access)
- [GeeksforGeeks: Arrow operator](https://www.geeksforgeeks.org/arrow-operator-in-c-c-with-examples/)

## Terms
[[Arrow operator]], [[Struct]], [[Pointer]], [[Dereference]], [[Dot operator]], [[Field]]
