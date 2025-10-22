---
title: "POST form data and DevTools payload"
lang_tags: "#lang/html"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/editor/vscode"
atom_idx: 02
status: "done"
difficulty: "easy"
date: "2025-10-22"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-11-22"
---

![[Screenshot 2025-10-21 at 12.23.18.png]]

## Summary
When a form uses **POST**, the browser sends the inputs as **Form Data** in the **request body**. In Chrome **DevTools → Network → Payload**, you can see the key–value pairs (e.g., `name: David`). This is why the value is **not in the URL**, unlike **GET**.

## Very simple
> You pass a note to the server in a closed envelope (**POST body**), not written on the envelope itself (**URL**). DevTools lets you peek at what was sent.

## Key Points
- **GET** puts data in the **query string** (`/greet?name=David`); visible in URL/history.
- **POST** puts data in the **body** as **application/x-www-form-urlencoded** by default; not shown in the URL.
- In **Flask**, read GET params via `request.args` and POST form fields via `request.form`.
- **Security note:** POST **hides** from the URL but is **not encryption**. Use **HTTPS** and **CSRF protection** for real forms.
- Check what was sent via **DevTools → Network → (doc or request) → Payload**.

## Details
- Default browser encoding for forms is **URL-encoded**; files use **multipart/form-data**.
- Use `methods=["GET", "POST"]` in your Flask route if you want to accept both.
- Redirect after a successful POST (**PRG pattern**) to avoid duplicate submissions on refresh.
- Keep sensitive inputs out of GET because links/logs/analytics may store URLs.

## Examples

### Flask routes showing GET vs POST
```python
# app.py
from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/greet", methods=["GET", "POST"])
def greet():
    if request.method == "POST":
        name = request.form.get("name", "world")
        # Post/Redirect/Get to avoid resubmits
        return redirect(url_for("hello", name=name))
    else:  # GET
        name = request.args.get("name", "world")
        return render_template("greet.html", name=name)

@app.route("/hello")
def hello():
    # ends up here after POST redirect
    name = request.args.get("name", "world")
    return render_template("greet.html", name=name)

if __name__ == "__main__":
    app.run(debug=True)
```

### Templates
```html
<!-- templates/index.html -->
<form action="/greet" method="post">
  <input name="name" placeholder="Your name" autocomplete="off" autofocus>
  <button type="submit">Greet</button>
</form>
```

```html
<!-- templates/greet.html -->
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>hello</title>
</head>
<body>
  <h1>hello, { name }</h1>
</body>
</html>
```

### How to inspect in DevTools
1. Open page → **Right‑click → Inspect**.
2. Go to **Network** tab.
3. Submit the form.
4. Click the new **request** (type **Doc** or **fetch**).
5. Open **Payload** → see **Form Data** (`name: David`).

## **Why It Matters**
Choosing **POST** keeps user inputs out of URLs, reduces accidental sharing in logs, and enables larger payloads and file uploads. Knowing where to see the **payload** helps debug quickly.

## Questions
- ❓When do I need **multipart/form-data** instead of URL‑encoded?
- ❓What does **CSRF** protect against in Flask forms?
- ❓When is **GET** better (e.g., search pages)?

## Related Concepts
- [[HTTP GET vs POST]] – how the transport differs and when to use each.
- [[Flask — Request vs Response Basics]] – where `request.args` / `request.form` live.
- [[CSRF protection basics]] – security for state‑changing POSTs.
- [[Chrome DevTools — Network tab]] – tooling to inspect requests.
- [[URL Query String]] – GET parameters and encoding rules.
- [[Form validation (server-side)]] – verifying input before use.
- [[JSON vs Form Data]] – when APIs accept JSON instead of forms.
- [[CS50 — Week 9 Flask Hub]] – index of all week 9 notes.

## See also
- [[HTML — Forms]]
- [MDN: Sending form data](https://developer.mozilla.org/en-US/docs/Learn/Forms/Sending_and_retrieving_form_data)
- [MDN: GET vs POST](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods#safe_methods)
- [CS50x 2025 — Week 9 (Flask)](https://cs50.harvard.edu/x/2025/weeks/9/)

## Terms
[[POST]], [[GET]], [[Form Data]], [[request.form]], [[request.args]], [[Content-Type]], [[URL-encoded]], [[DevTools]]
