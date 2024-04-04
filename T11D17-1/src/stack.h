#ifndef STACK_H
#define STACK_H

void push(int *top, int stack[100], int x);
void pop(int *top, int stack[100]);
void display(int top, int stack[100]);
void destroy(int top, int stack[100]);
void init(int stack[100], int *top);

#endif