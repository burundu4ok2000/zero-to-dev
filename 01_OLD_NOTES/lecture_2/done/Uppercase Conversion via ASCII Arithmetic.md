
![[2025-07-30_16-49-01.png]]
  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **Program (uppercase.c )**

```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    // Cache length once
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // Convert lowercase → uppercase
            printf("%c", s[i] - ('a' - 'A'));
        }
        else
        {
            // Already uppercase (or not a letter)
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```

i may use 32 instead of ('a' - 'A') because ASCII difference  capital A letter and lowercase A letter

---

## **How the logic works**

|**Part of code**|**Purpose**|**Detail**|
|---|---|---|
|for (int i = 0, n = strlen(s); … )|Iterates once per character while **caching** the string’s length in n (avoids repeated strlen calls).|Initialization clause can declare **multiple variables** separated by commas.|
|s[i] >= 'a' && s[i] <= 'z'|Checks if the current char is a **lowercase ASCII letter**.|'a' is 97, 'z' is 122.|
|s[i] - ('a' - 'A')|Converts a lowercase char to uppercase.|('a' - 'A') is **32** in ASCII. Subtracting 32 shifts 'a' → 'A', 'b' → 'B', …|
|printf("%c", …)|Writes either the converted char or the original char directly to stdout.|Does **not** modify the original string in memory, just the output stream.|

---

## **Example run**

```
$ make uppercase
$ ./uppercase
Before: David
After:  DAVID
```

- Only the lowercase letters a, v, i, d were shifted up by 32.
    
- The initial uppercase D stayed unchanged.
    

---

## **Key takeaways**

1. **ASCII arithmetic**: You can transform case by adding/subtracting the fixed offset 32.
    
2. **Bounds check**: Always verify a char is lowercase before shifting; otherwise punctuation and numbers will be mangled.
    
3. **Efficiency**: Caching n in the for initializer makes the loop O(n) instead of O(n²).
    
4. **Non-destructive**: Printing the converted character leaves the original string intact—a good pattern when you only need transformed output.
    

---

### **Possible extensions**

- Replace the manual arithmetic with library helpers: printf("%c", toupper(s[i])); from <ctype.h>.
    
- Modify s[i] in place rather than just printing, if you need the altered string later.