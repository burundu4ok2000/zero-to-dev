---
title: "Binary in Hardware — Voltage Representation"  
lang_tags: "#lang/binary"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: ""
atom_idx: 02
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: "23:03"
source: "https://cs50.harvard.edu/x/2025/weeks/0/"
review_next: ""
---

![[Screenshot 2025-06-23 at 17.22.01.png]]

---

## **One-liner**

Computers encode **binary** using **voltages**: **0** ≈ low voltage (near **0V**), **1** ≈ high voltage (historically around **5V**).

## What it means in hardware

- A wire carries an **analog** voltage, but digital systems interpret it via **thresholds** as **logic levels** (**LOW** or **HIGH**).  
- **Transistors** act like switches, forming **logic gates** that read these levels and produce new ones.  
- Real signals have **noise**; designs include **noise margins** so a slightly off voltage still counts as a valid 0/1.

## Why ~5V shows up (TTL)

- Early computers used **TTL** (Transistor–Transistor Logic) families where **5V** was the standard **Vcc**.  
- **LOW** typically \< 0.8V, **HIGH** typically \> 2.0V (margins between help reject noise).  
- Modern systems often use **CMOS** logic with **lower rails** for power efficiency.

## Modern logic levels (examples)

| Family | Vcc (typical) | HIGH ≳ | LOW ≲ | Notes |
|---|---:|---:|---:|---|
| TTL (5V) | 5.0V | 2.0V | 0.8V | Historical standard; hobby boards still use it |
| CMOS (3.3V) | 3.3V | ~2.0–2.3V | ~0.7–1.0V | Common in microcontrollers |
| CMOS (1.8V) | 1.8V | ~1.0–1.2V | ~0.4–0.6V | Phones/SoCs; saves power |

> Exact thresholds vary by chip family—always check the **datasheet**.

## Common pitfalls

- Treating 5V as universal — many boards are **3.3V-only**. Mixing levels can damage hardware without **level shifting**.  
- Assuming digital is perfectly crisp — wires have **capacitance** and **rise/fall times**; signals are analog under the hood.  
- Floating inputs **without pull-ups/pull-downs** can read randomly; tie them to a defined level.

## Mental model

**Binary** lives on a spectrum: hardware carries **voltages**, but we agree on **thresholds** so circuits behave **digitally**.

## Related Concepts

- [[ASCII Basics]] – binary codes mapped to characters.  
- [[ASCII and Its Limitations]] – where 8-bit encoding hits walls.  
- [[Binary Example - "CS Trivia"]] – playful practice with bits.  
- [[Transistors and Logic Gates]] – physical switches building logic.  
- [[Digital vs Analog Signal]] – how thresholds make analog behave digitally.  
- [[Noise Margin and Level Shifting]] – keeping bits reliable.  

## See Also

- [CS50x 2025 — Week 0 overview](https://cs50.harvard.edu/x/2025/weeks/0/)  
- [Wikipedia — Logic level](https://en.wikipedia.org/wiki/Logic_level)  
- [Wikipedia — Transistor–transistor logic](https://en.wikipedia.org/wiki/Transistor%E2%80%93transistor_logic)

## Terms

[[binary]], [[bit]], [[voltage]], [[logic level]], [[LOW]], [[HIGH]], [[TTL]], [[CMOS]], [[transistor]], [[logic gate]], [[noise margin]], [[pull-up resistor]], [[pull-down resistor]], [[level shifter]], [[datasheet]]
