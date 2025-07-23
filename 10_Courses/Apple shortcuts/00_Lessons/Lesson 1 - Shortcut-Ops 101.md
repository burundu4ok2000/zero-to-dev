[[Apple shortcuts]]

## 🎯 Goal
In **60–75 minutes** the learner will:

- Open the Shortcuts app
- Identify all major UI panes
- Build a **two-step** workflow
- Understand and use a **Magic Variable**
- Share **two shortcuts** to the Home Screen  
- Without bricking their iPhone 16 Pro Max 😄

---

## ⏱ 0. Prep (5 min)

| What                     | How                                                                 |
|--------------------------|----------------------------------------------------------------------|
| ✅ Update system & app    | Settings → General → **Software Update** (iOS 19+)<br>App Store → **Shortcuts** → Update |
| ✅ Enable Developer Mode  | Shortcuts → `⋯` → Settings → **Advanced** → toggle "Allow Scripts & Logging" |
| ✅ Starter Pack           | Download `Lesson-1-Starters.zip` → AirDrop to iPhone                |

---

## 🧭 1. Context Kick-off (3 min)

> “Shortcuts is Apple’s bash scripting for humans. Even your grandma can run them.”

- Why automation is vital in the iOS 19 + Apple Intelligence era
- Quick overview of the 10-lesson roadmap

---

## 🧱 2. UI Tour (10 min)

### 📚 Gallery
- Swipe up to browse templates
- Tap ➕ `Add Shortcut` → creates a read-only template
- Clone to edit

### 📁 Shortcuts Library
- Switch between **Grid** / **List** view
- Long-press options: Rename · Duplicate · Share · Details

### ✍️ Editor Pane (inside any shortcut)
- 🔍 Action drawer (⌄): search + categories + third-party Actions
- ▶️ Run Sheet: step-by-step log
- Top toolbar: Settings ⚙ · Play ▶ · Share sheet · Close ❌

> 💡 **Coach Tip:** Ask learner to find blue `Magic Variable` buttons on each action.

---

## 🧬 3. Action Anatomy & Privacy Tiers (10 min)

| Layer           | Example                | Data Exposure     | Best Practice                               |
| --------------- | ---------------------- | ----------------- | ------------------------------------------- |
| ✅ On-device     | Get Latest Screenshots | Local only        | Safest – use when possible                  |
| ⚠️ App-mediated | Send Message           | App receives data | Warn user, show alert                       |
| 🚨 Network      | Get Contents of URL    | Internet-bound    | Require user confirmation / VPN recommended |

### 🧪 Demo
- Add `Get Current Weather` → shows **Yellow** tag
- Open `Details → Privacy` → toggle permissions

---

## 🔮 4. Magic Variables 101 (7 min)

1. Drop `Date` action into flow
2. Run once → output appears in tray
3. Tap any text field → `Variables` → insert **blue Date pill**
4. Format: `Custom → "EEEE, MMM d"`
5. Explain difference:
   - Manual variable = boilerplate
   - **Magic Var** = implicit, clean, elegant ✅

---

## 🛠️ 5. Hands-On Lab A: Clone & Tweak Quick Timer (12 min)

### 🧪 Steps

1. Gallery → search `Quick Timer` → Add
2. Open → `Duplicate` → rename to `☕ Brew Timer`
3. Modify input prompt: “Brew time in minutes?”
4. Add condition:
   ```plaintext
   If input ≤ 0 → Show Alert “Nice try 🤨”