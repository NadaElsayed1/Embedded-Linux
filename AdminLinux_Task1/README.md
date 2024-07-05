# Embedded-Linux

## Linux Distribution:
Examples include Arch Linux, Ubuntu, Keil, Red Hat, Fedora, Debian, BlackArch

---

## man Command:
The `man` command is a system-wide documentation system that provides short reference manuals (pages) for individual commands, API functions, concepts, configuration file syntax, and file formats. It is organized in sections:
- 1 for user commands
- 2 for system calls

That's the traditional Unix documentation system.

---

## rm vs rmdir

### rm:
The `rm` command is used to remove files or directories.
- **Syntax**: `rm [option]... [file]...`
- **Options**:
  - `-r` or `--recursive`: Remove directories and their contents recursively.
  - `-f` or `--force`: Ignore nonexistent files and never prompt.
  - `-i`: Prompt before every removal.
  - `-I`: Prompt once before removing more than three files, or when removing recursively.
  - `--one-file-system`: When removing a hierarchy recursively, skip any directory that is on a file system different from that of the corresponding command line argument.
- **Examples**:
  - `rm file.txt`: Removes the file `file.txt`.
  - `rm -r dir`: Removes the directory `dir` and its contents.

### rmdir:
The `rmdir` command is used to remove empty directories.
- **Syntax**: `rmdir [option]... DIRECTORY...`
- **Options**:
  - `-p` or `--parents`: Remove the directory and its ancestors if they become empty.
  - `-v` or `--verbose`: Output a diagnostic for every directory processed.
- **Examples**:
  - `rmdir emptydir`: Removes the directory `emptydir` if it is empty.
  - `rmdir -p a/b/c`: Removes the directories `c`, `b`, and `a` if they are all empty.

---

## Reading Files with Commands

To read the contents of a file (e.g., `lab1.cpp`), you can use one of the following commands:

### Using `cat`
To read the entire content of `lab1.cpp`:
```bash
cat lab1.cpp
 