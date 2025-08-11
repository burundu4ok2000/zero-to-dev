![[Screenshot 2025-07-22 at 11.02.39.png]]

> **Lecture reference:** [[Lecture 2 - Arrays]]  
> **Course:** [[CS50x Harvard]]
> [[How code & algorythm becomes 0 s and 1 s.]]

---

## What happens last

- After preprocessing → compiling → assembling → linking, you end up with **machine code**.  
- Machine code is just **bytes** (often shown as 0s and 1s or hex). The CPU reads these bytes as instructions and data.

---

## Why it looks like gibberish

- Humans think in keywords like `printf` and `for`.  
- CPUs only understand fixed-size bit patterns: opcodes, registers, addresses.  
- So the final file (`a.out`, `hello`, etc.) is unreadable without special tools.

---

## How to peek (optional curiosity)

```bash
# show raw bytes
xxd hello | head

# disassemble back to assembly
objdump -d hello | less     # Linux
otool -tV hello             # macOS
```

These don’t recover your original C, just the assembly that corresponds.

---

## Mental model

1. **C source** → readable to you.  
2. **Assembly** → readable to humans with training.  
3. **Machine code** → readable to the CPU only.

Keep coding at level 1. Levels 2 and 3 are there to help you debug or go deeper later.