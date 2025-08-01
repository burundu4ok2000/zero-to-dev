![[2025-08-01_17-46-53.png]]
  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **Code from the slide**

```
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = {0, 1, 2, 3};

    set_int(a);     // try to change a
    set_array(b);   // try to change b

    printf("%d %d\n", a, b[0]);
}

// ── helpers ──────────────────────────────────────────────
void set_array(int array[4])
{
    array[0] = 22;          // attempt succeeds
}

void set_int(int x)
{
    x = 22;                 // attempt fails
}
```

**Output**

```
10 22
```

---

## **Why does** 

## **a**

##  **stay** 

## **10**

##  **but** 

## **b[0]**

##  **becomes** 

## **22**

## **?**

|**Call**|**What C passes under the hood**|**Result**|
|---|---|---|
|set_int(a)|**Copy** of a (value 10)|Function changes its **local** copy; the original a is untouched.|
|set_array(b)|**Pointer** to the first element of b|Function writes through the pointer, mutating the same memory b occupies.|

### **Key rule**

- **Scalars** (int, char, double, structs by default) are passed **by value** – you get a copy.
    
- **Arrays** decay to a **pointer** when passed to a function – effectively “by reference.”
    

---

## **Memory picture**

```
main()
┌─────┐   copy (10)    set_int()
│  a  │──────────────► [ x ]  (modified → 22, then discarded)
└─────┘

┌──────────────┐ pointer   set_array()
│ b[0] b[1]…   │──────────► [array]── modifies b[0] to 22
└──────────────┘
```

---

## **Take-away patterns**

1. **Want to mutate a scalar?**
    
    - Pass a pointer: void set_int(int *x) { *x = 22; } and call set_int(&a);.
        
    
2. **Arrays are already pointers.**
    
    - Any write inside the function changes the caller’s array.
        
    
3. **Return values** are not the only way to communicate back—shared memory via pointers works too.
    

---

### **TL;DR**

  

set_int fails because it edits a copy. set_array succeeds because arrays are passed as pointers, so the function reaches back into the caller’s memory and overwrites b[0].