#ifndef SHARED_H
#define SHARED_H

#define ENTITY_COUNT 50

typedef struct {
    int id;
    char name[30];
    int level;
    int cell;
    int isDeleted;
} Module;

typedef struct {
    int id;
    int cellCount;
    int isProtected;
} Level;

typedef struct {
    int id;
    int moduleId;
    int newStatus;
    char date[11];
    char time[9];
} StatusEvent;

typedef struct {
    int id;
    long position;
} IndexEntry;

int get_int();
int compare_index_entries(const void* a, const void* b);
void build_index(Module* modules, Level* levels, StatusEvent* events, IndexEntry* index, IndexEntry* index2,
                 IndexEntry* index3);
Module* select_module(Module* modules, IndexEntry* index, int id);
int read_from_files(Module* modules, Level* levels, StatusEvent* status_events, IndexEntry* module_index,
                    IndexEntry* module_index2, IndexEntry* module_index3);
int write_to_files(Module* modules, Level* levels, StatusEvent* status_events, IndexEntry* module_index,
                   IndexEntry* module_index2, IndexEntry* module_index3);
Level* select_level(Level* levels, int id);
StatusEvent* select_status_event(StatusEvent* status_events, int id);
void set_level_protection(Level* levels, int id, int isProtected);
void move_module(Module* modules, Level* levels, int moduleId, int levelId, int cellId,
                 IndexEntry* module_index);
void insert_module(Module* modules, int id, char* name, int level, int cell, int isDeleted);
void update_module(Module* modules, int id, char* name, int level, int cell, int isDeleted,
                   IndexEntry* module_index);
void delete_module(Module* modules, int id, IndexEntry* module_index);
void insert_status_event(StatusEvent* status_events, int id, int moduleId, int newStatus, char* date,
                         char* time);
void update_status_event(StatusEvent* status_events, int id, int moduleId, int newStatus, char* date,
                         char* time);
void delete_status_event(StatusEvent* status_events, int id);
void print_modules(Module* modules, int count, int start);
void print_levels(Level* levels, int count, int start);
void print_status_events(StatusEvent* status_events, int count, int start);
void insert_levels(Level* levels, int id, int cell, int isProtected);
void update_levels(Level* levels, int id, int cell, int isProtected);
void delete_levels(Level* levels, int id);

#endif