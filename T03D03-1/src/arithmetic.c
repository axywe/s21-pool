#include <stdio.h>

int sum(int a, int b);

int main() {
    int first, second;
    char c;
    if (scanf("%d %d%c", &first, &second, &c) && (c == '\n')) {
        printf("%d %d %d ", sum(first, second), first - second, first * second);
        if (second == 0)
            printf("n/a");
        else
            printf("%d", first / second);
    } else {
        printf("n/a");
    }
    printf("\n");
    return 0;
}

int sum(int a, int b) { return a + b; }