GCC=gcc -std=c17 -g #-Wall -Wextra

.PHONY: all run clean test

all: run

run: main.out
	./main.out $(ARGS)

test: test.out
	./test.out

lib.o: lib.c
	$(GCC) -c lib.c -o lib.o

main.out: main.c lib.o
	$(GCC) main.c lib.o -o main.out

test.out: test.c lib.o
	$(GCC) test.c lib.o -o test.out

clean:
	rm -rf main.out* lib.o test.out*