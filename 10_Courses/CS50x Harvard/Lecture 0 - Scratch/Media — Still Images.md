[[CS50x Harvard]] · [[10_Courses/CS50x Harvard/00_Lectures/Lecture 0 - Scratch]]
tags: #image #rgb #compression

## Core Concepts
| Format / Concept      | Bits per Pixel | Notes |
|-----------------------|----------------|-------|
| **Bitmap / RAW**      | 24 bits (8 R, 8 G, 8 B) | Uncompressed → huge but exact. |
| **Indexed / Palette** | 8 bits + color table | Re-uses 256 colors to shrink size. |
| **PNG / GIF / JPEG**  | Variable       | PNG/GIF = lossless · JPEG = lossy compression. |

### Binary Example
Pure white pixel → `11111111 11111111 11111111`  
= **255 R, 255 G, 255 B**

### Take-away
Images store millions of RGB triples; compression removes redundancy so the same picture needs fewer bits.

![[Screenshot 2025-06-24 at 10.38.28.png]]