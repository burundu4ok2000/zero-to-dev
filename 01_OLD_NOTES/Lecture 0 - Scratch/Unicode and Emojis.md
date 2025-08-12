
**Lecture Reference:** CS50x 2025, Lecture 0 (Timestamp ~35:53–36:33)
![[Screenshot 2025-06-23 at 19.24.35.png]]
  

**Summary:**

Unicode is a modern standard that extends the limited ASCII system to support a vast number of characters and symbols from all writing systems, as well as emojis.

  

**Example Discussed:**

David Malan demonstrates how Unicode can represent emojis using binary encoding. He shows the binary pattern:
![[Screenshot 2025-06-23 at 19.24.41.png]]
```
11110000 10010011 10011111 10000010
```

This sequence of bytes corresponds to the decimal number:
![[Screenshot 2025-06-23 at 19.24.44.png]]
```
4036991106
```

Which, according to the Unicode standard, represents the emoji:
![[Screenshot 2025-06-23 at 19.24.49.png]]
```
😂 (Face with Tears of Joy)
```

**Why It Matters:** This illustrates how Unicode uses multiple bytes to encode a huge variety of characters and symbols beyond the English alphabet. Unlike ASCII, which was limited to 128 (or 256) characters, Unicode can handle over a million unique symbols.

**Most popular emoji**
![[Screenshot 2025-06-23 at 19.31.26.png]]


- [[CS50x Harvard]]
    
- [[10_Courses/CS50x Harvard/00_Lectures/Lecture 0 - Scratch]]


