---
title: "Data Warehouse"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/warehouse/snowflake"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

---

![[Data Warehouse.png]]

---
## **One-liner**
A **data warehouse** is a centralized, query-optimized store for analytical workloads, built for **OLAP** not OLTP.

## The Big Idea
- Designed for **analytics**: aggregations, joins across history, large scans. Prioritizes **read performance** and **concurrency** over write latency.
- Uses **columnar storage** and **vectorized execution** to crunch wide tables fast with compression and **predicate pruning**.
- Separates **storage** and **compute** in modern cloud DWHs (e.g., Snowflake, BigQuery) enabling elastic **scaling** and workload isolation.
- Data arrives from **ingestion** pipelines; transforms happen via **ELT** (dbt, SQL) or **ETL** upstream.
- Models are shaped into **facts** and **dimensions** to make analytics simple and consistent.

## Architecture Patterns
- **Dimensional Modeling** (Kimball): **star schema** (facts in center, dimensions around) for simplicity and speed. **Snowflake schema** normalizes dimensions further.
- **Corporate Information Factory** (Inmon): enterprise-wide **3NF** warehouse with downstream **data marts**.
- **Data Vault**: hubs, links, satellites—great for **auditability**, **lineage**, and incremental loads.
- **Medallion** in lakehouse: **bronze → silver → gold** layers where **gold** serves warehouse-like curated models.

## Core Objects
- **Fact table**: numeric, additive **measures** at a **grain** (e.g., order_line). Keys: **surrogate key** plus **foreign keys** to dimensions.
- **Dimension table**: descriptive attributes with **hierarchies** (date, product, customer). Handles **SCD** (slowly changing dimensions) types 1/2.
- **Materialized views**: precomputed results for latency-sensitive dashboards.
- **Partitions / Clustering**: physical organization hints for cost and speed.

## Performance & Cost
- Prefer **columnar** formats, **compressed** storage, and **statistics** for the **cost-based optimizer**.
- Prune with **partitions**, **cluster/sort keys**, **z-ordering** (vendor-specific), and **min/max** metadata.
- Use **workload isolation**: dedicated warehouses/slots/pools for ETL vs BI to avoid noisy neighbors.
- Cache smartly: **result cache**, **data cache**, **compiled queries** where supported.

## Governance & Reliability
- Strict **RBAC** (roles, grants), **row/object** access policies, and **PII** masking.
- **Time travel** and **fail-safe** (where supported) for rollbacks and recovery.
- **Quality gates**: tests on schemas and metrics; **lineage** in the catalog; **observability** on queries and freshness **SLA/SLO**.

## Example: Minimal Star Schema (SQL)
```sql
-- Dimensions
CREATE TABLE dim_date (
  date_key DATE PRIMARY KEY,
  year INT,
  quarter INT,
  month INT,
  day INT,
  weekday INT
);

CREATE TABLE dim_product (
  product_sk BIGINT PRIMARY KEY,
  product_id TEXT,
  category TEXT,
  brand TEXT,
  is_active BOOLEAN
);

-- Fact with surrogate key and FKs
CREATE TABLE fct_sales (
  sales_sk BIGINT PRIMARY KEY,
  date_key DATE REFERENCES dim_date(date_key),
  product_sk BIGINT REFERENCES dim_product(product_sk),
  quantity INT,
  revenue NUMERIC(18,2)
);

-- Typical BI query
SELECT d.year, p.category, SUM(f.revenue) AS revenue
FROM fct_sales f
JOIN dim_date d     ON f.date_key = d.date_key
JOIN dim_product p  ON f.product_sk = p.product_sk
GROUP BY d.year, p.category
ORDER BY d.year, p.category;
```

## Common Gotchas
- Modeling without a clear **grain** leads to duplicates and bad aggregates.
- Ignoring **SCD** behavior yields misleading history.
- Over-normalizing hot dimensions hurts joins; over-denormalizing facts bloats storage.
- Treating the DWH as a **data lake** (dump-first, think-later) reduces trust and speed.

## Related Concepts
- [[ETL]] – curate data before loading into the warehouse.
- [[ELT]] – load raw, then transform with SQL/dbt inside the warehouse.
- [[Data Lake]] – cheap storage layer; often the warehouse’s upstream.
- [[Data Ingestion]] – pipelines and connectors feeding the warehouse.
- [[Dimensional Modeling]] – Kimball-style design for facts and dimensions.
- [[Star Schema]] – the canonical shape for analytic models.
- [[Medallion Architecture]] – bronze/silver/gold flow in lakehouses.
- [[Data Mart]] – business-domain subset of the warehouse.

## See Also
- [[ELT vs ETL]]
- [Kimball Group: Dimensional Modeling Basics](https://www.kimballgroup.com/2013/07/design-tip-152-a-dimensional-modeling-glossary/)
- [Snowflake: What is a data warehouse?](https://www.snowflake.com/guides/what-is-a-data-warehouse/)
- [Google BigQuery: Introduction](https://cloud.google.com/bigquery/docs/introduction)

## Terms
[[OLAP]], [[columnar storage]], [[vectorized execution]], [[predicate pruning]], [[separation of storage and compute]], [[elastic scaling]], [[concurrency]], [[fact table]], [[dimension table]], [[measure]], [[grain]], [[surrogate key]], [[foreign key]], [[slowly changing dimension]], [[SCD Type 2]], [[materialized view]], [[partitioning]], [[clustering]], [[cost-based optimizer]], [[result cache]], [[RBAC]], [[masking]], [[time travel]], [[lineage]], [[observability]], [[SLA]]
