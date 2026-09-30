/* Compilation checks only; no AME numerical execution is implied.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
typedef __riscv_ztt_f64_1x1_t now_available;
__riscv_ztt_f64_1x8_t too_wide; /* { dg-error "(unknown type name|does not name a type)" } */
__riscv_ztt_f16_1x32_t too_many; /* { dg-error "(unknown type name|does not name a type)" } */
