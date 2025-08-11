[[Lecture 1 - C]]
[[CS50x Harvard]]

Even after casting, floating‑point math has a _hard_ ceiling on accuracy because a computer uses only a fixed number of bits to store any real number.

### Key points

- **Finite bits ≠ infinite digits** – single precision (32‑bit) and double precision (64‑bit) can represent only a subset of real numbers.
    
- **Imperfect fractions** – a value like 1 / 3 becomes an approximation (`0.33333334` in `float`, `0.33333333333333331`in `double`). The more digits you print, the clearer the error.
    
- **More bits help, but don’t solve** – double precision just pushes the rounding error further out.
    
- **Why it’s inevitable** – there are infinitely many real numbers but only 2^32 or 2^64 bit patterns.
    
- **Real‑world impact** – financial apps, scientific simulations, even games must account for rounding error.
    

### Mitigation strategies (starter list)

| Need                          | Possible solution                                         |
| ----------------------------- | --------------------------------------------------------- |
| Exact decimal math (finance)  | Use fixed‑point libraries or `decimal` types              |
| Arbitrary precision (science) | GMP / MPFR, Python’s `decimal`, or languages like Julia   |
| Robust comparisons            | Compare floats with an **epsilon** margin instead of `==` |

> **Rule of thumb:** treat floating‑point numbers as _approximations_. Design algorithms that tolerate tiny errors rather than assuming perfect arithmetic.