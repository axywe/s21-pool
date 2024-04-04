/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int check(int *a, int n);

void output_result(int res);

int main() {
    int n, data[NMAX];
    int res = input(data, &n);
    if (res) {
        printf("n/a");
        return 1;
    }
    res = check(data, n);
    output_result(res);

    return 0;
}

int check(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0 && *(a + i) >= mean(a, n) &&
            *(a + i) <= mean(a, n) + 3 * sqrt(variance(a, n)) && *(a + i) != 0)
            return *(a + i);
    }
    return 0;
}

int input(int *a, int *n) {
    char c;
    scanf("%d%c", n, &c);
    if (c != '\n' || *n < 1 || *n > NMAX) return 1;
    for (int i = 0; i < *n; i++) {
        if (scanf("%d%c", (a + i), &c) > 30) return 1;
        if (c != '\n' && c != ' ') return 1;
    }
    return 0;
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

void output_result(int res) { printf("%d", res); }