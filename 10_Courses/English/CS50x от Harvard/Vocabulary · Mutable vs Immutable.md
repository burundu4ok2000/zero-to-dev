---
title: "Vocabulary · Mutable vs Immutable"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
status: "done"
difficulty: "easy"
date: "2025-09-24"
source: ""
review_next: ""
---

## 📖 Definition
**MUTABLE** *(adj.)* — **can change in place**; the same **object** gets modified (e.g., **list**, **dict**, **set**).  
**IMMUTABLE** *(adj.)* — **cannot change in place**; any “change” makes a **new object** (e.g., **str**, **tuple**, **int**, **float**).

---

Понял, давай уложим аккуратнее без “разваленной” таблицы. Можно вынести примеры кода отдельными блоками, а в таблице оставить только саму суть:

---

## 🔍 In Context (Python)

| Context                   | Meaning                                                           |
| ------------------------- | ----------------------------------------------------------------- |
| **Strings are immutable** | `+=` builds a **new object**                                      |
| **Lists are mutable**     | `+=` **modifies in place**                                        |
| **Rule of thumb**         | `+=` on **immutable** → new object; on **mutable** → **in-place** |
| **Identity vs equality**  | `id()` checks identity; == checks values                          |

###  ✅ Examples

```python
# Strings are immutable
s = "a"
id_before = id(s)
s += "b"
id_after = id(s)
print(id_before, id_after)
# different → new object
```

```python
# Lists are mutable
xs = [1]
id_before = id(xs)
xs += [2]
print(xs, id(xs))
# [1, 2], same id → modified in place
```

```python
# Identity vs equality
a = "hi"
b = "hi"
print(a == b)   # True → same value
print(id(a) == id(b))  # may be True or False → identity check
```

---

## 🧠 Very Simple
Think **play‑dough vs baked brick**: a **mutable** thing is play‑dough (you squeeze the same piece), an **immutable** thing is a baked brick (you can’t reshape it; you grab a **new** brick).

---

## 🧩 Collocations
- **mutable object**, **mutable state**, **in‑place** update  
- **immutable string**, **immutable tuple**, **persistent** data structure  
- **object identity**, **garbage collector**, **reference**

---

## 🔠 Forms & Pronunciation
**mutable** /ˈmjuːtəbl̩/ · **immutability** /ɪˌmjuːtəˈbɪləti/ · **immutable** /ɪˈmjuːtəbl̩/

---

## 📝 Quick Notes
- **Dict keys** must be **hashable** (usually **immutable**). A **tuple** is immutable, but if it contains a **list** inside, it’s not hashable.  
- Some operators use special methods: `+` calls **__add__**, `+=` may call **__iadd__** (in‑place) or fall back to **__add__** to make a new object. Strings don’t implement in‑place add, so you get a **new string**.

---

## Related Concepts
- [[Python Objects — Beginner Notes]] – objects, **attributes**, **methods**, **dunder** basics
- [[Python Syntax — Running, Style, Shebang]] – how to run code that shows **id()**, `+=`
- [[Python — Lists vs Tuples]] – choose **mutable** vs **immutable** sequences
- [[Identity vs Equality (id vs ==) in Python]] – object **identity** vs value **equality**
- [[Immutability & Hashability]] – why **dict**/**set** keys need **hashable** types
- [[Python — Dictionaries & Keys]] – constraints on keys, **hash** and **equality**
- [[Python — Data Model Magic Methods]] – **__add__**, **__iadd__**, **__hash__**
- [[Garbage Collection in Python]] – what happens to the old object

---

## See Also
- [Python Data Model — Official docs](https://docs.python.org/3/reference/datamodel.html)
- [Built-in Types — Sequence Types](https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range)
- [Why Python Strings Are Immutable (FAQ)](https://docs.python.org/3/faq/design.html#why-are-python-strings-immutable)
