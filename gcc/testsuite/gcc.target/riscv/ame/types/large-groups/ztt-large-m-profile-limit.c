/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
typedef __riscv_ztt_i128_rnu_1x1_t largest_square;
typedef __riscv_ztt_u8_rnu_1x16_t largest_group;
typedef __riscv_ztt_u8_rnu_1x32_t absent; /* { dg-error "(unknown type name|does not name a type)" } */
typedef __riscv_ztt_i128_rnu_1x2_t absent_wide; /* { dg-error "(unknown type name|does not name a type)" } */
/* ACC physical resources are independent of the complete M value limit.  */
typedef __riscv_ztt_i64_rnu_accx1_t complete_acc;
