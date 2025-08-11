![[Screenshot 2025-07-23 at 15.57.53.png]]

  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **Key idea**

  

A C string is a **char array that ends with an extra byte '\0' (null terminator)**.

That sentinel marks “end of text” for functions like printf, strlen, etc.

---

## **Memory layout example**

  

"HI!" actually needs **4 bytes**:

|**Index**|**Name**|**Char**|**ASCII (hex)**|**Binary**|
|---|---|---|---|---|
|0|s[0]|H|0x48|01001000|
|1|s[1]|I|0x49|01001001|
|2|s[2]|!|0x21|00100001|
|3|s[3]|'\0'|0x00|00000000|

> That last cell is the “invisible” byte David is pointing at in the lecture.

---

## **Why the extra byte matters**

- String-handling functions keep reading memory until they hit '\0'.
    
- Forgetting to terminate (or overwriting '\0') → garbage output or crashes.
    
- **sizeof**("HI!") → **4** (includes '\0')
    
    **strlen**("HI!") → **3** (counts visible characters only)
    

---

## **Code demo**

```
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "HI!";

    printf("strlen(s): %zu\n", strlen(s));   // 3
    printf("sizeof(s): %zu\n", sizeof(s));   // 4 (includes '\0')

    // Show each byte
    for (int i = 0; i < sizeof(s); i++)
    {
        printf("s[%d] = '%c' (0x%02X)\n", i,
               s[i] ? s[i] : '\\0', (unsigned char) s[i]);
    }
}
```

Output (conceptually):

```
strlen(s): 3
sizeof(s): 4
s[0] = 'H' (0x48)
s[1] = 'I' (0x49)
s[2] = '!' (0x21)
s[3] = '\0' (0x00)
```

---

## **Quick rules to remember**

- Always budget **one extra byte** for '\0' when allocating strings.
    
- Never rely on array size inside a function to find string length—use strlen.
    
- Don’t print raw buffers with %s unless you guarantee they’re null-terminated.
    
- string in CS50 is just typedef char *string; — still ends with '\0'.
    

---

## **Visual mnemonic**

![[Screenshot 2025-07-23 at 16.08.13.png]]

```
"H"  "I"  "!"  "\0"
s[0] s[1] s[2] s[3]
```

That last box is empty-looking—but it’s the most important one. 😉

---

**And futher it comes garbage values**

![[Screenshot 2025-07-23 at 16.10.39.png]]


---
