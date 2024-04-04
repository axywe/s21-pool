#ifndef DOOR_LINKED_STRUCT_H
#define DOOR_LIKED_STRUCT_H

#define DOORS_COUNT 7
#define MAX_ID_SEED 10000

struct door {
    int id;
    int status;
};

struct node {
    int id;
    int status;
    struct node* next;
};

struct node* init(struct door* door);
struct node* add_door(struct node* elem, struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* head);
void initialize_doors(struct door* doors);
void sort(struct door* a, int n);
void output(struct node* head);

#endif