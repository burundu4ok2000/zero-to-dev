---
title: "Does C Have Strings · CS50 String Type Explained"  
lang_tags: "#lang/c"                                    
type_tags: "#type/lecture"                                     
course_tags: "#course/cs50x/intoduction_to_CS"                                  
lecture_tags: "#lecture/week_4_Memory"                                  
tool_tags: ""                                          
atom_idx: 13                                          
status: "done"                                              
difficulty: "easy"                                          
date: "2025-08-22"                            
timecode: "00:52:00"                                          
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                            
review_next: "2025-09-22"                                     
---

## Summary

C **does not have** a built-in `string` type like Python or Java.  
In CS50, `string` is just a **custom alias** for `char *` to simplify learning.

---

## Very simple

> In C, a string is just a **pointer to the first character** in an array of chars, ending with `\0`.

---

## Key Points

- No `string` type in standard C.
- Strings are handled using **`char[]` or `char *`** with a null terminator.
- CS50 defines:
  ```c
  typedef char *string;
  ```
- This makes code more readable for beginners:
  ```c
  string name = get_string("Name: ");
  ```

---

## C-style strings
```c
char *s = "hello";    // points to a string literal
char t[] = {'h','e','l','l','o','\0'}; // manual array
```

- `printf("%s", s);` prints until `\0` is found.
- You need functions like `strlen`, `strcpy`, `strcmp` to manipulate strings.

---

## CS50 Simplified
CS50 provides a `string` type via a typedef:

```c
typedef char *string;
```

So this works:
```c
string name = get_string("Name: ");
```

But it's still just `char *` under the hood.

---

## Comparison

| Language    | Native `string`? | How it works                            |
|-------------|------------------|------------------------------------------|
| C           | ❌               | `char *` + null terminator               |
| Python      | ✅               | `str` object, unicode-aware              |
| Java        | ✅               | `String` object, immutable, UTF-16       |
| JavaScript  | ✅               | `String` primitive + object methods      |
| C#          | ✅               | `string` alias for `System.String`       |

---

## Why It Matters

- Understanding C-strings helps you avoid:
  - Memory bugs
  - Buffer overflows
  - Undefined behavior
- And it helps you appreciate how **high-level languages** abstract strings.

---

## Related Concepts

- [[Pointers in C — Address-of (&) and Dereference (*)]]
- [[%s Format Specifier and Null Terminator]]
- [[How Strings Are Stored · Low vs High Level]]
- [[ASCII and Character Encodings]]
- [[Dynamic Memory Allocation in C]]
- [[Memory Layout of a Program]]

## See Also

- [CS50 Docs: string](https://cs50.readthedocs.io/libraries/cs50/c/#string)
- [Strings in C – GeeksforGeeks](https://www.geeksforgeeks.org/strings-in-c/)
- [C Reference: <string.h>](https://en.cppreference.com/w/c/string)

## Terms

[[string]], [[char array]], [[char *]], [[null terminator]], [[string literal]], [[typedef]]
