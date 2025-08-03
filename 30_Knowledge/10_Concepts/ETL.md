

---

## **The Big Idea**

  

**ETL** = **Extract → Transform → Load**.

It’s the classic way to move data from messy, scattered sources into a clean, structured destination (usually a **data warehouse** or **data lakehouse**) so it’s ready for analytics, dashboards, and ML.

  

Why it exists:

- Source data is **inconsistent, incomplete, duplicated, noisy**.
    
- Business users need **trustworthy, fast** answers.
    
- ETL builds a **repeatable pipeline** that turns raw bits into usable facts.
    

---

## **The Flow at 10,000 ft**

```
[ Sources ] --Extract--> [ Raw/Staging ] --Transform--> [ Clean/Modeled ] --Load--> [ Warehouse / Lakehouse ]
      APIs  files  DBs              (unchanged copies)        (validated, typed)             (BI, ML, apps)
```

**Key idea:** Keep **raw** data unchanged for audit/replay; do your transformations in a **separate** step; then **load** the final, modeled data.

---

## **Each Step Explained (with examples)**

  

### **1) Extract — “Get the data safely”**

- **From:** REST APIs, CSV/JSON files, logs, sensors/IoT, relational DBs, message queues (Kafka), spreadsheets.
    
- **Concerns:** authentication, pagination, rate limits, incremental reads, network failures, schema drift.
    
- **Good practice:** write to **staging/raw** storage first (e.g., S3/GCS/Azure Blob), **don’t mutate** it.
    

  

### **2) Transform — “Make it correct and useful”**

  

Typical tasks:

- **Cleaning:** trim strings, standardize dates/timezones, handle nulls, fix encodings.
    
- **Validation:** enforce types, ranges, allowed values, uniqueness.
    
- **Shaping:** joins, aggregations, window functions, deduplication, pivot/unpivot.
    
- **Business logic:** dimensions & facts (Kimball), SCD handling, surrogate keys.
    
- **Enrichment:** lookup reference data, geocoding, currency/FX normalization.
    

  

### **3) Load — “Deliver fast access for consumers”**

- **Targets:** PostgreSQL, Snowflake, BigQuery, Redshift, Databricks, DuckDB.
    
- **Patterns:** truncate/insert, upsert/merge, partitioned append, batch vs micro-batch.
    
- **Concerns:** idempotency, primary keys, constraints, indexes, clustering, partitions.
    

---

## **ETL vs ELT (short take)**

- **ETL (classic):** heavy transforms happen **before** loading to the warehouse.
    
- **ELT (modern cloud):** load **raw** first, do transforms **inside** the warehouse (SQL/dbt).
    
- Rule of thumb: prefer **ELT** if your warehouse is powerful and cheap to scale; use **ETL** when you must clean data **before** it can land (e.g., PII redaction, strict contracts).
    

  

See also: [[ELT vs ETL]]

---

## **Storage Layers: Bronze / Silver / Gold**

|**Layer**|**Purpose**|**Rules of thumb**|
|---|---|---|
|Bronze|**Raw** snapshots/ingests|Immutable, append-only, exact copy of source|
|Silver|**Cleaned/standardized** data|Typed, validated, deduped; minimal business logic|
|Gold|**Modeled** (dim/fact, marts)|Business-ready; denormalized for analytics speed|

See also: [[Data Lakehouse: Bronze–Silver–Gold]]

---

## **File Formats & Why They Matter**

|**Format**|**Type**|**When to use**|
|---|---|---|
|CSV|Row, text|Small/simple, human-readable; **avoid** for big/typed data|
|JSON|Semi-struct|Nested events, logs; still row-oriented|
|Parquet|Columnar|Analytics at scale; compression + predicate pushdown = **fast**|
|Avro|Row, schema|Streaming & CDC records; strong schema evolution support|

Opinionated rule: for analytics, **prefer Parquet** (columnar) over CSV.

See also: [[File Formats: CSV, JSON, Parquet, Avro]]

---

## **Batch vs Streaming**

|**Mode**|**Description**|**Use cases**|**Tools**|
|---|---|---|---|
|Batch|Runs on a schedule (hourly, daily)|Reports, daily KPIs, backfills|Airflow, dbt, Spark, DuckDB|
|Streaming|Processes events continuously (low latency)|Real-time alerts, clickstreams|Kafka, Flink, Spark Streaming|

Tip: Start **batch** (simpler), move parts to **streaming** only when latency really matters.

See also: [[Batch vs Streaming]]

---

## **Incremental Loads & CDC**

- **Full load:** replace everything — simple but slow/expensive at scale.
    
- **Incremental load:** only new/changed rows (watermarks, updated_at, file lists).
    
- **CDC (Change Data Capture):** read inserts/updates/deletes from source logs (e.g., Debezium) to reproduce changes downstream.
    

  

Always design for **idempotency**: a rerun produces the same result.

See also: [[CDC (Change Data Capture)]]

---

## **Dimensional Modeling (Kimball) in 60 seconds**

- **Fact tables:** numeric measurements (sales, clicks), **FKs** to dimensions.
    
- **Dimension tables:** descriptive attributes (customer, product, date).
    
- **SCDs:** how you track changing dimension attributes:
    
    - **Type 1:** overwrite (no history)
        
    - **Type 2:** new row with validity period (history kept)
        
    

  

See also: [[Dimensional Modeling (Kimball)]]

---

## **Data Quality: Don’t Ship Garbage**

  

Checks to automate:

- **Freshness:** data is recent enough (e.g., daily before 07:00).
    
- **Completeness:** row counts, required fields not null.
    
- **Uniqueness:** primary keys have no duplicates.
    
- **Validity:** values in allowed sets/ranges; referential integrity OK.
    

  

Tooling: **dbt tests**, **Great Expectations**, **Deequ**.

Block loads when critical tests fail; alert loudly.

See also: [[Data Quality]]

---

## **Orchestration, DAGs, and Observability**

- **Orchestrators:** Airflow, Prefect, Dagster — define **DAGs** (task graph), retries, SLAs, backfills.
    
- **Observability:** logging (structured), metrics (latency, rows processed), tracing, **alerts** (on-call).
    
- **Backfills:** re-run historical ranges safely (idempotent + partitioned data helps).
    

  

See also: [[Orchestration & DAGs]]

---

## **Security, Privacy, Governance**

- **PII:** mask or hash sensitive fields; least-privilege access.
    
- **Encryption:** at rest and in transit (KMS/CMK).
    
- **Lineage & catalog:** know **where data came from** and who uses it (OpenLineage, DataHub, Amundsen).
    
- **Compliance:** GDPR, SOC 2—define retention and deletion policies.
    

---

## **Performance & Cost Tips**

- **Pushdown** work to where data lives (warehouse engine > Python loop).
    
- Use **columnar** formats + **partitioning** (by date/hour/tenant).
    
- Avoid SELECT * in production; **project only needed columns**.
    
- Prefer **set-based SQL** over row-by-row processing.
    
- Cache reference data; reuse connections; batch writes.
    
- Monitor **cost drivers:** scans read (bytes), slots/warehouses, shuffle.
    

---

## **A Minimal, Clean ETL (Python + SQL) — Structure**

```
# etl_users.py
import pandas as pd
from datetime import datetime
from utils import fetch_json, to_parquet, load_merge

RUN_TS = datetime.utcnow().isoformat()

def extract():
    data = fetch_json("https://api.example.com/users?active=true")
    return pd.DataFrame(data)

def transform(df: pd.DataFrame) -> pd.DataFrame:
    df = df.drop_duplicates(subset=["id"])
    df["email"] = df["email"].str.strip().str.lower()
    df["loaded_at"] = RUN_TS
    # validate
    assert df["id"].notna().all(), "id cannot be null"
    return df[["id", "name", "email", "loaded_at"]]

def load(df: pd.DataFrame):
    to_parquet(df, "s3://bronze/users/loaded_at=" + RUN_TS[:10])
    load_merge(df, table="analytics.users", key="id")  # upsert

def main():
    raw = extract()
    clean = transform(raw)
    load(clean)

if __name__ == "__main__":
    main()
```

Design notes:

- **Idempotent** (keyed upsert).
    
- **Validated** (assertions/tests).
    
- **Partition-aware** (date folder).
    
- **Separation of concerns** (E/T/L are distinct).
    
- Config (URLs, tables) should live in **YAML/env**, not in code.
    

---

## **Common Pitfalls (and fixes)**

- **Assuming sizes/schemas won’t change** → add **schema tests** & drift detection.
    
- **Writing directly to gold** → always keep **raw bronze**.
    
- **Row-by-row loops** → switch to **set-based SQL** or Spark.
    
- **Non-deterministic joins** (no keys) → define stable business keys or surrogate keys.
    
- **No backfill plan** → design **incremental & partitioned** from day one.
    
- **Silent failures** → add alerts on **missing data** and **row-count anomalies**.
    

---

## **Tools Landscape (you’ll see these a lot)**

|**Category**|**Examples**|
|---|---|
|Orchestrators|Airflow, Prefect, Dagster|
|Transforms|dbt (SQL models, tests), Spark, Pandas|
|Ingestion|Airbyte, Fivetran, Meltano, Kafka, Flume|
|Warehouses/LH|Snowflake, BigQuery, Redshift, Databricks|
|Quality/Lineage|Great Expectations, OpenLineage, DataHub|
|Storage|S3/GCS/ABFS, Hive Metastore/Unity Catalog|

---

## **What to Learn First (beginner roadmap)**

1. **SQL fundamentals** (SELECT, JOIN, GROUP BY, window functions).
    
2. **File formats & partitions** (Parquet + date partitioning).
    
3. **dbt or SQL-based modeling** (tests, docs, sources).
    
4. **Orchestration** basics (DAGs, retries, backfills).
    
5. **Data quality** checks and **idempotent** loads.
    
6. **Incremental** processing & basic **CDC** concepts.
    

---

## **Quick Checklist (before you ship)**

- Raw layer stored, immutable, versioned
    
- Transformations reproducible & code-reviewed
    
- Tests: freshness, uniqueness, not-null, referential integrity
    
- Loads are idempotent (safe to rerun)
    
- Monitoring + alerts in place
    
- Documented sources, models, and lineage
    

---

**Related notes:**

[[ELT vs ETL]] · [[Data Warehouse]] · [[Dimensional Modeling (Kimball)]] · [[Batch vs Streaming]] · [[CDC (Change Data Capture)]] · [[Data Quality]] · [[Orchestration & DAGs]] · [[File Formats: CSV, JSON, Parquet, Avro]] · [[Data Lakehouse: Bronze–Silver–Gold]]

---

Want a follow-up note? I can draft **“ELT vs ETL (when to choose which)”** or **“Dimensional Modeling in practice (SCD1/2 with examples)”** next.