---
title: Command Line Flags Cheat Sheet
lang_tags: "#lang/bash"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: "#tool/shell/bash"
atom_idx: 4
status: done
difficulty: easy
date: 2025-08-10
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---
![[Screenshot 2025-07-22 at 10.30.43.png]]

---

## **One-liner

> Common flags for `clang` and everyday shell commands, useful for compiling C and navigating the terminal efficiently.

## Common Commands / Syntax

| **Task**                             | **Command / Code**                               | **Notes**                                      |
|-------------------------------------|--------------------------------------------------|------------------------------------------------|
| Compile C file                      | `clang -o hello hello.c`                         | Output binary `hello`                          |
| Run compiled binary                 | `./hello`                                        | Executes compiled program                      |
| Enable all warnings                 | `-Wall`                                          | Shows most common issues                       |
| Treat warnings as errors            | `-Werror`                                        | Forces you to fix all warnings                 |
| Use specific C standard             | `-std=c11`                                       | Portable modern standard                       |
| Add debug symbols                   | `-g`                                             | Allows stepping through code in debugger       |
| Optimize compiled binary            | `-O2`                                            | Use for final builds, not debugging            |
| Preprocess only                     | `-E`                                             | Shows expanded `#include`, `#define`, etc.     |
| Compile only (no linking)          | `-c`                                             | Produces `.o` file for multi-file builds       |
| Emit assembly                       | `-S`                                             | Outputs assembly version of code               |
| Link CS50 library                   | `-lcs50`                                         | Needed if not using CS50's `make`              |
| Compile with warnings (manual)      | `clang -Wall -Werror -std=c11 -g prog.c -o prog` | More verbose than `make`                       |
| Build & run with CS50 make          | `make program` + `./program`                     | Alias with defaults (like `-lcs50`)            |

## Frequently Used Patterns

- **Clang Build Pattern:** `clang -Wall -Werror -std=c11 -g file.c -o file` — good for development, shows all warnings and enables debugging.
- **Make Pattern (CS50):** `make program` → `./program` — convenient for quick build & run if using CS50 libraries.

## Shortcuts

- `ls -la` — show hidden files with permissions  
- `rm -ri folder` — safely delete folder (asks for each file)  
- `mkdir -p a/b/c` — create nested folders in one go  
- `cp -r src dst` — recursively copy folder contents  
- `mv -v old new` — move with verbose output  

## Tips & Gotchas

- Flags are **case-sensitive**: `-r` ≠ `-R`
- Combining short flags: `ls -la` == `ls -l -a`
- Use `-Wall` + `-Werror` during dev; remove `-Werror` when integrating code
- `-O2` optimization can make debugging harder due to inlined/optimized code

## Examples

```bash
clang -Wall -Werror -std=c11 -g hello.c -o hello
./hello
````

```
clang -E hello.c
```

```
make hello
./hello
```

## **Related Concepts**

- [[CS50 Makefile system]] – uses clang under the hood with flags
    
- [[C Type Sizes and Memory]] – compiled program layout depends on types
    
- [[Black-box abstraction in functions]] – compilation abstracts implementation
    
- [[Array mutation via functions]] – use debugger (-g) to explore memory behavior
    
- [[Debugging with lldb]] – -g flag allows use of debugger
    

  

## **See Also**

- [Clang Manual](https://clang.llvm.org/docs/ClangCommandLineReference.html)
    
- [GNU Compiler Options](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)
    
- [CS50 Lecture 2](https://cs50.harvard.edu/x/2025/weeks/2/)
    

  

## **Terms**

  

[[clang]], [[flag]], [[make]], [[compiler]], [[debugger]], [[warning]], [[optimization]], [[terminal command]], [[bash]]
