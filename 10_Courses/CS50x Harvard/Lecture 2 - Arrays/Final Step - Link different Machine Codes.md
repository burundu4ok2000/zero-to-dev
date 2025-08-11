---
title: Final Step - Link different Machine Codes
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: ""
atom_idx: 12
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

---

![[Screenshot 2025-07-22 at 11.08.45.png]]
![[Screenshot 2025-07-22 at 11.08.50.png]]
![[Screenshot 2025-07-22 at 11.13.50.png]]

---

## Summary
The **linker** is the final build stage that merges **object files** and **libraries** into a single **executable**, resolving **symbols**, applying **relocations**, and laying out code/data sections.

## Key Points
- **Compile vs link:** `clang -c` produces **.o** (no linking). A later link step stitches **.o** + **libs** → **a.out** or a named binary.
- **Symbols:** functions/variables that are **defined** in one file and **referenced** in others. The linker matches references to definitions.
- **Relocation:** patching placeholder addresses in **.o** so calls and data pointers point to the final locations in the executable.
- **Static vs dynamic:** **static linking** copies library code into the binary; **dynamic linking** defers to shared objects (**.so** / **.dylib**) via the runtime loader.
- **Common errors:** “undefined reference to …”, “duplicate symbol …”. Order of **-l** libs can matter on some toolchains.
- **Inspection:** use **nm**, **otool/objdump**, **readelf** to peek at **symbol tables** and **sections**.

## Details
When you split code across files, the compiler can compile each file independently into an **object file** (ELF/Mach‑O). These files contain:
- a **symbol table** (what this file defines/needs),
- **relocation entries** (where addresses must be fixed later),
- code/data **sections** (e.g., .text, .data).

The **linker** then:
1) collects all **.o** and requested **libraries**,  
2) resolves every **undefined symbol** to a matching **definition**,  
3) applies **relocations** (fills in real addresses),  
4) produces the final **executable** with a single **entry point** (e.g., `_start` → calls runtime init → your `main`).

On macOS, `clang` frontends **ld64**; on Linux, **ld**/**gold**/**lld** may be used under the hood. You normally invoke it through `clang` rather than calling the linker directly.

## Examples
### 1) Two C files → one program
**add.c**
```c
int add(int a, int b) {
    return a + b;
}
```
**main.c**
```c
#include <stdio.h>
int add(int, int);

int main(void) {
    printf("%d\n", add(2, 3));
    return 0;
}
```

**Build (two-phase)**
```bash
clang -c add.c    # compile only → add.o
clang -c main.c   # compile only → main.o
clang main.o add.o -o app   # link objects → executable 'app'
./app             # 5
```

### 2) Trigger a typical link error
```bash
clang -c main.c
clang main.o -o app
# ld: undefined symbol: _add   ← we forgot add.o
```

### 3) Link with a library (illustration)
```bash
# order can matter on some platforms:
clang main.o -L. -lmylib -o app     # search in current dir, link libmylib.a or libmylib.dylib/so
```

## **Why It Matters**
- Enables **modular code**: split into multiple files and **reuse libraries**.
- Faster builds: only changed files are recompiled; the linker **incrementally** produces the final binary.
- Foundation for using **third‑party libs**, **package managers**, and **build systems** (e.g., **make**, **CMake**).

## Questions
- When should I prefer **static** over **dynamic** linking for tiny utilities?
- How do I inspect **undefined symbols** with **nm** to debug link errors?
- What’s the role of **CRT** startup code and the program **entry point**?

## Related Concepts
- [[Compiling Process in C]] – zoomed‑out pipeline (**preprocess → compile → assemble → link**)
- [[How code & algorythm becomes 0 s and 1 s.]] – big‑picture: source → machine code
- [[Header Files vs Implementation Files (.h vs .c)]] – declarations vs definitions across files
- [[Static vs Dynamic Linking]] – trade‑offs in binary size, portability, startup time
- [[Makefile Basics]] – automate multi‑file builds and linking
- [[Command Line Flags Cheat Sheet]] – handy **clang**/**ld** flags during builds
- [[Object File Anatomy (ELF/Mach-O/PE)]] – what’s inside **.o** and executables

## See also
- []                                                                       
- [GCC/Clang Compilation and Linking Options](https://clang.llvm.org/docs/CommandGuide/clang.html)                                                              
- [“What is a linker?” (Ian Lance Taylor)](https://www.airs.com/blog/archives/38)

## Terms
[[linker]], [[object file]], [[symbol]], [[symbol table]], [[relocation]], [[static linking]], [[dynamic linking]], [[executable]], [[entry point]], [[library]], [[ABI]], [[CRT]], [[nm]], [[objdump]], [[readelf]]
