![[Screenshot 2025-07-15 at 17.11.14.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]
> [[Function Definition in C]] [[Function Parameter in C]] [[Function Prototype in C]]

---

## 1 · Single call, inline definition

```c
#include <stdio.h>

int main(void)
{
    printf("meow\n");
}
```

### Traits  
* No function at all — logic lives directly in `main`.  
* Fine for one-off output but not reusable.

---

## 2 · Reusable function, defined above `main`

```c
#include <stdio.h>

void meow(void)          // definition first
{
    printf("meow\n");
}

int main(void)
{
    meow();              // call site
}
```

### Traits  
* `void meow(void)` returns nothing, takes nothing.  
* `main` can call it many times; compiler already “knows” the function because it appears earlier in the file.

---

## 3 · Reusable function, defined **below** `main` with prototype

```c
#include <stdio.h>

void meow(void);         // ← prototype (promise)

int main(void)
{
    meow();              // OK: compiler trusts the prototype
}

void meow(void)          // full definition after main
{
    printf("meow\n");
}
```

### Traits  
* Prototype declares return type & parameters ahead of use.  
* Keeps `main` near the top for readability.

---

## 4 · Parameterized function

```c
#include <stdio.h>

void meow(int n);        // prototype

int main(void)
{
    meow(3);             // caller decides how many
}

void meow(int n)         // takes an argument
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

### Traits  
* Adds flexibility via the parameter `int n`.  
* Same prototype/definition pattern; just updated signature.

---

## Key take-aways

| Version | Pros | Cons |
|---------|------|------|
| Inline print | Quick, minimal | Not reusable |
| Function above `main` | Reusable, no prototype needed | Pushes `main` down the file |
| Prototype + definition below | Keeps `main` on top, still reusable | Must keep prototype & definition in sync |
| Parameterized | Fully flexible | Slightly more code |

Using **prototypes** lets you organise code freely, and **parameters** turn one-purpose helpers into general-purpose tools — both fundamental steps toward clean, modular C programs.

---