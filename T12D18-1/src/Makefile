CC = gcc -Wall -Wextra -Werror -std=c11
SANITIZE = -fsanitize=address -fsanitize=leak

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

print_module:
	$(CC) main_module_entry_point.c print_module.c -DQUEST1 -o ../build/Quest_1

documentation_module:
	$(CC) main_module_entry_point.c documentation_module.c print_module.c -DQUEST2 -o ../build/Quest_2

bst_create_test:
	$(CC) bst.c bst_create_test.c -o ../build/Quest_3

bst_insert_test:
	$(CC) bst.c bst_insert_test.c -o ../build/Quest_4

bst_traverse_test:
	$(CC) bst.c bst_traverse_test.c -o ../build/Quest_5

clean:
	rm ../build/Quest_* ./a.out