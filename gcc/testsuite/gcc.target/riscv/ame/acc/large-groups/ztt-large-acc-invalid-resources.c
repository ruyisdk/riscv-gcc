/* Resource boundaries.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
__riscv_ztt_i128_rnu_accx8_t *too_many; /* { dg-error "unknown type name|does not name a type" } */
__riscv_ztt_i4_rnu_accx1_t *partial; /* { dg-error "unknown type name|does not name a type" } */
