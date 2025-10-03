---
title: "SQL DELETE — Safe Usage, WHERE, and Rollback Habits"  
lang_tags: "#lang/sql"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_7_SQL"
tool_tags: "#tool/db/sqlite"
atom_idx: 09
status: "in-progress"
difficulty: "easy"
date: "2025-10-03"
timecode: "01:15:38"
source: "https://cs50.harvard.edu/x/2025/weeks/7/"
review_next: ""
---

![[Screenshot 2025-10-03 at 18.03.56.png]]

## Summary
**DELETE** removes rows from a table. With a **WHERE** clause you delete *some* rows. Without **WHERE** you delete **every row** in the table — same as “empty the table.” Use transactions (**BEGIN**, **COMMIT**, **ROLLBACK**) and a **SELECT dry‑run** to stay safe.

## Very simple
- Think of **DELETE** as the **eraser**.  
- **WHERE** is the **stencil** that limits what the eraser touches.  
- If you forget the stencil, you erase the whole page.

## What he typed (and why it’s scary)
```sql
DELETE FROM favorites;
```
This removes **all rows** from `favorites`. The table still exists (unlike **DROP**), but it’s empty.

## Safe patterns (SQLite)
```sql
-- 1) Dry run: see *exactly* what would be deleted
SELECT * FROM favorites
WHERE title = 'The Office';

-- 2) Delete inside a transaction
BEGIN TRANSACTION;
DELETE FROM favorites
WHERE title = 'The Office';
-- sanity check:
SELECT changes() AS rows_deleted;
-- if wrong:
ROLLBACK;
-- if correct:
COMMIT;
```

### Extra (SQLite-specific)
```sql
-- Narrow deletion with ordering/limit (SQLite supports this)
DELETE FROM favorites
WHERE title LIKE 'The %'
ORDER BY title
LIMIT 10;
```
Note: ORDER BY/LIMIT in DELETE isn’t portable to all SQL engines; it’s a convenience in SQLite.

## Common mistakes (how to avoid them)
- Running **DELETE FROM table;** on the wrong database or in **production**.  
  - Fix: work on a **copy**, or set `PRAGMA foreign_keys=ON;` and **BEGIN** before risky changes.
- Filtering in your head instead of in SQL.  
  - Fix: always **SELECT** the rows first with the same **WHERE**.  
- Thinking **ROLLBACK** can undo everything.  
  - Reality: if you didn’t **BEGIN**, you can’t roll back; keep **autocommit off** during edits.
- Confusing commands: **DROP TABLE** removes the whole table; **TRUNCATE** (in other DBs) quickly empties it; **DELETE** removes rows with optional **WHERE**.
- Cascades surprise: foreign keys with **ON DELETE CASCADE** may remove related rows. Understand relationships before deleting.

## Tiny stories you’ll remember
- **The classroom purge**: a newbie typed `DELETE FROM students;` during a demo — wiped the table, learned the holy trinity: **BEGIN → DELETE → SELECT changes() → COMMIT/ROLLBACK**.  
- **The missing WHERE**: someone filtered *after* exporting, not in SQL; they ran `DELETE FROM logs;` instead of a precise **WHERE** and spent the afternoon restoring from backup.  
- **The Bobby‑Tables‑ish prank**: a test script built SQL by string concatenation; a value like `x' OR 1=1 --` turned a targeted delete into a mass delete. Moral: always use **parameters**.

## Checklist before you press Enter
- Did I run the **SELECT dry‑run** with the exact **WHERE**?  
- Am I inside **BEGIN TRANSACTION** so I can **ROLLBACK**?  
- Does this table have **foreign keys** or **ON DELETE CASCADE**?  
- Do I really intend to affect **N** rows? `SELECT changes()` is your friend.

## Related Concepts
- [[SQL Clauses — WHERE, LIKE, GROUP BY, ORDER BY, LIMIT]] – filtering comes first.  
- [[SQL Clause Order — Syntax vs Execution + Common Mistakes]] – why WHERE vs HAVING matters.  
- [[sqlite3 shell — Import CSV into SQLite (dot-commands)]] – repopulate a table if needed.  
- [[CSV — Comma-Separated Values]] – quick way to restore small data.  
- [[SQL Functions — AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER]] – sanity checks after deletes.  
- [[SQLite 3 vs Other SQL Databases — What’s the difference?]] – DELETE portability notes.  
- [[Transactions — BEGIN COMMIT ROLLBACK]] – create this note next to drill safety.  
- [[Foreign Keys — ON DELETE CASCADE]] – understand ripple effects.

## See also
- SQLite DELETE: https://sqlite.org/lang_delete.html  
- SQLite transactions: https://sqlite.org/lang_transaction.html  
- CS50 Week 7 page: https://cs50.harvard.edu/x/2025/weeks/7/

## Terms
[[DELETE]], [[WHERE]], [[BEGIN TRANSACTION]], [[COMMIT]], [[ROLLBACK]], [[DROP TABLE]], [[TRUNCATE]], [[foreign key]], [[ON DELETE CASCADE]], [[changes()]], [[backup]]
