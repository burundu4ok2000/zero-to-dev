![[Screenshot 2025-07-15 at 20.47.20.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]

---

## The three pillars CS50 uses to grade code

| Pillar        | What it asks | Typical checks |
|---------------|-------------|----------------|
| **Correctness** | “Does the program do exactly what it should for all valid inputs?” | • Passes all automated tests<br>• Handles corner-cases<br>• No crashes or undefined behaviour |
| **Design**      | “Is the solution well-structured and efficient?” | • Uses functions, loops, and data structures appropriately<br>• Avoids redundant work (e.g., `if-if-if` vs `if-else if-else`)<br>• Chooses clear algorithms over brute force |
| **Style**       | “Is the code readable and consistent?” | • Follows CS50’s `style50` guidelines (indentation, spacing, braces)<br>• Descriptive names (`get_positive_int`, not `gpi`)<br>• Inline comments for non-obvious logic |

---

### How to balance them

1. **Start with correctness** – get a working prototype first.  
2. **Refactor for design** – break code into functions, remove duplication, choose better algorithms.  
3. **Polish the style** – run `style50`, rename variables, add comments.

---

### Why it matters

- A correct but poorly designed program may work today but break tomorrow.  
- A beautifully styled program that produces the wrong answer is useless.  
- CS50 (and real-world code reviews) reward the union of all three.

Aim for **all three pillars** and your code will be not only accepted by the autograder but also admired by future readers—including you.