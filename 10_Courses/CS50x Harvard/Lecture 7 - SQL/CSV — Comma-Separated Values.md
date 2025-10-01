---
title: "CSV — Comma-Separated Values"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 02
status: "in-progress"
difficulty: "easy"
date: "2025-10-01"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-01 at 17.15.11.png]]


## Summary
CSV is a plain-text tabular format: each line is a record (row), fields are separated by a delimiter (commonly a comma), with an optional header row naming the columns. It’s lightweight and human-readable, but lacks built-in schema, types, and constraints.

## Very simple
> Explain CSV in simple terms that a 5-year-old would understand:
    1. Imagine a notebook where each line lists a kid’s name and favorite show.
    2. We put a comma between pieces so the computer knows where one ends.
    3. If a piece has a comma inside, we wrap it in quotes so it doesn’t spill.

## Key Points
- Text-based table: one row per line; fields split by a delimiter (`,` default, but `;` or `\t` also appear).  
- Uses quotes (`"..."`) to wrap fields that contain commas or newlines; double quotes inside become `""`.  
- Often includes a header row for column names.  
- Distinguishes between empty string and missing/NULL only by convention (depends on parser/tool).  
- Easy to share and import (e.g., SQLite .mode csv + .import in CS50).  
- No types/constraints/indexes → good for small data; fragile and slow for growing datasets.

## Details
CSV is part of the flat-file family: portable, tooling-friendly, and great for data exchange. In CS50 Week 7, CSV files (like `favorites.csv`) are loaded into SQLite with shell dot-commands. After import, you can use SQL to GROUP BY, ORDER BY, and COUNT efficiently — something that is clumsy on raw CSV.

## Examples

### Minimal CSV
```

name,title  
Alice,The Office  
Bob,The Crown  
Charlie,The Office

```

### CSV with commas/newlines (quote & escape)
```

name,title  
"Smith, John","Everything ""Everywhere"", Again"  
"Lee, Ana","Multi-line  
note allowed in quotes"

````

### CS50 → Import CSV into SQLite (favorites example)
```sql
-- In sqlite3 shell:
.mode csv
.import favorites.csv favorites       -- file -> table

-- Query top shows after import:
SELECT title, COUNT(*) AS n
FROM favorites
GROUP BY title
ORDER BY n DESC
LIMIT 10;
````

### CS50 → Create table with types before importing (safer)

```sql
CREATE TABLE favorites (
  name  TEXT    NOT NULL,
  title TEXT    NOT NULL
);
.mode csv
.import favorites.csv favorites
```

## **Why It Matters**

CSV is the everywhere format — perfect for moving data between apps, quick analysis, or seeding a small SQLite database. As soon as you need reliable types, validation, and performance, switch from CSV files to proper SQL tables with keys and indexes.

## Questions

- ❓When should a CSV be replaced by a real table with constraints?
    
- ❓What delimiter/quote rules does your tool follow (RFC 4180 vs custom)?
    
- ❓How do you represent NULL vs empty strings consistently across tools?
    

## Related Concepts

- [[Flat-file Database]] – CSV is the most common flat-file format.
    
- [[SQL — SELECT WHERE ORDER BY]] – querying the imported data.
    
- [[SQL Joins — INNER vs LEFT]] – combine tables once data leaves CSV-land.
    
- [[Keys — Primary & Foreign]] – add identity and relationships after import.
    
- [[Normalization — 1NF 2NF 3NF]] – structure the data beyond one wide CSV.
    
- [[Indexes — B-trees & Performance]] – speed after the import.
    
- [[SQLite Shell — Dot Commands]] – .mode csv, .import, etc.
    
- [[Data Cleaning — Quotes, Escapes, Newlines]] – common pitfalls when parsing.
    

## See also

- [[SQL Cheat Sheet]]
    
- RFC 4180 — Common CSV rules (Wikipedia summary): [https://en.wikipedia.org/wiki/Comma-separated_values](https://en.wikipedia.org/wiki/Comma-separated_values)
    
- SQLite import docs (shell): [https://sqlite.org/cli.html#csv_import](https://sqlite.org/cli.html#csv_import)
    
- CS50 Week 7 page: [https://cs50.harvard.edu/x/2025/weeks/7/](https://cs50.harvard.edu/x/2025/weeks/7/)
    

## Terms

[[CSV]], [[delimiter]], [[header row]], [[record]], [[field]], [[quote]], [[escape]], [[NULL]], [[SQLite]], [[.mode csv]], [[.import]], [[GROUP BY]], [[ORDER BY]], [[COUNT]]
