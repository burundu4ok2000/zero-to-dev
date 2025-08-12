---
title: ASCII Control Characters
lang_tags: 
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_Scratch"
tool_tags: ""
atom_idx: 4
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/0/
review_next: ""
---

![[Screenshot 2025-06-23 at 18.51.32.png]]
![[Screenshot 2025-06-23 at 19.12.33.png]]

---

## **One-liner**

Early ASCII codes **0–31** (and **127**) are **control characters** — **non‑printable** bytes for old terminals/teletypes that still influence **newlines**, **tabs**, and **escape sequences** today.

## Big picture

- **ASCII** is a **7‑bit** encoding: **0–127**. Only **32–126** are printable; **0–31** plus **127** (**DEL**) are **controls**.  
- These controls were invented for **device control** (line printers, teletypes). Many are **legacy**, but a few remain crucial in tooling and file formats.

## Core set you’ll meet

| Dec | Abbrev | Name | What it does (modern context) |
|---:|:-----:|:----------------|:-------------------------------|
| 0  | **NUL** | Null | String terminator in C; padding |
| 7  | **BEL** | Bell | May trigger a terminal “beep” |
| 8  | **BS**  | Backspace | Moves cursor left one column |
| 9  | **HT**  | Horizontal Tab | Jumps to next tab stop |
| 10 | **LF**  | Line Feed | New line on Unix‑like systems |
| 13 | **CR**  | Carriage Return | Return to start of line; pairs with LF on Windows |
| 27 | **ESC** | Escape | Starts **ANSI/VT100** **escape sequences** |
| 127| **DEL** | Delete | Historical delete; non‑printable |

> Newline conventions: **Unix/Linux/macOS** use **LF** (`\n`), **Windows** uses **CRLF** (`\r\n`). Files move between worlds all the time, so tools normalize/convert as needed.

## In C / terminals

- **Non‑printables** are written with **escape sequences**: `\n` (**LF**), `\r` (**CR**), `\t` (**HT**), `\a` (**BEL**), `\0` (**NUL**).  
- Printing a raw control char usually **doesn’t render a glyph**; it **affects the terminal** or is ignored.  
- Many modern terminals parse **ESC**‑led sequences like `\x1b[31m` (set text color).

## Quick examples

```c
printf("Hello\n");        // **LF**: move to next line
printf("Col1\tCol2\n");  // **HT**: tab between columns
printf("\a");             // **BEL**: audible/visual bell (if enabled)
```

## Why it matters in Week 0

Understanding **control characters** builds intuition for how “invisible” bytes control **text layout** and why `\n` vs `\r\n` differences matter when you copy files across systems or parse input.

## Related Concepts

- [[ASCII Basics]] – printable range, digits/letters mapping.  
- [[ASCII and Its Limitations]] – why **Unicode/UTF‑8** superseded 7‑bit ASCII.  
- [[Newline Conventions (CR LF)]] – platform differences and conversions.  
- [[Escape Sequences in C]] – how to spell control codes in strings.  
- [[Terminal ANSI Codes]] – coloring and cursor control via **ESC**.  

## See Also

- [CS50x 2025 — Week 0](https://cs50.harvard.edu/x/2025/weeks/0/)  
- [man 7 ascii — Linux man‑pages](https://man7.org/linux/man-pages/man7/ascii.7.html)  
- [Wikipedia — ASCII control characters](https://en.wikipedia.org/wiki/Control_character)

## Terms

[[ASCII]], [[control character]], [[NUL]], [[BEL]], [[BS]], [[HT]], [[LF]], [[CR]], [[ESC]], [[DEL]], [[escape sequence]], [[newline]], [[CRLF]], [[terminal]], [[ANSI codes]]
