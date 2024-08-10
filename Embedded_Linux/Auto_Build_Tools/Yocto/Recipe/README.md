So, we have already discussed variable assignments, variable types, and some BitBake commands like `bitbake-layer create-layer` and `bitbake getvar`.

Now, let's dive into recipes:
As mentioned earlier, when we talk about recipes, we refer to the `.bb` extension. Let's explore the contents of a recipe and how to write one.

1. Recipe Headers:

    - `SUMMARY`: This is considered a local variable.
    - `DESCRIPTION`: This is also considered a local variable.

2. LICENSE: When creating a recipe, you must specify the license it is based on.

For example, if your license is MIT:
Set `LICENSE = "MIT"`.
You must also set `LIC_FILES_CHKSUM`.

If you want to skip the license, set:
`LICENSE= "CLOSED"`

You can find all necessary licenses at `poky/meta/files/common-licenses/`.

What is a license? It's a text file.

To calculate the checksum:
Use the `md5sum` command to calculate the checksum and then pass it to the license.

```sh
md5sum MIT
```

Take this value and set `LIC_FILES_CHKSUM` like this:

```sh
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=<hash>"
```

Example:

```sh
cd ~/poky/build
bitbake-getvar COREBASE # which refers to `/home/nada/poky`
md5sum ../meta/files/common-licenses/MIT # to get the checksum
```

Applying the license:

```sh
mkdir RecipeLicense # in your home directory for testing
cd RecipeLicense
touch myrecipe.bb
nano myrecipe.bb
```

Add the following content:

```sh
SUMMARY = "This is my recipe"
DESCRIPTION = "This recipe does nothing"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=<hash>"
```

If you don't write this, the license won't work. You must provide the correct checksum for your file.

Alternatively, to skip all of that, set:
`LICENSE = "CLOSED"`

3. SRC_URI: This local variable specifies the source of your files, downloaded to the `dl` directory. It uses the schema related to the file location.

```sh
SRC_URI="git://<repo_link>;protocol=<e.g. https>;branch=<e.g. main>"
```

BitBake will then unpack this file in the `S` directory.

`SRC_REV`: Used only with git to checkout a specific commit hash. Each commit generates a hash.

Note: Other local variables hidden in each recipe include:

- `PV`: Package version
- `PR`: Package release
- `PN`: Package name
- `S`: Source directory of the recipe
- `B`: Destination directory used by the package feeder
- `D`: Build directory (for compilation)

You can modify these variables to change directories as needed.

Naming a recipe: `<package_name>_<package_version>_<package_release>.bb`
Example: `myrecipe_0.1_r3.bb`

To read the value of a local variable:
Use:

```sh
bitbake -e recipe | grep <variable_you_want>
```

`-e` stands for extend.

BitBake processes your variables and creates Python commands, adding the hidden variables.

Example:

```sh
bitbake -e nadaRecipe > pythonout
```

![1](images/4.png)
![1](images/5.png)