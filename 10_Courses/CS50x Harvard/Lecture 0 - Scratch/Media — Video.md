[[CS50x Harvard]] · [[10_Courses/CS50x Harvard/00_Lectures/Lecture 0 - Scratch]]
tags: #video #codec #h264

**Video = sequence of images + audio + timing metadata**

| Layer         | Stored As / With                                       |
| ------------- | ------------------------------------------------------ |
| **Frames**    | Intraframes (full) + Interframes (differences)         |
| **Codec**     | H.264, AV1, etc. (rules to compress/decompress)        |
| **Container** | MP4, MKV (package frames, audio, captions, timestamps) |
|               |                                                        |

### 1080p60 Example
- **Resolution:** 1920 × 1080 → ≈2 M pixels/frame  
- **Frame rate:** 60 fps → 60 frames/second  
- **Codec:** H.264 (widely supported)  
- **Bitrate:** **3–6 Mbit/s** compressed stream (suitable for online playback)

#### What a codec does
1. 🔐 *Encode* (compress) on save/stream  
2. 🔓 *Decode* (decompress) on playback

Without a codec, raw 1080p60 would be **hundreds of Mbit/s** — impractical for storage or streaming.