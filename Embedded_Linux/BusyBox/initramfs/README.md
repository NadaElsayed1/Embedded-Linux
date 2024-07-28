# Booting Kernel with initramfs

Welcome to the Embedded Linux series! This task provides detailed instructions on how to boot a Linux kernel using initramfs. Ensure that BusyBox is compiled statically. The purpose of using initramfs before booting from a root filesystem (ext4) is to create a recovery boot mechanism with two root filesystems acting as two banks for booting. This approach offers the following advantages:

1. Faster execution process
2. Enhanced security
3. Flashing in two banks

The process involves copying the root filesystem's content to initramfs, archiving it into an image using `mkimage`, and booting with this image using QEMU.

## Steps

### 1. Create the Initramfs Directory

Create the initramfs directory in `~/Desktop/Tools`:
```sh
mkdir initramfs
```

### 2. Copy the Root Filesystem Content to initramfs Directory

Copy the content of your root filesystem to the initramfs directory:
```sh
sudo cp -rp /media/nada/rootfs/* ~/Desktop/Tools/initramfs
```
Then change the owner to root:
```sh
sudo chown -R root:root *
```
![1](images/30.png)
![1](images/29.png)

### 3. Compress the Files

Compress all files using `cpio` to move them to RAM as they were on the hard disk for faster execution. Additionally, compress them using `gzip` as the kernel is configured to use gzip compression.

1. First compression:
   ```sh
   find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio
   ```
   ![1](images/31.png)
   ![1](images/32.png)

2. Second compression:
   ```sh
   cd ..
   gzip initramfs.cpio
   ```
   ![1](images/34.png)
   ![1](images/35.png)

### 4. Convert to an Image

Convert the compressed file to an image to use it with QEMU:
```sh
mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz RAMfs
```
![1](images/36.png)

Move the image to the boot partition:
```sh
sudo cp RAMfs /media/nada/boot/
```
![1](images/37.png)

### 5. Run QEMU

Run QEMU with the following command:
```sh
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd /home/nada/sd.img -net tap,script=./qemu_ifup -net nic
```

### 6. Boot with initramfs

Set up the environment and boot with initramfs:
```sh
setenv ramdisk_addr 0x60900000
fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
fatload mmc 0:1 $ramdisk_addr RAMfs
setenv bootargs 'console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait init=/sbin/init' 
saveenv
bootz $kernel_addr_r $ramdisk_addr $fdt_addr_r
```
![1](images/38.png)
![1](images/39.png)
![1](images/40.png)
![1](images/41.png)
