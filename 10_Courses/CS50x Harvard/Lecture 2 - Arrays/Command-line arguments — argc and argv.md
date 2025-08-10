---
title: "Command-line arguments — argc and argv"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: ""
atom_idx: 05
status: "done"
difficulty: "easy"
date: "2025-08-10"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/2/"
review_next: ""
---

![[2025-08-01_14-30-08.png]]

---

## Summary
`argc` and `argv` let your C program accept user input from the **command line**. They represent the number of arguments and the actual argument values.

## Key Points
- `int argc` is the number of strings passed to the program.
- `string argv[]` (or `char *argv[]`) is an array of strings containing those arguments.
- `argv[0]` is always the program’s own name/path.
- You must check `argc` before accessing `argv[i]` to avoid out-of-bounds access or crashes.
- `argv[argc]` is always `NULL`, which can be useful as a **sentinel**.
- Use `atoi` or `strtol` to convert numeric arguments to integers.

## Details
- When you run a C program via terminal with arguments (like `./greet David`), the operating system **passes them to `main()`** as an array of strings.
- Indexing into `argv[]` gives you each word, starting with the executable path at `argv[0]`.
- Checking `argc` helps avoid accessing arguments that weren’t passed, which can cause **undefined behavior**.
- In CS50, the `string` type is just a `typedef` for `char *`, meaning all standard C string rules apply.

## Examples

```c
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);  // correct greeting
    }
    else
    {
        printf("Usage: ./greet <name>\n");
        return 1;
    }
}
````

Terminal run:

```
$ ./greet David
hello, David
```

|**Index**|**argv[i]**|**Value**|
|---|---|---|
|0|argv[0]|“./greet”|
|1|argv[1]|“David”|
|2+|argv[i]|NULL|

## **Why It Matters**

  

Understanding how to receive **input at runtime** is crucial for creating flexible CLI programs. argc and argv give your programs context, config, or data without modifying source code.

  

## **Questions**

- ❓ When should we use strtol instead of atoi for numeric conversion?
    
- ❓ What happens if I try to access argv[5] when only 2 arguments are passed?
    

  

## **Related Concepts**

- [[Function Parameters in C]] – argc/argv are just parameters passed to main.
    
- [[Strings in C]] – argv stores **char pointers**, i.e., C-style strings.
    
- [[Memory Representation of Arrays]] – argv is a pointer to an array of pointers.
    
- [[Input Validation]] – argc helps validate argument count.
    
- [[String to Integer Conversion]] – using atoi, strtol safely.
    

  

## **See also**

- [[Lecture 2 - Arrays]]
    
- [CS50 Reference: Command Line Arguments](https://cs50.harvard.edu/x/2025/notes/2/#command-line-arguments)
    
- [GNU C Library — argc and argv](https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html)
    

  

## **Terms**

  

[[argc]], [[argv]], [[string]], [[char *]], [[command-line]], [[NULL]], [[atoi]], [[strtol]], [[segmentation fault]], [[main function]]