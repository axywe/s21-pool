#include <stdio.h>

int main(void) {
    int name;
    char c;
    if (scanf("%d%c", &name, &c) && (c == '\n')) {
        printf("Hello, %d\n", name);
    } else {
        printf("Введите только int\n");
    }
    return 0;
}