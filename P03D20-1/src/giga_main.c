#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SEPARATORS "+-*/()sctCSl"

#include "giga_main.h"

/////////////////////////////////
///
/////////////////////////////

t_list* main_parser() {
    t_list* lexems = NULL;
    char* input = main_checker_input();
    // printf("%s - length = %d\n", input, strlen(input));
    if (input != NULL) {
        lexems = split(input, SEPARATORS);
        t_list* tmp = lexems;
        while (tmp != NULL) {
            printf("%s|", (*tmp).value);
            tmp = (*tmp).next;
        }
        // destroy(lexems);
        free(input);
    } else
        printf("n/a");
    return lexems;
}
t_list* split(char* input, char* seperators) {
    t_list* root = NULL;
    char* temp_str = NULL;
    int length = 0;
    while (input[length] != '\0') ++length;
    int left_ptr = 0, rigth_ptr = left_ptr;
    while (rigth_ptr < length) {
        if (strchr(seperators, input[rigth_ptr]) == NULL)
            ++rigth_ptr;
        else {
            temp_str = NULL;
            if (rigth_ptr == left_ptr) {
                temp_str = malloc(2 * sizeof(char));
                temp_str[0] = input[rigth_ptr];
                temp_str[1] = '\0';
                root = add_node(root, temp_str);
                free(temp_str);
            } else {
                temp_str = malloc((rigth_ptr - left_ptr + 2) * sizeof(char));
                for (int i = left_ptr; i < rigth_ptr; ++i) temp_str[i - left_ptr] = input[i];
                temp_str[rigth_ptr - left_ptr] = '\0';
                root = add_node(root, temp_str);
                free(temp_str);

                temp_str = malloc(2 * sizeof(char));
                temp_str[0] = input[rigth_ptr];
                temp_str[1] = '\0';
                root = add_node(root, temp_str);
                free(temp_str);
            }
            ++rigth_ptr;
            left_ptr = rigth_ptr;
        }
    }
    --rigth_ptr;
    if ((rigth_ptr >= left_ptr) && (strchr(seperators, input[rigth_ptr]) == NULL)) {
        temp_str = malloc((rigth_ptr - left_ptr + 2) * sizeof(char));
        for (int i = left_ptr; i <= rigth_ptr; ++i) temp_str[i - left_ptr] = input[i];
        temp_str[rigth_ptr - left_ptr + 1] = '\0';
        root = add_node(root, temp_str);
        free(temp_str);
    }
    return root;
}
t_list* init(char* value) {
    t_list* root = NULL;
    root = malloc(sizeof(t_list));
    int i = 0;
    while (value[i] != '\0') ++i;
    (*root).value = malloc((i + 1) * sizeof(char));
    for (int k = 0; k < i; ++k) (*root).value[k] = value[k];
    (*root).value[i] = '\0';
    (*root).next = NULL;
    return root;
}

t_list* add_node(t_list* root, char* value) {
    if (root == NULL)
        root = init(value);
    else {
        t_list* tmp = root;
        while ((*tmp).next != NULL) tmp = (*tmp).next;
        (*tmp).next = init(value);
    }
    return root;
}

t_list* remove_node(t_list* root, t_list* elem) {
    if (elem != NULL) {
        if (elem == root) {
            root = (*root).next;
        } else {
            t_list* tmp = root;
            while ((*tmp).next != elem) tmp = (*tmp).next;
            (*tmp).next = (*elem).next;
        }
        if ((*elem).value != NULL) free((*elem).value);
        free(elem);
    }
    return root;
}

void destroy(t_list* root) {
    t_list* prev_tmp = NULL;
    t_list* tmp = root;
    while (tmp != NULL) {
        prev_tmp = tmp;
        tmp = (*tmp).next;
        free((*prev_tmp).value);
        free(prev_tmp);
    }
}

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

int is_digit(char a) {
    int result = 0;
    if ((a >= 48) && (a <= 57)) result = 1;
    return result;
}
void remove_long_trigonometry(char* input) {
    int count = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        int save_i = i;
        switch (input[i]) {
            case ('s'):
                if (input[i + 1] == 'i')
                    i += 2;
                else if (input[i + 1] == 'q') {
                    input[i] = 'S';
                    i += 3;
                }
                break;
            case ('c'):
                if (input[i + 1] == 't') input[i] = 'C';
                i += 2;
                break;
            case ('t'):
                if (input[i + 1] == 'a') i += 2;
                break;
            case ('l'):
                ++i;
                break;
            default:;
        }
        input[count] = input[save_i];
        ++count;
    }
    input[count] = '\0';
    return;
}
int input_checker_3(char* input) {
    int length = 0, error_flag = 0;
    while (input[length] != '\0') ++length;
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
    int length = 0, error_flag = 0;
    while (input[length] != '\0') ++length;
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
    int length = 0, bracket_counter = 0, error_flag = 0;
    while (input[length] != '\0') ++length;
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
