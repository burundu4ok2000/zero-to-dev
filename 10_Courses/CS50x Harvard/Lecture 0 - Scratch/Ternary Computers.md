---
title: Ternary Computers
lang_tags: 
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_Scratch"
tool_tags: ""
atom_idx: 8
status: done
difficulty: easy
date: 2025-08-12
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/0/
review_next: ""
---

![[Screenshot 2025-06-23 at 18.10.35.png]]

---

## **One-liner**

**Ternary computers** use **base‑3** digits (often −1, 0, +1 in **balanced ternary**) instead of binary’s **0/1**. They can be elegant, but **binary** won due to simpler, more reliable **hardware**.

## Quick mental model

- A binary **bit** has two states. A ternary **trit** has **three**.  
- **Balanced ternary** uses digits −1, 0, +1 which make **rounding** and **sign** handling neat.  
- Real machines existed (e.g., **Setun**, 1958), but most computing standardized on binary.

## Why binary dominates

- **Physics-friendly**: transistors naturally support two stable states with wide **noise margins** (easy to distinguish “low” vs “high”).  
- **Simplicity**: fewer **voltage levels** → cheaper, faster, more robust circuits.  
- **Universality**: a single gate family (**NAND**/**NOR**) is functionally complete; manufacturing optimized around it.  
- **Ecosystem lock‑in**: tools, memory, buses, and standards are all binary—network effects are huge.

## Where ternary shines (on paper)

- **Information density**: a **trit** carries log₂(3) ≈ **1.585 bits** of information.  
- **Balanced arithmetic**: subtraction and sign can be simpler; certain **algorithms** have tidy forms.  
- **Fewer digits** for some numbers relative to base‑2.

## Practical obstacles

- **Analog precision**: reliably separating **three** voltage levels at speed is harder than two.  
- **Mixed ecosystems**: I/O and storage are overwhelmingly **binary**, so conversion costs bite.  
- **Tooling**: compilers, ISAs, memories, and verification flows assume **bits**.

## Minimal examples (representations)

- Binary `6` = **110₂**.  
- Ternary `6` = **20₃** (unbalanced) or **+−0** in **balanced** ternary (one possible notation).

> Balanced digits are often written as `- 0 +`, or `T 0 1`, or with an overbar for −1.

## When to think about this in CS50

- As a thought experiment tying **hardware** to **number systems**.  
- When comparing **encodings** and why **binary in hardware — voltage representation** won historically.

## Related Concepts

- [[Binary in Hardware — Voltage Representation]] – why two levels map well to transistors.  
- [[Introduction to Binary Logic]] – gates, truth tables, and functional completeness.  
- [[Number Bases and Radix]] – converting between bases (2, 3, 10, 16).  
- [[Balanced Ternary Notation]] – −1/0/+1 digit system and arithmetic.  
- [[Information Theory Basics]] – why a trit ≈ 1.585 bits.  
- [[Logic Gates (NAND, NOR)]] – universality that favored binary hardware.

## See Also

- [Wikipedia — Ternary computer](https://en.wikipedia.org/wiki/Ternary_computer)  
- [Wikipedia — Balanced ternary](https://en.wikipedia.org/wiki/Balanced_ternary)  
- [Setun — Soviet ternary computer](https://en.wikipedia.org/wiki/Setun)

## Terms

[[ternary computer]], [[trit]], [[balanced ternary]], [[radix]], [[noise margin]], [[voltage level]], [[NAND gate]], [[NOR gate]], [[encoding]], [[information density]], [[logic gate]]
