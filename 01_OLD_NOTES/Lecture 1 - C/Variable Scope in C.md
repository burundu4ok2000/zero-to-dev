![[Screenshot 2025-07-15 at 17.23.18.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]

---

## Example

```c
#include <cs50.h>
#include <stdio.h>

void meow(int n);          // prototype

int main(void)
{
    int n = get_int("Number: ");   // n lives only inside main
    meow(n);
}

void meow(int n)           // parameter n lives only inside meow
{
    for (int i = 0; i < n; i++)    // i lives only inside the loop
    {
        printf("meow\n");
    }
}
```

---

## What “scope” means - "область видимости"

| Level                 | Variables visible | Lifetime                 |
|-----------------------|-------------------|--------------------------|
| **Function scope**    | `n` in `main`, `n` in `meow` | From entry to exit of the function |
| **Block scope**       | `i` in the `for` loop        | From `{` to matching `}`           |
| **File / global scope** | (none here)                | Entire program run                |

* A name is **only accessible** inside the braces `{ … }` where it is declared.  
* Re-using the same name (`n`) in two functions is legal; they are **distinct variables**.  
* Passing `n` to `meow(n)` copies its value — the two `n`s do **not** share memory.

---

## Why scope matters

* **Prevents collisions** between unrelated variables in different functions.  
* **Keeps data private** to the part of code that needs it.  
* Helps the compiler catch errors when you accidentally reference a variable outside its lifetime.

---

### Quick rules

1. Declare variables **as close** as possible to where they’re used.  
2. Prefer **function parameters** for input, not global variables.  
3. Remember that loop counters like `i` vanish after the loop ends.

---