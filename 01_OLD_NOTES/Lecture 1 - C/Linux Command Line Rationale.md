![[Screenshot 2025-07-20 at 16.01.19.png]]

> **Lecture reference:** [[Lecture 1 - C]] (CS50 Shorts – Command Line)  
> **Course:** [[CS50x Harvard]]
> [[CLI]]

---

## What the slide is saying

- The CS50 IDE gives you a **cloud Ubuntu environment** (a Linux distribution).
- Modern Linux distros have full **graphical interfaces**, but
- As a programmer you’ll still **live in the terminal** often, because many tasks are faster and more repeatable as commands.

---

## Why programmers use Linux

| Benefit            | Explanation                           | Example Command                  |
| ------------------ | ------------------------------------- | -------------------------------- |
| Automation         | Chain actions quickly                 | `make && ./app && ./test.sh`     |
| Scriptability      | Put sequences in reusable scripts     | `deploy.sh`, `backup.sh`         |
| Remote access      | Same interface over SSH anywhere      | `ssh user@server`                |
| Reproducibility    | Document exact steps                  | `README` with setup commands     |
| Package management | Rapid install of dev libs             | `sudo apt install valgrind`      |
| Production parity  | Most servers/containers = Linux       | Fewer “works on my machine” bugs |
| Transparency       | Inspect processes, files, permissions | `ps aux`, `ls -l`, `strace`      |
| Customization      | Dotfiles & aliases shape workflow     | `alias gc='git commit -m'`       |

---

## Core mental model

**GUI = discover, learn.**  
**CLI = automate, scale, reproduce.**  

You keep the GUI for casual tasks; you master the CLI for power.

---

## Key starting commands (orientation)

| Goal | Command | Note |
|------|---------|------|
| Where am I? | `pwd` | Print working directory |
| List files | `ls -lah` | Human sizes + hidden files |
| Change directory | `cd dirname` / `cd ..` | Move into / up |
| Read a file quickly | `cat`, `less file.txt` | `less` scrolls |
| Compile C | `make program` | Uses CS50’s Make defaults |
| Run program | `./program` | Needs execute permission |
| Edit file | `code file.c` | Opens in IDE editor |

---

## When GUI still helps

| Situation | Use GUI |
|-----------|---------|
| Visual diffing images / media | Image viewer |
| Drag-drop assets | File browser |
| Learning directory layout initially | Explorer panel |

---

## Progression

1. Memorize navigation & listing (`pwd`, `ls`, `cd`).
2. Add file ops (`cp`, `mv`, `rm`, `mkdir`).
3. Learn chaining & piping (`|`, `>`, `>>`).
4. Incorporate Git commands.
5. Write small shell scripts.
6. Optimize with aliases & environment variables.

---

## Take-away

The terminal is not “old”; it’s a *leverage multiplier*. Mastering it lets you build, test, debug, deploy, and automate with far less friction than clicking through menus. That’s why CS50 pushes you into a Linux shell early.

---