---
title: "Terminal Commands Advanced"  
lang_tags: "#lang/tools"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_1_C"
tool_tags: "#tool/cli #tool/os/linux"
atom_idx: 29
status: "done"
difficulty: "easy"
date: "2025-08-11"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/1/"
review_next: ""
---

![[Screenshot 2025-07-20 at 17.46.47.png]]

---

## **One-liner**

After you’re comfy with `cd`, `ls`, `cp`, and friends, these commands give you **permissions control**, **inspection**, **comparison**, **linking**, and **elevation**—the ingredients of a power user.

## Command overview

| Command | Core purpose | Typical usage | Mental hook |
|---------|--------------|---------------|-------------|
| `chmod` | Change file **permissions** (read / write / execute) | `chmod 644 notes.txt`, `chmod +x run.sh` | “Who can do what” |
| `sudo`  | Run with **superuser** privileges | `sudo apt update` | “Do as root (briefly)” |
| `ln`    | Create **links**: hard or symbolic | `ln -s ~/projects/app/config.json config.json` | “Another name/pointer” |
| `touch` | Create empty file or update timestamp | `touch log.txt` | “Ensure file exists” |
| `man`   | Read **manual** page | `man grep` | “Built-in docs” |
| `diff`  | Show line-by-line **differences** | `diff -u old.c new.c` | “What changed?” |
| `clear` | Clear terminal screen | `clear` or `Ctrl+L` | “Wipe clutter” |
| `rmdir` | Remove *empty* directory | `rmdir tempdir` | “Delete blank folder” |
| `telnet`* | Raw network connection (legacy) | `telnet towel.blinkenlights.nl` | “Old-school test” *(historical)* |

> Use **ssh** instead of telnet for secure connections.

## chmod essentials

Permissions look like: `-rwxr-xr--`

| Segment | Who | Example `-rwx r-x r--` |
|---------|-----|------------------------|
| 1st char | Type (`-` file, `d` dir) | `-` |
| Next 3 | Owner perms | `rwx` |
| Next 3 | Group perms | `r-x` |
| Last 3 | Others perms | `r--` |

Numeric shortcuts (octal):

| Mode | Meaning |
|------|---------|
| 7 = 4+2+1 | rwx |
| 6 = 4+2   | rw- |
| 5 = 4+1   | r-x |
| 4         | r-- |

Examples:

```bash
chmod 644 file.c    # rw-r--r--
chmod 600 secrets   # rw-------
chmod +x script.sh  # add execute bit
```

## sudo in context

`sudo` prepends commands to grant admin rights temporarily:

```bash
sudo apt install valgrind
```

Checklist before `sudo`:

1. Is a **system-level** change required?  
2. Am I blindly pasting commands from the web? **Stop & review.**  
3. Is there a **non-root** alternative (local install, user dir)?

## diff quick start

```bash
diff old.c new.c
diff -u old.c new.c   # unified format (preferred)
```

Hunk header example:

```
@@ -5,3 +5,4 @@
```

Meaning: from line 5, original had 3 lines; new has 4.

> Inside repos, prefer `git diff` for richer context.

## ln (links)

### Symbolic (soft) link

```bash
ln -s /actual/path/config.json config.json
```

- Points to original; breaks if original is removed.

### Hard link

```bash
ln original.txt twin.txt
```

- Both names point to the **same inode** (data); deleting one doesn’t remove data until the last link goes.  
- Same filesystem only; not for directories (normally).

## man pages

Sections: **NAME**, **SYNOPSIS**, **DESCRIPTION**, **OPTIONS**, **EXAMPLES**, **SEE ALSO**

Navigation:

| Key | Action |
|-----|--------|
| `/term` | Search forward |
| `n` | Next match |
| Space | Page down |
| `q` | Quit |

Too long? Pipe to a pager: `man ls | less`.

## Practical mini-scenarios

| Task | Command(s) | Why |
|------|------------|-----|
| Make a script executable | `chmod +x build.sh` | Enables `./build.sh` |
| Compare your code to staff distro | `diff -u distro.c my.c` | Shows exact edits |
| Create a shortcut to deep dir | `ln -s ~/psets/2025/week1 project` | Faster `cd project` |
| Trigger a rebuild | `touch main.c` | Make sees file as “changed” |
| Learn a mysterious flag | `man grep` → search `/--color` | Primary source |

## Common mistakes & fixes

| Mistake | Problem | Fix |
|---------|---------|-----|
| `chmod 777 file` | Over-permissive | Narrow to least needed (`644`, `600`) |
| `sudo rm -r /something/wrong` | Catastrophic delete | Triple-check path; avoid pairing `sudo` with `rm` |
| Forget `-s` with `ln` | Created hard link unintentionally | Use `ln -s` for symlink |
| `diff` unreadable | Too noisy | Add `-u` or use `colordiff` |
| Using `telnet` for secure services | Insecure plaintext | Use `ssh` or TLS tools |

## Progression roadmap

1. Add `man`, `clear`, `touch` to daily flow.  
2. Learn to read permission strings and adjust with `chmod`.  
3. Use `diff -u` before submitting code.  
4. Create symlinks for frequently accessed deep paths.  
5. Apply `sudo` **only** for package/system tasks.

## Related Concepts

- [[Terminal Commands Basics]] – first set of navigation/copy essentials.  
- [[Linux Command Line Rationale]] – why CLI speeds development.  
- [[Command-Line Interface (CLI)]] – where all of this runs.  
- [[Keyboard-first Programming]] – habits for speed.  
- [[VS Code Integrated Terminal]] – one window for editing + running.  
- [[SSH Basics]] – secure remote access (vs telnet).  
- [[File Permissions (chmod)]] – deeper dive on modes and octal.

## See Also

- [CS50x 2025 — Week 1 overview](https://cs50.harvard.edu/x/2025/weeks/1/)  
- [The Linux man-pages project](https://man7.org/linux/man-pages/)  
- [GNU Coreutils Manual](https://www.gnu.org/software/coreutils/manual/coreutils.html)

## Terms

[[chmod]], [[permissions]], [[octal mode]], [[rwx]], [[sudo]], [[root]], [[ln]], [[symbolic link]], [[hard link]], [[inode]], [[man page]], [[diff]], [[unified diff]], [[clear]], [[rmdir]], [[telnet]], [[ssh]]
