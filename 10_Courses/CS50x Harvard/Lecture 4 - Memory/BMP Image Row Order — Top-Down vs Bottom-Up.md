---
title: BMP Image Row Order — Top-Down vs Bottom-Up
status: done
date: 2025-08-27
source: https://cs50.harvard.edu/x/2025/weeks/4/
review_next: 2025-09-27
---

## 🧠 Why This Matters

When working with bitmap images (especially in CS50’s `resize.c` and `filter.c`), you need to know **how the image data is stored**. Surprisingly, **BMP files can store images upside-down by default**.

---

## 🖼️ How Image Rows Are Stored in BMP

### 🧾 Classic BMP Format (Bottom-Up)
- First row in file = **bottom** row of image
- Last row in file = **top** row of image
- **Upside-down storage** is default behavior in many BMPs

### 🧾 CS50 BMP Format (Top-Down)
- First row in file = **top** row of image
- Last row in file = **bottom** row of image
- Much more intuitive for reading top-down

---

## 🏛️ Why Are Some BMPs Upside-Down?

Historically:
- Early Windows/DOS used **bottom-up drawing** because the video memory was laid out that way
- It was easier to render rows starting at the beginning of RAM
- So BMP adopted this format by default

This legacy stuck, even though it feels weird now.

---

## 🧑‍💻 What It Means for Your Code

### For CS50’s BMPs:
- Don’t worry about inversion — data is already **top-down**
- You can read/write rows in normal order (from top to bottom)

### For Real-World BMPs:
- Always check the **`biHeight`** field in the file’s BITMAPINFOHEADER:
  - If `biHeight` is **positive** → bottom-up (classic BMP)
  - If `biHeight` is **negative** → top-down (modern interpretation)

```c
if (infoHeader.biHeight > 0)
{
    // bottom-up BMP: read rows in reverse order
}
else
{
    // top-down BMP: read normally
}
```

---

## 📦 Visual Comparison

```text
Classic BMP File (Bottom-Up)
----------------------------
[Row 3: bottom]
[Row 2]
[Row 1: top]

CS50 BMP File (Top-Down)
------------------------
[Row 1: top]
[Row 2]
[Row 3: bottom]
```

---

## 🧱 Summary

| Format         | biHeight | First Row in File | Last Row in File |
|----------------|----------|-------------------|------------------|
| Classic BMP    | Positive | Bottom            | Top              |
| CS50 BMP       | Negative | Top               | Bottom           |

---

## 🧘 Don’t Stress

> CS50 made it easy: BMPs are **already top-down**.  
> Just loop from top to bottom and you'll be fine.

---

## 🧪 Bonus: Real-World Gotchas

- Always check BMP headers before assuming row order
- If you read rows incorrectly, your image may be vertically flipped
- Libraries like `stb_image` or `Pillow` handle this automatically, but in C — it’s up to you
