---
title: Array mutation via functions
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
atom_idx: 1
status: done
difficulty: easy
date: 2025-08-10
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

![[2025-08-01_17-46-53.png]]

---

## Summary

Passing arrays to functions in C allows direct mutation of original values, unlike scalars which are passed by value.

## Key Points

- **Scalars** like `int` are passed **by value** – function gets a **copy**.
- **Arrays** decay to **pointers** – function receives reference to memory.
- To mutate scalars, you must **pass a pointer**.
- Functions can return values **or** mutate data via **shared memory**.

## Details

In C, function arguments behave differently based on their types:
- When you pass an `int`, you're passing its **value** (copy).
- When you pass an array, you're actually passing a **pointer** to its first element.

Therefore:
- `set_int(int x)` only modifies its local copy of `x`, not `a` in `main()`.
- `set_array(int array[4])` receives a pointer to `b`, so changing `array[0]` directly affects `b[0]`.

## Examples

```c
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = {0, 1, 2, 3};

    set_int(a);     // a stays 10
    set_array(b);   // b[0] becomes 22

    printf("%d %d\n", a, b[0]); // Output: 10 22
}

void set_array(int array[4])
{
    array[0] = 22;
}

void set_int(int x)
{
    x = 22;
}
````

**Output**

```
10 22
```

|**Call**|**What C passes under the hood**|**Result**|
|---|---|---|
|set_int(a)|**Copy** of a (value 10)|Function changes its **local** copy; the original a is untouched.|
|set_array(b)|**Pointer** to the first element of b|Function writes through the pointer, mutating the same memory b occupies.|

## **Why It Matters**

  

Understanding how **memory** and **argument passing** works is crucial for writing correct C programs. This distinction affects debugging, performance, and correctness of your functions — especially when handling large data structures or system-level code.

  

## **Questions**

- ❓ Why exactly do arrays decay to pointers? Is there a formal rule in the C standard?
    
- ❓ Can we force pass-by-reference behavior for other types in C?
    

  

## **Related Concepts**

- [[Pointers in C]] – \smth\ with array mutation by using pointer arithmetic.
    
- [[Pass by Value vs Pass by Reference in C]] – \smth\ with this example by contrasting function call semantics.
    
- [[Function Parameters and Memory Layout in C]] – how data is transferred on the stack.
    
- [[Memory Addressing Basics]] – explains pointer dereferencing in arrays.
    
- [[Call Stack and Function Frames]] – illustrates scope and variable lifetime.
    

  

## **See also**

- [Pass arrays to functions in C (GeeksForGeeks)](https://www.geeksforgeeks.org/pass-array-parameter-c/)
    
- [CS50 Lecture 2 — Arrays](https://cs50.harvard.edu/x/2025/weeks/2/)
    
- [Why arrays decay to pointers (Stack Overflow)](https://stackoverflow.com/questions/2528318/why-doesnt-the-sizeof-operator-work-properly-on-arrays)
    

  

## **Terms**

  

[[scalar]], [[pointer]], [[array]], [[pass by value]], [[pass by reference]], [[function argument]], [[memory mutation]]