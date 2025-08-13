---
title: "Dates, Times & Time Zones in SQL"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/sql"
atom_idx: 11
status: "in-progress"
difficulty: "easy"
date: "2025-08-13"
timecode: ""
source: ""
review_next: "2025-09-13"
---

![[Dates, Times & Time Zones in SQL.png]]

## **One-liner**
Handle **DATE/TIME/TIMESTAMP** and **time zones** correctly: store **UTC**, query with **half-open ranges**, convert at the **edges**, and watch out for **DST** traps.

## The Big Idea
- Keep a **canonical UTC** timestamp in storage; convert to local time only for presentation or user-specific logic.
- Use **half-open intervals** (`>= start AND < next_start`) for ranges to avoid off-by-one errors.
- Treat **time zone** as metadata: either store a separate `tz` field (user/site tz) or infer from context only when safe.
- Prefer **TIMESTAMP WITHOUT TZ** + explicit conversions in warehouses that don’t have full timezone types; in Postgres, `timestamptz` is convenient for automatic UTC handling.

## Core Concepts
- **DATE** — calendar date (no time).  
- **TIME** — wall-clock time (no date).  
- **TIMESTAMP** — date+time; may be **WITH** or **WITHOUT** time zone depending on engine.  
- **UTC** — Coordinated Universal Time; stable across regions and DST.  
- **DST** — daylight saving time: some local times **repeat** or **don’t exist**.  
- **Rounding/Truncation** — use **date_trunc** to bucket by hour/day/week.  
- **ISO week** — `IYYY-IW` differs from calendar week in some years.

## Examples

### 1) Half-open monthly range (sargable)
```sql
where event_ts >= timestamp '2025-01-01 00:00:00+00'
  and event_ts <  timestamp '2025-02-01 00:00:00+00';
```

### 2) Convert local → UTC (PostgreSQL)
```sql
-- Interpret a local timestamp in Europe/Amsterdam and convert to UTC (timestamptz)
select timestamp '2025-03-30 02:30:00' at time zone 'Europe/Amsterdam' as utc_ts;
-- Note: 2025-03-30 02:30 doesn't exist in AMS due to DST jump; engine adjusts.
```

### 3) Convert UTC → local for presentation (PostgreSQL)
```sql
select (event_ts at time zone 'Europe/Amsterdam') as event_local
from events;
```

### 4) date_trunc and extract
```sql
select
  date_trunc('day', event_ts) as day,
  extract(isodow from event_ts) as iso_dow,
  extract(epoch from event_ts) as epoch_seconds
from events;
```

### 5) Bucketing by hour (warehouse-friendly)
```sql
select
  date_trunc('hour', event_ts) as hour,
  count(*) as cnt
from events
where event_ts >= timestamp '2025-08-01 00:00:00+00'
  and event_ts <  timestamp '2025-08-02 00:00:00+00'
group by hour
order by hour;
```

### 6) Avoid non-sargable casts
```sql
-- bad: function on column blocks pruning
where date(event_ts) = date '2025-08-13'
-- good:
where event_ts >= timestamp '2025-08-13 00:00:00+00'
  and event_ts <  timestamp '2025-08-14 00:00:00+00';
```

## DST Pitfalls
- **Missing hour** at spring-forward (e.g., Europe/Amsterdam 2025‑03‑30 02:00→03:00): some local times **don’t exist**.  
- **Repeated hour** at fall-back (e.g., 2025‑10‑26 around 03:00): local times can occur **twice**.  
- Always store UTC; when converting, be explicit about the **zone** and lean on engine TZ rules.

## Warehouses & Dialects
- **BigQuery/Snowflake/Redshift**: lack a full `timestamptz` type like Postgres; store UTC and convert with built-ins (e.g., `TIMESTAMP`, `CONVERT_TIMEZONE`, `AT TIME ZONE`-like functions per engine).  
- Ensure your client/BI tool doesn’t **auto-apply** a session timezone that changes results.

## Practical Patterns
- Maintain a **dim_date** table for calendar logic (holidays, week numbers, fiscal periods).  
- Keep both `event_ts_utc` and optional `event_tz` (`Europe/Amsterdam`) if local wall-clock is needed for business rules.  
- For multi-tenant apps, compute **local day** columns (`event_local_day`) via ETL for easy grouping.  
- Normalize **precision** (seconds vs milliseconds) and document it in the schema/contract.

## Gotchas
- Comparing `TIMESTAMP WITH TZ` and `WITHOUT` can implicitly convert; be explicit.  
- Using `BETWEEN` for timestamp ranges includes the end → duplicates at boundaries. Prefer half-open.  
- Relying on `DATE(event_ts)` in WHERE → full scans; rewrite as range.  
- Week-based reporting without clarifying **week definition** (calendar vs ISO) yields mismatches.  
- Locale formats when parsing strings (`dd/mm` vs `mm/dd`) — parse at ingest.

## Interview Checks (self-test)
- Write a query for the last full **calendar month** using half-open ranges.  
- Convert a UTC column to **Europe/Amsterdam** and group by local **day**.  
- Explain DST issues and how UTC + explicit conversion avoids them.  
- Show how to get ISO week and year for a given timestamp.

## Related Concepts
- [[Filtering & Predicates (WHERE, IN, BETWEEN, LIKE)]]  
- [[Ordering & Pagination (ORDER BY, LIMIT-OFFSET, Keyset)]]  
- [[SQL Data Types & Casting Essentials]]  
- [[Aggregations & GROUP BY and HAVING]]  
- [[SQL Patterns & Window Functions for Data Engineers]]  
- [[Query Optimization Basics & EXPLAIN Lite]]

## See Also
- PostgreSQL: Date/Time functions — https://www.postgresql.org/docs/current/functions-datetime.html  
- BigQuery: Date/Time functions — https://cloud.google.com/bigquery/docs/reference/standard-sql/date_functions  
- Snowflake: Date/Time functions — https://docs.snowflake.com/en/sql-reference/functions-date-time

## Terms
[[date]], [[time]], [[timestamp]], [[timestamp with time zone]], [[timestamptz]], [[timestamp without time zone]], [[utc]], [[offset]], [[time zone]], [[dst]], [[daylight saving time]], [[date_trunc]], [[extract]], [[epoch]], [[iso week]], [[time bucket]], [[half-open interval]], [[calendar table]], [[local time]], [[conversion]]
