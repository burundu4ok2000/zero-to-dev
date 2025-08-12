---
title: Vocabulary · SENTINEL
status: in-progress
date: 2025-08-12
source: "#course/cs50x/intoduction_to_CS"
review_next: 2025-09-12
---

## 📖 Definition  
**SENTINEL** *(noun, in programming)* — a **special value used to signal the end of a data set, loop, or process**.  
It’s not actual data, but a **marker** that says, “stop here” or “this is the boundary.”

| Context | Meaning | Example Sentence |
|---------|---------|------------------|
| Programming | a marker or flag value | *We used -1 as a **sentinel** to stop user input.* |
| Memory / Pointers | guard value to prevent overflow or invalid access | *A **sentinel** node prevents null-pointer exceptions.* |
| General English | a guard or lookout | *A **sentinel** stood at the gate.* |

---

### 🔊 Pronunciation  
/ˈsɛn.tɪ.nəl/ → **SEN-tuh-nl**

---

## 🟰 Synonyms (in code context)  
stop value · guard · marker · terminator · end flag  

---

## 📝 Quick Note  
In programming, **sentinels** simplify loops and memory safety.  
They are especially useful in:

- `while` loops that run until a special value is entered  
- Linked lists (sentinel nodes instead of null)  
- Input validation systems  

### 🧠 Example in C  
```c
int number;
while (number != -1)
{
    // process number
    scanf("%d", &number);
}