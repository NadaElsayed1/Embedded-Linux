## Introduction
Welcome to the Embedded Linux series! This task involves setting up and configuring the Linux kernel for ARM architecture, including creating and managing users and groups using Bash scripts. Below, I provide detailed instructions for each step, covering kernel components, device tree files, kernel configuration, and compression methods, along with the necessary commands and configurations to ensure a smooth setup process.

### Kernel Overview
Linux consists of two main components: `zImage` and `file.dtb`.

**zImage**: This is the compressed image of the compiled Linux kernel source code.

**file.dtb**: This file is a Device Tree Blob, which describes the hardware connections outside of the CPU. It details all the registers outside the CPU on the SoC (System on Chip) and the remaining peripherals on the board. Essentially, it provides addresses and registers for all peripherals connected to the SoC and the board.

In previous Linux versions, such as Linux 1 and 2, there wasn't a `file.dtb`. Each architecture board had its own version of Linux, written specifically for it. When writing drivers under Linux, physical addresses were used directly, a method called "board-specific."

In modern Linux generations, the approach has shifted. Now, Linux is divided into two sections:

1. **Logic Part (zImage)**: This part contains the generic logic to run Linux based on the architecture used. It holds variables related to address mapping but not the actual values, as these will connect to the `file.dtb`.
   
2. **Hardware Description (file.dtb)**: This file contains the actual register values and addresses specific to your board.

This division allows Linux to be architecture-based rather than board-specific. With this approach, you only need one source code, and the `dtb` files are the only components that change based on the specific board.

This new method provides a more modular and flexible way to handle different hardware configurations without modifying the core kernel logic, streamlining the process of adapting Linux to various architectures.

3. **What is DTS, DTC, DTB**:

    1. DTS: Device Tree Source
        - **Description:** A human-readable text file that describes the hardware components of a system. It contains addressable nodes and properties for each peripheral and device.
        - **Example:** Describes CPUs, memory, buses, and peripherals.

    2. DTC: Device Tree Compiler
        - **Description:** A tool that converts the human-readable DTS files into binary format. It takes a DTS file as input and produces a DTB file.

    3. DTB: Device Tree Binary
        - **Description:** A binary file generated from a DTS file using the DTC. It is used by the Linux kernel to understand the hardware layout of the system during boot time.
        - **Example:** The kernel reads the DTB file to configure the hardware correctly.

## Now let's dive into the kernel
   1. Clone the kernel source:
      ```sh
      git clone --depth=1 git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
      ```
      `--depth=1` means to retrieve only the most recent commit, not the entire history.

   2. Configure the kernel:
      ```sh
      make menuconfig
      ```
      Navigate to `cd /linux/arch/arm/configs` and choose the board, which is `vexpress`. Then go back to the Linux directory `cd ~/linux`. If you run `make vexpress`, you will get an error *can't find default configuration*. This is because it is looking in the wrong place (arch/x86/configs/vexpress instead of arch/arm). So, set the environment variables:
      ```sh
      export ARCH=arm
      export CROSS_COMPILE=~/xtool/arm
      ```
      Now you can run `make vexpress`.

      Let's configure our kernel:
       1. Go to General Setup -> Kernel Compression Mode

        As you see, there are many types of compression, and we will choose xz. Let's know more about it. Write a forward slash `/` to search and then write xz:

            - It says that the kernel is about 30% smaller in size compared to gzip, but at the endpoint in RAM, it's the same.
            - During decompression, xz is better than LZMA and worse than gzip.
            - In terms of speed, it's equal to LZMA.
        
        So, finally, I can pick a specific compression method to make Linux boot faster depending on my CPU and RAM. For example, when the CPU is faster and RAM is slower, I will use gzip to generate a compressed image, as the CPU can compress and then pass a smaller image to RAM. If the opposite is true, where the CPU is slower and RAM is faster, it's better to use an uncompressed image. This is because, in this case, the CPU will be slower to compress, so I need to pick a method that minimizes CPU load and takes advantage of the faster RAM. Therefore, for slower CPUs and faster RAM, using an uncompressed image or a compression method with lower CPU overhead, such as LZ4, is recommended. LZ4 provides fast decompression speeds and is lightweight on CPU usage, making it ideal for scenarios where CPU performance is limited but RAM performance is not.

        Finally, the command I use to decompress the action of xz is `bootz`.

       2. Go back to General Setup -> Initramfs source file

        Now the kernel will go to RAM to decompress itself. The kernel knows it has arrived in RAM by the `bootz` command sent to U-Boot.

       3. Go to Boot Options -> Default Kernel Command String

       4. Still in Boot Options -> File Systems, select ext4. Linux is built on a filesystem type ext4, not FAT.

       5. Search for devtmpfs using `/`

        devtmpfs is a virtual filesystem that the kernel creates to allow userspace access to virtual devices. Ensure that the option for devtmpfs being automounted is not selected as we will do the mounting ourselves.

       6. Finally, save the changes.

   3. Now, run `make`. At the end, it will create the zImage. You may not see it in the `/linux` directory, but you can find it by running `ls /linux/arch/arm/boot`. Here you will find `Image` and `zImage`. You can also see `vmlinux`, which is the compiled source code (binary Linux). This file includes debugging symbols and the symbol table, so its size is very large. To see its size, run:
      ```sh
      du -sh vmlinux
      ```

      All this size is stored in RAM.

      Compare the sizes of `Image` and `zImage`:
      ```sh
      du -sh Image
      du -sh zImage
      ```

      We can conclude that one of them is compressed (`zImage`, which is self-compressed) and the other is not. If you want to boot using `Image`, use the `booti` command.

      You can find the `file.dtb` at:
      ```sh
      cd /linux/arch/arm/boot/dts/arm
      ```

   4. Now, we need to copy the files to the TFTP folder. In my case:
      ```sh
      cp /linux/arch/arm/boot/zImage /srv/tftp
      cp /linux/arch/arm/boot/dts/arm/vexpress_vp2_ca9.dtb /srv/tftp
      ```

      If your `file.dtb` doesn't exist, you can run `make dtbs`.

      Now let's run `make -j8` (`-j8` refers to the number of cores your device has):
      ```sh
      make -j8 zImage dtbs
      ```

      This command compiles both the `zImage` and `dtbs`.

   5. Now, what happens is our kernel goes to a specific part of RAM, and our `file.dtb` is loaded to another part of RAM. The `bootz` command maps them to each other, as the kernel alone cannot work without the `file.dtb`.

