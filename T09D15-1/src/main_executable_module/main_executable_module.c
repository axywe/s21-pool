#include <stdio.h>
#include <stdlib.h>

#ifdef MACRO
#include "../data_libs/data_io_macro.h"
#else
#include "../data_libs/data_io.h"
#endif
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

void sort(double *a, int n) {
    int i = 0;
    int j = n - 1;

    double mid = a[n / 2];

    do {
        while (a[i] < mid) {
            i++;
        }
        while (a[j] > mid) {
            j--;
        }
        if (i <= j) {
            double temp = a[i];
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

int main() {
    double *data;
    int n;
    scanf("%d", &n);
    data = malloc(n * sizeof(double));
    printf("LOAD DATA...\n");
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");
    free(data);
    return 0;
}
