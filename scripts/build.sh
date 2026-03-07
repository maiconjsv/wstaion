#!/bin/bash
#to compile input ./build.sh

VERSION=$(git describe --tags --always)

gcc ../src/main.c -o wstation -DVERSION=\"${VERSION}\"