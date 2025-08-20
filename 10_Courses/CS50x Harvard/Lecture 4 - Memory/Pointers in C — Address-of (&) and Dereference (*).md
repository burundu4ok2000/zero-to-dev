---
title: "Pointers in C — Address-of (&) and Dereference (*)"  
lang_tags: "#lang/c"                                        
type_tags: "#type/lecture"                                      
course_tags: "#course/cs50x/intoduction_to_CS"                                        
lecture_tags: "#lecture/week_4_Memory"                                    
tool_tags: ""                                             
atom_idx: 06                                          
status: "done"                                              
difficulty: "medium"                                          
date: "2025-08-20"                             
timecode: "00:19:21"                                          
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                             
review_next: "2025-09-20"                                      
---

![[Screenshot 2025-08-20 at 18.47.19.png]]

---

## Summary
In C, **pointers** are variables that store **memory addresses**. We use two special operators: **`&`** (address-of) to get a variable’s location, and **`*`** (dereference) to access the value at that address.

## Very simple

> A pointer is like a note with directions. `&` tells you **where** something lives, `*` says **go to that place and get what's inside**.

## Key Points
- `&x` means “the address of variable `x`”.
- `*p` means “go to the address stored in pointer `p` and get the value there”.
- Declaring a pointer: `int *ptr;` → `ptr` stores an address of an int.
- `*` in declaration vs usage:
  - `int *p;` → pointer to int
  - `*p = 5;` → store 5 in the place `p` points to

## Details
```c
int x = 42;
int *p = &x;    // store the address of x
printf("%p", p);   // prints something like 0x7ffee4a38c

printf("%d", *p);  // prints 42 (dereference)
*p = 99;           // changes x to 99
```

- Pointers are used to **share memory**, pass **references to functions**, and work with **arrays** and **dynamic memory**.

## Examples
```c
int a = 10;
int *ptr = &a;   // & gives address
*ptr = 20;       // * updates value at address
printf("%d", a); // prints 20
```

## **Why It Matters**
- Pointers are fundamental for **memory control**, **dynamic allocation**, and **low-level programming**.
- Without pointers, you can’t do **malloc**, **arrays-as-arguments**, or implement **data structures**.
- Core to understanding **C**, **memory leaks**, and **segmentation faults**.

## Questions
- ❓ Why is it `*ptr` for dereference, not another symbol?
- ❓ Can pointers be NULL? What happens if I dereference NULL?

## Related Concepts
- [[Hexadecimal Memory Grid & 0x Convention]] – pointers store addresses like `0x1234`.
- [[Memory Layout of a Program]] – shows where pointers point: stack, heap, etc.
- [[Dynamic Memory Allocation in C]] – uses pointers and `malloc`.
- [[Segmentation Faults]] – often caused by bad pointer access.
- [[Arrays and Pointers]] – closely linked; arrays decay to pointers.
- [[Pass by Reference in C]] – achieved via pointers.
- [[Call Stack Visualization]] – pointer addresses are part of stack frames.
- [[Type Declaration Syntax in C]] – `*` is part of type signature.

## See also
- [Pointers in C – CS50 Reference](https://cs50.harvard.edu/x/2025/notes/4/)
- [C Pointers – GeeksforGeeks](https://www.geeksforgeeks.org/pointers-in-c/)
- [Pointers (cplusplus.com)](https://cplusplus.com/doc/tutorial/pointers/)

## Terms
[[pointer]], [[memory address]], [[dereference]], [[address-of]], [[* operator]], [[& operator]], [[null pointer]], [[heap memory]]
