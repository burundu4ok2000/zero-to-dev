---
title: "Media — Still Images"  
lang_tags: "#lang/foundations"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: "#tool/image #tool/rgb #tool/compression"
atom_idx: 16
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/0/"
review_next: ""
---

![[Screenshot 2025-06-24 at 10.38.28.png]]

---

## **One-liner**

Still images are grids of **pixels**; each pixel stores a **color value** in **binary**. File **formats** trade size and quality using **compression**.

## Core concepts

| Format / Concept | Bits per Pixel | Notes |
|---|---|---|
| **Monochrome bitmap** | 1 bit | Black or white (screen-era nostalgia) |
| **Indexed / Palette** | 8 bits + color table | Store index 0–255; colors live in a palette |
| **Truecolor RGB** | 24 bits (8 R, 8 G, 8 B) | Standard for screens; ~16.7M colors |
| **RGBA** | 32 bits (24 RGB + 8 A) | Adds **alpha** (transparency) |

### Binary example
Pure white pixel → `11111111 11111111 11111111` → **255 R, 255 G, 255 B**.

### Resolution & size
Image size (bytes) ≈ **width × height × bpp / 8** before compression.

## Compression (why PNG ≠ JPEG)

- **Lossless** (PNG, GIF, WebP-lossless): compresses patterns without changing pixels; perfect for **UI/art**, **screenshots**, **line art**.  
- **Lossy** (JPEG, WebP-lossy, HEIC): throws away detail humans barely notice; tiny files for **photos**. Watch out for blockiness at high compression.

## Common tasks

- Convert a 24‑bit image to **indexed** to shrink size (poster art, icons).  
- Save screenshots as **PNG**; save camera photos as **JPEG**.  
- Keep **originals** (lossless) when you’ll edit repeatedly; lossy recompression accumulates artifacts.

## Gotchas

- **Color banding** at low **bit depth** (gradients show stripes).  
- **Alpha** not supported in JPEG → transparency is lost.  
- **Metadata** (EXIF, ICC) can affect display or leak info; strip when sharing.  
- Printing uses **CMYK**; screens use **RGB** — conversions can shift colors.

## Related Concepts

- [[How computers represent colors using only 0s and 1s]] – mapping binary to RGB channels.  
- [[Media — Audio]] – another medium: sampling rate, bit depth, compression.  
- [[Binary in Hardware — Voltage Representation]] – physical basis for bits.  
- [[Compression — Lossless vs Lossy]] – deeper dive into algorithms and tradeoffs.  
- [[File Formats: PNG GIF JPEG]] – capabilities, metadata, and use‑cases.  
- [[Bit Depth and Dynamic Range]] – why 8 vs 10 vs 12 bits matter.  

## See Also

- [RGB color model — Wikipedia](https://en.wikipedia.org/wiki/RGB_color_model)  
- [Portable Network Graphics (PNG) — Wikipedia](https://en.wikipedia.org/wiki/Portable_Network_Graphics)  
- [JPEG — Wikipedia](https://en.wikipedia.org/wiki/JPEG)

## Terms

[[pixel]], [[bit depth]], [[palette]], [[RGB]], [[RGBA]], [[alpha channel]], [[compression]], [[lossless]], [[lossy]], [[metadata]], [[EXIF]], [[ICC profile]], [[color model]], [[CMYK]]
