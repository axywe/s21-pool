#include "logger.h"

#include <string.h>
#include <time.h>

FILE* log_init(char* filename) {
    FILE* log_file = fopen(filename, "w");
    return log_file;
}

int logcat(FILE* log_file, char* message, log_level level) {
    if (log_file == NULL || message == NULL) {
        return -1;
    }

    time_t current_time;
    time(&current_time);
    char* timestamp = ctime(&current_time);
    timestamp[strlen(timestamp) - 1] = '\0';  // Remove the newline character from the timestamp

    const char* level_strings[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    fprintf(log_file, "%s - %s: %s\n", timestamp, level_strings[level], message);
    fflush(log_file);  // Flush the file buffer to ensure immediate writing

    return 0;
}

int log_close(FILE* log_file) {
    if (log_file == NULL) {
        return -1;
    }

    fclose(log_file);
    return 0;
}
