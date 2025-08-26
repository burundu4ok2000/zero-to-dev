---
title: Programming Languages Overview · Low vs High Level
lang_tags: ""
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: "17"
status: done
difficulty: medium
date: 2025-08-22
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/4/
review_next: 2025-09-22
---

## Summary

🧬 **Иерархия языков программирования** (упрощённо):

1. **Machine code** — нули и единицы, инструкции процессора напрямую
2. **Assembly** — мнемоники вроде `MOV`, `ADD`; близко к железу
3. **Low-level (C, Rust)** — контроль над памятью, ручная работа с указателями
4. **Mid-level (C++, Go)** — частичный контроль, но с абстракциями
5. **High-level (Python, Java, JS)** — читаемо, но далеко от железа

## The Big Idea

- **Низкоуровневые языки** дают прямой доступ к памяти и железу. Они сложнее, но позволяют точный контроль (оптимизация, безопасность, драйверы, ядро).
- **Высокоуровневые языки** скрывают детали. Их проще учить, они удобны для бизнес-логики, веба и автоматизации.
- **Язык не “лучше” или “хуже” — у каждого своя ниша.**

## Key Points

- C даёт контроль над памятью через **указатели**, **malloc**, **free**.
- Python управляет памятью автоматически (через **garbage collector**).
- Assembly нужен, когда важна скорость и размер (встроенные системы).
- Java — строго типизирован, компилируется в **байткод** (работает в JVM).
- JavaScript — выполняется в браузере, асинхронный по природе.
- Rust даёт контроль, но без утечек памяти (через ownership/borrow checker).

## Languages Breakdown

| Language      | Level       | Manual Memory? | Main Use                            |
|---------------|-------------|----------------|-------------------------------------|
| Machine code  | 0 (binary)  | Yes            | CPU instructions                    |
| Assembly      | 1           | Yes            | Embedded, microcontrollers          |
| C             | 2           | Yes            | OS kernels, system tools            |
| C++           | 3           | Partly         | Games, engines, perf-critical apps  |
| Rust          | 3           | Yes (safe)     | Systems programming                 |
| Go            | 3           | No             | Servers, concurrency                |
| Java          | 4           | No             | Cross-platform apps (JVM)           |
| Python        | 5           | No             | Scripts, AI, automation             |
| JavaScript    | 5           | No             | Web, front-end                      |

## Examples

### C (low-level)
```c
int *p = malloc(sizeof(int));
*p = 42;
free(p);
```

### Python (high-level)
```python
x = 42  # memory managed by interpreter
```

## Related Concepts

- [[What is a Memory Leak? · Causes, Consequences, Prevention]] – manual memory requires cleanup
- [[Pointers in C — Address-of (&) and Dereference (*)]] – foundation of low-level control
- [[Garbage Values and Crashes in C]] – risk in low-level if memory uninitialized
- [[Valgrind for CS50 · Detecting Memory Leaks and Invalid Access]] – debugging memory issues in C
- [[malloc and free in C — Dynamic Memory Allocation]] – key tools for low-level programming
- [[How Strings Are Stored · Low vs High Level]] – string handling differs a lot across levels
- [[Hexadecimal Notation]] – often used for addressing in low-level code
- [[Why 1 Byte = 8 Bits (History & Logic)]] – hardware conventions that affect language design

## See Also

- [Programming languages classification (Wikipedia)](https://en.wikipedia.org/wiki/Programming_language_classification)
- [Low vs High level languages (GeeksForGeeks)](https://www.geeksforgeeks.org/difference-between-high-level-and-low-level-language/)
- [Assembly vs C vs Python (YouTube)](https://www.youtube.com/watch?v=QzhlfbG6icY)

## Terms

[[assembly]], [[machine code]], [[high-level language]], [[low-level language]], [[garbage collector]], [[pointer]], [[malloc]], [[free]], [[memory management]], [[virtual machine]], [[JVM]], [[interpreter]], [[compiled language]]
