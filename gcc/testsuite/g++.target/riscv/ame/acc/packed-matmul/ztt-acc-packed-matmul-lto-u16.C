/* Complete packed matmul.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-acc-packed-matmul-lto.C" } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,packed_lto_entry -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a8" { target rv32 } } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,packed_lto_entry -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a8" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/packed-matmul/ztt-acc-packed-matmul-lto-body.h"
