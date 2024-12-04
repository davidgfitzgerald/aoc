CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -fPIC

TESTING_C = testing.c
TESTING_O = $(TESTING_C:.c=.o)
LIB_TESTING_SO = lib$(TESTING_C:.c=.so)

.PHONY: all clean

all: $(TESTING_O) $(LIB_TESTING_SO)

$(TESTING_O): $(TESTING_C)
	$(CC) $(CFLAGS) -c $(TESTING_C) -o $(TESTING_O)

$(LIB_TESTING_SO): $(TESTING_O)
	$(CC) $(CFLAGS) -shared -o $(LIB_TESTING_SO) $(TESTING_O)

clean:
	rm -f $(TESTING_O) $(LIB_TESTING_SO)
