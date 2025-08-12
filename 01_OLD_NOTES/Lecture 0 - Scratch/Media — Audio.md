[[CS50x Harvard]] · [[10_Courses/CS50x Harvard/00_Lectures/Lecture 0 - Scratch]]
tags: #audio #sampling #pcm #mp3

## Key Terms
| Term            | Meaning                                                                                             |
| --------------- | --------------------------------------------------------------------------------------------------- |
| **Sampling**    | “Snapshots” of sound pressure many times per second.                                                |
| **Sample Rate** | Samples/second; CD uses **44 100 Hz**.                                                              |
| **Bit Depth**   | Bits per sample; 16-bit → 65 536 amplitude steps.                                                   |
| **Channels**    | 2 channels = stereo (left + right).                                                                 |
| **PCM / WAV**   | Raw or lightly compressed samples (big files, accurate).                                            |
| **Lossy Codec** | MP3, AAC — discard inaudible data to shrink size.<br><br>![[Screenshot 2025-06-24 at 10.42.47.png]] |

### CD-Quality Example
`44.1 kHz · 16 bits · 2 ch` ⇒ **1.411 Mbit/s** raw  
(≈176 kB per second)

### 16-bit Sample Demo
Binary `1001110001100001₂` → decimal **–24 287** to **+24 288** (2’s-complement amplitude).

**Bottom line:** higher sample rate + bit depth = better fidelity but larger files; lossy codecs trade fidelity for size.