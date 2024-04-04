CC = gcc
FLAGS = -Wall -Wextra -Werror
BUILD = ../build/

all: clear style clean build_db

build_db: modules.o modules_index.o modules_db.o levels.o status_events.o shared.o
	$(info                                         )
	$(info ----------------------------------------)
	$(info Linking                                 )
	$(info ----------------------------------------)
	$(CC) $(FLAGS) $(BUILD)modules.o $(BUILD)modules_index.o $(BUILD)modules_db.o $(BUILD)levels.o $(BUILD)status_events.o shared.h $(BUILD)shared.o -o $(BUILD)db

modules.o:
	$(info                                         )
	$(info ----------------------------------------)
	$(info Compiling modules.o                     )
	$(info ----------------------------------------)
	$(CC) -c modules.c -o $(BUILD)modules.o
	rm -f ../build*.o

modules_index.o:
	$(info                                         )
	$(info ----------------------------------------)
	$(info Compiling modules_index.o               )
	$(info ----------------------------------------)
	$(CC) -c modules_index.c -o $(BUILD)modules_index.o

modules_db.o:
	$(info                                         )
	$(info ----------------------------------------)
	$(info Compiling modules_db.o                  )
	$(info ----------------------------------------)
	$(CC) -c modules_db.c -o $(BUILD)modules_db.o

levels.o:
	$(info                                         )
	$(info ----------------------------------------)
	$(info Compiling levels.o                      )
	$(info ----------------------------------------)
	$(CC) -c levels.c -o $(BUILD)levels.o

status_events.o:
	$(info                                         )
	$(info ----------------------------------------)
	$(info Compiling status_events.o               )
	$(info ----------------------------------------)
	$(CC) -c status_events.c -o $(BUILD)status_events.o

shared.o:
	$(info                                         )
	$(info ----------------------------------------)
	$(info Compiling shared.o                      )
	$(info ----------------------------------------)
	$(CC) -c shared.c -o $(BUILD)shared.o

clean:
	$(info                                         )
	$(info ----------------------------------------)
	$(info Clean                                   )
	$(info ----------------------------------------)
	rm -f ../build/* a.out

style:
	$(info                                         )
	$(info ----------------------------------------)
	$(info Check for code style and formatting     )
	$(info ----------------------------------------)
	[ -f ./.clang-format ] || cp ../materials/linters/.clang-format .
	clang-format -i *.[ch]

clear:
	clear