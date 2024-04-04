CC = gcc
FLAGS = -Wall -Werror -Wextra
MAIN_EXC = main_executable_module.c
DATA_MODULE = ../data_module/data_process.c
QUEST_3 = ../../build/Quest_3
QUEST_4 = ../../build/Quest_4
QUEST_5 = ../../build/Quest_5
QUEST_6 = ../../build/Quest_6
ANOTHER = ../yet_another_decision_module/decision.c
DATA_STAT = ../data_libs/data_stat.c
DATA_IO = ../data_libs/data_io.c

all:
	$(CC) $(FLAGS) $(MAIN_EXC) $(DATA_STAT) $(DATA_IO) $(ANOTHER) $(DATA_MODULE) -o $(QUEST_3)
clean:
	rm $(QUEST_3) $(QUEST_5) $(QUEST_6) data_stat.* ../main_executable_module/data_process.so data_process.so ../data_libs/data_stat.o ../../build/* ../../data_process.so
rebuild: clean all
data_stat.a: ../data_libs/data_stat.o
	ar rc ../../build/data_stat.a ../data_libs/data_stat.o
build_with_static: data_stat.a
		$(CC) $(FLAGS) $(MAIN_EXC) ../../build/data_stat.a $(DATA_IO) $(ANOTHER) $(DATA_MODULE) -o $(QUEST_5)
data_process.so: ../data_module/data_process.o data_stat.a
	gcc -shared -fPIC ../data_module/data_process.o ../../build/data_stat.a -o data_process.so
	cp data_process.so ../../build/data_process.so
	cp data_process.so ../../
	rm ../data_module/data_process.o ../data_libs/data_stat.o ../../build/data_stat.a
build_with_dynamic: data_process.so
		$(CC) $(FLAGS) $(MAIN_EXC) data_process.so $(DATA_IO) $(ANOTHER) -o $(QUEST_6)
build_with_macro:
		$(CC) $(FLAGS) $(MAIN_EXC) $(DATA_STAT) -DMACRO $(ANOTHER) $(DATA_MODULE) -o $(QUEST_4)