---
title: Final Compilation Step — Machine Code
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: "#tool/os/linux #tool/os/macos"
atom_idx: 10
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

---

![[Screenshot 2025-07-22 at 11.02.39.png]]

---

## Summary
After **preprocessing**, **compiling**, **assembling**, and **linking**, you get **machine code**: raw bytes the CPU executes. It’s readable to the computer, not to humans.

## Key Points
- Machine code is just bytes (often shown as **hex**) that encode **opcodes**, **registers**, **addresses**, and **immediates**.
- Tools like a **disassembler** (e.g., `objdump`, `otool`) let you *view* assembly, but they don’t recover your original C.
- Executables have a **binary format** (e.g., **ELF** on Linux, **Mach-O** on macOS) and follow an **ABI** (application binary interface).
- **Instruction Set Architecture (ISA)** (e.g., **x86-64**, **ARM64**) defines what opcodes exist and their encodings.
- **Endianness** and **calling conventions** affect how bytes and function calls are laid out at the machine level.

## Details
At the end of the toolchain, the linker emits an executable file whose contents are sections of **instructions** and **data**. The CPU’s **fetch–decode–execute** loop reads these bytes as **opcodes** plus operands (like **register** ids or memory **addresses**). Because the mapping is compact and ISA-specific, the output appears as gibberish unless you view it through a **disassembler**. That view is a best-effort translation to **assembly**, not back to high-level C; comments, names, and many abstractions are gone unless debug info was included.

## Examples
Peek into a compiled program on Linux/macOS:

```bash
# show raw bytes (hex dump)
xxd ./hello | head

# disassemble to assembly
objdump -d ./hello | less     # Linux (ELF)
otool -tV ./hello             # macOS (Mach-O)
```

Minimal mental model of levels:

```
C source  →  Assembly  →  Machine code (bytes)
(readable)    (semi)        (for CPU only)
```

## **Why It Matters**
Understanding that the CPU runs **bytes**, not C, explains why build flags, target **ISA**, and the **linker** output matter. It also demystifies debugging at the assembly level and tools like **objdump** or **lldb/gdb**.

## Questions
- ❓Which **calling convention** does my platform use (e.g., System V AMD64 vs. Windows x64), and how does it shape function prologues/epilogues?
- ❓How do **optimizations** (`-O2`, `-O3`) change emitted **opcodes** and control flow?
- ❓Where do my program’s **.text**, **.data**, and **.rodata** sections live in the final binary?

## Related Concepts
- [[Compilation Stages Overview]] – situates **preprocessing → compiling → assembling → linking** before this final step.
- [[Assembly Basics (x86-64)]] – reading the output of a disassembler confidently.
- [[Object Files vs Executables]] – how **.o** becomes a final binary via the **linker**.
- [[Linker and Loader]] – address resolution, relocation, and program startup.
- [[Calling Convention (System V AMD64)]] – why you see `push %rbp`, `mov %rsp, %rbp`, etc.
- [[Debug Symbols and DWARF]] – recovering names/lines for debugging.

## See also
- [](https://cs50.harvard.edu/x/2025/weeks/2/)
- [](https://sourceware.org/binutils/docs/binutils/objdump.html)

## Terms
[[machine code]], [[hex]], [[opcode]], [[register]], [[address]], [[immediate]], [[ELF format]], [[Mach-O format]], [[ABI]], [[ISA]], [[x86-64]], [[ARM64]], [[endianness]], [[calling convention]], [[disassembler]], [[objdump]], [[otool]], [[linker]], [[assembler]]
