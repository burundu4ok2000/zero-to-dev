![[2025-07-30_16-21-42.png]]

  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **Example program (**

## **length.c**

## **)**

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    int n = 0;
    while (name[n] != '\0')   // walk until sentinel
    {
        n++;
    }
    printf("%i\n", n);
}
```

---

## **How it works**

|**Step**|**What happens**|**Comment**|
|---|---|---|
|1|Prompt user for a **string**|get_string returns a null-terminated char *|
|2|int n = 0;|n will track the current **index**|
|3|while (name[n] != '\0')|Loop until the **null terminator** is found|
|4|n++;|Move to next character|
|5|After loop, n equals **number of visible chars**|Print the result|

---

## **Visual trace (input** 

## **"Harry"**

## **)**

|n|name[n]|**Condition**|**Action**|
|---|---|---|---|
|0|'H'|not '\0'|n = 1|
|1|'a'|not '\0'|n = 2|
|2|'r'|not '\0'|n = 3|
|3|'r'|not '\0'|n = 4|
|4|'y'|not '\0'|n = 5|
|5|'\0'|loop ends|print 5|

---

## **Key points**

- **Indexing**: name[n] accesses the _n-th_ character of the string.
    
- **Sentinel**: '\0' marks the end; loop stops right before it.
    
- **Time complexity**: O(length) — visits each byte exactly once.
    
- Works for any input, including the empty string (n stays 0).
    

---

## **Why write this yourself?**

- Illustrates how library functions like strlen operate under the hood.
    
- Reinforces understanding of arrays, pointers, and the null terminator.
    
- Lets you add custom logic (e.g., skip spaces, count vowels, etc.).
    

---

## **Built-in alternative**

```
#include <string.h>
int len = strlen(name);   // Returns same value as manual loop
```

strlen does the same walk internally, but you should still know _why_ it works.

---

## **Common mistakes to avoid**

1. **Using <=** in a loop condition — will count the '\0' byte.
    
2. **Forgetting** that strlen returns size_t, not int.
    
3. **Mixing up** sizeof(name) (pointer size after decay) vs. real length.