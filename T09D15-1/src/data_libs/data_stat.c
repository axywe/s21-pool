#include "data_stat.h"

double max(double *a, int n) {
    double m = *a;
    for (int i = 1; i < n; i++) {
        if (m < *(a + i)) m = *(a + i);
    }
    return m;
}

double min(double *a, int n) {
    double m = *a;
    for (int i = 1; i < n; i++) {
        if (m > *(a + i)) m = *(a + i);
    }
    return m;
}

double mean(double *a, int n) {
    double m = 0;
    double p = 1. / n;
    for (int i = 0; i < n; i++) {
        m += (*(a + i) * p);
    }
    return m;
}

double variance(double *a, int n) {
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
