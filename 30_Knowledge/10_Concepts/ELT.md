
  

> **One-liner:** **ELT** is **Extract → Load → Transform**: load raw data into the warehouse first, then transform it **inside** the warehouse. [[Concepts]]

---

## **The Big Idea**

  

Modern cloud warehouses (e.g., Snowflake, BigQuery) are powerful and cheap to scale, so you **load raw data as-is** and perform cleaning, joins, and modeling **with SQL/dbt in the warehouse**. This keeps raw data available for audit/replay and lets you reuse the warehouse’s speed and governance.

---

## **The Three Steps (at a glance)**

|**Step**|**What it means (plain English)**|**Tiny example**|
|---|---|---|
|**Extract**|Pull from sources (APIs, files, databases).|Download yesterday’s orders JSON.|
|**Load**|Land raw/staging tables in the warehouse.|Copy JSON → raw.orders_2025_08_02.|
|**Transform**|Clean/validate/model with SQL inside the warehouse.|Create analytics.orders via dbt.|

Minimal flow:

```
[ Sources ] → Extract → Load → Transform → [ BI / ML ]
```

---

## **Why Teams Choose ELT**

- **Speed to ingest:** get data in quickly; transform later.
    
- **Warehouse power:** push heavy work to scalable SQL engines.
    
- **Reproducibility:** raw layer stays intact; models are versioned code.
    

---

## **When ELT Makes Sense**

- You have a **strong warehouse** and mostly tabular analytics.
    
- You need **raw history** for audits/backfills.
    
- You prefer **SQL-first** transformations (e.g., **dbt**).
    

  

(If sensitive data must be cleaned **before** landing, consider [[ETL]].)

---

## **See also (details in separate notes)**

- [[ETL vs ELT]] — trade-offs and patterns
    
- [[Data Warehouse]] — the usual ELT destination
    
- [[Data Lakehouse]] — open files + ACID tables
    
- [[Data Pipeline]] — end-to-end orchestration
    
- [[Data Quality]] — tests for freshness/uniqueness/validity
    

---