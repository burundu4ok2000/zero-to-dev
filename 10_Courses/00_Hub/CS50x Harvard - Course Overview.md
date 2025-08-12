---
title: "CS50x Harvard - Course Overview"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_Scratch"
tool_tags: ""
atom_idx: 01
status: "in-progress"
difficulty: "easy"
date: "2025-08-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/"
review_next: "2025-09-12"
---

![[Screenshot 2025-07-15 at 20.47.20.png]]

---

## Summary
High-level orientation to **CS50x**: course structure, weekly topics, how **problem sets** build skill, and the core habits you’ll practice—**abstraction**, **algorithms**, **data structures**, **memory** management, and **web** fundamentals.

## Key Points
- The course is project-driven: each week ends with a graded **problem set (PSet)** that reinforces the week’s concepts.
- Early weeks emphasize **C**, **compilation**, **debugging**, and **time complexity**; later weeks shift to **Python**, **SQL**, and **web**.
- You’ll use a browser IDE (**VS Code** in **Codespaces**) with the CS50 toolchain; local dev comes later if you want it.
- Evaluation values **correctness**, **design**, **style**, and **reasonable time spent**. Avoid copying; cultivate your own **debugging** workflow.
- The mindset: think in **APIs**, treat functions as **black boxes**, and iterate—**make it work**, then **make it right**, then **make it fast**.

## Details
### Weekly map (you’ll refine links as notes grow)
- **Week 0 — Scratch:** **algorithmic thinking**, loops, conditions without syntax overhead.
- **Week 1 — C:** **types**, **operators**, **control flow**, **functions**, **compilation pipeline** (`preprocess → compile → assemble → link`).
- **Week 2 — Arrays & Strings:** **arrays**, **pointers**, **C-strings**, CLI args, **debugging** with `printf`/**LLDB**.
- **Week 3 — Algorithms:** **asymptotic analysis**, **search**/**sort** (linear, binary, selection, bubble, merge). 
- **Week 4 — Memory:** **stack vs heap**, **pointers**, **malloc/free**, **valgrind**/**sanitizers**.
- **Week 5 — Data Structures:** **structs**, **linked lists**, **hash tables**, **tries**, **stacks/queues**.
- **Week 6 — Python:** scripting, I/O, **OOP** basics, batteries‑included standard library.
- **Week 7 — SQL:** modeling data, **SELECT/WHERE/JOIN**, **indexes**, transactions.
- **Week 8 — HTML/CSS/JS:** the **DOM**, events, basic **frontend**.
- **Week 9 — Flask:** routes, templates, sessions, auth patterns.
- **Week 10 — Final Project:** scope, iterate, present.

### Tooling & workflow
- **IDE**: CS50 **Codespaces** (browser **VS Code**), git push to **GitHub**.
- **Build/Run C**: `clang -o app app.c` → `./app`; use flags like `-Wall -Werror -g -std=c11`.
- **Debugging**: **rubber duck**, `printf`, **LLDB**, then **valgrind** for leaks/UB in C.
- **Style**: consistent naming, **constants** in ALL_CAPS, small **functions**, no **magic numbers**.

### How to study effectively
- First pass: **pseudocode** your approach; second pass: implement minimal **working** version.
- Keep a **scratchpad** of failures and fixes. Track runtime/memory hypotheses vs. measurements.
- Iterate with **tests** (tiny inputs → edge cases → random data). Prefer **deterministic** behavior.

## Examples
### C compile/run quickstart
```bash
clang -Wall -Werror -std=c11 -g -o hello hello.c
./hello
# if it crashes → run in lldb
lldb ./hello
```
### Tiny C demo (argv count guard)
```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: %s name\n", argv[0]);
        return 1; // non‑zero → error
    }
    printf("hello, %s\n", argv[1]);
    return 0; // success
}
```

## **Why It Matters**
CS50x builds mental models that transfer: once you get **pointers**, **time complexity**, and **data modeling**, you can switch languages and stacks with far less friction. It’s training in **thinking like an engineer**: decompose, design clear **interfaces**, measure, and iterate.

## Questions
- ❓Where should I log **time spent** and blockers per PSet (Dataview table? separate **work log** note)?
- ❓What’s the minimal **debugging** ritual I’ll practice every time (repro steps → hypothesis → instrument → fix)?
- ❓Which **final project** ideas align with my Data Engineering track (ETL, API ingestion, analytics app)?

## Related Concepts

- [[Black Box Abstraction]] – Treating **functions/APIs** as contracts; swapping implementations safely.
- [[Compilation Pipeline in C]] – From **preprocessing** to **linking**; where warnings/errors arise.
- [[Stack vs Heap Memory]] – Function frames vs. dynamic allocation; lifetimes and pitfalls.
- [[Big-O Notation Basics]] – Reasoning about **time/space** growth to compare designs.

## See also
- [CS50x 2025 — Official site](https://cs50.harvard.edu/x/2025/)
- [CS50 2025 — YouTube Lectures](https://www.youtube.com/@cs50)
- [CS50 Library (cs50.h) docs](https://manual.cs50.io/)

## Terms
[[Problem Set]], [[Abstraction]], [[Algorithm]], [[Time Complexity]], [[Compilation]], [[Pointer]], [[Data Structure]], [[Stack]], [[Heap]], [[Debugger]], [[IDE]], [[Valgrind]], [[Sanitizer]], [[Big-O]], [[Linked List]], [[Hash Table]]
