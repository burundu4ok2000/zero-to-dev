---
title: "phonebook.c — Arrays of Structs in Practice"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_3_Algorithms"
tool_tags: ""
atom_idx: 10
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: "00:52:30"
source: "https://cs50.harvard.edu/x/2025/weeks/3/"
review_next: "2025-09-12"
---

![[2025-08-07_18-04-16.png]]

---

## Summary
Turning the toy **person** type into a working **phonebook.c**: store **records** in an **array of structs**, access fields with the **dot operator**, and perform a baseline **linear search** using **strcmp**. This pattern scales from tiny demos to real datasets and can later be upgraded to **sorted arrays** or a **hash table** without changing callers.

## Minimal scaffold
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>   // strcmp

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[] = {
        { "Brian", "+1-617-495-1000" },
        { "David", "+1-617-495-1000" },
        { "Emma",  "+1-617-495-1000" }
    };
    int n = sizeof(people) / sizeof(people[0]);

    string target = "Emma";
    for (int i = 0; i < n; i++)
    {
        if (strcmp(people[i].name, target) == 0)   // **linear search** with **strcmp**
        {
            printf("%s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

### Notes
- **Array of structs (AoS)** gives **contiguous** memory; `people[i]` is a full **record** (`name`, `number`).  
- Always compare **C-strings** with **strcmp**, not `==` (which compares pointers).  
- Complexity: **O(n)** time, **O(1)** extra space. For faster lookups, keep the array **sorted** and use **binary search** (**Θ(log n)**), or switch to a **hash table** (**amortized O(1)**).

## Common pitfalls
- Mixing **parallel arrays** (`names[i]`, `numbers[i]`) instead of one **struct** → invites index bugs.
- Forgetting preconditions (claiming **O(log n)** without **sorted** data).  
- Returning a pointer to a **stack-allocated** buffer when building numbers dynamically (prefer **string** from CS50 or heap-allocate and free).

## Related Concepts
- [[Structs in C — Typedef, Fields, and Dot Access]] – the underlying type design
- [[Data Structures — Why They Matter]] – container choice drives complexity
- [[Binary search]] – upgrade path when data can be kept **sorted**
- [[Hash table]] – constant-time average lookups by key
- [[Asymptotic Notation · O, Ω, Θ]] – how to talk about the costs precisely

## See Also
- [CS50x 2025 · Week 3: Algorithms](https://cs50.harvard.edu/x/2025/weeks/3/)
- [C strings and strcmp — cppreference](https://en.cppreference.com/w/c/string/byte/strcmp)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

## Terms
[[Array of structs]], [[Record]], [[Field]], [[Dot operator]], [[Linear search]], [[strcmp]], [[Sorted array]], [[Binary search]], [[Hash table]]
