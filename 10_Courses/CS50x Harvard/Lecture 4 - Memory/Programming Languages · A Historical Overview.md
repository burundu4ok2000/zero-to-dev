---
title: "Programming Languages · A Historical Overview"  
lang_tags: "#lang/c, #lang/cpp, #lang/csharp, #lang/python, #lang/java, #lang/javascript, #lang/assembly"                                    
type_tags: "#type/lecture"                                    
course_tags: "#course/cs50x/intoduction_to_CS"                                    
lecture_tags: "#lecture/week_4_Memory"                                    
tool_tags: ""                                            
atom_idx: 12                                           
status: "done"                                                
difficulty: "easy"                                            
date: "2025-08-22"                              
timecode: "00:45:00"                                           
source: "https://cs50.harvard.edu/x/2025/weeks/4/"                              
review_next: "2025-09-22"                                       
---

## Summary

This is a **big-picture overview** of how programming languages evolved from **Assembly and C** to modern high-level languages like **Python**, **Java**, **C#**, and **JavaScript**.

We look at the **core ideas**, **historical roots**, and how they differ in memory, syntax, abstraction, and use cases.

---

## 🧬 Language Family Tree (Simplified)

```
               Assembly
                   ↓
                 C (1972)
                /   \
           C++ (1983)  Python (1991)
              |          |
           Java (1995)  JavaScript (1995)
              |
            C# (2000)
```

---

## Assembly (1940s+)

- **Closest to machine code**
- Works directly with **registers, memory addresses, instructions**
- Extremely fast and dangerous
- **No abstractions**: just MOV, ADD, JMP
- Still used in:
  - Embedded systems
  - OS kernels
  - Bootloaders
  - Performance-critical code

> ⚙️ Assembly = manual gear shift for CPUs.

---

## C (1972)

- Designed for **system programming** (Unix)
- **Low-level but portable** (across CPUs)
- Gives full control: **pointers, manual memory, structs**
- Used in:
  - Operating Systems
  - Compilers
  - Embedded Devices
  - Databases

> 🔥 C = “portable Assembly” — fast, flexible, minimal.

---

## C++ (1983)

- Adds **object-oriented programming (OOP)** to C
- Supports:
  - Classes, Inheritance
  - Templates (generics)
  - RAII memory management
- Still used in:
  - Game engines (Unreal Engine)
  - GUI toolkits (Qt)
  - Performance-critical libraries

> 🧠 C++ = C + Abstractions + More Control + More Headache

---

## Python (1991)

- High-level, **interpreted**, and **dynamically typed**
- Focus on **readability** and **productivity**
- Built on top of C (CPython)
- Used in:
  - Data science, ML, AI
  - Web backends
  - Automation and scripting
  - Education

> 🐍 Python = C’s friendly face for humans.

---

## Java (1995)

- **Compiled** into **bytecode** → runs on the **JVM**
- Strongly typed, **OOP-heavy**
- Manages memory via **garbage collector**
- Runs on any OS (Write Once, Run Anywhere)
- Used in:
  - Enterprise apps
  - Android development
  - Backend systems

> ☕ Java = structured, portable, verbose but reliable.

---

## JavaScript (1995)

- Originally for **web browsers**
- Runs in every browser via JS engine (V8, SpiderMonkey)
- Dynamic, event-driven, functional and OO features
- Now used **outside browsers** via **Node.js**
- Powering:
  - Web frontends
  - APIs
  - Full-stack apps

> 🌐 JavaScript = glue of the web.

---

## C# (2000)

- Developed by Microsoft as a **.NET answer to Java**
- OOP + strong typing + syntax from C/C++
- Used in:
  - Desktop apps (Windows)
  - Unity game development
  - Web apps (ASP.NET)
  - Enterprise tools

> 🎯 C# = Java with Microsoft polish.

---

## Other Languages (Honorable Mentions)

- **Go (2009)**: Simplicity + concurrency (Goroutines), great for cloud/server.
- **Rust (2010)**: Modern alternative to C++, with **memory safety guarantees**.
- **Swift (2014)**: Apple’s modern language for iOS/macOS, fast and safe.
- **Ruby (1995)**: Web dev via Rails, very expressive but slower.
- **PHP (1995)**: Powering ~70% of websites, good for server-side rendering.

---

## Related Concepts

- [[Pointers in C — Address-of (&) and Dereference (*)]]
- [[Why 1 Byte = 8 Bits (History & Logic)]]
- [[How Strings Are Stored · Low vs High Level]]
- [[Memory Layout of a Program]]
- [[Compilation vs Interpretation]]
- [[From High-Level to Low-Level: Real-World Development Workflow]]
- [[ASCII and Character Encodings]]

## See Also

- [History of Programming Languages (Wikipedia)](https://en.wikipedia.org/wiki/History_of_programming_languages)
- [C Family Tree – GitHub](https://github.com/oz123/c-family-tree)
- [Why Learn C First? – CS50 Discussion](https://cs50.harvard.edu/x/2025/notes/1/)

## Terms

[[assembly language]], [[C]], [[C++]], [[C#]], [[python]], [[java]], [[javascript]], [[compilation]], [[bytecode]], [[garbage collector]], [[JVM]], [[interpreter]], [[object-oriented programming]], [[memory management]]
