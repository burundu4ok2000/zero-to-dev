---
title: Looping Dicts & Printing — items(), values(), .format, f-strings
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 23
status: in-progress
difficulty: easy
date: 2025-09-23
timecode: 00:21:45–00:24:30
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

## One Liner
Iterate **dict**s cleanly with **items()** and print with **f-strings**; use **values()** for just values and prefer sorted output when order matters.

## TL;DR
- `for key in d:` → keys
- `for key, value in d.items():` → pairs (**unpacking**)
- `for value in d.values():` → values
- Prefer **f-strings**: `f"pizza {pie} costs ${price}"` over `.format()` or `%` formatting.

## Examples (from slides, polished)
```python
pizzas = {"cheese": 9, "pepperoni": 10, "vegetable": 11, "buffalo chicken": 12}

# 1) Iterate keys (default)
for pie in pizzas:
    print(pie)                     # cheese, pepperoni, ...

# 2) Iterate values
for price in pizzas.values():
    print(price)                   # 9, 10, 11, 12

# 3) Iterate pairs (tuple unpacking)
for pie, price in pizzas.items():
    print(f"A whole {pie} pizza costs ${price}")
```

## Order notes
Python 3.7+ preserves **insertion order** for dicts. Still, if your output must be deterministic (tests, docs), sort:
```python
for pie, price in sorted(pizzas.items()):            # sort by key
    print(pie, price)

for pie, price in sorted(pizzas.items(), key=lambda kv: kv[1]):
    print(pie, price)                                 # sort by value
```

## Printing styles (and why to prefer f-strings)
```python
pie, price = "cheese", 9

# old printf-style (avoid for new code)
print("A whole %s pizza costs $%d" % (pie, price))

# str.format (ok, verbose)
print("A whole {} pizza costs ${}".format(pie, price))

# f-strings (concise, readable, fast; Python 3.6+)
print(f"A whole {pie} pizza costs ${price}")
```
You can also format inside f-strings:
```python
tax = 0.0625
print(f"subtotal ${price:,.2f}, tax {tax:.2%}, total ${price*(1+tax):.2f}")
```

## Handy patterns
```python
# Throwaway variable when you only need values
for _, price in pizzas.items():
    print(price)

# Enumerate while iterating a dict, with a stable order
for i, (pie, price) in enumerate(sorted(pizzas.items()), start=1):
    print(f"{i}. {pie} — ${price}")

# Build a list of lines then join once (fast output)
lines = [f"{pie}: ${price}" for pie, price in pizzas.items()]
print("\n".join(lines))
```

## Pitfalls
- `for pie in pizzas:` gives you **keys**, not `(key, value)`; don’t forget `.items()` when you need both.
- Converting views to lists (`list(d.items())`) **copies** data; iterate views directly when possible.
- Avoid relying on incidental order unless you **control** it (sort).

## Related Concepts
- [[Python Dictionaries — keys, values, items, get, update, merge]]
- [[Formatted Strings (f-strings) — Deep Dive]]
- [[Comprehensions — list/set/dict]]
- [[Enumerate — looping with index]]
- [[Zip — iterate multiple sequences]]
- [[Unpacking — tuple/list/dict patterns]]
- [[Sorting in Python — key functions, reverse, stability]]

## See Also
- [dict — mapping type](https://docs.python.org/3/library/stdtypes.html#mapping-types-dict)
- [f-strings — PEP 498](https://peps.python.org/pep-0498/)
- [Sorting HOWTO](https://docs.python.org/3/howto/sorting.html)

## Terms
[[dictionary]], [[loop]], [[for]], [[items()]], [[values()]], [[keys()]], [[tuple unpacking]], [[f-string]], [[format()]], [[sorting]], [[enumerate]]
