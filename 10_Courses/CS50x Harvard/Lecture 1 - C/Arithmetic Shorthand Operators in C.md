---
title: "Arithmetic Shorthand Operators in C"
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 05
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-19 at 13.34.33.png]]

## **One-liner
**Shorthand (compound) assignment** operators update a variable *in place* (e.g., **x += 5**) and **increment/decrement** operators adjust by 1 (**++x**, **x--**)—cleaner than repeating the name on both sides of **=**.

## The Big Idea 

- Use **compound assignment** (**+=**, **-=**, **\*=**, **/=**, **%=**) to express “take current value, apply an operation, store back” without boilerplate.
- Use **pre-increment** (**++i**) or **post-increment** (**i++**) when stepping counters; the difference matters only *inside larger expressions* because of **evaluation order** and **side effects**.
- Prefer forms that make intent obvious and avoid clever chains that harm **readability**.

## Key Characteristics 

- **In-place update**: `x += 5;` is equivalent to `x = x + 5;` but shorter and idiomatic.
- **Type semantics**: With **ints**, `/=` does **integer division** (truncation). Cast to **float**/**double** when needed.
- **Operator family**: All arithmetic compound ops exist (+=, -=, \*=, /=, %=). Bitwise variants (<<=, >>=, &=, \|=, ^=) follow the same pattern.
- **++ / --**: Unary operators that add/subtract **1**; **pre** form yields the updated value, **post** form yields the old value.
- **Order of evaluation**: In C, compound assignments sequence the **write** after evaluating both sides; misuse in complex expressions can surprise.

## Examples 

### Long form vs shorthand
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

### Increment and decrement
```c
x = x + 1;
x += 1;
x++;      // post-increment

x = x - 1;
x -= 1;
x--;      // post-decrement

// Pre vs post in an expression
int i = 3;
printf("%d %d\n", ++i, i); // prints 4 4  (pre: value is incremented, then used)
i = 3;
printf("%d %d\n", i++, i); // prints 3 4  (post: old value used, then incremented)
```

### Common patterns
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
pos = (pos + 1) % capacity;   // or: pos += 1; pos %= capacity;
```

### Pitfalls
| Mistake | Why it’s a problem | Fix |
|---------|--------------------|-----|
| `x =+ 5;` | Assigns **+5** to `x` (typo) | `x += 5;` |
| `x /= 5;` when `x` is `int` | **Truncates** (integer division) | `x = (float)x / 5;` |
| `%=` on non-integers | `%` is undefined for `float`/`double` in C | Use integral types only |
| Chaining like `a += b += 2;` | Confusing and order-sensitive | Split into clear steps |

## **Why It Matters**

- Express intent with minimal noise; fewer chances to **mistype** repeated identifiers.
- Idiomatic in loops and **accumulators**, reduces **cognitive load** and makes **reviews** easier.

## Related Concepts

- [[Arithmetic Operators in C]] – contrasts **simple arithmetic** with **compound assignment**.
- [[Increment and Decrement in C]] – deeper dive into **pre** vs **post** forms and side effects.
- [[Operator Precedence in C]] – how **+=**, **++**, and friends bind in expressions.
- [[Integer Division in C]] – why `/=` can silently **truncate** and how to cast.
- [[Assignment Operators in C]] – full catalog including **bitwise** compound ops.

## See Also

- [C assignment operators — cppreference](https://en.cppreference.com/w/c/language/operator_assignment)
- [C increment/decrement — cppreference](https://en.cppreference.com/w/c/language/operator_incdec)
- [CS50x 2025 – Week 1: C](https://cs50.harvard.edu/x/2025/weeks/1/)

## Terms

[[operator]], [[compound assignment]], [[shorthand operator]], [[increment operator]], [[decrement operator]], [[pre-increment]], [[post-increment]], [[modulus]], [[integer division]], [[type cast]], [[side effect]], [[loop counter]], [[expression]]
