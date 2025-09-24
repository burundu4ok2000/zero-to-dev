---
title: Ternary Operator in C (condition ? value_if_true value_if_false) 
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 32
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/1/
review_next: ""
---

  

![[Screenshot 2025-07-19 at 21.35.58.png]]

![[Screenshot 2025-07-19 at 21.48.28.png]]

  

---

  

## **One-liner**

  

The **ternary operator** is a compact **expression** form of **if/else** that chooses **one value** or **the other** based on a **condition**.

  

## Syntax

  

```c

condition ? value_if_true : value_if_false

```

  

The whole thing **evaluates to a value**; you can assign it, pass it to a function, or `return` it.

  

## Tiny examples

  

```c

int min = (a < b) ? a : b;

char sign = (n < 0) ? '-' : '+';

printf("%s\\n", ok ? "YES" : "NO");

```

  

Equivalent long form for one of them:

  

```c

int min;

if (a < b) min = a;

else       min = b;

```

  

## When to use (and when not)

  

- Use it for **simple two-way value selection** that fits on one readable line.  

- Avoid it for **multi-branch** logic or when branches involve **side effects** (mutating state, I/O). Prefer **if/else** in those cases.

  

## Precedence & parentheses

  

The ternary has low **precedence** (binds weaker than `+`, `-`, etc., but interacts with assignment). When mixing with other operators, **parenthesize** to be explicit:

  

```c

int result = flag ? (a + b) : (a - b);

```

  

## Common pitfalls

  

- **Nesting** multiple ternaries hurts readability. Expand to an **if/else** ladder instead.  

- Using it for **statements** (work with side effects) rather than **values** makes code opaque.  

- Comparing **floats** with \`\=\=\` inside the condition can be fragile — prefer an **epsilon** comparison.

  

## Patterns you’ll actually use

  

| Goal                | Snippet                                   |
| ------------------- | ----------------------------------------- |
| Clamp negative to 0 | `value = (value < 0) ? 0 : value;`        |
| Pick label          | `char level = (score >= 60) ? 'P' : 'F';` |
| Choose pointer      | `node *best = prefer_a ? a : b;`          |

  

## Related Concepts

  

- [[Conditionals Overview in C]] – when to choose **if**, **switch**, or **ternary**.  

- [[If Statement Design in C]] – exclusive vs independent branches.  

- [[Switch Statement in C]] – discrete multiway branching.  

- [[Operator Precedence in C]] – why parentheses help here.  

- [[Post vs Pre Increment in C]] – another precedence gotcha in expressions.  

- [[printf Format Specifiers]] – printing values selected by a ternary.

  

## See Also

  

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  

- [cppreference — Conditional operator `?:`](https://en.cppreference.com/w/c/language/conditional)  

- [C FAQ — Why not use the ternary for statements?](https://c-faq.com/expr/condop.html)

  

## Terms

  

[[ternary operator]], [[conditional operator ?:]], [[condition]], [[expression]], [[value selection]], [[precedence]], [[parentheses]], [[side effect]], [[assignment]], [[branching]]
