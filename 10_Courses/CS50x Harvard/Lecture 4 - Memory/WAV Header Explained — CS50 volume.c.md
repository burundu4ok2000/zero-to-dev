---
title: "WAV Header Explained — CS50 volume.c"
status: done
date: "2025-08-27"
source: "#course/cs50x/introduction_to_CS"
review_next: "2025-09-27"
---

## 🧠 What Is a Header in a WAV File?

In the context of the **volume.c** problem from CS50, a **header** refers to the first 44 bytes of a **WAV file**, which contain metadata about the file rather than audio content.

Think of the header as the file’s passport. It tells the program:

- What format it is (WAV, MP3, FLAC, etc.)
- How many channels (mono, stereo)
- The sample rate (e.g., 44100 Hz)
- Bits per sample (e.g., 16-bit)
- Total file size, and more

---

## 📦 Basic Structure of a WAV File

```ascii
┌────────────────────┐
│ Header (44 bytes)  │  ← Contains file metadata
├────────────────────┤
│ Sample 1 (2 bytes) │
│ Sample 2 (2 bytes) │
│ Sample 3 (2 bytes) │
│        ...         │
└────────────────────┘
```

Each **sample** is just a number representing the **amplitude** of the sound wave at a specific point in time — typically a signed 16-bit integer (−32,768 to +32,767).

---

## 🧑‍💻 In the C Code

CS50 provides the constant:

```c
#define HEADER_SIZE 44
```

And this is how you use it:

```c
uint8_t header[HEADER_SIZE];             // Create a 44-byte array
fread(header, HEADER_SIZE, 1, input);    // Read header from input file
fwrite(header, HEADER_SIZE, 1, output);  // Write header to output file
```

This ensures the structure and metadata of the WAV file are preserved, allowing media players to recognize and play it correctly.

---

## 🧠 Core Idea

> "**The header is everything before the sound. Without it, a player won’t even know it’s a sound file.**"

---

## 🔗 Related Concepts

[[volume.c]], [[fread]], [[fwrite]], [[sample]], [[byte]], [[audio file formats]]
