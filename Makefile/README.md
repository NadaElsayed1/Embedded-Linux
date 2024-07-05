
```bash
# Simple Calculator Application

This is a simple calculator application implemented in C, capable of performing basic arithmetic operations (+, -, *, /) based on user input.

## Directory Structure

```
project_root/
├── Makefile
├── src/
│   ├── main.c
│   └── other_source_files.c
├── include/
│   ├── main.h
│   └── other_header_files.h
├── bin/
└── build/
```

## Makefile Overview

### Compiler and Flags

- `CC := gcc` specifies the compiler.
- `INCS := -I ./include` specifies the include directory.

### Directories

- `SRC_DIR := src` defines the source directory.
- `INCLUDE_DIR := include` defines the include directory.
- `BIN_DIR := bin` defines the directory for object files.
- `BUILD_DIR := build` defines the directory for the final executable.

### Files

- `SRCS := $(wildcard $(SRC_DIR)/*.c)` lists all the source files.
- `OBJS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))` converts source file paths to object file paths.
- `EXEC := $(BUILD_DIR)/app` defines the path for the executable.

### Default Target

- `all: $(EXEC)` specifies the default target to build the executable.

### Rule to Build the Executable

- `$(EXEC): $(OBJS)` specifies that the executable depends on the object files.
  - `@mkdir -p $(BUILD_DIR)` creates the build directory if it doesn't exist.
  - `$(CC) $(INCS) $(OBJS) -o $(EXEC)` links the object files to create the executable.

### Rule to Compile Source Files

- `$(BIN_DIR)/%.o: $(SRC_DIR)/%.c` specifies that object files depend on source files.
  - `@mkdir -p $(BIN_DIR)` creates the bin directory if it doesn't exist.
  - `$(CC) -c $(INCS) $< -o $@` compiles the source file into an object file.

### Clean Target

- `clean:` removes the bin and build directories.

### Echo Message

- `@echo "Build complete: $(EXEC)"` prints a message after a successful build.

## Build and Run the Application

1. **Build the Project**:
   ```sh
   make
   ```

2. **Run the Executable**:
   ```sh
   ./build/app
   ```

3. **Clean the Build**:
   ```sh
   make clean
   ```

## Example Output

```
This is a simple calculator application
using operators (+, -, /, *)
Please enter 1st number: 22
Please enter the operator: /
Please enter 2nd number: 0
Your equation:
    MATH ERROR!
```

![Project Image](s26.png)