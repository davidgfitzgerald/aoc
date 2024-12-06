# Compiler command and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all clean test run  # Define commands as opposed to files to create

# Default commands to run
all: part1.out test_part1.out

# Create all .o files from all .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create src executable .out file
part1.out: part1.o
	$(CC) $(CFLAGS) -o part1.out part1.o

# Create test executable .out file
test_part1.out: test_part1.o funcs.o
	$(CC) $(CFLAGS) -o test_part1.out test_part1.o ../../testing/testing.o funcs.o

# Remove .o and .out files
clean:
	rm -f part1.o part1.out test_part1.o test_part1.out funcs.o

# Run the test .out file
test: test_part1.out
	./test_part1.out

# Run the source .out file
run: part1.out
	./part1.out
