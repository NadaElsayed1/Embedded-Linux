SUMMARY = "Nada's Recipe"
DESCRIPTION = "Recipe created by Nada to display a banner based on the value of a variable"

LICENSE = "MIT"

python do_display_banner() {
    import bb
    import os

    # Fetch the variable from the environment
    banner_variable = d.getVar('BANNER_VARIABLE', True)
    
    if banner_variable == "1":
        bb.plain("***********************************************")
        bb.plain("*                                             *")
        bb.plain("*                  hi                       *")
        bb.plain("*                                             *")
        bb.plain("***********************************************")
    elif banner_variable == "2":
        bb.plain("***********************************************")
        bb.plain("*                                             *")
        bb.plain("*                hello                       *")
        bb.plain("*                                             *")
        bb.plain("***********************************************")
    else:
        bb.plain("***********************************************")
        bb.plain("*                                             *")
        bb.plain("*           Default banner message            *")
        bb.plain("*                                             *")
        bb.plain("***********************************************")
}

addtask display_banner before do_build