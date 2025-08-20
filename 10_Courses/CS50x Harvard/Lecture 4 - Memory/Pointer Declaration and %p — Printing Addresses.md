---
title: "Pointer Declaration and %p — Printing Addresses"  
lang_tags: "#lang/c"                                      
type_tags: "#type/lecture"                                    
course_tags: "#course/cs50x/intoduction_to_CS"                                      
lecture_tags: "#lecture/week_4_Memory"                                   
tool_tags: ""                                           
atom_idx: 07                                        
status: "done"                                            
difficulty: "easy"                                        
date: "2025-08-20"                           
timecode: "00:22:57"                                        
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                            
review_next: "2025-09-20"                                    
---

![[Pasted image 20250820191743.png]]

---

## Summary
This example introduces how to **declare a pointer** and use **`%p` in printf** to print the **memory address** of a variable. It also shows how **reading pointer syntax right-to-left** gives deeper insight.

## Code Example
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
}
```

## Very simple

> The line `int *p = &n;` means: “p is a pointer to an int, and it stores the address of n.”

## Key Concepts
- `int *p` means “pointer to int”.
- `*` binds to the variable **`p`**, not to the type `int`.
- Reading **right-to-left**: "`p` is a pointer to `int`".
- `&n` gives the **address of variable `n`**.
- `%p` in `printf` prints a **memory address**, usually in **hex**.

## Details
- `*` in the declaration doesn’t mean dereference. It **defines** a pointer.
- You can have:
  ```c
  int* p;      // common in CS50 style
  int *p;      // widely preferred
  int* p, q;   // ❌ q is NOT a pointer! Only `p` is
  ```
- Safe rule: attach `*` to the variable, not the type.

## Output 
```c
0x7ffef3c2925c
```

## For example (hex, dec and bin)

```c
0x7ffef3c2925c      // hexadecimal
140732159660124     // decimal
0b011111111111111011110011110000101001001001011100   // binary
```

## **Why It Matters**
- This is the **starting point** for working with memory addresses.
- You learn how to **store** and **print** memory locations.
- `%p` gives visibility into how variables live in **RAM**.

## Questions
- ❓ Why is it better to read `int *p` right-to-left?
- ❓ What if I try to print `*p` instead of `p`?

## Related Concepts
- [[Pointers in C — Address-of (&) and Dereference (*)]] – this example builds directly on those concepts.
- [[Hexadecimal Memory Grid & 0x Convention]] – `%p` prints addresses like `0x...`.
- [[Memory Layout of a Program]] – addresses live in stack, heap, etc.
- [[Call Stack Visualization]] – helps show where `n` and `p` are stored.
- [[Type Declaration Syntax in C]] – how `*` is used in declarations.
- [[Printf Formatting in C]] – `%p` is the format for addresses.
- [[Variables in C]] – how and where variables are stored.

## See also
- [Pointer declaration in C – StackOverflow](https://stackoverflow.com/questions/890782/pointer-declaration-in-c)
- [C printf format specifiers – cppreference](https://en.cppreference.com/w/c/io/fprintf)
- [Why read C declarations right to left?](https://stackoverflow.com/questions/3683932/c-pointer-declaration-read-right-to-left)

## Terms
[[pointer]], [[* operator]], [[address-of]], [[& operator]], [[printf]], [[%p]], [[memory address]], [[right-to-left rule]]
