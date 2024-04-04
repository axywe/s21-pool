#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *count);
void output(int *buffer, int length);
int shift(int *buffer, int length, int number, int *numbers);

int main() {
    int n, data[NMAX], out[NMAX], count;
    int res = input(data, &n, &count);
    if (res) {
        printf("n/a");
        return 1;
    }
    shift(data, n, count, out);
    output(out, n);
}

int shift(int *buffer, int length, int number, int *numbers) {
    for (int i = 0; i < length; i++) {
        *(numbers + i) = buffer[(i + number) % length];
    }
    return 0;
}

int input(int *a, int *n, int *count) {
    char c;
    scanf("%d%c", n, &c);
    if (c != '\n' || *n < 1 || *n > NMAX) return 1;
    for (int i = 0; i < *n; i++) {
        scanf("%d%c", (a + i), &c);
        if (c != '\n' && c != ' ') return 1;
    }
    scanf("%d%c", count, &c);
    if (c != '\n') return 1;
    *count = (*count % *n + *n) % *n;
    return 0;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i != length - 1)
            printf("%d ", buffer[i]);
        else
            printf("%d", buffer[i]);
    }
    return;
}
