#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list args;
    va_start(args, document_count);

    int* availability_mask = (int*)malloc(document_count * sizeof(int));
    for (int i = 0; i < document_count; i++) {
        char* document = va_arg(args, char*);
        availability_mask[i] = validate(document);
    }
    va_end(args);
    return availability_mask;
}

void print_available(const int* availability_mask, int document_count, ...) {
    va_list args;
    va_start(args, document_count);

    for (int i = 0; i < document_count; i++) {
        printf("%-15s : %s", va_arg(args, char*), availability_mask[i] == 1 ? "available" : "unavailable");
        if (i != document_count - 1) printf("\n");
    }
    va_end(args);
}