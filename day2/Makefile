CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS_PT1 = part1.c testing.c
OBJS_PT1 = $(SRCS_PT1:.c=.o)
EXEC_PT1 = part1.out

SRCS_PT2 = part2.c
OBJS_PT2 = $(SRCS_PT2:.c=.o)
EXEC_PT2 = part2.out

.PHONY: all clean

all: $(EXEC_PT1) $(EXEC_PT2)

$(EXEC_PT1): $(OBJS_PT1)
	$(CC) $(CFLAGS) -o $(EXEC_PT1) $(OBJS_PT1)

$(EXEC_PT2): $(OBJS_PT2)
	$(CC) $(CFLAGS) -o $(EXEC_PT2) $(OBJS_PT2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_PT1) $(EXEC_PT1) $(OBJS_PT2) $(EXEC_PT2)

test_pt1: $(EXEC_PT1)
	./$(EXEC_PT1) --test

run_pt1: $(EXEC_PT1)
	./$(EXEC_PT1)

run_pt2: $(EXEC_PT2)
	./$(EXEC_PT2)
