![[Screenshot 2025-07-15 at 16.56.19.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]
> [[Function Definition in C]]

---

## Why add a prototype?

C is compiled **top-to-bottom**.  
If `main` calls a function that the compiler hasn’t “seen” yet, it doesn’t know the function’s name, return type, or parameters.  
A **prototype** is a one-line **promise** you put above `main` so the compiler can proceed with confidence.

---

## Example

```c
#include <cs50.h>
#include <stdio.h>

void meow(void);          // ← prototype

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();           // compiler already knows it exists
    }
}

void meow(void)           // full definition, can live below
{
    printf("meow\n");
}
```

---

## Anatomy of the prototype

| Piece          | In example | Meaning                                  |
|----------------|------------|------------------------------------------|
| Return type    | `void`     | Function returns nothing                 |
| Name           | `meow`     | Identifier you’ll call                   |
| Parameter list | `(void)`   | Takes no arguments                       |
| Semicolon      | `;`        | Ends the declaration (no body here)      |

---

## Key points

* **One line, no braces** – ends with `;`
* Tells the compiler: *“Trust me, a function named `meow` exists and looks like this.”*
* Put prototypes **before `main`** or in a **header file** (`.h`) and `#include` it.

---

## What happens if you skip it?

```c
int main(void)
{
    meow();     // ❌ compile-time error: implicit declaration
}
```

The compiler can’t verify the call, leading to warnings or errors.

---

## Best practice

1. **Prototype first** – either at the top of the `.c` file or in a `.h` header.
2. **Define later** – full function body below `main` or in another `.c` file.
3. Keep prototypes and definitions **in sync**; mismatches will trigger errors.

---

Using prototypes keeps your code organized and lets `main` appear earlier in the file, improving readability without confusing the compiler.