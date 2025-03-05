FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"
FILESEXTRAPATHS:prepend := "${COREBASE}/meta/recipes-bsp/u-boot/files:"

SRC_URI:append:qoriq-ppc = "\
    file://0001-add-typedef-to-avoid-multiple-definition-issue.patch \
"

SRC_URI:append = "\
    file://CVE-2024-57254.patch \
    file://CVE-2024-57255.patch \
"

