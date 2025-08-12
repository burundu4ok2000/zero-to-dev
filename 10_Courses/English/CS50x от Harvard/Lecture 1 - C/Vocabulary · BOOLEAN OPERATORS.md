---
title: "Vocabulary · BOOLEAN OPERATORS"
status: done
date: "2025-08-12"
source: "#course/cs50x/intoduction_to_CS"
review_next: "2025-09-12"
---


## 📖 Definition  
**BOOLEAN OPERATORS** *(noun phrase)* — symbols used to perform **logical operations** that return either **true (1)** or **false (0)**.  
They are used in **conditions**, **loops**, and **decision-making** in C and most programming languages.

Boolean logic is named after **George Boole**, the mathematician who developed the system.

---

## 🔁 Boolean (Logical) Operators in C

| Symbol               | Name                 | Action                          | Example           | Result                                |
| -------------------- | -------------------- | ------------------------------- | ----------------- | ------------------------------------- |
| `&&`                 | logical AND          | true if **both** sides are true | `x > 0 && y > 0`  | true only if **x > 0** and **y > 0**  |
| \| \|                | logical OR           | true if **either** side is true | x > 0 \| \| y > 0 | true if **x > 0**, **y > 0**, or both |
| `!`                  | logical NOT          | inverts truth value             | `!true`           | false                                 |
| `==`                 | equal to             | true if values are equal        | `x == 5`          | true if x is 5                        |
| `!=`                 | not equal to         | true if values differ           | `x != 5`          | true if x is **not** 5                |
| `<`, `>`, `<=`, `>=` | comparison operators | true based on value comparison  | `x <= 10`         | true if x is less than or equal to 10 |

---

### 🔊 Pronunciation Guide

| Symbol     | Pronounced As                                       |
| ---------- | --------------------------------------------------- |
| `&&`       | "and" or "double ampersand"                         |
| \| \|      | "or" or "double pipe" \|                            |
| `!`        | "not" or "bang"                                     |
| `==`       | "equals equals"                                     |
| `!=`       | "not equal"                                         |
| `<`, `>`   | "less than", "greater than"                         |
| `<=`, `>=` | "less than or equal to", "greater than or equal to" |

---

## 📝 Quick Note  
Boolean expressions are **crucial** in programming for controlling logic and flow.  
They're often used in:

- `if`, `while`, and `for` conditions  
- `return` statements  
- `assert` checks (in debugging)

> Example:  
```c
if (score >= 90 && passed == true)
{
    printf("Excellent!\n");
}