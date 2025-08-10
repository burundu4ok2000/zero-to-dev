---
title: Compiling process — from C to machine code
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
atom_idx: 6
status: done
difficulty: easy
date: 2025-08-10
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

![[Screenshot 2025-07-22 at 10.21.03.png]]

---

## Summary
The compiler is not a single monolithic program, but a **toolchain of steps**: preprocessing, compiling, assembling, and linking — each transforming code closer to executable machine code.

## Key Points
- **Compilation** is a multi-step process: not just turning `.c` into `.exe`.
- Each stage has a clear role: text expansion, translation, encoding, linking.
- Different types of **errors** appear in different stages (syntax, link, macro, etc.).
- Tools like `make` wrap these steps automatically.

## Details

### Compilation Stages

| **Stage**     | **What it does**                              | **Input → Output**             | **Command**                      |
|---------------|-----------------------------------------------|-------------------------------|----------------------------------|
| **Preprocess**| Text-level macros & includes                  | `.c` → expanded `.c`          | `clang -E file.c`               |
| **Compile**   | Translates to **assembly**                    | expanded C → `.s`             | `clang -S file.c`               |
| **Assemble**  | Translates assembly into **object code**      | `.s` → `.o`                   | `clang -c file.c`               |
| **Link**      | Links `.o` files and libraries → executable   | `.o` + libs → final binary    | `clang file.o -o program`       |

### Analogy:
- **Preprocessor:** like `copy-paste + find/replace`
- **Compiler:** high-level to **assembly**
- **Assembler:** assembly to **machine code**
- **Linker:** binds all pieces into one runnable file

### Typical errors:
| **Type**               | **Example**                          | **Stage**      |
|------------------------|--------------------------------------|----------------|
| Syntax error           | `expected ‘;’`                       | Compile        |
| Undefined reference    | `undefined reference to 'foo'`       | Link           |
| Macro issues           | Broken expansion                     | Preprocess     |
| Missing header         | `No such file or directory`          | Preprocess     |

## Examples

```bash
clang -E hello.c > hello.i        # Just preprocessing
clang -S hello.c                  # Compile → assembly
clang -c hello.c                  # Assemble → object file
clang hello.o -o hello            # Link → executable
````

## **Why It Matters**

  

Understanding this process:

- Makes debugging **faster** (knowing what broke _where_)
    
- Helps reading **error messages**
    
- Reveals how make works and what it automates
    

  

## **Questions**

- ❓What happens if multiple .o files use the same symbol?
    
- ❓Can you link files written in different languages (e.g., .o from C and Rust)?
    

  

## **Related Concepts**

- [[Preprocessor in C]] – responsible for macros and includes
    
- [[Makefiles and Automation]] – make automates all compile steps
    
- [[Linking and Static Libraries]] – linker errors & how libraries are merged
    
- [[Assembly Basics in x86_64]] – what compiler generates before machine code
    
- [[Compilation Errors in C]] – mapping errors to their stages
    
- [[Stack Frame in Assembly]] – relevant for understanding compiler output
    
- [[Debugging with lldb]] – assembly helps understand stack in debugger
    

  

## **See also**

- [CS50x 2025 – Week 2 (Arrays)](https://cs50.harvard.edu/x/2025/weeks/2/)
    
- [GCC Compilation Pipeline](https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html)
    
- [How compilers work](https://en.wikipedia.org/wiki/Compiler)
    

  

## **Terms**

  

[[compiler]], [[preprocessor]], [[assembler]], [[linker]], [[clang]], [[make]], [[object code]], [[binary]], [[assembly]], [[machine code]]

