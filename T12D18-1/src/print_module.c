#include "print_module.h"

#include <stdio.h>
#include <time.h>

void print_log(char (*print)(char), char* message) {
    for (int i = 0; i < 5; i++) {
        print(Log_prefix[i]);
    }

    print(' ');

    time_t t = time(NULL);
    const struct tm* currentTime = localtime(&t);

    int hours = currentTime->tm_hour;
    int minutes = currentTime->tm_min;
    int seconds = currentTime->tm_sec;

    print('0' + hours / 10);
    print('0' + hours % 10);
    print(':');

    print('0' + minutes / 10);
    print('0' + minutes % 10);
    print(':');

    print('0' + seconds / 10);
    print('0' + seconds % 10);

    print(' ');

    while (*message != '\0') {
        print(*message);
        message++;
    }
}

char print_char(char ch) { return putchar(ch); }
