#! /bin/bash

if [ -z "${RISCV_GNU_TOOLCHAIN_PATH}" ]; then
    echo "Provide RISCV_GNU_TOOLCHAIN_PATH"
    echo "export RISCV_GNU_TOOLCHAIN_PATH=~/riscv-gnu-toolchain"
    exit 1
fi

if [ -z "${GCC_INSTALL_DIR}" ]; then
    echo "Provide GCC_INSTALL_DIR"
    echo "export GCC_INSTALL_DIR=~/riscv-gcc"
    exit 1
fi

cd "${RISCV_GNU_TOOLCHAIN_PATH}"
./configure --prefix="${GCC_INSTALL_DIR}" --with-arch=rv64gcv --with-cmodel=medlow --enable-multilib
make MAKEINFO=true -j4