Earlier, we built the kernel with the bootloader using a cross-compiler and compiled BusyBox using the same method. This approach saved space as the created image was smaller. However, we encountered some issues, such as dependencies during the build process.

In the [../Build_from_Scratch](https://github.com/NadaElsayed1/Embedded-Linux/tree/main/Embedded_Linux/Build_from_Scratch) directory, we created our own distribution (Distro).

Now, in this directory, we will learn about tools that make it easier to build an image. We will provide some configurations (e.g., using `menuconfig`), then run `make`, which will handle fetching the necessary files. You will then be able to build and obtain your customized image. At this phase, we are not concerned with compilation or similar tasks.

The image consists of two parts (FAT, EXT4):
- **FAT**: Contains U-Boot and the kernel.
- **EXT4**: Contains the userspace, including BusyBox.

With everything set up, you only need to use `dd` to create your virtual SD image, and you should find your board working. However, there may still be issues, such as the timing of the `make` process after configuration, as it will fetch, build, and create the image automatically. Note that these tools will download items that may seem unnecessary but are crucial for creating their environment, similar to Docker, which creates a space with all its requirements. This setup ensures it does not depend on system binaries but instead relies on itself, creating an environment with all it needs.

Let's assume you want to add another application, like Chrome, to your Distro, and it's not available in the config menu. You will need to create a script that outlines how to download this package and inject it into the configuration under "Target packages," which will be in the userspace or the Distro. We will explain this in more detail later in the `buildroot` section. However, in Yocto, there are many packages available, both familiar and unfamiliar, making it more complex.

Previously, when building from scratch, we first searched for the source code on GitHub, cloned it, configured it, and finally built it before placing it in the root filesystem.

**Note:** The most famous auto-build tools are Buildroot and Yocto. Buildroot's drawback is that it supports fewer packages compared to Yocto, which is more widely used.

As mentioned, Buildroot has a `menuconfig` interface. In Yocto, you will find separate sections for the bootloader (e.g., U-Boot, GRUB, Barebox) and the cross-compiler. You can navigate through these sections and adjust settings as needed.

|                      | Buildroot              | Yocto               |
|----------------------|------------------------|---------------------|
| Timing               | ⬇️                     | ⬆️                  |
| Workspace Environment| ⬇️ @ hard disk         | ⬆️                  |
| Footprint            | ⬇️ @ target device     | ⬆️                  |

**Notes:**
- Yocto is an industrial tool.
- Tesla previously used Buildroot as an auto-build tool.
- If you obtain a Linux package, you could potentially run it on a bare-metal board (e.g., Cortex-M). You will likely need external RAM and must minimize the image size by removing the virtual filesystem, as there will be no need for userspace.
