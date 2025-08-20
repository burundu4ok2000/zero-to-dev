---
title: "RGB, RGBA & Color Representation in Bytes"  
lang_tags: "#lang/c"                                        
type_tags: "#type/lecture"                                      
course_tags: "#course/cs50x/intoduction_to_CS"                                        
lecture_tags: "#lecture/week_4_Memory"                                      
tool_tags: ""                                            
atom_idx: 04                                          
status: "done"                                             
difficulty: "easy"                                           
date: "2025-08-20"                             
timecode: "00:13:00"                                          
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                             
review_next: "2025-09-20"                                      
---

---

## Summary
**RGB** uses 3 bytes to represent color using **Red, Green, Blue** channels. **RGBA** adds a fourth byte for **transparency** (alpha). Each channel stores a value from 0 to 255 (`0x00` to `0xFF`).

## Very simple

> Imagine you mix 3 buckets of paint: **red**, **green**, **blue** — each can go from **empty (0)** to **full (255)**. Then you add a **glass filter** on top: alpha controls how transparent that glass is!

## Key Points
- **RGB** = 3 channels → Red, Green, Blue
- Each channel: 1 byte (0–255)
- **RGBA** = RGB + Alpha → adds transparency
- Alpha = 0 (invisible) → 255 (fully visible)
- Total size: 3 bytes (RGB) or 4 bytes (RGBA)

## Details
- Color example: `#FF0000` = red (R=255, G=0, B=0)
- With alpha: `#FF000080` → red with 50% transparency
- Common formats:
  - `RGB` → used in most JPEGs
  - `RGBA` → used in PNGs, UIs, games
- Often expressed in hex: `0xRRGGBB` or `0xRRGGBBAA`

## Examples
```c
uint8_t red = 255;      // 0xFF
uint8_t green = 0;
uint8_t blue = 0;
uint8_t alpha = 128;    // 50% opacity

// Together: RGBA = {255, 0, 0, 128}
```

## **Why It Matters**
- Every color pixel on screen is stored using RGB(A).
- Knowing the 0–255 range explains why **`0xFF` = full intensity**.
- Helps understand UI rendering, image formats, and memory layout of pixels.
- Useful when writing low-level graphics code or debugging image data.

## Questions
- ❓ Why do some formats not support alpha?
- ❓ Is 16-bit or float-based color used in modern displays?

## Related Concepts
- [[Counting in Hex — FF Equals 255]] – each RGB channel uses a full byte, from 0 to 255.
- [[Hexadecimal Notation]] – often used to express color values.
- [[Memory Representation]] – pixels are just structured memory.
- [[Bitmasking in C]] – color channels can be extracted using bit operations.
- [[Endianness]] – can affect how pixel data is stored.
- [[Floating Point vs Integer]] – higher color fidelity in HDR uses floats.

## See also
- [RGBA color values – W3Schools](https://www.w3schools.com/css/css3_colors.asp)
- [What is RGBA? – MDN](https://developer.mozilla.org/en-US/docs/Web/CSS/color_value#rgba)
- [How colors are stored in bytes](https://stackoverflow.com/questions/6937789/how-are-colors-stored-in-memory)

## Terms
[[rgb]], [[rgba]], [[byte]], [[color depth]], [[alpha channel]], [[pixel]], [[hex color]], [[opacity]]
