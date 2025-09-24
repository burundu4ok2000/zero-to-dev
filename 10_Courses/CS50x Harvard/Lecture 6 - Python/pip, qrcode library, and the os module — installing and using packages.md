---
title: pip, qrcode library, and the os module — installing and using packages
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_6_Python"
tool_tags: ""
atom_idx: 17
status: in-progress
difficulty: easy
date: 2025-09-22
timecode: 02:10:06
source: https://cs50.harvard.edu/x/2025/weeks/6/
review_next: ""
---

![[Screenshot 2025-09-22 at 20.54.19.png]]

## Summary
This note bundles three pieces: **pip** (installing third‑party packages), a mini program that generates a **QR code** using the `qrcode` library, and a quick tour of Python’s built‑in **os** module for file paths and process info.

## pip — install and manage packages
```bash
# install a package from PyPI
python -m pip install qrcode[pil]

# freeze current packages to a file
python -m pip freeze > requirements.txt

# install from a requirements file
python -m pip install -r requirements.txt
```

### Virtual environments (recommended)
```bash
python -m venv .venv
# activate
# macOS/Linux:
source .venv/bin/activate
# Windows (PowerShell):
.venv\Scripts\Activate.ps1

python -m pip install qrcode[pil]
```
Why: isolates dependencies per project; avoids polluting the system Python.

## QR code demo (from lecture, cleaned)
```python
# qr.py
import qrcode

img = qrcode.make("https://youtu.be/xvFZjo5PgG0")
img.save("qr.png", "PNG")
print("Saved qr.png")
```
Run:
```bash
python qr.py
```

## os module — paths, cwd, environment
```python
import os

print(os.getcwd())              # current working directory
print(os.listdir("."))          # names in a folder

# make folders/files safely
os.makedirs("out/images", exist_ok=True)

# build paths portably (or prefer pathlib)
path = os.path.join("out", "images", "qr.png")

# read env vars (e.g., API keys)
token = os.getenv("API_TOKEN", default="missing")
```

### Bonus: pathlib version (cleaner for paths)
```python
from pathlib import Path
dst = Path("out") / "images" / "qr.png"
dst.parent.mkdir(parents=True, exist_ok=True)
img.save(dst)                   # from the qrcode example above
```

## Common pitfalls
- Forgetting to **activate** the virtual env → `ModuleNotFoundError` even after installing.
- Mixing global pip and venv pip; always prefer `python -m pip ...` to bind pip to the current interpreter.
- Writing to paths that don’t exist; create folders first (`os.makedirs(..., exist_ok=True)`).
- Committing `venv` to git — don’t. Commit `requirements.txt` instead.

## Related Concepts
- [[Using Module Namespaces — import module vs from module import name]]
- [[Python Syntactic Sugar — Shortcuts from CS50]]
- [[Command-line Args in Python — sys.argv and sys.exit]]
- [[CSV I/O in Python — open/with, csv.writer, csv.DictWriter]]
- [[Phonebook search — list of dicts + for-else (CS50x Lecture 6)]]
- [[Exceptions — try/except, else, finally, raise]]
- [[File I/O — open/read/write/close]]
- [[Modules and Imports in Python]]

## See Also
- [pip user guide](https://pip.pypa.io/en/stable/user_guide/)
- [virtual environments (venv)](https://docs.python.org/3/library/venv.html)
- [qrcode on PyPI](https://pypi.org/project/qrcode/)
- [os — Miscellaneous operating system interfaces](https://docs.python.org/3/library/os.html)
- [pathlib — Object-oriented filesystem paths](https://docs.python.org/3/library/pathlib.html)

## Terms
[[pip]], [[PyPI]], [[virtual environment]], [[venv]], [[requirements.txt]], [[package]], [[module]], [[os module]], [[environment variable]], [[current working directory]], [[path]], [[pathlib]], [[QR code]], [[qrcode]]
