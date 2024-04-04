#include "s21_string.h"

#include <stdio.h>

typedef enum { true, false } bool;

int s21_strlen(const char* s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

int s21_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

char* s21_strcpy(char* s, char* p) {
    char* temp1 = s;
    char* temp2 = p;
    int i = 0;
    while (temp2[i] != '\0') {
        temp1[i] = temp2[i];
        i++;
    }
    temp1[i] = '\0';
    return temp1;
}

char* s21_strcat(char* dest, const char* src) {
    char* ptr = dest + s21_strlen(dest);

    while (*src != '\0') {
        *ptr++ = *src++;
    }

    *ptr = '\0';

    return dest;
}

char* s21_strchr(const char* s, const char c) {
    while (*s != c && *s != '\0') s++;
    return *s == c ? (char*)s : NULL;
}

char* s21_strstr(char* string, char* substring) {
    char *a, *b;

    b = substring;
    if (*b == 0) {
        return string;
    }
    for (; *string != 0; string += 1) {
        if (*string != *b) {
            continue;
        }
        a = string;
        while (1) {
            if (*b == 0) {
                return string;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = substring;
    }
    return NULL;
}

// char* s21_strtok(char* str, const char* delim) {
//     static char* nextToken = NULL;
//     static bool reset = false;

//     if (reset) {
//         nextToken = NULL;
//         reset = false;
//     }

//     if (str != NULL) {
//         nextToken = str;
//     }

//     if (nextToken == NULL || *nextToken == '\0') {
//         reset = true;
//         return NULL;
//     }

//     char* tokenStart = nextToken;
//     char* tokenEnd = nextToken;

//     while (*tokenEnd != '\0') {
//         const char* delimiter = delim;
//         while (*delimiter != '\0') {
//             if (*tokenEnd == *delimiter) {
//                 *tokenEnd = '\0';
//                 nextToken = tokenEnd + 1;
//                 return tokenStart;
//             }
//             delimiter++;
//         }
//         tokenEnd++;
//     }

//     reset = true;
//     return tokenStart;
// }