---
title: "Get Positive Int Abstraction"  
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: ""
atom_idx: 18
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-15 at 20.26.19.png]]
![[Screenshot 2025-07-15 at 20.29.20.png]]
![[Screenshot 2025-07-15 at 20.32.00.png]]
![[Screenshot 2025-07-15 at 20.32.06.png]]

---

## **One-liner**

Use **Abstraction** to isolate **Input validation** with a **do while** loop inside a helper **Function**, so `main` reads like pseudocode and stays clean.

---

## 1 · The problem

You want the user to enter a **positive** integer `n` and then print `"meow"` `n` times. A naïve approach nests `if` statements or loops inside loops — it “works” but is painful to read and maintain.

```c
int n = get_int("Number: ");
if (n < 1)
{
    int n = get_int("Number: ");
    if (n < 1)
    {
        int n = get_int("Number: ");
        // ...
    }
}
meow(n);
```

**Why this is bad design**: deep nesting, repeated prompts, and mixed concerns (validation + work) inside `main`.

---

## 2 · First improvement — **do while**

```c
int n;
do
{
    n = get_int("Number: ");
}
while (n < 1);
meow(n);
```

**Benefits**

- Runs the prompt **at least once** (fits validation).  
- Condition at the **end** keeps the prompt in the loop body.  
- No deep nesting; code stays flat and readable.

---

## 3 · Final abstraction — helper **Function**

```c
int get_positive_int(void);   // prototype
void meow(int n);             // prototype

int main(void)
{
    int times = get_positive_int();
    meow(times);
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    return n;
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

### What improved?

| Aspect      | Before (inline)       | After (`get_positive_int`) |
|------------|------------------------|----------------------------|
| Validation | Inside `main`          | Encapsulated in a function |
| Readability| Mixed responsibilities | `main` reads like steps    |
| Reusability| Tied to one file       | Any program can call it    |
| Testing    | Hard to isolate        | Unit-testable helper       |

---

## Key take-aways

1. **Abstraction** — move repetitive or detailed logic into **named functions**.  
2. **do while** — use when the body must run **at least once**, then decide to repeat.  
3. **Prototype** — declare functions (e.g., `int get_positive_int(void);`) above `main` so the compiler knows their **Signature**.  
4. **Scope** — variables like `times`, `n`, and loop counter `i` live only where they are declared.  
5. **Return types** — functions that compute values should **return** them; printing-only helpers can be **void**.

## Related Concepts

- [[Do While Loop in C]] – body-first loop ideal for validation.
- [[Function Prototype in C]] – declare interfaces before use.
- [[Function Definition in C]] – implement helpers cleanly.
- [[Function Parameter in C]] – pass data into helpers.
- [[Function Signatures in C]] – keep declarations and definitions in sync.
- [[Input Validation in C]] – patterns for safe user input.
- [[Refactoring Techniques in C]] – extract and name things.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)
- [cppreference — Iteration statements](https://en.cppreference.com/w/c/language/iteration_statements)
- [cppreference — Function declaration](https://en.cppreference.com/w/c/language/function_declaration)

## Terms

[[abstraction]], [[input validation]], [[do while]], [[function]], [[prototype]], [[signature]], [[scope]], [[return type]], [[unit test]], [[loop]], [[for loop]], [[while loop]]
