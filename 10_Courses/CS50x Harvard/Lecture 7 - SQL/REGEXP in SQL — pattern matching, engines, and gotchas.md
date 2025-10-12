---
title: "REGEXP in SQL — pattern matching, engines, and gotchas"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/mysql"
atom_idx: 23
status: "in-progress"
difficulty: "easy"
date: "2025-10-05"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---
![[Screenshot 2025-10-12 at 18.17.37.png]]
![[Screenshot 2025-10-12 at 18.18.52.png]]

## Summary
**REGEXP** lets you match a **pattern** (a **regular expression**) inside text. In SQL it’s usually used in a **WHERE** clause to filter rows. Support differs by engine:
- **MySQL 8+**: `REGEXP` / `REGEXP_LIKE()` using the **ICU** regex engine.
- **PostgreSQL**: POSIX regex operators `~` (case‑sens), `~*` (case‑insens), and their negations `!~`, `!~*`.
- **SQLite**: no built‑in `REGEXP` operator by default; you can add a user‑defined function or use `GLOB`/`LIKE` for simple patterns.
- Standard SQL also has **SIMILAR TO** (simpler, SQL‑ish regex).

Use **REGEXP** when **LIKE** is too limited, but remember: regex can be slower than indexed **WHERE**s unless paired with the right indexes (e.g., **prefix** anchors).

## Very simple
“Keep rows whose text **fits this mold**.” Example: cities that start with a vowel:
```sql
-- MySQL
SELECT city FROM places WHERE city REGEXP '^[AEIOUaeiou]';
-- Postgres
SELECT city FROM places WHERE city ~ '^[AEIOUaeiou]';
```

## Regex atoms (mini‑primer)
| Symbol | Meaning | Example |
|---|---|---|
| `^` | start of string | `^A` → starts with “A” |
| `$` | end of string | `a$` → ends with “a” |
| `.` | any single char | `c.t` → `cat`, `cot`, `cut` |
| `[AEIOUaeiou]` | **character class** (any one of …) | `[abc]` → `a` or `b` or `c` |
| `[^...]` | **negated class** | `[^0-9]` → any non‑digit |
| `*` | 0 or more repeats | `ba*` → `b`, `ba`, `baa`… |
| `+` | 1 or more repeats | `ba+` → `ba`, `baa`… |
| `?` | 0 or 1 (optional) | `Nov(ember)?` |
| `{n,m}` | from n to m repeats | `a{2,4}` → `aa`…`aaaa` |
| `|` | **alternation** (OR) | `cat|dog` |
| `()` | **grouping** / backrefs | `(ab)+` → `ab`, `abab`… |

## Handy SQL examples
### 1) Starts/ends with a vowel
```sql
-- MySQL
WHERE city REGEXP '^[AEIOUaeiou]'
-- or ends with a vowel
WHERE city REGEXP '[AEIOUaeiou]$'
```

### 2) Contains a digit anywhere
```sql
WHERE city REGEXP '[0-9]'
```

### 3) No vowels at all
```sql
WHERE city NOT REGEXP '[AEIOUaeiou]'
```

### 4) Case‑insensitive match via collation (MySQL)
```sql
WHERE city REGEXP '^[aeiou]' COLLATE utf8mb4_general_ci
```
Postgres alternative: use `~*` (case‑insensitive):
```sql
WHERE city ~* '^[aeiou]'
```

### 5) Word boundaries (engine‑dependent)
```sql
-- MySQL ICU: use Unicode property classes or () in many cases
WHERE title REGEXP '\bOffice\b'
-- Postgres supports \m (start of word) / \M (end of word) in some builds
```

## Engine notes (behavior differences)
- **MySQL 8** uses ICU: full Unicode, modern features. Older MySQL pre‑8 used a limited engine. Prefer `REGEXP_LIKE(col, pat)` for clarity.
- **PostgreSQL** uses POSIX‑style regex. Use `~*` for case‑insensitive searches; `SIMILAR TO` exists but is rarely needed.
- **SQLite** ships without regex; to use `REGEXP`, you must load an extension or define a C/SQL function. For simple prefix/suffix matches, prefer `LIKE 'abc%'` or `GLOB 'abc*'`.
- **Indexes**: regex with a **leading anchor** (e.g., `^The`) can leverage a **B‑tree** index via a planner trick in some engines; otherwise expect a full scan. For heavy use, consider **expression indexes** (e.g., `UPPER(name)`) plus simpler predicates.

## Pitfalls & performance
- `LIKE '%foo'` and `REGEXP 'foo$'` both break prefix indexing—expensive on big tables.
- Regex on huge text fields can be slow; try to **pre‑filter** with simpler conditions first.
- Greedy patterns (`.*`) can surprise you. Prefer bounded quantifiers like `{0,40}`.
- Always **EXPLAIN** your query to see whether an index is used.

## Testing recipes
```sql
-- MySQL: quickly test patterns
SELECT 'Carell' REGEXP 'Car.*';         -- returns 1 or 0
SELECT REGEXP_LIKE('Office', '^Off');   -- 1

-- Postgres:
SELECT 'Carell' ~ 'Car.*';
SELECT 'office' ~* '^off';              -- case-insensitive
```

## Related Concepts
- [[SQL Basics — SELECT, WHERE, ORDER BY, LIMIT (tiny patterns)]]
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]]
- [[Indexes — speed up WHERE/JOIN/ORDER BY]]
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]]
- [[SQL CRUD Basics — SELECT, INSERT, UPDATE, DELETE]]
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]]

## See also
- MySQL `REGEXP_LIKE` and regex functions: https://dev.mysql.com/doc/refman/8.0/en/regexp.html  
- PostgreSQL pattern matching (`~`, `SIMILAR TO`): https://www.postgresql.org/docs/current/functions-matching.html  
- SQLite and regular expressions (user-defined `REGEXP`): https://sqlite.org/lang_expr.html#regexp  
- Regular‑expression basics (MDN): https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_expressions/Cheatsheet

## Terms
[[REGEXP]], [[regular expression]], [[pattern]], [[character class]], [[negated class]], [[anchor]], [[quantifier]], [[alternation]], [[group]], [[ICU]], [[POSIX regex]], [[SIMILAR TO]], [[GLOB]], [[collation]]
