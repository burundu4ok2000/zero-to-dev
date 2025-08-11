![[2025-08-01_16-32-16.png]]
  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **Why bother breaking out functions?**

|**Pain point if everything stays in** main|**How a function fixes it**|
|---|---|
|File grows to hundreds of lines → hard to read|Split logic into **named blocks** you can mentally fold away|
|Repeating the same code in multiple spots|Write once, **call** many times|
|Can’t test specific pieces|Unit-test a function in isolation|
|Hard to reason about state|Each call gets its own **parameters / locals**|

---

## **Vocabulary snapshot**

|**Term (rough synonyms)**|**In C context**|
|---|---|
|**Function**|Primary CS50 term|
|**Procedure / Subroutine**|Older languages (Pascal, BASIC)|
|**Method**|Inside a class (C++, Java, Python)|

All describe the idea of a **reusable operation with a name, inputs, and (optionally) a return value**.

---

## **Minimal anatomy**

```
// prototype
int add(int a, int b);

// definition
int add(int a, int b)
{
    return a + b;
}

// call site
int sum = add(2, 3);
```

|**Piece**|**Purpose**|
|---|---|
|**Return type** (int)|What comes back (or void for nothing)|
|**Name** (add)|Verb describing the action|
|**Parameters** (int a, int b)|Local names for incoming data|
|**Body**|The actual algorithm|

---

## **Compiler workflow**

1. **Prototype** (or placement above main) lets the compiler verify calls.
    
2. **Definition** generates machine code.
    
3. **Call** stores return value on the **stack** (or registers) and resumes in main.
    

---

## **Best practices as programs scale**

# very useful!

- One well-named function per conceptual step.
    
- Keep function bodies **≤ 40–50 lines** when possible.
    
- Single responsibility: each function should “do one thing.”
    
- Document with a one-line comment _above_ the prototype.
    

---

### **TL;DR**


Functions turn sprawling main code into small, named, reusable “verbs,” improving readability, testing, and maintenance.
