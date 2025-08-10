---
title: C Type Sizes and Memory
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
atom_idx: 3
status: done
difficulty: easy
date: 2025-08-10
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

![[Screenshot 2025-07-22 at 11.54.49.png]]

---

## Summary

Each data type in C has a specific memory footprint, determined by the system architecture. Understanding these sizes is key to effective memory management.

## Key Points

- Use `sizeof(type)` to determine the memory size in **bytes** of any C data type.
- Most sizes are **platform-dependent**, though on CS50’s 64-bit Linux setup:
  - `bool` and `char`: 1 byte
  - `int`: 4 bytes
  - `long`: 8 bytes
  - `float`: 4 bytes (~7 decimal digits)
  - `double`: 8 bytes (~15–16 decimal digits)
  - `char *`: 8 bytes (pointer to string)

## Details

C uses **static typing** and low-level access to memory. The `sizeof(...)` operator tells how much memory (in bytes) a type or variable occupies. This is critical for systems programming, manual memory allocation, and pointer arithmetic.

The `string` type in CS50 is actually a `char *`, i.e., a pointer to the first character of a text in memory. The pointer itself takes up 8 bytes (on 64-bit), and the text it points to takes 1 byte per character, ending with `'\0'`.

## Examples

```c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    printf("bool:   %zu\n", sizeof(bool));
    printf("char:   %zu\n", sizeof(char));
    printf("int:    %zu\n", sizeof(int));
    printf("long:   %zu\n", sizeof(long));
    printf("float:  %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    printf("char *: %zu\n", sizeof(char *));
}
````

|**Type**|**sizeof(…)**|**Notes**|
|---|---|---|
|bool|1 byte|Requires <stdbool.h>, stores 0 or 1|
|char|1 byte|One ASCII character|
|int|4 bytes|Integer: ~ −2.1B … 2.1B|
|long|8 bytes|Larger integer, platform-dependent|
|float|4 bytes|~7 decimal digits (IEEE-754 single precision)|
|double|8 bytes|~15–16 digits (IEEE-754 double precision)|
|char *|8 bytes|Pointer to first character in a string|

## **Why It Matters**

  

Knowing the size of types allows:

- Writing memory-efficient programs.
    
- Correctly allocating dynamic memory.
    
- Performing accurate pointer arithmetic.
    
- Understanding what’s happening under the hood in system-level code.
    

  

## **Questions**

- ❓ How do type sizes differ across platforms (e.g., ARM vs x86_64)?
    
- ❓ What determines whether a type is aligned on 4-byte or 8-byte boundaries?
    

  

## **Related Concepts**

- [[Pointers in C]] – \smth\ with type sizes when passing or dereferencing memory.
    
- [[Memory Addressing Basics]] – \smth\ with understanding layout of different types.
    
- [[Pass by Value vs Pass by Reference in C]] – memory footprint matters in argument passing.
    
- [[Data Alignment and Padding in C]] – size isn’t always everything; layout matters.
    
- [[CS50 String Explained]] – CS50’s string as char * builds on type sizes.
    

  

## **See also**

- [C Data Types (GeeksForGeeks)](https://www.geeksforgeeks.org/c-data-types/)
    
- [CS50 Lecture 2: Arrays and Types](https://cs50.harvard.edu/x/2025/weeks/2/)
    
- [C sizeof Operator (cplusplus.com)](https://cplusplus.com/reference/cstddef/sizeof/)
    
-  [[Char Type in C]]
 

## **Terms**


[[bool]], [[char]], [[int]], [[long]], [[float]], [[double]], [[char *]], [[string]], [[sizeof]], [[pointer]], [[memory]]
