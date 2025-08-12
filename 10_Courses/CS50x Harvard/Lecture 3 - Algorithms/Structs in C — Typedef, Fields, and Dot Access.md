---
title: "Structs in C — Typedef, Fields, and Dot Access"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 09
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:51:48"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_18-00-05.png]]

---

## Summary
A **struct** groups related **fields** into one **record** so your code is clearer and safer than juggling **parallel arrays**. With **typedef** you give the structure a short type name, and with **dot access** (`person.name`) you reach its fields.

## Minimal pattern
```c
typedef struct
{
    string name;
    string number;
} person;          // new type name

person p = { .name = "David", .number = "+1-617-495-1000" };
printf("%s\n", p.name);  // dot access
```

## Arrays of records
```c
person people[3];
people[0].name = "David";
people[0].number = "+1-617-495-1000";
```
- **Contiguous** layout: an **array of structs** sits sequentially in memory.
- Prefer this to **parallel arrays** (`string names[]`, `string numbers[]`) to avoid index bugs and keep data coherent.

## Passing to functions
```c
void print_person(const person *p) {
    printf("%s: %s\n", p->name, p->number);  // arrow for pointers
}
```
- By value copies the whole **record**; by pointer passes an **address** and uses the **arrow operator** (`->`).

## Common pitfalls
- Forgetting **typedef** (not wrong, just noisy: `struct person` everywhere).
- Mixing **parallel arrays** with a **struct** → duplicated state and drift.
- Mishandling **C-strings**: ensure **null-terminated** strings and compare with **strcmp**, not `==`.

## When to reach for a struct
- You have an **entity** with multiple **fields** (name, phone, id).
- You want to pass/return a **group of values** as one object.
- You plan to search or sort by a **key field**; the interface remains stable if you later switch to a **sorted array**, **hash table**, or **tree**.

## Related Concepts
- [[Data Structures — Why They Matter]] – picking the right container changes complexity
- [[phonebook.c — Arrays of Structs in Practice]] – practical init and field access
- [[Binary search]] – works on a **sorted array** of records by a key
- [[Hash table]] – average **O(1)** lookups by key
- [[Memory layout: AoS vs SoA]] – **Array of Structs** vs **Struct of Arrays**

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [C struct — cppreference](https://en.cppreference.com/w/c/language/struct)
- [C FAQ: struct vs typedef](https://c-faq.com/decl/typedefvsstruct.html)

## Terms
[[struct]], [[typedef]], [[Record]], [[Field]], [[Dot operator]], [[Arrow operator]], [[Array of structs]], [[Parallel arrays]], [[Pass by value]], [[Pass by pointer]]
