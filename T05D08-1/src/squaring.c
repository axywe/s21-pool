#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main() {
    int n, data[NMAX];
    int res = input(data, &n);
    if (res != 0) {
        printf("n/a");
        return 1;
    }
    squaring(data, &n);
    output(data, &n);
    return 0;
}

int input(int *a, int *n) {
    char c;
    scanf("%d%c", n, &c);
    if (c != '\n' || *n < 1 || *n > NMAX) return 1;
    for (int i = 0; i < *n; i++) {
        scanf("%d%c", (a + i), &c);
        if (c != '\n' && c != ' ') return 1;
    }
    return 0;
}

void output(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (i == *n - 1)
            printf("%d", *(a + i));
        else
            printf("%d ", *(a + i));
    }
    return;
}

void squaring(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        *(a + i) *= *(a + i);
    }
    return;
}
