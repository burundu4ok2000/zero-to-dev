  

> **Lecture reference:** [[Lecture 1 - C]]

> **Course:** [[CS50x Harvard]]

---

## **Operator cheat-sheet with pronunciation**

|**Symbol**|**Spoken name**|**Meaning**|**True when…**|**Example**|
|---|---|---|---|---|
|=|**equals** / **assignment**|assignment operator (⚠️ not a comparison)|value on right is stored in variable on left|x = 5;|
|<|**less-than**|comparison|left < right|x < y|
|<=|**less-than-or-equal**|comparison|left ≤ right|x <= y|
|>|**greater-than**|comparison|left > right|x > y|
|>=|**greater-than-or-equal**|comparison|left ≥ right|x >= y|
|==|**double equals** / **equals equals**|equality test|left == right|x == y|
|!=|**bang equals** / **not equals**|inequality test|left ≠ right|x != y|

> **Bang?** In programmer slang, the exclamation mark (!) is called **“bang.”** So != is read aloud as “bang equals,” meaning _not equal_.
![[Screenshot 2025-07-12 at 13.15.33.png]]
---

### **Key reminders**

- = vs == : one assigns, two compares. Mixing them causes subtle bugs.
    
- Every comparison evaluates to 1 (**true**) or 0 (**false**), perfect for if, while, or ternary expressions.
    
- Chain comparisons with logical operators: && (and), || (or), ! (not).
    

---

### **Minimal demo**

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    if (x != y)
    {
        printf("x and y are different\n");
    }
    else if (x == y)
    {
        printf("x and y are equal\n");
    }
}
```

These operators form the backbone of decision-making in C.