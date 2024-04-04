CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak

all: state_sort state_search clear_state

state_sort:
	$(CC) $(FLAGS) state_sort.c -o ../build/Quest_1

state_search:
	$(CC) $(FLAGS) state_search.c -o ../build/Quest_2

clear_state:
	$(CC) $(FLAGS) clear_state.c -o ../build/Quest_3

clean:
	rm -f a.out ../build/Quest_*