#!/usr/bin/bash

set -xe

./configure >> "debug.txt"
make qemu >> "debug.txt"