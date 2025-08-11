---
title: "Terminal Shortcuts VS Code"  
lang_tags: "#lang/tools"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: "#tool/cli #tool/vscode"
atom_idx: 31
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

## **One-liner**

**Terminal shortcuts** in VS Code speed up your compile–run loop by letting you edit commands, search history, and manage terminals without leaving the keyboard.

## Core line-editing & control keys
*(Work in VS Code’s **integrated terminal**; these are the standard Unix “Emacs” keys implemented by bash/zsh/readline.)*

| Shortcut | Action | When to use |
|----------|--------|-------------|
| **Ctrl + L** | Clear visible screen (same as `clear`) | Reset clutter before the next run. |
| **Ctrl + C** | Interrupt (**SIGINT**) current process | Stop an infinite loop / stuck program. |
| **Ctrl + D** | **EOF** (End Of File) / exit shell if line empty | Quit shell or signal EOF to a waiting program. |
| **Ctrl + A** | Cursor to **start** of line | Edit the beginning of a long command. |
| **Ctrl + E** | Cursor to **end** of line | Append flags quickly. |
| **Ctrl + K** | Delete from cursor to end of line | Trim a bad tail. |
| **Ctrl + U** | Delete from cursor back to start | Nuke and retype. |
| **Ctrl + W** | Delete previous **word** | Remove the last arg fast. |
| **Ctrl + Y** | **Yank** (paste last killed text) | Undo a K/U/W deletion. |
| **Ctrl + R** | Reverse **history search** | Recall a previous `clang ...` or `make ...`. |
| **Up / Down** | Navigate history | Re-run last commands. |
| **Tab** | **Autocomplete** file/command | Avoid typos; explore paths. |

## VS Code terminal management
*(Shortcuts may vary by platform—these are the defaults or common bindings.)*

| Shortcut | Scope | Action |
|----------|------|--------|
| `` Ctrl + ` `` | VS Code | Toggle integrated terminal panel |
| **Ctrl + Shift + `** | VS Code | Create **new terminal** |
| **Ctrl + Shift + 5** | VS Code | **Split** terminal |
| **Ctrl + Shift + P** → “Terminal: Clear” | VS Code | Clear terminal **scrollback** |
| **Ctrl + K** then **Ctrl + K** | VS Code | Clear scrollback (alt binding) |
| **Ctrl + Shift + W** | VS Code | Kill active terminal instance |
| **Ctrl + PgUp / PgDn** | VS Code | Switch terminal tabs |
| **Ctrl + J** | VS Code | Toggle panel (terminal/problems/output) |

> On macOS, replace **Ctrl** with **Cmd** for many VS Code UI shortcuts (e.g., `Cmd + J`). On Linux/Windows, defaults usually use **Ctrl**.

## Productive patterns

| Task | Shortcut combo |
|------|----------------|
| Abort & immediately re-run last command | `Ctrl + C` → **Up** → **Enter** |
| Fix start **and** end of a long line | `Ctrl + A` → edit → `Ctrl + E` |
| Edit a middle argument | Word-jump, `Ctrl + W` to delete, type replacement |
| Recover a deleted tail | `Ctrl + K` (oops) → `Ctrl + Y` |

## Safety tip

If **Ctrl + C** doesn’t stop it, list and kill:

```bash
ps            # list processes
kill <pid>    # gentle
kill -9 <pid> # force only if necessary
```

## Related Concepts

- [[Keyboard-first Programming]] – build the habit of staying on the keyboard.  
- [[Terminal Commands Basics]] – navigation/copy essentials.  
- [[Terminal Commands Advanced]] – permissions, links, diffs, sudo.  
- [[Command-Line Interface (CLI)]] – environment where these shortcuts live.  
- [[VS Code Integrated Terminal]] – the terminal inside your editor.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [VS Code — Integrated Terminal docs](https://code.visualstudio.com/docs/terminal/basics)  
- [GNU Readline — Emacs-style shortcuts](https://tiswww.case.edu/php/chet/readline/rltop.html)

## Terms

[[terminal]], [[integrated terminal]], [[keyboard shortcut]], [[history]], [[reverse search]], [[SIGINT]], [[EOF]], [[autocomplete]], [[scrollback]], [[split terminal]], [[panel]], [[kill process]]
