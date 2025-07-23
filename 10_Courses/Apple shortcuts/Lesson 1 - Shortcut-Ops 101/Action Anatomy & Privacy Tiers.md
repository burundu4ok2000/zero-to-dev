
---

## 🎯 Goal  
Понять, какие действия Shortcuts трогают сеть/приложения/устройство, и как управлять их приватностью.

---

## 🧱 Action Anatomy & Privacy Tiers

| Layer           | Example                    | Data Exposure     | Best Practice                                   |
|-----------------|----------------------------|-------------------|-------------------------------------------------|
| ✅ **On-device** | `Get Latest Screenshots`    | Local only        | Самый безопасный. Используй по умолчанию.       |
| ⚠️ **App-mediated** | `Send Message` / `Add to Notes` | Data → конкретное приложение | Предупреди пользователя, покажи alert.          |
| 🚨 **Network**  | `Get Contents of URL`       | Internet-bound    | Подтверждение пользователя, VPN/HTTPS, логгинг. |

---

## 🧪 Demo (3–4 мин)
1. В редакторе добавь `Get Current Weather` — увидишь **жёлтый ярлык** (локейшн → app-mediated).  
2. Открой **Settings (⚙) → Privacy** у шортката:  
   - Потогли permission’ы (Location, Photos, Network).  
   - Покажи, как включить “Ask Each Time”.

> 💡 *Coach Tip:* Спроси: «Какие действия в твоём последнем шорткате уходят в сеть?»

---

## ⚡ Quick Practice (5–6 мин)

### 1. Классификация (1 мин)  
Разложи по слоям (просто подпиши On-device / App / Network):
- `Get Battery Level`  
- `Show Notification`  
- `Post to Mastodon` (через API)  
- `Save File to iCloud Drive`  
- `Open App`  
- `Get Contents of URL (POST JSON)`  
- `Speak Text`  
- `Run JavaScript on Web Page`

### 2. Микро-шорткат «Privacy Ping» (3 мин)
**Задача:** показать пользователю, какие его данные пойдут наружу.  
Шаги:
1. `Ask for Input` → “Что ты хочешь сделать?”  
2. `Choose from Menu` (3 пункта):  
   - “Работаем только локально” → действия типа `Get Clipboard`, `Format Date`  
   - “Через приложение” → `Add to Notes`, `Create Reminder`  
   - “Через интернет” → `Get Contents of URL` (запрос на public API)  
3. Перед каждым блоком вставь `Show Alert`: “⚠️ Этот шаг передаст данные X → Y”.  
4. В конце `Show Result`: “Готово. Проверь Privacy в Settings → Privacy”.

### 3. Вопросы для закрепления (1 мин)
- Какие два действия сегодня были *network-bound*?  
- Где в Shortcut Settings прячется список требуемых разрешений?  
- Что будет, если отключить Location, а в шорткате есть `Get Current Weather`?

---

## 📝 Самопроверка
- [ ] Я отличаю on-device от network actions на глаз  
- [ ] Я знаю, как включить “Ask Each Time” в Privacy  
- [ ] Я могу предупредить пользователя об отправке данных наружу

---

**Next →** *Magic Variables 101 & Hands-On Lab A.*