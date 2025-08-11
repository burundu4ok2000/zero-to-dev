---
title: "Switch Statement in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 27
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-19 at 21.28.47.png]]

---

## **One-liner**

A **switch** is a compact alternative to a long **if / else if / else** ladder when you’re matching **one integral expression** against several **constant** values.

## Syntax

```c
switch (expression)
{
    case CONSTANT1:
        // code
        break;
    case CONSTANT2:
        // code
        break;
    default:
        // fallback
}
```

- Only the **expression** is evaluated once.
- The value is compared to each **case label**.
- **default** runs if nothing matches (recommended).

## Why use it?

| If / else ladder | switch |
|---|---|
| Repeats the variable: `if (x == 1)`, `else if (x == 2)`... | States the variable once: `switch (x) { case 1: ... }` |
| Works with any boolean condition | Limited to **equality** vs **compile-time constants** |
| Verbose for many discrete values | More compact & visually grouped |
| No fall-through by accident | Has **fall-through** unless you `break;` |

Use **switch** for **many mutually exclusive discrete cases** on **one** variable (menus, decoding a `char`, handling small opcodes).

## Countdown example (intentional fall-through)

```c
int x = get_int("Start: ");
switch (x)
{
    case 5:
        printf("Five, ");
    case 4:
        printf("Four, ");
    case 3:
        printf("Three, ");
    case 2:
        printf("Two, ");
    case 1:
        printf("One, ");
    default:
        printf("Blast-off!\n");
}
```

No `break;` → output continues through later cases. If `x == 3`, prints “Three, Two, One, Blast-off!”.

## Usual pattern (with breaks)

```c
switch (grade)
{
    case 'A': puts("Excellent"); break;
    case 'B': puts("Good");      break;
    case 'C': puts("Average");   break;
    case 'D': puts("Below avg"); break;
    case 'F': puts("Fail");      break;
    default:  puts("Unknown");
}
```

Each **break** exits the switch. Without it, execution **falls through** to the next case.

## Shared logic (case folding)

```c
switch (c)
{
    case 'y':
    case 'Y':
        printf("Yes\n");
        break;
    case 'n':
    case 'N':
        printf("No\n");
        break;
    default:
        printf("Huh?\n");
}
```

## When **not** to use switch

| Situation | Prefer |
|---|---|
| Ranges (`score >= 90`) | **if / else if** |
| Complex boolean logic (multiple variables) | **if / else if** |
| Non-constant comparisons (runtime values) | **if ladder** |
| Strings in C | `strcmp` with **if** (switch can’t match `char *`) |

## Rules & limits

- Expression type: **integral** (`char`, `short`, `int`, `long`, **enum**). Not `float`/`double`.
- Case labels: **compile-time constants** (`5`, `'A'`, `MY_ENUM_VALUE`). No duplicates.
- Flow control: **break** or **return** usually ends a case.
- Scope: declare locals in a **block** if you need isolation: `case 1: { int a = 0; ... break; }`

## Common pitfalls

| Pitfall | Fix |
|---|---|
| Missing `break;` unintentionally → extra cases run | Add `break;` after each case (or `return`) |
| Trying ranges in `case` (`case x > 5:`) | Use **if** outside/inside cases |
| Floating expression (`switch (f)` where `f` is `float`) | Convert to int or use **if** |
| Variable case labels (`case n:`) | Replace with a constant or use **if** |

## Related Concepts

- [[Conditionals Overview in C]] – picking among **if**, **switch**, **ternary**.
- [[If If If Else Pattern in C]] – how `else` binds to the nearest `if`.
- [[Comparison Operators in C]] – values that feed your conditions.
- [[Logical Operators in C]] – compose boolean expressions.
- [[Control Flow in C]] – selection within the big picture.
- [[Enumeration (enum) in C]] – great partner for **switch**.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [cppreference — Selection statements](https://en.cppreference.com/w/c/language/selection)  
- [Wikipedia — Switch statement](https://en.wikipedia.org/wiki/Switch_statement)

## Terms

[[switch statement]], [[case label]], [[default label]], [[break statement]], [[fall-through]], [[integral type]], [[enum]], [[compile-time constant]], [[jump table]]
