---
title: "How Strings Are Stored · Low vs High Level"  
lang_tags: "#lang/c, #lang/python, #lang/java"                                      
type_tags: "#type/lecture"                                       
course_tags: "#course/cs50x/intoduction_to_CS"                                   
lecture_tags: "#lecture/week_4_Memory"                                    
tool_tags: ""                                            
atom_idx: 11                                           
status: "done"                                                
difficulty: "medium"                                            
date: "2025-08-22"                              
timecode: "00:36:40"                                           
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                              
review_next: "2025-09-22"                                       
---

![[Screenshot 2025-08-22 at 16.32.01.png]]
![[Screenshot 2025-08-22 at 16.42.51.png]]

---

## Summary
Strings are stored differently in **low-level languages** like C and **high-level languages** like Python or Java. C treats strings as **char arrays** ending with a **null terminator** (`\0`), while high-level languages use objects with metadata.

## Very simple

> A string in C is like a line of beads with a special "stop" bead (\0). In Python or Java, it's more like a labeled box that knows how many beads it holds and what type they are.

## Key Points
- In C, a string is a sequence of **char**s ending with `\0`.
- `char *s = "HI!";` points to the first character in a memory array.
- `printf("%s", s);` keeps printing until it finds `\0`.
- High-level languages manage strings as **objects** with known **lengths** and **encodings**.
- Strings in Java and Python are **immutable**, stored on the **heap**, and often Unicode-aware.

## Details
- C does **not** store the length of the string — it relies on the **null terminator** to detect the end.
- `char *s = "HI!";` → stores 'H', 'I', '!', then `\0` in memory.
- In Python: `'HI!'` is an object of type `str`, with internal fields like length and encoding.
- In Java: `String s = "HI!";` creates a string object with similar internal metadata.
- C is faster but riskier — buffer overflows, manual management.
- High-level languages are safer — prevent errors, but abstract away memory layout.

## Examples

### C
```c
char *s = "HI!";
printf("%s", s);  // prints HI!
```

### Python
```python
s = "HI!"
print(s)  # prints HI!
```

### Java
```java
String s = "HI!";
System.out.println(s); // prints HI!
```

## **Why It Matters**
- String handling is one of the **most common** tasks in any language.
- In C, understanding how strings work prevents **memory bugs**.
- In high-level languages, it helps to know the **abstractions** hiding under the hood.

## Questions
- ❓ What happens if we forget `\0` in a C string?
- ❓ How do encodings (like UTF-8) affect memory layout in Python/Java?

## Related Concepts
- [[Pointers in C — Address-of (&) and Dereference (*)]] – strings in C are accessed by pointers.
- [[Why 1 Byte = 8 Bits (History & Logic)]] – strings rely on byte-addressable memory.
- [[%s Format Specifier and Null Terminator]] – used to print C strings.
- [[Memory Layout of a Program]] – where strings are stored in RAM.
- [[Dynamic Memory Allocation in C]] – for building strings at runtime.
- [[Type Declaration Syntax in C]] – explains `char *`.
- [[ASCII and Character Encodings]] – characters are stored as bytes.

## See also
- [Strings in C – CS50 Reference](https://cs50.harvard.edu/x/2025/notes/4/)
- [How Strings Work in C (GFG)](https://www.geeksforgeeks.org/strings-in-c/)
- [Python String Internals](https://realpython.com/python-strings/)

## Terms
[[string]], [[char array]], [[null terminator]], [[char *]], [[immutable object]], [[heap memory]], [[pointer]], [[string object]]
