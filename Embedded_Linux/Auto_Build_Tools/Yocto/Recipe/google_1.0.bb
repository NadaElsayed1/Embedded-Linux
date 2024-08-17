# HEADER SECTION
SUMMARY = "Demo App Recipe"
DESCRIPTION = "This recipe clones and builds the demo app"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"

SRCREV = "720c663c5fd7246b4b42c5205d74db7d9784b5b2"

# Where the source files will be located after fetching

S = "${WORKDIR}/git"
DEPENDS = "cmake"

inherit cmake

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"
D = "${WORKDIR}/image"

do_configure(){
  #This ensures that CMake is properly configured to produce the desired output, with static linking as specified.
  #-DCMAKE_EXE_LINKER_FLAGS="-static": Sets the linker flags for executables to be statically linked.
  #-DCMAKE_SHARED_LINKER_FLAGS="-static": Sets the linker flags for shared libraries to be statically linked.
  cmake -S ${S} -B ${B} -DCMAKE_EXE_LINKER_FLAGS="-static" -DCMAKE_SHARED_LINKER_FLAGS="-static"
}

do_compile() {
    #In Yocto, oe_runmake is a helper function used in recipes to invoke make commands during the build process. It ensures that make is called in a consistent environment
    #so here make or cmake only would run correct
    oe_runmake -C ${B}
}

do_install() {
    # Create the destination directory for binaries
    # bindir -> /usr/bin
    install -d ${D}${bindir}  

    # Install the compiled binary
    install -m 0755 ${B}/calculator ${D}${bindir}/  
}
