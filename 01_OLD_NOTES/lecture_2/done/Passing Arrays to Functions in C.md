
![[Screenshot 2025-07-23 at 14.58.34.png]]
  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **Core pattern**

  

When you pass an array to a function, you must also pass its **length** as a separate argument.

```
void print_array(int nums[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i\n", nums[i]);
    }
}

int main(void)
{
    int scores[] = {72, 73, 33};
    int n = sizeof(scores) / sizeof(scores[0]); // compute length at call site
    print_array(scores, n);
}
```

---

## **Why length is separate**

- In a parameter list (int nums[]), the array **decays to a pointer**; size info is lost.
    
- sizeof(nums) inside the function gives pointer size, not element count.
    
- So you explicitly provide length (or use another convention like a sentinel).
    

---

## **Syntax reminders**

|**Place**|**How it looks**|**Meaning**|
|---|---|---|
|**Declaration**|int scores[] = { … };|Real array with compile-time size|
|**Parameter**|int nums[] / int *nums|Pointer to first element (no size info)|
|**Call site**|print_array(scores, n);|Pass pointer + explicit length|

---

## **Alternatives (know, but don’t overuse)**

- **Sentinel value** (e.g., terminate with -1) and loop until found.
    
- **Fixed-size contract** (both sides assume same constant size — brittle).
    
- **Struct wrapper** combining data and length.
    
- sizeof tricks only work in the same scope where the true array is visible.
    

---

## **Common mistakes**

- Forgetting to pass length → out-of-bounds reads/writes (UB).
    
- Looping with i <= length instead of i < length.
    
- Confusing “element count” vs. “last valid index”.
    

---

## **Quick template**

```
// Prototype
void process(TYPE arr[], int length);

// Definition
void process(TYPE arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        // use arr[i]
    }
}

// Usage
TYPE data[] = { /* ... */ };
int len = sizeof(data) / sizeof(data[0]);
process(data, len);
```

---

## **Bonus: strings = arrays with a sentinel**

  

C strings are char arrays ending in '\0'. Functions like strlen walk until that sentinel to find length.

Numeric arrays don’t have that — **you must pass the length yourself**.