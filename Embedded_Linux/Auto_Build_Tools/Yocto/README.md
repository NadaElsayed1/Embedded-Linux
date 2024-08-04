First, we'll cover some information about the BitBake tool, which requires some configurations called metadata to create our image. To do this:

1. We will create a directory called `Image_Generator_Dir` and then navigate to it using `cd Image_Generator_Dir`.
2. Next, we need to go to the `OpenEmbedded` community on GitHub, which contains the BitBake repository. We'll clone it using `git clone bitbake`. BitBake is written in Python, making it abstract from any architecture. This abstraction makes implementation easier, as you'll only need Python on your target. Now we have the BitBake folder.
3. To create an image, you still need metadata. OpenEmbedded has decided to create many layers containing applications. For example, if you want to download Python, you'll need to download `meta-core` (where "meta" refers to a layer), which contains many applications, including Python. So, use `git clone meta-core` to clone this layer.

In general, layers are split into two categories:
- **Apps**: For example, the Python application mentioned earlier belongs to the userspace and falls under this layer.
- **BSP (Board Support Package)**: If you want to download something for hardware, like for an RPI (Raspberry Pi), there is a layer for that. This includes components like U-Boot, the kernel, etc., which build on the board itself. You can use `git clone meta-raspberrypi` to clone this BSP layer.

- In the OpenEmbedded community, there are two types of layers (Apps and BSP), but sometimes they are not clearly separated and can be found in one layer.

Now, we have three folders in `Image_Generator_Dir`.

You might not know how to map BitBake to these folders, which is one of the problems with OpenEmbedded. You don't know what BitBake or the layers do; you just clone them. The first problem was:

### 1st Problem for OpenEmbedded -> Documentation:

You have everything you need to create an image, but you might not know how to use it. This is where Yocto comes in. In 2011, Yocto provided documentation on how to use BitBake with layers and explained that it uses OpenEmbedded. Yocto is more famous for its documentation, but there is still confusion about whether Yocto creates a distribution. As you can see from the documentation:

![1](images/1.png)

Yocto does not create a distribution; it is a reference (it just shows how to create an image). The actual image creation is done by OpenEmbedded using BitBake.

Yocto provides two layers (`meta-poky`, `meta-yocto-BSP`) in the `poky` repository:
- **meta-poky**: This is for Apps, different from meta-core.
- **meta-yocto-BSP**: This is for hardware, supporting a number of boards, including BeagleBone.

Additionally, other important layers from OpenEmbedded include (`meta-core`, `meta`, `meta-skeleton`, `meta-selftest`).
- **meta-skeleton**: Acts as a template or structure for creating BSPs.

### 2nd Problem for OpenEmbedded -> Compatibility:

There may be compatibility issues between versions. For example, if you download BitBake version 4 and need Python, you might download `meta-core` version 10, but the last work on this layer was done with BitBake version 1. If you configure BitBake with this layer, it will fail due to compatibility issues.

Yocto solves this by making Poky your destination. When you download it, it contains BitBake along with some branches (releases) like `zeus`, `dunfell`, `kirkstone`, and `master`. For example, `zeus` is one of the older releases from 2016. If you clone it and want a specific layer with Apps, you first clone the layer and check if the BitBake branch you have (e.g., `zeus`) is compatible with it, allowing you to create your image.

- The `dunfell` release was in 2018.
- The `kirkstone` release was in 2020.
- The `master` release is the newest one, but it might not yet have compatible layers.

### Note:

**Long-term support concept**: This means that each branch has compatible layers for a period until the next release.
