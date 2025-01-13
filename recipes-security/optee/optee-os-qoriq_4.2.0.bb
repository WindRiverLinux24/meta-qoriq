# Copyright 2022-2024 NXP
require optee-os-qoriq.inc

OPTEE_OS_BRANCH = "lf-6.6.36_2.1.0"
SRCREV = "612bc5a642a4608d282abeee2349d86de996d7ee"

PV:append = "+git${SRCPV}"

do_install:append () {
	install -d ${D}${nonarch_base_libdir}/firmware/
	install -m 644 ${B}/core/tee-raw.bin ${D}${nonarch_base_libdir}/firmware/tee_${SDK_MACHINE}.bin
}

FILES:${PN} = "${nonarch_base_libdir}/optee_armtz/ ${nonarch_base_libdir}/firmware/"
