#/bin/bash

# Имя файла
m=$0
if (pwd | grep 'src'); then
cd ..
fi

read -p "Введите название файла: " filename
if [[ "$filename" == "${m:2}" || "$filename" == "$m" ]]; then
    echo "Нельзя изменять текущий файл"
    exit
fi

if [[ ! -f "$filename" ]]; then
    echo "Файла '$filename' не существует."
    exit
fi

if [[ ! -w "$filename" || ! -r "$filename" ]]; then
    echo "В файл '$filename' нельзя записать информацию."
    exit
fi


# Строка поиска
read -p "Введите строку поиска: " search

if ! (grep -q "$search" "$filename" ); then
    echo "В файле нет подстроки '$search'"
    exit
fi

# Строка замены
read -p "Введите строку замены: " replace

if [[ $search != "" && $replace != "" && $filename != "" && $search != $replace ]]; then
    find . -type f -name $filename -exec sed -i '' s/$search/$replace/g {} + 
    if [ $? -eq 0 ]; then
        echo "Все строки с текстом '$search' были заменены"
        echo "src/$filename - $(wc -c $filename | awk '{print $1}') - $(date +"%F %H:%M") - $(shasum -a 256 $filename | awk '{print $1}') - sha256" >> files.log
    else
        echo "Ошибка " $?
    fi
else
    echo "Ошибка, введите уникальный текст"
fi