```
#!/bin/bash

# Папка с PNG
SOURCE_DIR="/Users/stasnislavburundukov/Library/Mobile Documents/iCloud~md~obsidian/Documents/zero-to-dev/98_Images"

# Подпапка для оригиналов
LAST_DIR="$SOURCE_DIR/last"

# Создаём папку last, если её нет
mkdir -p "$LAST_DIR"

# Проходим по всем .png
for file in "$SOURCE_DIR"/*.png; do
    # Проверяем, что это действительно файл
    [ -f "$file" ] || continue
    
    filename=$(basename "$file")
    
    # Временный файл сжатого изображения
    tmp_file="$SOURCE_DIR/tmp_$filename"
    
    # Сжимаем PNG (qscale не работает, поэтому используем compression_level)
    ffmpeg -y -i "$file" -compression_level 100 -pred mixed "$tmp_file"
    
    # Перемещаем оригинал в last
    mv "$file" "$LAST_DIR/$filename"
    
    # Переименовываем сжатый файл в оригинальное имя
    mv "$tmp_file" "$SOURCE_DIR/$filename"
    
    echo "Сжат: $filename"
done

echo "Готово! Оригиналы в $LAST_DIR"

```