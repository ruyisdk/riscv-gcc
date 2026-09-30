/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
typedef __riscv_ztt_i128_rnu_1x1_t now_available;
typedef __riscv_ztt_i128_rnu_1x4_t unavailable; /* { dg-error "(unknown type name|does not name a type)" } */
