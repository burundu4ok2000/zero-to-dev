---
title: "Linked Lists — Freeing Memory"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 05
status: "in-progress"
difficulty: "medium"
date: "2025-09-15"
timecode: "01:05:00"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---



## Summary
This loop goes through a **linked list** and frees each node’s memory, preventing memory leaks.  
It carefully stores the next pointer before freeing the current node.

## Very simple
Imagine you’re throwing away a chain of boxes one by one.  
Before you throw away the current box, you first look inside and note where the next box is.  
Then you throw the current box away and move to the next one.

## Key Points
- **Goal**: release memory allocated by `malloc` for each node.  
- Must **not lose track** of the next node before calling `free()`.  
- Uses a helper pointer (`next`) to remember where to go next.  
- After freeing, we move forward using that saved pointer.  
- Loop stops when all nodes are freed (`ptr == NULL`).

## Details
```c
node *ptr = list;
while (ptr != NULL)
{
    node *next = ptr->next; // save the next node
    free(ptr);              // free current node
    ptr = next;             // move to the saved next node
}
```

### Step by step
1. Start with the head of the list (`ptr = list`).  
2. Store pointer to the next node (`next = ptr->next`).  
3. Free the current node (`free(ptr)`).  
4. Move to the next node (`ptr = next`).  
5. Repeat until no nodes remain (`ptr == NULL`).

If we didn’t save `next` before freeing, we’d lose access to the rest of the list.

## Examples
### Before freeing
```
list → [3 | next] → [2 | next] → [1 | NULL]
```
`ptr` points to 3.

### After first free
```
free(3)
ptr → [2 | next] → [1 | NULL]
```

And so on, until the entire list is freed.

## **Why It Matters**
- Prevents **memory leaks**: allocated memory is returned to the system.  
- Essential in long-running programs where memory use must stay controlled.  
- Reinforces careful pointer handling: freeing without saving `next` breaks the chain.

## Questions
- ❓ What happens if you call `free()` without saving `next`?  
- ❓ Is freeing necessary at the very end of a short program?  

## Related Concepts
- [[Linked Lists — Types and Usage]] – context for traversal.  
- [[Dynamic Memory Allocation — malloc & free]] – allocation and freeing go hand-in-hand.  
- [[Pointers in C — Address-of & Dereference]] – required to navigate nodes.  
- [[Structs in C — Defining and Self-Referencing]] – basis of linked lists.  
- [[Garbage value]] – avoided by cleaning up.  
- [[Heap]] – memory region used by malloc/free.  
- [[Stacks — LIFO Principle]] – contrast: memory freed automatically.  
- [[Queues — FIFO Principle]] – also implemented with linked lists.

## See also
- [[CS50x Harvard]]  
- [free() in C](https://www.geeksforgeeks.org/memory-management-in-c/)  
- [Why freeing memory matters](https://stackoverflow.com/questions/6417158/when-should-i-use-free-in-c)  

## Terms
[[Linked list]], [[malloc]], [[free]], [[Pointer]], [[Heap]], [[Memory leak]], [[Traversal]], [[Node]]
