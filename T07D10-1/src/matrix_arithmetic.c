#include <stdio.h>
#include <stdlib.h>

#define ERROR 1
#define OK 0

void sum(int** m1, int n, int m, int** m2);
void transpose(int** matrix, int n, int m, int** res);
void mul(int** matrix_first, int n_first, int m_first, int** matrix_second, int m_second,
         int** matrix_result);
void input(int** matrix, int row, int col);
void output(int** matrix, int row, int col);
int** alloc(int r, int c);
void method(int* m);
void size(int* row, int* col);

int main() {
    int STATUS = OK;
    int m, row, col, row2, col2;
    method(&m);
    size(&row, &col);
    if (m == -1 || row == -1) {
        STATUS = ERROR;
        // printf("%d %d", m, row);
    }
    if (STATUS == OK) {
        if (m == 1) {
            int** m1 = alloc(row, col);
            input(m1, row, col);
            //     output(m1, row, col);
            size(&row2, &col2);
            int** m2 = alloc(row, col);
            if (row2 != row || col2 != col) {
                STATUS = ERROR;
            } else {
                input(m2, row2, col2);
                sum(m1, row, col, m2);
                output(m1, row, col);
            }
            if (m2 != NULL) free(m2);
            if (m1 != NULL) free(m1);
        } else if (m == 2) {
            int** m1 = alloc(row, col);
            input(m1, row, col);
            size(&row2, &col2);
            if (row2 != -1 && row != col2) {
                int** m2 = alloc(row2, col2);
                input(m2, row2, col2);
                int** res = alloc(row, col2);
                mul(m1, row, col, m2, col2, res);
                output(res, row, col2);
                if (m2 != NULL) free(m2);
                if (res != NULL) free(res);
            } else {
                STATUS = ERROR;
            }

            if (m1 != NULL) free(m1);
        } else if (m == 3) {
            int** m1 = alloc(row, col);
            int** res = alloc(col, row);
            input(m1, row, col);
            transpose(m1, row, col, res);
            output(res, col, row);
            if (m1 != NULL) free(m1);
            if (res != NULL) free(res);
        }
    }
    if (STATUS == ERROR) printf("n/a");
    return STATUS;
}

void mul(int** matrix_first, int n_first, int m_first, int** matrix_second, int m_second,
         int** matrix_result) {
    for (int r = 0; r < n_first; r++) {
        for (int c = 0; c < m_second; c++) {
            matrix_result[r][c] = 0;
            for (int i = 0; i < m_first; i++) {
                matrix_result[r][c] += matrix_first[r][i] * matrix_second[i][c];
            }
        }
    }
}

void transpose(int** matrix, int row, int col, int** res) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[j][i] = matrix[i][j];
        }
    }
}

void sum(int** m1, int n, int m, int** m2) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            m1[i][j] += m2[i][j];
        }
    }
}

void method(int* m) {
    if (!(scanf("%d", m) == 1 && *m > 0 && *m < 4)) {
        *m = -1;
    }
}

void size(int* row, int* col) {
    if (!(scanf("%d%d", row, col) == 2 && *row > 0 && *row <= 100 && *col > 0 && *col <= 100)) {
        *row = -1;
    }
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
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
            if (j != col - 1) printf(" ");
        }
        if (i != row - 1) printf("\n");
    }
}

int** alloc(int row, int column) {
    int** arr = (int**)malloc(row * column * sizeof(int) + row * sizeof(int*));
    int* ptr = (int*)(arr + row);
    for (int r = 0; r < row; r++) {
        arr[r] = ptr + column * r;
    }
    return arr;
}