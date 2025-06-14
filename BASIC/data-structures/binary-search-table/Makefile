# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files and object files
SRC_FILES = $(SRC_DIR)/bst.c $(SRC_DIR)/bst-test.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Output binary
EXEC = bst

# Default target
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC)

# Rule to create object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Run the executable after build
run: $(EXEC)
	./$(EXEC)

# Debug target: Clean, rebuild with debug symbols, and run Valgrind
debug: clean
	$(MAKE) CFLAGS="$(CFLAGS) -g" all
	valgrind --leak-check=full ./$(EXEC)

# Clean up
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)

# Phony targets
.PHONY: all clean run

