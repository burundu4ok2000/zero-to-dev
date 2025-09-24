---
title: "Named Parameters (Keyword Arguments) — Python"
lang_tags: "#lang/python"
type_tags: "#type/termin"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 03
status: "in-progress"
difficulty: "easy"
date: "2025-09-22"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/6/"
review_next: ""
---
![[Screenshot 2025-09-22 at 15.47.38.png]]

![[Screenshot 2025-09-22 at 15.55.14.png]]
## Definition
**Named parameters** (aka **keyword arguments**) let you pass arguments by **name** instead of position. This boosts **readability** and avoids mistakes when functions have many parameters or **defaults**.

## **Python terms**: 

### **1.** **Positional arguments**

Arguments matched **by order**.

```py
def greet(name, age):
    print(f"{name} is {age} years old.")

greet("Alice", 30)   # "Alice" → name, 30 → age
```

---

### **2.**  **Keyword arguments**

  

Arguments matched **by name**.

```py
greet(age=30, name="Alice")
```

Order doesn’t matter, because you explicitly say which is which.

---

### **3.**  **Defaults**

  

You can give parameters a **default value**.
```py
def ___(___, ___=18)
```


```py
def greet(name, age=18):
    print(f"{name} is {age} years old.")

greet("Alice")        # age = 18
greet("Bob", 25)      # age = 25
```

---

### **4.**  **Keyword-only arguments**. 

```py
*,
```

  

Arguments that **must** be passed with name=value.

They come **after** a * in the function signature.

```py
def make_user(name, *, active=True, admin=False):
    print(name, active, admin)

make_user("Alice", active=False)  # ✅
make_user("Alice", False)         # ❌ error
```

---

### **5.**  ***args**

  

Collects **extra positional arguments** into a tuple.

```py
def add(*args):
    return sum(args)

add(1, 2, 3, 4)   # 10
```

---

### **6.** ****kwargs**

  
Python will scoop up **any extra key=value pairs** that weren’t matched to named parameters, and put them into a **dictionary**.

```py
def show(**kwargs):
    print(kwargs)

show(name="Alice", age=30)
# {'name': 'Alice', 'age': 30}
```

### **Why ****kwargs** is useful**

- Lets you write **flexible functions** that can accept optional named arguments.
    
- Common in frameworks (like Flask, Django, Pandas) where functions need to handle lots of possible settings.

---

### **Rule of thumb for function signatures**

  

The order is:

```py
def func(positional, defaults, *args, keyword_only, **kwargs):
    ...
```



## Syntax
```py
def greet(name, time="day"):
    print(f"Good {time}, {name}!")

greet("Alice")                        # positional → Good day, Alice!
greet(name="Alice", time="evening")   # named → order doesn’t matter
greet(time="morning", name="Bob")     # named → still OK
```

### Keyword‑only parameters

```py
*,
```

```py
def scale(value, *, factor=1.0):
    return value * factor

scale(10, factor=2)   # OK
scale(10, 2)          # ❌ TypeError: factor must be named
```

### Collecting keywords dynamically
```py
def connect(**opts):
    # opts is a dict of all keyword args
    print(opts)

connect(host="db", port=5432, ssl=True)
# {'host': 'db', 'port': 5432, 'ssl': True}
```

- You can call the variable *****kwargs anything (**kwargs, **options, **banana…), but **kwargs is the convention.
  
### Unpacking a dict into named params

That’s the **reverse move** of **kwargs. Instead of _packing_ keyword args into a dict, you’re _unpacking_ a dict into keyword args.

```py
params = {"sep": " | ", "end": " \n"}
print("a", "b", **params)   # uses sep and end by name
```

### Why **params s useful

- Lets you store arguments in a dict (maybe loaded from a config file, JSON, or user input) and pass them straight to a function without rewriting them by hand.
    
- Super common in frameworks (Flask, Pandas, TensorFlow), where functions accept a lot of options.

## Rules & Gotchas
- **Order**: positional args first, then keyword args.  
  `fn(1, 2, x=3)` ✅  but `fn(x=3, 1, 2)` ❌  
- **No duplicates**: you can’t pass the **same** parameter twice (positional + named).  
- **Names must match** function parameter names exactly.  
- **Defaults** are evaluated once, at def time (avoid mutable defaults like `[]`).  
- Many built‑ins use named params: `print(sep=..., end=...)`, `sorted(key=..., reverse=...)`.

## Why it matters (CS50 angle)
Compared to C’s positional parameters, Python’s **named arguments** improve **clarity** and **safety** with almost **zero boilerplate**. They’re used everywhere in real codebases and libraries.

## Micro‑examples
```py
# Readable calls
send_email(to="you@example.com", subject="Hi", body="...")

# Clear overloading
open("data.txt", mode="w", encoding="utf-8")

# Safer long parameter lists
plot(x=data, y=labels, color="red", linewidth=2)
```

## Related Concepts
- [[Hello, world — C vs Python]] – compilation vs interpretation mindset.
- [[Concatenation — Python’s + for Strings and Sequences]] – string operations you pass into functions.
- [[Choosing a Data Structure — Practical Guide]] – APIs often expose **keyword** flags.
- [[Hash Tables — Arrays and Linked Lists]] – Python’s dict consumes `**kwargs` (a **hash map**).
- [[Prime Numbers for Hashing — Why Primes Matter and How to Use Them]] – hashing background for dicts.
- [[Queues — Enqueue and Dequeue]] – function params to control behavior.
- [[Binary-Search-Trees-Basics-and-Operations]] – alternative ordered lookups (contrast with dict/kwargs).
- [[Signed vs Unsigned Integers in C — Ranges and Memory]] – shows how Python hides low‑level details.

## See Also
- [Python Tutorial — Defining functions (keyword arguments)](https://docs.python.org/3/tutorial/controlflow.html#keyword-arguments)
- [PEP 3102 — Keyword‑Only Arguments](https://peps.python.org/pep-3102/)
- [Built‑in `print()` parameters](https://docs.python.org/3/library/functions.html#print)

## Terms
[[Keyword argument]] [[Positional argument]] [[Default parameter]] [[Keyword‑only argument]] [[*args]] [[**kwargs]] [[Unpacking]] [[Function signature]] [[Mutable default]]
