# Assumptions / Decision Log — «памятка» простыми словами

> **Коротко:** это одна табличка, куда ты заносишь **важные предположения** (assumptions) и **принятые решения** (decisions) вместе с обоснованием.  
> Когда приходит соблазн снова сравнивать GCP vs AWS или dbt vs SQL-скрипты, ты открываешь лог и видишь: «а-га, уже выбрали – почему, кем, когда». Экономит нервы и не даёт топтаться на месте.  [oai_citation:0‡BestOutcome](https://bestoutcome.com/knowledge-centre/decision-log/?utm_source=chatgpt.com) [oai_citation:1‡govrn.com](https://govrn.com/blog/benefits-of-decision-logs-for-businesses?utm_source=chatgpt.com)

---

## Зачем вести такой лог

1. **Прозрачность** — любой участник (или сам ты через месяц) понимает, *почему* принято то или иное решение.  [oai_citation:2‡govrn.com](https://govrn.com/blog/benefits-of-decision-logs-for-businesses?utm_source=chatgpt.com)  
2. **Экономия времени** — нет бесконечных «а вдруг мы зря выбрали Airflow?». Смотришь лог, вспоминаешь доводы, двигаешься дальше.  [oai_citation:3‡BestOutcome](https://bestoutcome.com/knowledge-centre/decision-log/?utm_source=chatgpt.com)  
3. **История для ретроспектив** — видно, какие допущения были верными, где промахнулись. Это улучшает будущие решения.  [oai_citation:4‡Architectural Decision Records](https://adr.github.io/?utm_source=chatgpt.com)  
4. **Документ для новых людей** — новичок читает лог и быстро ловит контекст.  [oai_citation:5‡Atlassian](https://www.atlassian.com/software/confluence/templates/decision?utm_source=chatgpt.com)  

---

## Что вносить

| Поле | Что писать |
|------|------------|
| **ID** | Номер записи (A-001 – Assumption, D-001 – Decision) |
| **Дата** | Когда записали |
| **Заголовок** | Короткая суть: «Выбрали GCP» |
| **Описание / Резюме** | 1-2 предложения «что и зачем» |
| **Причины** | Ключевые доводы или ссылки на исследование |
| **Автор / Участники** | Кто предложил, кто одобрил (DACI помогает)  [oai_citation:6‡Atlassian](https://www.atlassian.com/software/confluence/templates/decision?utm_source=chatgpt.com) |
| **Последствия** | Что изменится, плюсы/минусы |
| **Срок пересмотра** | Дата, когда проверим актуальность |

> Такой формат повторяет идею **ADR — Architectural Decision Record**: одна запись = одно решение + контекст + последствия.  [oai_citation:7‡Architectural Decision Records](https://adr.github.io/?utm_source=chatgpt.com)

---

## Пример заполнения

| ID | Дата | Заголовок | Причины | Последствия | Срок ревью |
|----|------|-----------|---------|-------------|------------|
| **D-001** | 2025-08-10 | Выбрали **Google Cloud Platform** для прод-контура | BigQuery → без-серверный DWH, Dataflow (Apache Beam), встроенные IAM-политики; интеграция с Vertex AI.  [oai_citation:8‡Medium](https://medium.com/%40venimeka1906/why-i-chose-google-cloud-platform-gcp-for-data-engineering-real-world-benefits-32f6ea990533?utm_source=chatgpt.com) [oai_citation:9‡SquareShift Technologies](https://www.squareshift.co/post/5-key-benefits-of-using-gcp-for-your-data-engineering-projects?utm_source=chatgpt.com) | Учимся GCP CLI, настраиваем бюджет-алерты, Terraform под GCP. | 2026-02-01 |
| **D-002** | 2025-08-10 | Выбрали **dbt** для трансформаций | Версионирование, auto-docs, тесты и линейка модулей Zoomcamp.  [oai_citation:10‡dbt Developer Hub](https://docs.getdbt.com/docs/introduction?utm_source=chatgpt.com) | Пишем модели в `models/`, держим тесты not null/unique; CI = `dbt build`. | 2025-12-01 |
| **D-003** | 2025-08-10 | Выбрали **Apache Airflow** как оркестратор | Python-код, огромная экосистема операторов, туториалы от сообщества.  [oai_citation:11‡Apache Airflow](https://airflow.apache.org/docs/apache-airflow/stable/tutorial/pipeline.html?utm_source=chatgpt.com) | Делаем DAG-и с ретраями; держим WIP ≤ 10 DAG-ов; лог-алерты в Slack. | 2025-11-01 |
| **A-004** | 2025-08-10 | “Junior DA-оффер за 6 мес” — достижим | На рынке есть примеры перехода после Zoomcamp + 3 портфолио-проектов.  [oai_citation:12‡project-management-knowledge.com](https://project-management-knowledge.com/definitions/a/assumptions-log/?utm_source=chatgpt.com) | План OKR настроен на ноябрь 2025 — дату первых собеседований. | 2025-09-30 |

---

## Как работать с логом (очень просто)

1. Принимаешь **существенное решение** — сразу создаёшь запись `D-###`.  
2. Делаешь **крупное предположение** («хватит 6 месяцев») — записываешь `A-###`.  
3. В конце спринта просматриваешь записи со сроком ревью — подтвердить или откорректировать.  
4. Если решение устарело → помечаешь *Deprecated* и пишешь новое.  [oai_citation:13‡AWS Documentation](https://docs.aws.amazon.com/prescriptive-guidance/latest/architectural-decision-records/adr-process.html?utm_source=chatgpt.com)  

---

## Полезные шаблоны и чтение

* **ADR шаблон** — краткий Markdown-шаблон от GitHub ADR: <https://adr.github.io/>  [oai_citation:14‡Architectural Decision Records](https://adr.github.io/?utm_source=chatgpt.com)  
* **Confluence Decision Template (DACI)** — ролевая матрица Driver / Approver / Contributors / Informed.  [oai_citation:15‡Atlassian](https://www.atlassian.com/software/confluence/templates/decision?utm_source=chatgpt.com)  
* **AWS Prescriptive Guidance — ADR process** — жизненный цикл архитектурного решения.  [oai_citation:16‡AWS Documentation](https://docs.aws.amazon.com/prescriptive-guidance/latest/architectural-decision-records/adr-process.html?utm_source=chatgpt.com)  
* **Assumptions Log (PM-BOK)** — зачем фиксировать и пересматривать предположения.  [oai_citation:17‡project-management-knowledge.com](https://project-management-knowledge.com/definitions/a/assumptions-log/?utm_source=chatgpt.com)  
* **Benefit of decision logs** — как логи повышают прозрачность и обучение.  [oai_citation:18‡BestOutcome](https://bestoutcome.com/knowledge-centre/decision-log/?utm_source=chatgpt.com) [oai_citation:19‡govrn.com](https://govrn.com/blog/benefits-of-decision-logs-for-businesses?utm_source=chatgpt.com)