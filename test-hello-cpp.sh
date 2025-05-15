#! /bin/bash

if [ -z "${GCC_INSTALL_DIR}" ]; then
    echo "Provide GCC_INSTALL_DIR"
    echo "export GCC_INSTALL_DIR=~/riscv-gcc"
    exit 1
fi
export PATH=${GCC_INSTALL_DIR}/bin:$PATH

make run_verilator_wf CFG=MAX BUS=AXI TARGETS="hello_cpp" TRACE=1