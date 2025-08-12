---
title: "Data Quality & Testing (Great Expectations)"
lang_tags: "#lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/data_quality/great_expectations"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---


![[Data Quality & Testing (Great Expectations).png]]

## **One-liner**
Make data trustworthy by codifying **expectations** (tests) about your datasets—nulls, types, ranges, **freshness**, **uniqueness**, and **referential integrity**—and run them automatically in your **ELT/ETL** pipelines with Great Expectations.

## The Big Idea
- Data breaks silently. **Great Expectations (GE)** turns assumptions into executable checks. Fail fast, quarantine bad rows, and keep downstream **BI/ML** sane.
- Define checks as **expectations** grouped into an **expectation suite**. Validate **batches** of data via a **checkpoint**. Publish **Data Docs** to make results visible.
- Store results and suites in versioned **stores** (S3/GCS/git). Pipe outcomes to alerting and block deployments or **MERGE** steps when quality drifts.
- Complements **dbt tests**: GE excels at dataset-level profiling, distributions, and row-wise assertions; dbt shines at **schema**- and **model**-level contracts in SQL.

## Core Pieces (GE)
- **Expectation** — a single rule (e.g., “`order_id` is not null”).  
- **Expectation Suite** — a versioned collection of expectations.  
- **Data Context** — project config and metadata.  
- **Batch / Validator** — a specific slice of data you validate.  
- **Checkpoint** — how/what to run, where to write **validation results**.  
- **Data Docs** — static site with human-friendly results.  
- **Stores & Actions** — backends (S3/GCS/DB) and side effects (Slack, stop run).

## Typical Checks
- **Schema & types**: column exists, type matches.  
- **Nullability & completeness**: % of nulls ≤ threshold.  
- **Uniqueness / PK**: no duplicates; composite keys valid.  
- **Referential integrity**: **foreign key** values are a subset of a dim table.  
- **Ranges & sets**: numeric bounds, allowed enums, regex for emails.  
- **Distribution**: std/quantiles within tolerance; **row count** within delta vs yesterday.  
- **Freshness**: `max(event_ts)` not older than N minutes/hours.

## Integration Patterns
- In **Airflow/Dagster**: run a **checkpoint** after **extract/load** and before `dbt run`. On failure → alert + stop downstream jobs.  
- With **Spark** or **Pandas**: validate at **Bronze → Silver** boundary to catch dedupe/type issues early.  
- **DLQ/Quarantine**: write failing rows to a separate table or path for triage; add **lineage** tags.  
- **Contracts**: pair GE with explicit **data contracts** (schemas, owners, SLA).

## Example (conceptual Python with Airflow)
```python
import great_expectations as ge
from great_expectations.core.batch import BatchRequest
from airflow.operators.python import PythonOperator

def validate_orders(**ctx):
    context = ge.get_context()  # loads gx project
    suite_name = "silver_orders_suite"
    batch = BatchRequest(
        datasource_name="warehouse",
        data_asset_name="silver.orders",
        options={{"execution_date": ctx["ds"]}},
    )
    validator = context.get_validator(batch_request=batch, expectation_suite_name=suite_name)
    # expectations
    validator.expect_column_values_to_not_be_null("order_id")
    validator.expect_column_values_to_be_unique("order_id")
    validator.expect_column_values_to_be_in_set("status", ["paid", "shipped", "refunded"])
    validator.expect_column_max_to_be_between("order_amount", min_value=0, max_value=100000)
    # run via checkpoint (or save & run)
    checkpoint = context.add_or_update_checkpoint(
        name="silver_orders_checkpoint",
        validations=[{{"batch_request": batch, "expectation_suite_name": suite_name}}],
    )
    result = context.run_checkpoint(checkpoint_name="silver_orders_checkpoint")
    if not result["success"]:
        raise RuntimeError("Data quality failed for silver.orders")

validate = PythonOperator(task_id="validate_silver_orders", python_callable=validate_orders)
```

## Example (YAML snippet – suite definition)
```yaml
expectation_suite_name: silver_orders_suite
expectations:
  - expect_column_values_to_not_be_null:
      column: order_id
  - expect_column_values_to_be_unique:
      column: order_id
  - expect_column_values_to_be_in_set:
      column: status
      value_set: ["paid", "shipped", "refunded"]
  - expect_column_values_to_match_regex:
      column: email
      regex: "^[^@\s]+@[^@\s]+\.[^@\s]+$"
  - expect_table_row_count_to_be_between:
      min_value: 1000
      max_value: 2000000
```

## Anti-patterns
- Only checking nulls/uniqueness, skipping **freshness** and **row-count deltas**.  
- Running tests **after** transformations—catch issues **before** `MERGE` into **Silver/Gold**.  
- No **baseline**/tolerance for distributions → noisy alerts.  
- Storing suites/results locally—use durable **stores** and CI checks.

## Related Concepts
- [[ELT]]  
- [[ETL]]  
- [[Data Ingestion]]  
- [[Data Warehouse]]  
- [[Medallion Architecture (Bronze/Silver/Gold)]]  
- [[Dimensional Modeling (Kimball)]]  
- [[Orchestration & Scheduling (Airflow/Cron/Dagster)]]  
- [[dbt Core Concepts]]  
- [[Change Data Capture (CDC)]]  

## See Also
- [Great Expectations: Getting started](https://docs.greatexpectations.io/docs/)
- [Astronomer: Great Expectations with Airflow](https://www.astronomer.io/guides/airflow-great-expectations/)
- [dbt: Tests and documentation](https://docs.getdbt.com/docs/build/tests)

## Terms
[[expectation]], [[expectation suite]], [[data context]], [[validator]], [[batch]], [[checkpoint]], [[validation result]], [[data docs]], [[store]], [[action]], [[schema validation]], [[uniqueness]], [[foreign key subset]], [[range check]], [[set membership]], [[regex]], [[distribution]], [[quantile]], [[freshness]], [[row count delta]], [[quarantine]], [[dead-letter queue]], [[SLA]], [[data contract]], [[lineage]]
