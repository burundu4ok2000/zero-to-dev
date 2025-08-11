---
title: Char Type in C
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 6
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/1/
review_next: ""
---

---

![[Screenshot 2025-07-15 at 15.42.51.png]]
![[Screenshot 2025-07-15 at 15.50.10.png]]

---
## **One-liner

> `char` is a **\1-byte integer\** that encodes a **\single character\** via its **\ASCII code\**.

## The Big Idea 
- In C, characters are just **\small integers\**. `'A'` is 65, `'0'` is 48.
- You use **\single quotes\** for a **\character literal\**; **double quotes** create a **\string\** (array of `char`).
- Because `char` is numeric, you can do **\comparisons\**, **\casting\**, and even light **\arithmetic\** on it.

## Key Characteristics 
- Size: 1 byte (8 bits) on CS50’s 64‑bit Linux.
- Signedness: implementation-defined (`char` may behave as **\signed\** or **\unsigned\**). Prefer `signed char` / `unsigned char` when it matters.
- Literals: `'A'`, `'z'`, `'3'`, `'!'`. Use **\escape sequences\** like `'\n'`, `'\t'`, `'\''`, `'\"'`.
- Printing: `%c` for the character, `%i` to see its numeric ASCII value.
- Strings: `"A"` is **not** a `char` — it’s a **\NUL-terminated\** array of `char` (`char *`).

## Examples 
```c
// Declaration + print
char initial = 'S';
printf("%c\n", initial);      // S

// ASCII peek
char ch = 'A';
printf("%i\n", ch);           // 65

// Comparison (note single quotes)
char ans = get_char("Continue? (y/n) ");
if (ans == 'y') printf("Yes\n");
else if (ans == 'n') printf("No\n");

// Casting between int and char
int code = 97;
printf("%c\n", (char) code);  // a

// Wrong vs right
// if (ans == "y") { ... }    // ❌ string (char *) — type mismatch
// if (ans == 'y') { ... }    // ✅ char literal
```

## Related Concepts
- [[Single vs Double Quotes]] – distinguishes **characters** vs **strings** in C usage.
- [[C Type Sizes and Memory]] – where `char` sits among other primitive types.
- [[ASCII Table]] – mapping between characters and integer codes.
- [[printf Format Specifiers]] – how `%c`, `%i`, `%s` differ.
- [[Strings in C]] – arrays of `char`, NUL-termination, and common pitfalls.

## See Also
- [CS50x 2025 — Week 1: C](https://cs50.harvard.edu/x/2025/weeks/1/)
- [cppreference — Character types](https://en.cppreference.com/w/c/language/char)
- [man ascii — ASCII table](https://man7.org/linux/man-pages/man7/ascii.7.html)

## Terms
 [[data type]], [[ASCII]], [[character literal]], [[string]], [[casting]], [[format specifier]], [[escape sequence]]
