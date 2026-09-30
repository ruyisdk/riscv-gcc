/* { dg-do compile } */
/* { dg-options "-O0 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

template<typename T>
__attribute__ ((noinline)) void
type_identity ()
{
}

template void type_identity<__riscv_ztt_i8_rne_1x1_t> ();

/* { dg-final { scan-assembler "_Z13type_identityIu24__riscv_ztt_i8_rne_1x1_tEvv" } } */
