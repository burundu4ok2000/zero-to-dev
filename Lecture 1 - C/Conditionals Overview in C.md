![[Screenshot 2025-07-20 at 15.41.32.png]]

> **Lecture reference:** [[Lecture 1 - C]] (CS50 Shorts)  
> **Course:** [[CS50x Harvard]]

---

## The three tools

| Construct | Use when | Strengths | Limitations | Micro example |
|-----------|----------|-----------|-------------|---------------|
| `if / else if / else` | Decisions based on *Boolean expressions* (comparisons, ranges, combined logic) | Flexible, supports complex conditions | Verbose when only checking one variable against many discrete constants | `if (x > 10) ... else if (x == 10) ...` |
| `switch` | One variable compared to *many discrete constant values* (`int`, `char`, enum) | Compact, readable dispatch, fall-through (if desired) | Only equality, integral types, need `break;` | `switch (grade) { case 'A': ... }` |
| Ternary `?:` | Tiny two-way value choice | Inline, expressive for assignments & arguments | Not for multi-branch logic; unreadable when nested | `int min = (a < b) ? a : b;` |

---

## Decision flow cheat sheet

| Situation | Pick |
|-----------|------|
| Single simple value choice feeding an assignment | Ternary |
| 2–4 mutually exclusive branches with different conditions | `if / else if` |
| 5+ discrete constant cases on **one** variable (e.g., menu) | `switch` |
| Need intentional fall-through behavior | `switch` |
| Ranges (`0–9`, `>= 100`), compound boolean (`a && b`) | `if / else if` |
| Selecting between two strings / chars / numbers inline | Ternary |
| Comparing strings in C | `if (strcmp(s, \"yes\") == 0)` (switch can’t) |
| Complex nested decisions hurting readability | Split into functions or early returns + `if`s |

---

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

---

## Anti-pattern alerts

| Smell | Why bad | Fix |
|-------|---------|-----|
| Long nested `if` blocks indented deeply | Hard to scan | Use early returns or flatten ladder |
| Switch without `break;` (unintended) | Accidental fall-through | Add `break;` or a comment `// fall through` |
| Nested ternaries | Confusing precedence | Expand to `if` |
| Repeating same variable in many `if (x == ...)` | Boilerplate | Convert to `switch` |

---

## Quick mental models

| Construct | Mental model |
|-----------|--------------|
| `if` chain | Sequential gates; first true one wins (unless separate `if`s) |
| `switch` | A table of labeled doors; you jump to one and (usually) exit |
| Ternary | Tiny inline “if-return” that yields a value |

---

## Checklist before choosing

1. **Am I comparing one variable to constants?** → `switch`.
2. **Do I need ranges or complex logic?** → `if / else if`.
3. **Is it just a small value choice?** → `?:`.
4. **Will readability suffer if shortened?** → Prefer explicit `if`.

---

**Rule of clarity:** Start explicit (`if` ladder). Refactor to `switch` or ternary only if it genuinely improves readability.

---