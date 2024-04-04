#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node* init(struct door* door) {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    for (int i = 0; i < DOORS_COUNT; i++) {
        head->id = door[i].id;
        head->status = door[i].status;
        if (i != DOORS_COUNT - 1) {
            head->next = (struct node*)malloc(sizeof(struct node));
            head = head->next;
        } else {
            head->next = NULL;
        }
    }
    return temp;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->id = door->id;
    temp->status = door->status;
    temp->next = elem->next;
    elem->next = temp;
    return elem;
}
struct node* find_door(int door_id, struct node* root) {
    int STATUS = 0;
    while (root->next != NULL && STATUS == 0) {
        if (root->id == door_id)
            STATUS = 1;
        else
            root = root->next;
    }
    return STATUS == 1 ? root : NULL;
}
struct node* remove_door(struct node* elem, struct node* root) {
    while (root->next != elem) {
        root = root->next;
    }
    root->next = root->next->next;
    free(elem);
    return root;
}

void destroy(struct node* head) {
    while (head != NULL) {
        struct node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* a, int n) {
    int i = 0;
    int j = n - 1;

    struct door mid = a[n / 2];

    do {
        while (a[i].id < mid.id) {
            i++;
        }
        while (a[j].id > mid.id) {
            j--;
        }
        if (i <= j) {
            struct door temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        sort(a, j + 1);
    }
    if (i < n) {
        sort(&a[i], n - i);
    }
}

void output(struct node* head) {
    while (head != NULL) {
        printf("%d %d\n", head->id, head->status);
        head = head->next;
    }
}