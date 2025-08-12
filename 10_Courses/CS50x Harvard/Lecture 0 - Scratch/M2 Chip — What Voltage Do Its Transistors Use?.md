---
title: M2 Chip — What Voltage Do Its Transistors Use?
lang_tags: "#lang/hardware"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: ""
atom_idx: 8
status: done
difficulty: easy
date: 2025-08-12
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/0/
review_next: ""
---

  

## **One-liner**

  

Modern SoCs like Apple’s **M2** run their cores at **sub‑1V** **Vdd**; shrinking **transistors** enables lower **voltage** for efficiency (dynamic power ≈ **C × V² × f**).

  

## Big picture

  

- **Transistor scaling** (smaller geometry, e.g., **nanometers**) lets circuits switch reliably at **lower voltages**.  

- Lower **Vdd** dramatically reduces **dynamic power** because power scales with **V²**; small drops in voltage yield large power savings.  

- Exact **operating voltage** varies with **process**, **temperature**, **frequency**, and **power mode** (low‑power vs performance). Core rails are typically **well under 1 volt**, while I/O and always‑on domains may differ.

  

## What to remember about M‑class chips

  

- They’re built on advanced **FinFET** processes (e.g., TSMC N5 family for the original M2), optimized for **low‑voltage** operation.  

- **DVFS** (Dynamic Voltage and Frequency Scaling) changes **Vdd** on the fly to balance **performance** and **battery life**.  

- “One number” doesn’t exist—expect a **range** depending on workload and thermal budget.

  

## Why voltage matters (developer intuition)

  

- **Battery life**: lowering **Vdd** is the strongest lever (V² term).  

- **Thermals**: less voltage → less heat for the same work, enabling higher **sustained performance**.  

- **Signal integrity**: too‑low voltage risks timing failures; designs keep **margins** for reliability.

  

## Safe talking points

  

- Say **“sub‑1V core rails with DVFS”** rather than quoting a single fixed value.  

- Distinguish **core voltage** from **I/O voltages** (e.g., display, LPDDR).  

- Avoid guessing proprietary numbers; discuss **principles** (CMOS power, scaling).

  

## Related Concepts

  

- [[Binary in Hardware — Voltage Representation]] – how digital **0/1** map to voltage levels.  

- [[Transistors and Logic Gates]] – how **logic** is built from **transistors**.  

- [[CMOS Power Consumption]] – the **C × V² × f** relationship.  

- [[Process Nodes (nm) and Scaling]] – why smaller nodes enable lower **Vdd**.  

- [[Dynamic Voltage and Frequency Scaling (DVFS)]] – runtime voltage control.  

  

## See Also

  

- [Apple — M2 family overview](https://www.apple.com/newsroom/2022/06/apple-introduces-m2-with-breakthrough-performance-and-capabilities/)  

- [TSMC — N5 process technology brief](https://www.tsmc.com/english/dedicatedFoundry/technology/logic/l_5nm)  

- [CMOS power equation explained](https://en.wikipedia.org/wiki/Power_dissipation#CMOS)

  

## Terms

  

[[transistor]], [[Vdd]], [[voltage]], [[dynamic power]], [[capacitance (C)]], [[frequency (f)]], [[FinFET]], [[process node]], [[DVFS]], [[core rail]], [[I/O voltage]], [[thermal budget]]

"""