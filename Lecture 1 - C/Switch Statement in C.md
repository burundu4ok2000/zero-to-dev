![[Screenshot 2025-07-19 at 21.28.47.png]]

> **Lecture reference:** [[Lecture 1 - C]] (CS50 Shorts extension)  
> **Course:** [[CS50x Harvard]]

---

## What is `switch`?

`switch` is an alternative to a long `if / else if / else` ladder **when you are comparing the *same* integral expression** (e.g., an `int`, `char`, or enum) against several constant values.

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

* Only one expression is evaluated.
* The value is matched against labeled `case` constants.
* `default` runs if none match (optional but recommended).

---

## Why use it?

| If / else ladder | Switch |
|------------------|--------|
| Repeats the variable: `if (x == 1)`, `else if (x == 2)` ... | States the variable once: `switch (x) { case 1: ... }` |
| Works with any boolean condition | Limited to equality against *constant* values |
| Verbose for many discrete values | More compact & visually grouped |
| Control flow obvious (no fall-through unless you force it with gotos) | Has *fall-through* unless you `break;` |

Use `switch` when you have **many mutually exclusive discrete cases** on *one* variable (menus, decoding a char, handling small protocol opcodes).

---

## Countdown example (from the slide)

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

### What happens here?

There are **no `break;` statements**, so execution “falls through”:
* If `x == 3`, printing starts at `"Three, "` and continues **through** the later cases → `"Three, Two, One, Blast-off!"`.
* This *intentional fall-through* creates a countdown effect.

---

## Adding `break;` (the usual pattern)

```c
switch (grade)
{
    case 'A':
        puts("Excellent");
        break;
    case 'B':
        puts("Good");
        break;
    case 'C':
        puts("Average");
        break;
    case 'D':
        puts("Below average");
        break;
    case 'F':
        puts("Fail");
        break;
    default:
        puts("Unknown grade");
}
```

Each `break;` exits the `switch`. Without it, code keeps executing the following cases.

---

## Intentional fall-through

Sometimes you *want* multiple cases to share logic:

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

Here `'y'` and `'Y'` both flow into the same block before the `break;`.

---

## When **not** to use `switch`

| Situation | Prefer |
|-----------|--------|
| Ranges (e.g., score >= 90) | `if / else if` |
| Complex boolean logic (multiple variables) | `if / else if` |
| Non-constant comparisons (runtime values, expressions) | `if` ladder |
| Strings in C | Manual `strcmp()` with `if` (C `switch` doesn’t work on `char *`) |

---

## Rules & limits

| Rule | Detail |
|------|--------|
| Expression type | Integral: `char`, `short`, `int`, `long`, enums. (Not `float` / `double`.) |
| Case labels | Must be *compile-time constants* (`5`, `'A'`, `MY_ENUM_VALUE`). |
| Unique cases | No duplicate constant values. |
| Flow control | `break;` (or `return`) usually ends a case. |
| Scope | Declare variables inside blocks if you need isolation: `case 1: { int a = 0; ... break; }` |

---

## Common pitfalls

| Pitfall | Example | Fix |
|---------|---------|-----|
| Missing `break;` unintentionally | Case prints extra lines | Add `break;` after each case |
| Using ranges in `case` | `case x > 5:` (invalid) | Use `if` outside or inside cases |
| Floating switch expression | `switch (f)` where `f` is `float` | Convert to int or use `if` |
| Variable case labels | `case n:` (where `n` is a variable) | Replace with constant or `if` |

---

## Pattern comparison

| Goal | Best construct |
|------|----------------|
| Single variable exact match (many options) | `switch` |
| Mutually exclusive numeric ranges | `if / else if` |
| Need fall-through sequencing (countdown) | `switch` without `break;` |
| Multiple variables or complex boolean | `if` ladder |

---

## Mini cheat sheet

| Need | Example |
|------|---------|
| Shared logic (case folding) | `case 'a': case 'A':` |
| Countdown / cumulative output | Omit breaks intentionally |
| Early exit | Use `return` inside case (no `break;` needed) |
| Default fallback | Always include `default:` for unexpected values |

---

## Take-away

`switch` gives you a **clean dispatch table** when matching one integral value. Remember:
> *Add `break;` unless you want fall-through — and when you *do* want fall-through, comment it.*

---

### Tiny annotated example

```c
switch (op)
{
    case '+':   result = a + b; break;
    case '-':   result = a - b; break;
    case '*':   result = a * b; break;
    case '/':   result = b != 0 ? a / b : 0; break;
    default:    printf("Unknown operator\n");
}
```

---

**Mental model:** `switch` is like a jump table of labeled doors; without `break;` you keep walking through the hallway.

---