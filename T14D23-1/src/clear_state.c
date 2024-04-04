#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

int get_int();
dataset read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const dataset *record_to_write, int index);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
void remove_records_in_interval(FILE *pfile, const char *start_date, const char *end_date);

int check(dataset *num1, dataset *num2) {
    int ret = -1;
    if (num1 != NULL && num2 != NULL) {
        if (num2->year > num1->year) {
            ret = 1;
        } else if (num2->year == num1->year && num2->month > num1->month) {
            ret = 1;
        } else if (num2->year == num1->year && num2->month == num1->month && num2->day > num1->day) {
            ret = 1;
        } else if (num2->year == num1->year && num2->month == num1->month && num2->day == num1->day) {
            ret = 1;
        } else {
            ret = 0;
        }
    }

    return ret;
}

int main() {
    char str[256];
    scanf("%255s", str);
    char start_date[11];
    char end_date[11];
    scanf("%10s %10s", start_date, end_date);
    FILE *door_state = fopen(str, "rb+");
    if (door_state == NULL || get_records_count_in_file(door_state) == 0) {
        printf("n/a");
        return 1;
    }

    int total_records = get_records_count_in_file(door_state);
    int count = 0;

    for (int i = 0; i < total_records; i++) {
        dataset buf = read_record_from_file(door_state, i);

        dataset time1, time2;
        sscanf(start_date, "%d.%d.%d", &time1.day, &time1.month, &time1.year);
        sscanf(end_date, "%d.%d.%d", &time2.day, &time2.month, &time2.year);
        if (check(&time1, &buf) == 0 || check(&buf, &time2) == 0) {
            printf("%d %d %d %d %d %d %d %d\n", buf.year, buf.month, buf.day, buf.hour, buf.minutes,
                   buf.seconds, buf.code, buf.status);
            write_record_in_file(door_state, &buf, count);
            count++;
        }
    }

    if (count < total_records) {
        int new_file_size = count * sizeof(dataset);
        ftruncate(fileno(door_state), new_file_size);
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

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(dataset); }