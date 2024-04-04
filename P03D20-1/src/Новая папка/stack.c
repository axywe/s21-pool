#include "stack.h"

#include <stdlib.h>
#include <string.h>

t_stack* init(char* a) {
    t_stack* head = malloc(sizeof(t_stack));
    (*head).next = NULL;
    char* value = malloc(strlen(a) * sizeof(char));
    for (int i = 0; i <= strlen(a); ++i) value[i] = a[i];
    return head;
}
void push(t_stack* head, char* a) {
    t_stack* new_node = init(a);
    (*new_node).next = head;
    head = new_node;
    return;
}
char* peek(t_stack* head) {
    char* result = (*head).value;
    return result;
}
char* pop(t_stack* head) {
    char* result = "\0";
    t_stack* output_node = NULL;
    if (head != NULL) {
        result = (*head).value;
        output_node = head;
        head = (*head).next;
        free(output_node);
    }
    return result;
}
int isEmpty(t_stack* head) {
    int result = 0;
    if (head == NULL) result = 1;
    return result;
}
