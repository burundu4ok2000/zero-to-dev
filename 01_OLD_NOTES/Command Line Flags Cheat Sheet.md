![[Screenshot 2025-07-22 at 10.30.43.png]]


> **Lecture reference:** [[Lecture 2 - Arrays]]  
> **Course:** [[CS50x Harvard]]

---

## Clang basics

```bash
clang -o hello hello.c    # compile → output file hello
./hello                   # run the program
```

### Useful clang flags

| Flag | Meaning | When to use |
|------|---------|--------------|
| `-o file` | Output filename | Name the executable yourself |
| `-Wall` | All common warnings | Catch bugs early |
| `-Werror` | Treat warnings as errors | Force yourself to fix them |
| `-std=c11` | Use C11 standard | Keep things portable/modern |
| `-g` | Debug symbols | Step through code with `lldb`/`gdb` |
| `-O2` | Optimize | Final builds (not during debugging) |
| `-E` | Stop after preprocessing | Inspect `#include`/`#define` expansion |
| `-S` | Stop after compilation (emit assembly) | Peek under the hood |
| `-c` | Compile to object (`.o`) only | For multi-file projects |
| `-lcs50` | Link CS50 library (if makefile not provided) | Manual builds using CS50 helpers |

---

## Command + flag mental model

- **Command** does the thing (`clang`, `ls`, `cp`, `rm` …).  
- **Flags/options** tweak behavior.  
  - Short: `-g`, `-o`, `-r` (single dash, one letter; can be combined: `-la`)  
  - Long: `--help`, `--version` (double dash, full word)

---

## Everyday terminal flags you’ll meet

| Command | Common flags | Example | Why |
|---------|--------------|---------|-----|
| `ls` | `-l` long, `-a` all | `ls -la` | See perms + hidden files |
| `cp` | `-r` recursive, `-i` interactive | `cp -r src dst` | Copy folders safely |
| `rm` | `-r`, `-f`, `-i` | `rm -ri dir` | Delete dirs with confirmation |
| `mv` | `-i`, `-v` | `mv -v old new` | Rename/move with feedback |
| `mkdir` | `-p` parents | `mkdir -p a/b/c` | Create nested dirs |

---

## Quick reference

```bash
# Build + run fast
make program     # CS50 alias for clang with the right flags
./program

# Manual, verbose build (see warnings)
clang -Wall -Werror -std=c11 -g program.c -o program
```

Keep this around until “eventually you memorize these things.” 🙂