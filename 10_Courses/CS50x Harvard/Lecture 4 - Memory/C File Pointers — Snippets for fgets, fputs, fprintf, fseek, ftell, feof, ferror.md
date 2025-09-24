---
title: C File Pointers — Snippets for fgets, fputs, fprintf, fseek, ftell, feof, ferror
status: done
date: 2025-09-13
source: https://cs50.harvard.edu/x/2025/weeks/4/
review_next: 2025-10-13
lang_tags: "#lang/c"
type_tags: "#type/snippet"
course_tags: "#course/cs50x"
lecture_tags: "#lecture/week4_memory"
tool_tags: "#tool/clang, #tool/valgrind"
---

# One Liner
Quick **file I/O** cheat with small C snippets for **FILE*** and friends: **fgets**, **fputs**, **fprintf**, **fseek**, **ftell**, **feof**, **ferror**.

# TL;DR
Open with `fopen`, operate via a **FILE*** handle, always check **NULL**, and close with `fclose`. Use **fseek/ftell** to move/query the **file offset**; **feof/ferror** to inspect read state.

---

## Setup (common header)
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("demo.txt", "r+"); // create the file first if needed
    if (!fp) { perror("fopen"); return 1; }
    // ... snippets below would live here ...
    fclose(fp);
    return 0;
}
```

---

## fgets — read a whole line (safe, bounded)
```c
char buf[128];
if (fgets(buf, sizeof buf, fp)) {
    // buf includes the trailing '\n' if line fits; otherwise it's truncated
    printf("line: %s", buf);
} else {
    // NULL => EOF or error; disambiguate with feof/ferror
    if (feof(fp)) puts("EOF reached");
    if (ferror(fp)) perror("read error");
}
```

**Use when** you want simple **line-based** input from a text file without manual char-by-char loops.

---

## fputs — write a full string
```c
if (fputs("Hello, file!\n", fp) == EOF) {
    perror("fputs");
}
```
**Note:** `fputs` does **not** append a newline — you do it yourself.

---

## fprintf — formatted write (like printf but to a file)
```c
int id = 42;
double score = 3.14;
if (fprintf(fp, "id=%d score=%.2f\n", id, score) < 0) {
    perror("fprintf");
}
```

---

## fseek — jump around the file (rewind/fast‑forward)
```c
// go to start
if (fseek(fp, 0L, SEEK_SET) != 0) perror("fseek SEEK_SET");

// go to end
if (fseek(fp, 0L, SEEK_END) != 0) perror("fseek SEEK_END");

// go 10 bytes forward from current
if (fseek(fp, 10L, SEEK_CUR) != 0) perror("fseek SEEK_CUR");
```
**Offsets** are `long`. For big files on some systems, prefer `fseeko/ftello`.

---

## ftell — get current byte offset
```c
long pos = ftell(fp);
if (pos == -1L) { perror("ftell"); }
else { printf("offset: %ld\n", pos); }
```

---

## feof — check if we hit EOF (after a failed read)
```c
// Typical loop pattern
rewind(fp);              // same as fseek(fp, 0L, SEEK_SET)
char c;
while ((c = fgetc(fp)) != EOF) {
    putchar(c);
}
if (feof(fp))   puts("\n-- reached EOF --");
if (ferror(fp)) perror("I/O error");
```
**Rule:** `feof` is **true only after** a read hits end‑of‑file.

---

## ferror — detect an I/O error
```c
clearerr(fp); // reset sticky flags (EOF/error) if needed
// ... do I/O ...
if (ferror(fp)) {
    perror("file I/O failed");
    // handle or abort
}
```

---

## Pitfalls & Gotchas
- Always check return values. **NULL**/**EOF**/**-1** are signals, not decorations.
- `fgets` may leave a partial line when the buffer is too small; loop until you see `\n` or **feof**.
- Text vs binary: on Windows, open with `"rb"/"wb"` to avoid newline translation.
- Mixing `fread/fwrite` with the text functions is fine, but keep your mental model clear about the **file offset**.
- Use `fflush(fp)` when you need guarantees that buffered data is pushed to disk.

---

## Minimal end‑to‑end demo
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // create and write
    FILE *out = fopen("demo.txt", "w");
    if (!out) { perror("fopen"); return 1; }
    fprintf(out, "first line\n");
    fputs("second line\n", out);
    fclose(out);

    // read back
    FILE *in = fopen("demo.txt", "r");
    if (!in) { perror("fopen"); return 1; }
    char buf[64];
    while (fgets(buf, sizeof buf, in)) {
        printf("%s", buf);
    }
    if (feof(in)) puts("--EOF--");
    if (ferror(in)) perror("read error");
    fclose(in);
    return 0;
}
```

---

## Terms
- **FILE*** — C handle to an open file stream.
- **EOF** — special end‑of‑file indicator (`#define EOF -1` on most libc).
- **Offset** — current byte position inside a file, managed by the stream.

## Related Concepts
- [[File I/O — fopen, fread, fwrite, fclose]] – pairs nicely with these high‑level helpers.
- [[Memory Layout of a Program — Stack, Heap, Globals, Machine Code]] – where buffers live when you read lines.
- [[Pointers in C — Address-of & Dereference]] – understanding **FILE*** as a pointer.
- [[Binary vs Text Files in C]] – newline translation, portability notes.
- [[Buffer Overflow — Risks & Mitigations]] – beware small buffers with **fgets**.
- [[Hexadecimal & Bytes — C Basics]] – read/write at the byte level.
- [[CS50x Week 4 — Memory]] – lecture context for these APIs.
- [[Error Handling Patterns in C]] – check/propagate **errno** and stream flags.

## See Also
- [C Reference — stdio.h](https://en.cppreference.com/w/c/io)  
- [The GNU C Library — I/O on Streams](https://www.gnu.org/software/libc/manual/html_node/Streams-and-I_002fO.html)  
- [File Positioning — fseek/ftell](https://en.cppreference.com/w/c/io/ftell)
