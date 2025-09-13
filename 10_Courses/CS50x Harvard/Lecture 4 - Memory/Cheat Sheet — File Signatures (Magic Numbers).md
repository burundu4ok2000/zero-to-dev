---
title: "Cheat Sheet — File Signatures (Magic Numbers)"
lang_tags: "#lang/c"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 19
status: done
difficulty: easy
date: "2025-09-13"
timecode: ""
source: "https://en.wikipedia.org/wiki/List_of_file_signatures"
review_next: "2025-11-12"
---

---

// Место для фото материалов

---

## **One-liner

File **signatures** (aka **magic numbers**) are short byte sequences at the **start** of a file that identify its **format**.

## Very simple

A file’s first bytes are like a **passport stamp**: they say “I’m a PNG” or “I’m a PDF”. Tools and OSes read that stamp to choose the right parser.

## Common Commands / Syntax

| **File Type**    | **Hex Signature (first bytes)**                   | **Notes**                                   |
| ---------------- | ------------------------------------------------- | ------------------------------------------- |
| JPEG             | `FF D8 FF`                                        | SOI marker (Start Of Image)                 |
| PNG              | `89 50 4E 47 0D 0A 1A 0A`                         | ASCII “.PNG”                                |
| GIF87a           | `47 49 46 38 37 61`                               | ASCII “GIF87a”                              |
| GIF89a           | `47 49 46 38 39 61`                               | ASCII “GIF89a”                              |
| PDF              | `25 50 44 46`                                     | ASCII “%PDF”                                |
| BMP              | `42 4D`                                           | ASCII “BM”                                  |
| WebP             | `52 49 46 46`                                     | RIFF container, `WEBP` in header later      |
| TIFF (LE)        | `49 49 2A 00`                                     | Little‑endian                               |
| TIFF (BE)        | `4D 4D 00 2A`                                     | Big‑endian                                  |
| ICO              | `00 00 01 00`                                     | Windows icon file                           |
| MP3 (ID3)        | `49 44 33`                                        | ASCII “ID3” metadata tag                    |
| WAV (RIFF)       | `52 49 46 46`                                     | ASCII “RIFF” (container)                    |
| AVI (RIFF)       | `52 49 46 46`                                     | Same RIFF container, different FourCC later |
| FLAC             | `66 4C 61 43`                                     | ASCII “fLaC”                                |
| OGG              | `4F 67 67 53`                                     | ASCII “OggS”                                |
| MP4 / MOV        | `66 74 79 70` (“ftyp…”)                           | Brand at bytes 4–7 (e.g., `isom`, `mp42`)   |
| HEIC/HEIF        | `66 74 79 70 68 65 69 63`                         | `ftypheic` brand                            |
| ZIP              | `50 4B 03 04`                                     | Container for DOCX/PPTX/XLSX                |
| 7‑Zip            | `37 7A BC AF 27 1C`                               | 7z archive                                  |
| GZIP             | `1F 8B`                                           | Deflate‑based                               |
| RAR (v1.5–4.x)   | `52 61 72 21 1A 07 00`                            | ASCII “Rar!”                                |
| RAR (v5+)        | `52 61 72 21 1A 07 01 00`                         | Newer format                                |
| TAR (ustar)      | `75 73 74 61 72`                                  | At **offset 257**, not byte 0               |
| ISO9660          | `43 44 30 30 31`                                  | “CD001” at **offset 0x8001**                |
| ELF (Linux)      | `7F 45 4C 46`                                     | ASCII “.ELF”                                |
| Mach‑O (macOS)   | `FE ED FA CE` / `FE ED FA CF`                     | 32/64‑bit variants                          |
| PE/EXE (Windows) | `4D 5A`                                           | ASCII “MZ”; PE header later                 |
| Java CLASS       | `CA FE BA BE`                                     | “CAFEBABE”                                  |
| SQLite           | `53 51 4C 69 74 65 20 66 6F 72 6D 61 74 20 33 00` | “SQLite format 3\0”                         |
| XML              | `3C 3F 78 6D 6C`                                  | ASCII"`<?xml”`                              |
| HTML             | `3C 21 44 4F 43 54 59 50 45`                      | ASCII `“<!DOCTYPE”`                         |
| PostScript       | `25 21`                                           | ASCII “%!PS”                                |
| Python .pyc      | varies by version                                 | CPython magic at start + timestamp          |

## Frequently Used Patterns
- **ZIP families**: DOCX/XLSX/PPTX are ZIP archives with XML inside.  
- **RIFF container**: WAV/AVI/WebP share `RIFF` then differ by later **FourCC**.  
- **Endian pairs**: TIFF has little‑endian and big‑endian signatures.  
- **Offset signatures**: TAR/ISO store magic not at byte 0 — check the **offset**.  

## Shortcuts
- macOS/Linux quick peek: `file my.bin`  
- Hex view first 32 bytes: `xxd -l 32 filename`

## Tips & Gotchas
- A matching signature ≠ guaranteed format; always validate the **rest of the header**.  
- Containers (ZIP, RIFF, MP4) need deeper checks (brands/FourCC/chunks).  
- Some tools write a **BOM** or metadata before content; don’t confuse it with the file’s magic.  

## Examples
```bash
# Identify format
file sample.bin

# Inspect first bytes
xxd -g 1 -l 32 sample.bin
```

## Related Concepts
- [[Concept — File Anatomy (Headers, Metadata, Data)]]
- [[Dynamic Memory Allocation (Week 4 — Memory)]]
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]]
- [[C File Pointers — Snippets for fgets, fputs, fprintf, fseek, ftell, feof, ferror]]
- [[Binary vs Text Files in C]]
- [[Hexadecimal & Bytes — C Basics]]
- [[Error Handling Patterns in C]]
- [[Valgrind Basics — Leak Check]]

## See Also
- [Wikipedia — List of file signatures](https://en.wikipedia.org/wiki/List_of_file_signatures)
- [Forensics Wiki — File signatures](https://forensicswiki.xyz/wiki/index.php?title=File_Signatures)
- [Linux `file` manpage](https://man7.org/linux/man-pages/man1/file.1.html)

## Terms
[[File Signature]], [[Magic Number]], [[Header]], [[Metadata]], [[Byte]], [[Hexadecimal]], [[Offset]], [[Container Format]], [[RIFF]], [[ZIP]], [[ELF]], [[Executable]], [[Endianness]]
