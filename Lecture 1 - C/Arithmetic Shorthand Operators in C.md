![[Screenshot 2025-07-19 at 13.34.33.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]
> [[Lecture 1 - C/Arithmetic Operators in C]]

---

## Purpose

Shorthand operators let you update a variable *in place* without repeating its name on both sides of `=`. They improve readability and reduce noise.

---

## Long form vs shorthand

```c
// Addition
x = x + 5;
x += 5;

// Subtraction
x = x - 5;
x -= 5;

// Multiplication
x = x * 5;
x *= 5;

// Division (integer division if x is int)
x = x / 5;
x /= 5;

// Remainder (modulus)
x = x % 5;
x %= 5;
```

---

## Increment and decrement

```c
x = x + 1;
x += 1;
x++;      // post-increment

x = x - 1;
x -= 1;
x--;      // post-decrement
```

> `++x` (pre-increment) and `x++` (post-increment) both add 1 to `x`; the difference only matters *inside larger expressions*.

---

## When to use which form

| Situation | Preferred form | Rationale |
|-----------|----------------|-----------|
| Simple constant adjustment | `x += 5;` | Clear & concise |
| Loop counter +1            | `i++`     | Idiomatic C |
| Variable step size         | `i += step;` | Shows intent |
| Multiply/scale             | `value *= factor;` | Communicates “scale” visually |
| Mod cycling                | `index %= size;` | Emphasizes wrap-around logic |

---

## Common patterns

```c
// Accumulate a running total
total += amount;

// Scale a value
score *= 2;

// Halve until small enough
while (n > limit)
{
    n /= 2;
}

// Wrap an index (circular buffer)
pos = (pos + 1) % capacity;   // or pos = (pos + 1); pos %= capacity;
```

---

## Pitfalls

| Mistake | Why it’s a problem | Fix |
|---------|--------------------|-----|
| `x =+ 5;` | This assigns `+5` to `x` (typo) | Use `x += 5;` |
| Forgetting integer division | `x /= 5;` truncates if `x` is `int` | Cast first: `x = (float)x / 5;` |
| Using `%=` with non-integers | `%` undefined for `float`/`double` in C | Only use with integral types |
| Chaining like `a += b += 2;` | Hurts readability; order can confuse | Split into lines |

---

## Readability rule

> If the shorthand is immediately obvious to a beginner, use it. If it makes someone pause, expand it.

---

## Quick checklist

- Prefer `+=`, `-=`, `*=`, `/=`, `%=` for constant or simple variable updates.
- Use `++` / `--` for single-step loop counters.
- Avoid clever chains; keep expressions clear.
- Remember integer vs floating division.

---