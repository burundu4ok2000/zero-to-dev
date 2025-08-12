---
title: "Change Data Capture (CDC)"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/cdc/debezium #tool/kafka #tool/elt/airbyte"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Change Data Capture (CDC).png]]

## **One-liner**
**Change Data Capture (CDC)** streams inserts/updates/deletes from source databases by reading their **write-ahead logs** (binlog/WAL) so downstream systems stay in near-real-time sync without heavy full-table scans.

## The Big Idea
- Instead of polling entire tables, CDC tails the database’s **transaction log** to emit ordered **events** that represent row-level changes.
- Events flow to a **landing** zone (lake/queue) or directly into **Silver**/**Gold** models via **upsert/merge**. This enables **incremental** processing and minimizes load on OLTP systems.
- Production-ready CDC requires **ordering**, **idempotency**, **schema evolution** handling, and backpressure-aware consumers with durable **checkpoints**.

## Where CDC Fits
- **Sources**: MySQL (**binlog**), Postgres (**WAL** + logical decoding), SQL Server (CDC/CT), Oracle (redo), MongoDB (oplog).  
- **Pipes**: **Kafka**/**Pulsar**/**Kinesis**, object storage (S3/GCS) as append-only files, or direct-to-warehouse.  
- **Sinks**: **Data lake** (bronze), **warehouse** (staging → merge), cache/indexes (Elasticsearch), or downstream microservices.

## Delivery Semantics & Keys
- Aim for **at-least-once** delivery with **deduplication** on a stable **primary/business key**.  
- **Exactly-once** is achievable in limited contexts via **idempotent producers**, consistent checkpoints, and **merge-on-read** sinks.  
- Preserve **ordering** per key (partitioning by PK) to avoid anomalies on replays.

## Implementation Patterns
- **Snapshot then stream**: take an initial **snapshot** of tables, then switch to log tailing for new changes.  
- **Outbox pattern**: source app writes to an **outbox** table in the same transaction; a CDC connector ships it to the bus.  
- **Schema evolution**: manage **Debezium**/connector schema registry; evolve downstream tables with **nullable** additions and versioned contracts.  
- **Soft deletes**: represent as tombstones; downstream performs **DELETE** or flags `is_deleted`.  
- **Idempotent sinks**: upsert using `MERGE` keyed by the business/primary key and latest **op_ts**/**lsn**.

## Examples

### Debezium (Kafka Connect) – conceptual connector config
```json
{
  "name": "mysql-orders-connector",
  "config": {
    "connector.class": "io.debezium.connector.mysql.MySqlConnector",
    "database.hostname": "mysql",
    "database.port": "3306",
    "database.user": "cdc",
    "database.password": "${secrets:MYSQL_PWD}",
    "database.history.kafka.bootstrap.servers": "kafka:9092",
    "database.server.name": "store",
    "table.include.list": "store.orders,store.order_items",
    "include.schema.changes": "false",
    "snapshot.mode": "initial",
    "tombstones.on.delete": "true",
    "transforms": "unwrap",
    "transforms.unwrap.type": "io.debezium.transforms.ExtractNewRecordState",
    "transforms.unwrap.drop.tombstones": "false",
    "key.converter": "org.apache.kafka.connect.storage.StringConverter",
    "value.converter": "org.apache.kafka.connect.json.JsonConverter"
  }
}
```

### Warehouse merge from CDC stream (SQL-ish)
```sql
MERGE INTO silver.orders t
USING staging.orders_cdc s
ON t.order_id = s.order_id
WHEN MATCHED AND s.op = 'D' THEN DELETE
WHEN MATCHED AND s.op IN ('U','R') AND s.op_ts > t.op_ts THEN
  UPDATE SET *
WHEN NOT MATCHED AND s.op IN ('C','R') THEN
  INSERT *;
```

### Airbyte (conceptual YAML)
```yaml
source: postgres_orders_wal
destination: s3_raw
sync_mode: incremental+dedup
cursor_field: updated_at
primary_key: [order_id]
```

### Kafka consumer sketch (Python)
```python
for record in consumer:
    event = record.value  # dict
    key = event["order_id"]
    # idempotent upsert keyed by business PK + event time
    warehouse.merge("silver.orders", key="order_id", row=event, ts_col="op_ts")
    checkpoint.save(record.topic, record.partition, record.offset)
```

## Operational Considerations
- Control **latency** with right-sized batches and partitions; monitor **lag** per topic and consumer.  
- Ensure secure access: **TLS**, SASL, network rules; protect **PII** in transit and at rest.  
- Implement **replay** workflow from **bronze** for backfills; keep **time travel** and lineage.  
- Alert on **schema drift**, **row-count deltas**, and excessive **tombstones**; quarantine corrupt records (**DLQ**).

## Related Concepts
- [[Data Ingestion]] – CDC is a core ingestion pattern into raw bronze.  
- [[ELT]] – consume CDC streams and **merge** into silver/gold models.  
- [[ETL]] – sometimes used to pre-aggregate CDC streams externally.  
- [[Data Lake vs Lakehouse]] – where CDC events land and are versioned.  
- [[Medallion Architecture (Bronze/Silver/Gold)]] – CDC populates Bronze and drives Silver.  
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]] – schedule snapshots, merges, and backfills.  
- [[Data Quality & Testing (Great Expectations)]] – validate CDC payloads and freshness.  
- [[Data Warehouse]] – the serving layer that consumes merges.

## See Also
- [Debezium Documentation](https://debezium.io/documentation/)
- [Kafka Connect: Concepts](https://kafka.apache.org/documentation/#connect)
- [Outbox Pattern](https://microservices.io/patterns/data/transactional-outbox.html)

## Terms
[[transaction log]], [[write-ahead log]], [[binlog]], [[WAL]], [[oplog]], [[snapshot]], [[incremental]], [[cursor]], [[checkpoint]], [[lag]], [[partition]], [[ordering]], [[at-least-once delivery]], [[exactly-once delivery]], [[tombstone]], [[schema evolution]], [[upsert]], [[merge]], [[primary key]], [[business key]], [[deduplication]], [[replay]], [[time travel]], [[outbox pattern]], [[connector]], [[Kafka Connect]]
