#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR 1

#define N_MAX 100

int** d1(int row, int col);
int** d2(int row, int col);
int** d3(int row, int col);
void input(int** matrix, int row, int col);
void output(int** matrix, int row, int col);
void msort(int** matrix, int row, int col);
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int STATUS = OK;
    int var, c, r;
    if (!(scanf("%d", &var) && var > 0 && var < 4)) {
        STATUS = ERROR;
    }
    if (scanf("%d %d", &r, &c) && (STATUS == OK) && (r < 100 && r > 0) && (c > 0 && c < 100)) {
        int** matrix;
        if (var == 1) {
            matrix = d1(r, c);
            msort(matrix, r, c);
            free(matrix);
        } else if (var == 2) {
            matrix = d2(r, c);
            msort(matrix, r, c);
            for (int i = 0; i < r; i++) {
                free(matrix[i]);
            }
            free(matrix);
        } else if (var == 3) {
            matrix = d3(r, c);
            msort(matrix, r, c);
            free(matrix);
        }
    } else {
        STATUS = ERROR;
        printf("n/a");
    }
    return STATUS;
}

void input(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void output(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col - 1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("%d", matrix[i][col - 1]);
        if (i != row - 1) printf("\n");
    }
}

int** d1(int row, int col) {
    int** matrix = malloc(col * row * sizeof(int) + row * sizeof(int*));
    int* ptr = (int*)(matrix + col);
    for (int i = 0; i < row; i++) {
        matrix[i] = ptr + row * i;
    }
    input(matrix, row, col);

    return matrix;
}

int** d2(int row, int col) {
    int** matrix = malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        matrix[i] = malloc(col * sizeof(int));
    }
    input(matrix, row, col);

    return matrix;
}

int** d3(int row, int col) {
    int** matrix = malloc(row * sizeof(int*));
    int* val = malloc(row * col * sizeof(int));
    for (int i = 0; i < row; i++) {
        matrix[i] = val + col * i;
    }
    input(matrix, row, col);
    free(val);
    return matrix;
}

void quicksort(int* a, int n) {
    int i = 0;
    int j = n - 1;

    int mid = a[n / 2];

    do {
        while (a[i] < mid) {
            i++;
        }
        while (a[j] > mid) {
            j--;
        }
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        quicksort(a, j + 1);
    }
    if (i < n) {
        quicksort(&a[i], n - i);
    }
}

void copy(int** matrix, int** sort, const int* mas, int sum, int row, int col, int i) {
    for (int k = 0; k < row; k++) {
        if (mas[k] == sum) {
            for (int m = 0; m < col; m++) {
                sort[k][m] = matrix[i][m];
            }
        }
    }
}

void msort(int** matrix, int row, int col) {
    int mas[row];
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += matrix[i][j];
        }
        mas[i] = sum;
    }
    quicksort(mas, row);
    int** res = malloc(col * row * sizeof(int) + row * sizeof(int*));
    int* ptr = (int*)(res + col);
    for (int i = 0; i < row; i++) {
        res[i] = ptr + row * i;
    }
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += matrix[i][j];
        }
        copy(matrix, res, mas, sum, row, col, i);
    }
    output(res, row, col);
    free(res);
}