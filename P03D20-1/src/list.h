#ifndef LIST_H
#define LIST_H

typedef struct t_list {
    char* value;
    struct t_list* next;
} t_list;

t_list* init(char* value);
t_list* add_node(t_list* root, char* value);
t_list* remove_node(t_list* root, t_list* elem);
void destroy(t_list* root);

#endif
