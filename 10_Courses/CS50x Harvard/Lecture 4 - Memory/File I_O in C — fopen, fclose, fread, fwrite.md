---
title: "File I_O in C — fopen, fclose, fread, fwrite"  
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_4_Memory"
tool_tags: ""
atom_idx: 27
status: "done"
difficulty: "medium"
date: "2025-08-27"
timecode: "2:12:00"
source: "https://cs50.harvard.edu/x/2025/weeks/4/"
review_next: "2025-09-27"
---
 
![[Screenshot 2025-08-27 at 12.38.03.png]]
![[Screenshot 2025-08-27 at 12.38.49.png]]

---

## Summary
**File I/O** (Input/Output) in C means reading data **from files** and writing data **to files**. This allows your programs to save information across runs.

## Very simple

> Imagine you’re writing on a **sheet of paper** (a file).  
> You can **open** it, **write** something, **read** it later, and finally **close** it.  
> That’s File I/O — working with **files like documents**.

## Key Points

- Files in C are accessed through `FILE *` pointers.
- You need to **open** the file using `fopen()`.
- Use `fscanf`, `fgets`, or `fread` to **read** from the file.
- Use `fprintf`, `fputs`, or `fwrite` to **write** to the file.
- Always remember to **close** the file using `fclose()`!

## Details

### Common File I/O Functions:

| Function    | Purpose                    |
|-------------|-----------------------------|
| `fopen()`   | Opens a file (`r`, `w`, `a`) |
| `fclose()`  | Closes an opened file        |
| `fprintf()` | Prints formatted data to a file |
| `fscanf()`  | Reads formatted data from a file |
| `fread()`   | Reads binary data from file |
| `fwrite()`  | Writes binary data to file  |
| `fseek()`   | Move position inside file   |

### Example: Writing to a file

```c
FILE *file = fopen("hello.txt", "w");
if (file != NULL) {
    fprintf(file, "Hello, file!\n");
    fclose(file);
}
```

### Example: Reading from a file

```c
FILE *file = fopen("hello.txt", "r");
char buffer[100];
if (file != NULL) {
    fscanf(file, "%s", buffer);
    printf("Read: %s\n", buffer);
    fclose(file);
}
```

## Why It Matters

- File I/O allows saving **data across runs**, like:
  - User preferences
  - Logs and configs
  - Game saves or chat history
- It teaches you about **persistence**, **resources**, and **system-level APIs**.

## Questions

- ❓What happens if you forget to `fclose()` a file?
- ❓How can we detect errors while reading/writing?

## Related Concepts

- [[Pointers in C]] – all file operations use `FILE *` pointers.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]]
- [[Buffer Overflow — Exploiting Memory via Arrays]] – reading too much from a file may cause overflow.
- [[scanf without allocation — Dangerous Use of %s in C]]
- [[CS50 File Pointers Explained]]

## See also

- [File I/O in C — GeeksForGeeks](https://www.geeksforgeeks.org/basics-file-handling-c/)
- [C Documentation — stdio.h](https://en.cppreference.com/w/c/io)
- [CS50 Reference — File I/O](https://cs50.harvard.edu/x/2025/weeks/4/)

## Terms

[[file]], [[fopen]], [[fclose]], [[fscanf]], [[fprintf]], [[fread]], [[fwrite]], [[fseek]], [[file pointer]], [[stdio.h]]
