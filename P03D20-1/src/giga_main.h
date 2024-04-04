#ifndef GIGA_MAIN_H
#define GIGA_MAIN_H

typedef struct t_list {
    char* value;
    struct t_list* next;
} t_list;

t_list* main_parser();
t_list* split(char* input, char* seperators);

char* main_checker_input();
int input_checker(char* input);
int input_checker_2(char* input);
int input_checker_3(char* input);
void remove_whitespaces(char* input);
void remove_long_trigonometry(char* input);
char* get_string();
int is_digit(char a);

t_list* init(char* value);
t_list* add_node(t_list* root, char* value);
t_list* remove_node(t_list* root, t_list* elem);
void destroy(t_list* root);

#endif
