---
title: "CI/CD for Data (GitHub Actions, dbt build, Airflow deploy)"
lang_tags: "#lang/yaml #lang/sql #lang/python"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/github_actions #tool/dbt #tool/airflow"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[CI-CD for Data (GitHub Actions, dbt build, Airflow deploy).png]]


## **One-liner**
Wire **CI/CD** so every change to data code (**SQL**, **dbt**, **DAGs**) is tested, documented, and safely **deployed** across **dev → staging → prod** with rollbacks and guardrails.

## The Big Idea
- Treat data pipelines like software: versioned in Git, validated in **CI**, and promoted via **CD**.  
- CI runs fast checks on **PRs** (lint, unit/model tests, **dbt build**, **data quality**).  
- CD promotes artifacts (dbt project, compiled DAGs/images) through environments with approvals and **blue/green** or **canary** releases.  
- Guard with **data contracts**, **freshness/SLA** monitors, and **observability** to avoid shipping bad data.

## Environments & Promotion
- **dev**: per-dev schemas/workspaces (`dbt` target/schema = username).  
- **staging**: production-like data slices; scheduled integration tests and backfills.  
- **prod**: strict approvals; migrations and **backfills** are scripted and idempotent.  
- Promote via tags/branches (`main` → staging → prod) or release versions.

## CI: Pull Request Checks
- **Static checks**: `sqlfluff` for SQL style, `ruff/black` for Python, `yamllint` for configs, **detect-secrets**.  
- **dbt**: `dbt deps`, `dbt compile`, `dbt build --select state:modified+` using previous `manifest.json`.  
- **Tests**: `dbt test`, Great Expectations suites for critical tables, lightweight **data-diff** (row counts and key deltas against staging).  
- **Artifacts**: upload `manifest.json`, `catalog.json`, and docs site as build artifacts.

### GitHub Actions — PR pipeline (dbt + linters)
```yaml
name: pr-ci
on:
  pull_request:
    paths:
      - "models/**"
      - "seeds/**"
      - "snapshots/**"
      - "macros/**"
      - ".github/workflows/**"
jobs:
  ci:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - uses: actions/setup-python@v5
        with: {python-version: "3.12"}
      - name: Install tools
        run: |
          pip install dbt-core dbt-bigquery sqlfluff ruff detect-secrets
      - name: Lint
        run: |
          ruff check .
          sqlfluff lint models --dialect bigquery
          detect-secrets scan --all-files
      - name: dbt deps & compile
        env: {DBT_PROFILES_DIR: ./.github/dbt_profiles}
        run: |
          dbt deps
          dbt compile
      - name: Build changed graph only
        env: {DBT_PROFILES_DIR: ./.github/dbt_profiles}
        run: |
          dbt build --select state:modified+ --state target
      - name: Upload artifacts
        uses: actions/upload-artifact@v4
        with:
          name: dbt-artifacts
          path: |
            target/manifest.json
            target/run_results.json
            target/catalog.json
```

## CD: Deploy dbt & Airflow
- **dbt**: run `dbt build` on **staging**; require approval; then run on **prod**. Generate and publish **docs**.  
- **Airflow**: package DAGs in a Docker image or sync to a DAG bucket; roll out via Helm/Kubernetes, MWAA/Composer, or simple rsync to the scheduler volume. Use **healthchecks** and **graceful** restarts.

### GitHub Actions — deploy (staging → prod)
```yaml
name: cd-deploy
on:
  workflow_dispatch:
  push:
    branches: [main]
jobs:
  staging:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - uses: actions/setup-python@v5
        with: {python-version: "3.12"}
      - name: Install dbt
        run: pip install dbt-core dbt-bigquery
      - name: dbt build (staging)
        env: {DBT_PROFILES_DIR: ./.github/dbt_profiles}
        run: dbt build --target staging
      - name: Publish docs
        run: dbt docs generate && ./scripts/publish_docs.sh
  prod:
    needs: staging
    runs-on: ubuntu-latest
    environment: production   # requires manual approval
    steps:
      - uses: actions/checkout@v4
      - uses: actions/setup-python@v5
        with: {python-version: "3.12"}
      - name: Install dbt
        run: pip install dbt-core dbt-bigquery
      - name: dbt build (prod)
        env: {DBT_PROFILES_DIR: ./.github/dbt_profiles}
        run: dbt build --target prod
```

### Airflow DAG Image (containerized deploy)
```yaml
name: airflow-dag-image
on: {push: {branches: [main], paths: ["dags/**","requirements.txt","Dockerfile"]}}
jobs:
  build-and-push:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - name: Build
        run: docker build -t ghcr.io/acme/airflow-dags:${{ github.sha }} .
      - name: Login & Push
        run: |
          echo ${{ secrets.GHCR_TOKEN }} | docker login ghcr.io -u ${{ github.actor }} --password-stdin
          docker push ghcr.io/acme/airflow-dags:${{ github.sha }}
      - name: Rollout (Helm)
        run: helm upgrade --install airflow charts/airflow --set dags.image.tag=${{ github.sha }}
```

## Migrations & Backfills
- Bundle schema migrations with code (dbt **migrations**/seeds/snapshots).  
- Make backfills **idempotent** and parameterized by **date range**; run in staging first; monitor **row deltas** and runtime.  
- Pause downstream schedules during high-impact migrations; communicate via **status page** or Slack bot.

## Rollbacks & Safety Nets
- Keep **previous artifacts** (dbt `manifest.json`, DAG image tags) for quick rollback.  
- Use **feature flags** or **environment variables** to disable risky models/DAGs.  
- Enforce **SLA**/**freshness** checks as release gates; block prod deploy if violated.  
- Gate on **lineage impact**: deploy only if downstream critical assets aren’t failing.

## Pre-commit (dev experience)
```yaml
repos:
  - repo: https://github.com/astral-sh/ruff-pre-commit
    rev: v0.5.0
    hooks: [{id: ruff}]
  - repo: https://github.com/sqlfluff/sqlfluff
    rev: 3.0.0
    hooks: [{id: sqlfluff-lint, additional_dependencies: ["sqlfluff-templater-dbt"]}]
  - repo: https://github.com/Yelp/detect-secrets
    rev: v1.5.0
    hooks: [{id: detect-secrets}]
```

## Observability & Approvals
- Post **run_results** to Slack; link **docs** and **lineage**.  
- Track **MTTR**, failed build rate, and dataset **freshness** across envs.  
- Require **code owners** review for sensitive domains (PII, finance).

## Common Gotchas
- Running `dbt build` against prod on every push → compute burn; scope to **changed graph** and schedule full builds.  
- No state cache → `state:modified+` can’t work; always persist `target/manifest.json` in CI artifacts.  
- Treating Airflow deploy as “copy files” without environment parity; prefer **images** or tested sync with health checks.  
- Secrets in repo; use **GitHub Secrets** / cloud secret managers.  
- Not testing migrations/backfills at scale before prod.

## Related Concepts
- [[dbt Core Concepts]]
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]
- [[Data Quality & Testing (Great Expectations)]]
- [[Data Observability & Lineage (OpenLineage/Marquez)]]
- [[ELT]]
- [[Data Warehouse]]
- [[Data Contracts & Schema Management (Avro/Protobuf/JSON Schema)]]

## See Also
- GitHub Actions: https://docs.github.com/actions
- dbt: Deployment best practices — https://docs.getdbt.com/best-practices/how-we-structure/overview
- Astronomer: CI/CD for Airflow — https://www.astronomer.io/docs/learn/ci-cd

## Terms
[[CI]], [[CD]], [[pipeline]], [[artifact]], [[environment]], [[dev environment]], [[staging environment]], [[production]], [[approval]], [[blue/green deploy]], [[canary release]], [[rollback]], [[migration]], [[backfill]], [[dbt build]], [[manifest.json]], [[run_results.json]], [[sqlfluff]], [[ruff]], [[detect-secrets]], [[GitHub Actions]], [[Helm]], [[Docker image]], [[MWAA]], [[Composer]], [[lineage gate]], [[SLA gate]], [[feature flag]]
