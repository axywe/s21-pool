#include <stdio.h>
#include <stdlib.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int (*picture)[M], int n, int m);
void reset_picture(int (*picture)[M], int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    int arr[N];
    transform(arr, picture, N, M);
    make_picture(picture_data, N, M);
    return 0;
}

void make_picture(int (*picture)[M], int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);
    for (int i = 0; i < 4; i++) {
        for (long unsigned int j = 0; j < (sizeof(tree_foliage) / sizeof(tree_foliage[0])); j++) {
            if (i == 0) {
                picture[3][2 + j] = tree_foliage[j];
            } else if (i == 1) {
                picture[4][2 + j] = tree_foliage[j];
            } else if (i == 2) {
                picture[2 + j][3] = tree_foliage[j];
            } else if (i == 3) {
                picture[2 + j][4] = tree_foliage[j];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (long unsigned int j = 0; j < (sizeof(tree_trunk) / sizeof(tree_trunk[0])); j++) {
            if (i == 0) {
                picture[6 + j][3] = tree_trunk[j];
            } else if (i == 1) {
                picture[6 + j][4] = tree_trunk[j];
            } else if (i == 2) {
                picture[10][2 + j] = tree_trunk[j];
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            picture[1 + i][7 + j] = sun_data[i][j];
        }
    }
    for (long unsigned int i = 0; i < (sizeof(frame_w) / sizeof(frame_w[0])); i++) {
        picture[0][i] = frame_w[i];
        picture[n - 1][i] = frame_w[i];
        picture[n / 2][i] = frame_w[i];
    }
    for (long unsigned int i = 0; i < (sizeof(frame_h) / sizeof(frame_h[0])); i++) {
        picture[i][0] = frame_h[i];
        picture[i][m - 1] = frame_h[i];
        picture[i][m / 2] = frame_h[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", picture[i][j]);
            if (j + 1 < m) printf(" ");
        }
        if (i + 1 < n) printf("\n");
    }
}

void reset_picture(int (*picture)[M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}
