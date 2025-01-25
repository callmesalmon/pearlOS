#!/usr/bin/bash

MAKE_CMD="make"

if [[ $1 == "qemu" ]]; then
    MAKE_CMD="make qemu"
fi

${MAKE_CMD}                              \
    CC="gcc"                             \
    CFLAGS="-m32 -ffreestanding -fno-pie \
    -Os -c -ggdb -I./lib -I. -std=c17"