#include "data_io.h"

#include <stdio.h>

void input(double *a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", (a + i));
    }
}

void output(double *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%.2lf", *(a + i));
        else
            printf("%.2lf ", *(a + i));
    }
}
