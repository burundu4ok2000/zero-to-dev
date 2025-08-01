![[2025-08-01_17-41-55.png]]

  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

```
int foo[5] = {1, 2, 3, 4, 5};  // declare + initialize
int bar[5];                    // same length, uninitialized

for (int j = 0; j < 5; j++)    // copy element-by-element
{
    bar[j] = foo[j];
}
```

- Array **size** (5) must be a compile-time constant.
    
- You can’t do bar = foo; in C—use a loop or memcpy.