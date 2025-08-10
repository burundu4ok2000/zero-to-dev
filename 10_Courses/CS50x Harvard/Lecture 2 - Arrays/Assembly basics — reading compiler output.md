---
title: "Assembly basics — reading compiler output"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
atom_idx: 06
status: "done"
difficulty: "medium"
date: "2025-08-10"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/2/"
review_next: ""
---

![[Screenshot 2025-07-22 at 10.53.01.png]]

---

## Summary
CS50 doesn’t require writing assembly, but knowing how to **read the output** makes debugging and understanding the compiler process easier.

## Key Points
- Assembly reflects how your C code actually executes.
- Stack setup (`push`, `mov`, `sub`), function calls (`callq`), return (`leave`, `ret`) — all map to familiar C concepts.
- Mnemonics follow patterns you can learn to recognize even as a beginner.

## Details

### Sample output

```asm
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    callq   get_string
    movl    $0, %eax
    callq   printf
    leave
    ret
````

### **Key translation table:**

|**Assembly**|**Meaning**|**C Equivalent**|
|---|---|---|
|main:|Label — function entry|int main(void)|
|pushq %rbp|Save base pointer|Setup stack frame|
|movq %rsp, %rbp|Establish new base pointer|Start local scope|
|subq $16, %rsp|Reserve space on stack|Local variables|
|callq get_string|Call function|get_string();|
|movl $0, %eax|Set return value|return 0;|
|callq printf|Another function call|printf(...);|
|leave / ret|Restore stack, return|End of main()|

---

## **Examples of Common Mnemonics**

- mov — copy data between registers/memory
    
- add, sub, imul, idiv — perform arithmetic
    
- cmp, test — compare values
    
- jmp, je, jne, jg — jump based on conditions
    
- call, ret — call/return from function
    
- push, pop — manage stack manually
    

---

You’ll **see this assembly output** when using clang -S or when stepping through code in lldb.

You **don’t need to write** this yourself, but **recognizing structure** is useful for:

- understanding what main() does behind the scenes,
    
- interpreting stack traces,
    
- demystifying the compilation pipeline.
    

  

![[Screenshot 2025-07-22 at 10.56.36.png]]

![[Screenshot 2025-07-22 at 10.57.10.png]]

  

## **Why It Matters**

- Helps you understand how variables are passed, stored, and returned.
    
- Makes **compiler and debugger output** more readable.
    
- Improves your intuition around **memory layout**, stack usage, and low-level flow.
    

  

## **Questions**

- ❓What do %rsp, %rbp, %rax actually stand for on x86_64?
    
- ❓How does the calling convention affect which registers are used?
    

  

## **Related Concepts**

- [[Stack Frame in Assembly]] – shows how stack-based execution works
    
- [[Function Calls in C]] – how C maps to callq, ret, etc.
    
- [[Registers in x86_64]] – %rbp, %rsp, %rax, %rdi, etc.
    
- [[Debugger Output (lldb)]] – understanding assembly helps debug
    
- [[Machine Code and Assembler]] – lower-level translation from source
    
- [[Calling Conventions]] – how args and return values move in CPU
    

  

## **See also**

- [CS50x Week 2 (Arrays)](https://cs50.harvard.edu/x/2025/weeks/2/)
    
- [Assembly Language Guide (MIT)](https://ocw.mit.edu/6-004/notes/assembly/)
    
- [x86 Assembly Cheat Sheet](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)
    

  

## **Terms**

  

[[assembly]], [[stack frame]], [[main function]], [[registers]], [[callq]], [[ret]], [[push]], [[mov]], [[clang -S]]
