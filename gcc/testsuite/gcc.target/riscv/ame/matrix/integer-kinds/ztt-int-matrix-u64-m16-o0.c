/* { dg-do compile } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a16" { target rv64 } } */
#define TEST_UDS 64
#include "ztt-int-matrix-all.h"
/* { dg-final { scan-assembler-not {mconv\.ew|__builtin_riscv_ztt_integer_matrix} } } */
