> **Lecture reference:** [[Lecture 1 - C]]

> **Course:** [[CS50x Harvard]]

---

## **📝 Quick Table**

|**Function**|**Return type**|**Purpose**|**Example call**|
|---|---|---|---|
|get_char()|char|Read a single character from stdin|char c = get_char();|
|get_double()|double|Read a floating-point number|double d = get_double();|
|get_float()|float|Read a 32-bit floating-point value|float f = get_float();|
|get_int()|int|Read an integer (checks for range)|int n = get_int();|
|get_long()|long|Read a 64-bit integer|long id = get_long();|
|get_string()|string*|Read an arbitrary-length string|string s = get_string("Name: ");|

*string is CS50’s typedef for char *.

---

## **Why use them?**

- **Input validation** — they re-prompt until the user provides a value of the right type.
    
- **Memory safety** — get_string auto-allocates enough space; no buffer overflows.
    
- **Convenience** — no need to juggle scanf, %d, %s, or manual error checking in early assignments.
    

---

## **Under the Hood**

  

The CS50 Library wraps standard C functions (fgets, strtod, etc.), adding loops that:

1. **Check return values**. If input fails, it clears the buffer.
    
2. **Re-prompt** the user until valid data arrives.
    
3. **Return** the correctly typed result to your code.
    

  

For strings, get_string allocates memory with malloc. When you’re done, free it with free(s) to avoid leaks.

---

### **Minimal Example**

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int age = get_int("Age: ");
    string name = get_string("Name: ");

    printf("%s is %i years old.\n", name, age);
    free(name);  // only required for get_string
}
```

---

### **Takeaways**

- The CS50 Library is perfect while you learn the basics; later you’ll graduate to raw scanf, getline, or fgets for more control.
    
- Always _free_ strings you allocate with get_string once manual memory management becomes the topic in Week 4.