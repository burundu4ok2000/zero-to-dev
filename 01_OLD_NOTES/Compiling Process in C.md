![[Screenshot 2025-07-22 at 10.21.03.png]]


> **Lecture reference:** [[Lecture 2 - Arrays]]  
> **Course:** [[CS50x Harvard]]
> [[How code & algorythm becomes 0 s and 1 s.]]

---

## Big picture

**source code (C) → compiler toolchain → machine code (binary)**

The compiler is really a *pipeline* of smaller steps:

| Stage | What it does | Input → Output | Try it with `clang` |
|-------|---------------|----------------|---------------------|
| Preprocess | Expands `#include`, `#define` (pure text work) | `.c` → expanded C | `clang -E file.c` |
| Compile | Translates C to assembly | expanded C → `.s` | `clang -S file.c` |
| Assemble | Turns assembly into object code | `.s` → `.o` (machine code, but incomplete) | `clang -c file.c` |
| Link | Glues `.o` files + libraries into one executable | many `.o` + libs → program | `clang file.o -o program` (or `make`) |

---

## Mental model

- **Preprocessor:** “copy–paste & find–replace” phase.  
- **Compiler:** “English-like C → low-level assembly.”  
- **Assembler:** “Assembly mnemonics → 0s and 1s.”  
- **Linker:** “Stitch everything together so `main` can call other functions.”

---

## Where errors show up

| Error type | Typical message | Stage | Example cause |
|------------|------------------|-------|---------------|
| Syntax error | “expected ‘;’ before…” | Compile | Bad C syntax |
| Undefined reference | “undefined reference to `foo`” | Link | Forgot to compile/include `foo.c` |
| Macro mishaps | Strange expanded code | Preprocess | Bad `#define` with semicolon/parentheses |
| Missing header | “file.h: No such file or directory” | Preprocess | Wrong path in `#include` |

---

## Why `make` feels magic

`make` just automates those four steps using a **Makefile**. It knows:

- which files changed,
- which commands to run (`clang -c …`, link, etc.),
- when to rebuild.

---

## Quick demo commands

```bash
clang -E hello.c > hello.i        # Preprocessed source
clang -S hello.c                  # Assembly (hello.s)
clang -c hello.c                  # Object code (hello.o)
clang hello.o -o hello            # Link to final executable
```

You rarely need these flags in CS50, but seeing them once makes the black box transparent.

---

## Take-aways

- The “compiler” is a **chain of translators**, not one magic box.  
- Different mistakes surface at different stages—read the error to know *where* you broke it.  
- Understanding the pipeline helps you debug faster and reason about warnings, headers, libraries, and `make`.

---

Assembly code


![[Screenshot 2025-07-22 at 10.53.01.png]]


---

```asm
main:                 # function label
    pushq   %rbp      # save old base pointer
    movq    %rsp, %rbp# start new stack frame
    subq    $16, %rsp # make room for locals
    callq   get_string
    movl    $0, %eax  # return value
    callq   printf
    leave             # tear down stack frame
    ret
```

## How to read this

| Piece                | Meaning                              | Rough C analogy                 |
|----------------------|--------------------------------------|---------------------------------|
| `main:`              | Label / entry point                  | Function name                   |
| `pushq %rbp`         | Push old base pointer on stack       | Save caller’s frame pointer     |
| `movq %rsp, %rbp`    | New base pointer = current stack top | Begin this function’s frame     |
| `subq $16, %rsp`     | Move stack pointer down 16 bytes     | Allocate local variables        |
| `callq get_string`   | Call another function                | `get_string(...);`              |
| `%rax`, `%rdi`, etc. | CPU registers                        | Temps / args / return value     |
| `$16`, `$0`          | Immediate constants                  | Literals in code                |
| `-8(%rbp)`           | Memory at rbp - 8                    | Local variable slot             |
| `leave` / `ret`      | Restore frame, return to caller      | End of function                 |

### Common mnemonics

- `mov` – copy data  
- `add`, `sub`, `imul`, `idiv` – arithmetic  
- `cmp`, `test` – compare / bit-test  
- `jmp`, `je`, `jne`, `jl`, `jg` – jumps for if/else & loops  
- `call`, `ret` – function call / return  
- `push`, `pop` – stack ops

---

You don’t need to write assembly in CS50—just recognize the shape so compiler/linker errors and debugger output make more sense.


![[Screenshot 2025-07-22 at 10.56.36.png]]


![[Screenshot 2025-07-22 at 10.57.10.png]]