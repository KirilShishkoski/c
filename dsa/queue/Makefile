CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c11 -O2

TARGET  = demo
SRC     = main.c queue.c
OBJ     = $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c queue.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)