CC = g++
CFLAGS = -Wall -Wextra

TARGET = main
SOURCES_DIR = src
TESTS_DIR = tests

SOURCES = $(SOURCES_DIR)/main.cpp
TESTS = $(TESTS_DIR)/Source.cpp

all: $(TARGET) test

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

test: $(TESTS)
	$(CC) $(CFLAGS) -o $(TESTS_DIR)/test $(TESTS)
	$(TESTS_DIR)/test

clean:
	rm -f $(TARGET) $(TESTS_DIR)/test
