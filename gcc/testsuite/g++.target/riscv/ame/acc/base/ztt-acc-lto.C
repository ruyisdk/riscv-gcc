/* UDS32, i32/RNU only.  */
/* { dg-do link } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,acc_smoke -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,acc_smoke -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/base/ztt-acc-body.h"
