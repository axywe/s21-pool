#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int res = input(data, &n);
    if (res) {
        printf("n/a");
        return 1;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%d\n", *(a + i));
        else
            printf("%d ", *(a + i));
    }
    return;
}

int max(int *a, int n) {
    int m = *a;
    for (int i = 1; i < n; i++) {
        if (m < *(a + i)) m = *(a + i);
    }
    return m;
}

int min(int *a, int n) {
    int m = *a;
    for (int i = 1; i < n; i++) {
        if (m > *(a + i)) m = *(a + i);
    }
    return m;
}

double mean(int *a, int n) {
    double m = 0;
    double p = 1. / n;
    for (int i = 0; i < n; i++) {
        m += (*(a + i) * p);
    }
    return m;
}

double variance(int *a, int n) {
    double v = 0;
    double m = 0;
    double b = 0;
    double p = 1. / n;
    for (int i = 0; i < n; i++) {
        b += (*(a + i) * p);
    }
    for (int i = 0; i < n; i++) {
        m += (*(a + i) - b) * (*(a + i) - b);
    }
    v = m / n;
    return v;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %lf %lf", max_v, min_v, mean_v, variance_v);
}