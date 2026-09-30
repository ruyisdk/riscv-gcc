/* UDS16.  */
/* { dg-do compile } */
/* { dg-options " -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options " -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#ifndef __riscv_ztt_i32_rnu_accx1
#error wide i32 ACC capability required
#endif
__riscv_ztt_i8_rnu_accx1_t *a; /* { dg-error "unknown type name|does not name a type" } */
