# Commands and Shell Basics

### Q1) Script Description

This section describes a script that modifies the `.bashrc` file to set environment variables and prints a local variable when a new terminal is opened. It also opens a new GNOME terminal.

#### Script Breakdown

##### Shebang
```bash
#!/bin/bash
```
Specifies the script should be run using the Bash shell.

##### Check for .bashrc File
```bash
if [ -f "$HOME/.bashrc" ]; then
```
Checks if the `.bashrc` file exists in the user's home directory.

##### Append HELLO Environment Variable
```bash
echo "export HELLO=\$HOSTNAME" >> "$HOME/.bashrc"
```
Appends an environment variable `HELLO` with the value of `HOSTNAME` to the `.bashrc` file.

##### Append LOCAL Variable
```bash
echo "LOCAL=\$(whoami)" >> "$HOME/.bashrc"
```
Appends a local variable `LOCAL` with the value of the `whoami` command to the `.bashrc` file.

##### Print LOCAL Variable
```bash
echo "echo LOCAL=\$LOCAL" >> "$HOME/.bashrc"
```
Adds a command to print the `LOCAL` variable when opening a new terminal. This line prints `LOCAL=username` where `username` is the output of the `whoami` command.

##### End of if Statement
```bash
fi
```
Ends the `if` statement.

##### Open New Terminal
```bash
gnome-terminal &
```
Opens a new GNOME terminal in the background.

#### What Happens When the Terminal is Opened

When a new terminal is opened, the `.bashrc` file is sourced, which means all the commands and variable assignments in `.bashrc` are executed. In this case, it will:

1. Set the environment variable `HELLO` to the value of the `HOSTNAME` environment variable.
2. Set the local variable `LOCAL` to the username of the current user (output of the `whoami` command).
3. Print the string `LOCAL=username` to the terminal, where `username` is the current user's username.

### Q2) Command to Retrieve Command History

This command retrieves the command history using the `history` command and redirects the output to the file `/tmp/commands.list`:

```bash
history > /tmp/commands.list
```

![Example Image](02.png)

### Q3) Edit Profile and Count Words/Files

#### 2. Edit Profile to Display Date at Login and Change Prompt Permanently

Add the following line to your `.bashrc` or `.bash_profile`:

```bash
echo 'export PS1="\[\e[32m\]\u@\h \[\e[34m\]\w \[\e[35m\]\$(date "+%Y-%m-%d") \[\e[0m\]$ "' >> ~/.bashrc
source ~/.bashrc
```

#### 3. Commands for Counting Words and Files

To count the number of words in a file:

```sh
wc -w < filename
```

To count the number of files in a directory:

```sh
ls -l | grep "^-" | wc -l
```

To count the number of user commands in the history file:

```sh
history | wc -l
```

### Q4) Command Execution Examples

#### a. `cat filename1 | cat filename2`

This command will output the contents of `filename1`, which will then be piped as input to `cat filename2`. Essentially, it will display the contents of `filename1`.

#### b. `ls | rm`

This command will attempt to remove all files listed by `ls`. However, it will fail because `rm` expects filenames as arguments, not input from a pipe.

#### c. `ls /etc/passwd | wc -l`

This command lists the file `/etc/passwd` and pipes the output to `wc -l`, which counts the number of lines in the output. Since `ls` outputs a single line for `/etc/passwd`, `wc -l` will output `1`.

### Q5) Search for Files Named ".profile"

To search for all files on the system named `.profile`:

```sh
find / -name ".profile" 2>/dev/null
```

### Q6) List Inode Numbers

To list the inode numbers of `/`, `/etc`, and `/etc/hosts`:

```sh
ls -i / /etc /etc/hosts
```

### Q7) Create Links

#### a. Create a Symbolic Link

Create a symbolic link of `/etc/passwd` in `/boot`:

```sh
ln -s /etc/passwd /boot/passwd_link
```

#### b. Create a Hard Link

You cannot create a hard link of `/etc/passwd` in `/boot` because hard links cannot span across different file systems. Both the source and destination must be on the same file system.

### Q8) Change the Continuation Prompt

When using backslashes (`\`) in an `echo` command, it continues the command to the next line and prompts with `>`. To change this continuation prompt from `>` to `:`, set the `PS2` variable in your shell configuration file:

```sh
echo 'PS2=":"' >> ~/.bashrc
source ~/.bashrc
```

### Q9) Additional Prompt Customization (PS1)

For more information on shell prompt customization, refer to the usage of `PS1` and `PS2`.
