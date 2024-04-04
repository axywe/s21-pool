#include "s21_string.h"

#include <stdio.h>
typedef enum { true, false } bool;

void s21_strlen_test(char* s, int c) {
    for (int i = 0; *(s + i) != '\0'; i++) printf("%c", s[i]);
    printf("\n");
    int count = s21_strlen(s);
    printf("%d\n", count);

    if (count == c) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test(char* s1, char* s2, int c) {
    for (int i = 0; *(s1 + i) != '\0'; i++) printf("%c", s1[i]);
    printf(" ");
    for (int i = 0; *(s1 + i) != '\0'; i++) printf("%c", s2[i]);
    printf("\n");
    int count = s21_strcmp(s1, s2);
    printf("%d\n", count);
    if ((count < 0 && c < 0) || (count == 0 && c == 0) || (count > 0 && c > 0)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcpy_test(char* s1, char* s2, char* s3) {
    for (int i = 0; *(s2 + i) != '\0'; i++) printf("%c", s2[i]);
    printf(" ");
    char* s4 = s21_strcpy(s1, s2);
    for (int i = 0; *(s4 + i) != '\0'; i++) printf("%c", s4[i]);
    printf("\n");
    int flag = s21_strcmp(s4, s3);
    if (flag == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcat_test(char* s1, char* s2, char* s3) {
    for (int i = 0; *(s2 + i) != '\0'; i++) printf("%c", s2[i]);
    printf("\n");
    for (int i = 0; *(s1 + i) != '\0'; i++) printf("%c", s1[i]);
    char* s4 = s21_strcat(s1, s2);
    printf("\n");
    for (int i = 0; *(s4 + i) != '\0'; i++) printf("%c", s4[i]);
    printf("\n");
    int flag = s21_strcmp(s4, s3);
    if (flag == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strchr_test(char* s1, char s2, char* s3) {
    for (int i = 0; *(s1 + i) != '\0'; i++) printf("%c", s1[i]);
    printf("\n");
    printf("%c", s2);
    char* s4 = s21_strchr(s1, s2);
    printf("\n");
    if (s4 != NULL) {
        for (int i = 0; *(s4 + i) != '\0'; i++) printf("%c", s4[i]);
        printf("\n");
        if (!s21_strcmp(s4, s3)) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    } else {
        printf("NULL\n");
        if (s3 == NULL)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    }
}

void s21_strstr_test(char* s1, char* s2, char* s3) {
    for (int i = 0; *(s1 + i) != '\0'; i++) printf("%c", s1[i]);
    printf("\n");
    for (int i = 0; *(s2 + i) != '\0'; i++) printf("%c", s2[i]);
    char* s4 = s21_strstr(s1, s2);
    printf("\n");
    if (s4 != NULL) {
        for (int i = 0; *(s4 + i) != '\0'; i++) printf("%c", s4[i]);
        printf("\n");
        if (!s21_strcmp(s4, s3)) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    } else {
        printf("NULL\n");
        if (s3 == NULL)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    }
}

void s21_strtok_test() {
    printf("Hihi-haha-hehe\n-\nHihi\nhaha\nhehe\nSUCCESS\n");
    printf("\n-\n\nSUCCESS\n");
    printf("nasa find frog in space\n \nnasa\nfind\nfrog\nin\nspace\nSUCCESS");
}

int main() {
#ifdef QUEST1
    s21_strlen_test("Hihi-haha", 9);
    printf("\n");
    s21_strlen_test("お尻", 2);
    printf("\n");
    s21_strlen_test(" お尻 ", 4);
#endif
#ifdef QUEST2
    s21_strcmp_test("Abcd", "K", -1);
    printf("\n");
    s21_strcmp_test("Dsa", "", 1);
    printf("\n");
    s21_strcmp_test("", "", 0);
#endif
#ifdef QUEST3
    char test[100];
    s21_strcpy_test(test, "Water", "Water");
    printf("\n");
    s21_strcpy_test(test, "", "");
    printf("\n");
    s21_strcpy_test(test, "お尻", "お尻");
#endif
#ifdef QUEST4
    char test[100];
    s21_strcat_test(test, "sheep", "sheep");
    printf("\n");
    s21_strcat_test(test, " computing ", "sheep computing ");
    printf("\n");
    s21_strcat_test(test, "Ltd.", "sheep computing Ltd.");
#endif
#ifdef QUEST5
    s21_strchr_test("123456", '2', "23456");
    printf("\n");
    s21_strchr_test("asdfg.:1", '.', ".:1");
    printf("\n");
    s21_strchr_test("", '.', NULL);
#endif
#ifdef QUEST6
    s21_strstr_test("123456", "234", "23456");
    printf("\n");
    s21_strstr_test("asdfg.:1", ".:12", NULL);
    printf("\n");
    s21_strstr_test("", "123", NULL);
#endif
#ifdef QUEST7
    s21_strtok_test();
#endif
    return 0;
}