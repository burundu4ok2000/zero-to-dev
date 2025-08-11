Mac Terminal Shortcuts (VS Code / macOS)

> **Lecture reference:** [[Lecture 1 - C]] · **Course:** [[CS50x Harvard]]

---

## Core (Control) shortcuts — work inside the **integrated terminal** and macOS Terminal (Unix / bash / zsh “Emacs” keys)

| Shortcut | Action | When to use |
|----------|--------|-------------|
| **Ctrl + L** | Clear visible screen (same as `clear`) | Wipe clutter before a new compile / run cycle. |
| **Ctrl + C** | Interrupt (SIGINT) current process | Stop an infinite loop / stuck program (`./a.out`). |
| **Ctrl + D** | End Of File (EOF) / exit shell if line empty | Quit the shell or signal EOF to a waiting program. |
| **Ctrl + A** | Move cursor to start of line | Jump to tweak a command’s beginning (`gcc ...`). |
| **Ctrl + E** | Move cursor to end of line | Append flags (`-Wall -Werror`) quickly. |
| **Ctrl + K** | Kill (delete) from cursor to end of line | Truncate a long mistyped tail. |
| **Ctrl + U** | Kill from cursor back to start | Nuke and retype a broken command fast. |
| **Ctrl + W** | Kill word to the left | Remove just the previous argument. |
| **Ctrl + Y** | Yank (paste last killed text) | Restore something you just killed with K / U / W. |
| **Ctrl + R** | Reverse search history | Find that perfect `clang ...` command by typing a fragment. |
| **Up / Down** | Previous / next history entry | Rapidly re-run `make foo`, `./foo`. |
| **Tab** | Autocomplete path / file / command | Avoid typos: `./me` + Tab → `./meow`. |
| **Tab Tab** | (Sometimes) list possible completions | Explore ambiguous matches. |
| **Ctrl + Z** | Suspend foreground job | Temporarily pause a program (resume with `fg`). |

---

## macOS / VS Code specific extras

| Shortcut | Scope | Action | Note |
|----------|-------|--------|------|
| **Cmd + K** then **Cmd + K** (VS Code terminal) | VS Code | Clear terminal *scrollback* | Leaves current prompt; more thorough than `Ctrl + L`. |
| **Cmd + ← / Cmd + →** | Shell line (macOS Terminal & some shells) | Jump to start / end of line | Alternative to Ctrl+A / Ctrl+E (depends on key bindings). |
| **Option + ← / Option + →** | Shell line | Move cursor one word left / right | Faster intra-line navigation. |
| **Cmd + C** (when *no* selection & process running) | macOS | Also sends interrupt | Falls back to copy if text selected. |
| **Cmd + V** | macOS | Paste | Standard macOS paste (vs. middle-click on Linux). |

> If Option word shortcuts don’t work, enable: **Terminal ▸ Settings ▸ Profiles ▸ Keyboard ▸ Use Option as Meta**.

---

## Dot-slash (`./`) reminder

- `./program` runs an executable **in the current directory** (current working directory is *not* searched automatically for security reasons).
- Combine with Tab to complete: `./co` + **Tab** → `./compare`.

---

## Productive patterns

| Task | Shortcut combo |
|------|----------------|
| Fix start AND end of a long line | `Ctrl + A` → edit → `Ctrl + E` |
| Abort & immediately re-run last command | `Ctrl + C` → **Up** → **Enter** |
| Edit middle argument | Arrow keys / Option+←→ to word, `Ctrl + W` to remove, type replacement |
| Recover accidentally deleted tail | `Ctrl + K` (oops) → `Ctrl + Y` |

---

## Safety tip

If you hit **Ctrl + C** and the program **doesn’t** stop, you might be in a state where it’s ignoring interrupts (rare in CS50). Use:

```bash
ps            # list processes
kill <pid>    # gentle
kill -9 <pid> # force (only if necessary)
```

---

**Memorize 3 first**: `Ctrl + C`, `Ctrl + L`, `Ctrl + R`.  
Add the navigation/editing keys next. Muscle memory compounds your compile–run loop speed.

---