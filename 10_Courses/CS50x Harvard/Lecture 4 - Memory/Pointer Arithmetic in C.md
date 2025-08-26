---
title: Pointer Arithmetic in C
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
atom_idx: 19
status: done
difficulty: medium
date: 2025-08-22
timecode: 00:55:00
source: https://cs50.harvard.edu/x/2025/weeks/4/
review_next: 2025-09-22
---

![[Screenshot 2025-08-22 at 17.31.05.png]]
![[Screenshot 2025-08-22 at 17.33.03.png]]

---

## Summary

**Pointer arithmetic** in C allows you to move through memory by manipulating addresses. Because pointers store memory addresses, and memory is just a long array of bytes, you can perform arithmetic operations like addition and subtraction on them.

## Example Code

```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
```

**Output:**
```text
H
I
!
```

## Key Concepts

- `*s` dereferences the pointer → gives the first character (`H`)
- `*(s + 1)` → moves pointer 1 byte forward → gets `I`
- `*(s + 2)` → gets `!`
- Pointer arithmetic respects the **data type**. For `char *`, `s + 1` means move 1 byte ahead. For `int *`, it would move 4 bytes ahead on 32-bit systems.

## Why It Works

Pointers are just numbers under the hood — memory addresses. C lets you do math on these numbers because it gives you low-level control.

```c
int *p;
p + 1; // advances by sizeof(int) bytes
```

## Analogy

Think of memory as a street with houses (bytes), and a pointer as a street address. Pointer arithmetic lets you go to the "next house" down the street.

## Related Concepts

- [[Pointers in C — Address-of (&) and Dereference (*)]]
- [[How Strings Are Stored · Low vs High Level]]
- [[Memory Layout of a Program]]
- [[Null Terminator]]
- [[char * and Strings in C]]

## See also

- [Pointer Arithmetic – GeeksforGeeks](https://www.geeksforgeeks.org/pointer-arithmetic-in-c-with-examples/)
- [CS50 Notes on Pointers](https://cs50.harvard.edu/x/2025/notes/4/)

## Terms

[[pointer]], [[address]], [[dereference]], [[pointer arithmetic]], [[char *]], [[memory offset]], [[indexing]]
