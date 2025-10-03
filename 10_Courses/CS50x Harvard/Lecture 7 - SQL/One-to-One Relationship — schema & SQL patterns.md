---
title: "One-to-One Relationship — schema & SQL patterns"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 12
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "01:31:00"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 19.37.52.png]]

## Summary
A **one-to-one relationship** means each row in table **A** matches **at most one** row in table **B**, and vice‑versa. In practice it’s often **zero-or-one ↔ zero-or-one** (e.g., each user optionally has one profile). You enforce it with **PRIMARY KEY**, **UNIQUE**, and **FOREIGN KEY** constraints.

## Very simple
Think of **student ↔ ID card**: one student has one card; one card belongs to one student.

## Why/when to use
- Split rarely used or private columns into a separate table (**profiles**, **settings**, **secrets**) to keep the main row lean.  
- Optional data: keep `users` even if they don’t have a profile yet.  
- Security/permissions: store sensitive data with tighter access.

## Patterns in SQLite

### Pattern A — Shared Primary Key (strict 1↔1)
`profiles.id` is **both** the primary key and a foreign key to `users.id`.
```sql
CREATE TABLE users (
  id     INTEGER PRIMARY KEY,
  email  TEXT NOT NULL UNIQUE
);

CREATE TABLE profiles (
  id        INTEGER PRIMARY KEY,              -- same value as users.id
  full_name TEXT,
  bio       TEXT,
  FOREIGN KEY (id) REFERENCES users(id) ON DELETE CASCADE
);
```
- Guarantees: each `users.id` has **0 or 1** row in `profiles`; each `profiles.id` matches **exactly one** `users.id`.

### Pattern B — Unique Foreign Key (also 1↔1)
`profiles.user_id` is unique and references `users(id)`.
```sql
CREATE TABLE profiles (
  id       INTEGER PRIMARY KEY,
  user_id  INTEGER NOT NULL UNIQUE,          -- uniqueness enforces 1↔1
  full_name TEXT,
  FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
);
```
- Same effect; a bit more flexible if you want a separate `profiles.id` for internal use.

### Insert, join, and clean up
```sql
INSERT INTO users(email) VALUES ('alice@example.com');
INSERT INTO profiles(id, full_name) VALUES (last_insert_rowid(), 'Alice A.');
/* or Pattern B:
INSERT INTO profiles(user_id, full_name) VALUES (last_insert_rowid(), 'Alice A.');
*/

-- Fetch user with profile
SELECT u.email, p.full_name
FROM users u
LEFT JOIN profiles p ON p.id = u.id;   -- Pattern A (or p.user_id = u.id for Pattern B)

-- Delete user and cascade profile
DELETE FROM users WHERE id = 1;  -- profile row is removed by ON DELETE CASCADE
```

## Gotchas
- One-to-one often really means **zero-or-one** on one or both sides; model optionality with **NULL** or a **LEFT JOIN** in queries.  
- Don’t rely on application logic alone — enforce with **UNIQUE** or a shared **PRIMARY KEY**.  
- Remember to enable foreign keys in SQLite shells/scripts: `PRAGMA foreign_keys = ON;`.  
- For frequently joined 1↔1 tables, consider merging columns back into one table if it improves simplicity without hurting normalization.

## Related Concepts
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]] – ratings can be modeled close to 1↔1 with shows.
- [[Keys — Primary & Foreign]] – constraints that make 1↔1 real.
- [[Normalization — 1NF 2NF 3NF]] – when to split vs merge.
- [[SQL Joins — INNER vs LEFT]] – re‑stitch 1↔1 tables in queries.
- [[Indexes — B-trees & Performance]] – speed FK lookups.
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]] – daily toolkit on top.
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]] – portability notes.
- [[IMDb — Big Real-World Database (CS50 usage)]] – see how IDs connect entities.

## See also
- SQLite foreign keys: https://sqlite.org/foreignkeys.html  
- SQLite UNIQUE constraint: https://sqlite.org/lang_createtable.html#unique  
- Discussion of 1-to-1 designs (shared PK vs unique FK): https://en.wikipedia.org/wiki/One-to-one_(data_model)

## Terms
[[one-to-one relationship]], [[shared primary key]], [[unique constraint]], [[foreign key]], [[ON DELETE CASCADE]], [[LEFT JOIN]], [[last_insert_rowid()]], [[PRAGMA foreign_keys]]
