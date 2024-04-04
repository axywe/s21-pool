#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared.h"

Module* select_module(Module* modules, IndexEntry* index, int id) {
    IndexEntry key = {.id = id};
    IndexEntry* found = bsearch(&key, index, ENTITY_COUNT, sizeof(IndexEntry), compare_index_entries);
    if (found != NULL) {
        return &modules[found->position / sizeof(Module)];
    }
    return NULL;
}

void insert_module(Module* modules, int id, char* name, int level, int cell, int isDeleted) {
    int i;
    for (i = 0; i < ENTITY_COUNT; i++) {
        if (modules[i].isDeleted == 1) {
            modules[i].id = id;
            strncpy(modules[i].name, name, 30);
            modules[i].level = level;
            modules[i].cell = cell;
            modules[i].isDeleted = isDeleted;
            return;
        }
    }
    printf("No space to insert new module.\n");
}

void update_module(Module* modules, int id, char* name, int level, int cell, int isDeleted,
                   IndexEntry* module_index) {
    Module* module = select_module(modules, module_index, id);
    if (module != NULL) {
        strncpy(module->name, name, 30);
        module->level = level;
        module->cell = cell;
        module->isDeleted = isDeleted;
    } else {
        printf("Module not found.\n");
    }
}

void move_module(Module* modules, Level* levels, int moduleId, int levelId, int cellId,
                 IndexEntry* module_index) {
    Module* module = select_module(modules, module_index, moduleId);
    Level* level = select_level(levels, levelId);
    if (module != NULL && level != NULL) {
        if (cellId >= 0 && cellId < level->cellCount) {
            module->level = levelId;
            module->cell = cellId;
        }
    }
}

void delete_module(Module* modules, int id, IndexEntry* module_index) {
    Module* module = select_module(modules, module_index, id);
    if (module != NULL) {
        module->isDeleted = 1;
    } else {
        printf("Module not found.\n");
    }
}

void print_modules(Module* modules, int count, int start) {
    int i;
    for (i = start; i < ENTITY_COUNT && i < count; i++) {
        if (modules[i].isDeleted != 1) {
            printf("Module %d: %s, Level %d, Cell %d\n", modules[i].id, modules[i].name, modules[i].level,
                   modules[i].cell);
        }
    }
}