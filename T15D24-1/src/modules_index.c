#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared.h"

int compare_index_entries(const void* a, const void* b) {
    return ((IndexEntry*)a)->id - ((IndexEntry*)b)->id;
}

void build_index(Module* modules, Level* levels, StatusEvent* events, IndexEntry* index, IndexEntry* index2,
                 IndexEntry* index3) {
    for (int i = 0; i < ENTITY_COUNT; i++) {
        index[i].id = modules[i].id;
        index[i].position = i * sizeof(Module);
    }
    qsort(index, ENTITY_COUNT, sizeof(IndexEntry), compare_index_entries);
    for (int i = 0; i < ENTITY_COUNT; i++) {
        index[i].id = levels[i].id;
        index[i].position = i * sizeof(Level);
    }
    qsort(index2, ENTITY_COUNT, sizeof(IndexEntry), compare_index_entries);
    for (int i = 0; i < ENTITY_COUNT; i++) {
        index[i].id = events[i].id;
        index[i].position = i * sizeof(StatusEvent);
    }
    qsort(index3, ENTITY_COUNT, sizeof(IndexEntry), compare_index_entries);
}
