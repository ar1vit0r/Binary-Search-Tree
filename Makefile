CC=gcc

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 

.PHONY: all clean


all: clean grade

arvore.o: arvore.c

test: arvore.o test.c
	$(CC) $(CFLAGS) arvore.o test.c -o test -lm

grade: test
	./test



clean:
	rm -rf *.o test test.dSYM

