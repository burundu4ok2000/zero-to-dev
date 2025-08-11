> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]

---

## Core operators

| Operator | Name        | Meaning                      | Example                   | Result (if x=5, y=7) |
| -------- | ----------- | ---------------------------- | ------------------------- | -------------------- |
| `&&`     | Logical AND | True if **both** sides true  | `(x < y) && (x > 0)`      | `true` (1)           |
| \| \|    | Logical OR  | True if **either** side true | `(x == 5) \|\| (y == 10)` | `true` (1)           |
| `!`      | Logical NOT | Flips a boolean value        | `!(x == 5)`               | `false` (0)          |

In C, “true” is any **non-zero** integer; “false” is `0`. With `<stdbool.h>` you also get the keywords `bool`, `true`, `false`.

---

## Truth tables

### AND (`&&`)
| A | B | A && B |
|---|---|--------|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

### OR (`||`)
| A | B | A \|\| B |
|---|---|----------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

### NOT (`!`)
| A | !A |
|---|----|
| 0 | 1  |
| 1 | 0  |

---

## Short-circuit behavior

| Expression | What short-circuits?                    | Explanation                        |
| ---------- | --------------------------------------- | ---------------------------------- |
| `A && B`   | If `A` is false, **B is not evaluated** | False AND anything → false already |
| `A OR B`   | If `A` is true, **B is not evaluated**  | True OR anything → true already    |

Use this to *safely* guard operations:

```c
if (ptr != NULL && ptr->value > 0)
{
    …
}
```
Second part is only checked when `ptr` is not `NULL`.

---

## Precedence (high → low)

1. `!`
2. Comparison operators: `< <= > >= == !=`
3. `&&`
4. `||`

Add parentheses when in doubt:

```c
if ((x < y && y < z) || flag)
{
    …
}
```

---

## Common patterns

| Goal | Example | Notes |
|------|---------|-------|
| Range check | `if (score >= 0 && score <= 100)` | Both bounds inclusive |
| Multi-value match | `if (c == 'y' || c == 'Y')` | Case-insensitive quick check |
| Safety guard | `if (p && p->next)` | Ensures `p` isn’t `NULL` before dereference |
| Negation of equality | `if (x != y)` | “Not equal” uses `!=` (pronounced “bang equals”) |

---

## Pitfalls

| Mistake | Wrong | Why | Fix |
|---------|-------|-----|-----|
| Assign vs compare | `if (x = 0)` | Assigns 0 → always false | `if (x == 0)` |
| Using bitwise ops | `if (a & b)` | `&` evaluates both sides bitwise | Use `&&` for logic |
| Double-negating unnecessarily | `!!x` in clarity code | Overkill unless forcing 0/1 | Prefer `(x != 0)` |
| Chaining without parentheses | `a && b || c` | Reads as `(a && b) || c` due to precedence | Add parentheses for intent |

---

## With `<stdbool.h>`

```c
#include <stdbool.h>

bool valid = (age >= 18 && age <= 65);
if (!valid)
{
    printf("Out of range\n");
}
```

Using `bool` clarifies intent vs using raw `int`.

---

## Quick checklist

- Use `&&` and `||` (not `&` / `|`) for logical control flow.
- Trust short-circuiting for safe pointer / null checks.
- Parenthesize complex conditions for readability.
- Keep comparisons explicit—avoid clever but unclear tricks.

---