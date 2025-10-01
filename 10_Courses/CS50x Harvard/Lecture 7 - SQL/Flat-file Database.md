---
title: Flat-file Database
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 1
status: in-progress
difficulty: easy
date: 2025-10-01
timecode: 00:04:38
source: https://cs50.harvard.edu/x/2025/weeks/7/
review_next: ""
---

![[Screenshot 2025-10-01 at 17.13.37.png]]

## Summary
A flat-file database is just a single file (often **CSV**) that stores data in rows and columns without enforced schema, constraints, or relationships. It’s quick and simple, but fragile and slow at scale.

## Very simple

> Explain flat-file database in simple terms that a 5-year-old would understand:
1. It’s like one big sheet of paper with a neat table.  
2. You can write anything in the boxes, but no one stops you from making mistakes.  
3. If the table gets huge, finding things becomes slow and messy.

## Key Points
- One file, usually text-based (**.csv**, **.tsv**).  
- No built-in types, unique keys, or foreign keys — you must self-discipline.  
- Great for tiny datasets, data exchange, and quick hacks.  
- Painful for search, updates, avoiding duplicates, and doing JOIN-like work.  
- RDBMS (e.g., SQLite, PostgreSQL) fix this with schemas, indexes, and constraints.

## Details
A flat file is literally a text file with delimited values. Because it lacks a formal schema, the computer won’t enforce “age must be a number” or “id must be unique.” You can read/write it with any language, but as the data grows, operations like filtering, grouping, and joining become slow and bug-prone. Relational databases add structure (tables with primary keys / foreign keys), validation (NOT NULL, UNIQUE), and performance features (indexes, query planner).

## Examples

### Minimal CSV (flat-file) example
```csv
id,name,age
1,Alice,21
2,Bob,19
3,Charlie,22
````

### Doing the same with SQL (preferred as data grows)

```sql
CREATE TABLE students (
  id INTEGER PRIMARY KEY,
  name TEXT NOT NULL,
  age INTEGER CHECK(age >= 0)
);

INSERT INTO students (name, age) VALUES ('Alice', 21), ('Bob', 19), ('Charlie', 22);
SELECT id, name FROM students WHERE age >= 20 ORDER BY name;
```

### Mini example from Week 6 — DNA Pset (flat-file in the wild)

The DNA pset ships with a CSV “database” of STR counts — each row is a person, each column is how many times a short DNA pattern repeats.

```csv
name,AGAT,AATG,TATC
Alice,3,1,4
Bob,2,5,3
Charlie,4,1,5
```

- This is a classic flat-file database: one file, one table, no enforced types or keys.
    
- In the pset, you read this file and compare it to a DNA sequence (another text file) to find a match — all without SQL.
    

## Why It Matters

Flat files are perfect when you just need to save/share small tabular data fast. But once you care about data integrity, relationships, and performance, you’ll graduate to SQL and real tables with keys, indexes, and joins.

## Questions

- ❓When does it make sense to keep data in a single CSV vs move to SQLite?
    
- ❓What simple invariants (like “id is unique”) would you enforce if this became SQL?
    
- ❓How would you split one large CSV into multiple related tables?
    

## Related Concepts

- [[00_Inbox/CSV — Comma-Separated Values]] – the most common flat-file format.
    
- [[SQL — SELECT WHERE ORDER BY]] – querying the imported data.
    
- [[SQL Joins — INNER vs LEFT]] – connect related tables instead of faking joins in code.
    
- [[Keys — Primary & Foreign]] – enforce identity and relationships.
    
- [[Normalization — 1NF 2NF 3NF]] – keep data tidy and consistent.
    
- [[Indexes — B-trees & Performance]] – speed up lookups beyond linear scans.
    
- [[Python — File I/O]] – reading/writing text files.
    
- [[DNA Pset — STR Matching]] – Week 6 example of a flat-file “database”.
    

## See also

- [[SQL Cheat Sheet]]
    
- [SQLite Language Reference](https://sqlite.org/lang.html)
    
- [CSV — Wikipedia](https://en.wikipedia.org/wiki/Comma-separated_values)
    
- [CS50x — Course Home](https://cs50.harvard.edu/x/2025)
    

## Terms

[[flat-file database]], [[text file]], [[delimiter]], [[table]], [[record]], [[field]], [[schema]], [[constraint]], [[SQLite]], [[query planner]]

