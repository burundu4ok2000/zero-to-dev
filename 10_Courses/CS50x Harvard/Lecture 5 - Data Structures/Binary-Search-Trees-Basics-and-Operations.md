---
title: "Binary Search Trees — Basics and Operations"
lang_tags: "#lang/c"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 02
status: "in-progress"
difficulty: "medium"
date: "2025-09-17"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---

## Summary
A **binary search tree** (**BST**) is a **tree** where each **node** has up to two **children** and the **BST property** holds:  
- all keys in the **left subtree** are **less** than the node’s key,  
- all keys in the **right subtree** are **greater**.  

This makes **search**, **insert**, and **delete** work fast (average **O(log n)**) when the tree is **balanced**.

## Very simple
Think of a phone book tree: small numbers go **left**, big numbers go **right**. You keep zooming to the correct side until you find what you need (or hit **NULL**).

## Key Points
- **BST property** lets you skip half of the remaining tree at each step.
- **Balanced** trees are fast (≈ **O(log n)**). **Skewed** trees (like a linked list) are slow (**O(n)**).
- Common operations: **search**, **insert**, **min/max**, **delete**, **traverse (inorder)**.
- **Inorder traversal** prints keys in **sorted order**.
- Memory lives on the **heap** (use **malloc**/**free**).

---

## Node definition (C)
```c
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node;

node *new_node(int k) {
    node *n = malloc(sizeof(node));
    if (!n) return NULL;
    n->key = k;
    n->left = n->right = NULL;
    return n;
}
```

---

## Search
```c
bool bst_search(node *root, int k) {
    for (node *cur = root; cur != NULL; ) {
        if (k == cur->key) return true;
        cur = (k < cur->key) ? cur->left : cur->right;
    }
    return false;
}
```
**ASCII**
```
        [8]
       /        [3]   [10]
    /  \        [1]  [6]    [14]

Search 6: 8 → left (3) → right (6) ✓
```

---

## Insert
```c
node *bst_insert(node *root, int k) {
    if (!root) return new_node(k);
    if (k < root->key)  root->left  = bst_insert(root->left, k);
    else if (k > root->key) root->right = bst_insert(root->right, k);
    // ignore duplicates (or handle as you like)
    return root;
}
```

**ASCII**
```
Insert 5 into

   [4]
  /   [2]   [7]

go right? 5>4 → right to [7]
5<7 → left of [7]

   [4]
  /   [2]   [7]
     /
   [5]
```

---

## Minimum (leftmost) and Maximum (rightmost)
```c
node *bst_min(node *root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

node *bst_max(node *root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}
```

---

## Delete (3 cases)
1) **Leaf** (no children) → just free it.  
2) **One child** → link parent to the child, free node.  
3) **Two children** → replace node’s key with **inorder successor** (smallest in right subtree), then delete that successor.

```c
node *bst_delete(node *root, int k) {
    if (!root) return NULL;

    if (k < root->key)      root->left  = bst_delete(root->left, k);
    else if (k > root->key) root->right = bst_delete(root->right, k);
    else {
        // found it
        if (!root->left && !root->right) {
            free(root);
            return NULL; // leaf
        } else if (!root->left || !root->right) {
            node *child = root->left ? root->left : root->right;
            free(root);
            return child; // one child
        } else {
            node *succ = bst_min(root->right);
            root->key = succ->key;
            root->right = bst_delete(root->right, succ->key);
        }
    }
    return root;
}
```

**ASCII (delete 8)**
```
        [8]
       /        [3]   [10]
          /            [9]    [14]

succ = min(right) = 9
copy 9 into 8, then delete original 9

        [9]
       /        [3]   [10]
                          [14]
```

---

## Traversals
```c
void inorder(node *root) {        // Left, Node, Right  → sorted order
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(node *root) {       // Node, Left, Right
    if (!root) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {      // Left, Right, Node
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}
```

---

## **Why It Matters**
- **Fast lookups** with structure: keep data **sorted** while enabling **near-logarithmic** operations.
- Foundation for many features: **sets**, **maps**, **range queries**.
- Understanding BST helps you later with **balanced trees** (AVL, Red‑Black) and **binary heaps**.

## CS50 angle (simple and honest)
- Start with **plain BST** code (as above). It’s simple and great for learning.
- Know the tradeoff: without balancing, worst-case turns into a **linked list**.
- That’s okay for the course — you learn the patterns now, then meet **balanced trees** later.

---

## Related Concepts
- [[Singly-Linked Lists — Core Operations]] – contrast pointer rewiring vs tree links.
- [[Doubly-Linked Lists — Basics and Operations]] – different two-pointer idea.
- [[Stacks — Push and Pop]] – used for iterative traversals.
- [[Queues — Enqueue and Dequeue]] – used for level‑order traversal (BFS).
- [[Hash Tables — Arrays and Linked Lists]] – alternative **O(1)** average access.
- [[Tries — Prefix Trees]] – specialized string search trees.
- [[Arrow Operator and Struct Pointers in C]] – tree nodes use pointers everywhere.

## See also
- [Binary Search Tree — Wikipedia](https://en.wikipedia.org/wiki/Binary_search_tree)
- [BST — cp‑algorithms](https://cp-algorithms.com/data_structures/treap.html#bst-basics)  // section explains BST basics
- [Princeton Algorithms, BSTs](https://algs4.cs.princeton.edu/32bst/)

## Terms
[[Binary search tree]], [[BST property]], [[Node]], [[Left child]], [[Right child]], [[Inorder traversal]], [[Successor]], [[Predecessor]], [[Balanced]], [[Skewed]], [[O(log n)]], [[NULL]]
