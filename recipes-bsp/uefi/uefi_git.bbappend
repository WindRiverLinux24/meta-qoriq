SRCREV = "3f240a6453ed258aee4b45a9e280ee0d5d6b84d2"
SDK_MACHINE ?= "${MACHINE}"

do_install () {
       if [ -d ${B}/${SDK_MACHINE} ]; then
           install -d ${D}/uefi
           cp -r  ${B}/grub ${D}/uefi
           if [ "${SDK_MACHINE}" = "lx2160ardb-rev2" ]; then
               cp -r  ${B}/lx2160ardb ${D}/uefi/
           else
               cp -r  ${B}/${SDK_MACHINE} ${D}/uefi
           fi
       fi
}

do_deploy () {
       if [ -d ${B}/${SDK_MACHINE} ]; then
           install -d ${DEPLOYDIR}/uefi
           cp -r  ${B}/grub   ${DEPLOYDIR}/uefi
           if [ "${SDK_MACHINE}" = "lx2160ardb-rev2" ]; then
               cp -r  ${B}/lx2160ardb ${DEPLOYDIR}/uefi/
           else
               cp -r  ${B}/${SDK_MACHINE} ${DEPLOYDIR}/uefi
           fi
       fi
}
