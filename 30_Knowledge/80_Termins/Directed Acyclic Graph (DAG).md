---
title: "Directed Acyclic Graph (DAG)"
lang_tags: ""
type_tags: "#type/concept"
tool_tags: ""
status: "done"
difficulty: "na"
date: "2025-08-17"
source: ""
review_next: "2025-09-17"
---

## **One-liner

A **Directed Acyclic Graph** is a **graph** with **directed edges** and no **cycles**; nodes can be ordered by **topological sort**.

## Very simple

Think of tasks connected by arrows. You follow arrows forward to do tasks in the right order. You never loop back to the start, so no circles happen. That is why it is **acyclic**.

## Examples

### Example 1
```text
A → B → C
```
A must come before B, and B before C. No way back.

### **Example 2 (optional)**
```text
A → B
 ↘
   C → D
```
Arrows go forward only. Still no cycle.

##  Related Terms

[[graph]], [[node (graph)]], [[edge (graph)]], [[cycle (graph)]], [[topological sort]], [[partial order]], [[lineage]], [[critical path]]

## Related Concepts

- [[Airflow — DAG Anatomy]] – how **tasks** and **dependencies** form a **DAG** in orchestration
- [[Dagster — Graphs and Ops]] – building graphs of **ops** and **jobs**
- [[Prefect — Flow and Task Basics]] – flows as DAGs of tasks
- [[ETL Orchestration Patterns]] – using **DAGs** to control **ETL** steps
- [[Spark DAG — RDD Lineage]] – execution graphs and **lineage**
- [[Version Control — DAG of Commits]] – commits in Git form a **DAG**
- [[Dependency Resolution — Build Systems]] – make, Bazel, and **dependency graphs**

## See also

- [Wikipedia — Directed Acyclic Graph](https://en.wikipedia.org/wiki/Directed_acyclic_graph)
- [Topological Sorting — GeeksforGeeks](https://www.geeksforgeeks.org/topological-sorting/)
- [Apache Airflow — Concepts (DAGs)](https://airflow.apache.org/docs/apache-airflow/stable/core-concepts/dags.html)
