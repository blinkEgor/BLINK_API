#!/bin/bash
# ----------------------------------------
# pack_api.sh — упаковка слоя абстракий BLINK_API для релиза
# Автор: Егор
#
# Инструкция:
# 	chmod +x pack_api.sh		# дать права
# 	./pack_api.sh			# запустить
# 	unzip -l dist/API.zip		# распокавать
# ----------------------------------------

# === ПАРАМЕТРЫ ===

ZIP_NAME="API"

LIBRARY_BIN="libblink_api.so"

DIST_DIR="dist"
BIN_DIR="bin"
CONFIG_DIR="configs/api_plugins"
INCLUDE_DIR="include/blink_api"
ABSTRACTION_DIR="include/blink_api/abstractions"
STUB_DIR="include/blink_api/stubs"

README_API_FILE="README_API.md"
LICENSE_FILE="LICENSE"

if [ ! -z "$1" ]; then
	ZIP_NAME=$1
fi

# === СОЗДАНИЕ ===
echo "=== Creating a structure in $DIST_DIR/$ZIP_NAME ==="

mkdir -p $DIST_DIR/$ZIP_NAME/$BIN_DIR
mkdir -p $DIST_DIR/$ZIP_NAME/$CONFIG_DIR
mkdir -p $DIST_DIR/$ZIP_NAME/$INCLUDE_DIR
mkdir -p $DIST_DIR/$ZIP_NAME/$ABSTRACTION_DIR
mkdir -p $DIST_DIR/$ZIP_NAME/$STUB_DIR

# Вывод созданной структуры

if command -v tree &> /dev/null; then
	tree $DIST_DIR/$ZIP_NAME
else
	echo "Directory structure created at: $DIST_DIR/$ZIP_NAME"
	echo "	- $BIN_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$BIN_DIR" 2>/dev/null || echo " 	(empty)"
	echo "	- $CONFIG_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$CONFIG_DIR" 2>/dev/null || echo " 	(empty)"
	echo "	- $INCLUDE_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$INCLUDE_DIR" 2>/dev/null || echo " 	(empty)"
	echo "	- $ABSTRACTION_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$ABSTRACTION_DIR" 2>/dev/null || echo " 	(empty)"
	echo "	- $STUB_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$STUB_DIR" 2>/dev/null || echo " 	(empty)"
	echo "(Install 'tree' command for visual directory tree)"
fi

# === КОПИРОВАНИЕ ===
echo "=== Copying files ==="


copy_with_check() {
	local src=$1
	local dst=$2
	if [ -f "$src" ] || [ -d "$src" ]; then
		cp -rf "$src" "$dst" && echo "[OK] $src -> $dst"
	else
		echo "[MISSED] $src not found"
		return 1
	fi
}

# Библиотека
copy_with_check "$BIN_DIR/$LIBRARY_BIN" "$DIST_DIR/$ZIP_NAME/$BIN_DIR/"

# Конфиги
copy_with_check "$CONFIG_DIR/" "$DIST_DIR/$ZIP_NAME/configs/"

# Заголовки
copy_with_check "$INCLUDE_DIR/" "$DIST_DIR/$ZIP_NAME/include/"

# Документация
copy_with_check "$README_API_FILE" "$DIST_DIR/$ZIP_NAME/"
copy_with_check "$LICENSE_FILE" "$DIST_DIR/$ZIP_NAME/"

# Удаляем временные файлы если нужно
find "$DIST_DIR/$ZIP_NAME" -name "*.in" -type f -delete

# === ЗАПАКОВКА В АРХИВ ZIP ===
echo "=== Creating an archive ==="

cd "$DIST_DIR" || exit 1
zip -r "$ZIP_NAME.zip" "$ZIP_NAME" > /dev/null && echo "[OK] Archive created: $ZIP_NAME.zip" || echo "[ERROR] Failed to create archive"
cd ..

# === ИТОГ ===
echo "=== Ready! ==="

if command -v tree &> /dev/null; then
	tree $DIST_DIR/$ZIP_NAME
else
	echo "Final directory structure at: $DIST_DIR/$ZIP_NAME"
	echo "	- $BIN_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$BIN_DIR" 2>/dev/null || echo " 	(empty)"
	echo "	- $CONFIG_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$CONFIG_DIR" 2>/dev/null || echo " 	(empty)"
	echo "	- $INCLUDE_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$INCLUDE_DIR" 2>/dev/null || echo " 	(empty)"
	echo "	- $ABSTRACTION_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$ABSTRACTION_DIR" 2>/dev/null || echo " 	(empty)"
	echo "	- $STUB_DIR: " && ls -1 "$DIST_DIR/$ZIP_NAME/$STUB_DIR" 2>/dev/null || echo " 	(empty)"
	echo "(Install 'tree' command for visual directory tree)"
fi


echo "Result: $DIST_DIR/$ZIP_NAME | $DIST_DIR/$ZIP_NAME.zip"
