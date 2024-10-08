# Embedded-Linux

## Q1) Linux Distribution:
Examples include Arch Linux, Ubuntu, Keil, Red Hat, Fedora, Debian, BlackArch

---

## Q2) man Command:
The `man` command is a system-wide documentation system that provides short reference manuals (pages) for individual commands, API functions, concepts, configuration file syntax, and file formats. It is organized in sections:
- 1 for user commands
- 2 for system calls

That's the traditional Unix documentation system.

---

## Q3) rm vs rmdir

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

![Image related to rm command](s2.png)

### rmdir:
The `rmdir` command is used to remove empty directories.
- **Syntax**: `rmdir [option]... DIRECTORY...`
- **Options**:
  - `-p` or `--parents`: Remove the directory and its ancestors if they become empty.
  - `-v` or `--verbose`: Output a diagnostic for every directory processed.
- **Examples**:
  - `rmdir emptydir`: Removes the directory `emptydir` if it is empty.
  - `rmdir -p a/b/c`: Removes the directories `c`, `b`, and `a` if they are all empty.

![Image related to rmdir command](s1.png)

---

## Q4) Working with Directories

![Image related to working with directories](s3.png)
![Image related to rm -r command](s4.png)
![Image related to rm -r command](s5.png)
![Image related to rm -r command](s6.png)


a) When I use the command `rmdir dirl/dirl1` it gives me "fail to remove directory not empty". 
	![Image related to rm -r command](s7.png)

To overcome this:
   - By using this command `rm -r dirl/dirl1` I could remove the filled directories.

![Image related to overcome](s8.png)

b) When I use this command `rmdir -p` it gives me "fail to remove directory not empty". To overcome this:
   - Starts from the root directory `/`

![Image related to root directory](s9.png)

c) The absolute path for `mycv` file:
   -  Starts from the root directory '/'
   - Absolute Path: `/home/usr/docs/mycv`

![Image related to absolute path](s23.png)

   - Starts from the current directory

   - Relative Path: `docs/mycv`

![Image related to relative path](s24.png)

---

## Q5) Copying `/etc/passwd` file to my home directory

![Image related to copying /etc/passwd](s10.png)

---

## Q6) Rename it to `oldpasswd`

![Image related to renaming file](s11.png)

---

## Q7) From `/usr/bin` go to the home directory in 4 ways

![Image related to first way](s14.png)

---

## Q8) Linux commands in `/usr/bin` that start with the letter `w`

![Image related to commands starting with w](s15.png)

---

## Q9) `type` Command:
Used to display information about command types.

---

## Q10) Two types of command files in `/usr/bin` that start with the letter `c`

![Image related to command files starting with c](s16.png)
![Image related to second command file](s18.png)

or by using `type` command on a couple of commands I know exist like (cd, cp)

![Image related to 3rd command file](s26.png)


---

## Q11) Using `man` command to find the command to read a file

![Image related to man command](s22.png)
![Image related to second command to read file](s20.png)
![Image related to reading file](s19.png)

---

## Q12) What is the usage of `apropos` command?

**Purpose**: To search the manual page database for names and descriptions that match a specific keyword or keywords.  
**Usage**: Helps users find commands related to a concept or function when they do not know the exact command name.

**Example Usage**:
- **Searching for a Keyword**:
  ```bash
  apropos read
 