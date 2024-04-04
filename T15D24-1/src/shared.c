#include "shared.h"

#include <stdio.h>
#include <stdlib.h>

int get_int() {
    char line[256];
    int num, result;

    do {
        fgets(line, sizeof(line), stdin);
        result = sscanf(line, "%d", &num);
    } while (result != 1);

    return num;
}

int read_from_files(Module* modules, Level* levels, StatusEvent* status_events, IndexEntry* module_index,
                    IndexEntry* module_index2, IndexEntry* module_index3) {
    int status = 1;
    FILE* file = fopen("db/master_levels.db", "rb");
    if (file != NULL) {
        fread(levels, sizeof(Level), ENTITY_COUNT, file);
        fclose(file);
    } else
        status = 0;
    file = fopen("db/master_modules.db", "rb");
    if (file != NULL) {
        fread(modules, sizeof(Module), ENTITY_COUNT, file);
        fclose(file);
    } else
        status = 0;
    file = fopen("db/master_status_events.db", "rb");
    if (file != NULL) {
        fread(status_events, sizeof(StatusEvent), ENTITY_COUNT, file);
        fclose(file);
    } else
        status = 0;
    file = fopen("db/master_modules_index.db", "rb");
    if (file != NULL) {
        fread(module_index, sizeof(IndexEntry), ENTITY_COUNT, file);
        fclose(file);
    }
    file = fopen("db/master_levels_index.db", "rb");
    if (file != NULL) {
        fread(module_index2, sizeof(IndexEntry), ENTITY_COUNT, file);
        fclose(file);
    }
    file = fopen("db/master_status_index.db", "rb");
    if (file != NULL) {
        fread(module_index3, sizeof(IndexEntry), ENTITY_COUNT, file);
        fclose(file);
    }
    return status;
}

int write_to_files(Module* modules, Level* levels, StatusEvent* status_events, IndexEntry* module_index,
                   IndexEntry* module_index2, IndexEntry* module_index3) {
    int status = 1;
    FILE* file = fopen("db/master_levels.db", "wb");
    if (file != NULL) {
        fwrite(levels, sizeof(Level), ENTITY_COUNT, file);
        fclose(file);
    } else
        status = 0;

    file = fopen("db/master_modules.db", "wb");
    if (file != NULL) {
        fwrite(modules, sizeof(Module), ENTITY_COUNT, file);
        fclose(file);
    } else
        status = 0;

    file = fopen("db/master_status_events.db", "wb");
    if (file != NULL) {
        fwrite(status_events, sizeof(StatusEvent), ENTITY_COUNT, file);
        fclose(file);
    } else
        status = 0;
    file = fopen("db/master_modules_index.db", "wb");
    if (file != NULL) {
        fwrite(module_index, sizeof(IndexEntry), ENTITY_COUNT, file);
        fclose(file);
    } else
        status = 0;
    file = fopen("db/master_levels_index.db", "wb");
    if (file != NULL) {
        fwrite(module_index2, sizeof(IndexEntry), ENTITY_COUNT, file);
        fclose(file);
    } else
        status = 0;
    file = fopen("db/master_status_index.db", "wb");
    if (file != NULL) {
        fwrite(module_index3, sizeof(IndexEntry), ENTITY_COUNT, file);
        fclose(file);
    } else
        status = 0;
    return status;
}