---
title: "Format Specifiers in C"
lang_tags: "#lang/c"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
status: done
date: "2025-09-13"
review_next: "2025-10-13"
---

# Format Specifiers in C

**Format specifiers** are used in `printf`, `sprintf`, and similar functions to control how variables are printed or written into strings.

---

## 🧩 Syntax

```
%[flags][width][.precision][length][specifier]
```

- **flags** → how to align or pad (e.g., `0` = pad with zeros).  
- **width** → minimum number of characters.  
- **.precision** → for floats = decimals, for strings = max length.  
- **specifier** → type: `i`, `d`, `f`, `s`, `c`, etc.

---

## 📋 Common Specifiers

| Specifier | Meaning                           | Example Output |
|-----------|-----------------------------------|----------------|
| `%i`, `%d`| Integer (decimal)                 | `42` |
| `%u`      | Unsigned integer                  | `300` |
| `%x`      | Hexadecimal (lowercase)           | `2a` |
| `%X`      | Hexadecimal (uppercase)           | `2A` |
| `%c`      | Single character                  | `A` |
| `%s`      | String                            | `Hello` |
| `%f`      | Floating point                    | `3.141593` |
| `%e`      | Scientific notation               | `3.14e+00` |

---

## 🚦 Width & Padding

```c
printf("%3i\n", 7);    // "  7"   (width = 3, padded with spaces)
printf("%03i\n", 7);   // "007"   (width = 3, padded with zeros)
printf("%10i\n", 42);  // "        42" (width = 10, spaces)
printf("%010i\n", 42); // "0000000042" (width = 10, zeros)
```

---

## 🔍 Strings

```c
printf("%.3s\n", "Hello");   // "Hel" (precision = max length)
printf("%10s\n", "Hi");      // "        Hi" (width = 10)
```

---

## 🔢 Floats

```c
printf("%f\n", 3.14159);     // "3.141590" (default = 6 decimals)
printf("%.2f\n", 3.14159);   // "3.14" (precision = 2 decimals)
printf("%7.2f\n", 3.14159);  // "   3.14" (width = 7, precision = 2)
```

---

## 🎯 Example — Zero‑padded Filenames

```c
char filename[10];
int i = 7;
sprintf(filename, "%03i.jpg", i);
printf("%s\n", filename);  // "007.jpg"
```

This ensures sorted filenames: `001.jpg, 002.jpg, ... 123.jpg`.

---

## ⚠️ Custom Padding (non‑zero)

Standard C only supports **spaces** or **zeros** as fill.  
If you want to pad with other characters (e.g., `7`):

```c
char buf[32];
sprintf(buf, "%010i", 42); // "0000000042"

// Replace zeros with sevens
for (int j = 0; buf[j]; j++) {
    if (buf[j] == '0') buf[j] = '7';
}
printf("%s\n", buf); // "7777777742"
```

---

## Related Concepts
- [[Markers in File Formats]] – uses `%03i` in recovery code  
- [[Bitwise Operations & Masks in C]] – another way to manipulate numbers at bit level  
- [[Pointers in C — Address-of & Dereference]]  
- [[Dynamic Memory Allocation (Week 4 — Memory)]]  
- [[Endianess — Big vs Little]]  
- [[Hexadecimal & Bytes — C Basics]]  

## See Also
- [C printf format specification](https://en.cppreference.com/w/c/io/fprintf)  
- [GeeksforGeeks — Format Specifiers in C](https://www.geeksforgeeks.org/format-specifiers-in-c/)  
- [Tutorialspoint — printf() function in C](https://www.tutorialspoint.com/printf-in-c)  

## Terms
[[Format Specifier]], [[Width]], [[Precision]], [[Padding]], [[Integer]], [[Float]], [[String]], [[Hexadecimal]]
