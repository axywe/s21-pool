#include <stdio.h>
#include <stdlib.h>

int input(int *a, int count);
void sort(int *a, int n);
void output(int *a, int count);

int main() {
    int flag = 0;
    int count;
    scanf("%d", &count);
    int *data = malloc(count * sizeof(int));
    if (input(data, count)) {
        printf("n/a");
        flag = 1;
    }
    if (flag) {
        sort(data, count);
        output(data, count);
    }
    free(data);
    return 0;
}

int input(int *arr, int count) {
    for (int i = 0; i < count; i++) {
        scanf("%d", (arr + i));
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

void output(int *a, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", *(a + i));
    }
    printf("\b");
    // printf("%d", *(a + count));
}
