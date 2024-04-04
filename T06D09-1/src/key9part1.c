/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX], out[NMAX];
    int res = input(data, &n);
    if (res) {
        printf("n/a");
        return 1;
    }
    int sum = sum_numbers(data, n);
    printf("%d\n", sum);
    int size = find_numbers(data, n, sum, out);
    output(out, size);
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        }
    }
    return count;
}

int input(int *a, int *n) {
    char c;
    scanf("%d%c", n, &c);
    if (c != '\n' || *n < 1 || *n > NMAX) return 1;
    for (int i = 0; i < *n; i++) {
        if (scanf("%d%c", (a + i), &c) > 30) return 1;
        if (c != '\n' && c != ' ') return 1;
    }
    return 0;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i != length - 1)
            printf("%d ", buffer[i]);
        else
            printf("%d", buffer[i]);
    }
    return;
}