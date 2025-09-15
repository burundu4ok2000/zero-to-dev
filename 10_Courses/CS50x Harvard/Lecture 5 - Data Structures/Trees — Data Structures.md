---
title: "Trees — Data Structures"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 07
status: "in-progress"
difficulty: "medium"
date: "2025-09-15"
timecode: "01:28:00"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

## Summary
A **tree** is a hierarchical structure of **nodes**. Each node stores **data** and references to child nodes.  
A **binary tree** has up to two children (**left** and **right**). A **Binary Search Tree (BST)** keeps the **ordering rule**: values in the left subtree \< node \< values in the right subtree. This rule lets us **search/insert/delete** in **O(log n)** time *if the tree stays balanced*.

## Very simple
Think folders on your computer: one folder can contain more folders. To find a file, you **branch** left/right based on names or numbers instead of scanning everything one by one.

## Key Points
- **Node** = value + **pointers** to children.  
- **BST invariant**: `left < node < right`.  
- **Height** = longest path from root to a leaf; smaller height ⇒ faster operations.  
- **Degeneration**: inserting sorted data into an unbalanced BST can make it a skinny **linked list** (O(n)).  
- **Balanced trees** (e.g., **AVL**, **Red–Black**) keep height ≈ **O(log n)** using **rotations**. CS50 hints that “the code is already written” — treat balancing as a feature you can plug in.  
- **Traversals**: **inorder**, **preorder**, **postorder**, and **level-order** (BFS).

## Details
### Node type (C)
```c
typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;
```

### Search (recursive)
```c
bool search(node *tree, int x)
{
    if (tree == NULL) return false;
    if (x < tree->number)   return search(tree->left, x);
    else if (x > tree->number) return search(tree->right, x);
    else return true;
}
```

### Insert (recursive, simple BST)
```c
bool insert(node **ptree, int x)
{
    node *t = *ptree;
    if (t == NULL)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL) return false;
        n->number = x;
        n->left = n->right = NULL;
        *ptree = n;
        return true;
    }
    if (x < t->number)  return insert(&t->left, x);
    if (x > t->number)  return insert(&t->right, x);
    return true; // duplicate policy: ignore
}
```

### Delete (three classic cases)
```c
node *min_node(node *t) { while (t->left) t = t->left; return t; }

node *erase(node *t, int x)
{
    if (!t) return NULL;
    if (x < t->number)      t->left  = erase(t->left, x);
    else if (x > t->number) t->right = erase(t->right, x);
    else
    {
        // Case A: 0 or 1 child
        if (!t->left)  { node *r = t->right; free(t); return r; }
        if (!t->right) { node *l = t->left;  free(t); return l; }
        // Case B: 2 children → replace with inorder successor
        node *s = min_node(t->right);
        t->number = s->number;
        t->right = erase(t->right, s->number);
    }
    return t;
}
```

### Traversals
```c
void inorder(node *t)  { if (!t) return; inorder(t->left);  printf("%d ", t->number); inorder(t->right); }
void preorder(node *t) { if (!t) return; printf("%d ", t->number); preorder(t->left); preorder(t->right); }
void postorder(node *t){ if (!t) return; postorder(t->left); postorder(t->right); printf("%d ", t->number); }
```
- **Inorder** on a BST prints **sorted** numbers.  
- **Level-order** (BFS) uses a **queue** to visit nodes by levels.

### Balancing & Rotations (concept)
If inserts arrive in unlucky order, the tree can become **unbalanced** (height ≈ n). **Self-balancing** BSTs fix this automatically using **rotations**: small **pointer** moves that “pivot” a subtree so heights even out.  
Common options:
- **AVL trees**: strict balance via **left/right rotations** after inserts/deletes.  
- **Red–Black trees**: looser balance via colors + rotations.  
In CS50 context: you can assume “there’s code for this” — you’ll see it in libraries or later psets. The important takeaway is: **balanced trees keep operations ≈ O(log n)** by rotating when needed.

### Complexity (typical)
- **Search / Insert / Delete**: **O(log n)** balanced, **O(n)** worst-case unbalanced.  
- **Space**: **O(n)** nodes; recursion uses **call stack** depth up to height.

### Use Cases
- Ordered **sets** or **maps** (key → value) where you need **sorted traversal**.  
- Auto-suggest over ranges, leaderboard top-K, in-memory indexes.  
- Implementations of language features (C++ `std::map` is a Red–Black tree).

### Gotchas
- Always check `malloc` for **NULL**; initialize new `left/right = NULL`.  
- **Recursion** must have base cases or you’ll **segfault**.  
- Decide on a **duplicate** policy (ignore, count frequency, or store to one side).  
- Free the whole tree to avoid **memory leaks**:
```c
void free_tree(node *t)
{
    if (!t) return;
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}
```

## **Why It Matters**
Trees let you mix **ordering** with **fast lookups**. With balancing, you keep the sweet spot: **sorted data** and **logarithmic** performance.

## Questions
- How would you adapt `insert` to **reject** duplicates or store a **count**?  
- When would you prefer a **hash table** (O(1) average) over a **BST** (ordered)?

## Related Concepts
- [[Data Structures — What & Why]] – big picture of structures.  
- [[Structs in C — Defining and Self-Referencing]] – node shape and self-pointers.  
- [[Linked Lists — Types and Usage]] – contrast: fast inserts, slow search.  
- [[Linked Lists — Inserting in Sorted Order]] – same invariant as BST but linear.  
- [[Pointers in C — Address-of & Dereference]] – needed for all tree ops.  
- [[Dynamic Memory Allocation — malloc & free]] – building and freeing trees.  
- [[Asymptotic Analysis]] – reason about O(log n) vs O(n).  
- [[Hash Tables — Key-Value Storage]] – unordered alternative.

## See also
- [Tree (data structure) — Wikipedia](https://en.wikipedia.org/wiki/Tree_(data_structure))
- [Binary search tree — Wikipedia](https://en.wikipedia.org/wiki/Binary_search_tree)
- [AVL tree — Rotations explained](https://en.wikipedia.org/wiki/AVL_tree)

## Terms
[[Tree]], [[Binary tree]], [[Binary Search Tree]], [[Root]], [[Leaf]], [[Height]], [[Rotation]], [[AVL tree]]
