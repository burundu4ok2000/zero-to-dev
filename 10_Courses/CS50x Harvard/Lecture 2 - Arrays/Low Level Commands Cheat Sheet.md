---
title: Low Level Commands Cheat Sheet
lang_tags: "#lang/c"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: ""
atom_idx: 14
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---
![[Screenshot 2025-07-22 at 10.58.30.png]]


---

## Common Commands / Syntax

Assembly on x86-64 uses terse **\mnemonics\** and explicit **\operands\**. Operand order is usually **src, dst**.

- **Immediate**: `$42` means a literal constant (**\immediate\**).
- **Memory addressing**: `-8(%rbp)` means memory at address `rbp - 8` (a local on the **\stack\**).
- **Registers** are prefixed with `%`: `%rax`, `%rbp`, `%rsp` (aka **\general-purpose register\**, **\frame pointer\**, **\stack pointer\**).
- **Comments** start with `#`.

### Frequent mnemonics

| Instruction | Plain English | Typical C concept |
|-------------|----------------|-------------------|
| `pushq X`   | Put X on the **\stack\** | Save something for later |
| `popq X`    | Pop top of **\stack\** into X | Restore saved value |
| `movq A, B` | Copy A into B | Assignment `B = A;` |
| `subq $N, %rsp` | Move **\stack pointer\** down N bytes | Allocate locals |
| `addq $N, %rsp` | Move **\stack pointer\** up N bytes | Free locals |
| `callq foo` | Jump to function `foo`, remember return point | Function call |
| `ret`       | Return to caller | `return …;` |
| `cmpq A, B` | Compare B with A (sets **\flags\**) | `if (B ? A)` |
| `jmp label` | Unconditional jump | `goto` / loop jump |
| `je`, `jne`, `jl`, `jg` | Conditional jumps | `if` / `else if` branches |
| `xorq %rax, %rax` | Zero `%rax` (idiom) | `rax = 0;` |
| `imul`, `idiv` | Integer multiply / divide | `*` and `/` |

---

## Patterns

### Function prologue / epilogue

```asm
pushq  %rbp          # save old base pointer
movq   %rsp, %rbp    # start new stack frame
...                  # body
leave                # mov %rbp, %rsp ; pop %rbp
ret                  # back to caller
```

This is the standard **\prologue\**/**\epilogue\** pattern the compiler emits for a C **\function\**.

### Argument registers (System V x86-64 **\ABI\**)

| Order | Register |
|------:|----------|
| 1–6   | `%rdi`, `%rsi`, `%rdx`, `%rcx`, `%r8`, `%r9` |
| Ret   | `%rax` |

Spills beyond six go to the **\stack\**.

---

## Tips

- Read disassembly top–down: spot the prologue, then **\calls\**, then jumps.
- Map `%rdi/%rsi/...` to your function parameters; `%rax` is the return.
- Zeroing with `xorq %reg, %reg` is a common **\peephole optimization\** idiom.
- Don’t panic at noise from **\compiler optimization\**; look for shape, not exact 1:1 with your C.

---

## Examples

A minimal `main` often looks like:

```asm
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    callq   get_string
    movl    $0, %eax
    callq   printf
    leave
    ret
```

You don’t need to write assembly; you just need to glance and say: prologue → work → calls → **\return\**.

---

## Related Concepts
- [[Compiling Process in C]] – Connects **\C\** source to **\assembly\** via the toolchain.
- [[Command Line Flags Cheat Sheet]] – Flags to make the compiler/linker emit assembly or symbols.
- [[Registers in x86-64]] – Names/roles of general-purpose registers.
- [[Function Call Stack (C/x86-64)]] – How **\stack frames\** are laid out.
- [[Calling Convention (System V x86-64)]] – Register passing and caller/callee-saved rules.

## See Also

- [[Assembly code]]
- [x86-64 System V ABI (official PDF)](https://refspecs.linuxfoundation.org/elf/x86_64-abi-0.99.pdf)
- [Intel® 64 and IA-32 SDM (Vol. 1–3)](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)
- [x86-64 Assembly Cheat Sheet (Berkeley CS61C)](https://inst.eecs.berkeley.edu/~cs61c/fa20/img/cheat-sheet)

## Terms

[[assembly]], [[mnemonic]], [[operand]], [[immediate]], [[stack]], [[register]], [[frame pointer]], [[stack pointer]], [[flags]], [[prologue]], [[epilogue]], [[function]], [[ABI]], [[peephole optimization]], [[calling convention]], [[stack frame]], [[disassembly]], [[return]], [[compiler optimization]]
