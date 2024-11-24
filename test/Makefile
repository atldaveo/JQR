# Compiler
CC = gcc

# Directories
SRCDIR = src
BUILDDIR = build
INCLUDEDIR = include
TESTDIR = test

# Source files and object files
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/math.c
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))

# Output executables
TARGET = $(BUILDDIR)/simple-calc
TEST_TARGET = $(BUILDDIR)/test-math

# Compiler flags
CFLAGS = -I$(INCLUDEDIR) -Wall -Wextra
DEBUGFLAGS = -g -DDEBUG
RELEASEFLAGS = -O2
TESTFLAGS = -lcunit

# Default build (release mode)
all: release

# Debug build
debug: CFLAGS += $(DEBUGFLAGS)
debug: $(TARGET)

# Release build
release: CFLAGS += $(RELEASEFLAGS)
release: $(TARGET)

# Build the main target
$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(CC) $(OBJECTS) -o $(TARGET)

# Rule to build object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Test build
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Build the test executable
$(TEST_TARGET): $(SRCDIR)/math.c $(TESTDIR)/test_math.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(TESTDIR)/test_math.c $(SRCDIR)/math.c -o $(TEST_TARGET) $(TESTFLAGS)

# Clean rule to remove build artifacts
clean:
	rm -rf $(BUILDDIR)

# Phony targets
.PHONY: all debug release test clean
