
---


# Базовый стандарт (вставляй в начало любой заметки)

```yaml
---
title: "<Заголовок>"
aliases: []
note_type: "<lecture|concept|problem|project|cheatsheet|reading|journal|moc>"
topics: []               # ключевые темы: ["algorithms","sql","etl"]
tags: []                 # организационные теги: ["#concept","#cs50","#redo"]
status: "draft"          # draft|in-progress|review|done|archived
difficulty: "na"         # na|easy|medium|hard
priority: 3              # 1..5 (1 = fire)
effort_min: 25           # оценка усилия
time_spent_min: 0        # факт (обновляешь по мере работы)
created: "<% tp.date.now('YYYY-MM-DD') %>"
# updated: (лучше читать через dv: file.mtime)
source: []               # внешние ссылки (URL)
related: []              # [[связанные заметки]]
course: ""               # напр. "CS50x" (для lecture|reading)
module: ""               # произвольный модуль/глава
lecture_no:              # номер лекции (целое)
review_next: ""          # YYYY-MM-DD (для повторения)
owner: "stan"            # кто ведёт
---
```


Tags:

- #type/lecture — конспекты лекций/уроков
    
- #type/concept — атомарные понятия (твои «словарные» заметки)
    
- #type/reading — заметки по книгам/статьям/докам
    
- #type/snippet — сниппеты/рецепты кода
    
- #type/problem — “проблема-решение”, разбор задач/багов
    
- #type/cheatsheet — шпаргалки
    
- #type/project — проектные заметки/журналы
    
- #type/roadmap — планы/дорожные карты
    
- #type/daily — дневники/ежедневки
    
- #type/moc — оглавления/хабы (MOC)





Мини-политика ключей:

- `note_type` — единый «переключатель» для Dataview.
    
- Даты в ISO-формате. Обновление `updated` не храним, читаем `file.mtime`.
    
- `tags` — только контекст/статус (тип храним в `note_type`).
    
- `topics` — смысловые темы (для срезов и графа).
    

# Готовые мини-шаблоны

## Лекция

```yaml
---
title: "Lecture <N> — <тема>"
note_type: "lecture"
course: "CS50x"
module: "Week <W>"
lecture_no: <N>
topics: ["<topic1>","<topic2>"]
tags: ["#lecture","#study"]
status: "in-progress"
difficulty: "medium"
effort_min: 90
time_spent_min: 0
created: "<% tp.date.now('YYYY-MM-DD') %>"
source: ["<url>"]
related: ["[[Lecture <N-1> — ...]]"]
review_next: "<% tp.date.now('YYYY-MM-DD', 3) %>"
---
# Summary
# Key Points
# Examples
# Questions
# See also
```

## Концепт

```yaml
---
title: "<Термин / Концепт>"
aliases: ["<синонимы>"]
note_type: "concept"
topics: ["data-engineering","algorithms"]
tags: ["#concept"]
status: "in-progress"
difficulty: "medium"
created: "<% tp.date.now('YYYY-MM-DD') %>"
source: []
related: []
---
## TL;DR
## Definition
## Details
## Examples
## Use cases
## See also
```

## Проблема/Решение (bug, задача DSA, leetcode)

```yaml
---
title: "[Problem] <краткое имя>"
note_type: "problem"
topics: ["<algo|tool>"]
tags: ["#problem","#redo"]   # #redo = к повторению
status: "in-progress"
difficulty: "hard"
effort_min: 25
time_spent_min: 0
created: "<% tp.date.now('YYYY-MM-DD') %>"
source: ["<url на задачу/ошибку>"]
related: ["[[<связанный концепт>]]"]
review_next: "<% tp.date.now('YYYY-MM-DD', 7) %>"
---
**Statement.**

**Attempt(s).**  
1) …  
2) …

**Solution.**  
Сложность: `O(...)` по времени, `O(...)` по памяти.

**Why it works.**

**Pitfalls / Variants.**

**See also.**
```

## Проект (pet, учебный, рабочий)

```yaml
---
title: "[Project] <имя>"
note_type: "project"
topics: ["python","etl","docker"]
tags: ["#project"]
status: "in-progress"    # draft|in-progress|review|done|archived
priority: 2
effort_min: 240
time_spent_min: 0
created: "<% tp.date.now('YYYY-MM-DD') %>"
source: []
related: ["[[Roadmap — Data Engineering]]"]
---
## Goals / Definition of Done
## Stack
## Plan / Tasks
- [ ] …
## Notes / Decisions
## Changelog
- 2025-08-09: init
```

## Шпаргалка

```yaml
---
title: "Cheat Sheet — <тема>"
note_type: "cheatsheet"
topics: ["<тема>"]
tags: ["#cheatsheet"]
status: "done"
created: "<% tp.date.now('YYYY-MM-DD') %>"
---
## Commands
## Patterns
## Gotchas
```

## Конспект чтения (книга/статья)

```yaml
---
title: "Reading — <Название>"
note_type: "reading"
topics: ["<тема>"]
tags: ["#reading"]
status: "in-progress"
created: "<% tp.date.now('YYYY-MM-DD') %>"
source:
  - "<url>"
related: []
---
## Summary
## Key Takeaways
## Quotes
## See also
```

# Dataview быстрые срезы

Сводка по типам:

```dataview
TABLE file.link as Note, note_type, status, difficulty, effort_min, time_spent_min
FROM ""
WHERE note_type
SORT file.mtime desc
```

Лекции по CS50x:

```dataview
TABLE lecture_no, module, topics, status, review_next
FROM "" 
WHERE note_type = "lecture" AND course = "CS50x"
SORT lecture_no asc
```

К повторению (проблемы):

```dataview
LIST file.link
FROM "" 
WHERE note_type = "problem" AND contains(tags, "#redo")
```

# Почему так

- Один `note_type` упрощает все отчёты и графы.
    
- Плоские поля читаются Dataview без танцев.
    
- `time_spent_min` даёт дешёвую метрику прогресса.
    
- `review_next` — крючок под твой режим повторений.
    

Хочешь — допилю QuickAdd/Templater-макро “Новая лекция/концепт/проблема” и сделаю Dataview-дашборд “Учёба сегодня” с авто-фильтрами.