![[Screenshot 2025-07-19 at 21.35.58.png]]

> **Lecture reference:** [[Lecture 1 - C]] (CS50 Shorts)  
> **Course:** [[CS50x Harvard]]

---

## What is the ternary operator?

A compact, *expression* form of an `if / else`:

```c
condition ? value_if_true : value_if_false
```

It evaluates `condition`; if true, the whole expression becomes `value_if_true`, else it becomes `value_if_false`.

---

## Basic example

```c
int x;
if (expr)
{
    x = 5;
}
else
{
    x = 6;
}

// Equivalent:
int x = expr ? 5 : 6;
```

---

## Where it shines

| Situation | Example | Why |
|-----------|---------|-----|
| Simple assignment based on condition | `int min = (a < b) ? a : b;` | One readable line |
| Select a printable string | `printf("%s\n", ok ? "YES" : "NO");` | Avoids separate `if` block |
| Inline value in a larger expression | `sum += (n > 0) ? n : 0;` | Keeps flow tight |

---

## Avoid overusing

**Do NOT** nest them deeply:

```c
// Hard to read:
grade = (score >= 90) ? 'A' :
        (score >= 80) ? 'B' :
        (score >= 70) ? 'C' : 'F';

// Prefer:
if (score >= 90)      grade = 'A';
else if (score >= 80) grade = 'B';
else if (score >= 70) grade = 'C';
else                  grade = 'F';
```

---

## Expression vs statement

- Ternary returns a **value** → you can assign it, pass it, return it.
- `if / else` is a **statement** → no intrinsic value; needs separate lines.

---

## Precedence & parentheses

Ternary has **lower precedence** than most operators but higher than assignment nuances; when in doubt, wrap it:

```c
int result = (flag) ? a + b : a - b;
```

---

## Side-effect caution

Avoid executing work in both branches that alters shared state:

```c
// Risky:
flag ? push(stack, x) : push(stack, y);

// Clearer:
if (flag) push(stack, x);
else      push(stack, y);
```

---

## Quick patterns

| Goal                   | Idiomatic ternary                            |     |
| ---------------------- | -------------------------------------------- | --- |
| Clamp negative to zero | `value = (value < 0) ? 0 : value;`           |     |
| Choose sign label      | `char sign = (n < 0) ? '-' : '+';`           |     |
| Convert bool to text   | `printf(\"%s\", valid ? \"OK\" : \"FAIL\");` |     |

---

## Checklist

- Use for **simple** two-way choices producing a value.
- Skip it for multi-branch logic or side-effect-heavy code.
- Parenthesize the whole expression when mixing with `+`, `-`, etc.
- Don’t sacrifice clarity for cleverness.

---

**Mental model:** The ternary is a tiny inline “if-return” for *values*.

> The **ternary operator** is a **short, one-line version** of an if–else statement that returns **a value**, not just runs some code.


![[Screenshot 2025-07-19 at 21.48.28.png]]

Excellent — let’s decode this phrase and turn it into something crystal clear and actionable:

### **⚙️ Examples**

```
int age = 18;
string result = (age >= 18) ? "adult" : "minor";
// result now holds "adult"
```

Compare that to the longer form:

```
string result;
if (age >= 18)
    result = "adult";
else
    result = "minor";
```

Same outcome — but longer.

---

### **✅ Why the word** 

### **“values”**

###  **is key:**

  

Ternary operators **don’t run blocks of code**.

They **evaluate to a value**.

  

So you can use them like this:

```
printf("%s", is_ok ? "Yes" : "No");
```

But **not** like this:

```
// ❌ INVALID (ternary can't run full statements)
is_ok ? do_something() : log_error();
```

---

### **🧠 Final mental model:**

  

> Think of it as:

> _“If this is true — give me this value; otherwise — give me that one.”_

> _(Not: do this block of code or that one.)_