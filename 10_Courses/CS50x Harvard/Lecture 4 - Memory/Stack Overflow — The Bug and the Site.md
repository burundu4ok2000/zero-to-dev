---
title: "Stack Overflow — The Bug and the Site"  
lang_tags: "#lang/c"
type_tags: "#type/termin"
tool_tags: ""
status: "done"
difficulty: "na"
date: "2025-08-27"
source: "https://cs50.harvard.edu/x/2025/weeks/4/"
review_next: "2025-09-27"
---
![[pIgix.png]]
## **One-liner

> **Stack overflow** is a program crash caused by infinite or excessive function calls. It’s also the name of the most famous Q&A site for programmers.

## Very simple

> Imagine you’re stacking dishes. You keep adding more, never stopping. Eventually, they fall — crash!  
> That’s what happens when functions call each other endlessly: the **stack explodes**.

## Examples

### Example 1 — The bug

```c
void boom() {
    boom(); // calls itself forever
}

int main() {
    boom(); // causes stack overflow
}
```

### Example 2 — The site

> **Stack Overflow** (the site) is where programmers go when they *feel like their brain stack is about to overflow*.  
> It’s named after this very bug — a metaphor for the programmer’s typical struggle.

##  Related Terms

[[stack]], [[heap]], [[recursion]], [[segmentation fault]], [[stack frame]], [[function call]], [[infinite loop]]

## See also

- [What is a Stack Overflow? — StackOverflow Blog](https://stackoverflow.blog/2009/04/29/a-brief-history-of-stack-overflow/)
- [Stack Overflow (bug) — Wikipedia](https://en.wikipedia.org/wiki/Stack_overflow)
- [StackOverflow site](https://stackoverflow.com)
