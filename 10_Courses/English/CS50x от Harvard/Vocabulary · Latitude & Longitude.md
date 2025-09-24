---
title: "Vocabulary · Latitude & Longitude"
lang_tags: "#lang/english"
type_tags: "#type/vocabulary"
course_tags: ""
lecture_tags: ""
tool_tags: ""
status: "done"
difficulty: "easy"
date: "2025-09-24"
source: ""
review_next: ""
---

## 📖 Definition
**Latitude** — a geographic coordinate telling how far **north** or **south** you are from the **Equator** (in degrees).  
**Longitude** — a geographic coordinate telling how far **east** or **west** you are from the **Prime Meridian** (in degrees).

---

## 🔍 In Context
- **Latitude** range: **−90°** (South Pole) → **0°** (Equator) → **+90°** (North Pole). Positive = **north**, negative = **south**.  
- **Longitude** range: **−180° … +180°** (west negative, east positive), 0° at **Greenwich**.

**Example (tuple: `(lat, lon)`)**  
```python
point = (51.5, -0.12)
# 51.5  → latitude  ≈ 51.5° N (London-ish)
# -0.12 → longitude ≈ 0.12° W (London area)
```

---

## 🧠 Very Simple
- **Latitude** = “**up/down**” on the globe.  
- **Longitude** = “**side to side**”.  
Together they **pin a location** on Earth.

---

## 🔊 Pronunciation
**latitude** /ˈlæt.ɪ.tjuːd/ · **longitude** /ˈlɒn.dʒɪ.tjuːd/

---

## ✅ Examples
- “The city sits at **52.5° N, 13.4° E**.”  
- “Use **latitude/longitude** to plot a point on a map.”

---

## 📝 Quick Notes
- Often written as **decimal degrees**: `(lat, lon)` like `(37.7749, -122.4194)`.
- Alternative: **degrees‑minutes‑seconds (DMS)** format, e.g., `37°46′29.6″N 122°25′09.8″W`.
- The common global datum is **WGS84** (used by GPS).

---

## Related Concepts
- [[Coordinate system — Geographic]] – how Earth positions are defined
- [[Prime Meridian & Equator]] – reference lines for **0° longitude** and **0° latitude**
- [[Decimal degrees vs DMS]] – formats you’ll see in code and maps
- [[Haversine distance]] – compute distance between two **lat/lon** points
- [[Great‑circle route]] – shortest path on a sphere
- [[Geocoding & Reverse geocoding]] – addresses ⇄ coordinates
- [[WGS84 & Datums]] – why the same place can have slightly different numbers
- [[Map projections (Mercator, etc.)]] – turning the sphere into a flat map

---

## See Also
- [Latitude — Wikipedia](https://en.wikipedia.org/wiki/Latitude)
- [Longitude — Wikipedia](https://en.wikipedia.org/wiki/Longitude)
- [What is GPS? — NOAA](https://oceanservice.noaa.gov/facts/gps.html)
