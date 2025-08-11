---
title: Strings and Arrays in C — Hidden Null Terminator
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: ""
atom_idx: 11
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

---



![[Screenshot 2025-07-23 at 16.13.55.png]]

---

## Summary
**Strings** in C are **char arrays** that end with a hidden **null terminator** (`'\0'`). The **%s** format in **printf** reads bytes until it hits that terminator, which is why `"HI!"` actually occupies 4 bytes and `"BYE!"` 5.

## Key Points
- A **string** is a **char array** plus a **sentinel** byte `\0` at the end.
- **%s** stops printing at the first `\0`; passing a non‑terminated buffer is unsafe.
- **strlen** counts visible chars; **sizeof** (on the array) includes the `\0`.
- Always allocate **+1 byte** for the terminator when building buffers.
- Clobbering or missing `\0` leads to **UB** (undefined behavior): garbage output, over‑reads, or crashes.

## Details
### What the board is showing
Two variables:
```c
string s = "HI!";
string t = "BYE!";
printf("%s\n", s);
printf("%s\n", t);
```
Conceptual memory layout (indices per array):
```
Index:   0    1    2    3      0    1    2    3    4
Var:     s                     t
Bytes:   H    I    !   \0      B    Y    E    !    \0
```
That extra “empty” cell is **0x00** — the **null terminator**.

### strlen vs sizeof
```c
char s[] = "HI!";        // 4 bytes: 'H' 'I' '!' '\0'
strlen(s);   // 3
sizeof(s);   // 4
```
`strlen` walks until `\0`. `sizeof` reports the array’s total storage at compile time (for arrays in scope).

## Examples
### Inspect every byte (shows the hidden terminator)
```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[] = "HI!";
    for (size_t i = 0; i < sizeof(s); i++) {
        unsigned char c = (unsigned char)s[i];
        printf("s[%zu] = '%c' (0x%02X)%s\n",
               i, s[i] ? s[i] : '\0', c, s[i] ? "" : "  <-- terminator");
    }
}
```

### Don’t forget +1 when allocating
```c
size_t n = 3;                 // we plan to store "HI!"
char *buf = malloc(n + 1);    // +1 for '\0'
memcpy(buf, "HI!", n);
buf[n] = '\0';               // terminate
```

## **Why It Matters**
C’s **string APIs** (e.g., **printf**, **strcpy**, **strlen**) assume **null‑termination**. Forgetting `\0` turns benign reads into **out‑of‑bounds** traversals and turns prints into data leaks or crashes. Getting this right is foundational for memory safety and later topics like **pointers**, **buffers**, and **file I/O**.

## Questions
- ❓ What happens if there’s a `\0` **inside** the middle of a buffer?
- ❓ Why does `sizeof` on a **pointer** not help you find string length?

## Related Concepts
- [[Char Type in C]] – relates as the atomic storage unit of text
- [[strlen vs sizeof in C]] – contrasts runtime length and compile‑time storage
- [[printf Format Specifiers]] – ties into how **%s** reads until `\0`
- [[Pointer vs Array in C]] – clarifies decays and why `sizeof` changes meaning
- [[Memory Layout of C Arrays]] – zooms out to indexing and contiguity

## See also
- [C string handling (byte strings) — cppreference](https://en.cppreference.com/w/c/string/byte)
- [CS50x 2025 – Week 2: Arrays](https://cs50.harvard.edu/x/2025/weeks/2/)

## Terms
[[string]], [[char array]], [[null terminator]], [[sentinel]], [[printf]], [[%s]], [[strlen]], [[sizeof]], [[ASCII]], [[buffer]], [[undefined behavior]], [[pointer]], [[array]]
