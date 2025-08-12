# Evidence Vault — «страница-индекс» для рекрутёра за 30 секунд

> **По-простому:** это **одна главная заметка** в Obsidian, где в три клика видно ваши лучшие проекты, демо-GIF, ноутбуки, pull-request’ы, резюме и контакты.  
> Рекрутёр открывает ссылку и за пол-минуты понимает, что вы умеете — без долгих скроллов и скрытых папок.  
> Такой «30-second portfolio» — частый совет HR-ов и hiring-менеджеров.  [oai_citation:0‡Medium](https://medium.com/%40biswajitpanda91/behind-the-portfolio-curtains-first-30-seconds-can-make-or-break-your-ux-career-43b541277bcd?utm_source=chatgpt.com) [oai_citation:1‡Reddit](https://www.reddit.com/r/jobs/comments/7y8k6p/im_an_exrecruiter_for_some_of_the_top_companies/?utm_source=chatgpt.com)

---

## Зачем нужен Evidence Vault

1. **Экономит время читателя.** У HR-ов 30–60 сек на первичный скрин портфолио.  [oai_citation:2‡Medium](https://medium.com/%40biswajitpanda91/behind-the-portfolio-curtains-first-30-seconds-can-make-or-break-your-ux-career-43b541277bcd?utm_source=chatgpt.com)  
2. **Публичные артефакты** (GIF-демо, README с инструкцией) лучше сухого списка навыков.  [oai_citation:3‡DEV Community](https://dev.to/kelli/demo-your-app-in-your-github-readme-with-an-animated-gif-2o3c?utm_source=chatgpt.com) [oai_citation:4‡Medium](https://medium.com/%40yukiyao/demo-projects-with-animated-gifs-719f77d657dd?utm_source=chatgpt.com)  
3. **Ссылки на код** ценятся выше абстрактных заявлений в резюме.  [oai_citation:5‡Index](https://www.index.dev/blog/tech-resume-red-flags-developer-jobs?utm_source=chatgpt.com) [oai_citation:6‡Reddit](https://www.reddit.com/r/animationcareer/comments/ty8fp7/some_3d_animation_demoreel_tips_from_a_recruiting/?utm_source=chatgpt.com)  
4. **Markdown-индекс** легко поддерживать и хранить прямо в Obsidian; внутренняя вики-связь ускоряет навигацию.  [oai_citation:7‡Reddit](https://www.reddit.com/r/ObsidianMD/comments/1ae2eot/generate_index_page_for_a_folder_into_markdown/?utm_source=chatgpt.com) [oai_citation:8‡Obsidian Help](https://help.obsidian.md/syntax?utm_source=chatgpt.com)  
5. GIF-ы работают во всех браузерах и GitHub README.  [oai_citation:9‡GitHub](https://github.com/matiassingers/awesome-readme?utm_source=chatgpt.com)

---

## Мини-структура страницы-индекса

| Блок | Что внутри | Почему это здесь |
|------|------------|------------------|
| **🚀 Top 3 Projects** | Название · короткий one-liner · GIF (5-10 с) · ссылки: repo / demo | Приём «show, don’t tell» для быстрого впечатления.  [oai_citation:10‡DEV Community](https://dev.to/kelli/demo-your-app-in-your-github-readme-with-an-animated-gif-2o3c?utm_source=chatgpt.com) |
| **📂 Key Notebooks** | Jupyter / Colab с EDA, ML или SQL-разбором +скрин превью | Демонстрация аналитических/DE-скилов на реальных данных. |
| **🔗 Pull Requests** | 2–3 ссылки на PR, где был код-ревью | Показывает умение работать по Git-процессу. |
| **📄 Resume & Cases** | PDF-резюме, one-pager «Data Case», публичные статьи | Даёт HR быстрый документ и «чит-лист» успехов. |
| **🗂️ Other Links** | LinkedIn, Telegram demo-day, блог | Контакт и социальное подтверждение. |

---

## Шаблон Obsidian-страницы

```markdown
# 📌 Evidence Vault

## 🚀 Top Projects
1. **ETL Pipeline — GCP → BigQuery**  
   ![[etl-demo.gif]]  
   *One-liner*: Python + Airflow, инкрементальный загрузчик 5 млн строк/день.  
   • [GitHub](https://github.com/you/etl-airflow) • [Demo video](https://youtu.be/xxx)
2. **dbt + GX Quality Layer**  
   ![[dbt-demo.gif]]  
   • [Repo](https://github.com/you/dbt-gx) • [PR Review](https://github.com/you/dbt-gx/pull/12)

## 🗒️ Key Notebooks
- [[notebooks/ecommerce_eda.ipynb|E-commerce EDA]] — выводы о LTV  
- [[notebooks/sql_tuning_bigquery.ipynb|SQL tuning]]

## 🔗 Pull Requests
- Airflow DAG refactor → [#24](https://github.com/you/etl-airflow/pull/24)
- Spark Structured Streaming checkpoint fix → [#11](https://github.com/you/streaming/pull/11)

## 📄 Resume & Cases
- [[resume.pdf]]  
- [[case_study_data_quality.md]]

## 🗂️ Contacts
[LinkedIn](https://linkedin.com/in/you) • [Telegram](https://t.me/you) • [Blog](https://medium.com/@you)
```

