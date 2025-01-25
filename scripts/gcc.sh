#!/usr/bin/bash

MAKE_CMD="make"

if [[ $# -gt 0 ]]; then
    MAKE_CMD="make $@"
fi

${MAKE_CMD}                              \
    CC="gcc"                             \
    CFLAGS="-m32 -ffreestanding -fno-pie \
    -Os -c -ggdb -I./lib -I. -std=c17"