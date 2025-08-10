

---
title: "{{Atom Title}}"  
lang_tags: ""                                      # (#lang/...)
type_tags: ""                                      # (#type/...)
course_tags: ""                                    # (#course/...)
lecture_tags: ""                                   # (#lecture/...)
tool: 
atom_idx: 01                                       # порядковый номер внутри лекции (для сортировки)         
status: ""                                         # draft | in-progress | review | done
difficulty: ""                                     # na|easy|medium|hard
date: "{{date:YYYY-MM-DD}}"                        # дата создания
timecode: ""                                       # таймкод заметки внутри лекции
source: "{{Lecture URL}}"                          # ссылка на источник в интернете
review_next: ""                                    # YYYY-MM-DD для повторения 
---

```
---
title: "{{Cheat Sheet Topic}}"
aliases: ["{{Cheat Sheet Topic}}"]
note_type: "cheatsheet"
topics: ["{{Topic}}"]                  # например: ["Git"], ["SQL"], ["Regex"]
tags: ["cheatsheet","reference","{{Topic}}"]
lang: "{{Language}}"                   # например: "bash" | "sql" | "python" | "general"
tool: "{{Tool}}"                       # например: "git" | "vim" | "docker" | ""
status: "draft"                        # draft | active | deprecated
difficulty: ""                         # na | easy | medium | hard
created: "{{date:YYYY-MM-DD}}"
source: []                             # ["https://…", "[[Внутренняя заметка]]"]
related: []                            # [["[[Связанный концепт]]", "[[Проект]]"]]
review_next: ""                        # YYYY-MM-DD — дата следующего ревью (если нужно)
---
```

## **One-liner

> (short definition or description in 1-2 sentence). 

## Common Commands / Syntax
%% Таблица *задача → команда → заметки*.  
   Редактировать удобно через плагин Advanced Tables. %%
| **Task**                 | **Command / Code**     | **Notes**                  |
|-------------------------|------------------------|----------------------------|
| …                       | `…`                    | …                          |
| …                       | `…`                    | …                          |

## Frequently Used Patterns
%% Типовые заготовки/паттерны кода/запросов. %%
- **Pattern A:** `…` — когда использовать: …
- **Pattern B:** `…` — нюансы: …

## Shortcuts
%% Горячие клавиши или команды, ускоряющие работу. %%
- **⌘K ⌘S** — открыть «Keyboard Shortcuts» (VS Code)
- **:wq** — save & quit (vim)

## Tips & Gotchas
%% Советы, подводные камни, лимиты. %%
- Tip: …
- Gotcha: …

## Examples
%% 1–3 минимальных примера использования. %%
```{{Language}}
# пример 1
````

```
# пример 2
```

## **See Also**

  

%% Быстрые ссылки на доку и твои заметки по теме. %%

- Official docs: {{Topic}}
    
- [[Подробная заметка / концепт]]
    
- [[Проект, где это использовано]]
    

  

## **Changelog**

  

%% Записывай изменения шпаргалки по мере обновлений. %%

- {{date:YYYY-MM-DD}}: initial
    

```
Если хочешь, я могу ещё сделать вариант этого шаблона, чтобы он автоматически подставлял `{{date}}`, `{{Topic}}` и прочее через **Templater** — тогда ты сможешь создавать такие шпаргалки буквально в один клик.  
```