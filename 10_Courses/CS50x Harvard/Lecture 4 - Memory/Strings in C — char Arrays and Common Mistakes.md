---
title: "Strings in C — char Arrays and Common Mistakes"  
lang_tags: "#lang/c"                                    
type_tags: "#type/lecture"                                   
course_tags: "#course/cs50x/intoduction_to_CS"                                    
lecture_tags: "#lecture/week_4_Memory"                                  
tool_tags: ""                                            
atom_idx: 09                                        
status: "done"                                            
difficulty: "medium"                                        
date: "2025-08-20"                           
timecode: "00:37:24"                                       
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                            
review_next: "2025-09-20"                                    
---

![[Screenshot 2025-08-20 at 19.49.31.png]]
![[Screenshot 2025-08-20 at 19.48.50.png]]

---

## Summary
In **C**, there is no built-in `string` type like in Python or JavaScript. A **string** is simply an **array of characters (`char[]`)** stored in **contiguous memory**, ending with a **null terminator** (`\0`). Trying to declare a `string` without including CS50's custom header file will result in a compiler error.

## Very simple

> A “string” in C is just a list of characters, stored one after another, ending with a special “stop” character: `\0`.

## Key Points
- No native `string` type in C. You must use `char` arrays.
- Example:
  ```c
  char s[] = "HI!";
  ```
  is equivalent to:
  ```c
  char s[] = { 'H', 'I', '!', '\0' };
  ```

- If you write:
  ```c
  string s = "HI!";
  ```
  you’ll get an error **unless** `string` is defined — e.g., by including `#include <cs50.h>` which defines:
  ```c
  typedef char *string;
  ```

- A **string** is a pointer to the first char in a `char[]`.

## Memory layout

| Address  | Value |
|----------|-------|
| `0x123`  | `'H'` |
| `0x124`  | `'I'` |
| `0x125`  | `'!'` |
| `0x126`  | `\0` |

Characters are **contiguous** in memory.

## Why It Matters
- Understanding how strings are stored helps avoid **memory bugs**, **off-by-one errors**, and **buffer overflows**.
- Helps clarify why some functions (like `strlen`, `printf("%s")`) work only if the string ends with `\0`.
- Explains why `string` works in CS50 IDE but not standard C.

## Questions
- ❓ What happens if I forget the `\0`?
- ❓ Can I modify a string literal directly?
- ❓ Why does CS50 use `string` at all?

## Related Concepts
- [[Pointers in C — Address-of (&) and Dereference (*)]] – strings are pointers to arrays of chars.
- [[Memory Layout of a Program]] – string characters are stored in stack or static data segment.
- [[Hexadecimal Memory Grid & 0x Convention]] – each character has an address.
- [[Arrays and Pointers]] – strings are arrays and decay to pointers.
- [[Null Terminator (\0)]] – marks the end of a string in C.
- [[Functions That Operate on Strings in C]] – like `strlen`, `strcmp`, etc.

## See also
- [What is a string in C? – StackOverflow](https://stackoverflow.com/questions/1127986/what-is-the-difference-between-char-s-and-char-s-in-c)
- [C Strings – GeeksforGeeks](https://www.geeksforgeeks.org/strings-in-c-2/)
- [CS50 Manual — string](https://manual.cs50.io/3/string)

## Terms
[[string]], [[char array]], [[null terminator]], [[\0]], [[pointer]], [[typedef]], [[CS50.h]]
