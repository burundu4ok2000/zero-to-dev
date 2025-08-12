---
title: "Data Versioning & Reproducibility (lakeFS/DVC)"
lang_tags: "#lang/bash #lang/yaml"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/versioning/lakefs #tool/versioning/dvc"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Data Versioning & Reproducibility (lakeFS-DVC).png]]


## **One-liner**
Version datasets like code: create **branches**, **commits**, and **tags** over your lake, enable **reproducible** pipelines, safe **backfills**, and short-lived **preview** environments.

## The Big Idea
- Tools like **lakeFS** wrap object storage with a **Git-like** model (branches over buckets). **DVC** versions files/dirs and tracks data lineage alongside Git.
- Reproducibility means a job can re-run against the **same snapshot**; debugging and rollback become trivial.

## Core Concepts
- **Repository** — logical dataset (backed by an object store).  
- **Branch** — isolated view of data for dev/testing; merge back after validation.  
- **Commit** — immutable snapshot of data + metadata.  
- **Tag/Release** — named pointer to a commit (e.g., `gold-2025-08-12`).  
- **Import/Ref** — reference external data without copy (lakeFS).  
- **Pipeline integration** — pass commit IDs to jobs; promote after tests.

## Patterns
- **Preview environments**: branch from `main`, run **dbt build** and quality checks; if green → **merge** to publish.  
- **Backfills**: branch, run backfill, compare **row deltas**, then merge atomically.  
- **Repro bugfix**: pin consumer to a known commit; diff changes between commits.  
- **CI/CD**: treat data commits as release artifacts; attach lineage and run results.

## lakeFS Example (CLI sketch)
```bash
lakectl repo create lakefs://analytics s3://company-analytics
lakectl branch create lakefs://analytics@dev --source main
# run jobs against dev commit, then:
lakectl merge lakefs://analytics@dev lakefs://analytics@main
```

## DVC Example (YAML)
```yaml
stages:
  preprocess:
    cmd: python preprocess.py
    deps: [raw/data.csv]
    outs:
      - data/clean.parquet
```

## Common Gotchas
- Treating versioning as “copy folders with dates” → no atomicity or lineage.  
- Not passing **commit IDs** to pipelines; jobs accidentally read moving targets.  
- Orphaned branches consuming storage; schedule retention policies.  
- Versioning **secrets** or PII in repos — never.

## Related Concepts
- [[Medallion Architecture (Bronze/Silver/Gold)]]
- [[Data Observability & Lineage (OpenLineage/Marquez)]]
- [[CI-CD for Data (GitHub Actions, dbt build, Airflow deploy)]]
- [[Data Quality & Testing (Great Expectations)]]
- [[Lakehouse Table Formats (Delta vs Iceberg vs Hudi)]]

## See Also
- lakeFS: https://lakefs.io/
- DVC: https://dvc.org/
- Delta Lake time travel: https://delta.io/

## Terms
[[branch]], [[commit]], [[tag]], [[snapshot]], [[preview environment]], [[time travel]], [[data diff]], [[promotion]], [[rollback]], [[retention]], [[atomicity]], [[lineage]], [[artifact]], [[reproducibility]]
