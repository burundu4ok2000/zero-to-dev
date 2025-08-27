---
title: "Appending to a CSV with fprintf and get_string"  
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 28
status: "done"
difficulty: "easy"
date: "2025-08-27"
timecode: "2:18:00"
source: "https://cs50.harvard.edu/x/2025/weeks/4/"
review_next: "2025-09-27"
---
![[Screenshot 2025-08-27 at 13.08.01.png]]
 
---

## Summary
This program uses **`fopen()`**, **`fprintf()`**, and **`fclose()`** to append new name/number entries into a `phonebook.csv` file. User input is collected via `get_string()`.

---

## Very simple

> You ask someone their **name** and **phone number**, then write it into a file on your desk — without erasing anything already written.  
> That’s what appending to a CSV file is.

---

## Key Points

- `"a"` mode in `fopen()` = append (write to the end of the file)
- Always check for `NULL` when opening a file — the program may crash otherwise
- `get_string()` from CS50 reads a line of user input as a string
- `fprintf()` formats and writes the result to the file
- File is properly closed with `fclose()` to flush buffers and release resources

---

## Code Breakdown

```c
FILE *file = fopen("phonebook.csv", "a");
if (file == NULL) {
    return 1;
}
```

- Opens `phonebook.csv` for appending
- If opening fails, returns error code `1`

```c
char *name = get_string("Name: ");
char *number = get_string("Number: ");
```

- Prompts the user for input (from CS50 library)

```c
fprintf(file, "%s,%s\n", name, number);
```

- Writes name and number in CSV format: `name,number`

```c
fclose(file);
```

- Always close the file when done

---

## Why It Matters

- Introduces a basic **data persistence** technique
- Shows how to structure output as **CSV**, a common data format
- Teaches good habits: check for `NULL`, close your files
- Used for **logging**, **saving user data**, **collecting form input**, etc.

---

## Questions

- ❓What happens if two programs write to the same file at once?
- ❓How could we improve safety with error checks or length limits?

---

## Related Concepts

- [[File I_O in C — fopen, fclose, fread, fwrite]]
- [[fopen vs fopen_s — Differences in safety]]
- [[Pointers in C]] – because `FILE *` and `char *` are pointers
- [[Memory Leak — What It Is and How to Fix It]] – if you forget to `free()` the inputs
- [[CSV Format Basics]] – optional future note

---

## See Also

- [CS50 get_string docs](https://manual.cs50.io/)
- [fopen — cppreference](https://en.cppreference.com/w/c/io/fopen)
- [fprintf — cppreference](https://en.cppreference.com/w/c/io/fprintf)

---

## Terms

[[fopen]], [[fclose]], [[fprintf]], [[get_string]], [[append mode]], [[csv]], [[file I/O]], [[null pointer]], [[user input]]
