
![[Screenshot 2025-07-22 at 11.54.49.png]]


> Lecture reference: [[Lecture 2 - Arrays]]  
> Course: [[CS50x Harvard]]
> [[Char Type in C]]


---

## Typical sizes on CS50’s 64-bit Linux

| Type   | sizeof(...)        | Stores / notes                                    |
| ------ | ----------------- | ------------------------------------------------- |
| bool   | 1 by               | 0 or 1 (from `<stdbool.h>`)                       |
| char   | 1 b                | One ASCII character                               |
| int    | 4 b                | Integer (~ −2.1B … 2.1B)                          |
| long   | 8                  | Bigger integer (platform dependent)               |
| float  | 4           s      | ~7 decimal digits (IEEE-754 single)               |
| double |            es      | ~15–16 digits (IEEE-754 double)                   |
|  8 bytes + ? bytes tes + ?  | Pointer (`char *`) to first character of the text |

> `string` is a CS50 typedef for `char *`. The pointer is 8 bytes; the characters it points to take 1 byte each plus the `'\0'` terminator.

---

## Check your platform

```c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    printf("bool:   %zu\n", sizeof(bool));
    printf("char:   %zu\n", sizeof(char));
    printf("int:    %zu\n", sizeof(int));
    printf("long:   %zu\n", sizeof(long));
    printf("float:  %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    printf("char *: %zu\n", sizeof(char *));
}