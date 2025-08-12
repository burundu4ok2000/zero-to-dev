---
title: "Stream Processing & Kafka Fundamentals"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/kafka"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Stream Processing & Kafka Fundamentals.png]]


## **One-liner**
Build **low-latency**, **fault-tolerant** data pipelines with **Kafka** by mastering **topics**, **partitions**, **consumer groups**, delivery semantics, and **stateful** operations like **windows** and **joins**.

## The Big Idea
- **Stream processing** treats data as an unbounded sequence of events. Systems like **Kafka** provide durable, ordered logs; engines (Kafka Streams, Flink, Spark Structured Streaming, ksqlDB) compute over those logs in near real time.
- Scaling comes from **partitioning**: producers write by **key**; consumers in a **group** divide partitions among themselves for parallelism. Ordering is guaranteed **within** a partition.
- Reliability hinges on **offset** management, **idempotent producers**, **transactions** (for EOS), and **retries** with **backoff**. Exactly-once is achievable in narrow, well-configured paths; most pipelines are **at-least-once** with dedupe.
- Streaming isn’t only “fast batch.” Time semantics (**event time** + **watermarks**) drive **windows**, **late data** handling, and **state stores** for joins/aggregations.

## Core Concepts
- **Topic** — named log of records.  
- **Partition** — shard of a topic; defines parallelism and per-partition ordering.  
- **Broker & Replication** — servers store partitions with a **replication factor** for HA.  
- **Producer** — writes records (optionally **idempotent** or **transactional**).  
- **Consumer / Consumer Group** — reads records; offsets tracked per partition per group; rebalances when membership changes.  
- **Serialization** — **Avro**/**Protobuf**/**JSON** with a **Schema Registry** for evolution.  
- **Retention & Compaction** — delete old data by time/size; **log compaction** keeps latest record per key.  
- **Delivery semantics** — **at-most-once**, **at-least-once**, **exactly-once** (EOS).  
- **Time semantics** — **event time** vs **processing time**; **watermarks** for lateness.  
- **Windows** — **tumbling**, **hopping**, **sliding**, **session**; drive aggregations.  
- **State** — local **state stores** (often RocksDB) with **changelog** topics for recovery.  
- **Stream–Table duality** — change-log of a table ↔ stream of events.

## Patterns
- **Outbox + CDC**: apps write to an outbox table; CDC ships to Kafka for reliable integration.  
- **Dead-Letter Queue (DLQ)**: route poison messages to a side topic with reason metadata.  
- **Exactly-once pipeline**: idempotent + transactional producer, read-process-write with EOS-enabled libraries, transactional offsets.  
- **Backpressure**: control producer rate, use bounded state, monitor consumer **lag**.  
- **Schema evolution**: use compatible changes (add optional fields), versioned subjects in **Schema Registry**.

## Examples

### Create a topic (3 partitions, RF=3)
```bash
kafka-topics --create --topic orders --partitions 3 --replication-factor 3 --bootstrap-server localhost:9092
```

### Python producer (idempotent)
```python
from confluent_kafka import Producer
p = Producer({"bootstrap.servers": "localhost:9092", "enable.idempotence": True})
p.produce("orders", key=str(order_id), value=payload_json)
p.flush()
```

### Python consumer group
```python
from confluent_kafka import Consumer
c = Consumer({"bootstrap.servers": "localhost:9092", "group.id": "orders-etl", "auto.offset.reset": "earliest"})
c.subscribe(["orders"])
while True:
    msg = c.poll(1.0)
    if not msg or msg.error(): continue
    process(msg.key(), msg.value())  # idempotent sink!
    c.commit(msg)  # commit after successful processing
```

### Windowed aggregation (ksqlDB-style)
```sql
CREATE TABLE orders_per_min AS
SELECT key, COUNT(*) AS c
FROM orders_stream
WINDOW TUMBLING (SIZE 1 MINUTE, GRACE PERIOD 30 SECONDS)
GROUP BY key;
```

## Ops & Observability
- Track **consumer lag**, end-to-end **latency**, **throughput**, and error rates per topic/partition.  
- Right-size partitions (too few → no parallelism; too many → overhead).  
- Secure with **TLS/SASL**, ACLs; mask or tokenize **PII**.  
- Tune **retention** and **compaction** per topic; vacuum small segments; plan storage.  
- Practice **failure drills**: leader loss, rebalance storms, schema incompatibility.

## Common Gotchas
- Assuming global ordering; only **per-partition** ordering is guaranteed.  
- Non-idempotent sinks with retries → duplicates. Add **dedup** keys or **MERGE** in the warehouse.  
- Unbounded state growth from wide windows or joins; set **grace periods** and TTLs.  
- Schema changes without registry compatibility rules → consumer breakage.  
- Using one giant partition “for ordering” → zero parallelism.

## Related Concepts
- [[Change Data Capture (CDC)]]  
- [[Data Ingestion]]  
- [[ELT]]  
- [[ETL]]  
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]  
- [[Data Quality & Testing (Great Expectations)]]  
- [[Data Lake vs Lakehouse]]  
- [[Data Warehouse]]  
- [[Medallion Architecture (Bronze/Silver/Gold)]]  
- [[Kappa Architecture]]

## See Also
- [Apache Kafka Documentation](https://kafka.apache.org/documentation/)
- [Kafka Streams Concepts](https://kafka.apache.org/documentation/streams/)
- [Confluent: Exactly-once Semantics](https://www.confluent.io/blog/enabling-exactly-once-kafka-streams/)
- [Flink: Event Time & Watermarks](https://nightlies.apache.org/flink/flink-docs-stable/docs/concepts/time/)
- [Spark Structured Streaming Guide](https://spark.apache.org/docs/latest/structured-streaming-programming-guide.html)

## Terms
[[topic]], [[partition]], [[broker]], [[replication factor]], [[producer]], [[consumer]], [[consumer group]], [[offset]], [[rebalance]], [[idempotent producer]], [[transactional producer]], [[at-most-once delivery]], [[at-least-once delivery]], [[exactly-once semantics]], [[backpressure]], [[throughput]], [[latency]], [[retention]], [[log compaction]], [[schema registry]], [[Avro]], [[Protobuf]], [[JSON]], [[event time]], [[processing time]], [[watermark]], [[window]], [[tumbling window]], [[hopping window]], [[sliding window]], [[session window]], [[state store]], [[RocksDB]], [[changelog]], [[stream-table duality]], [[windowed aggregation]], [[dead-letter queue]], [[consumer lag]], [[ksqlDB]], [[Kafka Streams]], [[Apache Flink]], [[Spark Structured Streaming]]
