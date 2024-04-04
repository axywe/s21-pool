#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared.h"
Level* select_level(Level* levels, int id) {
    int i;
    for (i = 0; i < ENTITY_COUNT; i++) {
        if (levels[i].id == id) {
            return &levels[i];
        }
    }
    return NULL;
}

void insert_levels(Level* levels, int id, int cell, int isProtected) {
    int i;
    for (i = 0; i < ENTITY_COUNT; i++) {
        if (levels[i].id == -1) {
            levels[i].id = id;
            levels[i].cellCount = cell;
            levels[i].isProtected = isProtected;
            return;
        }
    }
    printf("No space to insert new level.\n");
}

void update_levels(Level* levels, int id, int cell, int isProtected) {
    int i;
    for (i = 0; i < ENTITY_COUNT; i++) {
        if (levels[i].id == id) {
            levels[i].cellCount = cell;
            levels[i].isProtected = isProtected;
            return;
        }
    }
    printf("No space to insert new level.\n");
}

void delete_levels(Level* levels, int id) {
    Level* level = select_level(levels, id);
    if (level != NULL) {
        level->id = -1;
    } else {
        printf("Level not found.\n");
    }
}

void set_level_protection(Level* levels, int id, int isProtected) {
    Level* level = select_level(levels, id);
    if (level != NULL) {
        level->isProtected = isProtected;
    }
}

void print_levels(Level* levels, int count, int start) {
    int i;
    for (i = start; i < ENTITY_COUNT && i < count; i++) {
        if (levels[i].id != -1) {
            printf("Level %d: %d cells, %sprotected\n", levels[i].id, levels[i].cellCount,
                   levels[i].isProtected ? "" : "not ");
        }
    }
}