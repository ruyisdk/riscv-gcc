/* Mixed integer matmul.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-acc-mixed-lto.C" } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,mixed_lto_entry -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a2" { target rv32 } } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,mixed_lto_entry -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a2" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/mixed/ztt-acc-mixed-lto-body.h"
