SUMMARY = "Ping host machine and control LED"
DESCRIPTION = "This application pings the host machine and turns an LED on/off based on the ping result."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

FILEPATH:append = " :${THISDIR}/files"
SRC_URI += "file://ping_led.sh"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/ping_led.sh ${D}${bindir}/ping_led.sh
}
