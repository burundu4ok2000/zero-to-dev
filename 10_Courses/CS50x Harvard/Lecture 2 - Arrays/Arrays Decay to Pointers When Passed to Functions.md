Вот как можно переписать твою заметку **по шаблону лекционного атома** из CS50x. Включены все обязательные блоки, YAML и структура:

---

# **Array mutation via functions**

  




---

![[2025-08-01_17-46-53.png]]

---

## **Summary**

  

The behavior of **function arguments** in C depends on their type: **scalars are passed by value**, while **arrays decay to pointers** — enabling mutation inside a function.

  

## **Key Points**

- **Scalars** like int are passed **by value** → changes affect only a local copy.
    
- **Arrays** are passed as **pointers** → modifications affect the caller’s memory.
    
- Use **pointers** explicitly if you want to mutate a scalar inside a function.
    
- Arrays allow direct in-place modification because they already act as references.
    

  

## **Details**

  

In this code, set_int(a) doesn’t affect a because a copy of a is passed. The assignment x = 22 modifies only the local copy.

  

Meanwhile, set_array(b) succeeds in changing b[0] to 22 because b decays into a pointer to its first element when passed to the function. This allows the function to modify the actual memory in main().

  

## **Examples/Demos**

```
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = {0, 1, 2, 3};

    set_int(a);     // no effect on a
    set_array(b);   // modifies b[0]

    printf("%d %d\n", a, b[0]);  // Output: 10 22
}

void set_array(int array[4])
{
    array[0] = 22;
}

void set_int(int x)
{
    x = 22;
}
```

### **Output:**

```
10 22
```

### **Memory visualization:**

```
main()
┌─────┐   copy (10)    set_int()
│  a  │──────────────► [ x ]  (modified → 22, then discarded)
└─────┘

┌──────────────┐ pointer   set_array()
│ b[0] b[1]…   │──────────► [array]── modifies b[0] to 22
└──────────────┘
```

## **Why It Matters**

  

This distinction is essential for understanding **function design**, **memory safety**, and **performance** in C. Knowing when and how data can be mutated allows better control over side effects and helps prevent bugs when working with large structures, arrays, or system-level code.

  

## **Questions**

- ❓ Does this apply to structs as well?
    
- ❓ How does this compare to references in C++?
    

  

## **Related Concepts**

- [[Pointers and Memory Addresses in C]] – \pointers\ explain how arrays decay and how memory access works.
    
- [[Pass-by-Value vs Pass-by-Reference]] – \comparison\ of function argument mechanisms.
    
- [[Function Parameters and Side Effects]] – \effects\ when mutating shared memory.
    
- [[Pointer Arithmetic in C]] – \used\ when working with arrays as pointers.
    
- [[Arrays vs Pointers in C]] – \clarifies\ their differences and similarities.
    

  

## **See also**

- [CS50 Lecture on Arrays (YouTube)](https://youtu.be/6kQTKD3CjZ8?si=2ntoGD6cs8M6bZ5y)
    
- [CS50x Notes on Arrays](https://cs50.harvard.edu/x/2023/notes/2/)
    
- [Arrays and Functions – C Programming Tutorial](https://www.learn-c.org/en/Arrays)
    

---

Хочешь, я сделаю аналогичную заметку для случая, когда ты передаёшь указатель на int, чтобы мутация сработала?