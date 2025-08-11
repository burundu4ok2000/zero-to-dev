

  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **Two-level indexing concept**

```
words[i][j]
        ▲  ▲
        │  └─ character index inside a single string
        └──── string index inside the array
```

- **First pair of brackets** selects **which string** you want ("HI" vs "BYE").
    
- **Second pair** selects **which character** inside that string ('H', 'I', …).
    
- Works because every string is actually a char * (pointer to the first byte).
    

---

## **Example code**

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string words[] = {"HI", "BYE"};

    // Access single characters
    printf("%c\n", words[0][0]); // 'H'
    printf("%c\n", words[0][1]); // 'I'
    printf("%c\n", words[1][0]); // 'B'
    printf("%c\n", words[1][2]); // 'E'

    // Loop through every character of every word
    for (int i = 0; i < 2; i++)              // choose word
    {
        for (int j = 0; words[i][j] != '\0'; j++) // choose char
        {
            printf("words[%d][%d] = '%c'\n", i, j, words[i][j]);
        }
    }
}
```

_Output (trimmed)_

```
H
I
B
E
words[0][0] = 'H'
words[0][1] = 'I'
words[1][0] = 'B'
words[1][1] = 'Y'
words[1][2] = 'E'
```

---

## **Memory picture (conceptual)**

|**Index**|words **element**|**Points to**|
|---|---|---|
|0|"HI"|{'H', 'I', '\0'}|
|1|"BYE"|{'B', 'Y', 'E', '\0'}|

Each entry in words is a **pointer** (8 bytes on CS50’s 64-bit Linux) that leads to its own null-terminated char array.

---

## **Quick rules**

1. **Single string** → one index: s[j].
    
2. **Array of strings** → two indices: words[i][j].
    
3. Stop the inner loop when you hit '\0', the sentinel byte.
    
4. Avoid out-of-bounds: check both word count and character length.
    

---

> **TL;DR**

> Want the 'Y' in "BYE"? It’s words[1][1] — choose the word first, the character second.