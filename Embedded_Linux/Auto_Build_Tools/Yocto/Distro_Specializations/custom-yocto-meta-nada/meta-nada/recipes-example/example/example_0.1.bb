SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Recipe created by bitbake"
LICENSE = "MIT"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*       New Recipe Created by bitbake         *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
