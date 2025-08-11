![[Screenshot 2025-07-12 at 12.17.12.png]]
![[Screenshot 2025-07-20 at 16.23.25.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]

---

## 🗂 Core file-system commands

| Command | Purpose | Key flags (most used) | Example |
|---------|---------|-----------------------|---------|
| cd | Change current directory | – | `cd ~/projects` |
| ls | List directory contents | `-l` long format · `-a` hidden · `-h` human sizes | `ls -lah` |
| cp | Copy files **or** directories | `-r` (or `-R`) recurse · `-i` prompt before overwrite · `-v` verbose | `cp -r pset0 pset3` |
| mv | Move or rename | `-i` prompt · `-v` verbose | `mv draft.txt final.txt` |
| mkdir | Create directory | `-p` create parents | `mkdir -p src/include` |
| rm | Remove files / dirs | `-i` prompt · `-r` recurse (dir trees) · `-f` force | `rm -r old_build` |
| rmdir | Remove *empty* directory | – | `rmdir tmp` |
| pwd | Print working directory | – | `pwd` |
| touch | Create / update timestamp | – | `touch notes.txt` |

---

## Why they matter in CS50

- Daily workflow = **edit → compile (`make`) → run (`./program`)** inside project folders.
- Fast navigation & safe copying prevent accidental deletion and time loss.
- Psets often come in separate directories (`pset0`, `pset1` …); you’ll duplicate, rename, reorganize.

---

## Copying directories (the `cp -r` nuance)

If you try to copy a **directory** *without* `-r`:

```bash
cp pset0 pset3
# cp: omitting directory 'pset0'
```

The tool refuses (protects you from silently skipping contents).  
**Solution:** add **`-r`** (“recursive”) to descend into all subdirectories:

```bash
cp -r pset0 pset3
```

Result: a new directory `pset3` containing everything that was in `pset0`.

### Safe patterns

| Goal | Command | Why |
|------|---------|-----|
| Copy a whole pset once | `cp -r pset0 pset0_backup` | Quick snapshot before changes |
| Prevent accidental overwrite | `cp -ri pset0 pset3` | `-i` asks before replacing existing files |
| See what’s being copied | `cp -rv pset0 pset3` | `-v` enumerates each file |

> **Tip:** For large trees you rarely *move* until you are sure; first `cp -r`, verify, then optionally `rm -r original`.

---

## Quick cheat-sheet

```bash
# navigate
cd ~         # home
cd ..        # up one level
pwd          # show where I am

# inspect
ls -lah      # list all, long, human sizes
ls pset1/    # list specific directory

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

---

## Safety checklist

| Action | Question to ask |
|--------|-----------------|
| `rm -r something` | *Am I 100% in the right directory? (`pwd`)* |
| `cp -r dirA dirB` | *Does `dirB` already exist (possible merge)?* |
| `mv old new` | *Is `new` intended as a file or destination directory?* |
| `ls -l` output | *Are permissions or sizes as expected?* |

---

## Mental models

| Command | Picture in mind |
|---------|-----------------|
| `cd` | Move your “you are here” sticker |
| `ls` | Peek inside a box |
| `cp -r` | Clone box + its nested boxes |
| `mv` | Pick up and carry (rename if new label) |
| `rm -r` | Shred box & contents (irreversible) |
| `mkdir -p` | Build a path, creating missing folders |

---

## Common mistakes (and fixes)

| Mistake | Symptom | Fix |
|---------|---------|-----|
| Forget `-r` on directory copy | “omitting directory” | Add `-r` |
| Overwriting file with `cp` silently | Lost previous version | Use `-i` or make backups (`filename.old`) |
| Deleting wrong tree | Data gone | Always `pwd` + `ls` before `rm -r` |
| Confusing source/dest in `mv` | File “disappears” | Remember: `mv SOURCE TARGET` |
| Running commands in wrong pset folder | Build errors / missing files | `pwd`, then `cd correct_folder` |

---

**Take-away:** Master these primitives early; every higher-level tool (Git, build systems, deployment) composes them under the hood. Speed + safety = leverage.

---