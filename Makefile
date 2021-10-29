CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
LIBS=-lm
BIN=ball

$(BIN):main.c vect.c vect.h
	$(CC) $(CFLAGS) -o $@ main.c vect.c $(LIBS)
