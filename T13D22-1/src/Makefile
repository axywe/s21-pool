CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC = src/cipher.c
EXECUTABLE = ../build/cipher

all: cipher2 logging_cipher

cipher:
	gcc cipher.c -o ../build/cipher

cipher2:
	gcc cipher.c -DQUEST4 -o ../build/cipher

logging_cipher:
	gcc -DQUEST4 -DQUEST5 cipher.c logger.c -o ../build/logging_cipher

clean:
	rm a.out ../build/Quest_1 ../build/cipher ../build/logging_cipher
