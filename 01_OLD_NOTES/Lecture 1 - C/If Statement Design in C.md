> **Lecture reference:** [[Lecture 1 - C]]

> **Course:** [[CS50x Harvard]]

---

## **Comparing the two approaches**

|**Pattern**|**Example code**|**Tests executed per run**|**Pros**|**Cons**|
|---|---|---|---|---|
|**Standalone if × 3**|c\nif (x < y) { … }\nif (x > y) { … }\nif (x == y) { … }\n|Always **3**|• Straightforward to write• Each block is independent|• Wastes CPU cycles after the first true branch• Hides the fact that conditions are mutually exclusive|
|**if … else if … else**|c\nif (x < y) { … }\nelse if (x > y) { … }\nelse { … }\n|**1 – 2** (chain stops once a match is found)|• Short-circuits automatically → faster• Signals exclusivity to future readers|• Slightly more syntax to remember (else if)|

---

## **Scaling up**

  

Need more than three branches? Extend the chain:

```
if (grade >= 90)      { … }
else if (grade >= 80) { … }
else if (grade >= 70) { … }
else                  { … }   // below 70
```

Or switch to a switch statement when checking one discrete variable against many fixed values.

  **grade >= 90**
    
    Read as “grade isgreater than or equal to 90.”
---

### **Quick rules of thumb**

- **Use else if / else** when only **one** branch should run.
    
- **Use separate ifs** when **multiple** branches might all need to run.
    
- For **4 +** options on the _same_ variable, consider a **switch** for readability.
    

---

> **Performance note:** Modern compilers optimize both patterns heavily, but clear intent still matters for maintainability—and prevents accidental double-work in more complex code.