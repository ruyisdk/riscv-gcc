/* Tuple matmul.  */
/* { dg-do link } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,acc_tuple_matmul_kernel -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,acc_tuple_matmul_kernel -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/tuple-matmul/ztt-acc-tuple-matmul-body.h"
