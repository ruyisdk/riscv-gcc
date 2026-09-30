/* M utilities.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-m-utils-lto.C" } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,m_utils_entry -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,m_utils_entry -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/utils/ztt-m-utils-lto-body.h"
