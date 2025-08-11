---
title: "Terminal Commands Basics"  
lang_tags: "#lang/tools"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: "#tool/cli #tool/os/linux"
atom_idx: 28
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-12 at 12.17.12.png]]
![[Screenshot 2025-07-20 at 16.23.25.png]]

---

## **One-liner**

Day‑1 **terminal** fluency = moving around the **file system**, copying safely, and running builds from the **CLI** using short, composable **commands** with **flags** and **arguments**.

## Core file‑system commands

| Command | Purpose | Key flags (most used) | Example |
|---------|---------|-----------------------|---------|
| `cd` | Change current **working directory** | – | `cd ~/projects` |
| `ls` | List directory contents | `-l` long · `-a` hidden · `-h` human sizes | `ls -lah` |
| `cp` | Copy files **or** directories | `-r` recursive · `-i` prompt · `-v` verbose | `cp -r pset0 pset3` |
| `mv` | Move or rename | `-i` prompt · `-v` verbose | `mv draft.txt final.txt` |
| `mkdir` | Create directory | `-p` create parents | `mkdir -p src/include` |
| `rm` | Remove files/dirs | `-i` prompt · `-r` recurse (trees) · `-f` force | `rm -r old_build` |
| `rmdir` | Remove *empty* directory | – | `rmdir tmp` |
| `pwd` | Print working directory | – | `pwd` |
| `touch` | Create or update timestamp | – | `touch notes.txt` |

## Why they matter in CS50

- Your daily loop is **edit → compile (`make`) → run (`./program`)** inside project folders.  
- Fast navigation + safe copying prevents accidental deletion and time loss.  
- Psets live in separate directories (`pset0`, `pset1`, …); you’ll duplicate, rename, reorganize often.

## Copying directories (the `cp -r` nuance)

If you try to copy a **directory** *without* `-r`:

```bash
cp pset0 pset3
# cp: omitting directory 'pset0'
```

The tool refuses (protects you from silently skipping contents).  
**Fix:** add **`-r`** (“recursive”) to descend into subdirectories:

```bash
cp -r pset0 pset3
```

### Safe patterns

| Goal | Command | Why |
|------|---------|-----|
| Quick snapshot | `cp -r pset0 pset0_backup` | Version before risky edits |
| Avoid overwrite | `cp -ri pset0 pset3` | `-i` asks before replacing |
| See progress | `cp -rv pset0 pset3` | `-v` lists copied files |

## Quick cheat‑sheet

```bash
# navigate
cd ~         # home
cd ..        # up one level
pwd          # where am I?

# inspect
ls -lah      # list all, long, human sizes
ls pset1/    # list a specific dir

# create / delete
mkdir docs
mkdir -p src/include
rm notes.txt
rm -r old_dir   # remove directory tree (careful!)

# copy / rename
cp main.c backup.c
cp -r pset0 pset3
mv backup.c old_main.c

# edit & build
code main.c
make main
./main
```

## Safety checklist

| Action | Question to ask |
|--------|-----------------|
| `rm -r something` | *Am I in the right place? (`pwd`)* |
| `cp -r dirA dirB` | *Does `dirB` already exist (merge risk)?* |
| `mv old new` | *Is `new` a file name or a directory?* |
| `ls -l` output | *Permissions/sizes look right?* |

## Mental models

| Command | Picture in mind |
|---------|-----------------|
| `cd` | Move your “you are here” sticker |
| `ls` | Peek inside a box |
| `cp -r` | Clone a box + its nested boxes |
| `mv` | Pick up and carry (rename if new label) |
| `rm -r` | Shred box & contents (irreversible) |
| `mkdir -p` | Build a path, creating missing folders |

## Common mistakes (and fixes)

| Mistake | Symptom | Fix |
|---------|---------|-----|
| Forget `-r` on directory copy | “omitting directory” | Add `-r` |
| Overwriting with `cp` | Lost previous version | Use `-i` or backups (`file.old`) |
| Deleting wrong tree | Data gone | Always `pwd` + `ls` before `rm -r` |
| Swapping source/dest in `mv` | File “disappears” | Remember `mv SOURCE TARGET` |
| Running in wrong folder | Build errors | `pwd`, then `cd correct_folder` |

## Related Concepts

- [[Command-Line Interface (CLI)]] – the text‑based interface where you type **commands**.  
- [[Linux Command Line Rationale]] – why devs favor **CLI** for speed and automation.  
- [[Keyboard-first Programming]] – develop **muscle memory** and flow.  
- [[VS Code Integrated Terminal]] – one window for editing and running.  
- [[make Build Tool]] – compile with one **command**.  
- [[Exit status and echo $?]] – inspect the last program’s result.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [The Linux man‑pages project](https://man7.org/linux/man-pages/)  
- [The Art of Command Line](https://github.com/jlevy/the-art-of-command-line)

## Terms

[[command]], [[argument]], [[flag]], [[working directory]], [[home directory]], [[parent directory]], [[path]], [[recursive copy]], [[prompt before overwrite]], [[verbose mode]], [[file system]], [[shell]], [[terminal]], [[build]], [[compile]], [[execute]]
