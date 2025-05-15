#! /bin/bash

if [ -z "${VERILATOR_PATH}"]; then
    echo "Provide VERILATOR_PATH"
    echo "export VERILATOR_PATH=~/verilator"
    exit 1
fi

cd "${VERILATOR_PATH}"

unset VERILATOR_ROOT  # For bash

git checkout stable      # Use most recent stable release
#git checkout v{version}  # Switch to specified release version

autoconf         # Create ./configure script
./configure      # Configure and create Makefile
make -j `nproc`  # Build Verilator itself (if error, try just 'make')
sudo make install
