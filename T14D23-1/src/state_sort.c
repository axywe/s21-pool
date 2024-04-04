#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

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
void write_record_in_file(FILE *pfile, const dataset *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
void bubble_sort(FILE *pfile);

int main() {
    char str[256];
    scanf("%255s", str);
    int todo;
    scanf("%d", &todo);
    FILE *door_state = fopen(str, "rb+");
    if (door_state == NULL || get_records_count_in_file(door_state) == 0 ||
        (todo != 0 && todo != 1 && todo != 2)) {
        printf("n/a");
        return 1;
    }
    int i = 0;
    if (todo == 2) {
        dataset test;
        scanf("%d %d %d %d %d %d %d %d", &test.year, &test.month, &test.day, &test.hour, &test.minutes,
              &test.seconds, &test.status, &test.code);
        write_record_in_file(door_state, &test, get_records_count_in_file(door_state));
    }
    if (todo == 1 || todo == 2) {
        bubble_sort(door_state);
    }
    while (i < get_records_count_in_file(door_state)) {
        dataset test = read_record_from_file(door_state, i);
        printf("%d %d %d %d %d %d %d %d", test.year, test.month, test.day, test.hour, test.minutes,
               test.seconds, test.status, test.code);
        i++;
        if (i != get_records_count_in_file(door_state)) printf("\n");
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

void write_record_in_file(FILE *pfile, const dataset *record_to_write, int index) {
    int offset = index * sizeof(dataset);

    fseek(pfile, offset, SEEK_SET);

    fwrite(record_to_write, sizeof(dataset), 1, pfile);

    fflush(pfile);

    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    dataset record1 = read_record_from_file(pfile, record_index1);
    dataset record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(dataset); }

void bubble_sort(FILE *pfile) {
    int size = get_records_count_in_file(pfile);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            dataset record1 = read_record_from_file(pfile, j);
            dataset record2 = read_record_from_file(pfile, j + 1);

            if (record1.year > record2.year ||
                (record1.year == record2.year && record1.month > record2.month) ||
                (record1.year == record2.year && record1.month == record2.month &&
                 record1.day > record2.day) ||
                (record1.year == record2.year && record1.month == record2.month &&
                 record1.day == record2.day && record1.hour > record2.hour) ||
                (record1.year == record2.year && record1.month == record2.month &&
                 record1.day == record2.day && record1.hour == record2.hour &&
                 record1.minutes > record2.minutes) ||
                (record1.year == record2.year && record1.month == record2.month &&
                 record1.day == record2.day && record1.hour == record2.hour &&
                 record1.minutes == record2.minutes && record1.seconds > record2.seconds)) {
                swap_records_in_file(pfile, j, j + 1);
            }
        }
    }
}