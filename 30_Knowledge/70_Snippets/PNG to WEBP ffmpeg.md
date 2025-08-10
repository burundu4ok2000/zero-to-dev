
Ниже два режима:

- **LOSSY (рекомендуется)**: очень маленький вес при хорошем качестве.
    
- **LOSSLESS**: без потерь, обычно меньше PNG на 20–50%.
    

  

Вот удобный скрипт для macOS: конвертит все .png в .webp, кладёт результат рядом с исходником, а оригиналы переносит в папку last. Считает экономию по каждому файлу.

```
#!/bin/bash
# convert_png_to_webp.sh
# Зависимости: ffmpeg (и желательно libwebp). Установить: brew install ffmpeg

# ====== НАСТРОЙКИ ======
# РЕЖИМ: lossy или lossless
MODE="lossy"           # "lossy" | "lossless"
QUALITY=82             # для lossy: 70–90 обычно оптимально
ALPHA_QUALITY=90       # качество альфа-канала в lossy режиме (0–100)
COMPRESSION_LEVEL=6    # 0–6 (6 = медленнее, но лучше сжатие)
# =======================

# Папка с PNG — можно перетащить папку в терминал на место "$1"
SOURCE_DIR="${1:-/path/to/your/folder}"
if [ ! -d "$SOURCE_DIR" ]; then
  echo "Укажи существующую папку. Пример: ./convert_png_to_webp.sh \"/Users/you/Pictures\""
  exit 1
fi

LAST_DIR="$SOURCE_DIR/last"
mkdir -p "$LAST_DIR"

shopt -s nullglob

total_before=0
total_after=0

for file in "$SOURCE_DIR"/*.png "$SOURCE_DIR"/*.PNG; do
  [ -f "$file" ] || continue
  base="$(basename "$file")"
  name="${base%.*}"
  out="$SOURCE_DIR/$name.webp"

  # размеры до
  size_before=$(stat -f%z "$file" 2>/dev/null || stat -c%s "$file")
  total_before=$((total_before + size_before))

  if [ "$MODE" = "lossless" ]; then
    # Без потерь
    ffmpeg -y -i "$file" -c:v libwebp -lossless 1 -compression_level "$COMPRESSION_LEVEL" "$out"
  else
    # Потерянное, с поддержкой прозрачности
    ffmpeg -y -i "$file" -c:v libwebp -lossless 0 -q:v "$QUALITY" -compression_level "$COMPRESSION_LEVEL" -alpha_quality "$ALPHA_QUALITY" "$out"
  fi

  if [ $? -ne 0 ] || [ ! -f "$out" ]; then
    echo "Ошибка при конвертации: $base — пропускаю"
    continue
  fi

  # размеры после
  size_after=$(stat -f%z "$out" 2>/dev/null || stat -c%s "$out")
  total_after=$((total_after + size_after))

  # перенос оригинала
  mv -f "$file" "$LAST_DIR/$base"

  # отчёт по файлу
  saved=$((size_before - size_after))
  if [ $size_before -gt 0 ]; then
    percent=$(( 100 * saved / size_before ))
  else
    percent=0
  fi
  echo "✅ $base -> $name.webp | было: $((size_before/1024)) KB, стало: $((size_after/1024)) KB (−$percent%)"
done

echo "---------------------------"
echo "ИТОГО:"
echo "Было:  $((total_before/1024)) KB"
echo "Стало: $((total_after/1024)) KB"
if [ $total_before -gt 0 ]; then
  total_saved=$((total_before - total_after))
  total_percent=$(( 100 * total_saved / total_before ))
  echo "Экономия: −$total_percent% (≈ $((total_saved/1024)) KB)"
fi
echo "Оригиналы лежат в: $LAST_DIR"
```

### **Как использовать**

1. Сохрани как convert_png_to_webp.sh.
    
2. Выдай права:
    

```
chmod +x convert_png_to_webp.sh
```

2.   
    
3. Запусти, перетащив папку в терминал:
    

```
./convert_png_to_webp.sh "/путь/к/папке"
```

3. (или пропиши путь в переменную SOURCE_DIR внутри файла)
    

  

### **Что ожидать по размеру**

- **LOSSY (рекомендую, QUALITY≈80–85):** чаще всего минус **60–90%**.
    
    Пример: из 1 МБ → **100–400 КБ** (зависит от картинки и прозрачности).
    
- **LOSSLESS:** минус **20–50%** по сравнению с PNG, иногда больше/меньше.
    

  