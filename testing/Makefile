# Build testing.o

.PHONY: all clean

all: testing.o

testing.o: testing.c
	gcc -Wall -Wextra -std=c99 -c testing.c -o testing.o

clean:
	rm -f testing.o
