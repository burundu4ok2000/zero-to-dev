---
title: Single vs Double Quotes in C
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: ""
atom_idx: 13
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

## **One-liner

> In C, **'A'** is a **char** (one byte), but **"A"** is a **char array** (two bytes: the character plus the **null terminator**).

## The Big Idea 
- **Single quotes** create a **character literal** → a single **char** value.
- **Double quotes** create a **string literal** → a **char[]** with an automatic **'\0'** at the end.
- This affects **memory layout**, **type**, **`sizeof` vs `strlen`**, and which **`printf`** specifier you should use (**%c** vs **%s**).

## Key Characteristics 
- **Type**: 'A' → **char**; "A" → **char[]** (array of **char**).
- **Size**: 'A' → **1** byte; "A" → **2** bytes (**'A'** + **'\0'**).
- **Sentinel**: String literals always end with **'\0'** (the **sentinel**/**null terminator**).
- **Immutability note**: String literals have **static storage** and are **read-only**; use **`const char *`** when pointing at them.
- **APIs**: Functions like **`strlen`**, **`strcpy`**, **`printf("%s")`** rely on the **'\0'** to know where the string ends.
- **Gotcha**: **Multi-character literals** like `'AB'` exist in C but produce an **int** with **implementation-defined** value—avoid them in real code.

## Examples 

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char c  = 'A';       // one byte, no terminator
    char s[] = "A";      // two bytes: 'A' and '\0'

    printf("c   = '%c'\n", c);         // use %c for a single char
    printf("s   = \"%s\"\n", s);       // use %s for a string
    printf("len = %zu, size = %zu\n", strlen(s), sizeof(s)); // 1 vs 2

    const char *p = "HI!";              // pointer to string literal (read-only)
    printf("p as %%s: %s\n", p);
}
```

**Memory layout of "HI!"**

| Index | Byte | Hex  | Comment         |
|------:|:----:|:----:|-----------------|
| 0     | H    | 0x48 | visible char    |
| 1     | I    | 0x49 | visible char    |
| 2     | !    | 0x21 | visible char    |
| 3     | '\0'| 0x00 | **sentinel**     |

`sizeof("HI!")` ⇒ **4** (includes **'\0'**); `strlen("HI!")` ⇒ **3**.

**Manual construction (don’t forget the terminator):**
```c
char name[5] = {'J','o','e','y','\0'};  // OK
char bad[3]  = {'O','n','e'};            // NO terminator → unsafe with %s/strlen
```

## Related Concepts
- [[Char Type in C]] – pairs with this note: what's a **char** exactly and how it’s stored
- [[Strings in C]] – how **char[]** strings work, common ops
- [[Null Terminator]] – the **'\0'** sentinel in detail
- [[sizeof vs strlen in C]] – bytes in memory vs visible length
- [[printf format specifiers]] – when to use **%c** vs **%s**

## See Also
- [CS50x 2025 – Week 2: Arrays & Strings](https://cs50.harvard.edu/x/2025/weeks/2/)
- [cppreference – String literals](https://en.cppreference.com/w/c/language/string_literal)
- [C11 draft (n1570) – §6.4.5 String literals](https://port70.net/~nsz/c/c11/n1570.html#6.4.5)

## Terms
[[character literal]], [[string literal (C)]], [[char]], [[char array]], [[null terminator]], [[sentinel value]], [[pointer]], [[array]], [[printf]], [[strlen]], [[sizeof]], [[implementation-defined behavior]]
