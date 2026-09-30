/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
__riscv_ztt_i8_rnu_1x32_t *q32; /* { dg-error "unknown type name|does not name a type" } */
#if __riscv_ztt_i8_u8_shapes != 1
#error fixed P0 shape set changed
#endif
