
> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]
![[Screenshot 2025-07-15 at 15.42.51.png]]
---
## What is `char`?

A `char` is a **data type** in C that stores a **single character**, like `'a'`, `'Z'`, `'3'`, or `'!'`.

- Stored as a **1-byte integer** (8 bits)
- Internally represents the character’s **ASCII code**  
  e.g. `'A'` → `65`, `'n'` → `110`

---

## Declaration and usage

```c
char initial = 'S';
printf("%c\n", initial);       // prints: S
```

Use **single quotes** for characters: `'y'`, `'n'`, `'?'`

✅ This is required.  
❌ `"y"` is a string, not a char — it won’t compile in this context.

---

## Common use cases

| Scenario            | Example                 |
|---------------------|-------------------------|
| Yes/No input        | `char answer = get_char("Continue? (y/n) ");` |
| Initials / Letters  | `char grade = 'A';`     |
| Character comparison | `if (ch == 'y') …`      |

---

## ASCII & casting

Each `char` has a numeric value:

```c
char ch = 'A';
printf("%i\n", ch);   // prints: 65
```

You can **cast** between `char` and `int` freely in C.

---

## Important syntax rule
![[Screenshot 2025-07-15 at 15.50.10.png]]
- A `char` must be enclosed in **single quotes**: `'a'`, `'1'`, `'!'`
- Double quotes (`"a"`) create a **string** — that's an array of chars, not a single char

If you mistakenly use `"y"` in a comparison:

```c
if (c == "y")   // ❌ Wrong! You're comparing to a string pointer
```

You’ll get a warning or bug. Always use `'y'`, `'n'`, etc., when working with `char`.

---

### Real CS50 example

```c
char c = get_char("Do you agree? ");
if (c == 'y')
{
    printf("Agreed.\n");
}
else if (c == 'n')
{
    printf("Not agreed.\n");
}
```

```get_char()``` returns a `char`, so you must compare it to `'y'` and `'n'` using **single quotes**.

---