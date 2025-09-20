---
title: "Prime Numbers for Hashing — Why Primes Matter and How to Use Them"
lang_tags: "#lang/c"
type_tags: "#type/concept"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#lecture/week_5_Data_Structures"
tool_tags: ""
atom_idx: 15
status: "in-progress"
difficulty: "easy"
date: "2025-09-17"
timecode: "—"
source: "https://cs50.harvard.edu/x/2025/weeks/5/"
review_next: ""
---
![[cover_primes_hashing.png]]
## One Liner
**Primes** make **modulo** math behave nicely, which helps **hash functions** spread keys evenly across buckets.

## Very Simple
A **prime** is a number > 1 that’s divisible only by **1** and **itself** (2, 3, 5, 7, 11, …).  
When we use primes with **modulo** (`%`) and **coprime** steps, we avoid short repeating loops. That’s why primes show up everywhere in hashing.

---

## Key Ideas (why primes help hashing)
- **Even spread**: Using a **prime modulus** (like 1_000_000_007 or just 101) breaks many bad patterns in input data and reduces **collisions**.  
- **Coprime cycles**: With **open addressing** (probing), choosing a **prime table size** means step sizes that are **coprime** with the table size will eventually visit **every bucket** before repeating.  
- **Polynomial rolling hash**: Building a hash as `h = h * B + x` with a **prime base B** (31, 33, 37…) improves distribution and keeps order sensitivity (`"abc"` ≠ `"cab"`).  
- **Modulo arithmetic**: Using a **prime modulus** keeps the math “well‑behaved” (fewer accidental cycles; better mixing).  
- **Not magic**: Primes **reduce** collisions; they don’t make them impossible. You still need resizing and good load‑factor control.

---

## Minimal C snippets

### 1) Polynomial rolling hash (classic string hash)
```c
// returns hash in [0, MOD)
unsigned long hash_str(const char *s) {
    const unsigned long B = 31;       // prime base
    const unsigned long MOD = 1000003; // prime modulus (small demo)
    unsigned long h = 0;
    for (const unsigned char *p = (const unsigned char*)s; *p; p++) {
        h = (h * B + (unsigned long)(*p)) % MOD;
    }
    return h;
}
```
**Why it works:** `* B` pushes previous chars “to the left” (order matters), `% MOD` keeps the number in range, and **prime** `B`/`MOD` avoid nasty periodic patterns.

### 2) Table capacity as prime (chaining)
```c
#define CAPACITY 101 // prime table size

size_t index_for(unsigned long h) {
    return h % CAPACITY;
}
```
**Tip:** When the **load factor** (items / buckets) grows (e.g., > 0.75), **rehash** into a **bigger prime** capacity.

### 3) Linear probing with wraparound
```c
// Insert with linear probing, step = 1 (coprime with any size)
size_t put_slot(size_t h, size_t cap) {
    size_t i = h % cap;
    while (occupied(i)) i = (i + 1) % cap; // visits all buckets if cap is prime or step coprime
    return i;
}
```

---

## Tiny intuition demo
If you mod by **10**, lots of English words ending with vowels might cluster (since ASCII vowels have similar low bits).  
Mod by **11** (prime) tends to mix those patterns better.

```
sum("abc") = 294
294 % 10 = 4   (same last digit as many strings)
294 % 11 = 8   (less correlated with last digit)
```

---

## When primes matter vs when they don’t
- **Matter**:
  - You use a **simple** hash and rely on `% capacity` to spread keys.  
  - You implement **open addressing** and need full‑table coverage during probing.  
  - You build a **rolling/polynomial** string hash.
- **Less critical** (but still fine to use primes):
  - Your hash function already produces **uniform 32/64‑bit** output (e.g., MurmurHash).  
  - Your table size is a **power of two** and you mask (`index = h & (cap - 1)`); here you must ensure the hash mixes low bits well. Many production hash maps do this.

---

## Gotchas
- **Collisions still happen**. Primes don’t “turn them off”. Use **chaining** or **probing** and keep load factor healthy.  
- **Integer overflow** in C is a thing: prefer **unsigned** math and take `%` often if you need a bounded range.  
- **B = 31** is traditional, but not sacred. Other **primes** (33, 37, 131, 1009, …) are okay; benchmark for your data.

---

## Why it matters (CS50 angle)
- You’ll write hash functions that look like `hash = hash * 31 + c;` — **31 is prime** to reduce accidental patterns.  
- You’ll pick **prime** table sizes (101, 1009, 10007…) when coding a simple hash table.  
- You’ll reason about **load factor**, **collisions**, and **rehash** — primes make the simple designs work better.

---

## Quick FAQ
- **What is a prime?** A number with no divisors except **1** and itself.  
- **Why prime modulus?** Better mixing in `%` arithmetic; fewer short cycles.  
- **Why prime base 31?** Small, fast, coprime to many encodings; classic choice for string hashes.  
- **Does prime kill collisions?** No. It only **reduces** clusters. Always handle collisions.

---

## Related Concepts
- [[Hash Tables — Arrays and Linked Lists]] – where these hashes land as **buckets**.
- [[Choosing a Data Structure — Practical Guide]] – when a **hash map** beats a **tree**.
- [[Singly-Linked Lists — Core Operations]] – used for **chaining** in buckets.
- [[Doubly-Linked Lists — Basics and Operations]] – alternative chaining style.
- [[Binary-Search-Trees-Basics-and-Operations]] – the **ordered** alternative to hashing.
- [[Tries — Prefix Trees]] – another way to do string lookup without hashing.
- [[Arrow Operator and Struct Pointers in C]] – syntax glue for node fields.

## See Also
- [Prime number — Wikipedia](https://en.wikipedia.org/wiki/Prime_number)
- [Hash function — Wikipedia](https://en.wikipedia.org/wiki/Hash_function)
- [Modular arithmetic — Wikipedia](https://en.wikipedia.org/wiki/Modular_arithmetic)

## Terms

[[Prime]] [[Modulo]] [[Coprime]] [[Hash function]] [[Bucket]] [[Load factor]] [[Collision]] [[Chaining]] [[Open addressing]] [[Polynomial rolling hash]] [[Rehash]]
