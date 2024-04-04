#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    int stack[100];
    int top = -1;
    init(stack, &top);
    display(top, stack);
    printf("\n");
    push(&top, stack, 1);
    display(top, stack);
    printf("\n");

    pop(&top, stack);
    display(top, stack);
    printf("\n");

    destroy(top, stack);
    printf("Destroy");
    return 0;
}