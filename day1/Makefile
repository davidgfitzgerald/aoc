CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c
OBJS = $(SRCS:.c=.o)
EXEC = main.out

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC)
