---
title: "requirements.txt basics"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/pip, #tool/venv, #tool/poetry, #tool/pip-tools"
atom_idx: 25
status: "done"
difficulty: "easy"
date: "2025-11-06"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-12-06"
---

## Summary
**requirements.txt** lists the Python packages your app needs. You install them with `pip install -r requirements.txt`. Good **culture** around this file means: use a **virtual environment**, **pin** versions thoughtfully, regenerate it when dependencies change, and prefer **parameterized** version specifiers (PEP 440) or a compiled lock style when you need fully reproducible builds.

## Why it matters
- Guarantees teammates (and deploy servers) get **the same dependencies**.
- Documents your project’s **runtime contract**.
- Enables quick setup: `python -m venv .venv && source .venv/bin/activate && pip install -r requirements.txt`.

## Typical entries in CS50 Finance
- **cs50** — helper that exposes **SQL** object for simple DB calls.
- **Flask** — web framework: routes, templates (**Jinja**), `request`, `session`.
- **Flask-Session** — server‑side **sessions** (e.g., filesystem) for logins.
- **pytz** — timezone conversions for timestamps.
- **requests** — HTTP client (call stock quote APIs, etc.).

## Versioning (PEP 440 quick tour)
Common operators:
-  == 1.2.3 — exact pin (reproducible but brittle).
- `~=1.2` — *compatible release* (≥1.2, <2.0; keeps bugfixes).
- `>=1.2,<2.0` — explicit range.
- omit version — always latest (risky).
Pin **top‑level** deps you import; ranges or compatible pins are fine for learning. For strict prod reproducibility, pin everything (see below).

## Two workflows
**A. Simple (learning / small apps)**
```bash
python -m venv .venv
source .venv/bin/activate          # .venv\Scripts\activate on Windows
pip install -r requirements.txt
# Update:
pip install flask==3.0.3
pip freeze > requirements.txt      # snapshot current env (all deps)
```
Pros: fast & simple. Cons: `pip freeze` pins **transitive** deps too (can be noisy).

**B. Reproducible (apps you deploy)**
```bash
# 1) Declare what YOU depend on (top‑level) in requirements.in
flask~=3.0
flask-session~=0.8
requests~=2.32

# 2) Compile a locked requirements.txt with hashes
pip install pip-tools
pip-compile --generate-hashes requirements.in
# 3) Sync your env exactly
pip-sync
```
This produces a deterministic `requirements.txt` (with hashes) from a clean `requirements.in`.

## Best practices (“culture”)
- Use **virtual environments** (`python -m venv .venv`) per project.
- Keep `requirements.txt` in the **repo root**; update it whenever deps change.
- Choose pins: **learning** → looser (`~=`); **prod** → locked pins + **hashes**.
- Do **not** commit secrets or environment‑specific stuff into the file.
- Add **dev‑only** tools to a separate file (e.g., `requirements-dev.txt`) if needed.
- CI: `pip install -r requirements.txt && pip check` to catch conflicts.
- Document your **Python version** in README or `.python-version` (pyenv).

## Commands you’ll actually use
```bash
# Create & enter venv
python -m venv .venv
source .venv/bin/activate    # Windows: .venv\Scripts\activate

# Install everything listed
pip install -r requirements.txt

# Snapshot current env (simple flow)
pip freeze > requirements.txt

# Upgrade a package
pip install --upgrade requests

# Compile lockfile from top-level specs (advanced)
pip-compile --generate-hashes requirements.in
pip-sync
```

## Related Concepts
- [[Flask dev server vs WSGI (production)]] – deploy flow that reads your `requirements.txt`.
- [[Password hashing with werkzeug.security]] – auth dependencies live here.
- [[Parameterized queries prevent SQL injection]] – DB libs pinned via requirements.
- [[Returning JSON from Flask]] – APIs rely on `Flask`/`requests` versions.
- [[AJAX — Asynchronous JavaScript and XML]] – client talks to your pinned server stack.
- [[Wrapper (decorator) in Python]] – utilities you might ship as a small lib later.
- [[Flask: request.form and methods]] – framework behavior tied to pinned Flask versions.

## See also
- pip docs — **Requirements File Format**  
  https://pip.pypa.io/en/stable/reference/requirements-file-format/
- pip user guide — **Repeatable installs** & `pip freeze`  
  https://pip.pypa.io/en/stable/user_guide/
- PEP 440 — **Version specifiers**  
  https://peps.python.org/pep-0440/
- pip‑tools — `pip-compile`/`pip-sync` for deterministic builds  
  https://pip-tools.readthedocs.io/en/latest/
- Python docs — **venv** (virtual environments)  
  https://docs.python.org/3/library/venv.html

## Terms
[[requirements.txt]], [[pinning]], [[Version specifier (PEP 440)]], [[pip freeze]], [[pip-compile]], [[virtual environment]], [[venv]], [[transitive dependency]]
