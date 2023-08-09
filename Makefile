# Makefile for the Sudoku program

# Compiler and compiler flags
CC = g++
CFLAGS = -std=c++11 -Wall

# Source file and executable name
SOURCE_DIR = source
SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.cc)
EXECUTABLE = sudoku

# Rules
all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE_FILES)
	$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)