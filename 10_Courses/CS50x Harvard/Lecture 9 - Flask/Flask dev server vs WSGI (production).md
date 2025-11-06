---
title: "Flask dev server vs WSGI (production)"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/flask, #tool/wsgi, #tool/gunicorn"
atom_idx: 20
status: "done"
difficulty: "easy"
date: "2025-11-06"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-12-06"
---

## Summary
Flask’s built‑in server (from **Werkzeug**) is a **development** server. It’s great for local testing of your CS50 projects (like **Finance**), but it’s **not** secure, scalable, or tuned for heavy traffic. In **production**, you run your Flask app behind a **WSGI** server such as **Gunicorn**, **uWSGI**, or **Waitress**, often behind a reverse proxy (e.g., **Nginx**) for TLS, compression, and static files.

## What is **WSGI**
**WSGI** (Web Server Gateway Interface) is a minimal, standard interface between **Python** web apps and web servers. You expose a Python callable (usually your `Flask(__name__)` app), and a WSGI server speaks HTTP with the outside world and calls your app per request. This decouples your app from the web‑server details and lets you swap servers without touching app code.

## Minimal patterns

### Dev (local only)
```bash
export FLASK_APP=app
export FLASK_DEBUG=1      # optional: auto‑reload + debugger
flask run                 # 127.0.0.1:5000, development server
```

### Production (one simple way with **Gunicorn**)
```bash
# Install
pip install gunicorn

# Run (basic)
gunicorn -w 4 -b 0.0.0.0:8000 "app:app"

# With environment
export FLASK_ENV=production
gunicorn --workers 4 --threads 2 --timeout 60 "app:app"
```

### With **Nginx** as reverse proxy (idea)
- Nginx handles **TLS**/certs and serves static assets efficiently.
- Nginx proxies requests to `gunicorn` on `127.0.0.1:8000`.
- Your Flask app only focuses on Python logic.

## When to use what
- **Use Flask dev server**: quick local testing, debugging, CS50 problem sets.
- **Use WSGI server**: anything user‑facing on the internet (deployments, demos for other people, staging/prod).

## Gotchas / tips
- Dev server is **single‑process** and not hardened. Don’t put it on the public internet.
- Set **`FLASK_ENV=production`** (or don’t enable debug) in prod — debug mode shows sensitive stack traces.
- Keep **secrets** outside the repo; use env vars or a secrets manager.
- For background jobs, static files, file uploads, and WebSocket needs — consider extra services (Celery/Redis, S3, etc.) or frameworks that fit those needs.
- Observe and log: add **health checks**, **timeouts**, and **logging**; monitor with **systemd**, **supervisor**, or Docker orchestration.

## Related Concepts
- [[AJAX — Asynchronous JavaScript and XML]] – pairs with API endpoints your Flask app might expose.
- [[Meta viewport for responsive pages]] – front‑end basics you’ll use with Flask templates.
- [[render_template() in Flask]] – server‑side **Jinja** rendering before sending a response.
- [[Jinja control flow (if/for)]] – template logic used in forms and pages.
- [[Form submission (GET vs POST) in Flask]] – choosing the right **HTTP** method.
- [[Sessions and cookies in Flask]] – storing per‑user data securely.
- [[Returning JSON from Flask]] – power client‑side **fetch()**/**AJAX**.
- [[Routing and URL params in Flask]] – mapping `/path/<param>` into function args.

## See also
- [Flask docs — Deployment options](https://flask.palletsprojects.com/en/latest/deploying/)
- [Gunicorn — WSGI server for Python](https://gunicorn.org/)
- [uWSGI — The uWSGI project](https://uwsgi-docs.readthedocs.io/en/latest/)
- [Waitress — production WSGI server (pure‑Python)](https://docs.pylonsproject.org/projects/waitress/en/stable/)

## Terms
[[WSGI]], [[Werkzeug]], [[Gunicorn]] ,[[uWSGI]], [[Waitress]], [[Reverse proxy]], [[Nginx]], [[Flask]]
