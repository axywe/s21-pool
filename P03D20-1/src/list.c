#include "list.h"

#include <stdlib.h>
#include <string.h>

t_list* init(char* value) {
    t_list* root = malloc(sizeof(t_list));
    (*root).value = malloc(strlen(value) * sizeof(char));
    (*root).value = strcpy((*root).value, value);
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
