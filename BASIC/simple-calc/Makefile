# Compiler
CC = gcc
MUSL_CC = musl-gcc

# Directories
SRCDIR = src
BUILDDIR = build
INCLUDEDIR = include
TESTDIR = test

# Source files and object files
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/arithmetic.c $(SRCDIR)/operations.c $(SRCDIR)/validations.c
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))

# Output executables
TARGET = simple-calc
TEST_TARGET = test-arithmetic

# Compiler flags
CFLAGS = -I$(INCLUDEDIR) -Wall -Wextra -fPIC
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
	@set -f; ./$(TEST_TARGET)

# Run the main target
run: $(TARGET)
	@set -f; ./$(TARGET)

# Build the test executable
$(TEST_TARGET): $(SRCDIR)/arithmetic.c $(SRCDIR)/operations.c $(SRCDIR)/validations.c $(TESTDIR)/test-arithmetic.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(TESTDIR)/test-arithmetic.c $(SRCDIR)/arithmetic.c $(SRCDIR)/operations.c $(SRCDIR)/validations.c -o $(TEST_TARGET) $(TESTFLAGS)

# Static Analysis
tidy:
	clang-tidy $(SOURCES) -checks="cert-*,bugprone-*,misc-*,readability-*" --warnings-as-errors=* -- $(CFLAGS) -I$(INCLUDEDIR)

# Clean rule to remove build artifacts
clean:
	rm -rf $(BUILDDIR)/*.o $(BUILDDIR)/*-musl.o $(TARGET) $(TARGET).exe $(TARGET)-musl *.txt $(TEST_TARGET)

# Configure MUSL build
musl: CFLAGS += $(RELEASEFLAGS)
musl: CC = $(MUSL_CC)
musl: $(TARGET)-musl

# Build MUSL target
$(TARGET)-musl: $(OBJECTS:.o=-musl.o)
	@mkdir -p $(BUILDDIR)
	$(CC) $^ -static -o $(TARGET)-musl

# Recompile objects with musl-gcc
$(BUILDDIR)/%-musl.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(MUSL_CC) $(CFLAGS) -c $< -o $@

# Phony targets
.PHONY: all debug release test clean
