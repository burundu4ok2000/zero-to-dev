---
title: "Media — Audio"  
lang_tags: "#lang/tools"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: "#tool/audio"
atom_idx: 15
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/0/"
review_next: ""
---

![[Screenshot 2025-06-24 at 10.42.47.png]]

---

## **One-liner**

Digital **audio** stores sound as a stream of **samples** (numbers) taken at a **sample rate** with a chosen **bit depth**; higher values capture more detail but cost more space.

## Key ideas

- **Sampling**: take fast snapshots of air pressure (e.g., **44,100 Hz** for CD).  
- **Bit depth**: bits per sample (e.g., **16-bit** → 65,536 amplitude steps).  
- **Channels**: **mono** (1), **stereo** (2: left + right), or more.  
- **PCM/WAV**: raw or lightly compressed samples (accurate, large).  
- **Lossy codecs** (MP3, AAC): shrink files by discarding inaudible details.  
- **Trade‑off**: more **Hz** and **bits** = better fidelity, bigger files.

## CD‑quality reference

`44.1 kHz · 16-bit · 2 ch` ⇒ **1.411 Mbit/s** raw (≈ **176 kB/s**).

## 16‑bit sample demo

A 16‑bit signed sample is an integer in **–32,768..+32,767**. Two’s‑complement maps binary patterns to these amplitudes.

Example binary: `1001110001100001₂` → some negative amplitude (depends on exact interpretation).

## Why this matters in Week 0

- Audio, images, text — all become **0s and 1s**; audio shows **quantization** (bit depth) and **sampling** (time discretization).  
- Understanding sizes helps you reason about **storage** and **bandwidth**.

## Quick glossary

| Term | Meaning |
|---|---|
| **Sampling** | Taking discrete measurements of sound over time |
| **Sample Rate** | Samples per second (Hz) |
| **Bit Depth** | Bits per sample → dynamic range |
| **Channels** | How many independent streams (mono/stereo/…) |
| **PCM** | Pulse‑Code Modulation; raw sample encoding |
| **WAV** | Container that often holds PCM |
| **Lossy Codec** | MP3/AAC; compress by throwing away masked detail |

## Related Concepts

- [[Binary in Hardware — Voltage Representation]] – how bits are physically represented.  
- [[How computers represent colors using only 0s and 1s]] – media encoding beyond audio.  
- [[ASCII Basics]] – another encoding story (text).  
- [[Artificial Intelligence · CS50x Week 0]] – lecture context for media encodings.  
- [[Introduction to Binary Logic]] – operations on bits that underlie codecs.

## See Also

- [CS50x 2025 — Week 0 overview](https://cs50.harvard.edu/x/2025/weeks/0/)  
- [Wikipedia — Pulse‑code modulation](https://en.wikipedia.org/wiki/Pulse-code_modulation)  
- [Wikipedia — MP3](https://en.wikipedia.org/wiki/MP3)

## Terms

[[sampling]], [[sample rate]], [[bit depth]], [[PCM]], [[WAV]], [[lossy codec]], [[MP3]], [[AAC]], [[stereo]], [[mono]], [[quantization]], [[dynamic range]], [[bitstream]], [[bandwidth]]
