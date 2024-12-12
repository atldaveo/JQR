# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Project Name
PROJECT = cll-test

# Source and Build Directories
SRCDIR = src
BUILDDIR = build
INCDIR = include

# Source Files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

# Include Paths
INCLUDES = -I$(INCDIR)

# Final Executable
TARGET = $(PROJECT)

# Default Rule
all: $(TARGET)

# Linking Object Files into Executable
$(TARGET): $(OBJS)
	@echo "Linking: $@"
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiling Source Files into Object Files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	@echo "Compiling: $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean Build Files
clean:
	@echo "Cleaning build files..."
	rm -rf $(BUILDDIR) $(TARGET)

# Rebuild Project
rebuild: clean all

# Phony Targets
.PHONY: all clean rebuild
