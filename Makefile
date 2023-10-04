CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
SRC_DIR = src
TEST_DIR = test
BIN_DIR = bin

all: $(BIN_DIR)/app

$(BIN_DIR)/app: obj/main.o obj/hangman.o
	$(CC) $(CFLAGS) -o bin/app obj/main.o obj/hangman.o

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -o obj/main.o -c src/main.c

obj/hangman.o: src/hangman.c
	$(CC) $(CFLAGS) -o obj/hangman.o -c src/hangman.c	

tests: $(BIN_DIR)/tests

$(BIN_DIR)/tests: obj/test_hangman.o obj/hangman.o
	$(CC) $(CFLAGS) -o bin/tests obj/test_hangman.o obj/hangman.o

obj/test_hangman.o: test/test_hangman.c
	$(CC) $(CFLAGS) -o obj/test_hangman.o -c test/test_hangman.c
