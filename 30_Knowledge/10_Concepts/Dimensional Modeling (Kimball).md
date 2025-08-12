---
title: "Dimensional Modeling (Kimball)"
lang_tags: "#lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/dbt"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Dimensional Modeling (Kimball).png]]

## **One-liner**
A practical way to model analytics with **fact tables**, **dimension tables**, a clear **grain**, and stable **conformed dimensions** so BI is fast, consistent, and explainable.

## The Big Idea
- Optimize for **OLAP**: star-shaped models that make **joins**, **aggregations**, and **time-series** cheap and predictable.
- Pick a single, atomic **grain** for each fact; everything else derives from that choice.
- Keep measures **additive** or document **semi-/non-additive** behavior across dimensions (e.g., ratios, distinct counts).
- Stabilize meaning with **conformed dimensions** shared across marts (e.g., a single Customer).
- Track history via **Slowly Changing Dimensions** (**SCD**), usually Type 2 with effective/expiry timestamps.
- Prefer **surrogate keys** in warehouse, separate from business keys; handle **late-arriving** facts/dimensions.

## Modeling Workflow
1. Define business questions → identify **facts** and **dimensions**.
2. Choose **grain** for the fact (e.g., order line, page view, payment).
3. Map **measures** and dimensional **attributes**; decide additivity and null-handling.
4. Design **SCD strategy** (Type 1 vs Type 2) for each dimension.
5. Implement in SQL/**dbt** with tests for **uniqueness**, **not null**, and **referential integrity**.
6. Expose **semantic names** and **documentation** for analysts (dbt docs or catalog).

## Star vs Snowflake
- **Star schema**: wide dimensions denormalized for simplicity and query speed; fewer joins.
- **Snowflake schema**: normalize big dimensions into sub-dimensions to reduce duplication; more joins but smaller storage.
- Use star by default; snowflake only for truly huge, sparse, or fast-changing dimensions.

## Example (conceptual SQL)
```sql
-- Dimension: Product (SCD Type 2)
CREATE TABLE dim_product (
  product_sk      BIGINT PRIMARY KEY,
  product_id      TEXT,              -- business key
  category        TEXT,
  brand           TEXT,
  is_active       BOOLEAN,
  effective_from  TIMESTAMP,
  effective_to    TIMESTAMP,
  is_current      BOOLEAN
);

-- Fact: Sales at order-line grain
CREATE TABLE fct_sales (
  sales_sk     BIGINT PRIMARY KEY,
  order_id     TEXT,
  order_ts     TIMESTAMP,
  product_sk   BIGINT REFERENCES dim_product(product_sk),
  customer_sk  BIGINT,
  qty          INT,
  revenue      NUMERIC(18,2)
);

-- Typical rollup
SELECT date_trunc('month', order_ts) AS month,
       SUM(revenue) AS revenue
FROM fct_sales
GROUP BY 1
ORDER BY 1;
```

## Anti‑patterns
- Mixing multiple **grains** in one fact; causes double counting.
- Missing **SCD** rules; silently rewrites history.
- Over-normalizing hot dimensions; death by joins. Over-denormalizing facts; bloat and slow loads.
- Using business keys directly everywhere; brittle when upstream systems change.

## Related Concepts
- [[Data Warehouse]] – the home and engine for dimensional models.
- [[Data Mart]] – business-scoped slice built from conformed dimensions.
- [[Medallion Architecture (Bronze/Silver/Gold)]] – fits nicely with curated gold models.
- [[ELT]] – build models with SQL and dbt inside the warehouse.
- [[Orchestration & Scheduling (Airflow/Cron/Dagster)]] – run model builds and tests on schedule.
- [[dbt Core Concepts]] – models, materializations, tests, and docs layer.
- [[Data Ingestion]] – feeds raw and staged data before modeling.

## See Also
- [Kimball Group: Dimensional Modeling Basics](https://www.kimballgroup.com/2013/07/design-tip-152-a-dimensional-modeling-glossary/)
- [Wikipedia: Dimensional modeling](https://en.wikipedia.org/wiki/Dimensional_modeling)
- [Microsoft: Star schema design guidance](https://learn.microsoft.com/power-bi/guidance/star-schema)

## Terms
[[fact table]], [[dimension table]], [[grain]], [[measure]], [[additivity]], [[semi-additive measure]], [[non-additive measure]], [[conformed dimension]], [[surrogate key]], [[business key]], [[slowly changing dimension]], [[SCD Type 1]], [[SCD Type 2]], [[degenerate dimension]], [[junk dimension]], [[role-playing dimension]], [[bridge table]], [[factless fact table]], [[late-arriving data]]
