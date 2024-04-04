#include <stdio.h>
#ifdef QUEST1
#include "print_module.h"
#endif
// #define QUEST2
#ifdef QUEST2
#include "documentation_module.h"
#endif
int main() {
#ifdef QUEST1
    print_log(print_char, Module_load_success_message);
#endif
#ifdef QUEST2
    int* availability_mask = check_available_documentation_module(validate, Documents_count, Documents);

    // Output availability for each document....
    print_available(availability_mask, Documents_count, Documents);
    if (availability_mask != NULL) free(availability_mask);
#endif

    return 0;
}
