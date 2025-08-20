---
title: "Hex vs Decimal — Why Hex is Used"  
lang_tags: "#lang/c"                                      
type_tags: "#type/lecture"                                      
course_tags: "#course/cs50x/intoduction_to_CS"                                      
lecture_tags: "#lecture/week_4_Memory"                                    
tool_tags: ""                                          
atom_idx: 02                                        
status: "done"                                          
difficulty: "easy"                                       
date: "2025-08-20"                         
timecode: "00:11:00"                                      
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                            
review_next: "2025-09-20"                                  
---

![[Screenshot 2025-08-20 at 15.56.54.png]]

---

## Summary
**Hex values** are used for **readability** and **convenience**, not for **performance**. CPUs always process **binary**, not hexadecimal.

## Very simple

> Hex is like shorthand. It makes long binary numbers shorter and easier to read — but the computer still uses **1s and 0s** underneath.

## Key Points
- **CPUs work in binary**, not hex or decimal.
- Hex is a **human-friendly format** for large binary values.
- Easier to convert between **hex ↔ binary** (1 hex = 4 bits).
- Used heavily in memory representation, debugging, color codes.

## Details
- Hex is **never faster** than decimal — it’s just a notation.
- You write `0xFF`, compiler turns it into binary → `11111111`.
- Helpful for humans: memory addresses, opcodes, bitmasks, etc.

## Examples
```c
int x = 255;       // same as 0xFF
int y = 0b11111111; // binary literal (same value)
```

## **Why It Matters**
- Makes **debugging** easier: hex dumps, memory editors.
- Makes **patterns in memory** more obvious.
- Converts easily to **bitwise operations** and **registers**.

## Questions
- ❓ Are there cases where hex is required, not optional?
- ❓ Is octal still used, or replaced fully by hex?

## Related Concepts
- [[Hexadecimal Notation]] – foundational format discussed before this note.
- [[Pointers in C]] – printed in hex (e.g., `0x7ffee3...`).
- [[Memory Layout of a Program]] – memory offsets in hex.
- [[Binary Representation]] – underlying layer beneath hex.
- [[Bitmasking in C]] – often expressed in hex form.
- [[Debugging with gdb]] – memory shown in hex.

## See also
- [Why programmers use hexadecimal](https://stackoverflow.com/questions/114857/why-are-hexadecimal-numbers-used)
- [Base numbering systems](https://www.tutorialspoint.com/computer_logical_organization/number_systems.htm)
- [[Lecture 4 — Memory]]

## Terms
[[hexadecimal]], [[decimal]], [[binary]], [[compiler]], [[debugger]], [[bitmask]], [[opcode]], [[CPU]]
