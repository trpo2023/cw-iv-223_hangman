CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
TEST_DIR = test
BIN_DIR = bin
OBJ_DIR = obj

all: $(BIN_DIR)/game

$(BIN_DIR)/game: $(OBJ_DIR)/main.o $(OBJ_DIR)/hangman.o
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/hangman.o -o $(BIN_DIR)/game 
	ar rcs lib/mylib.a $(OBJ_DIR)/hangman.o

$(OBJ_DIR)/main.o: src/app/main.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c src/app/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/hangman.o: src/app_lib/hangman.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c src/app_lib/hangman.c -o $(OBJ_DIR)/hangman.o

$(OBJ_DIR)/test_hangman.o: test/test_hangman.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c test/test_hangman.c -o $(OBJ_DIR)/test_hangman.o

$(BIN_DIR)/tests: $(OBJ_DIR)/test_hangman.o $(OBJ_DIR)/hangman.o
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_DIR)/test_hangman.o lib/mylib.a -o $(BIN_DIR)/tests

lib/mylib.a: $(OBJ_DIR)/hangman.o
	mkdir -p lib
	ar rcs lib/mylib.a $(OBJ_DIR)/hangman.o

tests: $(BIN_DIR)/tests

run: $(BIN_DIR)/game
	./$(BIN_DIR)/game

run_tests: $(BIN_DIR)/tests
	xvfb-run -a ./$(BIN_DIR)/tests

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) lib/mylib.a