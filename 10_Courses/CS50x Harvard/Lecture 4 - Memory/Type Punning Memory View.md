---
title: Type Punning Memory View
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: "#tool/clang"
atom_idx: 21
status: done
difficulty: medium
date: 2025-09-13
timecode: ""
source: https://cs50.harvard.edu/x/2025/notes/4/
review_next: 2025-10-13
---

---



![[Screenshot 2025-09-13 at 12.49.49.png]]

---

## Summary
The code uses **type punning**: reinterpreting the same memory as different types.  
Instead of printing the value of a variable, it prints its **raw bytes** as stored in memory.

## Very simple
Imagine writing a number on paper, then putting a colored filter over it. With one filter it looks like a number, with another it looks like strange symbols. Same data, different view.

## Key Points
- **Type punning**: treating the same bytes as another type (e.g., `int` → `unsigned char*`).  
- Used to peek into **memory layout** of variables.  
- Reveals details like **endianness** (byte order).  
- Very powerful but can be dangerous if misused.

## Example

```c
#include <stdio.h>

int main(void) {
    int x = 0x12345678;
    unsigned char *p = (unsigned char *)&x;

    for (int i = 0; i < sizeof(int); i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");
}
```

### Output on little-endian machine:
```
78 56 34 12
```

### Output on big-endian machine:
```
12 34 56 78
```

---

## ASCII Diagram

```
int x = 0x12345678;

Memory (little endian):
+----+----+----+----+
| 78 | 56 | 34 | 12 |
+----+----+----+----+
 p[0] p[1] p[2] p[3]

Memory (big endian):
+----+----+----+----+
| 12 | 34 | 56 | 78 |
+----+----+----+----+
 p[0] p[1] p[2] p[3]
```

---

## Why It Matters
- Helpful for **debugging** binary data.  
- Used in **networking** to check byte order.  
- Needed for **file parsing** and working with low-level data formats.  
- Can cause **undefined behavior** if you go too far.

## Related Concepts
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]]  
- [[Dynamic Memory Allocation (Week 4 — Memory)]]  
- [[C File Pointers — Snippets for fgets, fputs, fprintf, fseek, ftell, feof, ferror]]  
- [[Binary vs Text Files in C]]  
- [[Buffer Overflow — Risks & Mitigations]]  
- [[Hexadecimal & Bytes — C Basics]]  
- [[Endianess — Big vs Little]]  
- [[Pointers in C — Address-of & Dereference]]  

## See Also
- [Type punning in C — Wikipedia](https://en.wikipedia.org/wiki/Type_punning)  
- [Endianness explained](https://developer.ibm.com/articles/au-endianc/)  
- [Modern C: Memory model](https://gustedt.wordpress.com/2010/11/29/the-c11-memory-model-introduction/)  

## Terms
[[Type Punning]], [[Pointer Casting]], [[Endianess]], [[Memory Layout]], [[Byte Order]], [[Raw Bytes]]
