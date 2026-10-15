/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-expand -mztt-profile=gcc-runtime-u64-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define BC_TYPE i64_rnu
#define BC_CARRIER __INT64_TYPE__
#define BC_OTHER i32_rnu
#define BC_OTHER_CARRIER __INT32_TYPE__
#include "../../../../gcc.target/riscv/ame/state/ztt-matmul-concat.h"
/* { dg-final { scan-rtl-dump-not "Use concat inputs for matmul" "expand" } } */
