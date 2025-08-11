

> **Lecture reference:** [[Lecture 1 - C]]

> **Course:** [[CS50x Harvard]]

---

## **Three equivalent forms**

|**Syntax**|**Reads as**|**What happens**|**Typical use**|
|---|---|---|---|
|counter = counter + 1;|“counter equals counter plus one”|Recalculates the right-hand side and stores it back into counter.|Very explicit; good for beginners or when adding more than 1.|
|counter += 1;|“counter plus-equals one”|**Compound assignment**: adds the value on the right to the variable and assigns the result back.|Saves keystrokes; still clear when adding small constants.|
|counter++;|“counter plus plus”|**Post-increment**: adds 1 to counter. Returns the _old_ value if used inside an expression.|Most common when stepping through loops.|

> Note: ++counter; (pre-increment) also adds 1 but returns the _new_ value. In standalone statements the distinction doesn’t matter; inside expressions it does.
![[Screenshot 2025-07-12 at 13.27.37.png]]

![[Screenshot 2025-07-12 at 13.27.40.png]]

![[Screenshot 2025-07-12 at 13.27.45.png]]


---

### **Which should you choose?**

- Use **counter++** in for loops or when you only need to bump by one.
    
- Use **+= n** when the increment might vary (+= 2, += step).
    
- Use the full **counter = counter + n** form when teaching, reading unfamiliar code, or modifying by a variable (counter + increment).
    

  

All three compile to the same machine instruction when the optimizer is on, so pick the one that maximizes clarity for the reader.