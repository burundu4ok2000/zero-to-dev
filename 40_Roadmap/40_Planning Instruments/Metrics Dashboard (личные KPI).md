![[Metrics Dashboard.png]]

> **Коротко:** «личные KPI-метрики» — это небольшой набор чисел, которые объективно показывают, как движутся ваши навыки и проекты из недели в неделю. Главное правило: **метрика должна приводить к действию**. Если число растёт / падает, вы сразу понимаете, что делать (праздновать или менять план). Ниже — простое объяснение ключевых потоковых метрик и готовый шаблон для Obsidian.

---

## 1. Зачем это нужно

* **Видимость прогресса** — цифры не врут и хорошо мотивируют  [oai_citation:0‡Teramind -](https://www.teramind.co/blog/employee-productivity-metrics/?utm_source=chatgpt.com).  
* **Раннее обнаружение «провалов»** — если график «фокус-часов» падает две недели подряд, пора чинить рутину  [oai_citation:1‡AIHR](https://www.aihr.com/blog/productivity-metrics/?utm_source=chatgpt.com).  
* **Привязка к OKR / Roadmap** — метрики делают ваши цели измеримыми  [oai_citation:2‡Adobe Business](https://business.adobe.com/blog/basics/velocity?utm_source=chatgpt.com).

---

## 2. Ключевые потоковые метрики (простыми словами)

| Метрика | Что измеряет | Почему важна | Как считать |
|---------|--------------|--------------|-------------|
| **Чистые фокус-часы / неделя** | Сколько действительно сконцентрированного времени вы потратили на код/учёбу, без отвлечений | Прямая связь с глубокой работой  [oai_citation:3‡The Times](https://www.thetimes.co.uk/article/the-key-to-productivity-stop-measuring-work-by-time-v20m6lfrn?utm_source=chatgpt.com) | Таймер Pomodoro + листинг сессий в Obsidian / Toggl |
| **Issue-velocity** | Сколько задач закрыто за неделю в GitHub / Trello | Показывает скорость вывода работы «в готово»  [oai_citation:4‡Adobe Business](https://business.adobe.com/blog/basics/velocity?utm_source=chatgpt.com) | Кол-во закрытых issue с лейблом `weekly` |
| **Repo-commits** | Количество коммитов в основных репо | Видимый прогресс кода и публичный «след»  [oai_citation:5‡Databox](https://databox.com/metric-library/metrics/github/commits?utm_source=chatgpt.com) | `git shortlog --since="1 week ago" -s` |
| **Applies → Screens → Interviews** | Воронка поиска работы: подано / скринингов / интервью | Даёт реальный % конверсии и пункт, который «течёт»  [oai_citation:6‡BarRaiser](https://www.barraiser.com/blogs/troubleshooting-hiring-funnel-boost-your-conversion-rates-effectively?utm_source=chatgpt.com) | Таблица откликов в Notion/Sheet |
| **% попадания в недельный план** | Сколько запланированных задач действительно выполнено | Объективный индикатор реалистичности планирования  [oai_citation:7‡scw.ai](https://scw.ai/blog/schedule-adherence/?utm_source=chatgpt.com) | (Выполнено ÷ Запланировано) × 100 |

---

## 3. Как настроить (лайт-шаги)

1. **Соберите данные автоматически**  
   * Focus — таймеры (Apple Shortcuts ➜ DataJar, Toggl API).  
   * Git — `git log` или GitHub GraphQL (commits / issue events).  
   * Job-воронка — Google Sheet с формулой конверсии.  
   * План-факт — чекбоксы недельного плана (Obsidian Dataview).  
2. **Раз в неделю** (например, в воскресенье вечером):  
   * Экспортируйте числа → вставьте в Dataview-таблицу / CSV.  
   * Посмотрите тренд: растёт / падает / стоит на месте.  
   * Запишите **одно действие** на следующую неделю (mitigation или «утвердить успех»).  
3. **Раз в месяц** — пересмотрите набор метрик: не даёт действия → выбросить.

---

## 4. Шаблон Dataview-таблицы (Obsidian)

```dataview
table
  week as "Неделя",
  focus_hours as "Фокус-часы",
  issue_velocity as "Issue-velocity",
  commits as "Коммиты",
  applies as "Applies",
  screens as "Screens",
  interviews as "Interviews",
  round((done/plan)*100,0) as "% план"
from "Metrics"
sort week desc
```

---

## 5. Мини-пример записи за неделю

```markdown
## 2025-W32  (4–10 авг)

| Метрика | Значение |
|---------|----------|
| Фокус-часы | **24 ч** |
| Issue-velocity | **6** закрыто |
| Repo-commits | **15** |
| Воронка | 25 → 8 → 2 |
| % попадания в план | 83 % |

**Итого:** фокус-часы выросли (вернулся режим утренних сессий); уход в код уменьшил количество откликов — добавить минимум 35 откликов на следующей неделе.
```

---

## **6. Частые вопросы**

- **Сколько метрик держать?** 3–5, иначе утонете в отчётности  .
    
- **Нормы?** Нет универсальных чисел: смотрим динамику («лучше, чем на прошлой неделе»).
    
- **А если коммитов мало, но код «толстый»?** Смотрите связку коммиты + Issue-velocity: один «толстый» PR обычно закрывает несколько задач.
    

---

### Полезные ссылки

- «17 Productivity Metrics» — хорошие примеры для вдохновения ([AIHR](https://www.aihr.com/blog/productivity-metrics/?utm_source=chatgpt.com "17 Productivity Metrics Examples for Working Effectively"))
    
- Agile Velocity — понятие и формула ([Adobe Business](https://business.adobe.com/blog/basics/velocity?utm_source=chatgpt.com "What is Velocity in Agile? Formula & Examples"))
    
- Μεtric «Commits» в GitHub dashboards ([Databox](https://databox.com/metric-library/metrics/github/commits?utm_source=chatgpt.com "GitHub Commits - Metric Definition"))
    
- Конверсия hiring funnel ([BarRaiser](https://www.barraiser.com/blogs/troubleshooting-hiring-funnel-boost-your-conversion-rates-effectively?utm_source=chatgpt.com "Troubleshooting Hiring Funnel: Boost Your Conversion ..."))
    
- Schedule adherence как метрика выполнения плана ([scw.ai](https://scw.ai/blog/schedule-adherence/?utm_source=chatgpt.com "A Complete Guide to Schedule Adherence for Manufacturers"))
    
- Scrum.org — velocity разъяснения ([Scrum.org](https://www.scrum.org/resources/blog/agile-metrics-velocity?utm_source=chatgpt.com "Agile Metrics: Velocity"))
    
- GitHub personal dashboard docs ([GitHub Docs](https://docs.github.com/account-and-profile/setting-up-and-managing-your-github-user-account/managing-user-account-settings/about-your-personal-dashboard?utm_source=chatgpt.com "About your personal dashboard"))
    
- Reddit обсуждение конверсии откликов ([Reddit](https://www.reddit.com/r/cscareerquestions/comments/vgosqd/a_question_for_recruiters_what_is_your_conversion/?utm_source=chatgpt.com "A question for recruiters - What is your conversion rate or ..."))
    
- Assembled: что такое schedule adherence ([assembled.com](https://www.assembled.com/university/what-is-schedule-adherence?utm_source=chatgpt.com "What is Schedule Adherence?"))
    
