
---

## **The Big Idea**

  

A **Data Warehouse (DWH)** is a central system that stores **clean, structured, and analytics-ready data** from multiple sources.

It’s optimized for **reading, aggregating, and analyzing** — not for frequent updates like a regular database.

---

## **What Makes It Special?**

|**Feature**|**Description**|
|---|---|
|Read-optimized|Fast for SELECT, slow for frequent UPDATE/DELETE|
|Historical|Stores **years** of data, often **append-only**|
|Structured|Follows a **schema** (tables, types, relationships)|
|Analytical|Built for **OLAP**, not OLTP|

See also: [[OLAP vs OLTP]]

---

## **Common Use Cases**

- Business dashboards and KPIs
    
- Financial or sales reports
    
- Machine learning model training
    
- Long-term data storage for compliance
    
- Joining data from multiple systems
    

---

## **Typical Workflow**

```
 [Source Systems] → [ETL/ELT] → [Staging] → [DWH] → [BI/ML/Apps]
      CRMs, APIs     Airflow, dbt        tables       Looker, Tableau, Python
```

The DWH is the **hub** for clean data.

---

## **Warehouse vs Database**

|**Feature**|**Data Warehouse**|**Transactional Database**|
|---|---|---|
|Optimized for|Aggregation, reporting (OLAP)|Fast inserts, updates (OLTP)|
|Schema design|Star/snowflake (dim/fact)|Normalized (3NF)|
|Writes|Batched (daily/hourly loads)|Constant (per user action)|
|Example tools|Snowflake, BigQuery, Redshift|MySQL, PostgreSQL, MongoDB|
|Data size|TB–PB range|MB–GB range|

---

## **Examples of Warehouses**

|**Product**|**Type**|**Notes**|
|---|---|---|
|**Snowflake**|Cloud-native|Scales compute/storage separately, SQL-based|
|**BigQuery**|Serverless|Google Cloud’s DWH, very fast on big scans|
|**Redshift**|Cluster-based|AWS-native, older than Snowflake/BigQuery|
|**Databricks**|Lakehouse|Combines DWH + Data Lake (via Delta Lake)|
|**ClickHouse**|Open-source|Super-fast analytics DB (used in Yandex)|

---

## **Data Modeling Inside a DWH**

  

Typical structure uses **dimensional modeling**:

- **Fact tables** — numbers you want to measure (sales, clicks)
    
- **Dimension tables** — context for the numbers (date, customer, product)
    

  

Example:

```
Fact: sales → amount, date_id, product_id, store_id  
Dims: date, product, store
```

This is the **star schema** — see: [[Dimensional Modeling (Kimball)]]

---

## **Partitioning and Clustering**

  

To improve performance and cost, DWHs use:

- **Partitioning** — split data by date, region, etc.
    
- **Clustering** — organize data inside partitions for fast filtering
    

  

> Good partitioning = cheaper queries

---

## **Storage Format**

  

Many DWHs store data in **columnar** formats (e.g., Parquet) for:

- Faster aggregation (only read the needed columns)
    
- Better compression (columns are more similar)
    
- Predicate pushdown (skip irrelevant data blocks)
    

  

See: [[File Formats: CSV, JSON, Parquet, Avro]]

---

## **Warehouse Layers (Bronze → Silver → Gold)**

  

A typical DWH follows a **layered architecture**:

|**Layer**|**Purpose**|
|---|---|
|Bronze|Raw ingested data|
|Silver|Cleaned and typed tables|
|Gold|Final, business-ready models|

This makes the pipeline **modular, testable, and traceable**.

  

See: [[Data Lakehouse: Bronze–Silver–Gold]]

---

## **Cost Considerations**

  

Warehouses charge for:

- **Storage** (GBs per month)
    
- **Compute** (query time or slots)
    
- **Data scans** (especially in BigQuery)
    

  

💡 Tips:

- Use SELECT column1, column2 — **not SELECT ***
    
- Partition large tables by date or ID
    
- Materialize heavy queries if reused often
    

---

## **Observability and Governance**

  

Important for trust and compliance:

- **Data lineage** — where data came from
    
- **Access control** — role-based permissions
    
- **Auditing** — who queried what, when
    
- **Documentation** — table and column descriptions
    

  

Tools: dbt docs, Amundsen, DataHub, Monte Carlo, OpenLineage

---

## **Common Pitfalls**

- ❌ Loading dirty data — always clean first
    
- ❌ No schema enforcement — adds risk
    
- ❌ No incremental strategy — slow and expensive loads
    
- ❌ No freshness monitoring — reports break silently
    
- ❌ Poor naming — causes confusion across teams
    

---

## **Quick Checklist**

- Tables are partitioned and clustered
    
- Gold layer is tested and documented
    
- Raw data preserved (audit/compliance)
    
- Queries are optimized (no SELECT *)
    
- Access and roles reviewed regularly
    
- Lineage and ownership are known
    

---

**Related notes:**

[[ETL]] · [[ELT vs ETL]] · [[Dimensional Modeling (Kimball)]] · [[Batch vs Streaming]] · [[Data Lakehouse: Bronze–Silver–Gold]] · [[Data Pipeline]]

---
