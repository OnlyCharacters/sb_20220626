CC = gcc
CFLAGS = -Wall -g

dd:dd.c
	$(CC) $(CFLAGS) $^ -o $@
