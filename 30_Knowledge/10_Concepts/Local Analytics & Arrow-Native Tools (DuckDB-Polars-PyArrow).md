---
title: "Local Analytics & Arrow-Native Tools (DuckDB/Polars/PyArrow)"
lang_tags: "#lang/sql #lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/duckdb #tool/polars #tool/pyarrow"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Local Analytics & Arrow-Native Tools (DuckDB-Polars-PyArrow).png]]


## **One-liner**
Fast local analytics with **DuckDB**, **Polars**, and **PyArrow**: query **Parquet**/**CSV** directly, move data zero-copy with **Arrow**, and prototype pipelines without a cluster.

## The Big Idea
- **DuckDB** is an in-process OLAP DB; it reads Parquet/CSV (even S3) and runs vectorized SQL blazing fast.  
- **Polars** is a Rust-powered **DataFrame** library with lazy execution and strong Parquet/Arrow support; great for medium data.  
- **PyArrow** is the columnar memory layer enabling **zero-copy** interchange between tools (Pandas/Polars/DuckDB/Spark).

## Core Patterns
- Query Parquet directly with **DuckDB**; write results back to Parquet/CSV for portability.  
- Use **Polars lazy** to build pipelines with `scan_parquet()`, then `collect()` only when needed.  
- Interop via **Arrow**: convert without copies between DuckDB ↔ Polars ↔ Pandas.  
- Prototype **dbt**-like transforms locally, then port SQL to the warehouse.

## Examples
```sql
-- DuckDB: ad-hoc SQL over Parquet
SELECT country, avg(amount) AS avg_amount
FROM read_parquet('s3://lake/silver/orders/*.parquet')
GROUP BY country
ORDER BY avg_amount DESC
LIMIT 10;
```

```python
# Polars: lazy pipeline
import polars as pl
df = (pl.scan_parquet("s3://lake/silver/orders/*.parquet")
        .filter(pl.col("status").is_in(["paid","shipped"]))
        .with_columns(pl.col("amount").cast(pl.Float64))
        .groupby_dynamic(index_column="order_ts", every="1d", closed="left")
        .agg(pl.col("amount").sum().alias("revenue"))
     ).collect()

# Arrow interop
import duckdb, pyarrow as pa
rel = duckdb.query("SELECT * FROM df")  # df -> Arrow table via DuckDB integration
tbl: pa.Table = rel.arrow()
```

## When to Use
- Local dev, **unit tests**, and **smoke tests** for ELT logic before hitting the warehouse.  
- Lightweight data exploration and debugging of pipeline outputs.  
- CI jobs that validate **schemas** and **row deltas** on small samples.

## Common Gotchas
- Overusing local tools for truly big data; know when to move to Spark/warehouse.  
- Inconsistent timezone/decimal handling across libraries; pin versions and test.  
- Reading from S3 without proper credentials/session settings.

## Related Concepts
- [[SQL Patterns & Window Functions for Data Engineers]]
- [[Data Formats & Compression for Analytics (CSV/JSON/Parquet/ORC)]]
- [[dbt Core Concepts]]
- [[Spark Basics for Data Engineering]]
- [[ELT]]
- [[CI-CD for Data (GitHub Actions, dbt build, Airflow deploy)]]

## See Also
- DuckDB: https://duckdb.org/
- Polars: https://pola.rs/
- Apache Arrow: https://arrow.apache.org/

## Terms
[[DuckDB]], [[Polars]], [[PyArrow]], [[Arrow memory format]], [[zero-copy]], [[vectorized execution]], [[scan_parquet]], [[lazy execution]], [[collect]], [[Parquet]], [[CSV]], [[S3]], [[prototype]], [[unit test]]
