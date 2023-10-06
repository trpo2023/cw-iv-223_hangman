CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
SRC_DIR = src
TEST_DIR = test
BIN_DIR = bin
OBJ_DIR = obj

all: $(BIN_DIR)/app

$(BIN_DIR)/app: $(OBJ_DIR)/main.o $(OBJ_DIR)/hangman.o
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/app $(OBJ_DIR)/main.o $(OBJ_DIR)/hangman.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/main.o -c $(SRC_DIR)/main.c

$(OBJ_DIR)/hangman.o: $(SRC_DIR)/hangman.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/hangman.o -c $(SRC_DIR)/hangman.c	

tests: $(BIN_DIR)/tests

$(BIN_DIR)/tests: $(OBJ_DIR)/test_hangman.o $(OBJ_DIR)/hangman.o
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/tests $(OBJ_DIR)/test_hangman.o $(OBJ_DIR)/hangman.o

$(OBJ_DIR)/test_hangman.o: $(TEST_DIR)/test_hangman.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/test_hangman.o -c $(TEST_DIR)/test_hangman.c

.PHONY: clean

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)