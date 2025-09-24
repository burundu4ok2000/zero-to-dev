---
title: Markers in File Formats
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
status: done
date: 2025-09-13
review_next: 2025-10-13
source: https://cs50.harvard.edu/x/2025/weeks/4/
---

# Markers in File Formats

Markers are **special byte sequences** inside files that act like **flags**.  
They tell the computer: "Here begins this kind of block."  
Think of them as **road signs** in a binary highway.

---

## 🧩 Why do we need markers?
- **Structure** → split the file into sections (header, metadata, pixel data, etc.).  
- **Navigation** → software knows where to jump and what to parse.  
- **Compatibility** → new blocks (e.g., EXIF) can be added without breaking old decoders.  
- **Error recovery** → you can re-sync at the next marker if something is corrupted.

---

## 📸 JPEG Example

A JPEG file always starts and ends with fixed markers:

```
[ FF D8 ] SOI  (Start Of Image)
[ FF E0..EF ] APP0..APP15 (Application-specific blocks, e.g. EXIF)
[ FF DB ] DQT  (Define Quantization Table)
[ FF C0 ] SOF0 (Start of Frame – width, height, channels)
[ FF C4 ] DHT  (Define Huffman Table)
[ FF DA ] SOS  (Start of Scan – compressed pixels)
[ FF D9 ] EOI  (End Of Image)
```

---

## ASCII Diagram of a JPEG File

```
+-------------------+
| SOI (FF D8)       |  <- Start of Image
+-------------------+
| APPn (FF E0..EF)  |  <- Metadata (JFIF/EXIF)
+-------------------+
| DQT (FF DB)       |  <- Quantization tables
+-------------------+
| SOF0 (FF C0)      |  <- Frame header (size, info)
+-------------------+
| DHT (FF C4)       |  <- Huffman tables
+-------------------+
| SOS (FF DA)       |  <- Start of compressed data
|   ... pixel data ... 
+-------------------+
| EOI (FF D9)       |  <- End of Image
+-------------------+
```

---

## 🔍 Snippet — Detecting JPEG Start

```c
if (buffer[0] == 0xff &&
    buffer[1] == 0xd8 &&
    buffer[2] == 0xff &&
    (buffer[3] & 0xf0) == 0xe0) {
    // Found a JPEG marker (SOI + APPn)
}
```

- ``& 0xf0`` = **mask** → keep only the top 4 bits.  
- ```== 0xe0 = check if those bits equal `1110` (hex E).  
- This matches all `E0..EF` markers in one go.

---

## 🔢 What is a Nibble?

- **Byte** = 8 bits.  
- **Nibble** = 4 bits (half a byte).  

Hexadecimal digits map perfectly to nibbles:  
```
Hex  : 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
Binary:0000 ...                           ...   1111
```

# So:
# - One **hex digit** = one **nibble**.  
# - Two hex digits (e.g., `FF`) = one **byte**.

###### Fun fact:  
- Word "byte" ~ "bite" (a chunk).  
- "Nibble" = a small bite (half a byte).

---

## Related Concepts
- [[Hexadecimal & Bytes — C Basics]] – hex maps directly onto nibbles and bytes  
- [[File Signatures (Magic Numbers)]] – files start with special markers  
- [[Bitwise Operations & Masks in C]] – how `& 0xf0` works  
- [[Endianess — Big vs Little]] – affects how bytes are stored in memory  
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]]  
- [[Dynamic Memory Allocation (Week 4 — Memory)]]  
- [[Pointers in C — Address-of & Dereference]]  

## See Also
- [JPEG File Interchange Format (JFIF)](https://www.w3.org/Graphics/JPEG/jfif3.pdf)  
- [JPEG markers overview](https://en.wikipedia.org/wiki/JPEG#Syntax_and_structure)  
- [Bitwise operations in C](https://en.cppreference.com/w/c/language/operator_arithmetic)  

## Terms
[[Marker]], [[Header]], [[Magic Number]], [[Nibble]], [[Byte]], [[Hexadecimal]], [[Bitwise AND]], [[Mask]]
