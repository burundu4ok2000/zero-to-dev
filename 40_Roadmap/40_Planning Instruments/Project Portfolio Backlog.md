
![[project partfolio backlog.png]]


  

**Идея**

Короткий «лист ожидания» из 3–5 проектов, где каждый — **проверяемый инкремент ценности** (а не просто «курс прошёл»). Каждый проект содержит Outcome, стек, Acceptance/Evidence и док-ссылки.

---

## **P1 — Инкрементальный ETL из публичного API → DWH → BI**

  

**Outcome:** стабильный пайплайн, который ежедневно подгружает **только новые/изменённые** записи, складывает в DWH и визуализирует ключевые метрики.

**Стек:** Python + Requests, DB (BigQuery/PG/Snowflake), **dbt (incremental)**, BI (Looker Studio/Metabase).

**Acceptance / Evidence:**

- dbt-модель c **materialization: incremental** + README с описанием уникального ключа/стратегии апдейта. 
    
- Снижение времени/стоимости трансформаций против full-refresh (скрин сравнения). 
    
- DWH-таблицы с **partition/cluster** (пояснение выбора). 
    
    **Docs:** dbt «What is dbt?», docs & dbt docs generate. 
    

---

## **P2 — dbt-модели (staging → marts) + тесты качества (Great Expectations)**

  

**Outcome:** слой **staging → marts** (звезда), тесты **uniqueness / not null / referential**, автогенерация документации и **Data Docs**.

**Стек:** dbt, **Great Expectations (GX)**.

**Acceptance / Evidence:**

- dbt-модели и автодоки (dbt docs generate & serve). 
    
- GX-проект, отчёты **Data Docs** прикреплены к PR/релизу. 
    
    **Docs:** GX Data Docs, dbt Docs. 
    

---

## **P3 — Стриминг: Kafka → Spark Structured Streaming (агрегаты в реальном времени)**

  

**Outcome:** продьюсер пишет события в **Kafka topics**; **Spark Structured Streaming** считает оконные агрегаты (watermark, checkpoint) и кладёт в sink (DWH/OLAP).

**Стек:** Kafka (локально или Confluent Cloud), Spark Structured Streaming.

**Acceptance / Evidence:**

- Демонстрация: producer/consumer + Spark job с окнами/чекпоинтом; README с **latency/throughput**.
    
- Запуск по Quickstart (локально/Cloud) — ссылки/скрины. 
    
    **Docs:** Kafka Intro/Quickstart; Spark **Structured Streaming Programming Guide**. 
    

---

## **P4 — DAG в Airflow: расписание + алерты + идемпотентность**

  

**Outcome:** **Airflow DAG** с ретраями, расписанием (cron preset), сенсорами/зависимостями; алерты; идемпотентный перезапуск.

**Стек:** Apache Airflow.

**Acceptance / Evidence:**

- Скрин графа DAG + логика расписания и ретраев; описание «идемпотентности».
    
- Короткое видео (3–5 мин) с объяснением **scheduler** и триггеров. 
    
- Использование готового пресета (напр., @hourly) и/или cron-строки. 
    
    **Docs:** Airflow Core Concepts; Airflow Scheduler. 
    

---

## **(Опционально) P5 — Облако + CI/CD**

  

**Outcome:** минимальный прод-контур: хранилище+DWH в облаке, деплой пайплайна; CI/CD на **GitHub Actions**.

**Acceptance / Evidence:**

- Pipeline YAML (.github/workflows/*.yml) + секреты; скрин «зелёного» ран-лога. 
    
- Проект-борд в **GitHub Projects** с **Roadmap view** для трекинга вех. 
    

---

### **Как этим пользоваться (ритуал)**

1. Держи **3 активных проекта максимум**, остальные — в Backlog.
    
2. На каждый проект — один **явный Outcome и Acceptance/Evidence** (линки на демо/доки).
    
3. Связывай проекты с **OKR/KR** (например, KR: «end-to-end streaming demo»).
    

  

**Подсказка:** если хочешь «шлифануть ценность» для портфолио — добавляй в README явные метрики: «время ETL −60% за счёт incremental», «стоимость запроса −35% благодаря partition/cluster», «stream latency P95 < 5 с». (dbt incremental снижает runtime за счёт переработки только новых/изменённых строк; BigQuery partition/cluster ускоряет и уменьшает сканируемые данные.) 

  

Хочешь — сгенерирую PNG-карту Backlog (4 карточки в один экран) и md-шаблоны README для каждого проекта.