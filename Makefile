CC=gcc
CFLAGS=-Wall -Wextra -pedantic -ggdb
LIBS=-lm
BIN=graph

$(BIN):main.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)
