#include <stdio.h>
#define N_MAX 10

int input(int *a, int *b);
void sort1(int *a, int n);
void heapSort(int *arr, int N);
void heapify(int *arr, int N, int i);
void output(int *a, int *b);
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int data[N_MAX], data2[N_MAX];
    if (input(data, data2)) {
        printf("n/a");
        return 1;
    }
    sort1(data, 10);
    heapSort(data2, 10);
    output(data, data2);
    return 0;
}
int input(int *a, int *b) {
    char c;
    for (int i = 0; i < 10; i++) {
        scanf("%d%c", (a + i), &c);
        if (c != ' ' && c != '\n') {
            return 1;
        }
        *(b + i) = *(a + i);
    }
    return 0;
}

void sort1(int *a, int n) {
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
        sort1(a, j + 1);
    }
    if (i < n) {
        sort1(&a[i], n - i);
    }
}

void heapify(int *arr, int N, int i) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest]) largest = left;

    if (right < N && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, N, largest);
    }
}

void heapSort(int *arr, int N) {
    for (int i = N / 2 - 1; i >= 0; i--) heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--) {
        swap((arr), (arr + i));

        heapify(arr, i, 0);
    }
}

void output(int *a, int *b) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(b + i));
    }
}
