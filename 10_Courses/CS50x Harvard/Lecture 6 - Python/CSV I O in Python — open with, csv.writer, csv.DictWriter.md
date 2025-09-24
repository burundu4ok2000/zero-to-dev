---
title: CSV I/O in Python — open/with, csv.writer, csv.DictWriter
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 16
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 02:04:40–02:06:10
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

![[Screenshot 2025-09-22 at 20.44.07.png]]
![[Screenshot 2025-09-22 at 20.46.06.png]]
![[Screenshot 2025-09-22 at 20.48.20.png]]

## Summary
How to append rows to a **CSV** (comma‑separated values) file in Python using the **csv** module. Start with plain `open()` and then prefer the **context manager** `with open(...) as file:` so files are closed automatically. Use `csv.writer` for list‑style rows, or `csv.DictWriter` for named columns.

## Quick patterns

### 1) Append a row (basic writer)
```python
import csv

with open("phonebook.csv", "a", newline="", encoding="utf-8") as file:
    writer = csv.writer(file)
    name = input("Name: ")
    number = input("Number: ")
    writer.writerow([name, number])
```

### 2) Append a row with column names (DictWriter)
```python
import csv

with open("phonebook.csv", "a", newline="", encoding="utf-8") as file:
    fieldnames = ["name", "number"]
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    # write header once if the file is empty:
    if file.tell() == 0:
        writer.writeheader()

    name = input("Name: ")
    number = input("Number: ")
    writer.writerow({ "name": name, "number": number })
```

### 3) Read it back
```python
import csv

with open("phonebook.csv", newline="", encoding="utf-8") as file:
    for row in csv.reader(file):
        print(row)

with open("phonebook.csv", newline="", encoding="utf-8") as file:
    for obj in csv.DictReader(file):
        print(obj["name"], obj["number"])
```

## Why these details
- `newline=""` avoids blank lines on Windows when using the **csv** module.
- `encoding="utf-8"` keeps names/numbers portable across systems.
- `file.tell()==0` is a quick way to detect an empty file and write the **header** once.
- `DictWriter` lets you **reorder** columns and makes code self‑documenting.

## Gotchas
- Don’t mix manual `print(..., file=f)` with `csv.writer` on the same handle unless you know what you’re doing.
- Open in **append** mode `"a"` for adding rows, `"w"` to overwrite.
- Delimiter isn’t always a comma; set it with `csv.writer(file, delimiter=";")` if needed.
- Wrap user input validation with [[Exceptions — try/except, else, finally, raise]] when parsing numbers.

## Related Concepts
- [[File I/O — open/read/write/close]]
- [[Python Syntactic Sugar — Shortcuts from CS50]]
- [[Phonebook search — list of dicts + for-else (CS50x Lecture 6)]]
- [[Formatted Strings (f-strings) — Deep Dive]]
- [[Using Module Namespaces — import module vs from module import name]]
- [[Command-line Args in Python — sys.argv and sys.exit]]
- [[Dictionaries (dict) — methods and patterns]]
- [[Lists and Iteration in Python]]

## See Also
- [csv module (official docs)](https://docs.python.org/3/library/csv.html)
- [Reading and Writing Files](https://docs.python.org/3/tutorial/inputoutput.html#reading-and-writing-files)
- [Unicode HOWTO](https://docs.python.org/3/howto/unicode.html)

## Terms
[[CSV]], [[context manager]], [[writer]], [[writerow]], [[DictWriter]], [[DictReader]], [[header row]], [[encoding]], [[newline]], [[delimiter]]
