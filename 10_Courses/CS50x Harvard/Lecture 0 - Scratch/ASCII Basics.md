---
title: "ASCII Basics"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_Scratch"
tool_tags: ""
atom_idx: 02
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/0/"
review_next: ""
---

![[Screenshot 2025-06-23 at 18.44.26.png]]

---

## **One-liner**

**ASCII** maps characters to numbers (0–127) so text can be stored and moved as **bytes**; under the hood, every letter is just a **code** in **binary**.

## What is ASCII?

- **American Standard Code for Information Interchange** — a **character encoding** that assigns **code points** 0–127 to letters, digits, punctuation, and control signals.  
- Stored as **8 bits** per character in practice (a **byte**), though **standard ASCII** uses only the lower **7 bits** (0–127).  
- Examples: **'A' = 65 = 01000001₂**, **'a' = 97 = 01100001₂**.

## Binary representation (mental model)

Text → **numbers** → **binary** → **bits in memory**. The same bits travel over networks and land in files — the UI just renders the codes back into glyphs.

## Why it matters in Week 0

- Explains how Scratch and C strings eventually reduce to raw **bytes**.  
- Demystifies input/output: keyboards send **codes**, screens render based on **codes**.  
- Sets the stage for **Unicode** (when 128 symbols isn’t enough).

## Limitations (preview)

- Only **128** codes → English-centric. No emojis, accented letters, or most world scripts.  
- Multiple “extended ASCII” variants (0–255) exist but **aren’t standardized**.  
- Modern software prefers **Unicode/UTF‑8** for broad coverage and compatibility.

## Quick peek code (C)

```c
#include <stdio.h>
int main(void)
{
    char ch = 'A';                 // 65
    printf("%c %i\n", ch, ch);    // A 65
}
```

## Related Concepts

- [[ASCII and Its Limitations]] – what breaks when you leave plain English.  
- [[ASCII Control Characters]] – non-printing codes (0–31, 127).  
- [[Binary Example - CS Trivia]] – fun binary/ASCII decoding demos.  
- [[Unicode and UTF-8 Basics]] – modern successor covering most scripts.  
- [[Char Type in C]] – how characters live as small integers in C.  
- [[Strings in C]] – arrays of `char` terminated with NUL.

## See Also

- [CS50x 2025 — Week 0 overview](https://cs50.harvard.edu/x/2025/weeks/0/)  
- [Wikipedia — ASCII](https://en.wikipedia.org/wiki/ASCII)  
- [man ascii — ASCII table](https://man7.org/linux/man-pages/man7/ascii.7.html)

## Terms

[[ASCII]], [[character encoding]], [[code point]], [[byte]], [[bit]], [[binary]], [[glyph]], [[control character]], [[Unicode]], [[UTF-8]], [[string]], [[char]]
