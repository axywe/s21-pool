CC = gcc
FLAGS = -Wall -Werror -Wextra
BUILD = ../build/

clean:
	rm -f $(BUILD)*

strlen_tests:
	$(CC) $(FLAGS) s21_string_test.c -DQUEST1 s21_string.c -o $(BUILD)Quest_1

strcmp_tests:
	$(CC) $(FLAGS) s21_string_test.c -DQUEST2 s21_string.c -o $(BUILD)Quest_2

strcpy_tests:
	$(CC) $(FLAGS) s21_string_test.c -DQUEST3 s21_string.c -o $(BUILD)Quest_3

strcat_tests:
	$(CC) $(FLAGS) s21_string_test.c -DQUEST4 s21_string.c -o $(BUILD)Quest_4

strchr_tests:
	$(CC) $(FLAGS) s21_string_test.c -DQUEST5 s21_string.c -o $(BUILD)Quest_5

strstr_tests:
	$(CC) $(FLAGS) s21_string_test.c -DQUEST6 s21_string.c -o $(BUILD)Quest_6

strtok_tests:
	$(CC) $(FLAGS) s21_string_test.c -DQUEST7 s21_string.c -o $(BUILD)Quest_7

text_processor:
	$(CC) $(FLAGS) text_processor.c -o $(BUILD)Quest_8