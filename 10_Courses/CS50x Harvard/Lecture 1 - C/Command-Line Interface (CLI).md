---
title: Command-Line Interface (CLI)
lang_tags: "#lang/tools"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: "#tool/cli #tool/bash #tool/make #tool/vscode"
atom_idx: 7
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/1/
review_next: ""
---

  

## One-liner


The **CLI** is a text-based interface where you run programs by typing **commands** with **arguments**, which is fast, scriptable, and perfect for development.

  

## Big picture

  

- **\\CLI\\** is the counterpart to **\\GUI\\**: instead of windows and buttons, you interact via a **\\terminal\\** running a **\\shell\\** (like **\\bash\\** or **\\zsh\\**).

- CS50’s workflow uses VS Code’s **\\integrated terminal\\** to compile and run code quickly (e.g., `make hello`, `./hello`). Keyboard > mouse for repetitive dev tasks.

- The shell connects your program to **\\STDIN\\**, **\\STDOUT\\**, and **\\STDERR\\** and sets your **\\working directory\\** and **\\environment variables\\** (like `PATH`).

  

## Mental model

  

```

┌──────────────┐      type commands      ┌────────┐

│  terminal    │ ──────────────────────▶ │ shell  │ ───▶ runs programs

└──────────────┘                         └────────┘

      ▲  │                                     │

      │  └─ displays program output (\\STDOUT\\ / \\STDERR\\)

      └────── you type input (\\STDIN\\)

```

  

## Core skills (Week 1 usage)

  

- **\\Navigation\\**: `pwd` (where am I), `ls` (what’s here), `cd` (move around).

- **\\Run binaries\\**: `./program` runs a compiled file in the current directory.

- **\\Build\\**: `make hello` compiles via a **\\Makefile\\**; `clang -o hello hello.c` is the raw compiler call.

- **\\Inspect status\\**: commands exit with an **\\exit status\\** (`0` = success). Check with `echo $?`.

- **\\Help\\**: `man clang`, `man make`, `--help` flags explain options.

  

## CLI vs GUI (quick compare)

  

| Aspect                | **\\CLI\\**                           | **\\GUI\\**                       |
| --------------------- | ------------------------------------- | --------------------------------- |
| Speed / repeatability | Scriptable, fast for repetitive tasks | Point-and-click, slower for loops |
| Learning curve        | Requires memorizing **commands**      | More discoverable                 |
| Automation            | Easy via **shell scripts**            | Limited without extra tools       |

  

## Example session

  

```bash

pwd                # show working directory

ls                 # list files

make hello         # build C program via make

./hello            # run the program

echo $?            # check exit status of last command

```

  

## Gotchas

  

- Running `program` without `./` won’t work unless the directory is in your **\\PATH\\**.

- Quoting matters: `'single'` vs `"double"` affects how the **\\shell\\** expands variables.

- Spaces in paths need quoting or escaping (`cd "CS50 Labs"`).

  

## Related Concepts

  

- [[Terminal vs Shell]] – difference between the window (terminal) and the interpreter (shell).

- [[Command Line Flags Cheat Sheet]] – common options for `clang`, `make`, and friends.

- [[Exit status and echo $?]] – inspecting program results in the shell.

- [[Path and Environment Variables]] – how `PATH` resolves commands.

- [[File System Navigation (CLI)]] – `pwd`, `ls`, `cd` patterns.

- [[VS Code Integrated Terminal]] – where you interact with the CLI during CS50.

- [[make Build Tool]] – declarative builds used in the course.

  

## See Also

  

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)

- [GNU Bash manual](https://www.gnu.org/software/bash/manual/)

- [The Linux man-pages project](https://man7.org/linux/man-pages/)

  

## Terms

  

[[CLI]], [[GUI]], [[terminal]], [[shell]], [[bash]], [[command]], [[argument]], [[exit status]], [[STDIN]], [[STDOUT]], [[STDERR]], [[PATH]], [[working directory]], [[environment variable]]