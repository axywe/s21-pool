#include "checker_and_clearer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* main_checker_input() {
    int error_flag = 0;
    char* input = get_string();
    remove_whitespaces(input);
    error_flag = input_checker(input) + input_checker_2(input);
    if (!error_flag) remove_long_trigonometry(input);
    if (!error_flag) error_flag = input_checker_3(input);
    if (error_flag) {
        free(input);
        input = NULL;
    }
    return input;
}
char* get_string() {
    int capacity = 1, length = 0;
    char* result = malloc(sizeof(char));
    char c = getchar();
    while (c != '\n') {
        result[length++] = c;
        if (length >= capacity) {
            capacity *= 2;
            char* tmp = realloc(result, capacity * sizeof(char));
            if (tmp != NULL)
                result = tmp;
            else {
                free(result);
                break;
            }
        }
        c = getchar();
    }
    result[length] = '\0';
    return result;
}
void remove_whitespaces(char* input) {
    int count = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] != ' ') input[count] = input[i];
        if (input[i] == ' ') --count;
        ++count;
    }
    input[count] = '\0';
    return;
}
/*void long_separetors(char* input, int* i) {
    if (input[*i] == 's') {
        if (input[*i + 1] == 'i') (*i) += 2;
        if (input[*i + 1] == 'q') (*i) += 3;
    }
    if ((input[*i] == 'c') || (input[*i] == 't')) (*i) += 2;
    if (input[*i] == 'l') (*i) += 1;
    (*i)++;
    return;
}*/
int is_digit(char a) {
    int result = 0;
    if ((a >= 48) && (a <= 57)) result = 1;
    return result;
}
void remove_long_trigonometry(char* input) {
    int count = 0;
    char prev_char = '=';
    for (int i = 0; input[i] != '\0'; ++i) {
        if ((input[i] != 'i') && (input[i] != 'n') && (input[i] != 'o') && (input[i] != 'a') &&
            (input[i] != 'g') && (input[i] != 'q') && (input[i] != 'r'))
            if ((!((input[i] == 's') && (prev_char == 'o'))) &&
                (!((input[i] == 't') && (prev_char == 'r'))) && (!((input[i] == 't') && (prev_char == 'c'))))
                input[count] = input[i];
        if ((input[i] == 'i') || (input[i] == 'n') || (input[i] == 'o') || (input[i] == 'a') ||
            (input[i] == 'g') || (input[i] == 'q') || (input[i] == 'r') ||
            ((input[i] == 's') && (prev_char == 'o')) || ((input[i] == 't') && (prev_char == 'r')) ||
            ((input[i] == 't') && (prev_char == 'c')))
            --count;
        if ((prev_char == 's') && (input[i] == 'q')) input[count] = 'S';
        if ((prev_char == 'c') && (input[i] == 't')) input[count] = 'C';
        ++count;
        prev_char = input[i];
    }
    input[count] = '\0';
    return;
}
int input_checker_3(char* input) {
    int length = strlen(input), error_flag = 0;
    char prev_char = '^';
    for (int i = 0; i < length; ++i) {
        if ((prev_char == '*') &&
            ((input[i] == '+') || (input[i] == '*') || (input[i] == '/') || (input[i] == ')')))
            error_flag = 1;
        if ((prev_char == '+') &&
            ((input[i] == '+') || (input[i] == '*') || (input[i] == '/') || (input[i] == ')')))
            error_flag = 1;
        if ((prev_char == '/') &&
            ((input[i] == '+') || (input[i] == '*') || (input[i] == '/') || (input[i] == ')')))
            error_flag = 1;
        if ((prev_char == '-') &&
            ((input[i] == '+') || (input[i] == '*') || (input[i] == '/') || (input[i] == ')')))
            error_flag = 1;
        prev_char = input[i];
    }
    if ((input[0] == '+') || (input[0] == '*') || (input[0] == '/')) error_flag = 1;
    if (length > 0)
        if ((input[length - 1] == '+') || (input[length - 1] == '*') || (input[length - 1] == '/') ||
            (input[length - 1] == '-'))
            error_flag = 1;

    for (int i = 1; i < length; ++i)
        if (input[i] == '-')
            if ((input[i - 1] != 'x') && (!is_digit(input[i - 1])) && (input[i - 1] != ')')) input[i] = '~';
    if (input[0] == '-') input[0] = '~';

    for (int i = 1; i < length - 1; ++i)
        if ((input[i] == 'x') && ((is_digit(input[i - 1])) || (is_digit(input[i + 1])))) error_flag = 1;
    return error_flag;
}
int input_checker_2(char* input) {
    int length = strlen(input), error_flag = 0;
    char prev_char = '^';
    if (length == 0) error_flag = 1;
    for (int i = 0; i < length; ++i) {
        if ((prev_char == '(') && (input[i] == ')')) error_flag = 1;
        if ((prev_char == ')') && (input[i] == '(')) error_flag = 1;
        if (prev_char == '.')
            if (!((is_digit(input[i])) && (is_digit(input[i - 2])))) error_flag = 1;
        if ((prev_char == 's') && !((input[i] == '(') || (input[i] == 'i') || (input[i] == 'q')))
            error_flag = 1;
        if ((prev_char == 'i') && (input[i] != 'n')) error_flag = 1;
        if ((prev_char == 'n') && (input[i] != '(')) error_flag = 1;

        if ((prev_char == 'c') && !((input[i] == 'o') || (input[i] == 't'))) error_flag = 1;
        if ((prev_char == 'o') && (input[i] != 's')) error_flag = 1;

        if ((prev_char == 't') && !((input[i] == '(') || (input[i] == 'a') || (input[i] == 'g')))
            error_flag = 1;
        if ((prev_char == 'a') && (input[i] != 'n')) error_flag = 1;

        if ((prev_char == 'g') && (input[i] != '(')) error_flag = 1;

        if ((prev_char == 'q') && (input[i] != 'r')) error_flag = 1;
        if ((prev_char == 'r') && (input[i] != 't')) error_flag = 1;

        if ((prev_char == 'l') && (input[i] != 'n')) error_flag = 1;
        prev_char = input[i];
    }
    if ((input[length - 1] == 'n') || (input[length - 1] == 's') || (input[length - 1] == 'g') ||
        (input[length - 1] == 't'))
        error_flag = 1;
    return error_flag;
}
int input_checker(char* input) {
    int length = strlen(input), bracket_counter = 0, error_flag = 0;
    if (length == 0) error_flag = 1;
    for (int i = 0; i < length; ++i) {
        if (input[i] == '(') ++bracket_counter;
        if (input[i] == ')') --bracket_counter;
        if (bracket_counter < 0) error_flag = 1;
        for (int j = 33; j <= 39; ++j)
            if (input[i] == (char)j) error_flag = 1;
        if (input[i] == (char)44) error_flag = 1;
        for (int j = 58; j <= 96; ++j)
            if (input[i] == (char)j) error_flag = 1;
        if (input[i] == (char)98) error_flag = 1;
        for (int j = 100; j <= 102; ++j)
            if (input[i] == (char)j) error_flag = 1;
        if (input[i] == (char)104) error_flag = 1;
        for (int j = 106; j <= 107; ++j)
            if (input[i] == (char)j) error_flag = 1;
        if (input[i] == (char)109) error_flag = 1;
        if (input[i] == (char)112) error_flag = 1;
        for (int j = 117; j <= 119; ++j)
            if (input[i] == (char)j) error_flag = 1;
        for (int j = 121; j <= 254; ++j)
            if (input[i] == (char)j) error_flag = 1;
    }
    if (bracket_counter != 0) error_flag = 1;
    return error_flag;
}
