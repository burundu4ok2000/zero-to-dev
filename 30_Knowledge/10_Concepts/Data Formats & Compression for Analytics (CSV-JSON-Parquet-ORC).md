---
title: "Data Formats & Compression for Analytics (CSV/JSON/Parquet/ORC)"
lang_tags: "#lang/sql #lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/lakehouse"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Data Formats & Compression for Analytics (CSV-JSON-Parquet-ORC).png]]


## **One-liner**
Choose the right **file format** (**CSV**, **JSON/NDJSON**, **Parquet**, **ORC**) and **compression** (**gzip**, **snappy**, **zstd**, **lz4**) to minimize cost, maximize **scan speed**, and unlock **predicate pushdown**/**partition pruning**.

## The Big Idea
- **Row-based** formats (CSV/JSON) are flexible but inefficient for analytics; **columnar** formats (**Parquet/ORC**) are built for **OLAP** with column-wise compression and metadata that enables pushdown.
- Compression is a trade-off between **ratio** and **CPU**. For warehouses/lakes, **snappy** or **zstd** on columnar formats usually wins on total cost (storage + compute).
- File **size** and **layout** matter: too many tiny files kill performance; aim for large, moderately sized files and tuned **row groups**/**stripes**.

## Formats Overview
- **CSV**
  - Pros: universal, human-readable, easy export.
  - Cons: no types, no schema, no nested data, no metadata; expensive to parse; ambiguous nulls/quotes.
  - Use: small exchanges, edge integrations; convert to columnar ASAP.
- **JSON / NDJSON**
  - Pros: nested/semistructured, human-friendly, streamable as **NDJSON** (one object per line).
  - Cons: bulky, slow to parse; no column stats for pushdown.
  - Use: ingest APIs/events; land as raw, then normalize to columnar.
- **Parquet**
  - Pros: columnar, **statistics** and **min/max** per **row group**, **dictionary**/**RLE** encodings, optional **Bloom filters**.
  - Cons: not human-readable; must choose proper **row group** size.
  - Use: default for analytics on lakes/warehouses.
- **ORC**
  - Pros: similar to Parquet; strong **predicate pushdown**, **stripes**, **indexes**; great with Hive/Presto/Trino.
  - Cons: ecosystem skew (some tools prefer Parquet).
  - Use: Hive/Presto-heavy stacks; large fact tables.

## Compression Codecs (typical)
- **gzip**: high ratio, slower (CPU-heavy), single-threaded stream → poor parallel splits.
- **snappy**: fast, lower ratio; great default for Parquet/ORC.
- **zstd**: tunable levels (speed↔ratio), often best balance for analytics.
- **lz4**: very fast, modest ratio; good for hot data/streaming.
- Columnar files add **column encodings** (dictionary/RLE) on top of codec → big wins even with “lighter” codecs.

## Pushdown & Partitioning
- **Predicate pushdown**: engines skip row groups/stripes that fail min/max stats (e.g., `event_day BETWEEN '2025-08-01' AND '2025-08-07'`).
- **Partition pruning**: physical layout like `.../event_day=2025-08-01/` lets engines skip entire folders.
- **Clustering/Z-order** (vendor-specific): organizes data for multi-column pruning.

## File Sizing Guidelines
- Target **128–1024 MB** per Parquet file in lakes; balance with cluster parallelism.
- Set Parquet **row group** around **128–256 MB**; avoid millions of tiny row groups.
- Periodically **compact** small files after incremental writes/CDC.
- Avoid gzipping massive single JSON files; compressors limit splitting → poor parallelism.

## Examples

### Pandas / PyArrow → Parquet
```python
import pandas as pd
df = pd.read_csv("reports.csv")
# Normalize types, then write columnar with compression
df.to_parquet("s3://company-lake/bronze/reports/",
              engine="pyarrow",
              compression="zstd",
              index=False)
```

### Spark DataFrame → partitioned Parquet
```python
from pyspark.sql import functions as F

clean = (df
  .withColumn("event_day", F.to_date("event_ts"))
  .select("event_day","user_id","amount","status"))

(clean
  .repartition(64, "event_day")    # parallel by partition key
  .write
  .option("compression","zstd")
  .partitionBy("event_day")
  .parquet("s3://lake/silver/events/"))
```

### BigQuery load from Parquet
```bash
bq load --source_format=PARQUET analytics.events s3://lake/silver/events/*.parquet
```

## Gotchas
- CSV/JSON **type drift** (strings that look like numbers); define **data contracts** and cast on ingest.
- JSON and **gzip**: giant gzipped files can’t be split → slow scans. Prefer many NDJSON chunks or columnar.
- Mismatched **timezones** and **decimal** precision; use logical types in Parquet and explicit casts.
- Over-partitioning (one folder per user/hour) → metadata overhead; choose balanced keys.
- Forgetting **statistics** (disabled in some writers) → weak pushdown.
- ORC/Parquet defaults vary across engines; verify **row group/stripe** size and **codec**.

## Related Concepts
- [[Data Lake vs Lakehouse]]
- [[Lakehouse Table Formats (Delta vs Iceberg vs Hudi)]]
- [[ELT]]
- [[Data Ingestion]]
- [[Spark Basics for Data Engineering]]
- [[SQL Patterns & Window Functions for Data Engineers]]
- [[Data Contracts & Schema Management (Avro/Protobuf/JSON Schema)]]

## See Also
- Apache Parquet: Overview — https://parquet.apache.org/docs/
- ORC: Official site — https://orc.apache.org/
- BigQuery: Parquet considerations — https://cloud.google.com/bigquery/docs/loading-data-cloud-storage-parquet

## Terms
[[row-based format]], [[columnar format]], [[predicate pushdown]], [[partition pruning]], [[row group]], [[stripe]], [[dictionary encoding]], [[run-length encoding]], [[Bloom filter]], [[NDJSON]], [[logical type]], [[decimal precision]], [[timezone]], [[compression codec]], [[gzip]], [[snappy]], [[zstd]], [[lz4]], [[compaction]], [[file sizing]], [[cluster parallelism]]
