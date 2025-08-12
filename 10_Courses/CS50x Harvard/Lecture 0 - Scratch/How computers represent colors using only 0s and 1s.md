---
title: How computers represent colors using only 0s and 1s
lang_tags: 
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: ""
atom_idx: 10
status: done
difficulty: easy
date: 2025-08-12
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/0/
review_next: ""
---

![[Screenshot 2025-06-23 at 19.33.57.png]]

---

## **One-liner**

Screens are **RGB** light mixers: each pixel stores **Red**, **Green**, and **Blue** intensities as **binary numbers**, usually **8 bits per channel** → **24‑bit color** with 16,777,216 combinations.

## Big idea

- **Pixels** are made of three **channels**: **R**, **G**, **B**.  
- Each channel is an **integer** encoded in **binary** (commonly 0–255 with **8 bits** = one **byte**).  
- A color is the **triplet** `(R, G, B)`, e.g., pure red = `(255, 0, 0)` → `11111111 00000000 00000000`.  
- More bits per channel (**color depth**) → smoother gradients and fewer **banding** artifacts.

## Quick examples

- **Red**: `(255, 0, 0)` → `11111111 00000000 00000000`  
- **Green**: `(0, 255, 0)` → `00000000 11111111 00000000`  
- **Blue**: `(0, 0, 255)` → `00000000 00000000 11111111`  
- **Orange** `(255, 165, 0)` → `11111111 10100101 00000000`

Total combinations in 24‑bit color: `256 × 256 × 256 = 16,777,216`.

## Hex view (developer habit)

Programmers often write colors in **hexadecimal** (base‑16): `#RRGGBB`.  
Example: Orange `#FFA500`  
- `FF` = 255, `A5` = 165, `00` = 0.

## Alpha channel (transparency)

Many formats add **alpha** (`A`) for opacity: **RGBA**. With 8‑bit alpha, `0` = transparent, `255` = opaque. Stored as a fourth byte per pixel.

## Gotchas & nuances

- **Monitor profiles** and **sRGB gamma** mean `(R,G,B)` doesn’t map linearly to human **perception**.  
- **Color management** (ICC profiles) and **HDR** displays complicate “same numbers, same look.”  
- Some images are **indexed color** (palette + indexes) or use different models (**CMYK**, **HSV**)—but memory still stores **binary** numbers.

## Related Concepts

- [[Binary in Hardware — Voltage Representation]] – how bits are physically realized.  
- [[ASCII Basics]] – another mapping from **numbers** to human‑meaningful symbols.  
- [[ASCII and Its Limitations]] – why 8‑bit encodings hit limits (analogy to color depth).  
- [[How code & algorythm becomes 0 s and 1 s.]] – compile‑down perspective.  
- [[Bits and Bytes Fundamentals]] – size units behind channels and pixels.

## See Also

- [CS50x 2025 — Week 0](https://cs50.harvard.edu/x/2025/weeks/0/)  
- [Wikipedia — RGB color model](https://en.wikipedia.org/wiki/RGB_color_model)  
- [MDN — Color value syntax (`#RRGGBB`, `rgb()`, `rgba()`)](https://developer.mozilla.org/en-US/docs/Web/CSS/color_value)  

## Terms

[[pixel]], [[RGB]], [[channel]], [[8-bit]], [[byte]], [[color depth]], [[24-bit color]], [[hexadecimal]], [[alpha channel]], [[sRGB]], [[gamma]], [[indexed color]], [[palette]], [[CMYK]], [[HSV]]
