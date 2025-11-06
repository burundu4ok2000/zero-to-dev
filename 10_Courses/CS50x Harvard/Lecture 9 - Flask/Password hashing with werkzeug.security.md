---
title: "Password hashing with werkzeug.security"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/flask, #tool/werkzeug, #tool/sqlite"
atom_idx: 22
status: "done"
difficulty: "easy"
date: "2025-11-06"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-12-06"
---

## Summary
`werkzeug.security` gives you two battle‑tested helpers for **password hashing**: **generate_password_hash()** and **check_password_hash()**. Use them to **store hashes** (never raw passwords) and **verify** user logins. The hash string includes **algorithm**, **iterations** and **salt** (e.g., `pbkdf2:sha256:260000$<salt>$<digest>`), so verification knows how to check it. Seeing the algorithm in the hash is **normal** — security comes from strong passwords + **slow hashing** (many iterations), not secrecy of the algorithm.

## Core API
```python
from werkzeug.security import generate_password_hash, check_password_hash

# Registration — store hash in DB
pwd_hash = generate_password_hash(password)   # salted + iterative

# Login — verify
ok = check_password_hash(pwd_hash, candidate) # True/False
```

### Why this is safe
- User input is hashed with a **unique salt** → breaks rainbow tables.
- Many **iterations** make brute‑force slower (CPU/GPU‑expensive).
- Even if hashes leak, attacker must still guess the password offline.

### Where things break
- **Weak passwords** (e.g., `12345`) fall to brute force despite salts.
- **Re‑used passwords** across sites = one breach → many accounts.
- App vulns (e.g., **SQL injection**) leak hashes → enable offline attack.

## Practical patterns (CS50 style)
**Register**
```python
from werkzeug.security import generate_password_hash

def register():
    username = request.form.get("username")
    password = request.form.get("password")
    # TODO: validate strength (length + classes, or passphrase)
    hash_ = generate_password_hash(password)              # default pbkdf2:sha256
    db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash_)
```

**Login**
```python
from werkzeug.security import check_password_hash

def login():
    username = request.form.get("username")
    password = request.form.get("password")
    row = db.execute("SELECT * FROM users WHERE username = ?", username)
    if not row:
        return apology("invalid username")
    if not check_password_hash(row[0]["hash"], password):
        return apology("invalid password")
    # success → set session, redirect
```

**Tune (optional)**
```python
# You can choose a different method or cost:
generate_password_hash(password, method="pbkdf2:sha256", salt_length=16)
# Consider modern KDFs via flask extensions (e.g., bcrypt/argon2) for stronger GPU resistance.
```

## Ops & Security checklist
- **HTTPS** everywhere; never send passwords in clear text.
- **Rate‑limit** and lockouts for login; add **2FA**.
- Store only **hashes**, back up DB securely, restrict access (RBAC).
- Consider a server‑side **pepper** (env secret) in addition to per‑user salts.
- On leak → force password reset + notify users.

## Related Concepts
- [[Parameterized queries prevent SQL injection]] – block dump‑leaks that enable offline cracking.
- [[Flask: request.form and methods]] – where the raw password enters your app; validate early.
- [[Sessions and cookies in Flask]] – post‑login user state; secure cookies.
- [[Returning JSON from Flask]] – auth APIs for AJAX clients.
- [[AJAX — Asynchronous JavaScript and XML]] – frontend calling your auth routes.
- [[Meta viewport for responsive pages]] – frontend ergonomics with auth forms.
- [[Routing and URL params in Flask]] – input is untrusted; validate and sanitize.
- [[Error handling and apology()]] – safe error messages without leaking auth hints.

## See Also
- Flask tutorial: *generate_password_hash()* / *check_password_hash()* (official) — hashing best practices in the tutorial.
  <https://flask.palletsprojects.com/en/stable/tutorial/views/>
- Werkzeug docs: *generate_password_hash* / *check_password_hash* — API details & defaults.
  <https://werkzeug.palletsprojects.com/en/stable/utils/>
- OWASP Password Storage Cheat Sheet — modern guidance (bcrypt/argon2, salt, pepper, cost).
  <https://cheatsheetseries.owasp.org/cheatsheets/Password_Storage_Cheat_Sheet.html>

## Terms
[[Password hashing]], [[Salt]], [[PBKDF2]], [[bcrypt]], [[argon2]], [[Pepper]], [[Rate limiting]], [[2FA]], [[Have I Been Pwned]]
