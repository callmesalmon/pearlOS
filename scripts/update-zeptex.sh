#!/usr/bin/bash

UPSTREAM_REPO="https://github.com/androvonx95/Zeptex"
ZEP_NOTICE="> [!NOTE]
> This README along with the rest of the Zeptex folder is taken
> from the upstream repository which can be found [here](https://github.com/androvonx95/Zeptex)."

git clone $UPSTREAM_REPO zeptex_upstream

rm zeptex/*

mv zeptex_upstream/zeptex-editor/* zeptex/
mv zeptex_upstream/LICENSE         zeptex/
mv zeptex_upstream/README.md       zeptex

echo -e "\n\n$ZEP_NOTICE" >> zeptex/README.md

rm zeptex_upstream -rf