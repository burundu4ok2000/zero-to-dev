
![[2025-07-30_16-38-52.png]]
  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **Example pattern**

```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");

    // Declare two variables in the *initialization* clause
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
```

---

## **What’s happening inside** 

## **for ( … ; … ; … )**

|**Clause**|**Code**|**Runs when?**|**Purpose**|
|---|---|---|---|
|**Initialization**|int i = 0, n = strlen(s)|**Once**, before first test|Set counter i, _cache_ length n|
|**Condition**|i < n|Before **each** loop iteration|Decide whether to keep looping|
|**Increment**|i++|After **each** iteration|Move to next character|

- By computing n = strlen(s) **once**, we avoid calling strlen on every pass.
    
- i and n are **block-scoped** to the loop; they disappear after the loop ends.
    

---

## **Syntax rules for multiple initializers**

```
for (type var1 = value1, var2 = value2;  condition;  increment)
```

- Separate declarations with commas.
    
- All variables must be of the **same type** (here, int).
    
- You can still use a single expression in the increment clause (i++).
    

---

## **Why it matters**

|**Benefit**|**Reason**|
|---|---|
|**Efficiency**|strlen walks the whole string; calling it once is O(n), calling it each iteration would make the loop O(n²).|
|**Clarity**|n names the string length explicitly—readers see the loop bounds at a glance.|
|**Energy**|Fewer CPU cycles = less “wasted computer energy,” especially for long strings.|

---

## **Common pitfalls**

1. **Different types** → int i = 0, size_t n = … is _illegal_ in a single init list.
    
2. **Accidentally modifying n** inside the loop—keep it read-only unless you mean to change the bound.
    
3. **Forgetting block scope**—i and n are not visible after the loop.
    

---

## **Quick takeaway**

- The for initialization clause can declare **multiple variables**—great for “one-time” setup like caching a string’s length.
    
- Do work **once** up front, loop over data efficiently, and keep your code tidy.