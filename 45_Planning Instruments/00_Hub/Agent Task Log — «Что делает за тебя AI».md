

> **TL;DR**: Agent Task Log — это одна заметка, где ты каждый день фиксируешь, **какие задачи выполнил за тебя ИИ-агент** (например, Siri Shortcuts + ChatGPT) и **какой получился результат**. Такой журнал помогает видеть реальную выгоду от автоматизаций, быстро чинить ошибки и не забывать хвастаться готовыми артефактами.

---

## 1. Зачем это вести

| Причина | Что это даёт |
|---------|--------------|
| **Прозрачность** | Одним взглядом видно, где ИИ экономит время ― от включения фокуса до автозаполнения отчётов. :contentReference[oaicite:0]{index=0} |
| **Отладка** | Когда что-то ломается, лог показывает шаги агента и ошибки. :contentReference[oaicite:1]{index=1} |
| **ROI** | Сравниваешь время «до/после» и понимаешь, какие шорткаты реально окупаются. :contentReference[oaicite:2]{index=2} |
| **Портфолио** | Журнал = готовое доказательство навыков автоматизации для резюме. :contentReference[oaicite:3]{index=3} |

---

## 2. Как это работает (на пальцах)

1. **Apple Shortcuts** запускают цепочку действий — от включения Focus-режима до записи коммита в Git через API. :contentReference[oaicite:4]{index=4}  
2. В конце шорткат вызывает «Log to Obsidian» (draft → DataJar → Append to File) и пишет строку вида  
   `2025-08-10 | 08:45 | Focus ON + Timer 25m | OK`.  
3. Раз в день/неделю ты открываешь файл `Agent_Task_Log.md`, чтобы:  
   * проверить, что всё выполняется без ошибок;  
   * отметить, сколько «рутинных» минут сэкономлено;  
   * добавить ссылку на артефакт (скрин, файл, PR). :contentReference[oaicite:5]{index=5}  
4. Если что-то упало — смотришь **agent execution log** в Shortcuts (или в App Log, если зовёшь API) и чинишь. :contentReference[oaicite:6]{index=6}

---

## 3. Пример ежедневных итераций

| Время | Шорткат | Что делает | Сэкономлено |
|-------|---------|-----------|-------------|
| 08:00 | **Morning Focus** | Включает Focus-режим «Coding», ставит таймер 25 мин, открывает VS Code. | 3 мин |
| 10:30 | **Stand-up Note** | Создаёт новую заметку «Daily-log», вставляет шаблон вопросов. | 5 мин |
| 15:00 | **Commit + Push** | Добавляет дату в commit-msg, пушит в Git и пишет log-строку. | 2 мин |
| 18:00 | **Shutdown Routine** | Архивирует папку /Work → iCloud, выключает Wi-Fi, ставит заряд. | 4 мин |

> **Итого**: ~14 мин рутины сняты в день, + чёткий журнал действий.

---

## 4. Шаблон Obsidian-файла

```markdown
# 🗂️ Agent Task Log

| Дата | Время | Шорткат / Агент | Действие | Результат | ⏱️ Экономия |
|------|-------|-----------------|----------|-----------|-------------|
| 2025-08-10 | 08:00 | Morning Focus | Focus ON, VS Code, таймер 25 мин | ✅ | 3 мин |
| 2025-08-10 | 10:30 | Stand-up Note | Создана note Daily-log | ✅ | 5 мин |
| … | … | … | … | … | … |

## 📊 Еженедельная сводка
- **Итого сэкономлено**: 1 ч 45 мин
- **Ошибки**: 1 (Commit shortcut упал — пофиксил токен).
- **Идеи для новых шорткатов**: Auto-apply LinkedIn, Pull RSS → Text-to-Speech
````


---

## 5. Лайфхаки «для чайника»

1. **Start simple**: автоматизируй одну рутинку (включить Focus+Таймер) и логируй её.
    
2. **GIF-демо**: запиши 5-секунду экранку и положи рядом с записью — рекрутёр увидит работу вживую. ([Apple Support](https://support.apple.com/guide/iphone/shortcuts-iph47e1c9d7d/ios?utm_source=chatgpt.com "Use Shortcuts to automate tasks on iPhone"), [Reddit](https://www.reddit.com/r/shortcuts/comments/rmbxqq/log_hours_at_work_in_a_note/?utm_source=chatgpt.com "Log hours at work in a note? : r/shortcuts"))
    
3. **1 шорткат = 1 строка лога** — так легче читать и считать экономию.
    
4. **Всё в одном месте**: держи лог в `Logs/` внутри Obsidian для быстрых ссылок в Evidence Vault.
    
5. **Публичная версия**: если готов показать миру — пушни файл в GitHub Pages как `Task-Log.md`. ([Reddit](https://www.reddit.com/r/shortcuts/comments/1e0wpnq/focus_mode_schedule_after_using/?utm_source=chatgpt.com "Focus mode schedule after using shortcuts/automations."))
    

---

## Полезные ссылки

- Apple Support: _Use Shortcuts to automate tasks on iPhone_ — базовый туториал. ([Apple Support](https://support.apple.com/guide/iphone/shortcuts-iph47e1c9d7d/ios?utm_source=chatgpt.com "Use Shortcuts to automate tasks on iPhone"))
    
- Tom’s Guide: обзор AI-фич iOS 26 (Shortcuts × ChatGPT). ([Tom's Guide](https://www.tomsguide.com/phones/iphones/ive-been-testing-the-ios-26-public-beta-what-i-like-and-what-i-dont-about-the-apple-intelligence-additions?utm_source=chatgpt.com "I've been testing the iOS 26 public beta - what I like and what I don't about the Apple Intelligence additions"))
    
- Reddit /r/shortcuts — идеи автоматизаций и лог-хаки. ([Reddit](https://www.reddit.com/r/iphone/comments/152x6e9/i_was_just_wondering_what_shortcuts_or_automation/?utm_source=chatgpt.com "I was just wondering what shortcuts or automation y'all use ..."))
    
- Adopt.ai: _Agent execution logs_ — зачем логировать шаги ИИ-агента. ([adopt.ai](https://www.adopt.ai/glossary/agent-execution-logs?utm_source=chatgpt.com "Agent Execution Logs: The Complete Guide to Monitoring ..."))
    
- Kore.ai docs: _Task Execution Logs_ — пример дашборда для ботов. ([Kore.ai Documentation](https://docs.kore.ai/xo/analytics/automation/task-execution-logs/?utm_source=chatgpt.com "Task Execution Logs"))
    
- Coralogix: _Benefits of logging agents_ — про агрегацию логов. ([Coralogix](https://coralogix.com/blog/benefits-logging-agents/?utm_source=chatgpt.com "What Is a Log Agent and Why It Matters, Plus Examples"))
    

```

::contentReference[oaicite:15]{index=15}
```


