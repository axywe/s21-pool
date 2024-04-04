#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared.h"

int main() {
    Module modules[ENTITY_COUNT];
    Level levels[ENTITY_COUNT];
    StatusEvent status_events[ENTITY_COUNT];
    IndexEntry index_entry[ENTITY_COUNT];
    IndexEntry index_entry2[ENTITY_COUNT];
    IndexEntry index_entry3[ENTITY_COUNT];

    memset(modules, -1, sizeof(modules));
    memset(levels, -1, sizeof(levels));
    memset(status_events, -1, sizeof(status_events));
    memset(index_entry, -1, sizeof(index_entry));
    memset(index_entry2, -1, sizeof(index_entry2));
    memset(index_entry3, -1, sizeof(index_entry3));

    if (read_from_files(modules, levels, status_events, index_entry, index_entry2, index_entry3) == 0) {
        printf("n/a");
        return 0;
    }
    build_index(modules, levels, status_events, index_entry, index_entry2, index_entry3);

    int table, recordCount, id, moduleId, newStatus, levelId, cellId, isDeleted, isProtected;
    char name[30], date[11], time[9];

    while (1) {
        printf("Please choose one operation:\n");
        printf(
            "1. SELECT\n2. INSERT\n3. UPDATE\n4. DELETE\n5. Get all active "
            "additional modules\n");
        printf("6. Delete modules by ids\n7. Set protected mode for module by id\n");
        printf("8. Move module by id to specified memory level and cell\n");
        printf("9. Set protection flag of the specified memory level\n10. Exit\n");

        int operation = get_int();

        if (operation == 10) break;
        if (operation < 5) {
            printf("Please choose a table:\n");
            printf("1. Modules\n2. Levels\n3. Status events\n");

            table = get_int();
        }
        switch (operation) {
            case 1:  // SELECT
                printf(
                    "Insert the number of records or leave empty to output all of "
                    "them: ");
                char line[256];
                fgets(line, sizeof(line), stdin);

                if (sscanf(line, "%d", &recordCount) != 1) {
                    recordCount = ENTITY_COUNT;
                }
                if (table == 1)
                    print_modules(modules, recordCount, 0);
                else if (table == 2)
                    print_levels(levels, recordCount, 0);
                else
                    print_status_events(status_events, recordCount, 0);
                break;
            case 2:  // INSERT
                printf("Please enter the id: ");
                id = get_int();

                if (table == 1) {
                    printf("Please enter the name, level, cell, and isDeleted: ");
                    scanf("%29s %d %d %d", name, &levelId, &cellId, &isDeleted);
                    insert_module(modules, id, name, levelId, cellId, isDeleted);
                } else if (table == 2) {
                    printf("Please enter cell, and isProtected: ");
                    scanf("%d %d", &cellId, &isProtected);
                    insert_levels(levels, id, cellId, isProtected);
                } else if (table == 3) {
                    printf("Please enter the moduleId, newStatus, date, and time: ");
                    scanf("%d %d %10s %8s", &moduleId, &newStatus, date, time);
                    insert_status_event(status_events, id, moduleId, newStatus, date, time);
                }
                break;
            case 3:  // UPDATE
                printf("Please enter the id: ");
                id = get_int();

                if (table == 1) {
                    printf("Please enter the name, level, cell, and isDeleted: ");
                    scanf("%29s %d %d %d", name, &levelId, &cellId, &isDeleted);
                    update_module(modules, id, name, levelId, cellId, isDeleted, index_entry);
                } else if (table == 3) {
                    printf("Please enter the moduleId, newStatus, date, and time: ");
                    scanf("%d %d %10s %8s", &moduleId, &newStatus, date, time);
                    update_status_event(status_events, id, moduleId, newStatus, date, time);
                } else if (table == 2) {
                    printf("Please enter cell, and isProtected: ");
                    scanf("%d %d", &cellId, &isProtected);
                    update_levels(levels, id, cellId, isProtected);
                }
                break;
            case 4:  // DELETE
                printf("Please enter the id: ");
                id = get_int();

                if (table == 1)
                    delete_module(modules, id, index_entry);
                else if (table == 2)
                    delete_levels(levels, id);
                else if (table == 3)
                    delete_status_event(status_events, id);
                break;
            case 5:  // Get all active additional modules
                print_modules(modules, ENTITY_COUNT, 0);
                break;
            case 6:  // Delete modules by ids
                printf("Please enter the number of modules to delete: ");
                recordCount = get_int();

                printf("Please enter the module ids to delete: ");
                for (int i = 0; i < recordCount; i++) {
                    id = get_int();
                    delete_module(modules, id, index_entry);
                }
                break;
            case 7:  // Set protected mode for module by id
                printf("Please enter the id of the module to set protection mode: ");
                id = get_int();

                printf(
                    "Please enter the protection mode (0 for unprotected, 1 for "
                    "protected): ");
                isProtected = get_int();

                set_level_protection(levels, id, isProtected);
                break;

            case 8:  // Move module by id to specified memory level and cell
                printf("Please enter the id of the module to move: ");
                id = get_int();

                printf("Please enter the level and cell to move the module to: ");
                scanf("%d %d", &levelId, &cellId);

                move_module(modules, levels, id, levelId, cellId, index_entry);
                break;
            case 9:  // Set protection flag of the specified memory level
                printf("Please enter the id of the memory level to set protection flag: ");
                id = get_int();

                printf(
                    "Please enter the protection flag (0 for unprotected, 1 for "
                    "protected): ");
                isProtected = get_int();

                set_level_protection(levels, id, isProtected);
                break;
            default:
                clearerr(stdin);
                break;
        }
        if (write_to_files(modules, levels, status_events, index_entry, index_entry2, index_entry3) == 0) {
            printf("n/a\n");
            break;
        }
    }

    return 0;
}