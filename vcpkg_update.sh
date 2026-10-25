#!/bin/sh

THIS=$(realpath -s "${0}")
HERE=$(dirname "${THIS}")
THIS=$(basename "${THIS}")

set -ex
cd ${HERE}/vendor/vcpkg
git pull
cd ${HERE}
##
## this requires a non-shallow git checkout for the vendor/vcpkg submodule,
## on the development machine
##
${HERE}/vendor/vcpkg/vcpkg x-update-baseline
cd ${HERE}
