# HEADER SECTION
SUMMARY = "Demo App Recipe"
DESCRIPTION = "This recipe clones and builds the demo app"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"

SRCREV = "720c663c5fd7246b4b42c5205d74db7d9784b5b2"

# Where the source files will be located after fetching

S = "${WORKDIR}/git"  
DEPENDS = "cmake"

inherit cmake

do_compile() {
    cmake -S ${S} -B ${B}  
    cmake --build ${B}
}

do_install() {
    install -d ${D}${bindir}  
    install -m 0755 ${B}/calculator ${D}${bindir}/  
}
