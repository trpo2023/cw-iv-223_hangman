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

clean:
	rm -f $(TARGET)
