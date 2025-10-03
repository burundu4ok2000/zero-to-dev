---
title: "When to use Python instead of SQL (Sorting)"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 03
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "00:33:57"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 15.48.05.png]]

## Summary
Prefer **SQL** for sorting when the data **lives in the database** and you want to leverage indexes and avoid shipping rows to your program. Prefer **Python** for **small, in‑memory** datasets or **custom sort logic** that’s awkward or impossible to express in SQL.

## Very simple

> Explain this idea like to a 5‑year‑old:
    1. If toys are already on the shelf (database), sort them **on the shelf** — faster and tidy.
    2. If you only have a few toys in your hands, sort them **in your hands** (Python).
    3. If you want a weird order (by color+size rules), do it where you can write your own rules easily (Python).

## Key Points
- **Use SQL** when: data is in **SQLite/Postgres**, you can **ORDER BY** a column or expression, and sorting can use **indexes** → fewer bytes moved, faster overall.
- **Use Python** when: data is **small/local**, lives in **lists/dicts/CSV**, or needs **custom key/compare** (e.g., **natural sort**, locale‑specific, multi‑step ranking).
- **Network/I/O dominates**: shipping millions of rows to Python just to sort is wasteful; push the sort to the **database**.
- **Compute where the data is**: “move code to data” beats “move data to code” (classic ETL principle).
- **Hybrid**: do coarse ordering in SQL, then a **secondary custom sort** in Python for ties or special rules.

## Details
- Databases can sort via **ORDER BY** and often use **B‑tree indexes** to avoid full sorts. This is usually faster than pulling rows into Python and calling `sorted(...)` because it eliminates **I/O** and exploits the DB’s **query planner**.
- Python wins when sort logic is **non‑relational** or relies on **custom functions** (e.g., score by regex, decode JSON, compute Levenshtein distance). Writing this in pure SQL can be messy or slow.
- For **one‑off scripts** or **tiny files** (e.g., a short **CSV**), Python’s `sorted`/`.sort()` is simpler than creating tables just to call `ORDER BY`.
- If the table is **already indexed by the sort key**, `ORDER BY key` can be nearly free; fetching in index order avoids a full sort.
- Beware of **collations**: SQL engines and Python have different default collations; if you need locale‑aware ordering, do it in the environment that gives you the right **collation** controls.

## Examples

### Sort inside SQL (data stays in DB; uses index)
```sql
-- favorites(title TEXT) with an index on title
CREATE INDEX IF NOT EXISTS idx_favorites_title ON favorites(title);
SELECT title
FROM favorites
ORDER BY title ASC
LIMIT 20;
```

### Sort in Python (small CSV; custom key)
```python
import csv

with open("favorites.csv", newline="") as f:
    rows = list(csv.DictReader(f))

# custom: sort by length of title, then alphabetically
rows_sorted = sorted(rows, key=lambda r: (len(r["title"]), r["title"].lower()))

for r in rows_sorted[:10]:
    print(r["title"])
```

### Hybrid: coarse SQL + tie‑break in Python
```sql
-- SQL first-pass: get top 100 by frequency
SELECT title, COUNT(*) AS n
FROM favorites
GROUP BY title
ORDER BY n DESC, title ASC
LIMIT 100;
```
```python
# second-pass: apply domain-specific score in Python
def weird_score(title):
    return (title.startswith("The"), len(title))

top = sorted(sql_rows, key=lambda r: (weird_score(r["title"])))
```

## **Why It Matters**
Sorting where the data lives reduces **I/O** and uses the right **engine** for the job. Keep heavy, simple sorts in **SQL**; keep small or **highly customized** sorts in **Python**. This pattern scales from CS50’s **favorites.csv** demo to production ETL.

## Questions
- ❓Is your dataset already in SQLite? Then why pull it out to sort — can an **index** make `ORDER BY` cheap?
- ❓Is your rule something like “by emoji count, then by vowel‑weight”? That’s a **Python sort key** smell.
- ❓What’s the break‑even size where the cost of importing to SQL outweighs Python’s simplicity?

## Related Concepts
- [[CSV — Comma-Separated Values]] – small flat files often sorted in Python before import.
- [[Flat-file Database]] – when your “database” is just a file, Python sorting is common.
- [[SQL — SELECT WHERE ORDER BY]] – push filtering/sorting into the database.
- [[Indexes — B-trees & Performance]] – how ORDER BY gets fast.
- [[SQL Joins — INNER vs LEFT]] – combine tables before you sort.
- [[ETL — Extract Transform Load]] – move code to data; minimize I/O.
- [[Python — List sort vs sorted]] – choosing keys, stability, and custom comparators.
- [[Database vs Application Logic]] – deciding where work should live.

## See also
- Python `sorted` and `.sort()` docs: https://docs.python.org/3/howto/sorting.html  
- SQLite ORDER BY: https://sqlite.org/lang_select.html#orderby  
- CS50 Week 7: Sorting & SQL context: https://cs50.harvard.edu/x/2025/weeks/7/

## Terms
[[ORDER BY]], [[index]], [[collation]], [[I/O]], [[query planner]], [[natural sort]], [[ETL]], [[SQLite]], [[CSV]], [[sorted()]]
