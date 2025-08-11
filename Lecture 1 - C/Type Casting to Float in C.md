![[Screenshot 2025-07-17 at 11.38.16.png]]

> **Lecture reference:** [[Lecture 1 - C]]  
> **Course:** [[CS50x Harvard]]

---

## Problem

```c
int x = 1;
int y = 3;
printf("%i\n", x / y);   // prints 0   (integer division)
```

Both operands are `int`, so `x / y` performs **integer division**, discarding the fractional part.

---

## Solution — cast one operand

```c
int x = get_int("x: ");
int y = get_int("y: ");

printf("%f\n", (float) x / y);   // prints 0.333333
```

### Why it works

1. `(float) x` converts `x` from `int` to `float`.  
2. C promotes `y` to `float` automatically.  
3. Division now happens in **floating-point**, preserving decimals.  
4. `%f` prints the resulting floating value.

---

## Quick tips

- **Force floating-point division:** cast *one* operand: `(float) x / y` or `(double) x / y`.  
- **Limit decimals:** `printf("%.2f\n", value);`  
- **Long formulas:** cast the first term once: `(float) x / y / z` (no need to cast every operand).

---

### Common pitfalls

* Forgetting to change the format specifier: `%i`/`%d` prints an int; `%f` prints a float/double.  
* Casting **after** division (`(float)(x / y)`) still does integer division first—too late! Cast **before**.

---

## **📌 Why this line looks like that:**

```
printf("%f\n", (float) x / y);
```

---

### **✅ What it does:**

  

It prints the result of the division x / y, but **forces the result to be a floating-point number**, not an integer.

---

### **🔍 Step-by-step breakdown:**

  

#### **1.** 

#### **printf("%f\n", ...)**

- printf is a function to print output to the terminal.
    
- "%f\n" means:
    
    - %f expects a float (floating-point number).
        
    - \n is a newline character (moves cursor to next line).
        
    

  

#### **2.** 

#### **(float) x**

- This is **type casting**.
    
- Converts the integer x into a float.
    
- Why? Because:
    
    - In C, int / int results in an int (e.g., 1 / 3 becomes 0).
        
    - But float / int will produce a float (e.g., 1.0 / 3 → 0.3333).
        
    

  

#### **3.** 

#### **(float) x / y**

- Only **one operand** needs to be cast to float.
    
- So this becomes a **floating-point division**, even if y is still an integer.
    

  

#### **4. Final result**

- printf receives the result (a float), and %f formats it correctly.
    
- Output example: 0.333333
    

---

### **✅ Summary:**

- int / int → integer division.
    
- (float) int / int → floating-point division.
    
- %f tells printf to format the output as a float.
    

---

### **🧠 Quick tips**

|**Task**|**Do this**|
|---|---|
|Force floating-point division|Cast one operand: (float), (double)|
|Limit decimals to two places|printf("%.2f\n", value);|
|Avoid cast repetition in long math|Cast the first term: (float) x / y / z|

---

Let me know if you’d like to add diagrams or examples in Russian too!