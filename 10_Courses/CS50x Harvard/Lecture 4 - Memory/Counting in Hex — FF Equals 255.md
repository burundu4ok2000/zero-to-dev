---
title: "Counting in Hex — FF Equals 255"  
lang_tags: "#lang/c"                                        
type_tags: "#type/lecture"                                      
course_tags: "#course/cs50x/intoduction_to_CS"                                        
lecture_tags: "#lecture/week_4_Memory"                                      
tool_tags: ""                                           
atom_idx: 03                                          
status: "done"                                            
difficulty: "easy"                                         
date: "2025-08-20"                           
timecode: "00:12:36"                                        
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                            
review_next: "2025-09-20"                                    
---

![[Screenshot 2025-08-20 at 16.08.29.png]]

---

## Summary
In **hexadecimal**, the number `FF` equals **255 in decimal**. This is the largest value that can be stored in a single byte.

## Very simple

> Imagine you have 2 digits in base-16. The biggest digit is `F`, which means 15. So `F` and `F` → 15×16 + 15 = 255. That’s the biggest number you can make with two hex digits!

## Key Points
- `F` in hex = **15** in decimal.
- `FF` = 15×16 + 15 = **255**
- `255` is the **max value for 8 bits** (aka 1 byte): `11111111`
- Useful when working with **colors**, **ASCII**, **masks**, and **raw memory**.

## Details
- Base-16 means each digit is a power of 16: `F` (15) × 16¹ + `F` (15) × 16⁰ = 255.
- One byte holds values from 0 to 255.
- `FF` = `0b11111111` = `255` = `0xFF`

## Examples
```c
unsigned char max = 0xFF;  // 255
printf("%d", max);         // prints 255
```

## **Why It Matters**
- 255 is everywhere in low-level code: **memory limits, color ranges, masks, chars**.
- Understanding this helps debug byte values and understand overflows.
- Also seen in: **IP addresses**, **RGB colors**, **file formats**, etc.

## Questions
- ❓ What happens if we go beyond 0xFF?
- ❓ Why don’t we use 0–100 instead?

## Related Concepts
- [[Hexadecimal Notation]] – defines the base-16 system used here.
- [[Hex vs Decimal — Why Hex is Used]] – this example builds on that reasoning.
- [[Binary Representation]] – 255 = `11111111` in binary.
- [[Integer Overflow]] – happens when values go over 255 for a byte.
- [[Bitmasking in C]] – `0xFF` used as mask to extract 8 bits.
- [[Unsigned Integers]] – 255 is max for unsigned 8-bit int.
- [[Color Representation in RGB]] – each channel ranges from 0 to 255.
- [[Memory Representation]] – `0xFF` is often used in initialization/fill.

## See also
- [Hex to Decimal Converter](https://www.rapidtables.com/convert/number/hex-to-decimal.html)
- [What is 0xFF? – StackOverflow](https://stackoverflow.com/questions/9844085/what-is-0xff)
- [[Lecture 4 — Memory]]

## Terms
[[hexadecimal]], [[decimal]], [[byte]], [[bit]], [[0xFF]], [[unsigned char]], [[overflow]], [[mask]]
