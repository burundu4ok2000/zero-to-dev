![[2025-08-01_14-30-08.png]]

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **What argc** and argv mean

| **Name** | **Type**                    | **Purpose**                                                                           |
| -------- | --------------------------- | ------------------------------------------------------------------------------------- |
| argc     | int                         | **A**rgument **c**ount – how many strings the OS passed to your program (always ≥ 1). |
| argv     | string[] (aka char *argv[]) | **A**rgument **v**ector – array of C-strings holding those arguments.                 |

**Example run**

```
$ ./greet David
```

|**Index**|argv[i]|**Value**|
|---|---|---|
|0|argv[0]|"./greet"|
|1|argv[1]|"David"|
|≥ 2|argv[i]|NULL after the last real argument|

---

## **Buggy demo from lecture**

```
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("hello, %s\n", argv[0]);   // prints program name
}
```

```
$ ./greet David
hello, ./greet
```

argv[0] is always the program’s own path, so the greeting is wrong.

---

## **Corrected version**

```
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)                       // expect exactly one name
    {
        printf("hello, %s\n", argv[1]);  // greet the user
    }
    else
    {
        printf("Usage: ./greet <name>\n");
        return 1;                        // non-zero exit code signals error
    }
    return 0;
}
```

```
$ ./greet David
hello, David
```

---

## **Quick rules**

1. **Index 0** is always the program’s path; user input starts at **index 1**.
    
2. Always check argc before reading argv[i] to avoid segmentation faults.
    
3. By convention, argv[argc] == NULL (handy sentinel).
    
4. Convert numeric arguments with atoi, strtol, etc., before using them as numbers.
    
5. In CS50, string is simply typedef char *string; – all standard C string rules apply.
    

---

### **TL;DR**

argc counts the words; argv holds the words. Grab user-supplied values starting at argv[1], and always verify argc first.