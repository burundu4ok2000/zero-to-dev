
> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]

---

## 1 · The problem

You want the user to enter a **positive** integer `n` and then print `"meow"` `n` times.

A naïve approach nests `if`-statements or loops inside loops, quickly becoming messy:
![[Screenshot 2025-07-15 at 20.26.19.png]]
```c
int n = get_int("Number: ");
if (n < 1)
{
    int n = get_int("Number: ");
    if (n < 1)
    {
        int n = get_int("Number: ");
        …
    }
}
meow(n);
```

David Malan calls this “correct but bad design” — hard to read, easy to break.

---

## 2 · First improvement — `do … while`
![[Screenshot 2025-07-15 at 20.29.20.png]]
```c
int n;
do
{
    n = get_int("Number: ");
}
while (n < 1);
meow(n);
```

**Why it’s better**

| Feature | Benefit |
|---------|---------|
| `do … while` runs **at least once** | Perfect for input validation loops |
| Condition at the **end** | Keeps the prompt inside the loop body |
| No deep nesting | Code stays flat and readable |

---

## 3 · Final abstraction — helper function
![[Screenshot 2025-07-15 at 20.32.00.png]]
![[Screenshot 2025-07-15 at 20.32.06.png]]
```c
int get_positive_int(void);   // prototype
void meow(int n);             // prototype

int main(void)
{
    int times = get_positive_int();
    meow(times);
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    return n;
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

### What changed?

| Aspect        | Before            | After (`get_positive_int`) |
|---------------|-------------------|----------------------------|
| Validation    | Inline in `main`  | Encapsulated in its own function |
| Readability   | Mixed concerns    | `main` now reads like pseudocode |
| Reusability   | Tied to one file  | Any program can call `get_positive_int()` |
| Testing       | Hard              | Function can be unit-tested separately |

---

## Key take-aways from the lecture

1. **Abstraction** – Move repetitive or detailed logic into well-named functions.  
2. **do while** – Use when you must run a block **at least once**, then decide if you should repeat.  
3. **Prototypes** – Declare functions above `main` (`int get_positive_int(void);`) so the compiler knows their signatures.  
4. **Scope** –  
   * `times` lives only inside `main`.  
   * `n` inside `get_positive_int` is a separate variable.  
   * Loop counter `i` lives only inside the `for` block.  
5. **Return types matter** – `int get_positive_int(void)` returns the validated number; `void meow(int n)` returns nothing because printing is a side-effect.

---

By isolating input validation in one function and output in another, the program becomes cleaner, safer, and easier to modify — exactly the