![[Screenshot 2025-07-20 at 17.46.47.png]]

> **Lecture reference:** [[Lecture 1 - C]] (CS50 Shorts – Command Line)  
> **Course:** [[CS50x Harvard]]  
> **Companion note:** [[Terminal Commands Basics]]

---

## Why these matter

Once you’re comfortable with `cd`, `ls`, `cp`, etc., these tools unlock **permissions, inspection, comparisons, linking, elevation, and cleaning the view**. They make you faster and help you understand what the OS is doing.

---

## Command overview

| Command | Core purpose | Typical usage | Mental hook |
|---------|--------------|---------------|-------------|
| `chmod` | Change file permissions (read / write / execute) | `chmod 644 notes.txt`, `chmod +x run.sh` | “Who can do what” |
| `sudo` | Run a command with *superuser* (admin) privileges | `sudo apt update` | “Do as root” (temporary power) |
| `ln` | Create links: hard or symbolic (shortcuts / aliases) | `ln -s ~/projects/app/config.json config.json` | “Alternative name / pointer” |
| `touch` | Create empty file or update timestamp | `touch log.txt` | “Ensure file exists” |
| `man` | Read manual page for a command | `man grep` | “Built-in docs” |
| `diff` | Show line-by-line differences between files | `diff old.c new.c` | “What changed?” |
| `clear` | Clear terminal screen (scrollback stays) | `clear` or `Ctrl+L` | “Wipe visual clutter” |
| `rmdir` | Remove *empty* directory | `rmdir tempdir` | “Delete blank folder” |
| `telnet`* | Raw network connection (legacy) | `telnet towel.blinkenlights.nl` | “Old-school network test” *(mostly historical)* |

> *`telnet` today is primarily educational; modern secure alternative: `ssh`.*

---

## chmod essentials

Permissions are shown like: `-rwxr-xr--`

| Segment | Who | Example `-rwx r-x r--` |
|---------|-----|------------------------|
| 1st char | Type (`-` file, `d` dir) | `-` |
| Next 3 | Owner perms | `rwx` |
| Next 3 | Group perms | `r-x` |
| Last 3 | Others perms | `r--` |

Numeric (octal) shortcuts:

| Mode | Meaning |
|------|---------|
| 7 = 4+2+1 | rwx |
| 6 = 4+2 | rw- |
| 5 = 4+1 | r-x |
| 4 | r-- |

Examples:

```bash
chmod 644 file.c    # rw-r--r--
chmod 600 secrets   # rw-------
chmod +x script.sh  # add execute for owner/group/others as allowed
```

---

## sudo in context

Use *sparingly*. It prepends commands:

```bash
sudo apt install valgrind
```

Checklist before using `sudo`:

1. Do I *need* system-level change? (Installing packages, editing protected files.)
2. Am I copying untrusted commands from the internet? (Pause & review.)
3. Could I use a non-root approach (local install, user-owned directory)?

---

## diff quick start

```bash
diff old.c new.c
diff -u old.c new.c   # unified format (preferred)
```

Typical output hunk header:

```
@@ -5,3 +5,4 @@
```

Meaning: starting at line 5, original had 3 lines, new has 4.

> Use `git diff` inside repos—richer integration.

---

## ln (links)

### Symbolic (soft) link (most common):

```bash
ln -s /actual/path/config.json config.json
```

- Points to original.
- Breaks (“dangling”) if original removed.

### Hard link:

```bash
ln original.txt twin.txt
```

- Both names point to *same inode* (data). Deleting one doesn’t delete data until last link removed.
- Only within same filesystem; not for directories (normally).

---

## man pages

Structure: *NAME, SYNOPSIS, DESCRIPTION, OPTIONS, EXAMPLES, SEE ALSO*

Fast navigation:

| Key | Action |
|-----|--------|
| `/term` | Search forward |
| `n` | Next match |
| `q` | Quit |
| Space | Page down |

If manual too long: `man ls | less`

---

## Practical mini-scenarios

| Task | Command(s) | Explanation |
|------|------------|-------------|
| Make a script executable | `chmod +x build.sh` | Allows `./build.sh` |
| Compare your code with staff distribution | `diff -u distro.c my.c` | Shows exact edits |
| Create shortcut to deep directory | `ln -s ~/psets/2025/week1 project` | Now `cd project` is shorter |
| Update a timestamp to trigger build | `touch main.c` | Make sees file as “changed” |
| Read docs for mysterious flag | `man grep` then search `/--color` | Direct primary source |
| Clean view before new run | `clear` or `Ctrl+L` | Focus on fresh output |

---

## Common mistakes & fixes

| Mistake | Problem | Fix |
|---------|---------|-----|
| `chmod 777 file` | Over-permissive | Narrow to least needed (`644`, `600`) |
| `sudo rm -r /something/wrong` | Catastrophic delete | Triple-check path; avoid `sudo` with `rm` unless essential |
| Forget `-s` with `ln` | Creates hard link unexpectedly | For a visible alias path, add `-s` |
| `diff` output unreadable | Mixed order | Add `-u` or use `colordiff` |
| Relying on telnet for secure services | Plaintext, insecure | Use `ssh` or `openssl s_client` for TLS tests |

---

## Progression roadmap

1. Add `man`, `clear`, `touch` into daily flow.  
2. Learn to read permission strings + adjust with `chmod`.  
3. Use `diff -u` to self-review before submitting code.  
4. Start creating symlinks for frequently accessed deep folders.  
5. Introduce `sudo` only when package management or system tasks required.

---

**Take-away:** These “advanced” commands deepen control: you *inspect*, *compare*, *link*, *elevate*, and *document* your environment—hallmarks of moving from beginner to power user.

---