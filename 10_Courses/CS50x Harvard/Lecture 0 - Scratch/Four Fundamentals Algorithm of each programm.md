---
title: "Four Fundamentals Algorithm of each programm"  
lang_tags: "#lang/scratch"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: "#tool/scratch"
atom_idx: 02
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/0/"
review_next: ""
---

## **One-liner**

Every program is built from four core ideas: **Functions**, **Conditionals**, **Booleans**, and **Loops** — whether you’re in **Scratch** blocks or **Python/C**.

## Big picture

- **Functions** (a.k.a. **procedures**) package a task behind a **name** so you can **call** it.  
- **Conditionals** choose a path based on a **Boolean expression**.  
- **Booleans** are questions that evaluate to **true/false** and feed decisions.  
- **Loops** repeat steps until a **condition** changes.

These four snap together like LEGO in Scratch — then scale to text languages the same way.

## Mini-examples

### Scratch vibes (pseudocode-ish)

```
when green flag clicked
if <age >= 18> then
  say [Welcome!]
else
  say [Come back later]
end
repeat (10)
  move (10) steps
end
```

### Quick Python mirrors

```python
def greet(name):                  # Function
    print(f"Hello, {name}!")

is_even = (n % 2 == 0)            # Boolean
if is_even:                        # Conditional
    greet("Stas")

for i in range(10):               # Loop
    pass
```

## Mental recipe

1. Break the problem into **functions** (verbs: do/compute/make).  
2. Inside each function, use **booleans** to ask questions.  
3. Branch with **conditionals**.  
4. Iterate with **loops**.

## Quick table

| **#** | **Concept**        | **Core idea**                            | **Scratch block / Python hint** |
|------:|--------------------|------------------------------------------|----------------------------------|
| 1 | **Function**         | Package a task; call by **name**         | `define do-thing` / `def foo()`  |
| 2 | **Conditional**      | Choose a path                            | `if <...> then` / `if ...:`      |
| 3 | **Boolean**          | Question → **true/false**                 | `<x > y>` / `x > y`              |
| 4 | **Loop**             | Repeat until a rule changes              | `repeat (N)` / `for/while`       |

## Common pitfalls

- Nesting conditionals and loops too deeply — extract a **helper function**.  
- Confusing **assignment** with **comparison** (`=` vs `==` in text languages).  
- Off‑by‑one errors in **loops**; in Scratch, `repeat (N)` runs N times.  
- Using magic numbers; name them with a **constant** (even in Scratch via variables).

## Related Concepts

- [[Artificial Intelligence · CS50x Week 0]] – context for Week 0 problems and mindset.  
- [[Scratch Blocks — Control]] – `if`, `repeat`, `forever` building blocks.  
- [[Boolean Expression]] – the questions that drive logic.  
- [[Functions/Procedures in Scratch]] – `define` and `call` patterns.  
- [[Algorithm vs Program]] – planning vs implementation.

## See Also

- [CS50x 2025 — Week 0 overview](https://cs50.harvard.edu/x/2025/weeks/0/)  
- [Scratch — Getting started](https://scratch.mit.edu/ideas)  
- [Khan Academy — Intro to algorithms](https://www.khanacademy.org/computing/computer-science/algorithms)

## Terms

[[function]], [[procedure]], [[conditional]], [[boolean]], [[boolean expression]], [[loop]], [[repeat]], [[if/else]], [[helper function]], [[constant]], [[scratch]], [[algorithm]]
