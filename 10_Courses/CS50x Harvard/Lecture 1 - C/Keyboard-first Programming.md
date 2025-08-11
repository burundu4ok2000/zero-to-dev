---
title: "Keyboard-first Programming"  
lang_tags: "#lang/tools"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: "#tool/vscode #tool/os/linux #tool/os/macos"
atom_idx: 23
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-11 at 13.22.22.png]]

---

## **One-liner**

**Keyboard-first programming** is a workflow where you drive your tools from the keyboard — **terminal**, **editor**, **build**, **run** — for speed, repeatability, and focus.

## Why it matters in Week 1

- The **Terminal** is text-based: you compile/run by typing (`make hello`, `./hello`).  
- **Muscle memory** compounds: keystrokes become automatic; mousing breaks flow.  
- Real-world dev stacks (servers, CI, containers) lean on **CLI** and scripts.

## Core habits

- Keep a **terminal** open (VS Code **integrated terminal**).  
- Prefer **commands** over menus: `make`, `clang`, `git`.  
- Learn a handful of **keyboard shortcuts** you’ll hit 100×/day.  
- Chain small commands; use **history** and **tab completion**.

## Minimal loop (compile → run → inspect)

```bash
make hello    # build
./hello       # run
echo $?       # check exit status
```

## Suggested shortcuts (VS Code default)

- **Open terminal**: `` Ctrl+` ``  
- **Quick file switch**: `Cmd/Ctrl+P`  
- **Command palette**: `Cmd/Ctrl+Shift+P`  
- **Toggle sidebar**: `Cmd/Ctrl+B`  
- **Multi-cursor**: `Alt/Option` + drag or `Cmd/Ctrl` + click

> Pick 3–5 to start; add more as they pay rent.

## Pitfalls

- Hunting menus with the mouse slows feedback cycles; script repetitive tasks.  
- Over-customizing keymaps early can backfire; stick to defaults until habits form.  
- Forgetting that GUI wrappers still call **CLI** under the hood.

## Related Concepts

- [[Command-Line Interface (CLI)]] – the text-based side of your toolkit.  
- [[Graphical User Interface (GUI)]] – where the editor lives; pair it with the terminal.  
- [[VS Code Integrated Terminal]] – one window, both worlds.  
- [[Command Line Flags Cheat Sheet]] – pass options without hunting dialogs.  
- [[make Build Tool]] – compile with one command.  
- [[Exit status and echo $?]] – quick check of what just happened.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [VS Code — Keyboard shortcuts reference](https://code.visualstudio.com/docs/getstarted/keybindings)  
- [The Art of Command Line](https://github.com/jlevy/the-art-of-command-line)

## Terms

[[keyboard-first]], [[terminal]], [[CLI]], [[GUI]], [[VS Code]], [[integrated terminal]], [[keyboard shortcut]], [[tab completion]], [[history]], [[make]], [[clang]], [[git]], [[echo $?]], [[exit status]], [[muscle memory]]
