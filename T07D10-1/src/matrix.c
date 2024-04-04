#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR 1

#define N_MAX 100

int** d1(int row, int col);
int** d2(int row, int col);
int** d3(int row, int col);
void d4(int matrix[][N_MAX], int row, int col);
void input(int** matrix, int row, int col);
void output(int** matrix, int row, int col);

int main() {
    int STATUS = OK;
    int var, c, r;
    if (!(scanf("%d", &var) && var > 0 && var < 5)) {
        STATUS = ERROR;
    }
    if (scanf("%d %d", &r, &c) && (STATUS == OK) && (r < 100 && r > 0) && (c > 0 && c < 100)) {
        if (var == 1) {
            int** matrix;
            matrix = d1(r, c);
            free(matrix);
        } else if (var == 2) {
            int** matrix;
            matrix = d2(r, c);
            for (int i = 0; i < r; i++) {
                free(matrix[i]);
            }
            free(matrix);
        } else if (var == 3) {
            int** matrix;
            matrix = d3(r, c);
            free(matrix);
        } else if (var == 4) {
            int matrix_static[N_MAX][N_MAX];
            d4(matrix_static, r, c);
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
    output(matrix, row, col);

    return matrix;
}

int** d2(int row, int col) {
    int** matrix = malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        matrix[i] = malloc(col * sizeof(int));
    }
    input(matrix, row, col);
    output(matrix, row, col);

    return matrix;
}

int** d3(int row, int col) {
    int** matrix = malloc(row * sizeof(int*));
    int* val = malloc(row * col * sizeof(int));
    for (int i = 0; i < row; i++) {
        matrix[i] = val + col * i;
    }
    input(matrix, row, col);
    output(matrix, row, col);
    free(val);
    return matrix;
}

void d4(int matrix[][N_MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col - 1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("%d", matrix[i][col - 1]);
        if (i != row - 1) printf("\n");
    }
}