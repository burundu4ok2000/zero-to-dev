
---

📚 **Gallery — discovery & one-tap installs**

| Gesture | What happens | Pro tip |
|---------|--------------|---------|
| Swipe ↑ / ↓ | Scroll curated templates and categories (Essentials, AI, Media, ⟲ Automation) | Check **Starter Shortcuts** at the top — каждый показывает ключевой API-приём |
| Tap a card → **Add Shortcut** | Создаёт *read-only* копию в Library | Gallery-копии — это “замороженные” шаблоны; чтобы изменить, сразу **Duplicate** |
| Long-press на карте | Просмотр описания, privacy-labels, списка actions | Отличный повод обсудить **Privacy tiers** до импорта |

---

📁 **Shortcuts Library — твоя полка проектов**

* Grid ⇆ List toggle (⋯ меню) — Grid = визуально, List = плотный список  
* **Drag & Drop** — меняй порядок или кидай в папки (*Work*, *Home*, *Play*)  
* Long-press карточки → быстрые действия:  
  * **Rename** (💡 префиксируй эмодзи для Spotlight: `☕ Brew Timer`)  
  * **Duplicate** — безопасная песочница для экспериментов  
  * **Share** — .shortcut файл или iCloud-ссылка  
  * **Details** — icon, color, privacy, Type & Recipient, Siri-фраза  

> **Coach-паттерн:** попроси ученика переключиться в List-view, отсортировать *by Date* и найти сегодняшние практические шорткаты — быстрый ориентир.

---

✍️ **Editor Pane — здесь происходит магия**

### 🔍 Action Drawer (⌄ pull-up)
* **Search** — fuzzy-poisk + синонимы (“photo” → *Get Latest Photo*)  
* **Categories** — Media · Scripting · Files · AI … отражают iOS-фреймворки  
* **Third-party Actions** — показываются под своим app-названием (*Actions*, *Drafts*, *Things 3*)

### ▶️ Run Sheet (live log)
* Выводит каждый шаг + результат по хронологии  
* Тапни строку — смотри превью или скрытые **Magic Variables**  
* Swipe ← строка → **Clear** для шумных выводов при отладке

### 🛠 Top Toolbar
| Icon | Function                                                             |
| ---- | -------------------------------------------------------------------- |
| ⚙    | Settings (Name, Icon, Privacy, Add to Home Screen, Type & Recipient) |
| ▶    | Одноразовый Run — удобно до триггеров                                |
| 🔗   | Share: .shortcut file или iCloud-link                                |
| ❌    | Auto-save; возврат в Library                                         |

> 💡 **Coach Tip:**  
> 1) “Найдите синюю **Magic Variable** pill для Action #1.”  
> 2) “Вставьте её в Action #2 без manual variable.”  
> Так закрепляется визуальное понимание data-flow.

---

🏃🏻‍♂️ **Mini-Exercise (≈3 min)**  
1. Gallery → **Take Break**.  
2. Сразу **Duplicate** (учимся клонировать).  
3. В копии: в Action Drawer добавь **Speak Text** после *Get Quote* → выбери Magic Variable.  
4. ▶ Run — смотри Run Sheet + слушай Siri.  
5. Close → long-press card → **Details** → поменяй цвет иконки.

---

📎 **Key take-aways**
- **Gallery = templates**, **Library = codebase**, **Editor = IDE**  
- **Run Sheet** — твой console.log()  
- **Magic Variables** — голубые таблетки, избавляющие от лишних переменных

*Next stop → Action Anatomy & Privacy Tiers.*