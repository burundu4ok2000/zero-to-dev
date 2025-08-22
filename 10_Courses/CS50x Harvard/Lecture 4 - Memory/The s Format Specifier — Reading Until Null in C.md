---
title: "The %s Format Specifier — Reading Until Null in C"  
lang_tags: "#lang/c"                                      
type_tags: "#type/lecture"                                
course_tags: "#course/cs50x/intoduction_to_CS"            
lecture_tags: "#lecture/week_4_Memory"                    
atom_idx: 10                                      
status: "done"                                            
difficulty: "easy"                                        
date: "2025-08-22"                                           
timecode: "00:38:57"                                      
source: "https://cs50.harvard.edu/x/2025/weeks/4/"        
review_next: "2025-09-20"                              
---

![[Screenshot 2025-08-20 at 19.48.50.png]]

---

## Summary

In C, the **`%s`** format specifier used in `printf()` expects a **pointer to the first character** of a string and prints characters **until it encounters a `\0` null terminator**. This means `%s` relies on the **contiguous memory** layout of strings.

---

## How `%s` Works

- `%s` does **not** print a specific number of bytes.
- Instead, it starts at the **memory address** passed to it (i.e., a pointer to a char) and keeps printing **character by character** until it finds the special **null character `\0`**.
- This only works because strings in C are **null-terminated character arrays**.

---

## Visual Example

```
Memory layout (char[] s = "HI!"):
[0x123]  'H'
[0x124]  'I'
[0x125]  '!'
[0x126]  '\0'
```

Calling `printf("%s", s);` will:
1. Start at address `0x123`
2. Print `'H'`, `'I'`, `'!'`
3. Stop at `\0` (null terminator)

---

## Code Example

```c
#include <stdio.h>

int main(void)
{
    char s[] = "HI!";
    printf("%s\n", s);  // Prints HI!
}
```

> The `%s` format specifier is only safe if the string is **properly null-terminated**. Otherwise, it may read garbage or cause a segmentation fault.

---

## Connection to Pointers

- `%s` expects a **pointer to a char**.
- Arrays in C **decay into pointers** when passed to functions like `printf`.
- You are indirectly passing the **address of the first character** in the string.
- This highlights how **pointers and memory addresses** work in practice, especially with `char *`.

---

## Related Concepts

- [[Pointers in C — Address-of (&) and Dereference (*)]]
- [[Strings in C — char Arrays and Common Mistakes]]
- [[Arrays and Pointers]]
- [[Memory Layout of a Program]]

---

## Questions to Ponder

- ❓ What happens if the string is not null-terminated?
- ❓ Can `%s` be safely used with dynamically allocated strings?
- ❓ Why does `printf()` require null-termination but `fwrite()` does not?

---

## See also

- [C – printf() Reference (cplusplus.com)](https://cplusplus.com/reference/cstdio/printf/)
- [Null-terminated strings – Wikipedia](https://en.wikipedia.org/wiki/Null-terminated_string)
- [CS50 Notes on Strings](https://cs50.harvard.edu/x/2025/notes/4/)

---

## Terms

[[format specifier]], [[%s]], [[null terminator]], [[char array]], [[pointer]], [[contiguous memory]], [[memory address]]
