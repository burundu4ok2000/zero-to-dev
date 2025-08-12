---
title: "Orchestration & Scheduling (Airflow/Cron/Dagster)"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/orchestration/airflow #tool/orchestration/dagster"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Orchestration & Scheduling (Airflow-Cron-Dagster).png]]

## **One-liner**
Run reliable data pipelines with **DAGs**, retries, backfills, and **SLA** tracking using Airflow, Cron, and Dagster.

## The Big Idea
- **Orchestration** coordinates tasks; **scheduling** decides when they run. Together they turn scripts into repeatable, observable pipelines.
- Model workflows as a **DAG** (Directed Acyclic Graph): nodes are **tasks**, edges are **dependencies**.
- Robust pipelines rely on **idempotency**, **retries with exponential backoff**, **backfill**/**catchup**, **concurrency** limits, and **isolation** (queues/pools).
- Prefer **declarative** configs, explicit **data contracts**, and strong **observability** (metrics, logs, traces, lineage).

## Core Concepts
- **DAG** — the workflow structure; no cycles.  
- **Task** — an atomic unit of work (Python, SQL, Spark job, Bash, dbt).  
- **Operators / Ops** — task types (Airflow Operators, Dagster Ops/Assets).  
- **Sensors** — wait for external conditions (file landed, partition ready).  
- **Schedule** — when to run (cron strings or interval-based).  
- **Catchup & Backfill** — execute missed historical intervals safely.  
- **Concurrency & Pools** — throttle parallelism to protect systems.  
- **Retries** — automatic reruns on failure; pair with **idempotent** writes.  
- **SLA/SLO** — timing guarantees for data freshness.  
- **Observability** — logs, metrics, traces, lineage, and alerting hooks.

## Design Patterns
- **Incremental windows**: drive runs by **execution date**, filter by **watermark**/**cursor**, write append-only then **MERGE**.  
- **Event-driven**: trigger downstream on file/object events or message bus signals.  
- **Decouple compute**: tasks call jobs on Spark/Kubernetes, orchestrator only coordinates.  
- **Cross-DAG contracts**: publish artifacts to well-known locations; avoid hidden coupling.  
- **Blue/Green DAGs**: ship a new DAG alongside old; switch consumers when validated.

## Examples

### Airflow: hourly ELT skeleton
```python
from airflow import DAG
from airflow.operators.bash import BashOperator
from datetime import datetime, timedelta

default_args = dict(retries=3, retry_delay=timedelta(minutes=5))
with DAG(
    "elt_hourly",
    start_date=datetime(2025, 1, 1),
    schedule="@hourly",
    catchup=True,
    default_args=default_args,
) as dag:
    extract = BashOperator(task_id="extract", bash_command="python extract.py { ds_nodash }")
    load    = BashOperator(task_id="load",    bash_command="python load.py { ds_nodash }")
    transform = BashOperator(task_id="transform", bash_command="dbt run --vars execution_date:{ ds }")
    extract >> load >> transform
```

### Cron: daily run at 02:15
```cron
15 2 * * * /usr/local/bin/python /opt/etl/daily_job.py >> /var/log/etl/daily_job.log 2>&1
```

### Dagster: assets with partitioning
```python
from dagster import asset, DailyPartitionsDefinition

daily = DailyPartitionsDefinition(start_date="2025-01-01")

@asset(partitions_def=daily)
def bronze_orders(context):
    day = context.partition_key
    # read source for `day`, write to bronze table/partition

@asset(partitions_def=daily, deps=[bronze_orders])
def silver_orders(context):
    day = context.partition_key
    # clean/dedupe bronze -> silver for `day`
```

## Common Gotchas
- Side-effectful tasks without **idempotency** → duplicates or corruption on retry.  
- Hidden state in containers or local disks → non-reproducible runs. Prefer **stateless** tasks and external state.  
- Inconsistent **grains** between schedule interval and data filters → missed or double-processed rows.  
- Overloading the orchestrator with heavy compute — let Spark/K8s do the heavy lifting.  
- Silenced alerts or absent **SLA** monitors → you discover failures from users, not dashboards.

## Related Concepts
- [[ELT]]  
- [[ETL]]  
- [[Data Ingestion]]  
- [[Data Warehouse]]  
- [[dbt Core Concepts]]  
- [[Change Data Capture (CDC)]]  
- [[Stream Processing & Kafka Fundamentals]]  
- [[Data Quality & Testing (Great Expectations)]]  

## See Also
- [Apache Airflow: Concepts](https://airflow.apache.org/docs/apache-airflow/stable/concepts/index.html)
- [Dagster: Software-defined assets](https://docs.dagster.io/concepts/assets/software-defined-assets)
- [Crontab Guru: Cron expression helper](https://crontab.guru/)
- [Astronomer: Airflow best practices](https://www.astronomer.io/guides/airflow-best-practices/)

## Terms
[[DAG]], [[task]], [[operator]], [[sensor]], [[schedule]], [[cron expression]], [[catchup]], [[backfill]], [[retry]], [[exponential backoff]], [[idempotency]], [[concurrency]], [[queue]], [[pool]], [[trigger]], [[event-driven pipeline]], [[data contract]], [[execution date]], [[partition]], [[watermark]], [[MERGE]], [[lineage]], [[observability]], [[SLA]], [[SLO]]
