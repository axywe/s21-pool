#ifndef STACK_H
#define STACK_H

typedef struct t_stack {
    struct t_stack* next;
    char* value;
} t_stack;
t_stack* init(char* a);
void push(t_stack* head, char* a);
char* peek(t_stack* head);
char* pop(t_stack* head);
int isEmpty(t_stack* head);

#endif
