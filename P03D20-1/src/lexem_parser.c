#include "lexem_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checker_and_clearer.h"
#include "list.h"
t_list* split(char* input, char* seperators);
int main() {
    t_list* lexems = NULL;
    char* input = main_checker_input();
    printf("%s\n", input);
    if (input != NULL) {
        lexems = split(input, SEPARATORS);
        t_list* tmp = lexems;
        while (tmp != NULL) {
            printf("%s|", (*tmp).value);
            tmp = (*tmp).next;
        }
        destroy(lexems);
        free(input);
    } else
        printf("n/a");
    return 0;
}
t_list* split(char* input, char* seperators) {
    t_list* root = NULL;
    int length = strlen(input);
    int left_ptr = 0, rigth_ptr = left_ptr;
    while (rigth_ptr < length) {
        if (strchr(seperators, input[rigth_ptr]) == NULL)
            ++rigth_ptr;
        else {
            char* temp_str = NULL;
            if (rigth_ptr > left_ptr) temp_str = malloc((rigth_ptr - left_ptr + 1) * sizeof(char));
            for (int i = left_ptr; i < rigth_ptr; ++i) temp_str[i - left_ptr] = input[i];
            if (temp_str != NULL) {
                temp_str[rigth_ptr - left_ptr] = '\0';
                root = add_node(root, temp_str);
                free(temp_str);
            }
            temp_str = malloc(2 * sizeof(char));
            temp_str[0] = input[rigth_ptr];
            temp_str[1] = '\0';
            root = add_node(root, temp_str);
            free(temp_str);
            ++rigth_ptr;
            left_ptr = rigth_ptr;
        }
    }
    return root;
}
