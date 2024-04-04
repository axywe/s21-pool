#include "print_module.h"

#include <stdio.h>

int main() {
    graph_print(func_calc);
    return 0;
}
void graph_print(double (*function)(double)) {
    for (double k = -1.0; k <= 1.0 + Eps; k += 2.0 / (HEIGTH - 1.0)) {
        printf("%lf\t", k);
        for (double x = 0.0; x <= 4 * M_PI + Eps; x += (4 * M_PI) / (LENGTH - 1.0)) {
            double current_value = function(x);
            if ((fabs(current_value) <= 1.0 + Eps) && (fabs(current_value - k) <= shift))
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
    return;
}
