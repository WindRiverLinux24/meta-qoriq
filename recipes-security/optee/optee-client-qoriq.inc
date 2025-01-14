# Copyright 2020-2023 NXP

require recipes-security/optee/optee-client.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/optee-client:"

DEPENDS = "util-linux-libuuid"

SRC_URI:remove = "git://github.com/OP-TEE/optee_client.git;branch=master;protocol=https"
SRC_URI:prepend = "${OPTEE_CLIENT_SRC};branch=${OPTEE_CLIENT_BRANCH} "

OPTEE_CLIENT_SRC ?= "git://github.com/nxp-qoriq/optee_client.git;protocol=https"

inherit pkgconfig

# Copy the udev rule from the libts recipe for starting tee-supplicant@.service
SRC_URI += "file://tee-udev.rules"
# Unix group name for dev/tee* ownership.
TEE_GROUP_NAME ?= "teeclnt"
do_install:append () {
    if ${@oe.utils.conditional('VIRTUAL-RUNTIME_dev_manager', 'busybox-mdev', 'false', 'true', d)}; then
        install -d ${D}${nonarch_base_libdir}/udev/rules.d/
        install -m 755 ${WORKDIR}/tee-udev.rules ${D}${nonarch_base_libdir}/udev/rules.d/
        sed -i -e "s/teeclnt/${TEE_GROUP_NAME}/" ${D}${nonarch_base_libdir}/udev/rules.d/tee-udev.rules
    fi
}
inherit ${@oe.utils.conditional('VIRTUAL-RUNTIME_dev_manager', 'busybox-mdev', '', 'useradd', d)}
USERADD_PACKAGES = "${PN}"
GROUPADD_PARAM:${PN} = "--system ${TEE_GROUP_NAME}"
