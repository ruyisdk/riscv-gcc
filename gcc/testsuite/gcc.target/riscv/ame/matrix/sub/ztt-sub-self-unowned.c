/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u16-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define AC_SELF_OP __riscv_ztt_msub_ew_i16_rnu_2x1
#include "../bitwise/ztt-self-zero-unowned.h"
/* { dg-error "ownership" "" { target *-*-* } 0 } */
