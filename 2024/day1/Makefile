CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS_PT1 = part1.c ../../testing/testing.c test_part1.c
OBJS_PT1 = $(SRCS_PT1:.c=.o)
EXEC_PT1 = part1.out

.PHONY: all clean

all: $(EXEC_PT1)

$(EXEC_PT1): $(OBJS_PT1)
	$(CC) $(CFLAGS) -o $(EXEC_PT1) $(OBJS_PT1)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_PT1) $(EXEC_PT1)

test_pt1: $(EXEC_PT1)
	./$(EXEC_PT1) --test

run_pt1: $(EXEC_PT1)
	./$(EXEC_PT1)
