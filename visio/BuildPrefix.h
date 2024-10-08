#!/bin/bash

# Имя префикса
PREFIX_NAME=".visio"

# Проверяем, существует ли уже префикс
if [ -d "$HOME/$PREFIX_NAME" ]; then
    echo "Префикс $PREFIX_NAME уже существует."
    exit
fi

env WINEPREFIX="$HOME/$PREFIX_NAME" WINEARCH=win64 winecfg

# Создаем директорию для winetricks
mkdir -p "$HOME/$PREFIX_NAME/drive_c/Program Files/Winetricks"

# Скачиваем winetricks
wget -q -P "$HOME/$PREFIX_NAME/drive_c/Program Files/Winetricks" https://raw.githubusercontent.com/Winetricks/winetricks/master/src/winetricks

# Разрешаем выполнение файла
chmod +x "$HOME/$PREFIX_NAME/drive_c/Program Files/Winetricks/winetricks"

# Запускаем установку дополнительных библиотек
env WINEPREFIX="$HOME/$PREFIX_NAME" WINEARCH=win64 "$HOME/$PREFIX_NAME/drive_c/Program Files/Winetricks/winetricks" -q vcrun2005 vcrun2008 msxml6 gdiplus riched20
