CC=gcc
CFLAGS=-std=c99 -g3

all:
	$(CC) $(CFLAGS) DM.c -o DM

clean:
	rm -Rf *~ DM
