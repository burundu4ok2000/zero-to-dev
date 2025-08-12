![[kanban board.png]]
# Kanban board / Спринт-доска — простое объяснение

> **В двух словах**: это доска-визуализация, где каждая карточка = задача, а колонки показывают, на каком этапе она сейчас. Двигаем карточку слева направо, пока не дойдём до **Done**. Такой процесс помогает видеть «заторы», не забывать про ревью и показывать результат.

---

## Зачем нужны колонки

| Колонка | Что означает | Почему полезна |
|---------|--------------|----------------|
| **Backlog** | Просто список «всего, что хотелось бы сделать». | Не теряем идеи и можем приоритизировать позже. |
| **Planned (неделя)** | 5-10 задач, которые **реально** берём на эту неделю. | Сужаем фокус, чтобы не растащить внимание. :contentReference[oaicite:0]{index=0} |
| **Doing** | Максимум 2-3 задачи на человека одновременно — это Work-in-Progress (WIP). | Ограничиваем многозадачность и ускоряем поток работы. :contentReference[oaicite:1]{index=1} |
| **Review** | Задача закончена разработчиком, но ждёт чужое ревью (код, текст, дизайн). | Гарантирует качество и делится знанием внутри команды. |
| **Demo** | Готова к показу внешнему миру (Telegram, LinkedIn, преподавателю). | Быстрый фидбэк и публичный «след» уменьшают риск «работаю в пустоту». :contentReference[oaicite:2]{index=2} |
| **Done** | Все критерии приёмки пройдены, артефакты размещены (репо/видео). | Карточка уходит из потока — мы видим реальный прогресс. |

> **Критерии приёмки** — это мини-чек-лист «как понять, что задача действительно готова» (например: тесты зелёные, README обновлён, ссылка на демо). :contentReference[oaicite:3]{index=3}

---

## Как работает процесс (пошагово)

1. **Наполняем Backlog** — всё, что приходит в голову, летит сюда.  
2. **Раз в неделю** выбираем топ-приоритет (колонка *Planned*). :contentReference[oaicite:4]{index=4}  
3. Берём задачу → кидаем в **Doing** (не больше WIP-лимита). :contentReference[oaicite:5]{index=5}  
4. Закончил кодить? → **Review** (пинг ревьюера).  
5. Всё ок? → **Demo** (показываем в соцсетях/команде). :contentReference[oaicite:6]{index=6}  
6. Условия DoD выполнены → **Done**.  
7. **Пустим кровь**: если *Doing* застопорилось — ищем причину; если *Review* копится — все помогают ревьюить. :contentReference[oaicite:7]{index=7}  

---

## Шаблон карточки задачи для Obsidian

```markdown
### <Короткое название задачи>
- **Описание**: ...
- **Критерии приёмки**  
  - [ ] ...
  - [ ] ...
- **Ссылка на артефакт**: <URL на репо / демо-видео>
- **Примечания / блокеры**: ...
````

### <Короткое название задачи>
- **Описание**: ...
- **Критерии приёмки**  
  - [ ] ...
  - [ ] ...
- **Ссылка на артефакт**: <URL на репо / демо-видео>
- **Примечания / блокеры**: ...
---

## Зачем ещё помнить о WIP-лимитах

- Меньше «висящего» кода → быстрее отзыв QA/ревью. ([Atlassian](https://www.atlassian.com/agile/kanban/wip-limits?utm_source=chatgpt.com "Working with WIP limits for kanban"))
    
- Блокеры сразу видны по переполненной колонке. ([Wikipedia](https://en.wikipedia.org/wiki/Kanban_board?utm_source=chatgpt.com "Kanban board - WikipediaWhat is the Difference Between a Sprint Backlog and a ..."))
    
- Команда концентрируется на завершении, а не «начал — бросил». ([businessmap.io](https://businessmap.io/kanban-resources/getting-started/what-is-wip?utm_source=chatgpt.com "The Ultimate Guide to WIP Limits in Kanban"))
    

---

## Полезные источники для углубления

1. Канбан-доска (Wikipedia) — базовые колонки и примеры. ([Wikipedia](https://en.wikipedia.org/wiki/Kanban_board?utm_source=chatgpt.com "Kanban board - WikipediaWhat is the Difference Between a Sprint Backlog and a ..."))
    
2. Atlassian: _Product vs Sprint Backlog_ — почему нужна отдельная колонка «Planned». ([Atlassian](https://www.atlassian.com/agile/project-management/sprint-backlog-product-backlog?utm_source=chatgpt.com "Product Backlog vs. Sprint Backlog: Key Differences"))
    
3. Atlassian: _Acceptance Criteria Explained_ — что такое AC и зачем чек-лист. ([Atlassian](https://www.atlassian.com/work-management/project-management/acceptance-criteria?utm_source=chatgpt.com "Acceptance Criteria Explained [+ Examples & Tips]"))
    
4. Scrum Alliance: _Need to Know about AC_ — примеры хороших критериев. ([resources.scrumalliance.org](https://resources.scrumalliance.org/Article/need-know-acceptance-criteria?utm_source=chatgpt.com "Everything You Need to Know About Acceptance Criteria"))
    
5. Atlassian: _WIP Limits_ — зачем ограничивать Doing. ([Atlassian](https://www.atlassian.com/agile/kanban/wip-limits?utm_source=chatgpt.com "Working with WIP limits for kanban"))
    
6. Businessmap: _Ultimate Guide to WIP Limits_ — подробнее о практике. ([businessmap.io](https://businessmap.io/kanban-resources/getting-started/what-is-wip?utm_source=chatgpt.com "The Ultimate Guide to WIP Limits in Kanban"))
    
7. Atlassian: _Sprint Demo Guide_ — как проводить демо. ([Atlassian](https://www.atlassian.com/agile/project-management/sprint-demo?utm_source=chatgpt.com "Sprint Demo: What it is & How to Conduct One"))
    
8. Kanban board примеры по сферам — вдохновение для собственных колоночек. ([businessmap.io](https://businessmap.io/kanban-resources/kanban-software/kanban-board-examples?utm_source=chatgpt.com "26 Practical Kanban Board Examples"))
    
9. Reddit обсуждение Backlog vs Sprint — живой опыт команд. ([Reddit](https://www.reddit.com/r/jira/comments/v3eje8/kanban_backlog_vs_sprint_backlog_question/?utm_source=chatgpt.com "Kanban backlog vs sprint backlog question : r/jira"))
    
10. PMI определение канбана как «visualization tool». ([Wikipedia](https://en.wikipedia.org/wiki/Kanban_board?utm_source=chatgpt.com "Kanban board - WikipediaWhat is the Difference Between a Sprint Backlog and a ..."))
    