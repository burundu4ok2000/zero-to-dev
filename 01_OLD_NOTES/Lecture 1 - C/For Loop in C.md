> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]
![[Screenshot 2025-07-15 at 16.16.34.png]]
---

## Basic example

```c
for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}
```

### Output

```
meow
meow
meow
```

---

## Why use a `for` loop?

The `for` loop is often preferred when:

- You **know in advance** how many times to loop
- You're working with **counters** or array **indexes**
- You want a **compact** syntax with all loop parts in one line

---

## Structure breakdown

```c
for (initialization; condition; update)
```

| Part          | In this case         | What it does                            |
|---------------|----------------------|------------------------------------------|
| Initialization | `int i = 0`          | Runs **once** before the loop starts     |
| Condition      | `i < 3`              | Checked **before each** loop iteration   |
| Update         | `i++`                | Runs **after each** iteration            |

---

## Same logic using `while`

```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```

✅ Works the same, but takes **more lines**

---

## When to use `for` vs `while`

| Use `for` when…                          | Use `while` when…                       |
|------------------------------------------|------------------------------------------|
| You have a known loop count (`0 to N`)   | You’re waiting for something to happen (user input, condition met) |
| You want tight, readable loop headers    | The exit condition is more complex       |
| You’re working with arrays/lists         | You’re looping indefinitely or conditionally |

---

## Notes

- The variable `i` in `for (int i = …)` is **scoped to the loop** — you can’t access it after the loop ends
- You can also loop **backwards**: `for (int i = 3; i > 0; i--)`

--- 

The `for` loop is a **concise and readable way** to do counting loops — it’s the go-to tool in most C programs when iterating a known number of times.