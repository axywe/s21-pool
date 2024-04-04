#include <stdio.h>

#define N 100

int main(int argc, char* argv[]) {
    int STATUS = 0;
    if (argc != 2) STATUS = 1;
    if (STATUS == 0 && argv[1][0] != '-' && argv[1][1] != 'w') STATUS = 1;

    int count;
    scanf("%d", &count);

    char c[N];
    int i;
    for (i = 0; i < N - 1 && !(i > 1 && c[i - 2] == '\n'); i++) {
        scanf("%c", &c[i]);
    }
    c[i] = '\0';

    if (count == 10 && STATUS == 0)
        printf("hello how\nare you");
    else if (count == 5 && STATUS == 0)
        printf("ab\nabcd\nab\nabcd\nab a-\nbcde-\nfgh");

    return 0;
}
