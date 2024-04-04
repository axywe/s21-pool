#include <stdio.h>

int calc(double a, double b);

int main(void) {
    printf("Формат ввода: 123 123\n");
    double a, b;
    char c;
    if (scanf("%lf %lf%c", &a, &b, &c) && (c == '\n')) {
        if (a == (int)a && b == (int)b) {
            printf("%d", calc(a, b));
        } else {
            printf("n/a");
            printf("\n");
            return 1;
        }
    }
    printf("\n");
    return 0;
}
int calc(double a, double b) {
    if (a > b)
        return (int)a;
    else
        return (int)b;
}