#include "stack.h"

#include <stdio.h>

void push(int *top, int stack[100], int x) {
    *top = *top + 1;
    stack[*top] = x;
}

void init(int stack[100], int *top) {
    int x[10];
    for (int i = 0; i < 10; i++) {
        x[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        *top = *top + 1;
        stack[*top] = x[i];
    }
}

void pop(int *top, int stack[100]) {
    if (*top <= -1) {
        printf("Stack is under flow\n");
    } else {
        printf("The poopped elements is %d\n", stack[*top]);
        *top = *top - 1;
    }
}
void display(int top, int stack[100]) {
    if (top >= 0) {
        printf("The elements in STACK \n");
        for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    } else {
        printf("\nThe STACK is empty");
    }
}

void destroy(int top, int stack[100]) {
    for (int i = 0; i < top; i++) {
        stack[i] = 0;
    }
}