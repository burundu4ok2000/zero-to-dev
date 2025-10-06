---
title: "sqlite3 shell — Import CSV into SQLite (dot-commands)"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 05
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "00:46:xx"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 16.47.18.png]]

## Summary
This is the **sqlite3** command-line workflow David shows to turn a **CSV** into a real **SQLite** table using shell **dot-commands**: create/open a database file, switch to **CSV mode**, **import** the file into a table, then **query** it with SQL.

## Very simple
> Think: “pouring a spreadsheet into a smart box.”  
You open the box (**favorites.db**), tell it “I’m about to pour **CSV**,” then pour (**.import**). Now the data is queryable with **SQL**.

## What he typed (explained)
```bash
$ sqlite3 favorites.db            # open (or create) a SQLite DB file
sqlite> .mode csv                 # parse incoming data as CSV
sqlite> .import favorites.csv favorites   # load file into table 'favorites'
sqlite> .quit                     # leave the shell
$ ls
favorites.csv  favorites.db  favorites.py
```
- **sqlite3 favorites.db** — creates/open a **.db** file and drops you into the SQLite shell (`sqlite>`).  
- **.mode csv** — a **dot-command** (shell command, not SQL) that tells the shell how to read/write text.  
- **.import favorites.csv favorites** — bulk-load the CSV into a table named **favorites**.  
  - If the table **doesn’t exist**, recent sqlite3 builds will **create it** using the CSV’s **header row** as column names and default each column to **TEXT** (convenient but lossy).  
  - If the table **exists**, every row (including header) is treated as data; create the table first or use `--skip 1` in newer shells.
- **.quit** — exit; the **favorites.db** file now contains your table.

## Best practice (safer schema first)
```sql
-- inside sqlite3
CREATE TABLE IF NOT EXISTS favorites (
  name  TEXT    NOT NULL,
  title TEXT    NOT NULL
);
.mode csv
.import favorites.csv favorites
```
Creating the table first lets you enforce **types** and **constraints** and avoid bad data. `IF NOT EXISTS` prevents duplicate‑table errors.

## Useful dot-commands
```
.schema favorites     -- show CREATE TABLE statement
.headers on           -- print column headers in query output
.mode column          -- prettier columns for SELECT output
.separator ';'        -- change delimiter if it's not a comma
.nullvalue NULL       -- choose how NULL prints
.help import          -- see .import flags (e.g., --skip)
```

## Quick sanity checks after import
```sql
SELECT COUNT(*) FROM favorites;

SELECT title, 
COUNT(*) AS n 
FROM favorites 
GROUP BY title 
ORDER BY n 
DESC LIMIT 10;
```
If you’ll sort/filter a lot, add an **index**:
```sql
CREATE INDEX IF NOT EXISTS idx_favorites_title ON favorites(title);
```

## Python alternative (programmatic import)
```python
import csv, sqlite3
con = sqlite3.connect("favorites.db")
cur = con.cursor()
cur.execute("""CREATE TABLE IF NOT EXISTS favorites(
  name TEXT NOT NULL, title TEXT NOT NULL)""")
with open("favorites.csv", newline="") as f:
    rows = list(csv.reader(f))[1:]  # skip header
cur.executemany("INSERT INTO favorites(name,title) VALUES(?,?)", rows)
con.commit(); con.close()
```

## Why it matters
Dot-commands make **bulk import** trivial so you can use real **SQL** (GROUP BY, ORDER BY, JOIN) instead of ad‑hoc parsing. It’s your on‑ramp from **flat-file** to **relational**.

## Related Concepts
- [[CSV — Comma-Separated Values]] – the file we import.  
- [[Flat-file Database]] – what CSV is before SQL.  
- [[When to use Python instead of SQL (Sorting)]] – don’t pull millions of rows out just to sort.  
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]] – when SQLite is enough vs Postgres/MySQL.  
- [[SQL — SELECT WHERE ORDER BY]] – first queries to run after import.  
- [[Indexes — B-trees & Performance]] – make lookups fast.  
- [[Data Cleaning — Quotes, Escapes, Newlines]] – common CSV gotchas.  
- [[SQLite Shell — Dot Commands]] – reference for `.schema`, `.mode`, `.import`.

## See also
- SQLite import CSV tutorial: https://www.sqlitetutorial.net/sqlite-import-csv/  
- SQLite CLI reference: https://sqlite.org/cli.html#csv_import  
- CS50 Week 7 page: https://cs50.harvard.edu/x/2025/weeks/7/  
- CSV virtual table (advanced): https://www.sqlite.org/csv.html

## Terms
[[sqlite3]], [[dot-command]], [[.mode csv]], [[.import]], [[schema]], [[TEXT]], [[constraint]], [[index]], [[CSV]], [[GROUP BY]], [[ORDER BY]]
