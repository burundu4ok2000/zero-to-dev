![[image.png]]
  

**Как читать**

- Фазы: **Core → Warehousing/Transformation (dbt) → Orchestration (Airflow) → Streaming (Kafka/Spark) → Cloud (GCP/Azure)**.
    
- Для каждой фазы: _Outcome_ (что «готово»), **Free-first** курс/доки, _Optional_ (если хочешь глубже).
    

---

### **Фаза 0 — Опора (Git/Docker/SQL/Python)**

  

**Outcome:** умеешь контейнеризовать мини-ETL, работаешь с Git-ветками/PR, пишешь запросы с CTE/оконными функциями.

**Free-first:**

- **DE Zoomcamp (вводные модули: Docker, SQL, GCP/BigQuery, dbt, Kafka, Spark)** — бесплатный 9-недельный курс от DataTalks.Club. → Repo: [https://github.com/DataTalksClub/data-engineering-zoomcamp](https://github.com/DataTalksClub/data-engineering-zoomcamp) 
    
    **Optional:** DataTalks.Club блог об устроении курса. 
    

---

### **Фаза 1 — Warehousing / Transformation (dbt)**

  

**Outcome:** слой **staging → marts** (звезда), базовые тесты и автодоки (dbt docs).

**Free-first:**

- **dbt Quickstart** (любой DWH: BigQuery/Redshift/Snowflake/Databricks). → [https://docs.getdbt.com](https://docs.getdbt.com) (раздел Quickstarts). 
    
    **Optional:** продолжай соответствующий модуль **DE Zoomcamp** (Analytics Engineering). 
    

---

### **Фаза 2 — Orchestration (Airflow)**

  

**Outcome:** работающий **DAG** с расписанием, ретраями, сенсорами и идемпотентностью.

**Free-first:**

- **Airflow Docs** — Core Concepts, Scheduler. → [https://airflow.apache.org/](https://airflow.apache.org/) (концепции/планировщик). 
    
    **Optional:** гайды по best practices от экосистемы Astronomer.
    

---

### **Фаза 3 — Streaming (Kafka / Spark Structured Streaming)**

  

**Outcome:** продьюсер → **Kafka topics** → **Spark Structured Streaming** (окна, watermarking, checkpointing) → sink.

**Free-first:**

- **Kafka**: Intro + **Quickstart**. → [https://kafka.apache.org/](https://kafka.apache.org/) 
    
- **Spark Structured Streaming Guide**. → [https://spark.apache.org/docs/](https://spark.apache.org/docs/) (Structured Streaming programming guide). 
    

---

### **Фаза 4 — Cloud (GCP / Azure)**

  

**Outcome:** развёрнут минимальный прод-контур: хранилище+DWH, секреты/IAM, мониторинг, при необходимости IaC.

  

**GCP — free-first:**

- **Google Cloud: Professional Data Engineer — learning & exam page** (карта доменов + тренинги и skill badges/лабы). → [https://cloud.google.com/learn/certification/data-engineer](https://cloud.google.com/learn/certification/data-engineer) 
    
- **Google Cloud Training каталог** (role-based пути, Data Engineer). → [https://cloud.google.com/learn/training](https://cloud.google.com/learn/training) 
    

  

**Azure — free-first (без DP-203):**

- **Microsoft Learn — Data Engineer career path** (актуальные модули/пути по Azure/Fabric). → [https://learn.microsoft.com/training/career-paths/data-engineer](https://learn.microsoft.com/training/career-paths/data-engineer) 
    
- **Get started with data engineering on Azure** (вводный learn-путь). → [https://learn.microsoft.com/training/paths/get-started-data-engineering/](https://learn.microsoft.com/training/paths/get-started-data-engineering/) 
    

  

> Примечание: **DP-203** (Azure Data Engineer Associate) **официально снят 31 марта 2025**, поэтому ориентируйся на актуальные learn-пути и материалы (Fabric/Synapse/ADF). 

---

## **Карточки для Obsidian (шаблон)**

```
### <Фаза — название>
**Outcome:** <что именно «готово»>  
**Free-first:** [курс/доки 1](URL), [курс/доки 2](URL)  
**Optional:** [ресурс 1](URL)  
**Связь с проектами:** <какой портфолио-проект/веха закрывается>  
**Evidence:** ссылка на репо/ноут/видео-демо (3–7 мин)
```

### **Пример (Streaming)**

```
### Streaming (Kafka/Spark)
**Outcome:** потоковый пайплайн с окнами и чекпоинтингом  
**Free-first:** [Kafka Quickstart](https://kafka.apache.org/quickstart), 
[Spark Structured Streaming Guide](https://spark.apache.org/docs/3.5.1/structured-streaming-programming-guide.html)  
**Optional:** DE Zoomcamp — модуль Streaming (Kafka/Spark)  
**Связь с проектами:** P3 — Kafka → Spark агрегаты  
**Evidence:** repo + README с latency/throughput
```

---

## **Где всё живёт**

- **DE Zoomcamp GitHub** — опорный репозиторий (силлабус, задания, проекты). 
    
- **DataTalks.Club** — витрина курсов/обновлений. 
    
- **Google Cloud** — официальные **learning paths** и сертификаты (в т.ч. **PDE**). 
    
- **Microsoft Learn** — карьеры и пути Data Engineer (вместо DP-203). 
    

---

Хочешь — сгенерирую **PNG-дорожку «Course Map»** (горизонтальные карточки по фазам) в тёмной теме, под твой Canvas. Или собрать тебе один .md с кликабельными карточками и проставленными ссылками? 🚀