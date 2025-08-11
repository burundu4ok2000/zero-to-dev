---
title: "Conditionals Overview in C"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 08
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-20 at 15.41.32.png]]

---

## **One-liner**

Pick between **if/else**, **switch**, and **ternary** to express decisions clearly and safely in C.

## The three tools

| Construct | Use when | Strengths | Limitations | Micro example |
|---|---|---|---|---|
| `if / else if / else` | Decisions based on **\Boolean expressions\** (comparisons, ranges, combined logic) | Flexible; handles ranges and compound conditions | Can get verbose for many discrete constants | `if (x > 10) ... else if (x == 10) ...` |
| `switch` | One variable vs many **\discrete constants\** (`int`, `char`, `enum`) | Compact, readable dispatch; allows **\fall-through\** | Only equality; integral types; needs `break;` to stop | `switch (grade) { case 'A': ... }` |
| Ternary `?:` | Tiny two-way **\value selection\** | Inline, expressive in assignments/arguments | Not for multi-branch logic; unreadable when **\nested\** | `int min = (a < b) ? a : b;` |

## Decision flow cheat sheet

| Situation | Pick |
|---|---|
| Single simple value choice feeding an assignment | **\Ternary operator\** |
| 2–4 mutually exclusive branches with different conditions | **\if / else if\** |
| 5+ discrete constant cases on **one** variable (e.g., menu) | **\switch\** |
| Need intentional fall-through behavior | **\switch\** |
| Ranges (`0–9`, `>= 100`), compound boolean (`a && b`) | **\if / else if\** |
| Selecting between two strings/chars/numbers inline | **\ternary\** |
| Comparing strings in C | `if (strcmp(s, "yes") == 0)` (**\switch\** can’t) |
| Complex nested decisions hurt readability | Split into **\functions\** or use early returns + **\if\** |

## Patterns

### If / else if ladder

```c
if (score >= 90)      grade = 'A';
else if (score >= 80) grade = 'B';
else if (score >= 70) grade = 'C';
else                  grade = 'F';
```

### Switch with shared cases

```c
switch (c)
{
    case 'y':
    case 'Y':
        puts("Yes");
        break;
    case 'n':
    case 'N':
        puts("No");
        break;
    default:
        puts("?");
}
```

### Intentional switch fall-through

```c
switch (start)
{
    case 5: puts("Five");
    case 4: puts("Four");
    case 3: puts("Three");
    case 2: puts("Two");
    case 1: puts("One");
    default: puts("Blast-off!");
}
```

### Ternary for value selection

```c
int abs_x = (x < 0) ? -x : x;
```

## Anti-pattern alerts

| Smell | Why bad | Fix |
|---|---|---|
| Long nested `if` blocks indented deeply | Hard to scan | Use **\early returns\** or flatten the ladder |
| `switch` without `break;` (unintended) | Accidental **\fall-through\** | Add `break;` or a comment `// fall through` |
| Nested ternaries | Confusing **\precedence\** / readability | Expand to `if` |
| Repeating `if (x == ...)` for many constants | Boilerplate | Convert to **\switch\** |

## Quick mental models

| Construct      | Mental model                                             |
| -------------- | -------------------------------------------------------- |
| **\if\** chain | Sequential gates: first true one **wins**                |
| **\switch\**   | A table of labeled doors: jump to one and (usually) exit |
| **\ternary\**  | Tiny inline “if-that-returns-a-value”                    |

## Checklist before choosing

1. **Am I comparing one variable to constants?** → **\switch\**.  
2. **Do I need ranges or compound logic?** → **\if / else if\**.  
3. **Is it just a small value choice?** → **\?: (ternary)\**.  
4. **Will shortening hurt readability?** → Prefer explicit **\if\**.

**Rule of clarity:** Start explicit (an **\if\** ladder). Refactor to **\switch\** or **\ternary\** only if it genuinely improves readability.

## Related Concepts

- [[Comparison Operators in C]] – feed **\Boolean expressions\** for decisions.
- [[Logical Operators in C]] – **\&&\**, **\||\**, **\!\** for compound conditions.
- [[Ternary Operator ?: in C]] – concise **\value selection\**.
- [[Switch Statement in C]] – multiway branch on one variable.
- [[Control Flow in C]] – bigger picture of sequencing, selection, iteration.

## See Also

- [cppreference — Selection statements (`if`, `switch`)](https://en.cppreference.com/w/c/language/selection)
- [cppreference — Conditional operator `?:`](https://en.cppreference.com/w/c/language/conditional)
- [man strcmp — string compare](https://man7.org/linux/man-pages/man3/strcmp.3.html)

## Terms

[[if statement]], [[else if]], [[else]], [[switch statement]], [[ternary operator]], [[Boolean expression]], [[comparison operator]], [[logical operator]], [[case label]], [[break statement]], [[default label]], [[fall-through]], [[precedence]], [[early return]], [[strcmp]], [[control flow]]
