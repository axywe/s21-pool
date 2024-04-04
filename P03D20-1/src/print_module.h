#ifndef PRINT_MODULE_H
#define PRINT_MODULE_H

#include <math.h>

#define HEIGTH 25
#define LENGTH 80
#define shift 1.0 / (HEIGTH - 1.0)
#define Eps 1E-9

double func_calc(double x) {
    double result = 2 * x / (4 * M_PI) - 1;  // 2 * x / (4 * M_PI) - 1
    return result;
}
void graph_print(double (*)(double));

#endif
