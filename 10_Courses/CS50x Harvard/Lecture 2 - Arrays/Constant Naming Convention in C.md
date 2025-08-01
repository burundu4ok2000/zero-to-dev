![[Screenshot 2025-07-22 at 13.16.16.png]]

![[Screenshot 2025-07-22 at 13.16.19.png]]

> **Lecture reference:** [[Lecture 2 - Arrays]]
> 
> **Course:** [[CS50x Harvard]]

---

## Why capitalize?
- **Signals immutability**: Readers instantly know “don’t change this”.
- **Matches long-standing C style**: `EXIT_SUCCESS`, `INT_MAX`, etc.
- **Stands out from variables** so you don’t confuse `N` with `i`, `score`, …

---

## Rule of thumb

- Use **ALL_CAPS_WITH_UNDERSCORES** for values that never change after definition.  
  ```c
  const int N = 3;      // N is a constant → ALL CAPS
  #define BUFFER_SIZE 1024
  enum { DAYS_IN_WEEK = 7 };