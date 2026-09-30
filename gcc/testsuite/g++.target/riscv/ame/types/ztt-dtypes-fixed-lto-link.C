/* integer
   1x1 types with UDS=8.  Wider elements own a complete 2/4-M group.  */
/* { dg-do link } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,test_u32_rnu_1x1 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,test_u32_rnu_1x1 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/types/ztt-dtypes-single.h"
#include "../../../../gcc.target/riscv/ame/types/ztt-dtypes-pressure.h"
