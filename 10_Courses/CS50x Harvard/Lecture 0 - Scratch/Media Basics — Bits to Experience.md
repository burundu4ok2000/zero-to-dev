---
title: "Media Basics — Bits to Experience"  
lang_tags: "#lang/tools"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: ""
atom_idx: 18
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/0/"
review_next: ""
---

## **One-liner**

How raw **bits** become human experience: encode **text**, **images**, **audio**, and **video** via **sampling**, **quantization**, and **compression**—then decode on playback.

## Big picture: bit → experience pipeline

1. **Sensing / Source** – microphone, camera sensor, file.  
2. **Sampling** – take values at discrete times/positions (e.g., **44.1 kHz** audio, **1920×1080** pixels).  
3. **Quantization** – map continuous values to discrete steps (e.g., **8-bit** or **24-bit** color per channel).  
4. **Encoding** – pack numbers using formats like **ASCII/Unicode**, **BMP/PNG/JPEG**, **WAV/MP3**, **RAW/H.264**.  
5. **Compression** – **lossless** (PNG, FLAC) vs **lossy** (JPEG, MP3) to shrink size.  
6. **Storage/Transmission** – files, **bitrate** (kbps, Mbps), streams.  
7. **Decoding/Rendering** – reverse the process and show/play.

## Units you’ll see

- **bit** (0 or 1) and **byte** (8 bits).  
- **Resolution** (e.g., 1080p) and **color depth** (e.g., 24‑bit → ~16.7M colors).  
- **Sample rate** (audio **Hz**) and **bit depth** (16‑bit, 24‑bit).  
- **Frame rate** (**fps**) for video; **bitrate** (kbps/Mbps) for streams.  

> Rule of thumb: more **samples** × more **bits per sample** = better fidelity and bigger files.

## Worked mini‑examples

### Text
- **ASCII** maps characters to numbers (e.g., `'A'` → **65**). Extended sets use **Unicode**/**UTF‑8**.

### Image (RGB)
- One pixel: **R,G,B** each 8 bits → **24 bits/pixel**.  
- 1920×1080 image (uncompressed): 2,073,600 pixels × 3 bytes ≈ **~6 MB**.

### Audio
- Mono **CD quality**: 44,100 samples/sec × 16 bits ≈ **705.6 kbps**; stereo doubles that.  
- **MP3/AAC** compress with **lossy** psychoacoustics to ~128–256 kbps.

### Video
- 1080p30 uncompressed: 1920×1080×3 bytes × 30 fps ≈ **~178 MB/s** → requires **codecs** (e.g., **H.264**) to be practical.

## Lossless vs lossy

| Property | **Lossless** | **Lossy** |
|---|---|---|
| Keeps originals exactly? | Yes | No (throws away imperceptible data) |
| Typical formats | **PNG**, **FLAC**, **ZIP** | **JPEG**, **MP3**, **AAC**, **H.264** |
| Use when | Archiving, source assets | Streaming, distribution |
| Artifact risk | None | **Compression artifacts** (blocking, ringing) |

## Gotchas

- **Bitrate ≠ quality** across different **codecs**—efficiency varies.  
- **Color subsampling** (e.g., 4:2:0) reduces chroma detail to save bits.  
- **Integer truncation** vs **floating point** rounding when converting numbers.  
- Confusing **container** (MP4, MKV) with **codec** (H.264, AAC).

## Quick mental models

- **Sampling** = “how often do we measure?”  
- **Quantization** = “how many buckets do we round into?”  
- **Compression** = “how do we pack it tighter (maybe discarding some)?”

## Related Concepts

- [[ASCII Basics]] – text as numbers.  
- [[Media — Still Images]] – resolution, color depth, formats.  
- [[Media — Audio]] – sample rate, bit depth, psychoacoustics.  
- [[Media — Video]] – frames, codecs, containers.  
- [[How computers represent colors using only 0s and 1s]] – RGB and encoding.  
- [[Binary in Hardware — Voltage Representation]] – what a **bit** is in circuits.

## See Also

- [CS50x 2025 — Week 0 overview](https://cs50.harvard.edu/x/2025/weeks/0/)  
- [Sampling (signal processing) — Wikipedia](https://en.wikipedia.org/wiki/Sampling_(signal_processing))  
- [Codec vs Container — HandBrake Docs](https://handbrake.fr/docs/en/latest/technical/container-and-codecs.html)

## Terms

[[bit]], [[byte]], [[sampling]], [[quantization]], [[resolution]], [[color depth]], [[sample rate]], [[bit depth]], [[frame rate]], [[bitrate]], [[codec]], [[container]], [[lossless]], [[lossy]], [[artifact]]
