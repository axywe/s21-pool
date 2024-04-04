#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef QUEST5
#include "logger.h"
#endif

#define BUFFER_SIZE 1024

void readAndPrintFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("n/a");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize == 0) {
        printf("n/a");
        fclose(file);
        return;
    }
    fseek(file, 0, SEEK_SET);

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void appendToFile(const char* filename, const char* text) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("n/a");
        return;
    }

    fprintf(file, "%s", text);
    fclose(file);
}

void caesarCipherFile(const char* filename, int shift) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        printf("n/a");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + shift + 26) % 26;
        } else if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + shift + 26) % 26;
        }
        fseek(file, -1, SEEK_CUR);
        fputc(ch, file);
    }

    fclose(file);
}
#ifdef QUEST4
void desCipherFile(const char* filename, int temp) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL || temp != 0) {
        printf("n/a\n");
        return;
    }

    char buffer;
    while ((buffer = fgetc(file)) != EOF) {
        if ((buffer >= 'A' && buffer <= 'Z') || (buffer >= 'a' && buffer <= 'z') ||
            (buffer >= '0' && buffer <= '9')) {
            char input[2] = {buffer, '\0'};
            char* encrypted = crypt(input, "A9");
            buffer = encrypted[strlen(encrypted) - 1];
            fseek(file, -1, SEEK_CUR);
            fputc(buffer, file);
        }
    }

    fclose(file);
}
#endif
void encryptAllCFiles(const char* directoryPath, int shift, void (*cpr)(const char*, int)) {
    DIR* dir = opendir(directoryPath);
    if (dir == NULL) {
        printf("n/a\n");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char* filename = entry->d_name;
            size_t length = strlen(filename);
            if (length > 2 && strcmp(filename + length - 2, ".c") == 0) {
                char filePath[256];
                snprintf(filePath, sizeof(filePath), "%s/%s", directoryPath, filename);
                cpr(filePath, shift);
            }
        }
    }

    closedir(dir);
}

void clearHeaderFiles(const char* directoryPath) {
    DIR* dir = opendir(directoryPath);
    if (dir == NULL) {
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char* filename = entry->d_name;
            size_t length = strlen(filename);
            if (length > 2 && strcmp(filename + length - 2, ".h") == 0) {
                char filePath[256];
                snprintf(filePath, sizeof(filePath), "%s/%s", directoryPath, filename);
                FILE* file = fopen(filePath, "w");
                if (file == NULL) {
                    printf("n/a\n");
                    closedir(dir);
                    return;
                }
                fclose(file);
            }
        }
    }

    closedir(dir);
}

int main() {
    char filename[256];
    char text[256];
    int shift;
    int fileLoaded = 0;
#ifdef QUEST5
    FILE* log_file = log_init("cipher.log");
#endif
    while (1) {
        int choice;
        scanf("%d", &choice);

        if (choice == -1) {
            break;
        } else if (choice == 1) {
            scanf("%255s", filename);
            FILE* tmp;
            tmp = fopen(filename, "rb+");
            if (tmp != NULL) {
                fileLoaded = 1;
                readAndPrintFile(filename);
#ifdef QUEST5
                logcat(log_file, "File read", INFO);
#endif
            } else {
#ifdef QUEST5
                logcat(log_file, "Error while reading file", ERROR);
#endif
                printf("n/a");
                fileLoaded = 0;
            }
        } else if (choice == 2) {
            scanf(" %255[^\n]", text);
            if (fileLoaded) {
                appendToFile(filename, text);
                readAndPrintFile(filename);
#ifdef QUEST5
                logcat(log_file, "Text appended to file", INFO);
#endif
            } else {
                printf("n/a");
#ifdef QUEST5
                logcat(log_file, "Error appending to file", INFO);
#endif
            }
        } else if (choice == 3) {
            char directoryPath[256];
            scanf("%255s", directoryPath);
            scanf("%d", &shift);
            encryptAllCFiles(directoryPath, shift, caesarCipherFile);
            clearHeaderFiles(directoryPath);
#ifdef QUEST5
            logcat(log_file, "Files encrypted", INFO);
#endif
        }
#ifdef QUEST4
        else if (choice == 4) {
            char directoryPath[256];
            scanf("%255s", directoryPath);
            encryptAllCFiles(directoryPath, 0, desCipherFile);
            clearHeaderFiles(directoryPath);
#ifdef QUEST5
            logcat(log_file, "Files encrypted", INFO);
#endif
        }
#endif
        else {
            printf("n/a\n");
            clearerr(stdin);
        }
        if (choice != 3 && choice != 4) printf("\n");
    }
#ifdef QUEST5
    log_close(log_file);
#endif
    return 0;
}
