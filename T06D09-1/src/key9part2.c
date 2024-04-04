#include <stdio.h>

#define OK 0
#define ERROR 1
#define BREAK 2
#define LEN 100

typedef enum { false, true } bool;

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int input(int *a, int *b, int *a_len, int *b_len);
void output(int *sum, int sum_len, int *sub, int sub_len);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int STATUS = OK;
    int a[LEN], b[LEN], a_len, b_len;
    int sum_res[LEN], sub_res[LEN], sub_len = 0, sum_len = 0;
    if (input(a, b, &a_len, &b_len)) {
        STATUS = ERROR;
    }
    if (STATUS != ERROR) {
        sum(a, a_len, b, b_len, sum_res, &sum_len);
        sub(a, a_len, b, b_len, sub_res, &sub_len);
        output(sum_res, sum_len, sub_res, sub_len);
    }
    if (STATUS == ERROR) printf("n/a");
    return STATUS;
}

int input(int *a, int *b, int *a_len, int *b_len) {
    char c;
    int STATUS = OK;
    for (int i = 0; i < LEN; i++) {
        scanf("%d%c", (a + i), &c);
        *a_len = i;
        if ((c != '\n' && c != ' ') || (*(a + i) < 0 || *(a + i) > 9)) STATUS = ERROR;
        if (c == '\n' || STATUS == ERROR) break;
    }
    for (int i = 0; i < LEN; i++) {
        scanf("%d%c", (b + i), &c);
        *b_len = i;
        if ((c != '\n' && c != ' ') || (*(b + i) < 0 || *(b + i) > 9)) STATUS = ERROR;
        if (c == '\n' || STATUS == ERROR) break;
    }
    return STATUS;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int cur = 0;
    bool flag = false;
    for (int i = 0; i <= (len1 > len2 ? len1 : len2); i++) {
        if (i <= len1 && i <= len2) {
            cur = buff1[len1 - i] + buff2[len2 - i];
        } else if (i > len1) {
            cur = buff2[len2 - i];
        } else if (i > len2) {
            cur = buff1[len1 - i];
        }
        if (flag == true) {
            cur++;
        }
        if (cur >= 10) {
            flag = true;
            cur %= 10;
        } else {
            flag = false;
        }
        result[i] = cur;
        *result_length = *result_length + 1;
    }
    if (flag == true) {
        result[(len1 > len2 ? len1 : len2) + 1] = 1;
        *result_length = *result_length + 1;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (len1 >= len2) {
        int cur = 0;
        bool flag = false;
        for (int i = 0; i <= len1; i++) {
            if (i <= len1 && i <= len2) {
                cur = buff1[len1 - i] - buff2[len2 - i];
            } else if (i > len2) {
                cur = buff1[len1 - i];
            }
            if (flag == true) {
                cur--;
            }
            if (cur < 0) {
                flag = true;
                cur += 10;
                cur %= 10;
            } else {
                flag = false;
            }
            result[i] = cur;
            *result_length = *result_length + 1;
        }
        if (flag == true) {
            *result_length = -1;
        }
    } else {
        *result_length = -1;
    }
}

void output(int *sum, int sum_len, int *sub, int sub_len) {
    bool flag = false;
    for (int i = sum_len - 1; i >= 0; i--) {
        if (!(flag == false && sum[i] == 0)) {
            if (i == 0)
                printf("%d", sum[i]);
            else
                printf("%d ", sum[i]);
            flag = true;
        }
    }
    printf("\n");
    flag = false;
    for (int i = sub_len - 1; i >= 0; i--) {
        if (!(flag == false && sub[i] == 0)) {
            if (i == 0)
                printf("%d", sub[i]);
            else
                printf("%d ", sub[i]);
            flag = true;
        } else if (i == 0)
            printf("0");
    }
    if (sub_len == -1) printf("n/a");
}