![[Screenshot 2025-07-22 at 10.58.30.png]]

> **Lecture reference:** [[Lecture 2 - Arrays]]  
> **Course:** [[CS50x Harvard]]
> [[Compiling Process in C]]
> [[Command Line Flags Cheat Sheet]]

---

## What “low-level commands” are

Assembly instructions are the tiny operations your CPU actually understands.  
Clang turns your C into this stuff; you just saw lines like `pushq`, `movq`, `subq`, `callq`, `ret`.

---

## Reading AT&T style (what Clang shows)

- **Mnemonic first**, then **source, destination** → `movq %rsp, %rbp`  
- **`%rax`, `%rbp`, …`** are **registers** (tiny, super-fast variables in the CPU).  
- **`$42`** is an **immediate constant** (literal number).  
- **`-8(%rbp)`** means “memory at address `rbp - 8`” (a local variable on the stack).  
- **Comments** start with `#`.

---

## Frequent mnemonics you’ll see

| Instruction | Plain English | Typical C concept |
|-------------|----------------|-------------------|
| `pushq X`   | Put X on the stack | Save something for later |
| `popq X`    | Take top of stack into X | Restore saved value |
| `movq A, B` | Copy A into B | Assignment `B = A;` |
| `subq $N, %rsp` | Move stack pointer down N bytes | Allocate locals |
| `addq $N, %rsp` | Move stack pointer up N bytes | Free locals |
| `callq foo` | Jump to function `foo`, remember return point | Function call |
| `ret`       | Return to caller | `return …;` |
| `cmpq A, B` | Compare B with A | `if (B ? A)` (sets flags) |
| `jmp label` | Unconditional jump | `goto` / loop jump |
| `je`, `jne`, `jl`, `jg` | Jump if equal / not equal / less / greater | `if` / `else if` branches |
| `xorq %rax, %rax` | Zero out `%rax` (common trick) | `rax = 0;` |
| `imul`, `idiv` | Integer multiply / divide | `*` and `/` |

---

## Function prologue / epilogue pattern

```asm
pushq  %rbp          # save old base pointer
movq   %rsp, %rbp    # start new stack frame
subq   $16, %rsp     # make space for locals
...                  # body
leave                # mov %rbp, %rsp ; pop %rbp
ret                  # back to caller
```

Recognize this shape; it’s how almost every compiled C function begins/ends.

---

## Registers you’ll spot most

| Register | Typical role (System V x86-64 ABI) |
|----------|------------------------------------|
| `%rax`   | Return value                       |
| `%rdi`, `%rsi`, `%rdx`, `%rcx`, `%r8`, `%r9` | First 6 integer/pointer arguments |
| `%rbp`   | Base pointer (frame pointer)       |
| `%rsp`   | Stack pointer                      |

---

### Why bother?

- Helps you decode compiler errors, optimizer “magic,” and debugger output.  
- Makes stack frames, recursion, and calling conventions less mysterious.  
- You’ll see these mnemonics in CS50 Shorts, gdb/lldb, and disassembly views.

*(You don’t need to write assembly—just be able to glance at it and say “ah, that’s a push/mov/call.”)*