

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **What the two quotes mean**

|**Literal form**|**Example**|**Produces**|**Size in bytes**|**Sentinel** '\0' **added?**|
|---|---|---|---|---|
|**Single quotes**|'A'|char (one character)|**1**|**No**|
|**Double quotes**|"A"|**char array** (char[])|**2** ('A' + '\0')|**Yes**|

_Single quotes_ define a **single char value**.

_Double quotes_ define a **string literal** → compiler makes an **array** and appends a null byte (0x00) automatically.

---

## **Why the null byte matters**

- It’s the **sentinel** that tells functions like printf("%s"), strlen, strcpy, etc., where the string ends.
    
- Without it, those functions would read past your data into random memory.
    

---

## **Code comparison**

```
#include <stdio.h>
#include <string.h>

int main(void)
{
    char  c = 'A';    // one byte, no terminator
    char  s[] = "A";  // two bytes: 'A' and '\0'

    printf("c   = '%c' (0x%02X)\n", c,  (unsigned char) c);
    printf("s   = \"%s\"\n", s);
    printf("len = %zu, size = %zu\n",
           strlen(s), sizeof(s));         // 1 vs 2
}
```

_Output_

```
c   = 'A' (0x41)
s   = "A"
len = 1, size = 2
```

---

## **Memory layout of** 

## **"HI!"**

|**Index**|**Byte**|**Hex**|**Comment**|
|---|---|---|---|
|0|H|0x48|visible character|
|1|I|0x49|visible character|
|2|!|0x21|visible character|
|3|'\0'|0x00|**sentinel**|

sizeof("HI!") ⇒ **4** bytes (includes sentinel)

strlen("HI!") ⇒ **3** bytes (visible characters only)

---

## **Quick rules of thumb**

1. **Use single quotes** for individual characters:
    

```
char newline = '\n';
```

1.   
    
2. **Use double quotes** for sequences (strings):
    

```
string greeting = "Hello, world!";
```

2.   
    
3. Always allocate **one extra byte** if you build a string manually:
    

```
char name[5] = {'J', 'o', 'e', 'y', '\0'};
```

3.   
    
4. Never pass a non-terminated buffer to %s or string functions.
    

---

## **Common pitfalls**

- Writing char *p = 'A'; (wrong quotes) → type error.
    
- Forgetting the sentinel when copying chunks of memory.
    
- Using sizeof to get length **after** the array has decayed to char * (pointer size, not string length).
    

---

> **TL;DR**

> **‘…’** = one char.

> **“…”** = char[] **plus** an automatic '\0'.

> That invisible byte is what keeps your strings safe and your prints sane.