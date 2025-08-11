![[Screenshot 2025-07-19 at 20.45.13.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]

---

## What this pattern looks like

```c
if (cond1)
{
    // branch 1
}
if (cond2)
{
    // branch 2
}
if (cond3)
{
    // branch 3
}
else
{
    // branch 4
}
```

Only the **last** `if` is paired with the `else`. The first two `if` statements are **independent** tests.

---

## Execution model

1. Evaluate `cond1`. If true → run branch 1.
2. Evaluate `cond2`. If true → run branch 2.
3. Evaluate `cond3`.  
   * If true → run branch 3.  
   * If false → run the `else` (branch 4).

Branches 1 and 2 do **not** block each other. They can both run, one, or neither—regardless of what happens with `cond3`.

---

## When (rarely) to use

| Use case | Why it might be acceptable |
|----------|----------------------------|
| Multiple *independent* side-effects plus a final mutually exclusive choice | Earlier conditions don’t preclude each other |
| Logging / accumulating flags, then a final fallback action | Prior `if`s collect state |
| Translating a truth table literally for clarity | Mirrors documentation exactly |

---

## Common misunderstanding

Developers sometimes *intend* this:

```c
if (cond1) { … }
else if (cond2) { … }
else if (cond3) { … }
else { … }
```

…but accidentally write independent `if`s. Result: more than one block executes unexpectedly.

---

## How to refactor

| Intention | Safer structure |
|-----------|-----------------|
| Exactly one branch should run | `if / else if / else` chain |
| Possibly many branches run | Separate `if` statements (no trailing `else`) |
| Mutually exclusive categories | Switch statement (if comparing one variable) |

---

## Visual

```
cond1? → branch1 (independent)
cond2? → branch2 (independent)
cond3? → branch3 else → branch4 (mutually exclusive pair only)
```

---

## Anti-pattern warning

If you see:

```c
if (score >= 90) { grade = 'A'; }
if (score >= 80) { grade = 'B'; }
if (score >= 70) { grade = 'C'; }
else { grade = 'F'; }
```

A score of 95 sets grade to 'A' *then* overwrites it with 'B'. Use a ladder:

```c
if (score >= 90)       grade = 'A';
else if (score >= 80)  grade = 'B';
else if (score >= 70)  grade = 'C';
else                   grade = 'F';
```

---

## Checklist

- Ask: *Can more than one branch run?* If **no**, use `else if`.
- Ensure the `else` is attached to the intended `if` (brace formatting helps).
- Don’t mix independent `if`s with a single `else` unless you **want** that pairing.

---