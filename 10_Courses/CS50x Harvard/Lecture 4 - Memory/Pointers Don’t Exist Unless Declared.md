---
title: "Pointers Don’t Exist Unless Declared"  
lang_tags: "#lang/c"                                    
type_tags: "#type/lecture"                                   
course_tags: "#course/cs50x/intoduction_to_CS"                                    
lecture_tags: "#lecture/week_4_Memory"                                  
tool_tags: ""                                            
atom_idx: 08                                        
status: "done"                                            
difficulty: "easy"                                        
date: "2025-08-20"                           
timecode: "00:30:19"                                       
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                            
review_next: "2025-09-20"                                    
---

![[Screenshot 2025-08-20 at 19.34.29.png]]

---

## Summary
**Pointers are not automatic.** Unless you explicitly declare a pointer, it will not exist in your program. The machine works with memory addresses under the hood, but it won’t expose them to you unless you request them using the `&` operator and a pointer variable.

## Very simple

> A pointer is like a note saying “Hey, that value lives at this address.” But if you don’t make that note, it doesn’t appear out of thin air — **you have to ask for it.**

## Key Points
- When you declare a variable like `int n = 50;`, the compiler stores `50` in memory (e.g. `0x123`).
- That memory address is used internally by the machine.
- If you don’t declare a pointer like `int *p = &n;`, there is **no way for your code to access that address directly**.
- The address exists, but **you don't have a variable that stores it.**

## Memory Perspective

| Action                   | Memory Result                                       |
|--------------------------|-----------------------------------------------------|
| `int n = 50;`            | Value `50` saved at some address (e.g. `0x123`)     |
| No pointer declared      | No variable holds that address                     |
| `int *p = &n;`           | Pointer `p` stores address `0x123`                 |

---

## Example

```c
int n = 50;     // Stored in memory
// No pointer = can't print its address

int *p = &n;    // Now we can use p to get the address and value
```

---

## Why It Matters
- Helps understand what **actually exists in memory**.
- Prevents assumption that **“every variable has a built-in pointer”**.
- Reinforces the idea that **pointers are just another kind of variable**.

---

## Related Concepts
- [[Pointer Declaration and %p — Printing Addresses]] – shows what happens when you do declare a pointer.
- [[Pointers in C — Address-of (&) and Dereference (*)]] – core operators used to create and follow pointers.
- [[Memory Layout of a Program]] – where both variables and pointers live.
- [[Hexadecimal Memory Grid & 0x Convention]] – visualizes how addresses are organized.
- [[Variables in C]] – shows what gets memory by default.
- [[Dynamic Memory Allocation in C]] – where pointers are used intentionally to manage memory.

---

## See also
- [CS50 Lecture 4 — Memory (2025)](https://cs50.harvard.edu/x/2025/weeks/4/)
- [Are pointers automatically created in C? – StackOverflow](https://stackoverflow.com/questions/32780718/are-pointers-automatically-created-in-c)
- [How memory works in compiled C code](https://www.cs.cornell.edu/courses/cs3110/2021sp/textbook/memory/pointers.html)

---

## Terms
[[pointer]], [[memory address]], [[& operator]], [[declaration]], [[variable]], [[implicit behavior]], [[heap]], [[stack]]
