![[2025-08-01_15-28-51.png]]

  ![[2025-08-01_15-29-22.png]]

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **The high-level pipeline**

```
plaintext  +  key  ─►  cipher box  ─►  ciphertext
```

- **Plaintext** – original human-readable message
    
- **Key** – secret (an integer shift in Caesar)
    
- **Cipher** – algorithm that scrambles text using the key
    
- **Ciphertext** – scrambled output you send over the wire
    

---

## **Caesar shift example (key = 1)**

```
Input :  H  I  ! 
Shift : +1 +1 +0
Output:  I  J  !
```

|**Char**|**ASCII**|**+1 →**|**Result**|
|---|---|---|---|
|H|72|73|I|
|I|73|74|J|
|!|33|—|!|

Only alphabetic characters rotate; punctuation stays as-is.

---

## **Pseudocode**

```
for each character c in plaintext
    if c is lowercase letter
        output  ((c - 'a' + key) % 26) + 'a'
    else if c is uppercase letter
        output  ((c - 'A' + key) % 26) + 'A'
    else
        output  c
```

Modulo 26 wraps z → a.

---

## **Minimal C implementation**

```
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }

    int key = atoi(argv[1]) % 26;
    string p = get_string("Plaintext: ");
    printf("Ciphertext: ");

    for (int i = 0; p[i] != '\0'; i++)
    {
        char c = p[i];
        if (isupper(c))
            printf("%c", ((c - 'A' + key) % 26) + 'A');
        else if (islower(c))
            printf("%c", ((c - 'a' + key) % 26) + 'a');
        else
            printf("%c", c);
    }
    printf("\n");
    return 0;
}
```

---

## **Key takeaways**

1. **Shift value = key** – same key encrypts and (in reverse) decrypts.
    
2. **Modulo arithmetic** keeps letters cycling within A–Z or a–z.
    
3. Non-letters are copied unchanged, preserving spaces & punctuation.
    
4. Security is trivial to break, but Caesar introduces core ideas you’ll reuse in stronger ciphers.
    

---

### **TL;DR**

  

A Caesar cipher adds a fixed integer to each alphabetic character (wrapping around the alphabet) to turn plaintext into ciphertext. Decrypt by subtracting the same key.