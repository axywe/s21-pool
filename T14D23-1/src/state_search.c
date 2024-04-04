#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int seconds;
    int status;
    int code;
} dataset;

dataset read_record_from_file(FILE *pfile, int index);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);

int main() {
    char str[256];
    scanf("%255s", str);
    int first = -1, second = -1, third = -1;
    scanf("%d.%d.%d", &first, &second, &third);
    FILE *door_state = fopen(str, "rb");
    if (door_state == NULL || get_records_count_in_file(door_state) == 0 || first == -1 || second == -1 ||
        third == -1) {
        printf("n/a");
        return 1;
    }
    int i = 0;
    while (i < get_records_count_in_file(door_state)) {
        dataset test = read_record_from_file(door_state, i);
        // printf("%d %d %d\n", test.year, test.month, test.day);
        if (test.day == first && test.month == second && test.year == third) printf("%d", test.code);
        i++;
    }
    fclose(door_state);
    return 0;
}

dataset read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(dataset);

    fseek(pfile, offset, SEEK_SET);

    dataset record;
    fread(&record, sizeof(dataset), 1, pfile);

    rewind(pfile);

    return record;
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(dataset); }
