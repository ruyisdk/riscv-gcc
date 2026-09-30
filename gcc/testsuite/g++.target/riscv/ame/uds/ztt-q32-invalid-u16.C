/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
typedef __riscv_ztt_i8_rnu_1x32_t now_available_1x32;
__riscv_ztt_i16_rnu_1x32_t *too_large_row; /* { dg-error "(unknown type name|does not name a type)" } */
typedef __riscv_ztt_i8_rnu_32x1_t now_available_32x1;
__riscv_ztt_i16_rnu_32x1_t *too_large_column; /* { dg-error "(unknown type name|does not name a type)" } */
__riscv_ztt_i8_rnu_1x64_t *outside_shape_set; /* { dg-error "(unknown type name|does not name a type)" } */
__riscv_ztt_i8_rnu_accx32_t *outside_acc_set; /* { dg-error "(unknown type name|does not name a type)" } */
#if defined(__riscv_ztt_n) || defined(__riscv_ztt_nelem)
#error N must remain runtime
#endif
