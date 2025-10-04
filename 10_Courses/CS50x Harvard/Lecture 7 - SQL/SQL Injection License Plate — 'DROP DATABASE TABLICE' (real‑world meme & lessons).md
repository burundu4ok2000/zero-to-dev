---
title: "SQL Injection License Plate — 'DROP DATABASE TABLICE' (real‑world meme & lessons)"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 18
status: "in-progress"
difficulty: "easy"
date: "2025-10-04"
timecode: "02:36:14"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-04 at 16.24.30.png]]

## Summary
A photo went viral of a car with a fake plate reading `ZU 0666', 0, 0); DROP DATABASE TABLICE; --` — a cheeky **SQL injection** payload aimed at speed‑camera systems that use **OCR** (optical character recognition) to read plates. **Tablice** is Polish for “plates.” The idea: if a backend naively concatenated plate text into **SQL**, the injected `DROP DATABASE` would erase the **license‑plate** database. It’s a great teaching story; there’s no solid evidence of production systems actually being wiped, but it illustrates why **parameterized queries** are non‑negotiable.

## Very simple
It’s the **Bobby Tables** gag on a bumper: trick a sloppy system by turning your plate text into code.

## What the payload means
```
'ZU 0666', 0, 0); DROP DATABASE TABLICE; --
└─────┬──┘         └──────────────┬────┘ └┬┘
 closes string            second SQL stmt   comment tail
```
- A preceding `INSERT(...) VALUES('<PLATE>', ...)` could be **terminated** by the `'`.  
- Then `DROP DATABASE TABLICE;` executes as a separate statement.  
- `--` comments out any trailing SQL so the syntax still “works.”

## Did this really work anywhere?
Likely **no** — this is best treated as a meme/anecdote. Coverage (2011–2014) spread via blogs and forums; none provided verifiable evidence of a real ticket system being destroyed. Still, the premise is plausible **if** a system:
- accepted arbitrary characters from OCR without an **allowlist** (letters/digits only),  
- concatenated values into SQL strings instead of **bound parameters**, and  
- granted the app user rights to `DROP DATABASE` or run multiple statements.

## Lessons for real systems
- Use **parameterized queries / prepared statements** everywhere; never string‑build SQL.  
- **Allowlist** input for license plates (only `[A–Z0–9]` and permitted separators).  
- Run the app with **least privilege**: no DDL rights (`DROP`, `ALTER`) for request‑path users.  
- Disable multi‑statement execution in the driver; log and alarm on suspicious tokens (`';--`, `UNION`, etc.).  
- Treat **OCR/ALPR** ingest like user input from the wild web. Validate before it ever touches your DB.

## Related Concepts
- [[SQL Injection — attacks and defenses (CS50 Week 7)]] – the full playbook against injection.  
- [[SQL DELETE — Safe Usage, WHERE, and Rollback Habits]] – damage control via transactions.  
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]] – drivers and parameter markers vary.  
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]] – where attackers wedge payloads.  
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]] – joins are common attack surfaces.  
- [[Indexes — speed up WHERE/JOIN/ORDER BY]] – performance ≠ security, but you’ll test on the same datasets.  
- [[CREATE TABLE + FOREIGN KEY (shows/ratings) — what it does]] – constraints complement validation.  
- [[Race Conditions — what they are and how to avoid them]] – another class of production bugs.

## See also
- Hackaday roundup on the meme and the “Tablice” translation: https://hackaday.com/2014/04/04/sql-injection-fools-speed-traps-and-clears-your-record/  
- Bruce Schneier’s discussion on license‑plate SQL injection (skeptical take): https://www.schneier.com/blog/archives/2008/04/sql_injection_a_1.html  
- XKCD #327 “Exploits of a Mom” (origin of the culture joke): https://xkcd.com/327/  

## Terms
[[SQL injection]], [[OCR]], [[ALPR]], [[parameterized query]], [[prepared statement]], [[least privilege]], [[input validation]], [[comment delimiter]], [[multi‑statement execution]]
