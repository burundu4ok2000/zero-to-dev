![[Screenshot 2025-07-15 at 16.31.27.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]
---

## Basic example

```c
void meow(void)
{
    printf("meow\n");
}
```

### Parts of the definition

| Part            | In this case | Meaning                           |
|-----------------|-------------|-----------------------------------|
| **Return type** | `void`      | Function returns **nothing**      |
| **Name**        | `meow`      | Identifier you’ll use to call it  |
| **Parameters**  | `void`      | Accepts **no arguments**          |
| **Body**        | `{ … }`     | Code that runs when called        |

---

## Why create a function?

* **Avoid repetition** – write `printf("meow\n");` once, call it many times  
* **Improve readability** – `meow();` is clearer than repeating the line  
* **Encapsulate logic** – hide details inside a named block

---

## Calling the function

```c
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}
```

Output:

```
meow
meow
meow
```

---

## Notes

- You can place the function **above `main`** or declare a **prototype** before `main` and define it below.  
- Replace `void` parameters with actual types to accept input, e.g., `void meow(int times)`.

---