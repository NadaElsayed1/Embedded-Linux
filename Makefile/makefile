CC := gcc
INCS := -I ./include

# Directories
SRC_DIR := src
INCLUDE_DIR := include
BIN_DIR := bin
BUILD_DIR := build

# Source, object, and executable files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))
EXEC := $(BUILD_DIR)/app

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(INCS) $(OBJS) -o $(EXEC)

# Rule to compile source files into object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) -c $(INCS) $< -o $@

# Clean target
.PHONY: clean
clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)

# Print a message indicating successful build
.PHONY: all
all: $(EXEC)
	@echo "Build complete: $(EXEC)"
