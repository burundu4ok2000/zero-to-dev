---
title: "Data Observability & Lineage (OpenLineage/Marquez)"
lang_tags: "#lang/python #lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/observability/openlineage #tool/observability/marquez"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Data Observability & Lineage (OpenLineage-Marquez).png]]


## **One-liner**
End-to-end **data observability** = measure **freshness**, **volume**, **schema**, and **distribution**; **lineage** = track how **jobs** move **datasets**. **OpenLineage** is an open spec for emitting lineage events; **Marquez** stores and visualizes them.

## The Big Idea
- Observability answers “Is my data **healthy** and **on time**?”; lineage answers “Where did it **come from** and who will I **break**?”
- **OpenLineage** defines a standard event with **job**, **run**, **dataset**, and **facets** (metadata like schema, data source, column lineage).
- **Marquez** is a service and UI that ingests OpenLineage events to build a **graph** of pipelines and datasets, enabling **impact analysis** and **root-cause** debugging.
- Integrate with orchestrators (Airflow, Dagster), **dbt**, and processing engines (Spark, Flink, SQL) to capture lineage at the **task** boundary.

## Core Concepts (OpenLineage)
- **Namespace** — logical scope (e.g., `prod` or `analytics`).  
- **Job** — a pipeline step (Airflow task/dbt model).  
- **Run** — a specific execution of a job with a **runId**.  
- **Dataset** — input/output data (table, file, topic) with **namespace** + **name**.  
- **Facets** — extensible metadata (e.g., **schema**, **dataSource**, **columnLineage**, **dataQualityMetrics**).  
- **Event** — `START`, `COMPLETE`, or `FAIL` with lists of **inputs** and **outputs**.

## Health Metrics (what to watch)
- **Freshness** — `max(event_ts)` lag vs now or scheduled **SLA**.  
- **Volume** — row/file counts and deltas vs baseline.  
- **Schema** — added/removed/changed columns; **contracts** enforce safe evolution.  
- **Distribution** — stats (min/max/null %, quantiles); detect **drift** and anomalies.  
- **Reliability** — job **success rate**, **latency**, backlog/lag for streams.

## Integration Patterns
- **Airflow**: install OpenLineage provider; it emits events per task with SQL parsing (for supported operators).  
- **dbt**: parse artifacts (`manifest.json`, `run_results.json`) or use dbt OpenLineage integration to emit lineage for each model.  
- **Spark/Flink**: use OpenLineage client to wrap jobs, including dataset I/O and schema facets.  
- **Quality checks**: attach **Great Expectations** results as **data quality facets**; block downstream on failures.  
- **Catalog sync**: export lineage graph to your data catalog; surface **owners** and **SLA** in docs.

## Example: OpenLineage Event (minimal JSON)
```json
{
  "eventType": "COMPLETE",
  "eventTime": "2025-08-12T10:15:00Z",
  "producer": "openlineage-airflow/1.0.0",
  "job": {"namespace": "prod", "name": "airflow.elt_hourly.transform"},
  "run": {"runId": "b7d1e5f3-9aee-4f5b-bc3b-9f2d4c1a8e21"},
  "inputs": [{"namespace": "warehouse", "name": "silver.orders"}],
  "outputs": [{"namespace": "warehouse", "name": "gold.fct_orders"}],
  "facets": {
    "schema": {"fields": [{"name": "order_id","type":"bigint"},{"name":"order_day","type":"date"}]},
    "dataQualityMetrics": {"rowCount": 124567, "nullCount": {"order_id": 0}}
  }
}
```

## Airflow Quickstart (conceptual)
```bash
pip install openlineage-airflow
export OPENLINEAGE_URL=http://marquez:5000
export OPENLINEAGE_NAMESPACE=prod
# In airflow.cfg enable the OpenLineage listener or use the provider's autoinstrumentation
```

## Marquez Deployment (docker-compose sketch)
```yaml
services:
  marquez:
    image: marquezproject/marquez:latest
    environment:
      - MARQUEZ_PORT=5000
    ports: ["5000:5000"]
  marquez-ui:
    image: marquezproject/marquez-web:latest
    environment:
      - MARQUEZ_HOST=http://localhost:5000
    ports: ["3000:3000"]
```

## Alerts & SLOs
- Turn freshness/volume/schema checks into **SLOs**; alert via PagerDuty/Slack when breached.  
- Combine lineage + SLOs for **blast radius**: given a failed job, list downstream **impacted** models/dashboards.  
- Track **MTTR** and incident history; attach **postmortems** to datasets/jobs.

## Common Gotchas
- Poor **dataset naming** (no stable namespace) breaks de-duplication of lineage nodes.  
- Only capturing lineage from the orchestrator—emit from engines too (Spark/SQL) to see **column-level** lineage.  
- No **contracts** → schema drift passes silently; align with [[Data Contracts & Schema Management (Avro/Protobuf/JSON Schema)]].  
- Capturing but not **alerting**: observability isn’t just dashboards; wire automated checks.  
- PII exposure in lineage metadata; avoid sampling values, stick to **metadata**/**stats**.

## Related Concepts
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]
- [[dbt Core Concepts]]
- [[Data Quality & Testing (Great Expectations)]]
- [[Data Contracts & Schema Management (Avro/Protobuf/JSON Schema)]]
- [[Data Warehouse]]
- [[ELT]]
- [[Change Data Capture (CDC)]]
- [[Stream Processing & Kafka Fundamentals]]

## See Also
- OpenLineage Docs — https://openlineage.io/docs/
- Marquez (GitHub) — https://github.com/MarquezProject/marquez
- OpenLineage Airflow — https://github.com/OpenLineage/OpenLineage/tree/main/integration/airflow
- DataHub lineage (alternative) — https://www.datahubproject.io/docs/metadata-modeling/lineage/

## Terms
[[observability]], [[lineage]], [[OpenLineage]], [[Marquez]], [[namespace]], [[job]], [[run]], [[dataset]], [[facet]], [[schema facet]], [[column lineage]], [[data quality facet]], [[producer]], [[eventType]], [[START event]], [[COMPLETE event]], [[FAIL event]], [[impact analysis]], [[root cause analysis]], [[SLA]], [[SLO]], [[freshness]], [[volume]], [[schema drift]], [[distribution drift]], [[runId]], [[Airflow provider]], [[dbt artifacts]], [[manifest.json]], [[run_results.json]], [[catalog]], [[owner]], [[postmortem]]
