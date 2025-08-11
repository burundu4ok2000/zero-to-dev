---
title: 
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: ""
atom_idx: 8
status: done
difficulty: easy
date: 2025-08-10
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

![[Screenshot 2025-07-22 at 13.16.16.png]]  
![[Screenshot 2025-07-22 at 13.16.19.png]]

---

## Summary
Capitalizing constant identifiers in C is a **stylistic convention** that signals **immutability**, enhances **readability**, and aligns with long-standing practices in the language.

## Key Points
- Use **ALL_CAPS_WITH_UNDERSCORES** for values that never change.
- Capitalization helps avoid confusing constants with mutable variables.
- This matches the convention used in standard C headers (e.g., `EXIT_SUCCESS`, `INT_MAX`).
- Makes code easier to understand and maintain, especially in large codebases.

## Details
Capitalizing constants is not required by the compiler — it's a **convention**, not syntax. However, it helps you and others reading the code quickly identify values that are not meant to change.

Two common ways to define constants in C:
- `const int N = 3;`
- `#define BUFFER_SIZE 1024`

Both are typically capitalized:
```c
const int N = 3;
#define BUFFER_SIZE 1024
````

Additionally, enums often use the same format:

```
enum { DAYS_IN_WEEK = 7 };
```

This way, constants visually **stand apart** from variables like i, score, or temp, reducing the cognitive load when reading the code.

  

## **Examples**

```
const int N = 3;
#define MAX_USERS 100
enum { DAYS_IN_WEEK = 7 };
```

## **Why It Matters**

- Promotes readability and clarity in large programs.
    
- Aligns your code with widely accepted industry conventions.
    
- Helps prevent bugs by making immutable values stand out.
    

  

## **Questions**

- ❓ Are there exceptions when constants shouldn’t be capitalized?
    
- ❓ Should I always prefer const over #define?
    

  

## **Related Concepts**

- [[const Keyword in C]] – defines immutable variables at compile-time.
    
- [[#define Macro]] – preprocessor directive for defining constants.
    
- [[Enum Type in C]] – often uses capitalized constant members.
    
- [[C Coding Style]] – explains broader style guidelines like indentation, naming.
    
- [[Variable Scope and Lifetime in C]] – relates to how long constants and variables live.
    
- [[Function Naming Conventions]] – how naming helps readability overall.
    

  

## **See also**

- [CS50 Style Guide](https://cs50.readthedocs.io/style/c/)
    
- [Wikipedia: Naming conventions (programming)](https://en.wikipedia.org/wiki/Naming_convention_\(programming\))
    
- [Google C++ Style Guide on Naming](https://google.github.io/styleguide/cppguide.html#Constant_Names)
    

  

## **Terms**

  

[[const Keyword in C]], [[#define Macro]], [[Enum Type in C]], [[Immutable]], [[C Coding Style]], [[Naming Conventions]]
