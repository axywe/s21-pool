#include <stdio.h>
#include <stdlib.h>

double **alloc(int row, int column) {
    double **arr = (double **)malloc(row * column * sizeof(double) + row * sizeof(double *));
    double *ptr = (double *)(arr + row);
    for (int r = 0; r < row; r++) {
        arr[r] = ptr + column * r;
    }
    return arr;
}

double xor_double(double a, double b) {
    unsigned long long int *pa = (unsigned long long int *)&a;
    unsigned long long int *pb = (unsigned long long int *)&b;
    unsigned long long int result = *pa ^ *pb;
    return *(double *)&result;
}

void input(double **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

double det(double **matrix, int n) {
    int i, j, k;
    double det = 1.0;
    double temp;

    for (i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            int found = 0;
            for (j = i + 1; j < n; j++) {
                if (matrix[j][i] != 0) {
                    found = 1;
                    for (k = i; k < n; k++) {
                        temp = matrix[i][k];
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = temp;
                    }
                    det *= -1.0;
                    break;
                }
            }
            if (found == 0) {
                return 0.0;
            }
        }
        for (j = i + 1; j < n; j++) {
            temp = matrix[j][i] / matrix[i][i];
            for (k = i; k < n; k++) {
                matrix[j][k] -= matrix[i][k] * temp;
            }
        }
        det *= matrix[i][i];
    }

    return det;
}

int main() {
    int i, j, k;
    int row, col;
    scanf("%d %d", &row, &col);
    if (row != col || row < 1 || col < 1) {
        printf("n/a");
        return 1;
    }
    double **Ai = alloc(row, col);
    input(Ai, row, col);
    if (det(Ai, row) == 0) {
        printf("n/a");
        return 0;
    }
    int n = row;
    double **A = alloc(row, col * 2);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) A[i][j] = Ai[i][j];
    for (i = 0; i < n; i++)
        for (j = n; j < 2 * n; j++) {
            if (i + n == j)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }

    for (i = 0; i < n; i++) {
        if (A[i][i] == 0)
            for (j = i + 1; j < n; j++) {
                if (A[j][i] == 1) {
                    for (k = 0; k < 2 * n; k++) {
                        double c = A[j][k];
                        A[j][k] = A[i][k];
                        A[i][k] = c;
                    }
                    break;
                }
            }
        for (k = i + 1; k < n; k++) {
            if (A[k][i] == 1) {
                for (j = 0; j < 2 * n; j++) {
                    xor_double(A[k][j], A[i][j]);
                }
            }
        }
    }
    for (i = n - 1; i >= 0; i--) {
        for (k = i - 1; k >= 0; k--) {
            if (A[k][i] == 1) {
                for (j = 0; j < 2 * n; j++) xor_double(A[k][j], A[i][j]);
            }
        }
    }

    double B[row][col];
    for (i = 0; i < n; i++)
        for (j = 0, k = n; j < n; j++, k++) B[i][j] = A[i][k];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf", B[i][j]);
            if (j != n - 1) printf(" ");
        }
        if (i != n - 1) printf("\n");
    }
    return 0;
}