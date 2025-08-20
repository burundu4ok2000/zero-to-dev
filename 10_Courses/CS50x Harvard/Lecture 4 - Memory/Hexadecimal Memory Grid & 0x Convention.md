---
title: "Hexadecimal Memory Grid & 0x Convention"  
lang_tags: "#lang/c"                                        
type_tags: "#type/lecture"                                      
course_tags: "#course/cs50x/intoduction_to_CS"                                        
lecture_tags: "#lecture/week_4_Memory"                                      
tool_tags: ""                                            
atom_idx: 05                                          
status: "done"                                             
difficulty: "easy"                                           
date: "2025-08-20"                             
timecode: "00:15:24"                                          
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                             
review_next: "2025-09-20"                                      
---

![[Screenshot 2025-08-20 at 18.38.13.png]]

---

## Summary
We use the `0x` prefix to clearly mark **hexadecimal values** — especially in **memory addresses**. A memory grid like this shows how hex addresses help us visualize and organize memory.

## Very simple

> Think of a big drawer with lots of slots. Instead of numbering the drawers as 1, 2, 3… we number them as `0x0`, `0x1`, `0x2`… This helps when working with computers that use binary behind the scenes, but need human-readable labels.

## Key Points
- `0x` is the **standard prefix** for hex numbers in C and many other languages.
- `0x10` = 16 in decimal, `0xFF` = 255
- Each **memory cell** (byte) is given an address — in **hex**.
- Grid layout helps visualize memory like a **2D hex map**: like rows/columns.

## Details
- By convention:
  - Start with `0x`
  - Use **lowercase x**, like: `0xA3`, not `0XA3` or `0XA3h`
- In C:
  ```c
  int x = 0x1F; // assigns 31
  ```
- Tools like `gdb`, `hexdump`, `objdump`, memory editors — all use this format.
- Each box in the grid often represents **1 byte** of memory.

## Examples
```bash
$ hexdump -C file.bin

00000000  48 65 6c 6c 6f 20 77 6f  72 6c 64 0a              |Hello world.|
```

## **Why It Matters**
- Helps you **track memory**, **debug memory leaks**, and work with **raw memory layout**.
- Essential when working close to the hardware or in C.
- Also useful when viewing binary files, working with embedded systems, or OS internals.

## Questions
- ❓ Why not just use decimal addresses?
- ❓ Is the `0x` prefix standard across all programming languages?

## Related Concepts
- [[Hexadecimal Notation]] – introduces base-16 and digits `0–F`.
- [[Counting in Hex — FF Equals 255]] – explains values in terms of byte limits.
- [[Memory Layout of a Program]] – this visual is a tool for understanding layout.
- [[Pointers in C]] – they point to addresses like `0x7ffe...`
- [[Bitmasking in C]] – often involves hex constants like `0xFF` or `0x0F`.
- [[How printf works]] – `%p` shows memory addresses in hex with `0x` prefix.
- [[Debugging with gdb]] – uses hex for memory and breakpoints.
- [[Endianness]] – affects how multi-byte values appear in grids like this.

## See also
- [Hexadecimal Prefixes Explained](https://stackoverflow.com/questions/1096128/why-do-numbers-have-0x-in-them)
- [Memory addressing – Wikipedia](https://en.wikipedia.org/wiki/Memory_address)
- [How memory is shown in gdb](https://sourceware.org/gdb/current/onlinedocs/gdb/Memory.html)

## Terms
[[hexadecimal]], [[memory address]], [[0x prefix]], [[pointer]], [[grid layout]], [[hexdump]], [[byte]], [[debugger]]
