#!/bin/sh

# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the LICENSE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

PROFILE_DIR=./config/profiles
PROFILE=$PROFILE_DIR/default

if [ $# -gt 0 ]; then
    PROFILE=$PROFILE_DIR/$1
fi

for rc in $PROFILE/*; do
    if [ -f $rc ]; then
        case $rc in 
            "$PROFILE/config.h" | "$PROFILE/kentry.asm")
                DESTDIR=kernel
                ;;
            "$PROFILE/config.asm")
                DESTDIR=boot
                ;;
            "$PROFILE/defs.mk")
                DESTDIR=.
        esac
        rm $DESTDIR/$(basename $rc)
        cp $rc $DESTDIR/$(basename $rc)
    fi
done

set -x

touch kernel/debug.h
mkdir -p dist/
mkdir -p mk/
mkdir -p mk/bin/
mkdir -p mk/kernel/
mkdir -p mk/drivers/
mkdir -p mk/cpu/
mkdir -p mk/lib/
mkdir -p mk/fs/