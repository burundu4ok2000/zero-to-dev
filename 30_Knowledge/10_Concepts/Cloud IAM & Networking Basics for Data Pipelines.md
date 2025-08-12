---
title: "Cloud IAM & Networking Basics for Data Pipelines"
lang_tags: "#lang/bash #lang/yaml"
type_tags: "#type/concept"
course_tags: ""
lecture_tags: ""
tool_tags: "#tool/cloud/aws #tool/cloud/gcp #tool/cloud/azure"
atom_idx: 01
status: "in-progress"
difficulty: "medium"
date: "2025-08-12"
timecode: ""
source: ""
review_next: "2025-09-12"
---

![[Cloud IAM & Networking Basics for Data Pipelines.png]]


## **One-liner**
Understand **IAM** roles, **service accounts**, **VPC** networking, and **private connectivity** to run data pipelines securely without sprinkling long-lived keys everywhere.

## The Big Idea
- Least-privilege **IAM** and private **network paths** prevent breaches. Pipelines should use short-lived **workload identity** (service accounts) and avoid public egress.
- Secure warehouse/lake access with **private endpoints** (PrivateLink/PSC), **VPC peering**, and controlled **egress/NAT**; rotate secrets with a **secret manager**.

## Core Concepts
- **IAM principal** — user, role, or **service account** that gets permissions.  
- **Policy/Role** — a set of permissions granted to a principal on a **resource**.  
- **VPC** — isolated network; subnets, **route tables**, **security groups**/**firewall rules**.  
- **Private connectivity** — **PrivateLink** (AWS), **Private Service Connect** (GCP), **Private Endpoint** (Azure).  
- **Peering / Transit** — connect VPCs/VNETs securely; beware overlapping CIDRs.  
- **NAT / Egress** — control outbound traffic; restrict to allowlists.  
- **Secrets** — store in **Secret Manager/KMS**; never in code or images.  
- **Workload identity** — bind K8s/VM workloads to cloud identities (no static keys).

## Patterns
- Assign a dedicated **service account** per pipeline/DAG; scope **least privilege** roles (e.g., read from `bronze`, write to `silver`).  
- Access S3/GCS via **instance/workload roles**, not access keys.  
- Use **private endpoints** to Snowflake/BigQuery/Databricks; block public access.  
- Centralize **egress** via NAT; monitor with flow logs; set **VPC-SC** (GCP) or equivalent for data exfiltration control.  
- Rotate secrets automatically; load at runtime from the secret manager.

## Example: GCP Workload Identity (conceptual)
```bash
gcloud iam service-accounts create etl-runner
gcloud projects add-iam-policy-binding $PROJ --member=serviceAccount:etl-runner@$PROJ.iam.gserviceaccount.com --role=roles/bigquery.dataEditor
# K8s workload identity binding (GKE):
kubectl annotate serviceaccount etl-sa iam.gke.io/gcp-service-account=etl-runner@$PROJ.iam.gserviceaccount.com
```

## Common Gotchas
- Hardcoded keys in code or Docker images.  
- Wide roles (`Owner`, `Editor`) instead of scoped permissions.  
- Public endpoints for warehouses/object stores; lack of egress control.  
- Overlapping CIDR blocks preventing peering.  
- Secrets in environment variables without rotation or audit.

## Related Concepts
- [[Docker for Data Engineering]]
- [[Orchestration & Scheduling (Airflow-Cron-Dagster)]]
- [[Data Warehouse]]
- [[Data Lake vs Lakehouse]]
- [[Data Observability & Lineage (OpenLineage/Marquez)]]
- [[Data Contracts & Schema Management (Avro/Protobuf/JSON Schema)]]

## See Also
- AWS IAM: https://docs.aws.amazon.com/IAM/latest/UserGuide/introduction.html
- GCP IAM: https://cloud.google.com/iam/docs/overview
- Azure AD & RBAC: https://learn.microsoft.com/azure/role-based-access-control/overview
- Private connectivity (AWS PrivateLink): https://docs.aws.amazon.com/vpc/latest/privatelink/what-is-privatelink.html

## Terms
[[IAM]], [[role]], [[policy]], [[service account]], [[resource]], [[VPC]], [[subnet]], [[route table]], [[security group]], [[firewall rule]], [[NAT]], [[egress]], [[PrivateLink]], [[Private Service Connect]], [[private endpoint]], [[peering]], [[CIDR]], [[secret manager]], [[KMS]], [[workload identity]], [[token]], [[least privilege]]
