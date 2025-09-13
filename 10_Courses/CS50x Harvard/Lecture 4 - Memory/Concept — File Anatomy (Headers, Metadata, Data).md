---
title: "Concept — File Anatomy (Headers, Metadata, Data)"
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 20
status: done
difficulty: easy
date: "2025-09-13"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/notes/4/"
review_next: "2025-10-28"
---

---

// Место для фото материалов

---

## **One-liner**

Every file has an **anatomy**: a beginning (magic number / header), possible **metadata**, and the actual **content (data)**.

## Very simple

Think of a file like a **book**:  
- The **cover page** = file header (magic number, format info).  
- The **table of contents** = metadata (author, size, encoding).  
- The **story** = actual data (image pixels, sound samples, text).  

## The Big Idea 

Files are not just random bytes. They are **structured containers** with predictable parts so software knows how to read them.

- **Header**: identifies file type and version.  
- **Metadata**: extra info about the file (size, compression, dimensions, etc.).  
- **Data section**: the raw content (pixels, sound waves, text, machine code).  

## Key Characteristics 
- The first bytes (magic numbers) tell you *what* the file is.  
- Metadata often sits right after the header or in special chunks.  
- Data is usually much larger and occupies the bulk of the file.  
- Some formats use **chunks** or **frames** (like PNG, MP3).  

## Examples 

### General ASCII Diagram

```
+-------------------------+
| File Header             |  <- Magic number, format ID
+-------------------------+
| Metadata                |  <- Info about file (author, size, encoding)
+-------------------------+
| Actual Data             |  <- Pixels, audio samples, text, etc.
+-------------------------+
```

### JPEG Anatomy

```
+------------+-------------------+------------------+
| SOI Marker |  Metadata (EXIF)  |   Image Data     |
| FF D8 FF   |  Camera info, etc |  compressed DCT  |
+------------+-------------------+------------------+
```

### PNG Anatomy

```
+-----------+----------------------------+--------------+
| Signature |   Chunks (IHDR, PLTE, IDAT)|  IEND marker |
| 89 50 4E  |  metadata + compressed img |  end signal  |
+-----------+----------------------------+--------------+
```

### PDF Anatomy

```
+----------------------+
| Header (%PDF-1.7)   |
+----------------------+
| Body (objects)      |
+----------------------+
| Cross-Reference     |
+----------------------+
| Trailer             |
+----------------------+
```

## Related Concepts
- [[Cheat Sheet — File Signatures (Magic Numbers)]] – the IDs in the header.  
- [[Dynamic Memory Allocation (Week 4 — Memory)]] – how buffers store file content in RAM.  
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]] – where file bytes live in process memory.  
- [[Binary vs Text Files in C]] – different anatomy depending on file type.  
- [[C File Pointers — Snippets for fgets, fputs, fprintf, fseek, ftell, feof, ferror]] – how you navigate these structures.  
- [[Buffer Overflow — Risks & Mitigations]] – danger when misreading file structure.  

## See Also
- [Wikipedia: File format](https://en.wikipedia.org/wiki/File_format)  
- [Forensics Wiki: File Signatures](https://forensicswiki.xyz/wiki/index.php?title=File_Signatures)  
- [JPEG File Interchange Format](https://en.wikipedia.org/wiki/JPEG_File_Interchange_Format)  

## Terms

