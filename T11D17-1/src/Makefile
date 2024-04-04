CC = gcc
FLAGS = -Wall -Werror -Wextra
BUILD = -o ../build/

all: stack_test list_test door_struct

door_struct:
	$(CC) $(FLAGS) dmanager_module.c $(BUILD)Quest_1

list_test:
	$(CC) $(FLAGS) list_test.c list.c $(BUILD)Quest_2

stack_test:
	 $(CC) $(FLAGS) stack.c stack_test.c $(BUILD)Quest_3

clean:
	rm ../build/Quest_* ./a.out