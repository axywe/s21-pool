#include <stdio.h>
#define N_MAX 10

int input(int *a);
void sort(int *a, int n);
void output(int *a);

int main() {
    int data[N_MAX];
    int flag = 1;
    if (input(data)) {
        printf("n/a");
        flag = 1;
    }
    if (!flag) {
        sort(data, 10);
        output(data);
    }
    return 0;
}

int input(int *a) {
    for (int i = 0; i < 10; i++) {
        scanf("%d", (a + i));
    }
    return 0;
}

void sort(int *a, int n) {
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
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        sort(a, j + 1);
    }
    if (i < n) {
        sort(&a[i], n - i);
    }
}

void output(int *a) {
    for (int i = 0; i < 9; i++) {
        printf("%d ", *(a + i));
    }
    printf("%d", *(a + 10));
}