
  

> **One-liner:** A **Data Warehouse (DWH)** is a centralized, **read-optimized** store of **clean, structured, historical** data for analytics and reporting. [[Concepts]]

---

## **The Big Idea**

  

A DWH aggregates data from many sources, standardizes it, and serves **fast SQL queries** for dashboards, KPIs, and analysis. It’s built for **OLAP** (reads and aggregates), not for high-frequency updates.

---

## **Key Properties (at a glance)**

|**Property**|**Meaning (plain English)**|
|---|---|
|Read-optimized|Fast SELECT and aggregations; slow frequent writes|
|Historical|Keeps years of data, usually append-heavy|
|Structured|Enforced schemas (tables, types, constraints)|
|Analytical|Designed for OLAP, not OLTP|

See also: [[OLAP vs OLTP]].

---

## **Where It Fits**

```
[ Sources ] → ETL/ELT → [ Data Warehouse ] → BI / Analytics / ML
```

The DWH is the **single, trusted place** analysts query.

---

## **When You Use It**

- Company-wide dashboards and KPIs
    
- Joining data from multiple systems consistently
    
- Long-term trends (months/years) and governance/compliance
    

---

## **Not the Same as an OLTP Database**

|**DWH (OLAP)**|**OLTP DB (apps)**|
|---|---|
|Aggregations & reporting|Rapid inserts/updates|
|Star/snowflake schemas|Normalized (3NF) schemas|
|Batch loads|Per-request writes|

See also: [[Dimensional Modeling (Kimball)]].

---

## **Examples (just to anchor the idea)**

  

**Snowflake**, **BigQuery**, **Redshift**, **ClickHouse** (analytics DB), **Databricks Lakehouse** (hybrid).

---

## **See also (details live elsewhere)**

- [[ETL]] / [[ELT vs ETL]] — how data gets in
    
- [[Data Lakehouse]] — files + tables with ACID
    
- [[Bronze–Silver–Gold]] — layering approach inside platforms
    
- [[Data Pipeline]] — end-to-end flow
    

---