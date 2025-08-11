![[Screenshot 2025-07-20 at 17.56.21.png]]

> **Lecture reference:** [[Lecture 1 - C]] (CS50 Shorts – Magic Numbers)  
> **Course:** [[CS50x Harvard]]

---

## Problem: “Magic Numbers”

A *magic number* is a raw literal value (like `86400`, `0.07`, `42`) that appears in code **without context**. It forces the reader to guess what it represents (seconds per day? tax rate? buffer size?) and is hard to update consistently.

**Bad:**
```c
for (int i = 0; i < 86400; i++) { ... }   // What is 86400?
```

If you later change the concept (e.g., want hours instead of seconds) you must search and edit every `86400`—risking missed or wrong replacements.

---

## Solution: Symbolic Constants with `#define`

C’s **preprocessor** runs *before* compilation. A directive of the form:

```c
#define NAME REPLACEMENT
```

Performs a **literal text substitution**: every `NAME` token in the source (after the definition) is replaced by `REPLACEMENT` *before* the compiler proper sees the code.

**Good:**
```c
#define SECONDS_PER_DAY 86400

for (int i = 0; i < SECONDS_PER_DAY; i++) { ... }
```

Now the meaning is clear and a single edit updates all uses.

> Analogy:  
> `#include` ≈ copy–paste another file’s contents.  
> `#define` ≈ find–replace a token with a value.

---

## Why not just use a variable?

```c
const int SECONDS_PER_DAY = 86400;
```

Also works and is type-checked. Choose between them:

| Approach | When to prefer | Notes |
|----------|----------------|-------|
| `#define` | Compile-time constants needed in array sizes, preprocessor conditionals | No type; pure text substitution |
| `const` variable | General constants, want type safety & debugger visibility | Respects scope, types, can take address |

For CS50 early code, either is accepted; many modern C codebases favor `const` for type safety.

---

## Naming Conventions

- Use ALL_CAPS with underscores: `MAX_STUDENTS`, `BUFFER_SIZE`.
- Avoid generic names: `SIZE`, `VALUE`.
- Express the concept, not the value: `TAX_RATE`, not `SEVEN_PERCENT`.

---

## Scope & Order

A `#define` applies from its point of definition to the end of the translation unit (file) unless `#undef`’d.

```c
#define LIMIT 10
// LIMIT usable here
#undef LIMIT
// LIMIT no longer usable
```

---

## Common Pitfalls


| Pitfall                                    | Example                                  | Problem                                                                      | Fix                                        |
| ------------------------------------------ | ---------------------------------------- | ---------------------------------------------------------------------------- | ------------------------------------------ |
| Missing parentheses around expressions     | `#define DOUBLE(x) x + x`                | `DOUBLE(1+2)` → `1+2+1+2` (=> 6, ok by luck) but precedence issues elsewhere | `#define DOUBLE(x) ((x) + (x))`            |
| Accidental replacement inside longer names | `#define MAX 100` and variable `MAXIMUM` | `MAX` token only—safe. (Preprocessor matches tokens, not substrings.)        | –                                          |
| Trailing semicolon                         | `#define SIZE 50;`                       | Expands to `50;` inside expressions → compile errors                         | Do **not** add semicolons                  |
| Overusing macros for trivial things        | `#define ADD(a,b) ((a)+(b))`             | Functions already do this with type checking                                 | Use functions unless you need macro powers |
|                                            |                                          |                                                                              |                                            |

![[Screenshot 2025-07-20 at 18.04.31.png]]
![[Screenshot 2025-07-20 at 18.05.16.png]]




---

## Macros vs Inline Functions (preview)

For simple numeric constants: **prefer `#define` or `const`**.  
For logic with parameters: modern C might use `static inline` functions instead of function-like macros to get type checking:

```c
static inline int double_int(int x) { return x + x; }
```

---

## Quick Examples

| Goal | Macro / Const |
|------|---------------|
| Max array length | `#define MAX_LEN 256` |
| π approximation | `const double PI = 3.141592653589793;` |
| Bitmap width & height | `#define WIDTH 1920` / `#define HEIGHT 1080` |
| Buffer size derived from another | `#define HEADER_BYTES 32`<br>`#define PACKET_BYTES (HEADER_BYTES + 512)` |

---

## Checklist Before Committing

- Any unexplained literals? Replace with a named constant.
- Name communicates *what*, not *how much*.
- Chose `const` when type clarity helps (especially non-integers).
- Wrapped macro parameter usages in parentheses.

---

**Take-away:** Eliminate “magic numbers.” Name your intent once, reuse everywhere, and make future changes a one-line edit instead of a bug hunt.

---