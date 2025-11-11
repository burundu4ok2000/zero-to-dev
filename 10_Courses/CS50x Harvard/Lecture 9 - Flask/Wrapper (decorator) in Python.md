---
title: "Wrapper (decorator) in Python"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/python, #tool/flask"
atom_idx: 24
status: "done"
difficulty: "easy"
date: "2025-11-06"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-12-06"
---

## Summary
A **decorator** is a function that **takes a function and returns a new function** (a **wrapper**) that adds behavior before/after/around the original call. You attach it with `@decorator` above a function. This pattern relies on **higher‑order functions** and **closures**, and in practice you’ll see it everywhere in Flask (e.g., `@login_required`).

## Minimal example
```python
def my_decorator(func):
    def wrapper():
        print("Before")
        func()
        print("After")
    return wrapper

@my_decorator
def hello():
    print("Hi!")

hello()
# Before
# Hi!
# After
```

## Keep metadata with **@wraps**
Without **@functools.wraps**, the wrapper hides the original function’s `__name__`, docstring, annotations, etc. Use it to copy metadata across.
```python
from functools import wraps

def my_decorator(func):
    @wraps(func)                     # keep name, __doc__, etc.
    def wrapper(*args, **kwargs):    # pass through arguments
        print("Before")
        result = func(*args, **kwargs)
        print("After")
        return result
    return wrapper
```

## Decorator with parameters
```python
from functools import wraps

def repeat(n=2):
    def deco(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            last = None
            for _ in range(n):
                last = func(*args, **kwargs)
            return last
        return wrapper
    return deco

@repeat(3)
def ping(who): 
    print(f"ping {who}")
```

## Flask‑style example (auth guard)
A classic use in web apps is to enforce **login** around a view. The wrapper checks session state, and either redirects or calls the original view.
```python
from functools import wraps
from flask import session, redirect, url_for

def login_required(view):
    @wraps(view)
    def wrapper(*args, **kwargs):
        if not session.get("user_id"):
            return redirect(url_for("login"))
        return view(*args, **kwargs)
    return wrapper

@app.route("/dashboard")
@login_required
def dashboard():
    ...
```
This mirrors how **Flask‑Login** implements `@login_required` under the hood.

## When to use
- Cross‑cutting concerns: **auth**, **rate‑limiting**, **logging**, **timing**, **caching**, **input validation**.
- Avoiding **copy‑paste** of the same checks in many routes/functions.

## Gotchas
- Always forward `*args`/`**kwargs` from wrapper to the original.
- Use **@wraps** to keep function identity (helps with debugging, docs, Flask routing).
- Keep side effects minimal; decorators should be predictable and fast.

## Related Concepts
- [[Flask dev server vs WSGI (production)]] – deployment context where decorators often guard views.
- [[Password hashing with werkzeug.security]] – used alongside `@login_required` in auth flows.
- [[Parameterized queries prevent SQL injection]] – safety pattern that often pairs with auth.
- [[Flask: request.form and methods]] – inputs validated before decorated views run.
- [[Returning JSON from Flask]] – decorators can wrap API responses.
- [[AJAX — Asynchronous JavaScript and XML]] – frontend calling decorated endpoints.
- [[Jinja control flow (if/for)]] – template layer consuming results from decorated views.

## See also
- Python docs — **functools** and **@wraps**  
  https://docs.python.org/3/library/functools.html
- PEP 318 — decorator syntax for functions and methods  
  https://peps.python.org/pep-0318/
- Real Python — primer on decorators (clear intro & patterns)  
  https://realpython.com/primer-on-python-decorators/
- Flask docs — view decorators pattern (auth example)  
  https://flask.palletsprojects.com/en/stable/patterns/viewdecorators/
- Flask‑Login — `@login_required` behavior  
  https://flask-login.readthedocs.io/

## Terms
[[Decorator]], [[Wrapper function]], [[Higher‑order function]], [[Closure]], [[functools.wraps]], [[*args]], [[**kwargs]], [[login_required]]
