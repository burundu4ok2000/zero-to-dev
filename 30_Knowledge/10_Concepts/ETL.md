
> **One-liner:** ETL is the process of **Extract → Transform → Load** for moving data from sources to an analytics-ready destination. [[Concepts]]

---

## **The Big Idea**

  

**ETL** is a repeatable pipeline that **collects raw data**, **cleans/shapes it**, and **stores** the result in a system built for analysis (e.g., a **data warehouse** or **lakehouse**).

Goal: turn messy inputs into **trustworthy, structured tables** for dashboards, reports, and ML.

---

## **The Three Steps (at a glance)**

|**Step**|**What it means (plain English)**|**Tiny example**|
|---|---|---|
|**Extract**|Pull data from sources (APIs, files, databases).|Download yesterday’s orders as JSON.|
|**Transform**|Clean, validate, and reshape the data.|Fix dates, dedupe by order_id.|
|**Load**|Write the final result to the destination.|Upsert into analytics.orders table.|

Minimal flow:

```
[ Sources ] → Extract → Transform → Load → [ Warehouse/Lakehouse ]
```

---

## **Why It Exists (beginner-friendly)**

- **Raw data is messy:** missing values, different formats, duplicates.
    
- **Analytics need structure:** typed columns, clear keys, stable schemas.
    
- **Repeatability:** the same steps run on a schedule and produce the same result.
    

---

## **Tiny Pseudo-Example**

```
1) Extract: read orders_2025-08-02.json from the API
2) Transform: keep paid orders, parse timestamps, drop duplicates by order_id
3) Load: upsert rows into analytics.orders (safe to rerun)
```

---

## **See also**

- [[ELT vs ETL]] — when to transform **before** vs **inside** the warehouse
    
- [[Data Warehouse]] — the typical ETL destination
    
- [[Data Lakehouse]] — files + tables with ACID
    
- [[Data Quality]] — tests for freshness, uniqueness, validity
    
- [[Orchestration & DAGs]] — scheduling and monitoring pipelines
    
- [[CDC (Change Data Capture)]] — capturing row changes from sources
    

---