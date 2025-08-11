> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]

---

## What is a `do while` loop?

A **`do while`** loop runs its body **at least once**, then repeats **while** the condition remains true.  
It’s ideal for **input validation** and situations where you must perform an action before you can test a condition.

---

## Syntax

```c
do
{
    // body
}
while (condition);
```

> Note the **semicolon after the closing `while`** — unique to `do while`.

---

## Classic input validation example

```c
int n;
do
{
    n = get_int("Number: ");
}
while (n < 1);
printf("You entered %i\n", n);
```

| Step | What happens |
|------|--------------|
| 1    | Body runs first: user is prompted. |
| 2    | Condition checked (`n < 1`). |
| 3    | If true → loop repeats; if false → exit. |

---

## Comparison with `while`

| Goal | `while` version | `do while` version | Which is clearer? |
|------|-----------------|--------------------|-------------------|
| Prompt until positive | Must duplicate initial input *before* loop or add a flag | Naturally prompts inside the loop | `do while` |
| Repeat a menu         | Needs pre-loop read | Body-first suits menus | `do while` |
| Iterate zero or more times based on condition already known | Works fine | May run unnecessarily once | `while` |

---

## When to use

Use **`do while`** when:
- You *must* execute the body **at least once** (e.g., prompt, menu, retry).
- The condition depends on **data gathered inside** the loop.

Prefer a plain **`while`** when:
- It’s acceptable that the body might **never** run.
- The condition is known **before** any work.

---

## Common pitfalls

| Mistake | Issue | Fix |
|---------|-------|-----|
| Missing semicolon after `while (cond)` | Compilation error | Add `;` |
| Using uninitialized variable in condition | Undefined behavior | Assign inside body before condition |
| Infinite loop | Condition never becomes false | Ensure loop variable changes |

---

## Pattern for menu loops

```c
int choice;
do
{
    printf("1) Play\n2) Settings\n0) Quit\n");
    choice = get_int("Choice: ");
}
while (choice != 0);
```

---

## Take-aways

- **Guarantees one execution** → perfect for validation.
- **Condition evaluated last** → fits “ask → check → maybe repeat”.
- Keep the loop body responsible for **changing** something so the condition eventually fails.

---