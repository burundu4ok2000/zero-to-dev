---
title: "Docker for Data Engineering"
lang_tags: "#lang/docker"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/docker"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Docker for Data Engineering.png]]


## **One-liner**
Use **Docker** to package data tools (DBs, brokers, dbt, Airflow) into reproducible **containers** with isolated **networks**, persistent **volumes**, and automated multi-service setups via **Docker Compose**.

## The Big Idea
- Containerize your data stack so onboarding is **minutes**, not days: consistent **runtime**, pinned **versions**, and disposable environments.
- Compose multiple services (Postgres, MinIO, Kafka, dbt) with a single `docker compose up` and wire them via an isolated **bridge network**.
- Keep state in **named volumes** (e.g., `pg_data`) so you can destroy/recreate containers without losing data.
- Favor **multi-stage builds** to keep images slim; run as a **non-root** **USER**; keep secrets out of images.

## Core Building Blocks
- **Image** — read-only template with OS/libs/app. Built from a **Dockerfile**.  
- **Container** — running instance of an image (ephemeral).  
- **Registry** — where images live (Docker Hub, GHCR, ECR, GCR).  
- **Dockerfile** — instructions to build an image; supports **multi-stage** and **cache** layers.  
- **Volume** — persistent data mount managed by Docker; alternative: **bind mount**.  
- **Network** — virtual LAN for containers; default **bridge** network resolves by service name.  
- **Compose** — YAML to define multi-container apps, **healthcheck**, **depends_on**, **profiles**.  

## Minimal Dockerfile (Python ETL app)
```dockerfile
# syntax=docker/dockerfile:1
FROM python:3.12-slim AS base
ENV PYTHONDONTWRITEBYTECODE=1 PYTHONUNBUFFERED=1
WORKDIR /app
RUN apt-get update && apt-get install -y --no-install-recommends build-essential && rm -rf /var/lib/apt/lists/*
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt
COPY . .
# drop privileges
RUN useradd -m appuser
USER appuser
CMD ["python", "main.py"]
```

## Compose: local analytics stack (Postgres + MinIO + dbt-runner)
```yaml
services:
  postgres:
    image: postgres:16
    environment:
      POSTGRES_USER: analytics
      POSTGRES_PASSWORD: analytics
      POSTGRES_DB: warehouse
    ports: ["5432:5432"]
    volumes:
      - pg_data:/var/lib/postgresql/data
    healthcheck:
      test: ["CMD-SHELL", "pg_isready -U analytics"]
      interval: 10s
      timeout: 5s
      retries: 5

  minio:
    image: minio/minio:latest
    command: server /data --console-address ":9001"
    environment:
      MINIO_ROOT_USER: minio
      MINIO_ROOT_PASSWORD: minio12345
    ports: ["9000:9000", "9001:9001"]
    volumes:
      - minio_data:/data

  dbt:
    image: ghcr.io/dbt-labs/dbt-postgres:1.8.0
    working_dir: /usr/app
    volumes:
      - ./dbt:/usr/app        # mount your dbt project
    depends_on:
      postgres:
        condition: service_healthy
    environment:
      DBT_PROFILES_DIR: /usr/app

volumes:
  pg_data:
  minio_data:
```

## Handy Commands
```bash
# build & run
docker build -t etl:dev .
docker run --rm -it --name etl --network mynet etl:dev

# compose up/down
docker compose up -d           # start all
docker compose ps              # list services
docker compose logs -f dbt     # follow logs
docker compose down            # stop (preserves volumes)
docker compose down -v         # stop and delete volumes

# exec & copy
docker exec -it etl bash
docker cp etl:/app/output.csv ./output.csv

# prune old stuff (careful)
docker system prune -f
```

## Patterns for Data Work
- **Local dev parity**: mirror prod versions (Postgres/Kafka tags); pin images for reproducible CI.  
- **Profiles**: use Compose **profiles** to toggle heavy services (`--profile kafka`).  
- **Health gates**: gate dependent services with `depends_on: condition: service_healthy`.  
- **Resource limits**: set `deploy.resources` or `--cpus/--memory` to avoid runaway jobs.  
- **Secrets**: pass via env files (`env_file:`) or Docker **secrets**; never bake into image.  
- **Data exchange**: mount a **bind** for `/data` to inspect artifacts from host.  
- **Network DNS**: talk to `postgres:5432` by service name, not `localhost`.  
- **Build cache**: order Dockerfile steps to maximize layer caching (requirements before source).  
- **CI**: run `docker compose -f compose.ci.yml up --build --exit-code-from dbt` on PRs.

## Security & Ops
- Run as non-root **USER**; use minimal bases (e.g., `python:slim`, `debian:bookworm-slim`).  
- Keep **.dockerignore** to avoid copying venvs, caches, big data dumps.  
- Pin image digests or at least tags; scan with **trivy**/**snyk**.  
- Use **read-only** root FS where possible; mount only needed volumes.  
- Backup volumes; label them by project; avoid writing secrets to volumes.  

## Common Gotchas
- Using `localhost` inside containers—use service names on the **bridge** network.  
- Forgetting **volumes** → data lost on `down`.  
- Giant images from copying `.venv` or build caches—use **.dockerignore** and multi-stage.  
- Cross-platform issues (ARM vs x86) — pick **multi-arch** images or set `--platform`.  
- Compose version drift — keep a `docker compose version` baseline in README/CI.

## Related Concepts
- [[Data Ingestion]]
- [[ELT]]
- [[ETL]]
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]
- [[dbt Core Concepts]]
- [[Data Warehouse]]
- [[Stream Processing & Kafka Fundamentals]]
- [[Change Data Capture (CDC)]]

## See Also
- [Docker Docs: Get Started](https://docs.docker.com/get-started/)
- [Dockerfile Best Practices](https://docs.docker.com/build/building/best-practices/)
- [Compose Specification](https://docs.docker.com/compose/compose-file/compose-file-v3/)
- [Awesome Compose (samples)](https://github.com/docker/awesome-compose)

## Terms
[[image]], [[container]], [[registry]], [[Dockerfile]], [[multi-stage build]], [[layer cache]], [[compose]], [[service]], [[volume]], [[bind mount]], [[network]], [[bridge network]], [[healthcheck]], [[depends_on]], [[profile]], [[entrypoint]], [[command]], [[env var]], [[secret]], [[USER non-root]], [[read-only rootfs]], [[port mapping]], [[platform]], [[arm64]], [[amd64]]
