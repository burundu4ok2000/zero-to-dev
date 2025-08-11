---
title: Manual String Length Calculation in C
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: ""
atom_idx: 10
status: in-progress
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

---

![[2025-07-30_16-21-42.png]]

---

## Summary
Manual length counting walks a **string** byte-by-byte until the **null terminator** (`'\0'`) and returns the **index** where it stops.

## Key Points
- C **strings** are **null-terminated**; the `'\0'` byte is a **sentinel** that marks the end.
- A simple **while loop** increments an **index** until it hits `'\0'` → length is the number of bytes visited.
- Time complexity is **O(n)**, same as the library **strlen**.
- Beware of counting the terminator or confusing **sizeof** with **strlen**; they measure different things.

## Details
C represents a string as an **array** of `char` (a **pointer** to its first element once passed to a function). Reading `name[n]` advances through memory one byte at a time. The loop stops when it encounters `'\0'`, which is not a visible character but a terminator. This mirrors how **strlen** works under the hood.

## Examples
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    int n = 0;
    while (name[n] != '\0')   // walk until sentinel
    {
        n++;
    }
    printf("%i\n", n);
}
```

### Visual trace for input `Harry`
| n | name[n] | condition    | action |
|---|---------|--------------|--------|
| 0 | 'H'     | not '\0'    | n = 1  |
| 1 | 'a'     | not '\0'    | n = 2  |
| 2 | 'r'     | not '\0'    | n = 3  |
| 3 | 'r'     | not '\0'    | n = 4  |
| 4 | 'y'     | not '\0'    | n = 5  |
| 5 | '\0'   | loop ends    | print 5 |

## **Why It Matters**
Understanding the **null-terminated** model is foundational for safe C: it explains **buffer overruns**, why **strlen** is **O(n)**, and why mixing up **sizeof(pointer)** with **strlen(string)** leads to bugs.

## Questions
- ❓ Why does `sizeof(name)` inside a function return the size of a **pointer** instead of the string’s length?
- ❓ What happens if `'\0'` is missing (unterminated byte sequence)?

## Related Concepts
- [[Char Type in C]] – pairs with manual length by defining the underlying byte **type**.
- [[C Type Sizes and Memory]] – context for byte sizes and **sizeof**.
- [[Pointers and arrays in C]] – explains why strings **decay** to pointers.
- [[Null-terminated strings]] – dedicated note on the `'\0'` **sentinel**.
- [[strlen vs sizeof in C]] – clarifies the common confusion.

## See also
- [[Lecture 2 - Arrays]]
- [C reference: strlen (cppreference)](https://en.cppreference.com/w/c/string/byte/strlen)
- [man 3 strlen (POSIX)](https://man7.org/linux/man-pages/man3/strlen.3.html)

## Terms
????
