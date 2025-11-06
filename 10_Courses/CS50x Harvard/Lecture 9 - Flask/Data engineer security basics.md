---
title: "Data engineer security basics"
lang_tags: "#lang/python"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_9_Flask"
tool_tags: "#tool/sqlite, #tool/python, #tool/flask, #tool/aws, #tool/gcp"
atom_idx: 23
status: "done"
difficulty: "easy"
date: "2025-11-06"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/9/"
review_next: "2025-12-06"
---

## Summary
As a **data engineer**, you don’t have to be a full‑time security expert, but you **do ship security** in code and pipelines. If data is sent or stored **raw** (no **TLS**, no **encryption**, no **hashing**, no **access control**), it will leak sooner or later. Even when a security team exists, DE is the person who **implements** safe defaults: **parameterized SQL**, **secrets management**, **least‑privilege IAM**, **encryption in transit/at rest**, and **logging**.

## Core principles (B1‑friendly, practical)
- **Passwords → slow hashing**: use **bcrypt** or **argon2** (salted, iterative). Weak passwords are still breakable, so enforce strength and **2FA/MFA**.  
- **In transit → TLS/HTTPS**: encrypt every network hop; follow modern TLS configs.  
- **At rest → encryption**: use **KMS**/**Key Vault**; never roll your own crypto.  
- **Secrets**: keep DB creds/API keys in a **Secrets Manager**, not in code or Git.  
- **SQL safety**: always **parameterize queries** (placeholders), never f‑strings for SQL.  
- **Access**: **RBAC/IAM** with **least privilege**; separate dev/stage/prod.  
- **PII protection**: **masking/tokenization/field‑level encryption** for sensitive columns.  
- **Observability**: **audit logs**, alerts, anomaly detection.  
- **Edge protection**: **rate‑limit**, **lockouts**, **WAF** on public endpoints.  
- **Resilience**: encrypted **backups**, regular **restore drills**; have an incident plan.  
- **Compliance**: data retention and privacy (GDPR/CCPA); don’t keep data “just in case.”

## First‑week checklist (80/20)
1) Force **HTTPS/TLS** everywhere.  
2) Replace hard‑coded secrets with a **secrets manager**.  
3) Make all DB calls **parameterized**.  
4) Hash user passwords with **argon2/bcrypt**; enforce password policy + **2FA**.  
5) Turn on **DB audit logs**; rotate and secure them.  
6) Map where **PII** lives; apply masking or column‑level encryption.  
7) Verify scheduled **backups** and perform one **test restore**.  
8) Review **IAM** roles for least privilege.

## Related Concepts
- [[Parameterized queries prevent SQL injection]] – eliminate injection via **placeholders**. 
- [[Password hashing with werkzeug.security]] – **generate_password_hash**/**check_password_hash** basics.  
- [[Flask dev server vs WSGI]] – production deployment and hardening context.  
- [[Returning JSON from Flask]] – APIs that carry PII must use **TLS** and auth.  
- [[AJAX — Asynchronous JavaScript and XML]] – don’t expose secrets in client calls.  
- [[Flask: request.form and methods]] – validate and sanitize inputs.  
- [[Sessions and cookies in Flask]] – secure cookies, **SameSite**, **HttpOnly**.  
- [[Error handling and apology()]] – avoid leaking stack traces or secrets.

## See also
- OWASP — **SQL Injection Prevention** (parameterized queries)  
  https://cheatsheetseries.owasp.org/cheatsheets/SQL_Injection_Prevention_Cheat_Sheet.html
- OWASP — **Password Storage** (bcrypt/argon2, salts, pepper)  
  https://cheatsheetseries.owasp.org/cheatsheets/Password_Storage_Cheat_Sheet.html
- NIST SP 800‑63B — **Authentication & lifecycle** (passwords, MFA)  
  https://pages.nist.gov/800-63-3/sp800-63b.html
- Mozilla — **Server‑Side TLS** (modern TLS configuration)  
  https://wiki.mozilla.org/Security/Server_Side_TLS
- AWS — **KMS encryption best practices** (keys, auditing)  
  https://docs.aws.amazon.com/prescriptive-guidance/latest/encryption-best-practices/kms.html
- AWS IAM — **least‑privilege** guidance  
  https://docs.aws.amazon.com/IAM/latest/UserGuide/best-practices.html

## Terms
[[TLS]] · [[HTTPS]] · [[Encryption in transit]] · [[Encryption at rest]] · [[KMS]] · [[Secrets Manager]] · [[Parameterization]] · [[RBAC]] · [[IAM]] · [[Least privilege]] · [[PII]] · [[Masking]] · [[Tokenization]] · [[Field‑level encryption]] · [[Audit logging]] · [[Rate limiting]] · [[MFA]] · [[2FA]] · [[WAF]]
