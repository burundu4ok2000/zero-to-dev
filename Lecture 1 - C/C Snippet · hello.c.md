```
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

---

|**Line**|**Element**|**Plain-English meaning**|
|---|---|---|
|**1**|#include <stdio.h>|“Copy-paste the contents of **Standard I/O header** before compiling so we can use functions like printf. #include is a **pre-processor directive** (runs before the compiler).|
|**3**|int|The **return type** of main. An int (integer) exit code gets sent back to the operating system. 0 means “all good.”|
||main|The **entry-point function**. Every C program starts executing here.|
||(void)|“This function takes **no parameters**.” An alternative is (int argc, char *argv[]) for command-line arguments.|
|**4–6**|{ … }|**Function body** — everything inside the braces runs when the program starts.|
|**5**|printf("hello, world\n");|Call the **print formatted** function to send text to the console.|
|• Double quotes = C-string.|||
|• \n = newline.|||
|• Semicolon ; ends the statement.|||
|**(implicit)**|return 0;|The compiler inserts this for you when the function has int return type and execution reaches the closing }.|

---

## **Why each piece matters**

- **#include** gives the compiler prototypes so it knows printf exists and what parameters it expects.
    
- **int main** lets your program communicate success/failure to scripts or the OS.
    
- **void** keeps the signature simple while you’re learning.
    
- **Semicolons** are statement terminators; forget one and the compiler throws an error.
    
- **printf** is your first I/O function — later you’ll meet scanf, file I/O, etc.
    

---

### **Quick compile-run cycle**

```
$ code hello.c   # edit
$ make hello     # compile (CS50 alias for clang …)
$ ./hello        # run → prints "hello, world"
```
[[CS50x Harvard]]
[[Lecture 1 - C]]