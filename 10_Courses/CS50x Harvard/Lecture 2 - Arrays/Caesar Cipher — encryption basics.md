---
title: Caesar Cipher — encryption basics
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: ""
atom_idx: 7
status: done
difficulty: easy
date: 2025-08-10
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

![[2025-08-01_15-28-51.png]]
![[2025-08-01_15-29-22.png]]

## Summary
A Caesar cipher replaces each letter in the **plaintext** with a letter some fixed number of positions down the alphabet, producing **ciphertext**. This note covers the basic idea, implementation, and implications.

## Key Points
- **Plaintext** is the original message.
- **Key** defines the number of positions to shift each character.
- **Cipher** scrambles text using this key.
- **Ciphertext** is the scrambled result sent/stored.
- Non-letters remain unchanged (e.g., punctuation).
- **Modulo 26** ensures wrap-around (e.g., 'z' becomes 'a').

## Details

### The high-level pipeline
```
plaintext  +  key  ─►  cipher box  ─►  ciphertext
```

- The Caesar cipher is an example of a **substitution cipher**.
- Works by applying a fixed **shift** to alphabetic characters.

### Caesar shift example (key = 1)

| **Char** | **ASCII** | **+1 →** | **Result** |
|----------|-----------|----------|------------|
| H        | 72        | 73       | I          |
| I        | 73        | 74       | J          |
| !        | 33        | —        | !          |

Only alphabetic characters rotate; punctuation remains untouched.

### Pseudocode

```
for each character c in plaintext
    if c is lowercase letter
        output  ((c - 'a' + key) % 26) + 'a'
    else if c is uppercase letter
        output  ((c - 'A' + key) % 26) + 'A'
    else
        output  c
```

## Examples

### Minimal C implementation

```c
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }

    int key = atoi(argv[1]) % 26;
    string p = get_string("Plaintext: ");
    printf("Ciphertext: ");

    for (int i = 0; p[i] != '\0'; i++)
    {
        char c = p[i];
        if (isupper(c))
            printf("%c", ((c - 'A' + key) % 26) + 'A');
        else if (islower(c))
            printf("%c", ((c - 'a' + key) % 26) + 'a');
        else
            printf("%c", c);
    }
    printf("\n");
    return 0;
}
```

## **Why It Matters**

- Caesar cipher is insecure but introduces **fundamental concepts** like:
  - text transformation,
  - keys,
  - encryption/decryption symmetry,
  - modular arithmetic.

## Questions

- ❓Why is modulo needed?
- ❓How would this break for Unicode or other alphabets?

## Related Concepts

- [[Modular Arithmetic in C]] – explains the modulo operation used for letter wrapping.
- [[Command-line arguments in C]] – `argv[1]` usage in key input.
- [[Char Type in C]] – ASCII math and `isupper()`/`islower()` checks.
- [[Black-box abstraction in functions]] – how the Caesar function could be abstracted.
- [[String manipulation in C]] – deals with `get_string`, indexing, and loops.

## See also

- [[Lecture 2 - Arrays]]
- [Caesar Cipher – Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher)
- [CS50 Caesar assignment](https://cs50.harvard.edu/x/2025/psets/2/caesar/)

## Terms

[[cipher]], [[plaintext]], [[ciphertext]], [[key]], [[ASCII]], [[modulo]], [[Caesar cipher]], [[substitution]], [[encryption]], [[decryption]], [[string]], [[argv]], [[argc]]
