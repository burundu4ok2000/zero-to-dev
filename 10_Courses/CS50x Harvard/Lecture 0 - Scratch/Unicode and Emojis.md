---
title: "Unicode and Emojis"  
lang_tags: "#lang/tools"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: ""
atom_idx: 08
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/0/"
review_next: ""
---

![[Screenshot 2025-06-23 at 19.24.35.png]]
![[Screenshot 2025-06-23 at 19.24.41.png]]
![[Screenshot 2025-06-23 at 19.24.44.png]]
![[Screenshot 2025-06-23 at 19.24.49.png]]
![[Screenshot 2025-06-23 at 19.31.26.png]]

---

## **One-liner**

**Unicode** is a universal **character encoding** standard that supersedes **ASCII** by assigning a unique **code point** to characters from all writing systems — including **emojis**.

## Why ASCII wasn’t enough

- **ASCII** covers only 128 basic symbols; even extended 8‑bit sets can’t represent most human languages.  
- **Unicode** maps over a **million** potential characters (U+0000…U+10FFFF), so scripts, symbols, and emojis can coexist.

## UTF‑8 in practice (how bytes carry characters)

- **UTF‑8** is the dominant **variable‑length encoding** for Unicode on the web and in modern OSes.  
- ASCII stays **1 byte** (`0xxxxxxx`). Non‑ASCII characters use **2–4 bytes** with the pattern `110xxxxx 10xxxxxx …`  
- This keeps English texts compact and still supports every script.  
- Emojis are typically **4 bytes** in UTF‑8.

### Emoji example (from lecture)

The emoji often shown in CS50 (Face with Tears of Joy) is represented by a **multibyte** UTF‑8 sequence. Each **byte** is part of the encoded **code point**, which is why we need more than one byte for rich symbols like emojis.

> Takeaway: **bytes** are storage units; **code points** are abstract characters; **UTF‑8** converts the latter into the former.

## Practical tips (dev mindset)

- Treat text as **Unicode** by default; assume **UTF‑8** encoding.  
- Don’t index strings by **bytes** when you care about **characters**; consider **grapheme clusters** (one visual “character” may be multiple code points).  
- Beware **combining marks**, **skin‑tone modifiers**, and **ZWJ** sequences that form a single emoji from multiple code points.  
- When debugging, print **hex bytes** and **code points**; confirm your editor and terminal are set to **UTF‑8**.

## Common pitfalls

- Assuming 1 **byte** = 1 **character** — false for Unicode.  
- Truncating a string in the middle of a **multibyte** sequence → **invalid encoding** errors.  
- Sorting/uppercasing with naive byte logic — use **locale‑aware** libraries.  
- Mixing encodings (UTF‑8 vs UTF‑16/Latin‑1) in the same pipeline without conversion.

## Related Concepts

- [[ASCII Basics]] – the 7‑bit ancestor that started it all.  
- [[ASCII and Its Limitations]] – why we needed something bigger.  
- [[ASCII Control Characters]] – non‑printing bytes from the teletype era.  
- [[Binary in Hardware — Voltage Representation]] – how bits become signals.  
- [[Media — Still Images]] – pixels and bytes, another encoding story.  
- [[Media — Audio]] – waveforms to samples to bits.
- [[Binary Example - "CS Trivia"]] – decoding bytes as symbols.

## See Also

- [CS50x 2025 — Week 0 overview](https://cs50.harvard.edu/x/2025/weeks/0/)  
- [The Unicode Consortium — What is Unicode?](https://home.unicode.org/what-is-unicode/)  
- [RFC 3629 — UTF‑8, a transformation format of ISO 10646](https://www.rfc-editor.org/rfc/rfc3629)

## Terms

[[Unicode]], [[emoji]], [[UTF-8]], [[code point]], [[code unit]], [[grapheme cluster]], [[combining mark]], [[ZWJ]], [[byte]], [[multibyte]], [[encoding]], [[normalization]], [[locale]]
