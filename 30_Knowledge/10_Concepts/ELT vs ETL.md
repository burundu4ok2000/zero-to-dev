
> **One-liner:** Both move data to analytics, but **ETL transforms before loading**, while **ELT loads raw first and transforms inside the warehouse**. [[Concepts]]

---

## The Big Idea

The choice is about **where** heavy transformations run:

- **ETL:** app/code layer (outside the warehouse), then load the cleaned result.
    
- **ELT:** warehouse/lakehouse engine (SQL/dbt) does the transformations after loading raw.
    

---

## Side-by-Side (at a glance)

|Aspect|**ETL** (Extract → Transform → Load)|**ELT** (Extract → Load → Transform)|
|---|---|---|
|Transform runs in|External compute (Python/Spark/ETL tool)|Warehouse/lakehouse SQL engine|
|Raw data landed?|Usually **no** (only cleaned data lands)|Usually **yes** (raw/staging preserved)|
|Speed to ingest|Slower (transform first)|Faster (load now, transform later)|
|Governance|Enforced before landing|Enforced via warehouse policies/tests|
|Cost model|ETL infra + warehouse|Mostly warehouse compute/storage|
|Flexibility|Good for strict pre-load rules|Great for SQL-first modeling & backfills|

---

## When to Choose Which

**Pick ETL if:**

- You must **clean/redact PII before landing** anywhere.
    
- Source data needs heavy **validation/reshape** that the warehouse shouldn’t see.
    
- You’re **bandwidth-constrained** and only want curated data stored.
    
- You’re on **legacy/on-prem** stacks with established ETL tooling.
    

**Pick ELT if:**

- You have a strong **cloud warehouse/lakehouse** (Snowflake, BigQuery, Databricks).
    
- Your team is **SQL/dbt-first** and wants versioned, in-warehouse models.
    
- You want **raw history for audit/replay/backfills**.
    
- You prefer to **iterate quickly**: load now, refine transforms later.
    

---

## Minimal Flows

```plaintext
ETL:  [Sources] → Extract → Transform (outside) → Load → [Warehouse]
ELT:  [Sources] → Extract → Load (raw) → Transform (SQL/dbt) → [Analytics]
```

---

## Common Pitfalls to Avoid

- **ETL:** Long cycles; losing raw history; overusing row-by-row code instead of set-based ops.
    
- **ELT:** Raw layer grows without **quality tests**; unclear ownership of models; “transform later” that never happens.
    

---

## See also

[[ETL]] · [[ELT]] · [[Data Warehouse]] · [[Data Lakehouse]] · [[Data Quality]] · [[Orchestration & DAGs]] · [[CDC (Change Data Capture)]]

---