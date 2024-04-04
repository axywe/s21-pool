#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);

void sort(struct door* a, int n);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors, DOORS_COUNT);
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (doors[i].status == 1) {
            doors[i].status = 0;
        }
    }
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i != DOORS_COUNT - 1) printf("\n");
    }
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
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
