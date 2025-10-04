---
title: "Race Conditions — what they are and how to avoid them"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 16
status: "in-progress"
difficulty: "easy"
date: "2025-10-04"
timecode: "02:24:47"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-04 at 16.05.04.png]]

## Summary
A **race condition** happens when two or more clients try to read/change the **same data** at nearly the same time, and the final result depends on who “wins the race.” Typical symptom: the famous *check‑then‑insert* or *read‑modify‑write* that works in a single user script but breaks under concurrency. We fix this with **transactions**, **constraints**, and **locking** patterns.

## Very simple
Two kids grab the same cookie at once. If no rules, chaos. Databases provide rules: **one kid at a time** (locks) or **the jar refills/blocks duplicates** (constraints).

## Classic buggy pattern (don’t do this)
```sql
-- Seat reservation (BAD): two clients can both see 0 and both insert
SELECT COUNT(*) FROM seats WHERE seat_id = 42;  -- returns 0
INSERT INTO seats(seat_id, user_id) VALUES(42, 123);  -- race!
```
Between the SELECT and INSERT, another client can insert the same seat.

## Safer patterns (SQLite‑friendly)

### 1) Use constraints + UPSERT (best for uniqueness)
```sql
CREATE TABLE IF NOT EXISTS seats(
  seat_id INTEGER PRIMARY KEY,        -- UNIQUE guarantee
  user_id INTEGER NOT NULL
);

-- try to claim seat 42
INSERT INTO seats(seat_id, user_id)
VALUES (42, 123)
ON CONFLICT(seat_id) DO NOTHING;      -- prevents duplicates atomically
```
- Races collapse into **one winner**; losers do nothing.

### 2) Do the change atomically inside a transaction
```sql
PRAGMA foreign_keys = ON;
BEGIN IMMEDIATE;                       -- take a write lock early in SQLite
UPDATE inventory
SET qty = qty - 1
WHERE product_id = 7 AND qty > 0;      -- succeeds only if stock remains
SELECT changes() AS rows_changed;      -- 0 → out of stock
COMMIT;                                -- or ROLLBACK on error
```
- The **UPDATE** happens as a single unit; another writer waits.

### 3) SELECT … FOR UPDATE? (note)
- SQLite doesn’t support **SELECT … FOR UPDATE** like Postgres/MySQL. Use **BEGIN IMMEDIATE/EXCLUSIVE** to block competing writers, or redesign with **constraints**/**UPSERT**/**atomic UPDATEs**.

## Isolation levels (quick map)
- SQLite uses **SERIALIZABLE** semantics for transactions by default; writers serialize via a single writer lock. Reads don’t block reads, but a writer blocks other writers.  
- In other engines you’ll meet **READ COMMITTED**, **REPEATABLE READ**, **SERIALIZABLE**. Higher isolation → fewer anomalies → more waiting.

## Checklist to avoid races
- Can a **UNIQUE constraint** + **ON CONFLICT** solve it?  
- Wrap multi‑statement changes in a **transaction** (**BEGIN → COMMIT/ROLLBACK**).  
- Prefer **atomic** `UPDATE ... WHERE ...` or `INSERT ... ON CONFLICT` over “check then do”.  
- In SQLite, use **BEGIN IMMEDIATE** before hot paths so a second writer queues instead of interleaving.  
- Log the outcome (`SELECT changes()`), don’t assume success.

## Tiny examples

### Prevent double likes
```sql
CREATE TABLE likes(
  user_id INTEGER,
  post_id INTEGER,
  UNIQUE(user_id, post_id)            -- at most one like per user/post
);
INSERT INTO likes(user_id, post_id) VALUES(1, 99)
ON CONFLICT(user_id, post_id) DO NOTHING;
```

### Bounded counter
```sql
BEGIN IMMEDIATE;
UPDATE coupons
SET remaining = remaining - 1
WHERE code = 'CS50' AND remaining > 0;
SELECT changes() AS grabbed;           -- 1 = success, 0 = none left
COMMIT;
```

## Related Concepts
- [[SQL DELETE — Safe Usage, WHERE, and Rollback Habits]] – transaction muscle memory.  
- [[SQL Clause Order — Syntax vs Execution + Common Mistakes]] – why we filter in the right step.  
- [[CREATE TABLE + FOREIGN KEY (shows/ratings) — what it does]] – integrity between tables.  
- [[Indexes — speed up WHERE/JOIN/ORDER BY]] – performance (not correctness) under load.  
- [[TV Shows ERD — people ⇆ shows (stars, writers, genres, ratings)]] – where races appear (e.g., duplicating stars).  
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]] – isolation and locking differ by engine.  
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]] – the querying basics used in fixes.

## See also
- SQLite transactions & isolation: https://sqlite.org/lang_transaction.html  
- On locking behavior in SQLite (BEGIN IMMEDIATE/EXCLUSIVE): https://sqlite.org/lang_transaction.html#deferred_immediate_and_exclusive_transactions  
- UPSERT in SQLite: https://sqlite.org/lang_UPSERT.html  
- CS50 Week 7 page: https://cs50.harvard.edu/x/2025/weeks/7/

## Terms
[[race condition]], [[transaction]], [[isolation level]], [[SERIALIZABLE]], [[READ COMMITTED]], [[lock]], [[BEGIN IMMEDIATE]], [[EXCLUSIVE transaction]], [[UNIQUE constraint]], [[UPSERT]], [[ON CONFLICT]], [[atomic update]], [[ROLLBACK]], [[COMMIT]]
