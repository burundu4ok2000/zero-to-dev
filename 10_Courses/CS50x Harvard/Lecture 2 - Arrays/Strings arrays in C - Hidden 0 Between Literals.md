
![[Screenshot 2025-07-23 at 16.13.47.png]]
  ![[Screenshot 2025-07-23 at 16.13.55.png]]

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **What you’re seeing on the board**

  

Two variables:

```
string s = "HI!";
string t = "BYE!";
printf("%s\n", s);
printf("%s\n", t);
```

Each string is a **char array that ends with a null byte '\0'**.

On the board, David shows the **extra box** (\0) after "HI!" and another after "BYE!". Those are the terminators.

---

## **Memory layout (conceptual)**

```
Index:   0    1    2    3      0    1    2    3    4
Var:     s                     t
Bytes:   H    I    !   \0      B    Y    E    !    \0
```

| **Var** | **Index** | **Char** | **ASCII hex** | **Note**                            |
| ------- | --------- | -------- | ------------- | ----------------------------------- |
| s       | 0         | H        | 0x48          | visible                             |
| s       | 1         | I        | 0x49          | visible                             |
| s       | 2         | !        | 0x21          | visible                             |
| s       | 3         | '\0'     | 0x00          | **null terminator** or **sentinel** |
| t       | 0         | B        | 0x42          | visible                             |
| t       | 1         | Y        | 0x59          | visible                             |
| t       | 2         | E        | 0x45          | visible                             |
| t       | 3         | !        | 0x21          | visible                             |
| t       | 4         | '\0'     | 0x00          | **null terminator** or **sentinel** |

> The board just visualizes that “invisible” byte. There **is** another character there — it’s 0x00.

---

## **Why** 

## **%s**

##  **works**

- %s in printf prints characters **until it hits '\0'**.
    
- That’s why you can just pass s or t without their lengths—C string functions rely on the sentinel.
    

---

## **strlen**

##  **vs.** 

## **sizeof**

```
char s[] = "HI!";           // 4 bytes: 'H' 'I' '!' '\0'
strlen(s);   // 3 (no '\0')
sizeof(s);   // 4 (includes '\0')
```

---

## **Rules to remember**

- Always allocate **+1 byte** for the terminator.
    
- Overwriting or forgetting '\0' => garbage output or crashes.
    
- Don’t use %s on non-terminated buffers.
    

---

## **Mini check-yourself snippet**

``` 
for (int i = 0; i < sizeof(s); i++)
{
    printf("s[%d] = '%c' (0x%02X)\n", i,
           s[i] ? s[i] : '\\0', (unsigned char) s[i]);
}
```

This just walks byte-by-byte and prints the value; if the byte is 0, it prints '\0' instead of an invisible character.

---

## **TL;DR**

- **String = chars + hidden '\0'.**
    
- %s stops at '\0'.
    
- strlen counts visible chars; sizeof (on the array) counts the whole buffer.
    
- That empty-looking box David points to **isn’t empty**—it’s the most important byte.