![[Risk Register.png]]

> **Просто и по-человечески:**  
> *Risk Register* — это **единый список рисков** по твоему Roadmap’у: что может пойти не так, насколько это вероятно/больно, кто отвечает и что мы делаем, чтобы этого не произошло. Это живой документ: его **дополняют и обновляют регулярно**, пока идёт проект.  [oai_citation:0‡Atlassian](https://www.atlassian.com/work-management/project-management/risk-register?utm_source=chatgpt.com) [oai_citation:1‡Project Management Academy](https://projectmanagementacademy.net/resources/blog/risk-report-vs-risk-register/?utm_source=chatgpt.com)

## Зачем он нужен
- Чтобы **увидеть проблемы заранее** и согласовать, **что делаем прямо сейчас** для снижения риска.  [oai_citation:2‡Atlassian](https://www.atlassian.com/work-management/project-management/risk-register?utm_source=chatgpt.com)  
- Чтобы не путать **риск** (может случиться в будущем) и **issue/проблему** (уже случилась). Для проблем — отдельный issue log; для будущих угроз — risk register.  [oai_citation:3‡Project Management Academy](https://projectmanagementacademy.net/resources/blog/risk-register-in-project-management/?utm_source=chatgpt.com) [oai_citation:4‡Project Management Institute](https://www.pmi.org/learning/library/project-risk-management-success-tool-6078?utm_source=chatgpt.com)  
- Чтобы держать цикл ISO 31000: **идентификация → анализ → оценка → обработка → мониторинг/пересмотр**.  [oai_citation:5‡ISO](https://www.iso.org/standard/65694.html?utm_source=chatgpt.com)

---

## Как пользоваться (очень коротко)
1) **Раз в неделю** открой таблицу, пробегись по рискам, обнови статусы и действия.  
2) На каждый риск есть **владелец** (ты/ментор/друг) и **следующий шаг** (mitigation).  
3) Если риск реализовался — переносим его в **issue log**, а в этом файле фиксируем уроки.  [oai_citation:6‡Project Management Academy](https://projectmanagementacademy.net/resources/blog/risk-report-vs-risk-register/?utm_source=chatgpt.com)

---

## Шаблон таблицы (скопируй в Obsidian)

| ID | Риск (что может случиться) | Триггер/симптом | Вероятность (1–5) | Влияние (1–5) | Итог (P×I) | Владелец | Mitigation (предотвратить) | Contingency (план Б) | Срок ревью | Статус |
|---|---|---|---:|---:|---:|---|---|---|---|---|
| R-001 |  |  |  |  |  |  |  |  |  |  |

> Поля «вероятность», «влияние», «владелец», «меры» — это базовые поля, которые рекомендуют использовать гайды по risk-register.  [oai_citation:7‡Project Management Institute](https://www.pmi.org/learning/library/project-risk-management-success-tool-6078?utm_source=chatgpt.com) [oai_citation:8‡Atlassian](https://www.atlassian.com/software/confluence/resources/guides/how-to/risk-register?utm_source=chatgpt.com)

---

## Готовые записи под твой кейс (можно вставлять сразу)

### Учёба/портфолио
| ID | Риск | Триггер | P | I | P×I | Владелец | Mitigation | Contingency | Ревью | Статус |
|---|---|---|---:|---:|---:|---|---|---|---|---|
| R-101 | **«Утонул в бесконечных курсах»** — потребление вместо создания | Неделя прошла без кода/репо-апдейтов | 4 | 4 | 16 | Станислав | Правило **«код > курс»**: 70/30 в пользу практики; каждый модуль заканчивается мини-проектом | Обрезать потребление до 30 мин/день, зафиксировать 1 микро-проект на выходные | Еженедельно (пн) | ☐ |
| R-102 | **Нет публичных артефактов** | Пустые pinned-репозитории/нет демо-видео | 3 | 5 | 15 | Станислав | Каждую пятницу — **release**: README + скрин/видео 3–7 мин | За один вечер собрать «release notes» по текущему прогрессу | Пт | ☐ |
| R-103 | **Нет фидбэка** (двигаюсь в пустоте) | 0 ревью PR / 0 комментариев в неделю | 3 | 4 | 12 | Станислав | Еженедельный **demo-day**: пост в Telegram/LinkedIn с демо и вопросами | Просить 1-на-1 ревью у двух знакомых; разместить на Reddit/DataTalks | Сб | ☐ |

### Техника/прод
| ID | Риск | Триггер | P | I | P×I | Владелец | Mitigation | Contingency | Ревью | Статус |
|---|---|---|---:|---:|---:|---|---|---|---|---|
| R-201 | **Локально работает, в облаке — нет** | Нет IaC/секреты в коде | 3 | 4 | 12 | Станислав | Мини-контур в облаке + секреты через env/manager; чек-лист деплоя | Срочный дебаг в dev-среде, отключить неключевые фичи | Каждые 2 недели | ☐ |
| R-202 | **Стек разросся (зверинец сервисов)** | >3 новых инструмента за месяц | 2 | 4 | 8 | Станислав | «Один инструмент на фазу» + justification в README | Делистим лишнее, заменяем на базовую реализацию | Мес. | ☐ |
| R-203 | **Перегорание/падение дисциплины** | <2 фокус-сессий/день 3 дня подряд | 3 | 5 | 15 | Станислав | 6×25 мин focus-блоки + дневной чек-ин, 1 выходной | 48 ч разгрузки, лёгкие таски + сон/спорт | Ежедневно | ☐ |

---

## Процедуры (вставь в рутину)

### Еженедельный demo-day (Telegram/LinkedIn)
1) 3–5 скринов или 1 видео до 3–7 минут (что сделал, выводы, что дальше).  
2) 1 конкретный вопрос к сообществу («проверьте SQL-запрос/схему/метрики»).  
3) Добавь ссылку на пост в **Evidence** по соответствующему риску/проекту.  
> Это создаёт **публичные артефакты** и регулярный **фидбэк-цикл**, снижая сразу два риска («нет артефактов», «нет обратной связи»).

### Правило «код > курс»
- Каждый модуль/урок заканчивается **мини-результатом** в репозитории (скрипт, DAG, dashboard).  
- Учёба без артефакта — **незачёт**. (Это формальная мера снижения риска «утонул в курсах».)

---

## Подсказки по оценке
- **Итоговый балл (P×I)**: 1–25. Наводи порядок начиная с «красных» (≥12).  
- **Срок ревью**: для «красных» — каждую неделю, для «жёлтых» — раз в 2 недели.  
- **Владелец** обязан зафиксировать **следующий шаг** до следующего ревью.  
> Такие практики соответствуют рекомендациям по ведению риск-реестра: фиксировать вероятность/влияние, назначать владельца и поддерживать документ обновлённым.  [oai_citation:9‡Project Management Institute](https://www.pmi.org/learning/library/project-risk-management-success-tool-6078?utm_source=chatgpt.com) [oai_citation:10‡Atlassian](https://www.atlassian.com/work-management/project-management/risk-register?utm_source=chatgpt.com)

---

## Справка (если хочешь копнуть глубже)
- **Risk Register** — инструмент проектного управления: список известных рисков с оценкой и планами реакций; ведётся и обновляется на протяжении проекта.  [oai_citation:11‡Atlassian](https://www.atlassian.com/work-management/project-management/risk-register?utm_source=chatgpt.com) [oai_citation:12‡Project Management Academy](https://projectmanagementacademy.net/resources/blog/risk-report-vs-risk-register/?utm_source=chatgpt.com)  
- **Не путать:** *risk register* ≠ *issue log* — первое про будущие события, второе про уже наступившие проблемы.  [oai_citation:13‡Project Management Academy](https://projectmanagementacademy.net/resources/blog/risk-register-in-project-management/?utm_source=chatgpt.com) [oai_citation:14‡Project Management Institute](https://www.pmi.org/learning/library/project-risk-management-success-tool-6078?utm_source=chatgpt.com)  
- **ISO 31000** — международный стандарт: принципы и процесс управления рисками (идентификация, анализ, оценка, обработка, мониторинг).  [oai_citation:15‡ISO](https://www.iso.org/standard/65694.html?utm_source=chatgpt.com)