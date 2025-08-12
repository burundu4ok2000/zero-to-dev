---
title: "Data Catalog & Governance (DataHub/OpenMetadata)"
lang_tags: "#lang/yaml #lang/sql"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/catalog/datahub #tool/catalog/openmetadata"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Data Catalog & Governance (DataHub-OpenMetadata).png]]


## **One-liner**
A **data catalog** centralizes metadata (**schemas**, **lineage**, **owners**, **SLA**) and enforces **governance** (RBAC, policies, tags) so people can **discover**, **trust**, and **use** datasets safely.

## The Big Idea
- Metadata is a product: publish **what a table means**, who **owns** it, how **fresh** it is, and where it flows (**lineage**).
- Tools like **DataHub** and **OpenMetadata** ingest metadata from warehouses, lakes, BI, and schedulers; they expose **search**, **glossary**, **tags**, **ownership**, and **policies**.
- Governance adds access control (**RBAC/ABAC**), **PII** classification, and **policies** (who can read/write/approve) integrated with your IAM.

## Core Capabilities
- **Discovery & Search** — find datasets, dashboards, owners, and documentation.  
- **Lineage** — upstream/downstream graph; integrates with **OpenLineage** and dbt artifacts.  
- **Glossary & Tags** — business terms linked to assets; semantic search.  
- **Ownership** — teams, SLAs, points of contact; on-call rotation links.  
- **Policies** — RBAC/ABAC to gate edits, visibility, and access requests.  
- **Quality Signals** — surface tests, freshness, incidents in the asset page.  

## Integrations
- **Warehouses/Lakes**: Snowflake, BigQuery, Redshift, Hive/Trino, Delta/Iceberg/Hudi tables.  
- **Orchestrators**: Airflow, Dagster (plus OpenLineage).  
- **dbt**: parse `manifest.json` to import models, columns, tests, and docs.  
- **BI**: Looker, Tableau, Power BI; link dashboards to datasets.  

## Example: DataHub Ingestion (YAML sketch)
```yaml
source:
  type: bigquery
  config:
    project_id: analytics-prod
sink:
  type: datahub-rest
  config:
    server: http://datahub:8080
```

## Governance Patterns
- Classify **PII** and apply **masking**/**row-level** policies in the platform (Snowflake/BigQuery) tied to catalog tags.  
- Gate critical changes with **ownership** approvals; record **SLA** and **data contracts** in asset docs.  
- Automate **stale asset** cleanup using last-access/run metadata.

## Common Gotchas
- Catalog rot: ingest once and forget → stale metadata; schedule regular syncs.  
- No owners: assets without a team create accountability gaps.  
- Over-tagging: taxonomy sprawl; keep a curated glossary.  
- Catalog ≠ access control: integrate with warehouse **policies/IAM** for enforcement.

## Related Concepts
- [[Data Observability & Lineage (OpenLineage/Marquez)]]
- [[dbt Core Concepts]]
- [[Data Quality & Testing (Great Expectations)]]
- [[Data Warehouse]]
- [[Data Contracts & Schema Management (Avro/Protobuf/JSON Schema)]]
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]

## See Also
- DataHub: https://www.datahubproject.io/
- OpenMetadata: https://open-metadata.org/
- OpenLineage: https://openlineage.io/docs/

## Terms
[[data catalog]], [[metadata]], [[schema]], [[owner]], [[SLA]], [[lineage]], [[glossary]], [[tagging]], [[RBAC]], [[ABAC]], [[policy]], [[PII classification]], [[masking]], [[row-level security]], [[column-level security]], [[access request]], [[ingestion connector]], [[asset]], [[search]], [[documentation]]
