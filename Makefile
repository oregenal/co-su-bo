CC=gcc
CFLAGS=-Wall -Wextra -pedantic -ggdb
LIBS=-lm
BIN=graph

$(BIN):main.c vect.c vect.h
	$(CC) $(CFLAGS) -o $@ main.c vect.c $(LIBS)
