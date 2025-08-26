<%*

const today     = tp.date.now("MMMM D, YYYY");          // July 17, 2025

const dayOfWeek = tp.date.now("dddd").toLowerCase();    // thursday

const fileTitle = tp.date.now("YYYY-MM-DD");            // 2025-07-17

  

// 🪄 Автопереименование файла

await tp.file.rename(`${fileTitle}`);

  

tR += `# ${fileTitle} – Work log

📅 ${today} – Work schedule

| Time | Task Name | NOTES |
|------|-----------|-------|
|      |           |       |
|      |           |       |
|      |           |       |
|      |           |       |
|      |           |       |
|      |           |       |
|      |           |       |
|      |           |       |
|      |           |       |
|      |           |       |

---

📅 ${today} – Work Log

🗓️ Day: ${dayOfWeek}
⏰ Wake-up Time: 

⸻
🔄 Cycle 1
💼 Start of Work: 
🏡 Location: 
- [ ] 🍅 Pomodoro 1
- [ ] 🍅 Pomodoro 2
- [ ] 🍅 Pomodoro 3
- [ ] 🍅 Pomodoro 4

🏁 End of Work: 
🎯 Concentration Level: high

⸻
🔄 Cycle 2
💼 Start of Work: 
🏡 Location: 
- [ ] 🍅 Pomodoro 1
- [ ] 🍅 Pomodoro 2
- [ ] 🍅 Pomodoro 3
- [ ] 🍅 Pomodoro 4

🏁 End of Work: 
🎯 Concentration Level: high

⸻
🌙 Cycle 3
💼 Start of Work: 
🏡 Location: 
- [ ] 🍅 Pomodoro 1
- [ ] 🍅 Pomodoro 2
- [ ] 🍅 Pomodoro 3
- [ ] 🍅 Pomodoro 4

🏁 End of Work: 
🎯 Concentration Level: mid

🌙 Cycle 4
💼 Start of Work: 
🏡 Location:  
- [ ] 🍅 Pomodoro 1
- [ ] 🍅 Pomodoro 2
- [ ] 🍅 Pomodoro 3
- [ ] 🍅 Pomodoro 4

🏁 End of Work: 
🎯 Concentration Level: low

` %>