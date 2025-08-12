---
title: "Media — Video"  
lang_tags: "#lang/media"
type_tags: "#type/concept"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_0_scratch"
tool_tags: "#tool/codecs #tool/ffmpeg"
atom_idx: 17
status: "done"
difficulty: "easy"
date: "2025-08-12"
timecode: ""
source: "https://cs50.harvard.edu/x/2025/weeks/0/"
review_next: ""
---

## **One-liner**

**Video** = a **sequence of images (frames)** + **audio** + **timing metadata**, compressed by a **codec** and packaged by a **container**.

## Big picture

- **Frames** are pictures. Some are full (**intra-frames**), most store only **differences** from nearby frames (**inter-frames**).  
- A **codec** (coder/decoder) defines the **rules** to compress/decompress streams (e.g., **H.264**, **AV1**).  
- A **container** (e.g., **MP4**, **MKV**) **bundles** the video stream, audio tracks, captions, and **timestamps** into one file.

## 1080p60 reality check

- **Resolution:** 1920 × 1080 ≈ 2 million pixels/frame.  
- **Frame rate:** 60 fps → 60 frames/second.  
- **Raw size would be huge**; with **H.264**, typical online **bitrate** is **3–6 Mbit/s** for watchable quality.  
- Without a codec, raw 1080p60 would be **hundreds of Mbit/s** — impractical for storage/streaming.

### What a codec does (mental model)

1) **Encode** (compress) when saving/streaming.  
2) **Decode** (decompress) when playing back.

## Glossary-on-one-screen

| Term | TL;DR |
|-----|------|
| **Frame** | One picture in the sequence |
| **FPS** | Frames per second (timing cadence) |
| **Bitrate** | How many bits per second after compression |
| **Codec** | Rules/algorithm to compress/decompress (H.264/AV1/HEVC) |
| **Container** | File wrapper for streams + metadata (MP4/MKV) |
| **Keyframe (I‑frame)** | A full, standalone frame |
| **P/B‑frames** | Frames that store *differences* from other frames |

## Practical notes

- Higher **bitrate** ≈ better quality but larger files; **VBR** (variable bitrate) adapts to scene complexity.  
- **Resolution** and **FPS** multiply data needs; 4K60 needs far more bitrate than 1080p30 for similar quality.  
- When editing/exporting, pick a **codec/container** your target platform supports (H.264 in MP4 is the common baseline).

## Related Concepts

- [[Media — Audio]] – audio tracks and compression (AAC/Opus).  
- [[Media — Still Images]] – how single frames compress (JPEG/PNG).  
- [[Binary in Hardware — Voltage Representation]] – bits under the hood.  
- [[Introduction to Binary Logic]] – why compression is possible.  
- [[How computers represent colors using only 0s and 1s]] – pixels and channels.  
- [[Inflatable Duck 🦆 (CS50 Prop)]] – fun prop often used in demos.

## See Also

- [Video codec — overview](https://en.wikipedia.org/wiki/Video_codec)  
- [H.264/MPEG‑4 AVC](https://en.wikipedia.org/wiki/H.264/MPEG-4_AVC)  
- [MP4 (ISO Base Media File Format)](https://en.wikipedia.org/wiki/MP4_file_format)

## Terms

[[video]], [[frame]], [[fps]], [[bitrate]], [[codec]], [[container]], [[intraframe]], [[interframe]], [[keyframe]], [[I-frame]], [[P-frame]], [[B-frame]], [[H.264]], [[AV1]], [[MP4]], [[MKV]]
