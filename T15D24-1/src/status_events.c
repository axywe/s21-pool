#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared.h"

StatusEvent* select_status_event(StatusEvent* status_events, int id) {
    int i;
    for (i = 0; i < ENTITY_COUNT; i++) {
        if (status_events[i].id == id) {
            return &status_events[i];
        }
    }
    return NULL;
}

void insert_status_event(StatusEvent* status_events, int id, int moduleId, int newStatus, char* date,
                         char* time) {
    int i;
    for (i = 0; i < ENTITY_COUNT; i++) {
        if (status_events[i].id == -1) {
            status_events[i].id = id;
            status_events[i].moduleId = moduleId;
            status_events[i].newStatus = newStatus;
            strncpy(status_events[i].date, date, 11);
            strncpy(status_events[i].time, time, 9);
            return;
        }
    }
    printf("No space to insert new status event.\n");
}

void update_status_event(StatusEvent* status_events, int id, int moduleId, int newStatus, char* date,
                         char* time) {
    StatusEvent* status_event = select_status_event(status_events, id);
    if (status_event != NULL) {
        status_event->moduleId = moduleId;
        status_event->newStatus = newStatus;
        strncpy(status_event->date, date, 11);
        strncpy(status_event->time, time, 9);
    } else {
        printf("Status event not found.\n");
    }
}

void delete_status_event(StatusEvent* status_events, int id) {
    StatusEvent* status_event = select_status_event(status_events, id);
    if (status_event != NULL) {
        status_event->id = -1;
    } else {
        printf("Status event not found.\n");
    }
}

void print_status_events(StatusEvent* status_events, int count, int start) {
    int i;
    for (i = start; i < ENTITY_COUNT && i < count; i++) {
        if (status_events[i].id != -1) {
            printf("Status Event %d: Module %d, New Status %d, Date %s, Time %s\n", status_events[i].id,
                   status_events[i].moduleId, status_events[i].newStatus, status_events[i].date,
                   status_events[i].time);
        }
    }
}