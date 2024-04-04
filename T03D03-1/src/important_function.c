#include <math.h>
#include <stdio.h>

double math(double);

int main() {
    double x;
    char c;
    if (scanf("%lf%c", &x, &c) && (c == '\n')) {
        printf("%.1lf\n", math(x));
    } else
        printf("n/a\n");
    return 0;
}

double math(double x) {
    return (7e-3 * pow(x, 4) + ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) -
            x * pow((10 + x), (2 / x)) - 1.01);
}
