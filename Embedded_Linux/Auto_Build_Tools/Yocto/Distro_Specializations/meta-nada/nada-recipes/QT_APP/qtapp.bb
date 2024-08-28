SUMMARY = "QML-based Login Application for Raspberry Pi"

DESCRIPTION = "This recipe provides a simple login application designed for Raspberry Pi using QML. The application leverages Qt's QML and QtQuick modules to create a modern and responsive user interface. It includes all necessary source files, such as the main application logic (`main.cpp`), QML files for the user interface (`main.qml`), and additional resources (`images.png`, `qml.qrc`). The application is built using Qt's `qmake` build system."

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://main.cpp \
           file://cppsignalsender.cpp \
           file://cppsignalsender.h \
           file://qml.qrc \
           file://main.qml \
           file://images.png \
           file://test2.pro \
           file://test2.pro.user"

S = "${WORKDIR}"

DEPENDS = "qtbase qtdeclarative qtquickcontrols2 qttools"

inherit qmake5
inherit qmake5_base

do_compile() {
    oe_runmake -C ${B}
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${B}/qtapp ${D}${bindir}/qtapp
}
FILES_${PN} += "${bindir}/qtapp"

