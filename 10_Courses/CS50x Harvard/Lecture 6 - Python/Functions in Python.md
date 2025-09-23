---
title: Functions in Python
note_type: concept
lang: en
course: CS50x 2025
lecture: 6
tags:
status: in-progress
difficulty: easy
effort_min: 25
time_spent_min: 0
created: 2025-09-23
source:
  - https://cs50.harvard.edu/x/2025/
related:
  - "[[Truncation vs Floor Division vs True Division — f-string Precision]]"
review_next: 2025-09-25
---
# Python Functions — Basics & Tips

Quick guide to defining and calling functions in Python, with CS50-friendly examples.

## TL;DR
- Define with `def name(params):` and indent the body.
- Return a value with `return` (implicit `None` if omitted).
- Parameters support defaults, keyword args, variable-length `*args` and `**kwargs`.
- Use docstrings and type hints for clarity.
- Functions are first-class: pass them around like values.

## Core syntax
```python
def greet(name: str) -> str:
    """Return a friendly greeting."""
    return f"Hello, {name}!"

print(greet("Yuliia"))  # Hello, Yuliia!
```

### Parameters & calling styles
```python
def power(base: float, exp: int = 2) -> float:   # default argument
    return base ** exp

power(3)            # 9  (uses default exp=2)
power(2, exp=5)     # 32 keyword argument
```

### Variable-length parameters
```python
def mean(*nums: float) -> float:        # *args: tuple of positional values
    return sum(nums) / len(nums) if nums else 0.0

def describe(**attrs):                  # **kwargs: dict of keyword values
    return ", ".join(f"{k}={v}" for k, v in attrs.items())

mean(1, 2, 3)           # 2.0
describe(role="TA", course="CS50")  # role=TA, course=CS50
```

### Multiple returns (tuple unpacking)
```python
def divmod_safe(a: int, b: int):
    if b == 0:
        return None, "division by zero"
    return a // b, None

q, err = divmod_safe(10, 3)   # (3, None)
```

### Scope (local vs global)
```python
counter = 0

def tick():
    global counter   # avoid unless necessary
    counter += 1
```

### Docstrings (help) & annotations
```python
def area(r: float) -> float:
    """Compute circle area for radius r."""
    from math import pi
    return pi * r * r

help(area)     # shows the docstring
area.__annotations__  # {'r': float, 'return': float}
```

## Idioms you’ll use early
- [[Comprehension]] + functions:
```python
def is_even(n: int) -> bool: return n % 2 == 0
evens = [n for n in range(10) if is_even(n)]
```
- Small one-liners with `lambda` (anonymous functions):
```python
square = lambda x: x * x
list(map(square, range(5)))  # [0, 1, 4, 9, 16]
```
- [[Context manager]] + helper:
```python
def read_lines(path: str) -> list[str]:
    with open(path) as f:    # file closes automatically
        return [line.rstrip("\n") for line in f]
```

## Common pitfalls
- Forgetting the colon `:` after the function header.
- Mixing tabs/spaces — always use 4 spaces for indentation.
- Mutating default arguments (e.g., `def f(x, acc=[])`) — use `None` and create inside:
```python
def f(x, acc=None):
    if acc is None:
        acc = []
    acc.append(x)
    return acc
```

## Minimal checklist
- Clear name (`verb_noun`), short docstring, type hints.
- Single responsibility; return values vs printing side-effects.
- Add tests in an `if __name__ == "__main__":` block when useful.

---
## Related Concepts
- [[Syntactic sugar]]
- [[Ternary expression]]
- [[Comprehension]]
- [[Context manager]]
- [[Enumerate]]

## See Also
- [[List — basics]]
- [[Dictionaries — basics]]
- [[Tuples — basics]]
- [[Pathlib]]
- [[for-else]]

## Terms used
[[Function]], [[Parameter]], [[Argument]], [[Return value]], [[Docstring]], [[Type hint]], [[Scope]], [[Lambda]], [[Tuple]]
