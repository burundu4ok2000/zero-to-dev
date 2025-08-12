---
title: "Data Contracts & Schema Management (Avro/Protobuf/JSON Schema)"
lang_tags: "#lang/python #lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/schema_registry"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Data Contracts & Schema Management (Avro-Protobuf-JSON Schema).png]]


## **One-liner**
A **data contract** specifies the structure, types, and guarantees of your data; **schema management** (Avro/Protobuf/JSON Schema + Schema Registry) enforces evolution rules so producers and consumers don’t break.

## The Big Idea
- Contracts make pipelines predictable: producers **guarantee** schema + semantics, consumers rely on **compatibility** and **lineage**.
- Use a **Schema Registry** to store versions, enforce **compatibility modes** (backward/forward/full), and hand out **schema IDs** for serialization.
- Pick a serialization format that matches your needs: **Avro** (dynamic, rich types, popular with Kafka), **Protobuf** (compact, strong IDL, fast codegen), **JSON Schema** (human-friendly, lightweight).

## Core Concepts
- **Schema** — type definition for a payload/table (fields, types, nullability, defaults).  
- **Compatibility** — whether a new schema version works with existing producers/consumers:  
  - **Backward**: new consumers can read old data.  
  - **Forward**: old consumers can read new data.  
  - **Full**: both backward and forward.  
- **Evolution** — allowed changes (add optional field with default, widen numeric type) vs breaking ones (remove required field, change type).  
- **Schema Registry** — service that stores schemas/versions and enforces compatibility; common in Kafka ecosystems.  
- **Subject naming** — mapping between a data stream and a schema name (e.g., `topic-value`).  
- **Serde** — serializer/deserializer library that reads/writes payloads using schema IDs.  
- **Logical types** — timestamps, decimals, UUIDs with precise representation.  
- **Defaults & nullability** — critical for forward/backward compatibility.

## Format Snapshots

### Avro (record)
```json
{
  "type": "record",
  "name": "Order",
  "namespace": "com.acme",
  "fields": [
    {"name": "order_id", "type": "long"},
    {"name": "status", "type": {"type": "enum", "name": "Status", "symbols": ["paid","shipped","refunded"]}},
    {"name": "amount", "type": ["null","double"], "default": null},
    {"name": "order_ts", "type": {"type":"long","logicalType":"timestamp-millis"}}
  ]
}
```

### Protobuf (`.proto`)
```proto
syntax = "proto3";
package com.acme;

message Order {
  int64 order_id = 1;
  string status   = 2;   // better as enum
  double amount   = 3;   // optional in proto3 via wrappers if needed
  int64 order_ts  = 4;   // use google.protobuf.Timestamp if preferred
}
```

### JSON Schema
```json
{
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "title": "Order",
  "type": "object",
  "properties": {
    "order_id": {"type": "integer"},
    "status":   {"enum": ["paid","shipped","refunded"]},
    "amount":   {"type": ["number","null"]},
    "order_ts": {"type": "string", "format": "date-time"}
  },
  "required": ["order_id","status","order_ts"],
  "additionalProperties": false
}
```

## Evolution Rules (Typical)
- **Safe**: add a new optional field with a **default**; add enum symbol (sometimes **backward** only); widen numeric (int → long).  
- **Risky**: rename a field without aliasing; change type (string → int); remove required field; change field meaning.  
- **Versioning**: bump **minor** for additive changes; **major** for breaking ones. Keep **migrations** and **changelogs**.

## Registry Integration (Kafka example)
- Subjects: `orders-value`, `orders-key`; set **BACKWARD** or **FULL** compatibility.  
- Payload wire format often = **magic byte** + **schema ID** + serialized message.  
- Use **Schema Registry** clients in producers/consumers; configure auth (**TLS/SASL**).  
- Validate in CI: reject PRs that introduce incompatible schemas.

## Contracts for Tables (Warehouse/Lakehouse)
- Treat table schemas as contracts: columns, types, **PK/unique** rules, nullability, **SLA** for freshness, owner.  
- Enforce with **dbt tests**, **Great Expectations**, and table **constraints** (where supported).  
- Manage **schema evolution** via migration scripts and **MERGE** logic; prefer additive changes; deprecate fields over time.

## Example: Breaking vs Safe Change (Avro)
```json
// v1
{"name":"amount","type":"double"}

// v2 (safe if default present)
{"name":"currency","type":["null","string"],"default":"USD"}

// v2 (breaking — type change)
{"name":"amount","type":"string"}
```

## Anti-patterns
- “Stringly-typed” payloads without constraints → downstream chaos.  
- Adding a non-nullable field **without default** in a live stream.  
- Sharing one giant schema across many event types → tight coupling.  
- No **logical types** for timestamps/decimals → rounding/timezone bugs.  
- Skipping **schema review** and CI compatibility checks.

## Related Concepts
- [[Stream Processing & Kafka Fundamentals]]
- [[Change Data Capture (CDC)]]
- [[Data Quality & Testing (Great Expectations)]]
- [[ELT]]
- [[dbt Core Concepts]]
- [[Data Lake vs Lakehouse]]
- [[Data Warehouse]]
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]

## See Also
- Confluent: [Schema Registry & Compatibility](https://docs.confluent.io/platform/current/schema-registry/avro.html#compatibility)  
- Apache Avro: [Specification](https://avro.apache.org/docs/current/specification/)  
- Protocol Buffers: [Language Guide](https://protobuf.dev/programming-guides/proto3/)  
- JSON Schema: [Getting Started](https://json-schema.org/learn/getting-started-step-by-step)

## Terms
[[data contract]], [[schema registry]], [[subject]], [[schema ID]], [[compatibility mode]], [[backward compatibility]], [[forward compatibility]], [[full compatibility]], [[evolution]], [[default]], [[nullability]], [[logical type]], [[namespace]], [[record]], [[message]], [[enum]], [[oneof]], [[IDL]], [[code generation]], [[serializer]], [[deserializer]], [[serde]], [[canonical form]], [[fingerprint]], [[wire format]], [[producer]], [[consumer]], [[breaking change]], [[migration]], [[changelog]]
