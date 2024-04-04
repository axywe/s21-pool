#Файл
# read -p "Введите название файла для анализа: " filename
filename=$"src/files.log"
if [[ ! -r "$filename" ]]; then
    echo "Файл '$filename' недоступен для чтения."
    exit
fi

array=()
hash=()
while read -r line
do
tmp=(${line//-/ })
array+=("${tmp[0]}")
hash+=("${tmp[6]}")
# echo $hash
# echo $array
done < $filename

array=($(echo "${array[@]}" | tr ' ' '\n' | sort -u | tr '\n' ' '))
num=$(wc -l $filename | awk '{print $1}')
echo ${hash[@]}

#Вывод
echo "$num" "${#array[@]}" "$(($num-${#array[@]}))"