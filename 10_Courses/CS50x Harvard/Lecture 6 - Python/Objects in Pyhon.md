---
title: "Python Objects — Beginner Notes"  
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 24
status: "in-progress"
difficulty: "easy"
date: "2025-09-23"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/6/"
review_next: ""
---

---
![[Screenshot 2025-09-23 at 15.45.45.png]]
![[Screenshot 2025-09-23 at 15.45.49.png]]

---

## Summary
Tiny crash course on **objects** in Python: data + behavior in one box. You’ll meet **classes**, **instances**, **attributes**, **methods**, and useful **dunder methods** that make your objects feel Pythonic.

## Very simple
Imagine a **toy car**. The **color** is its data; **drive()** is what it can do. In Python, every toy is an **object**. A **class** is the blueprint for making more toy cars. When you build one, you get an **instance** that remembers its own data and actions.

## Key Points
- **Object = data + behavior**. Everything in Python is an **object** (numbers, strings, functions).
- **Class** is a blueprint; **instance** is a concrete object created from it.
- **Attribute** stores data on the object (`obj.name`). **Method** is a function bound to the instance (`obj.action()`).
- **Constructor** `__init__(self, ...)` runs after creation; **self** is the current instance.
- **Dunder methods** like `__str__`, `__repr__`, `__len__`, `__iter__`, `__eq__` plug your class into Python’s operators/protocols.
- **Encapsulation** by convention: prefix internal stuff with `_like_this`.
- Prefer **composition** over deep **inheritance**; embrace **duck typing** (“if it quacks…”).
- **Truthiness**: define `__bool__` or `__len__` to control `if obj:`.
- Optional **type annotations** help readability; **dataclasses** remove boilerplate.

## Details
Python glues behavior to data with **classes**. When you instantiate (`User("Ada")`), Python allocates an **instance** and then calls your **constructor** `__init__`. Attributes live on `self`. **Dunder methods** are special hooks Python calls for you: `__repr__` for debug printing, `__iter__` for loops, `__eq__` for comparisons, etc. Use **properties** when a field needs validation or a computed value. Use **@classmethod** for alternate constructors and **@staticmethod** for helpers that don’t touch state.

## Examples

```python
# Minimal class
class Student:
    def __init__(self, name, sid):
        self.name = name          # attribute
        self.sid = sid

    def label(self):              # method
        return f"{self.name} — {self.sid}"

jane = Student("Jane", 10)        # instance
print(jane.label())
````

```python
# Defaults & type annotations
class Point:
    def __init__(self, x: int = 0, y: int = 0) -> None:
        self.x: int = x
        self.y: int = y

    def __repr__(self) -> str:
        return f"Point(x={self.x}, y={self.y})"
```

```python
# Property (validated field)
class Celsius:
    def __init__(self, temp=0):
        self._c = temp

    @property
    def c(self):
        return self._c

    @c.setter
    def c(self, value):
        if value < -273.15:
            raise ValueError("Below absolute zero")
        self._c = value
```

```python
# Class & static methods
class User:
    domain = "example.com"

    def __init__(self, name):
        self.name = name

    @classmethod
    def with_domain(cls, name):
        return cls(f"{name}@{cls.domain}")

    @staticmethod
    def greet(who):
        return f"Hello, {who}!"
```

```python
# Dataclass (auto __init__/__repr__/__eq__)
from dataclasses import dataclass

@dataclass
class Item:
    sku: str
    price: float = 0.0

i = Item("X1", 9.99)
```

```python
# Inheritance & super
class Animal:
    def speak(self):
        return "..."

class Dog(Animal):
    def speak(self):
        return "woof"

class GuideDog(Dog):
    def speak(self):
        return super().speak().upper()  # "WOOF"
```

## **Why It Matters**

You’ll use **objects** to model real-world things cleanly, hide complexity with **encapsulation**, and get Python’s “just works” behavior via **dunder methods**. This is the backbone for frameworks, ETL jobs, web apps—pretty much everything in Python.

## Questions

- When should I choose **composition** over **inheritance** here?
    
- Which **dunder methods** do I actually need for this class?
    
- Do I want a **property** or a plain attribute for this field?
    
- Would a **dataclass** be enough?
    

## Related Concepts

- [[Python — Classes & Instances]] – how blueprints become objects; naming, style, best practices
    
- [[Python — Methods & Attributes]] – binding functions to data and storing state
    
- [[Python — Properties & Descriptors]] – validated fields and lazy computation
    
- [[Python — Dunder Methods Overview]] – special methods for printing, math, iteration
    
- [[Python — Inheritance vs Composition]] – choosing relationships between objects
    
- [[Python — Type Hints Basics]] – readable, tool-friendly **type annotations**
    
- [[Python — Static vs Class Methods]] – factories vs utilities on a class
    
- [[Python — Special Methods for Truthiness]] – tailoring `if obj:` via `__bool__`/`__len__`
    

## See also

- [[CS50x Harvard]]
    
- [Python Data Model — official docs](https://docs.python.org/3/reference/datamodel.html)
    
- [dataclasses — official docs](https://docs.python.org/3/library/dataclasses.html)
    
- [CS50x 2025 — Week 6: Python](https://cs50.harvard.edu/x/2025/weeks/6/)
    

## Terms

[[object]], [[class]], [[instance]], [[attribute]], [[method]], [[constructor]], [[self]], [[dunder method]], [[str]], [[repr]], [[len]], [[iter]], [[property]], [[class method]], [[static method]], [[dataclass]], [[inheritance]], [[super]], [[duck typing]], [[composition]], [[truthiness]], [[type annotation]], [[default argument]], [[encapsulation]]
