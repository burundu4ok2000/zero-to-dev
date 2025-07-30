![[Screenshot 2025-07-17 at 10.57.20.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]
> [[Arithmetic Shorthand Operators in C]]

---

| Operator | Name          | Example (`x = 6`, `y = 4`) | Result | Notes                               |
|----------|--------------|-----------------------------|--------|-------------------------------------|
| `+`      | Addition      | `x + y`                    | `10`   | Also used for string concatenation in some languages, **not** in C. |
| `-`      | Subtraction   | `x - y`                    | `2`    | Unary `-` flips sign (`-x`).        |
| `*`      | Multiplication| `x * y`                    | `24`   | Same precedence as `/` and `%`.     |
| `/`      | Division      | `x / y`                    | `1`    | **Integer division** truncates toward zero; `6 / 4` → `1`. |
| `%`      | Remainder (modulus) | `x % y`              | `2`    | Gives the remainder of integer division; useful for “even/odd” checks. |

---

### Quick tips

* Use `float` or `double` variables if you need **fractional** results from division (`6.0 / 4.0` → `1.5`).  
* Operator **precedence**: `*`, `/`, `%` bind more tightly than `+` and `-`, but you can always add parentheses to be explicit.  
* `%` works only with integers in C.

---

### Mini demo

```c
int x = 6;
int y = 4;
printf("%i + %i = %i\n", x, y, x + y);  // 10
printf("%i - %i = %i\n", x, y, x - y);  // 2
printf("%i * %i = %i\n", x, y, x * y);  // 24
printf("%i / %i = %i\n", x, y, x / y);  // 1
printf("%i %% %i = %i\n", x, y, x % y); // 2
```

---

Keep this table handy while building calculator or mod-based programs in CS50 labs.