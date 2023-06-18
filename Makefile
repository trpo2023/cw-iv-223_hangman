CC = g++
CFLAGS = -std=c++11
SRC_DIR = src
TESTS_DIR = tests

all: main source

main: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -o main $<

source: $(TESTS_DIR)/Source.cpp
	$(CC) $(CFLAGS) -o source $<

clean:
	rm -f main source

run_main: main
	./main

run_source: source
	./source
