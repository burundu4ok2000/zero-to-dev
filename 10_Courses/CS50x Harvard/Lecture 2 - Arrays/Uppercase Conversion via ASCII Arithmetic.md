---
title: Uppercase Conversion via ASCII Arithmetic
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
atom_idx: 13
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

---

![[2025-07-30_16-49-01.png]]

---

## Summary
Convert lowercase letters to uppercase using **ASCII** arithmetic (subtract a constant **offset** of 32) or with the **standard library** helper `toupper`. Cache **strlen** in the **for-loop** initializer to keep the loop **O(n)**.

## Key Points
- **ASCII case offset** is 32: `'a' - 'A'` → **32**, so `c - 32` maps `'a'→'A'`, `'b'→'B'`, … when `c` is **lowercase**.
- Always do a **bounds check**: only transform when `c >= 'a' && c <= 'z'` to avoid mangling digits/punctuation.
- Cache `n = strlen(s)` once in the **for initializer** to avoid repeated scans (**perf** micro-optimization).
- Printing the transformed char is **non-destructive** — it doesn’t **mutate** the original **string**.
- Prefer `<ctype.h>` **toupper** for readability and **locale-agnostic** behavior over manual math when in doubt.

## Details
Lowercase and uppercase Latin letters are contiguous ranges in **ASCII**, which lets you flip case via simple integer math. Subtracting the fixed **offset** works only when the input is in the lowercase range. To keep things fast and clean, compute the string length once, then index chars by `i`. Using `<ctype.h>`'s `toupper` removes the need to reason about ranges and is the idiomatic C approach.

## Examples
### Manual ASCII arithmetic
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            printf("%c", s[i] - ('a' - 'A'));   // 32
        else
            printf("%c", s[i]);
    }
    printf("\n");
}
```

### Using <ctype.h>
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
        printf("%c", toupper((unsigned char)s[i]));

    printf("\n");
}
```

## **Why It Matters**
Understanding **byte-level** **char** math sharpens your mental model of **strings** and encodings, while `toupper` is the production-ready, portable way. You’ll use these patterns in **parsers**, **tokenizers**, and CLI text processing.

## Questions
- ❓ When should I prefer `toupper` over manual math in code that must handle non-ASCII locales?

## Related Concepts
- [[ASCII Table]] – mapping characters to integer codes underpins case math.
- [[Characters and Strings in C]] – how **char** arrays and **NUL** terminators work.
- [[For Loop Anatomy in C]] – caching **strlen** in the initializer.
- [[<ctype.h> Utilities]] – `toupper`, `tolower`, and friends.
- [[String Immutability vs Mutation in C]] – printing vs in-place edits.

## See also
- [[Lecture 2 - Arrays]]
- [ASCII on Wikipedia](https://en.wikipedia.org/wiki/ASCII)
- [cppreference – <ctype.h> toupper](https://en.cppreference.com/w/c/string/byte/toupper)

## Terms
[[ASCII]], [[char]], [[string]], [[offset]], [[bounds check]], [[for initializer]], [[time complexity]], [[non-destructive]], [[ctype.h]], [[toupper]]
