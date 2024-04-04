#include "list.h"

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

bool remove_door_test(int id, struct node* head);
bool add_door_test(int id, struct node* head);

int main() {
    struct node* head = NULL;
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors, DOORS_COUNT);
    head = init(doors);
    printf("Original\n");
    output(head);
    printf("Add Door\n");
    struct door test[1];
    test->id = DOORS_COUNT + 11;
    test->status = 0;
    add_door(head->next->next->next, test);
    output(head);
    if (add_door_test(DOORS_COUNT + 11, head) == true)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    printf("Find Door\n");
    struct node* find = find_door(5, head);
    if (find != NULL)
        printf("%d %d\n", find->id, find->status);
    else
        printf("NULL");
    printf("Remove Door\n");
    remove_door(head->next->next->next->next, head);
    if (remove_door_test(DOORS_COUNT + 11, head) == false)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    output(head);
    printf("Destroy\n");
    destroy(head);
    return 0;
}

bool remove_door_test(int id, struct node* head) {
    bool find = false;
    while (head->next != NULL && find == false) {
        if (head->id == id) find = true;
        head = head->next;
    }
    return find;
}

bool add_door_test(int id, struct node* head) {
    bool find = false;
    while (head->next != NULL && find == false) {
        if (head->id == id) find = true;
        head = head->next;
    }
    return find;
}
