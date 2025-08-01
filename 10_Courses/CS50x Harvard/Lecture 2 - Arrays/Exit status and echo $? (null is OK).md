![[2025-08-01_15-07-54.png]]


> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---



Every Unix command finishes with an **exit status** (a number 0–255).

- 0  → **success**
    
- 1–255 → **error / special condition**
    

  

The shell stores that number in the variable $?.

Printing it with echo $? lets you inspect what just happened.

---

### **Demo program (status.c)**

```
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;                 // error code
    }

    printf("hello, %s\n", argv[1]);
    return 0;                     // success
}
```

---

### **Sample runs**

```
$ ./status David
hello, David
$ echo $?
0              ← program returned 0 (success)
```

```
$ ./status
Missing command-line argument
$ echo $?
1              ← program returned 1 (our error code)
```

---

## **When to set non-zero codes**

|**Code**|**Conventional meaning**|**Typical use case**|
|---|---|---|
|1|Generic error|Wrong args, file not found, etc.|
|2|Misuse of shell built-in (per Bash docs)|Invalid option parsing|
|126|Command invoked but **not executable**|File isn’t marked executable|
|127|**Command not found**|Typos in program name|
|130|Script terminated by Ctrl-C (SIGINT)|User interruption|
|≥ 128|Exit due to **signal** (128 + n)|e.g. 137 = killed by SIGKILL|

> **Rule of thumb:**

- > Return **0** when the program does what it’s supposed to.
    
- > Return **non-zero** when something went wrong so scripts can react.
    

---

## **Quick checklist**

1. **Validate input** early; decide on an exit code.
    
2. **return** that code from main (or exit(code)).
    
3. Use echo $? for quick debugging:
    

```
make && ./myprog arg1 arg2
echo $?   # was it successful?
```

3.   
    
4. In Bash scripts, test with if.
    

```
./myprog "$@" || echo "failed!"
```

  

---

### **TL;DR**

- Your C program’s return value becomes the shell’s $?.
    
- 0 = OK, anything else = problem.
    
- Check it on the command line with **echo $?** to know what happened.