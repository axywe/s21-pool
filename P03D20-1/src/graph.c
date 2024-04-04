#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEIGTH 25
#define LENGTH 80

int main() {
    // input_func();            //чтение строки-функции
    // prefix_calc(x);       //перевод в польскую нотацию и вычисление функции в точке X
    graph_print(func_calc);  //вывод графика

    return 0;
}
