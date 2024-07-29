Here's the enhanced version of your file:

---

## The First Process
### Init Process

The init process is the first process created by the kernel, and it branches into other processes. It is the root of the process tree. The kernel creates the init process, which can be specified using `init=/sbin/init` or `init=/bin/sh`. The main purpose of the init process is to provide a GUI or shell to interface with the kernel.

### Types of Processes (BusyBox)
When we run the process `/sbin/init`, it gets a configuration file as input, which is `inittab`. At this phase, the init process parses `inittab` (the configuration file). The content of the file might look like this:
```
#!/bin/bash
node::action:application to run
::sysinit:/etc/init.d/rcS # This is a bash script: run commands at initialization
::ask_first:/bin/sh
```
This bash script aims to mount `proc`, `dev`, `sys`, etc., at system initialization.

As mentioned before, `/etc` is a directory for configuration files, so `inittab` would be located under `/etc`. The `/etc/init.d/` directory contains scripts that will run at startup.

### Understanding `inittab` and Shell Scripts
The `inittab` file specifies that `/etc/init.d/rcS` will run this script:
```
#!/bin/bash
# The shebang line ensures that the script runs in a shell environment.
```
At this phase, the shell does not work, so the shebang line runs the shell for this process, which then closes and allows the process to run independently.

The line `/bin/sh` prevents termination by providing an entry point to the shell. At the end of this script, an `exit 0` command is used to terminate the script, but the shell will wait until it is terminated.

### Using Shebang with Interpreted Processes
When using applications like `adduser`, the shebang line is also included:
```
#!/bin/bash/perl
```
Any interpreted process uses a shebang line.

## SystemV

### Introduction to SystemV
If we work with only one init process, for example, initializing Bluetooth, WiFi, etc., we need to handle all functionalities within this process. Using runlevels allows us to manage these initializations. Each runlevel corresponds to a different mode of operation.

For instance:
- Runlevel 5: Initializes GUI, Bluetooth, WiFi.
- Runlevel 3: Initializes GUI, deinitializes shell.
- Runlevel 1: Deinitializes WiFi and GUI, initializes shell.

Modes are used to reduce CPU load by initializing or deinitializing services.

### Maintaining Runlevels
- Runlevel 1: Maintenance mode
- Runlevel 2: Shell
- Runlevel 5: Normal GUI mode

To manage these scripts, SystemV uses the `/etc/init.d/` directory, which holds all initialization scripts for system applications like GUI, TFTP, network, SSH, shell, etc.

To view these scripts, you can run:
```
ls /etc/init.d/
```
Under `/etc`, create directories for each runlevel:
```
/etc/rc1.d
/etc/rc5.d
/etc/rc3.d
```
To see your current runlevel, use:
```
runlevel
```
To list all runlevels:
```
ls rc
```
### Example
To disable the network at runlevel 1:
```
ln -s /etc/init.d/network K01network
```
To enable SSH:
```
ln -s /etc/init.d/ssh S02ssh
```
You can view all mode softlinks with:
```
ls rc5.d/ -lh
```
### Naming Convention
`K01network` and `S02ssh`:
- `S` stands for start, `K` for kill.
- Numbers indicate priority; if files have the same priority, they are processed alphabetically.

### Writing a Script
Create a script called `rc.c`:
```c
switch(runlevel) {
    case 1:
        cd /etc/rc1.d/;
        for(parsing(K),00) {
            // Finds K01GUI softlink to tftp under init.d and stops it
        }
        for(parsing(S),00) {
            // Finds S01SHELL softlink to the shell app under init.d and starts it
        }
        break;
    default:
        // Handle default case
        break;
}
```
### Runlevels in Embedded Linux
We have two modes:
1. Application mode (user mode)
2. Maintenance mode (service center)

In some systems, the application runs using Linux, with bare metal acting as a security device.

### Starting with SystemV
1. `init=/sbin/init` uses `inittab`:
```
node:"runlevel":action:application
    :      S   :sysinit:rcS
    :      1   :wait:rc.c
    :      2   :wait:rc.c
    :      3   :wait:rc.c
    :      4   :wait:rc.c
```
During a restart, the system returns to `sysinit`.

### How It Works
- Kernel calls init.
- Init reads `inittab` and executes `rcS` to initialize proc and sys.
- Init parses `sysinit rcS` and selects the runlevel by calling `/sbin/init`.

### Differences Between SystemD and SystemV
- Linux uses SystemD.
- UNIX uses SystemV.

### SystemD Limitations
SystemD initializes processes sequentially, not in parallel, which can increase CPU load when processes do not depend on each other.

### SystemD Overview
SystemD is an init process located at `/sbin/init` -> `/lib/systemd/system`.

Main directories:
- `/etc/systemd/system/`
- `/lib/systemd/system/`

SystemD uses units for services, mounts, networks, automounts, sockets, etc. Each unit has a specific configuration.
