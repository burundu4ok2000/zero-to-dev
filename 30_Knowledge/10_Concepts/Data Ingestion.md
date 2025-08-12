---
title: "Data Ingestion"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/elt/airbyte"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

---

![[Data Ingestion.png]]

---
## **One-liner**
A practical blueprint for moving data from source systems into a target platform using **connectors**, **batch** or **streaming** pipelines, with guardrails for **schema**, **quality**, and **reliability**.

## The Big Idea
- Data ingestion is the entry point of a **data platform**: getting bytes from many places into one place **safely**, **repeatably**, and **observably**.
- Two operating modes dominate: **batch ingestion** (periodic loads of files or tables) and **streaming ingestion** (continuous events).
- Robust ingestion designs prioritize **idempotency** (safe re-runs), **ordering** and **deduplication**, **schema evolution** handling, and **backpressure** control.
- For analytics, ingestion usually targets a **data lake** and/or **data warehouse**; downstream **ELT**/**ETL** handles transforms.

## Key Characteristics
- **Sources**: databases (**CDC** via binlogs), SaaS APIs, files (CSV/JSON/Parquet), message queues, webhooks.
- **Modes**: **batch** (cron/triggered) vs **streaming** (low **latency**, higher operational complexity).
- **Transport**: **HTTP** pulls, S3/GCS drops, **Kafka** topics, managed connectors (Airbyte, Fivetran).
- **Reliability**: **at-least-once** by default; aim for **exactly-once** semantics with checkpoints + dedupe keys.
- **Schema strategy**: **schema-on-write** (warehouse tables) vs **schema-on-read** (lake with late-binding).
- **Quality**: validation, **dead-letter queues** (DLQ), row-level **quarantine**, replay.
- **Security**: secrets management, **TLS**, IP allowlists, **PII** masking, row/object-level controls.
- **Operations**: **SLA/SLO**, retries with exponential backoff, idempotent writes, observability (**metrics**, **logs**, **traces**).

## Examples

### Batch pull → land → load
```bash
# 1) Pull daily report from SaaS API
curl -sS -H "Authorization: Bearer $TOKEN"   "https://api.vendor.com/v1/report?date=$(date -u +%F)"   -o /landing/reports/report-$(date -u +%F).json

# 2) Stage to object storage (immutable, versioned)
aws s3 cp /landing/reports/report-$(date -u +%F).json s3://company-raw/reports/

# 3) Load to warehouse table (append-only)
bq load --source_format=NEWLINE_DELIMITED_JSON analytics.raw_reports s3://company-raw/reports/report-*.json
```

### Streaming (Kafka) → warehouse with dedupe
```python
from uuid import UUID
from somewhere import kafka, warehouse, checkpoint

consumer = kafka.Consumer(topic="events")
last_offset = checkpoint.read("events")

for msg in consumer.read(from_offset=last_offset):
    event = msg.json()
    # idempotency: use a natural/business key or event id
    key = UUID(event["event_id"])
    warehouse.upsert(table="events_raw", key="event_id", row=event)
    checkpoint.write("events", msg.offset)
```

### CDC (Change Data Capture) with Airbyte
```yaml
# airbyte connection (conceptual)
source: mysql_orders_binlog
destination: s3_raw
sync_mode: incremental+dedup
primary_key: [order_id]
cursor_field: updated_at
```
This replicates inserts/updates/deletes by reading the source binlog, lands them in the lake, and preserves a change stream for replay.

## Related Concepts
- [[ETL]] – ingestion is often the first leg before transforms.
- [[ELT]] – load raw, then transform in-warehouse.
- [[Data Warehouse]] – common target for curated, query-optimized data.
- [[Data Lake]] – cheap, immutable landing zone for raw/staged data.
- [[Batch Processing]] – periodic jobs for large volumes.
- [[Stream Processing]] – continuous event pipelines and low-latency use cases.

## See Also
- [[ELT vs ETL]]
- [Airbyte: What is data ingestion?](https://airbyte.com/learn/what-is-data-ingestion)
- [Google Cloud: Batch vs streaming data processing](https://cloud.google.com/architecture/batch-vs-streaming-data) 
- [Snowflake: Data ingestion patterns](https://docs.snowflake.com/en/user-guide/data-load-overview)

## Terms
[[batch]], [[streaming]], [[connector]], [[schema-on-write]], [[schema-on-read]], [[CDC]], [[idempotency]], [[deduplication]], [[ordering]], [[backpressure]], [[latency]], [[throughput]], [[dead-letter queue]], [[SLA]], [[checkpointing]], [[upsert]], [[exactly-once delivery]], [[at-least-once delivery]], [[observability]], [[PII]]
