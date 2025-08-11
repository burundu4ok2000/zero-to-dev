![[Screenshot 2025-07-15 at 17.06.01.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]
[[Function Prototype in C]]
[[Function Definition in C]]
---

## Parameterised version of `meow`

```c
void meow(int n)          // takes an int argument
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

### Calling it

```c
int main(void)
{
    meow(3);              // prints "meow" three times
}
```

---

## What changed from the previous version?

| Aspect          | Old function           | New function          |
|-----------------|------------------------|-----------------------|
| Parameters      | `void meow(void)` — none | `void meow(int n)` — accepts **n** |
| Flexibility     | Fixed output (always 1) | Prints as many times as caller specifies |
| Prototype       | `void meow(void);`      | `void meow(int n);`   |
| Loop variable   | Hard-coded `3` or `while` | Uses `n` in the loop condition |

---

## Why use parameters?

* **Reuse** – same function works for any number of meows  
* **Clarity** – caller decides the count: `meow(5)`, `meow(10)`  
* **Maintainability** – no need to edit the function to change its behaviour

---

## Notes

- A prototype (`void meow(int n);`) must appear before `main` if the definition is below.  
- You can add more parameters later (e.g., `char *word`) to generalise further.

---