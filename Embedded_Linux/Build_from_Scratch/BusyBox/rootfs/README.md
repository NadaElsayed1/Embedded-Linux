# Booting Kernel with Root Filesystem

Welcome to the Embedded Linux series! This task provides detailed instructions on how to boot a Linux kernel using root filesystem. 
The process includes downloading and configuring BusyBox, running the system on QEMU, and starting the kernel.

## Steps

### 1. Download and Configure BusyBox

1. Clone the BusyBox repository:
   ```sh
   git clone https://github.com/mirror/busybox.git
   cd busybox
   ```
   ![1](images/01.png)

2. Configure your cross-compiler and the target architecture:
   ```sh
   export CROSS_COMPILE=path/to/compiler/arm-cortexa9_neon-linux-musleabihf-
   export ARCH=arm
   ```
   
3. Set up the build configuration:
   ```sh
   make menuconfig
   ```
   In the menu, ensure you build a static binary (no shared libs). Navigate to Settings -> Build static binary.
   ![1](images/001.png)
   ![1](images/002.png)

4. Build BusyBox:
   ```sh
   make
   ```
   ![1](images/02.png)

5. Install BusyBox:
   ```sh
   make install
   ```
   ![1](images/03.png)
   ![1](images/08.png)

   The `_install` directory contains the installation files, which is the destination path for `make install`.

6. Verify the binary:
   ```sh
   file busybox
   ```
   It should be statically linked.

### 2. Create Root File System (rootfs) for Embedded Linux Target

1. Create the root filesystem directory and copy BusyBox files:
   ```sh
   mkdir ~/rootfs_Static
   rsync -av ~/busybox/_install/* ~/Desktop/Tools/rootfs_Static/
   cd ~/Desktop/Tools/rootfs_Static/
   ```

2. Create additional necessary directories:
   ```sh
   mkdir boot dev etc home mnt proc root srv sys
   ```

3. Create a startup script called `rcS` in `etc/init.d/` and the `inittab` file in `etc`:
   ```sh
   touch etc/inittab
   mkdir etc/init.d
   touch etc/init.d/rcS
   ```
   ![1](images/13.png)
   ![1](images/14.png)

4. Write the `inittab` script:
   ```sh
   # When system startup, it runs the script "rcS"
   ::sysinit:/etc/init.d/rcS
   # Ask the user to press any key before running /bin/sh
   ttyAMA0::askfirst:-/bin/sh
   # When restarting the init process, execute "init"
   ::restart:/sbin/init
   ```

5. Write the `rcS` file and make it executable:
   ```sh
   vim etc/init.d/rcS
   chmod +x etc/init.d/rcS
   ```
   ![1](images/15.png)

   Content of `rcS`:
   ```sh
   #!/bin/sh
   # Mount the proc filesystem
   mount -t proc nodev /proc
   # Mount the sysfs filesystem
   mount -t sysfs nodev /sys
   # Mount devtmpfs if not configured in Kernel menuconfig
   mount -t devtmpfs devtmpfs /dev
   ```

### 3. Configure Softlinks and Permissions

1. Create softlinks to the BusyBox executable:
   ```sh
   sudo cp busybox /media/nada/rootfs
   cd /media/nada/rootfs 
   ln -s busybox init
   ln -s busybox sh
   ```
   ![1](images/07.png)
   ![1](images/11.png)

2. Ensure all files are owned by the root user:
   ```sh
   chown -R root:root /path/to/directory
   # In my case
   sudo chown -R root:root ~/Desktop/tools/rootfs_Static
   ```

### 4. Copy Kernel Modules to rootfs_Static

1. Copy dynamic kernel modules to `rootfs_Static`:
   ![1](images/20.png)
   
   Use `rsync` to append the generated rootfs to `rootfs_Static`:
   ![1](images/28.png)

### 5. Boot the System with QEMU

1. Run QEMU:
   ```sh
   sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd /home/nada/sd.img -net tap,script=./qemu_ifup -net nic
   ```

2. Set the `bootargs` environment variable to avoid kernel panic:
   ```sh
   setenv bootargs 'console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait init=/sbin/init'
   saveenv
   ```

3. Load the kernel and device tree, then boot:
   ```sh
   fatload mmc 0:1 $kernel_addr_r zImage
   fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
   bootz $kernel_addr_r - $fdt_addr_r
   ```

   Alternatively, use the `bootflow scan` command:
   ```sh
   bootflow scan
   ```
   ![1](images/09.png)
   ![1](images/06.png)
   ![1](images/10.png)

   Note: If you encounter the error "init: must be run as PID", this message is generated by the init process itself, not the shell.


# BusyBox Dynamic Configuration

## Set Cross Compiler and Architecture

First, set the cross compiler and architecture by running the following commands:

```sh
export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-
export ARCH=arm
```

## Configure BusyBox

Navigate to the BusyBox directory and run:

```sh
make menuconfig
```

![menuconfig](images/53.png)
![menuconfig](images/52.png)

Select the necessary settings, then build and install BusyBox with:

```sh
make
make install
```

## Set Up Root Filesystem

Navigate to the root filesystem directory and create necessary directories:

```sh
cd ~/Desktop/Tools/rootfs_Dynamic
mkdir -p boot dev etc home mnt proc root srv sys
```

## Verify BusyBox Executable

Ensure the BusyBox executable file is linked dynamically:

```sh
file ~/Desktop/Tools/rootfs_Dynamic/bin/busybox
```

![busybox verification](images/51.png)

## Copy Libraries to Root Filesystem

Navigate to the sysroot directory in the x-tools directory and copy the libraries to the root filesystem:

```sh
cd ~/x-tools/arm-cortexa9_neon-linux-musleabihf/arm-cortexa9_neon-linux-musleabihf/sysroot
cp -rp ./lib/ ~/Desktop/Tools/rootfs_Dynamic/
cp -rp ./usr/lib/ ~/Desktop/Tools/rootfs_Dynamic/usr/
cp -rp ./usr/include/ ~/Desktop/Tools/rootfs_Dynamic/usr/
```

## Create Initialization Script

Navigate to the root filesystem directory and create the initialization script:

```sh
cd ~/Desktop/Tools/rootfs_Dynamic
mkdir -p etc/init.d
touch etc/init.d/rcS
```

Add the following content to `rcS`:

```sh
#!/bin/sh
# mount a filesystem of type `proc` to /proc
mount -t proc nodev /proc
# mount a filesystem of type `sysfs` to /sys
mount -t sysfs nodev /sys
# mount devtmpfs if you forget to configure it in Kernel menuconfig
# there are two options, uncomment one of them
# option 1: mount -t devtmpfs devtmpfs /dev
# option 2: mdev -s
```

Change the script permission to make it executable:

```sh
chmod +x etc/init.d/rcS
```

## Create Inittab Configuration File

Create the `inittab` configuration file in the etc directory:

```sh
cd ~/Desktop/Tools/rootfs_Dynamic/etc
touch inittab
```

Add the following content to `inittab`:

```sh
# inittab file 
#-------------------------------------------------------
# When system startup, will execute "rcS" script
::sysinit:/etc/init.d/rcS
# Start "askfirst" shell on the console (Ask the user firstly to press any key)
ttyAMA0::askfirst:-/bin/sh
# When restarting the init process, will execute "init"
::restart:/sbin/init
```

## Change File Ownership

Change the file ownership to root:

```sh
sudo chown -R root:root ~/Desktop/Tools/rootfs_Dynamic
```

![ownership change](images/55.png)

## Mount and Copy Root Filesystem

Mount the partition and copy the root filesystem:

```sh
sudo mount -o rw /dev/loop15p2 /media/nada/rootfs
sudo cp -rp ~/Desktop/Tools/rootfs_Dynamic/* /media/anas/rootfs
```

## Run QEMU

Run QEMU with the following command:

```sh
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd /path/to/sd.img -net tap,script=./qemu_ifup -net nic
```

![qemu run](images/56.png)
