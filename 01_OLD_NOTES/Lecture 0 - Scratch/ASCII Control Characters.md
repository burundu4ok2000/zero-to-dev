![[Screenshot 2025-06-23 at 18.51.32.png]]
In the early part of the ASCII table (positions 0–31), the characters are not printable letters or symbols, but **control characters**. These were originally designed for teletypes and communication control, and while many are now **obsolete**, some still play roles in computing.

## Key Examples:
![[Screenshot 2025-06-23 at 19.12.33.png]]

|Decimal|Abbrev|Name|Purpose / Notes|
|---|---|---|---|
|0|NUL|Null|End of string, padding|
|1|SOH|Start of Heading|Header control in communication|
|2|STX|Start of Text|Marks the start of main text|
|3|ETX|End of Text|Marks the end of main text|
|4|EOT|End of Transmission|Indicates communication is complete|
|5|ENQ|Enquiry|Requests a response ("Are you there?")|
|6|ACK|Acknowledge|Positive response to ENQ|
|7|BEL|Bell|Triggers a beep sound|
|8|BS|Backspace|Moves cursor back one space|
|9|HT|Horizontal Tab|Tab stop|
|10|LF|Line Feed|Moves down to next line|
|13|CR|Carriage Return|Moves to start of line|
|27|ESC|Escape|Starts an escape sequence|

## Notes:

- These characters do **not** display visibly.
    
- Some, like **LF (Line Feed)** and **CR (Carriage Return)** are still used in modern text files.
    
- Others like **BEL** (Bell) may still trigger a sound on terminal emulators.
    

## Context in CS50x:

This chart was shown during **Lecture 0** to illustrate how low-level representations of data were originally designed. Understanding ASCII is part of building intuition for how text is stored and processed by computers.

→ Linked to: [[10_Courses/CS50x Harvard/00_Lectures/Lecture 0 - Scratch]], [[CS50x Harvard]],

---

📺 _CS50x 2025 – Lecture 0 @ timestamp ~26:52_