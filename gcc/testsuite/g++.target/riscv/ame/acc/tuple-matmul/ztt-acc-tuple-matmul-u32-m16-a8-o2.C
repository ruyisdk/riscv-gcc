/* Tuple matmul.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a8" { target rv32 } } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a8" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/tuple-matmul/ztt-acc-tuple-matmul-body.h"
